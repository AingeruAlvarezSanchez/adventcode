#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

#define INFILE "day03/step_01/input.txt"

typedef std::vector<std::string> strVector;

bool isValidPart(const strVector &schema,
                 const strVector::iterator &schemaIt,
                 std::ptrdiff_t numEnd,
                 std::ptrdiff_t numStartPos) {
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
  strVector schema;
  int result = 0;

  for (std::string line; std::getline(input, line);) {
    schema.push_back(line);
  }
  for (auto schemaIt = schema.begin(); schemaIt != schema.end(); schemaIt++) {
    std::ptrdiff_t numEnd = 0;
    std::string::iterator currNum;

    while ((currNum = std::find_if(schemaIt->begin() + numEnd, schemaIt->end(), isdigit)) != schemaIt->end()) {
      numEnd = std::find_if_not(currNum, schemaIt->end(), isdigit) - schemaIt->begin();
      std::ptrdiff_t numStartPos = currNum - schemaIt->begin();

      if (isValidPart(schema, schemaIt, numEnd, numStartPos)) {
        result += std::stoi(schemaIt->substr(numStartPos, numEnd - numStartPos));
      }
    }
  }
  return result;
}