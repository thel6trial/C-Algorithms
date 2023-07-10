// Cho n nhà kho. Mỗi nhà kho có a[i] và t[i] là số lượng hàng và thời gian lấy hàng
// Tính tổng số lượng hàng max có thể lấy ở các nhà kho biết khoảng cách giữa 2 nhà kho lấy bất kì < D và tổng thời gian < T
// Quy hoạch động với dp[i][j] với i là tổng lượng hàng tính đến nhà kho thứ i và j là tổng thời gian tính hết nhà kho i => chạy 2 for cho i từ 1-> n và cho j từ 1->T

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, D, T;
    cin >> n >> D >> T;
    vector<int> a(n); // lượng hàng nhà ko thứ i
    vector<int> t(n); // thời gian bố hàng ở nhà kho i
    for(int i = 0; i < n; i++){
        cin >> a[i] >> t[i];
    }

    int dp[n][T+1]; // j là thời gian tính đến kho i thì nó phải nằm trong khoảng 0 -> T (thời gian tối đa cho phép bốc hàng)

    for(int j = 0; j <= T; j++){
        if(j > t[0]){
            dp[0][j] = a[0]; // xét từ 0->T, nếu như thời gian > thời gian bốc hàng ở kho 0 thì bốc được hàng ở kho 0 => gán dp với a[0]
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= T; j++){ // xét đến tổng thời gian đến hết i là j thì j > thời gian bốc hàng ở i thì mới bốc được
            if(j > t[i]){
                for(int k = 1; k <= i && k <= D; k++){ // xét khoảng cách từ kho hàng i đến kho hàng trước cần lấy phải nhỏ hơn D, means k = i - prev <= D
                    dp[i][j] = max(dp[i][j], dp[i-k][j - t[i]] + a[i]); // j - t[i] là tổng thời gian bốc hàng đến hết kho hàng trước i
                    // i - k tức là kho hàng trước i phải có khoảng cách với i <= D
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if(dp[i][T] > ans) ans = dp[i][T];
    }

    cout << ans;
    return 0;
}