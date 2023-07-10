// Tính dãy con có tổng max / không có 2 phần tử đứng cạnh nhau
// dp[i][0] và dp[i][1]: tổng tính đến phần tử thứ i: 0 tức là không lấy phần tử i (means có thể có hoặc ko lấy phần tử i-1)
//                                                    1 tức là lấy phần tử i (means không được lấy phần tử i-1)

#include<iostream>
#include<vector>

using namespace std;

int maxsum(vector<int> a, int n){
    int dp[n][2];

    dp[0][0] = 0; // không lấy phần tử thứ 0
    dp[0][1] = a[0]; 
    for(int i = 1; i < n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]); // không lấy phần tử thứ i thì có thể lấy / ko lấy phần tử i-1
        dp[i][1] = dp[i-1][0] + a[i]; // lấy phần tử thứ i thì ko lấy phần tử i-1
    }

    return max(dp[n-1][0], dp[n-1][1]);
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << maxsum(a, n);
    return 0;
}