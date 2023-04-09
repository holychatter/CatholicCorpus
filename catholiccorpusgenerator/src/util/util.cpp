#include "util.hpp"
#include <iostream>
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
  if (pLine == " a- Aristote. ")
    std::cout << "Toto " <<std::endl;
  static const std::vector<std::string> stringsToEscape = {"–","","●","→","","•",""};
  std::size_t numberOfGoodCharacters = 0;
  std::size_t beginOfLine = 0;
  std::size_t i = 0;
  while (i < pLine.size())
  {
    bool isGoodCharacter = true;
    if (numberOfGoodCharacters == 0)
    {
      if (pLine[i] == ' ' || _isDigit(pLine[i]) || pLine[i] == '-')
      {
        ++i;
        beginOfLine = i;
        continue;
      }
      for (const auto& currStr : stringsToEscape)
      {
        if (pLine.size()-i >= currStr.size() && pLine.compare(i, currStr.size(), currStr) == 0)
        {
          i = i + currStr.size();
          beginOfLine = i;
          isGoodCharacter = false;
          break;
        }
      }
    }
    else
    {
      if (pLine[i] == ' ')
      {
        ++i;
        continue;
      }
      if (pLine[i] == '-')
      {
        ++i;
        beginOfLine = i;
        break;
      }
    }

    if (isGoodCharacter)
    {
      if (numberOfGoodCharacters > 0)
        break;
      ++numberOfGoodCharacters;
      ++i;
    }
  }

  return pLine.substr(beginOfLine, pLine.size() - beginOfLine);
}
