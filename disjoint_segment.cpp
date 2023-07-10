// Cho tập X gồm rất nhiều đoạn. Đếm số đoạn khôgn trùng nhau
#include<iostream>
#include<vector>
using namespace std;

struct comparable{
    inline bool operator()(pair<int, int>&a, pair<int, int>&b){
        return a.second < b.second;
    }
};

int main(){
    // idea của bài toán chỉ đơn giản là sắp xếp các đoạn theo thứ tự tăng dần của thằng phần tử thứ 2
    // sau đó nếu i.first > i-1.second => 2 đoạn ko trùng nhau, cập nhật kết quả thêm 1
    int n;
    cin >> n;
    int ans = 0;
    vector<pair<int, int> > a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), comparable());
    int last = a[0].second;
    for(int i = 1; i < n; i++){
        if(a[i].first > last){
            ans ++;
            last = a[i].second;
        }
    }
    cout << ans;
    return 0;
}
