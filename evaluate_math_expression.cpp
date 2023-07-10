#include<iostream>
#include<stack>
#include<string>

using namespace std;

int uu_tien(char op){ // set độ ưu tiên của dấu nhân cao hơn dấu +, -
    if(op == '+' || op == '-'){
        return 1;
    }
    else if (op == '*' || op == '/'){
        return 2;
    }
    return 3;
}

int tinh(int a, int b, char op){ // hàm tính kết quả
     if(op == '+') return a+b;
     else if(op == '-') return a-b;
     else if(op == '*') return a*b;
     else if(op == '/') return a/b;
}

int ketqua(string expression){
    stack<char> ops; // stack lưu các dấu

    stack<int> num; //stack lưu các số

    for(int i = 0; i < expression.length(); i++){
        if(expression[i] == ' '){
            continue;
        }
        else if(expression[i] == '('){
            ops.push(expression[i]);
        }
        else if(isdigit(expression[i])){ // nếu là chữ số thì đẩy vào, các chữ số liên tiếp nhau thì phải ra 1 số
             int val = 0;

             while(i < expression.length() && isdigit(expression[i])){
                  val = val * 10 + (expression[i] - '0');
                  i++;
             }
             i--;
             num.push(val);
        }
        else if(expression[i] == ')'){
            // gặp dấu ) thì thực hiện phép tính đến khi thằng top trong ops != (
            while(!ops.empty() && ops.top() != '('){
                int val1 = num.top(); // lấy ra số top trong num
                num.pop();
                // stack là LIFO => top là số cuối cùng
                int val2 = num.top();
                num.pop();

                char op = ops.top();
                ops.pop();
                num.push(tinh(val1, val2, op));
            }
            // loại dấu ( đi
            if(!ops.empty()){
                ops.pop();
            }
        }else{
            // TH rơi vào các dấu
            // nếu dấu đang xét có độ ưu tiên >= dấu trong ops thì thực hiện thôi
            while( !ops.empty() && uu_tien(expression[i]) <= uu_tien(ops.top()) ){
                int val1 = num.top(); // lấy ra số top trong num
                num.pop();
                // stack là LIFO => top là số cuối cùng
                int val2 = num.top();
                num.pop();

                char op = ops.top();
                ops.pop();
                num.push(tinh(val1, val2, op));
            }
            ops.push(expression[i]);
        }
    }
    // sau đó thực hiện từ phải sang trái thôi, khi này dấu ở top có độ ưu tiên luôn >= dấu đẩy vào trước
    while( !ops.empty()){
                int val1 = num.top(); // lấy ra số top trong num
                num.pop();
                // stack là LIFO => top là số cuối cùng
                int val2 = num.top();
                num.pop();

                char op = ops.top();
                ops.pop();
                num.push(tinh(val1, val2, op));
    }
    return num.top();
}

int main(){
    string a;
    cin >> a;
    int result = ketqua(a);
    cout << result;
    return 0;
}