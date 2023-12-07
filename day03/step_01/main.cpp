#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

#define INFILE "day03/step_01/input.txt"

bool isValidPart(const std::vector<std::string> &schema,
                 const std::vector<std::string>::iterator &schemaIt,
                 std::string::iterator currNum,
                 long long numEnd,
                 long long numStartPos) {
  if (schemaIt != schema.begin()) {
    auto symbolPos = std::find_if((schemaIt - 1)->begin() + numStartPos - 1,
                                  (schemaIt - 1)->begin() + numEnd + 1,
                                  [](char c) { return ispunct(c) && c != '.'; });
    if (symbolPos != (schemaIt - 1)->begin() + numEnd + 1) {
      return true;
    }
  }
  if (schemaIt + 1 != schema.end()) {
    auto symbolPos = std::find_if((schemaIt + 1)->begin() + numStartPos - 1,
                                  (schemaIt + 1)->begin() + numEnd + 1,
                                  [](char c) { return ispunct(c) && c != '.'; });
    if (symbolPos != (schemaIt + 1)->begin() + numEnd + 1) {
      return true;
    }
  }
  if (numStartPos - 1 >= 0 && ispunct(schemaIt->at(numStartPos - 1)) && schemaIt->at(numStartPos - 1) != '.'
      || numEnd < schemaIt->size() && (ispunct(schemaIt->at(numEnd)) && schemaIt->at(numEnd) != '.')) {
    return true;
  }
  return false;
}

int main() {
  std::ifstream input(INFILE);
  std::vector<std::string> schema;
  int result = 0;

  for (std::string line; std::getline(input, line);) {
    schema.push_back(line);
  }
  for (auto schemaIt = schema.begin(); schemaIt != schema.end(); schemaIt++) {
    long long numEnd = 0;
    std::string::iterator currNum;

    while ((currNum = std::find_if(schemaIt->begin() + numEnd, schemaIt->end(), isdigit)) != schemaIt->end()) {
      numEnd = std::find_if_not(currNum, schemaIt->end(), isdigit) - schemaIt->begin();
      long long numStartPos = currNum - schemaIt->begin();

      if (isValidPart(schema, schemaIt, currNum, numEnd, numStartPos)) {
        result += std::stoi(schemaIt->substr(numStartPos, numEnd - numStartPos));
      }
    }
  }
  return result;
}