// Có n khoá học, m GV. Xếp GV / chỉ đc dạy nh khoá cho phép và 2 khoá ko trùng nhau. Rất nhiều cách xếp => rất nhiều kiểu loads(số ca dạy) của gv => trong số mỗi cái max loads đó, tìm min
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<vector<int> > courses; // lưu lại mỗi khoá học thứ i có thể có nh gv nào dạy
vector<int> conflict_courses; //lưu lại 2 khoá học trùng h nhau
vector<int> loads; //số khoá học mà mỗi gv dạy
vector<int>track; // cuối cùng, khoá thứ i sẽ do gv nào dạy
vector<vector<bool> > available; // 2 chiều, khoá thứ i có thể được dạy bởi gv đó không

int n, m, k, ans = INT32_MAX;
int c, c1;
bool solved = false;


void tryCourse(int i){
    if(i == n){
        int max_load = 0;
        for(int i = 0; i < m; i++){
            max_load = max(loads[i], max_load); // tìm thằng loads max trong trường hợp này
        }
        ans = min(ans, max_load); // so sánh max_load của tất cả các TH với nhau, chọn ra min
        solved = true;
        return;
    }
    for(int teacher: courses[i]){ // xét từng thằng teacher có thể dạy được khoá học courses[i]
        if(available[i][teacher] == false){
            continue;
        }
        if(solved && loads[teacher] > ans){ //nếu như loads của gv này đang xét đến i mà > ans trước đó thì bỏ luôn TH này
            continue;
        }

        available[i][teacher] = false;
        if(conflict_courses[i] != -1){ // nếu i có tồn tại khoá cùng h thì cho available của khoá đó và gv là false luôn
            available[conflict_courses[i]][teacher] = false;
        }

        loads[teacher] ++;
        track[i] = teacher;
        if(loads[teacher] < ans){
            tryCourse(i+1);
        }
        available[i][teacher] = true;
        if(conflict_courses[i] != -1){ // bước quay lui
            available[conflict_courses[i]][teacher] = true;
        }

        loads[teacher] --;

    }
}

int main(){
    cin >> n >> m;
    courses.resize(n); // xét n khoá học
    loads.resize(m, 0); // m gv, gán loads bđầu đều là 0
    conflict_courses.resize(n, -1); // set up conflict của n khoá bđầu đều là -1 hết
    track.resize(n);
    available.resize(n, vector<bool>(m, false)); // set up mảng nxm phần tử, đầu tiên để false hết
    for(int i = 0; i < n; i++){ // xét lần lượt n khoá học
        cin >> k;
        for(int j = 0; i < k; i++){ // k gv giảng dạy khoá i, đẩy lần lượt vào courses[i] và gán available = true cho nó
            cin >> c;
            c--;
            courses[i].push_back(c);
            available[i][c] = true;
        }
    }
    cin >> k;
    for(int i = 0; i < k; i++){ // k đôi một 2 khoá trùng h nhau
       cin >> c >> c1;
       c--;
       c1--;
       conflict_courses[c] = c1;
       conflict_courses[c1] = c;
    }
    tryCourse(0);
    cout << ans;
    return 0;
}