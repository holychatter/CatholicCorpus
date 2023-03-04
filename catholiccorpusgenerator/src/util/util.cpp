#include "util.hpp"

bool isOnlySpace(const std::string& pLine)
{
  for (const auto& currChar : pLine)
  {
    if (currChar != ' ')
      return false;
  }
  return true;
}
