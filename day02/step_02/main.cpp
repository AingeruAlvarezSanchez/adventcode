#include <fstream>
#include <algorithm>
#include <valarray>
#include <sstream>
#include <string>

#define INFILE "day02/step_02/input.txt"

int main() {
  std::ifstream input(INFILE);
  int result = 0;

  for (std::string line; std::getline(input, line);) {
    std::replace(line.begin(), line.end(), ';', ',');
    std::istringstream setStream(line.substr(line.find(':') + 1));
    std::valarray<int> totalCubes = {0, 0, 0};

    for (std::string gameSet; std::getline(setStream, gameSet, ',');) {
      std::string number = gameSet.substr(gameSet.find_first_not_of(' '),
                                          gameSet.find_first_not_of(' ') + gameSet.find_first_of(' ') + 1);
      if (gameSet.find("red") != std::string::npos && totalCubes[0] < std::stoi(number)) {
        totalCubes[0] = std::stoi(number);
      } else if (gameSet.find("green") != std::string::npos && totalCubes[1] < std::stoi(number)) {
        totalCubes[1] = std::stoi(number);
      } else if (gameSet.find("blue") != std::string::npos && totalCubes[2] < std::stoi(number)) {
        totalCubes[2] = std::stoi(number);
      }
    }
    result += totalCubes[0] * totalCubes[1] * totalCubes[2];
  }
  return result;
}