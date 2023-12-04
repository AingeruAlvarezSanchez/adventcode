#include <fstream>
#include <string>
#include <algorithm>

int main(__attribute__((unused)) int argc, char **argv) {
    std::ifstream input(argv[1]);
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