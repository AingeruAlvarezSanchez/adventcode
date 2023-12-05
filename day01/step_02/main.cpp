#include <fstream>
#include <iostream>
#include <array>
#include <algorithm>

int main(__attribute__((unused)) int argc, char **argv) {
    std::ifstream input(argv[1]);
    std::string line;
    int result = 0;
    std::array<std::string, 9> nbs = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    while (std::getline(input, line, '\n')) {
        auto firstnb = std::find_if(line.begin(), line.end(), isdigit);
        auto lastnb = std::find_if(line.rbegin(), line.rend(), isdigit);
        std::pair<std::string, unsigned long> firststr, laststr;
        for (const auto& it : nbs) {
            size_t findit = line.find(it);
            if ((findit != std::string::npos && findit < firstnb - line.begin())
                && (firststr.first.empty() || findit <= line.find(firststr.first))) {
                firststr.first = it;
                firststr.second = std::find(nbs.begin(), nbs.end(), firststr.first) - nbs.begin() + 1;
            }
            findit = line.rfind(it);
            if ((findit != std::string::npos
                && (lastnb.base() - line.begin() - 1 == -1 || findit > lastnb.base() - line.begin() - 1))
                && (laststr.first.empty() || findit >= line.rfind(laststr.first))) {
                laststr.first = it;
                laststr.second = std::find(nbs.begin(), nbs.end(), laststr.first) - nbs.begin() + 1;
            }
        }
        std::string combination;
        combination += !firststr.first.empty() ? std::to_string(firststr.second)
                : std::string(1, *firstnb);
        combination += !laststr.first.empty() ? std::to_string(laststr.second)
                : std::string(1, *lastnb);
        result += stoi(combination);
    }
    return result;
}