#include <algorithm>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    fstream file("/home/piotr/Downloads/gpl-3.0.txt", ios::in);
    unordered_map<string, int> words_map;
    // words_map["the"]++;

    if (file.is_open()) {
        string word;
        while (!file.eof()) {
            file >> word;
            words_map[word]++;
        }
    }

    for (auto el : words_map) {
        cout << el.first << " - " << el.second << endl;
    }

    // cout << words_map["the"];

    // vector<pair<string, int>> words_v(words_map.begin(), words_map.end());

    // sort(words_v.begin(),
    //      words_v.end(),
    //      [](const pair<string, int> &e1, const pair<string, int> &e2) {
    //          return e1.second < e2.second;
    //      });
    // for (auto el : words_v) {
    //     cout << el.first << " - " << el.second << endl;
    // }

    return 0;
}
