#include<iostream>
#include<cmath>

using namespace std;

int v;
int c[100][100];

int best(int d[], bool check[]){
    int min = INT_MAX, min_index;
    for(int i = 0; i < v; i++){
        if(check[i] == false && d[i] < min){
            min = d[i];
            min_index = i;
        }
    }
    return min_index;
}

void primMST(int c[100][100]){
    int d[v];
    bool check[v];
    int near[v];
    for(int i = 0; i < v; i++){
        d[i] = INT_MAX;
        check[i] = false;
    }
    d[0] = 0;
    near[0] = -1;

    for(int i = 0; i < v-1; i++){
        int u = best(d, check);
        check[u] = true;

        for(int j = 0; j < v; j++){
            if(c[u][j] && check[j] == false && c[u][j] < d[j]){
                d[j] = c[u][j];
                near[j] = u;
            }
        }
    }
    for(int i = 1; i < v; i++){
        cout << near[i] << " " << i << " " << c[near[i]][i];
    }
}

int main(){
    cin >> v;
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            cin >> c[i][j];
        }
    }
    primMST(c);
    return 0;
}