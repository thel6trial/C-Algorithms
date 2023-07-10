#include <iostream>
#include<map>
using namespace std;

bool check(string number)
{
    for (int i = 0; i < number.size(); i++)
    {
        if (number[i] < '0' || number[i] > '9')
        {
            return false;
        }
    }
    return true;
}

int time1(string time1, string time2)
{
    int t = (time1[0] * 10 + time1[1]) * 3600 + (time1[3] * 10 + time1[4]) * 60 + (time1[6] * 10 + time1[7]);
    int s = (time2[0] * 10 + time2[1]) * 3600 + (time2[3] * 10 + time2[4]) * 60 + (time2[6] * 10 + time2[7]);
    return s - t;
}

int main(){
    map<string, int> calls;
    map<string, int> time;
    int total = 0;
    int check1 = 0;
    string type;
    cin >> type;
    while(true)
    {
        if(type == "#"){
            break;
        }
        string from_number, to_number, date, from_time, to_time;
        cin >> from_number >> to_number >> date >> from_time >> to_time;
        if(check(from_number) == false || check(to_number) == false) check1 = 1;

        total ++;
        calls[from_number] += 1;
        time[from_number] += time1(from_time, to_time);
    }
    while (true)
    {
        string type;
        cin >> type;
        if (type == "#")
        {
            break;
        }
        if (type == "?check_phone_number")
        {
            if (check1 == 1)
            {
                cout << '1' << endl;
            }
            else
            {
                cout << '0' << endl;
            }
        }
        else if (type == "?number_calls_from")
        {
            string number;
            cin >> number;
            cout << calls[number] << endl;
        }
        else if (type == "?number_total_calls")
        {
            cout << total << endl;
        }
        else
        {
            string number1;
            cin >> number1;
            cout << calls[number1] << endl;
        }
    }
}
