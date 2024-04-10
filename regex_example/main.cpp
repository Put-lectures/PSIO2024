#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <vector>
using namespace std;
struct Ex_rate
{
    string currency;
    float rate;
};
int main()
{
    vector<Ex_rate> rate;
    fstream file("/home/piotr/Downloads/nbp2024/kursy_walut.html", ios::in);
    if (file.is_open()) {
        std::stringstream buffer;
        buffer << file.rdbuf();
        string text = buffer.str();
        // cout << text;
        std::smatch m;
        std::regex r(R"(<\/td><td>(\d+) (\w{3})<\/td><td>(\d,\d+)<\/td>)");
        while (std::regex_search(text, m, r)) {
            for (auto el : m) {
                cout << el << endl;
            }
            text = m.suffix();
        }
    }

    return 0;
}
