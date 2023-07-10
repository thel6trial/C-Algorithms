#include<iostream>
#include<cmath>

using namespace std;

// Đếm số nghiệm nguyên dương của phương trình a1*x1 + a2*x2 + ... + an*xn = M biết a1, a2, ...., an
int arr[100];
int n, M;
int count1 = 0;

void dem(int current, int i){ // current là tổng a1*x1... tính đến thằng i-1
     if(i == n-1){ // nếu xét đến thằng thứ n thì ktra xem chia hết an ko, chia hết thì lấy được
         if((M - current) % arr[i] == 0){
            count1 += 1;
         }
         return;
     }
     current += arr[i]; // đầu tiên lấy x[i] = 1 trước
     while(current < M){
        dem(current, i+1); // nếu current < M thì xét tiếp thằng i + 1
        current += arr[i]; // xét xong x[i] = 1 rùi thì tiếp tục tăng lên = 2, 3,... miễn là vẫn < M, sau đó lại quay lui xét thằng i+1
     }
}

int main(){
    cin >> n >> M;
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    dem(0, 0);
    cout << count1;
    delete[] arr;
    return 0;
}