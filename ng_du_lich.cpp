#include<iostream>
#include<cmath>
#define inf 1e9+9

using namespace std;

int n, f, best, g, min1;
const int maxn = 21;
int visited[maxn], x[maxn], x_best[maxn], c[maxn][maxn];

void update(int f){
    if(f + c[x[n]][1] < best){
        best = c[x[n]][1] + f;

        for(int i = 1; i <= n; i++){
            x_best[i] = x[i];
        }
    }
}

void print(){
    cout << best << endl;
    for(int i = 1; i <= n; i++){
        cout << x[i] << " ";
    }
}

void Try(int k){
    for(int i = 2; i <= n; i++){
        if(!visited[i]){
            x[k] = i;
            visited[i] = 1;
            f += c[x[k-1]][i];
            if(k == n) update(f);
            else{
                g = f + (n-k+1) * min1;
                if(g < best) Try(k+1);
            }
        }
        visited[i] = 0;
        f -= c[x[k-1]][i];
    }
}

int main(){
    cin >> n;
    min1 = inf;
    for(int i =1 ; i <= n; i++){
        for(int j = 1; i <=n ; j++){
            cin >> c[i][j];
            if(c[i][j]  < min1){
                min1 = c[i][j];
            }
        }
    }
    best = inf;
    Try(2);
    print();
    return 0;
}