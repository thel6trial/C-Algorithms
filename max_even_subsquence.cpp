// Đề bài: Tìm ra dãy con liên tiếp của 1 dãy cho trước có tổng là chẵn và tổng lớn nhất
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n; 
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long even[n]; // dãy tổng phần tử chẵn kết thúc ở thằng thứ i
    long long odd[n]; // dãy tổng các phần tử lẻ kết thúc ở thằng thứ i

    if(a[0] % 2 == 0){ // nếu phần tử đầu là chẵn => gán even0 với thằng đầu, odd với 0, o có dãy tổng lẻ kết thúc ở a0
        even[0] = a[0];
        odd[0] = 0;
    }else{  // tương tự trên
        odd[0] = a[0];
        even[0] = -1;
    }

    for(int i = 1; i < n; i++){
        if(a[i] % 2 == 0){
            if(even[i-1] == -1){ // tức là ko có tổng các phần tử liên tiếp là chẵn kết thúc ở i-1 => even[i] sẽ bđầu 1 dãy mới
                even[i] = a[i];
            }else{
                even[i] = even[i-1] + a[i]; // nếu có thì cộng thêm thằng ai chẵn vẫn ra tổng chẵn
            } 
            if(odd[i-1] == 0){ // nếu ko có tổng các phần tử lẻ liên tiếp ở vị trí i-1 thì cũng ko có ở vị trí i
                odd[i] = 0;
            }else{
                odd[i] = odd[i-1] + a[i]; // nếu có thì cộng thêm ai chẵn vẫn ra tổng lẻ
            }
        }else{ // h xét đến ai lẻ
            if(even[i-1] == -1){ // tức là ko có tổng các phần tử liên tiếp là chẵn kết thúc ở i-1 => dãy lẻ mới bđầu ở i
                odd[i] = a[i];
            }else{
                odd[i] = even[i-1] + a[i]; // nếu có thì cộng thêm thằng ai lẻ sẽ ra được tổng lẻ
            } 
            if(odd[i-1] == 0){ // nếu ko có tổng các phần tử lẻ liên tiếp ở vị trí i-1 thì cx ko có tổng chẵn kết thúc ở i
                 even[i] = -1;
            }else{
                even[i] = odd[i-1] + a[i]; // nếu có thì cộng thêm ai lẻ sẽ ra tổng chẵn
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(even[i] > ans) ans = even[i];
    }
    cout << ans;
    return 0;
}