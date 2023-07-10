#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n, m, r, c;
// từ điểm đang xét có thể dịch chuyển thêm 1 trong directions
// r và c là vị trí điểm đang xét; m và n là số hàng và cột 
bool validatePoint(int r, int c, vector<vector<int> >maze){
    if(r < 0 || r > n || c < 0 || c > m) { // điểm đi qua quá khỏi maze
       return false;
    }
    if(maze[r][c] == 1){ // là tường gạch
       return false;
    }
    return true;
}

int main(){
    vector<vector<int> >directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    cin >> n >> m >> r >> c;
    int ans = -1;
    vector<vector<int> > maze(n, vector<int>(m, 0));
    // khai báo vector maze 2 chiều mxn và giá trị bđầu là 0
    vector<vector<bool> >visited(n, vector<bool>(m, false));
    // đánh dấu điểm nào đã thăm là true
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> maze[i][j];
        }
    }
    queue<vector<int> >q;
    // đẩy vào queue những điểm lân cận của điểm đang xét
    //(chính là front của queue, xét xong sẽ pop điểm đó đi)
    vector<int> a = {r, c, 1} ;
    q.push(a); // 1 là số step, tăng lên 1 với 1 lần đi
    
    while(! q.empty()){
        auto diem = q.front(); // lấy điểm đang xét
        q.pop(); // xét xong thì xoá đi

        for(auto d: directions){
            int r1 = diem[1] + d[1]; // di chuyển diem sang điểm mới
            int c1 = diem[2] + d[2];
            int step = diem[3] + 1; // tăng step thêm 1

            if(r1 == n-1 || c1 == n-1){ // đến biên thì gán bằng step
              ans = step;
              break;
            }
            if(validatePoint(r1, c1, maze)){
                q.push({r1, c1, step}); // đẩy điểm có thể đi tới vào
                visited[r1][c1] = true; // đánh dấu đã đi qua
            }
        }
    }
    if(ans != -1) cout << ans;
    else cout << -1;
    return 0;
}