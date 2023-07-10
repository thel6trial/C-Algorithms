#include<iostream>
#include<set>

using namespace std;

int max_value(set<int> a){
    int max;
    while(!a.empty()){
        max = *(a.rbegin());
    }
    return max;
}

int main(){
    int n;
    cin >> n;
    set<int> a;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.insert(x);
    }
    string s;
    cin >> s;
    while(true){
        if(s == "INSERT"){
            int x;
            cin >> x;
            a.insert(x);
        }
        else if(s == "DELETE_MAX"){
            int t = max_value(a);
            cout << t << endl;
            a.erase(t);
        }
        else if(s == "*"){
            break;
        }
    }
    return 0;
}