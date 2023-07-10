#include<iostream>
#include<vector>

using namespace std;

struct dat{
    string id;
    string shape;
    vector<float> canh;

    float get_price(){
        if(id == "MD001"){
            return 50;
        }
        else if(id == "MD002"){
            return 30;
        }
        else if(id == "MD003"){
            return 10;
        }
    }

    float get_area(){
        if(shape == "Hinh chu nhat"){
            return canh[0] * canh[1];
        }
        else if(shape == "Hinh thang"){
            return (canh[0] + canh[1]) * canh[2] / 2;
        }
        else if(shape == "Hinh tam giac"){
            return canh[0] * canh[2] / 2;
        }
        else if(shape == "Hinh vuong"){
            return canh[0] * canh[0];
        }
    }

    float get_total_price(){
        return get_price() * get_area();
    }
    float get_deposit(){
        //đặt cọc
        if(id == "MD001"){
            return 0.7 * get_total_price();
        }
        else if(id == "MD002"){
            return 0.5 * get_total_price();
        }
        else if(id == "MD003"){
            return 0.3 * get_total_price();
        }
    }
    float get_discount(){
        if (shape == "Hinh thang" || shape == "Hinh vuong"){
            return 0.1 * get_total_price();
        }else{
            return 0;
        }
    }
};

struct company{
    string name;
    vector<dat> lands;

    float get_total_area(){
        int sum = 0;
        for(dat land: lands){
            sum += land.get_area();
        }
        return sum;
    }

    float get_total_price(){
        int sum = 0;
        for(dat land: lands){
            sum += land.get_price();
        }
        return sum;
    }

    float get_total_discount(){
        int sum = 0;
        for(dat land: lands){
            sum += land.get_discount();
        }
        return sum;
    }

    float get_total_deposit(){
        int sum = 0;
        for(dat land: lands){
            sum += land.get_deposit();
        }
        return sum;
    }
};

int main(){
    cout << "Nguyen Huu Loc - 20210536" << endl;
    cout << "CHUONG TRINH QUAN LY BAT DONG SAN" << endl;
    cout << "1. Nhap thong tin cong ty" << endl;
    cout << "2. In ket qua dien tich mieng dat" << endl;
    cout << "0. Thoat" << endl;

    vector<company> Companies;
    int a;
    cout << "NHAP LUA CHON CUA BAN: ";
    cin >> a;
    if(a == 0){
        cout << "Ban da thoat chuon trinh";
        return 0;
    }
    else if (a == 1){
        int number;
        cout << "Nhap thong tin so cong ty BDS: ";
        cin >> number;
        for(int i = 0; i < number; i++){
            company Company;
            cout << "Nhap thong tin cong ty: ";
            cout << "Ten cong ty: ";
            cin >> Company.name;
            string adress;
            cout << "Dia chi cong ty: ";
            cin >> adress;
            int num_land;
            cout << "So Mieng Dat: ";
            cin >> num_land;
            cout << "Nhap danh sach cac mieng dat: ";
            for(int j = 0; j < num_land; j++){
                dat land;
                cout << "Ma mieng dat thu " << j;
                cout << "(MD001, MD002, MD003)";
                cin >> land.id;
                cout << "Don gia theo m^2: " << land.get_price();
                cout << "Mieng dat hinh(Vuong, Thang, Tam giac, HinhCN): ";
                cin >> land.shape;
                land.canh.resize(3);
                if(land.shape == "HinhCN"){
                    cin >> land.canh[0] >> land.canh[1];
                }
                else if(land.shape == "Hinh thang"){
                    cin >> land.canh[0] >> land.canh[1] >> land.canh[2];

                }
                else if(land.shape == "Hinh tam giac"){
                    cin >> land.canh[0] >> land.canh[2];
                }
                else if(land.shape == "Hinh thang"){
                    cin >> land.canh[0];
                }
                cout << "Dien tich: " << land.get_area() << endl;
                cout << "Thanh tien: " << land.get_total_price() << endl;
                cout << "Tien dat coc: " << land.get_deposit() << endl;
                cout << "Giam gia: " << land.get_discount() << endl;

                Company.lands.push_back(land);
            }
            Companies.push_back(Company);
        }
    }
    else if(a == 2){
        for(company Company: Companies){
            cout << "Ten Cong ty: " << Company.name << endl;
            cout << "So mieng dat: " << Company.lands.size() << endl; 
            cout << "Tong dien tich: " << Company.get_total_area() << endl;
            cout << "Tong thanh tien: " << Company.get_total_price() << endl;
            cout << "Tong Dat coc: " << Company.get_total_deposit() << endl;
            cout << "Tong giam gia: " << Company.get_total_discount() << endl;
            cout << "Chi tiet cac manh dat: " << endl;
            cout << "MaMD" << " " << "Hinh dang" << " " << "Don gia" << " ";
            cout << "Dien tich " << "Thanh tien " << "Giam gia " << "Dat coc " << endl;
            for(dat land: Company.lands){
                cout << land.id << " " << land.shape << " " << land.get_price() << " ";
                cout << land.get_area() << " " << land.get_total_price() << " " << land.get_discount() << " " << land.get_deposit() << endl;
            } 
        }
        cout << "Bam phim bat ky de tiep tuc" << endl;
    }
}