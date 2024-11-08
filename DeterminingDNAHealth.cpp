#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string genes_temp_temp;
    getline(cin, genes_temp_temp);

    vector<string> genes_temp = split(rtrim(genes_temp_temp));
    vector<string> genes(n);

    for (int i = 0; i < n; i++) {
        genes[i] = genes_temp[i];
    }

    string health_temp_temp;
    getline(cin, health_temp_temp);

    vector<string> health_temp = split(rtrim(health_temp_temp));
    vector<int> health(n);

    for (int i = 0; i < n; i++) {
        health[i] = stoi(health_temp[i]);
    }

    string s_temp;
    getline(cin, s_temp);

    int s = stoi(ltrim(rtrim(s_temp)));
    long long min_health = LLONG_MAX, max_health = LLONG_MIN;

    for (int s_itr = 0; s_itr < s; s_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int first = stoi(first_multiple_input[0]);
        int last = stoi(first_multiple_input[1]);
        string d = first_multiple_input[2];

        long long total_health = 0;

        for (int i = first; i <= last; i++) {
            string gene = genes[i];
            size_t pos = d.find(gene);

            while (pos != string::npos) {
                total_health += health[i];
                pos = d.find(gene, pos + 1);
            }
        }

        min_health = min(min_health, total_health);
        max_health = max(max_health, total_health);
    }

    cout << min_health << " " << max_health << endl;
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