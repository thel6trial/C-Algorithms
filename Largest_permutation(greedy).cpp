/*
The first line contains two space-separated integers  and , the length of  and the maximum swaps that can be performed. 
The second line contains  distinct space-separated integers from  to  as  where .
Constraints

Output Format

Print the lexicographically largest permutation you can make with at most  swaps.
Sample Input 0

STDIN       Function
-----       --------
5 1         n = 5, k = 1
4 2 3 5 1   arr = [4, 2, 3, 5, 1]
*/


#include <iostream>
#include<string>
#include<vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



vector<int> largestPermutation(int k, vector<int> arr) {
    vector<int> a;
    a = arr;
    sort(a.rbegin(), a.rend()); // sort a theo thứ tự giảm dần
    int count = 0;
    for(int i = 0; i < a.size(); i++){
        if(count == k) break;
        for(int j = i; j < a.size(); j++){
            // xét từ thằng i tìm arr[j] = a[i], tức số lớn nhất tại i theo dãy đã sắp xếp, rồi đổi chỗ cho nhau
            if(arr[j] == a[i] && i != j){
                swap(arr[j], a[i]);
                count ++;
                break;
            }
        }
    }
    return arr;
}

int main()
{

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = largestPermutation(k, arr);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << " ";
        }
    }

    cout << "\n";


    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
