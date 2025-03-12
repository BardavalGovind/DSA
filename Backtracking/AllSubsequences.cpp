#include <bits/stdc++.h>
using namespace std;

vector<string> res;
string current;
void generateSubsequences(string &s, int index) {
    if (index == s.size()) {
        res.push_back(current); 
        return;
    }

    current.push_back(s[index]);
    generateSubsequences(s, index + 1);

    current.pop_back();
    generateSubsequences(s, index + 1);
}

int main() {
    string s = "abc";
    generateSubsequences(s, 0);

    cout << "All Subsequences:\n";
    for (auto &sub : res) {
        cout << "\"" << sub << "\"" << endl;
    }
    return 0;
}
