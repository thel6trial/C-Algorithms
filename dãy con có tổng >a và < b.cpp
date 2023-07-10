// Tính số dãy con của dãy có tổng > A và <B

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void generate_sum(int start, int size, int s[], vector<int>& res){
    // tính tổng của tất cả dãy con trong 1 dãy, push vào res
    int power_size = pow(2, size); // size phần tử sinh ra 2^size dãy con

    for(int i = 0; i < power_size; i++){
        int sum = 0;

        for(int j = 0; j < size; j++){
            if(i & (1 << j)){
                sum += s[j + start];
            }
        }
        res.push_back(sum);
    }
}

int dem(int s[], int n, int A, int B){
    // chia đôi dãy to ra thành 2 dãy rùi tính tổng lần lượt tất cả dãy con trong 2 dãy đưa vào 2 vector
    // sắp xếp vector của dãy sau
    // với từng thằng trong vector dãy trước, tìm lower_bound và higher_bound, hiệu của nó chính là dãy con kết hợp được vs số đó để tạo thành dãy thoả mã đề bài
    vector<int> s1;
    vector<int> s2;
    int ans = 0;
    generate_sum(0, n/2, s, s1);
    if(n % 2 != 0){
        generate_sum(n/2, n/2 + 1, s, s2);
    }else{
        generate_sum(n/2, n/2, s, s2);
    }
    sort(s2.begin(), s2.end()); // sort dãy 2

    for(int i = 0; i < s1.size(); i++){
        int low = lower_bound(s2.begin(), s2.end(), A-s1[i]);

        int high = higher_bound(s2.begin(), s2.end(), B - s1[i]);

        ans += high - low;
    }
    return ans;
}

int main(){
    int n, A, B;
    cin >> n >> A >> B;
    int s[1000];
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    cout << dem(s, n, A, B);
    return 0;
}