#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string period = s.substr(s.length()-2);
    
    string hour = s.substr(0,2);
    if(period == "PM" && hour!="12")
    {
        hour = to_string(stoi(hour)+12);
    }
    if(period == "AM" && hour =="12")
    {
        hour="00";
    }
    return hour + s.substr(2,6);
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}