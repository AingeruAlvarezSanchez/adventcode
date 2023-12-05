#include <fstream>
#include <string>
#include <algorithm>

#define INFILE "day01/step_01/input.txt"

int main() {
    std::ifstream input(INFILE);
    std::string line;
    int result = 0;
    while (std::getline(input, line, '\n')) {
        auto first = std::find_if(line.begin(), line.end(), isdigit);
        auto last = std::find_if(line.rbegin(), line.rend(), isdigit);
        std::string combination = std::string(1, *first) + std::string(1, *last);
        result += stoi(combination);
    }
    return result;
}