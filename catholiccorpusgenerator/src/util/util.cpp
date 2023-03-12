#include "util.hpp"

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
  static const std::string minusStr = "–";
  static const auto minusStr_size = minusStr.size();
  std::size_t i = 0;
  while (i < pLine.size())
  {
    if (pLine[i] == ' ' || _isDigit(pLine[i]) || pLine[i] == '-')
    {
      ++i;
      continue;
    }

    if (pLine.size()-i >= minusStr_size && pLine.compare(i, minusStr_size, minusStr) == 0)
    {
      i = i + minusStr_size;
      continue;
    }
    break;
  }
  return pLine.substr(i, pLine.size()-i);
}
