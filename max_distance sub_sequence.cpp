// Đề: Độ kết nối là khoảng cách ngắn nhất giữa 2 phần tử trong dãy con c phần tử của dãy ban đầu
// Trong tất cả các dãy con c phần tử, tìm độ kết nối lớn nhất, đã sort dãy
// idea: giả sử kết quả cần tìm là mid, kiểm tra xem dãy có ít nhất c phần tử / khoảng cách giữa 2 phần tử bất kì >= mid không
// nếu có, xets sang bên phải (tức tăng độ kết nối max có thể có lên)
// ngược lại, xét sang bên trái

#include<iostream>
#include<vector>
using namespace std;

int n, c, low, high, mid;
vector<int> a;

bool require(int x){ // kiểm tra xem dãy có ít nhất c phần tử / khoảng cách giữa 2 phần tử bất kì >= x không
    int current = a[0];
    int count = 0;
    for(int i = 0; i < n; i++){
        if(a[i] - current >= x){ // nếu khoảng cách a[i] vs current > x thoả mãn thì +1, gán current với a[i] để xét tiếp khoảng cách với thằng sau vì dãy tăng dần
            count ++;
            current = a[i];
        }
    }
    return count >= c; //trả về xem số phần tử có khoảng cách lẫn nhau >= x có >= c để lập thành dãy con thoả mãn độ kết nối không
}

int main(){
    cin >> n >> c;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    low = a[0], high = a[n-1];
    while(low < high){
        mid = (high + low + 1) / 2;
        if(require(mid) == true) { // nếu độ kết nối mid thoả mãn thì xét sang bên phải để tăng độ kết nối có thể có
           low = mid;
        }else{
            high = mid - 1;
        }
    }
    cout << low;
    return 0;
}