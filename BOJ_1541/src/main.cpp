#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

using vs = vector<string>;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string line;
    cin >> line;

    auto n = static_cast<int>(line.length());

    vs parsed{};
    for (int i = 0; i < n; ++i)
    {
        if ('+' == line[i] || '-' == line[i]) {
            parsed.push_back(line.substr(i, 1));
        }
        else {
            ostringstream oss{};
            while (!('+' == line[i] || '-' == line[i]) && i < n) {
                oss << line[i];
                ++i;
            }
            string s = oss.str();
            parsed.push_back(s);
            --i;
        }
    }

    int result{ 0 };
    bool isPlus{ true };
    for (const auto& v : parsed)
    {
        if ("-" == v) {
            isPlus = false;
        }
        else if ("+" != v) {
            istringstream iss{ v };
            int x;
            iss >> x;

            if (isPlus)
                result += x;
            else
                result -= x;
        }
    }

    cout << result;

    return 0;
}