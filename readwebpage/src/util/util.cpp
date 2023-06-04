#include "util.hpp"
#include <vector>

namespace
{
bool _isDigit(char pChar)
{
  return pChar >= '0' && pChar <= '9';
}
bool _isSpaceOrPunctuation(char pChar)
{
  return pChar == ' ' || pChar == ',' || pChar == '.' || pChar == '!' || pChar == '?';
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

void removeSmallParanthesis(std::string& pLine)
{
  auto beginOfParenthesisPosition = pLine.find('(');
  if (beginOfParenthesisPosition != std::string::npos)
  {
    auto endOfParenthesisPosition = pLine.find(')', beginOfParenthesisPosition);
    if (endOfParenthesisPosition != std::string::npos &&
        endOfParenthesisPosition - beginOfParenthesisPosition < 30) // Keep long size between parenthesis
    {
      auto beforeParenthesisPosition = beginOfParenthesisPosition;
      auto afterParenthesisPosition = endOfParenthesisPosition + 1;

      // Remove space before the parenthesis if there is a space before the parenthesis
      // and there is a space or a punctuation after the parenthesis
      if (beginOfParenthesisPosition > 0 && pLine[beginOfParenthesisPosition - 1] == ' ' &&
          (afterParenthesisPosition >= pLine.size() ||
           _isSpaceOrPunctuation(pLine[afterParenthesisPosition])))
        beforeParenthesisPosition = beginOfParenthesisPosition - 1;

      auto newLine = pLine.substr(0, beforeParenthesisPosition);
      if (afterParenthesisPosition < pLine.size())
        newLine += pLine.substr(afterParenthesisPosition, pLine.size() - afterParenthesisPosition);

      pLine = newLine;

      removeSmallParanthesis(pLine);
    }
  }
}
