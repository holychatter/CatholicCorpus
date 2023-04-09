#include "util.hpp"
#include <vector>

namespace
{
bool _isDigit(char pChar)
{
  return pChar >= '0' && pChar <= '9';
}
}


bool isOnlySpace(const std::string& pLine)
{
  for (const auto& currChar : pLine)
  {
    if (currChar != ' ')
      return false;
  }
  return true;
}

std::string removeBeginOfChapterNumber(const std::string& pLine)
{
  static const std::vector<std::string> stringsToEscape = {"–","","●","→","","•",""};
  std::size_t i = 0;
  while (i < pLine.size())
  {
    if (pLine[i] == ' ' || _isDigit(pLine[i]) || pLine[i] == '-')
    {
      ++i;
      continue;
    }

    bool shouldBreak = true;
    for (const auto& currStr : stringsToEscape)
    {
      if (pLine.size()-i >= currStr.size() && pLine.compare(i, currStr.size(), currStr) == 0)
      {
        i = i + currStr.size();
        shouldBreak = false;
        break;
      }
    }
    if (shouldBreak)
      break;
  }
  return pLine.substr(i, pLine.size()-i);
}
