#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct lesson{
    string code;
    int TC;
    int LT;
    int BT;
    int TH;

    float TC_HP(){
        return (float) LT + BT + TH * 1.5;
    }

    string type_h(){
        if(TH == 3 && LT == 0 && BT == 0){
            return "DAMH";
        }
        else if(TC == 6){
            return "DATN Cu Nhan";
        }
        else if(TC == 12){
            return "DATN Ky su";
        }
        else if(LT >= 1 && BT >= 1 && TH < 1){
            return "LT-BT";
        }
        else if(LT >= 1 && TH >= 1 && BT < 1){
            return "LT-TN";
        }
        else if(LT >= 1 && BT >= 1 && TH >= 1){
            return "LT-BT-TN";
        }
    }

    string weight(){
        string t = to_string(TC) + "(";
        t += to_string(LT) + "-";
        t += to_string(BT) + "-";
        t += to_string(TH) + "-";
        t += to_string(TC*2) + ")";
        return t;
    }
};

struct student{
    string name;
    int TC_price;
    int paid;
    vector<lesson> lessons;

    float total_TC(){
        float sum = 0;
        for(lesson Lesson: lessons){
            sum += Lesson.TC_HP();
        }
        return sum;
    }

    float total_TC_price(){
        return total_TC() * TC_price;
    }

    float have_to_paid(){
        return total_TC_price() - (float)paid;
    }

    string status(){
        if(have_to_paid() > 0){
            return "Con thieu";
        }else{
            return "Da nop du";
        }
    }
};

int main(){
    cout << "Nguyen Huu Loc - 20210536" << endl;
    cout << "**   CHUONG TRINH QUAN LY HOC PHI **" << endl;
    cout << "1. Nhap cac sinh vien va cac mon hoc" << endl;
    cout << "2. In ds sinh vien va hoc phi cac mon" << endl;
    cout << "0. Thoat" << endl;
    int a;
    cout << "** NHAP LUA CHON CUA BAN **";
    cin >> a;
    vector<student> Students;
    if(a == 0){
        cout << "Ban da thoat khoi chuong trinh";
        return 0;
    }
    else if(a == 1){
        int number;
        cin >> number;
        for(int i = 0; i < number; i++){
            student Student;
            cout << "Nhap thông tin cua sinh vien thu " << i << endl;
            cout << "Ten sinh vien: ";
            cin >> Student.name;
            int num_lesson;
            cout << "So mon hoc: ";
            cin >> num_lesson;
            cout << "So tien mot tin chi: ";
            cin >> Student.TC_price;
            for(int j = 0; j < num_lesson; j++){
                lesson Lesson;
                cout << "Mon hoc thu " << j << endl;
                cout << "Ma mon hoc: ";
                cin >> Lesson.code;
                cout << "So tin chi: ";
                cin >> Lesson.TC;
                cout << "Nhap tin chi LT: ";
                cin >> Lesson.LT;
                cout << "Nhap tin chi BT: ";
                cin >> Lesson.BT;
                cout << "Nhap tin chi TH: ";
                cin >> Lesson.TH;
                Student.lessons.push_back(Lesson);
            }
            Students.push_back(Student);
        }
    }
    else if(a == 2){
        cout << "Ban da chon xuat DS sinh vien !";
        for(student Student: Students){
            cout << "Ten SV: " << Student.name << endl;
            cout << "So mon hoc: " << Student.lessons.size() << endl;
            cout << "So tien 1 TC: " << Student.TC_price << endl;
            cout << "Phai nop: " << Student.total_TC_price() << endl;
            cout << "Da nop dot 1: " << Student.paid << endl;
            cout << "To tien thieu: " << Student.have_to_paid() << endl;
            cout << "Tinh trang nop HP: " << Student.status() << endl;
            cout << "Chi tiet học phi cac mon hoc: " << endl;
            cout << "Ma MH " << " " << "Loai gio " << " " << "Khoi luong " << " " << "Hoc phi phai nop " << " ";
            for(lesson Lesson: Student.lessons){
                cout << Lesson.code << "  " << Lesson.type_h() << " ";
                cout << Lesson.weight() << "  " << Student.TC_price * Lesson.TC_HP();
            }
        }
    }
}