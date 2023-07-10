// Cho n nhà kho, mỗi nhà kho có a[i] vàng. Tính số vàng nhiều nhất có thể lấy từ các nhà kho, biết khoảng cách các nhà kho trong dãy thuộc L1 đến L2
#include<iostream>

using namespace std;

int n, L1, L2;

int gold_max(int a[], int n, int L1, int L2){
    int F[n]; // F lưu lại tổng số vàng max tính đến vị trí thứ i
    for(int i = 0; i < n; i++){
        F[i] = a[i];
    }
    // Xét từ vị trí L1 -> L2, tại những i < L1 thì khoảng cách của nó đến với nh nhà kho trước không thoả mãn đề bài
    for(int i = L1; i < L2; i++){
        int max = F[0];
        for(int j = 1; j <= i-L1; j++){ // xét trong khoảng i từ L1 -> L2 thì khoảng cách từ i ->1 < L2, thoả mãm
        // j < i - L1 tức là i-j > L1, thoả mãn
            if(F[j] > max) max = F[j];
        }
        F[i] = max + a[i];
    }
    // Xét còn lại từ L2-> n: i-j <= L2 => j >= i-L2 +1; i-j >= L1 =>j <= i-L1
    for(int i = L2; i < n; i++){
        int max = 0;
        for(int j = i - L2 + 1; j <= i - L1; j++){
            if(F[j] > max) max = F[j];
        }
        F[i] = max + a[i];
    }
    //Xét thằng từ n - L1 + 1 -> n, không thoả mãn khoảng cách (<L1) nên chưa thể so sánh được với nhau, so sánh các F của thằng này, cái nào max sẽ là max
    int ans = 0;
    for(int i = n-L1+1; i < n; i++){
        if(F[i] > ans) ans = F[i];
    }
    return ans;

}

int main(){
    cin >> n >> L1 >> L2;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << gold_max(a, n, L1, L2);
    return 0;
}