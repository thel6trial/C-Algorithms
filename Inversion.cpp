// Cho dãy số. Tìm số các cặp sao cho i < j và a[i] > a[j]: dùng merge sort
#include<iostream>
using namespace std;

const int m = 1e9+7;
int result = 0;
int n;
int a[10000], list1[10000];

long long dem(int start, int end){
    if(start > end-1){
        return 0;
    }
    int mid = (start + end) / 2;
    
    long long left_inversion = dem(start, mid);
    long long right_inversion = dem(mid+1, end);
    long long inversion = 0; // gộp 2 nửa trái và nửa phải
    int begin1 = start, begin2 = mid, i = start;
    while(begin1 < mid && begin2 < end){
        if(a[begin1] > a[begin2]){ // tăng begin2 lên, cho biết số này có thể tạo ra một cặp với a[begin1]
            list1[i++] = a[begin2++];
        }else{
            inversion += begin2 - mid; // số lần dịch chuyển của begin2 cũng chính là số lần a[begin1] > a[begin2] hay cũng chính là số cặp thoả mãn đề bài
            list1[i++] = a[begin1++];
        }
    }
    while(begin1 < mid){ // tức tất cả thằng begin 2 đều vào list1, tức tất cả đều nhỏ hơn nh thằng begin1 đang xét, tức kết quả + thêm với begin2 - mid cặp thoả mãn đề
         inversion += begin2 - mid;
         list1[i++] = a[begin1++];
    }
    while(begin2 < end){
        list1[i++] = a[begin2++];
    }
    return  left_inversion + right_inversion + inversion;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << dem(0, n) % m;
    return 0;
}