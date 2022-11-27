#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

map<string, int> dict;
vector<string> words;

// 转换字符用不了多少时间复杂度，所以这个函数的时间复杂度可以忽略不计
string transf(const string &s) {
    string str = s;
    for (auto &i : str) {
        if (i <= 90) i += 32;
    }
    sort(str.begin(), str.end());
    return str;
}

int main() {
    string t;
    while(cin >> t) { // O(n)
        if (t == "#") break;
        string tmp = transf(t);

        // O(logn)
        if (!dict.count(tmp)) dict[tmp] = 0;
        else dict[tmp]++;

        words.emplace_back(t);
    }

    vector<string> res;

    for (const auto &i : words) {
        if (!dict[transf(i)]) res.emplace_back(i);
    }
    sort(res.begin(), res.end()); // O(nlogn)
    for (const auto &i: res) cout << i << endl;

    return 0;
}