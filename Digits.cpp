// Cho số n. Đếm số cách điền số vào HUST + SOICT để tổng = n. Chữ giống nhau thì số cũng giống nhau => phải điền 7 số
#include<iostream>

using namespace std;

int n;
int ans = 0;
int x[7]; // cần điền 7 số

bool check(int v, int k){ // xét đến số thứ k, cần điền số v => xem xem k-1 chữ số trước có trùng v không
    for(int i = 0; i < k; i++){
        if(x[i] == v) return false;
    }
    return true;
}

void Try(int k){ // xét đến thằng chữ số thứ k
    for(int v = 0; v < 10; v++){
        if(v == 0){
            if(k == 0 || k == 2) continue; // số 0 nếu vào chữ H hoặc S => loại vì đứng đầu
        }
        if(check(v, k)){
            x[k] = v;
            if(k == 6){ // xét đến chữ số cuối rùi thì kiểm tra xem bằng n ko
               if((x[0] * 1000 + x[1] * 100 + x[2] * 10 + x[3]) + (x[2] * 100000 + x[4] * 10000 + x[5] * 1000 + x[6] * 10 + x[3]) == n){
                   ans ++;
               }
            }else{
                Try(k+1);
            }
        }
    }
}

int main(){
    cin >> n;
    ans = 0;
    Try(0);

    cout << ans;
    return 0;
}