#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>

#define INFILE "day02/step_01/input.txt"

int main() {
    std::ifstream input(INFILE);
    int result = 0;

    for (std::string line; std::getline(input, line);) {
        std::istringstream setStream(line.substr(line.find(':') + 1));
        bool isValidGame = true;

        for (std::string gameSet; std::getline(setStream, gameSet, ';');) {
            std::istringstream colorStream(gameSet);

            for (std::string color; std::getline(colorStream, color, ',');) {
                std::string number = color.substr(color.find_first_not_of(' '),
                                                  color.find_first_not_of(' ') + color.find_first_of(' ') + 1);
                if (std::stoi(number) > 12 && color.find("red") != std::string::npos ||
                    std::stoi(number) > 13 && color.find("green") != std::string::npos ||
                    std::stoi(number) > 14 && color.find("blue") != std::string::npos) {
                    isValidGame = false;
                    break;
                }
            }
            if (!isValidGame) {
                break;
            }
        }
        auto gameIdStart = std::find_if(line.begin(), line.end(), isdigit);
        std::string number = line.substr(gameIdStart - line.begin(),
                                         std::find_if_not(gameIdStart, line.end(), isdigit) - gameIdStart);
        result += isValidGame ? stoi(number) : 0;
    }
    return result;
}