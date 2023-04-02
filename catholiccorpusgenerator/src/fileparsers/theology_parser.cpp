#include "theology_parser.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "../util/util.hpp"

namespace fs = std::filesystem;

Theology_Parser::Theology_Parser(const std::string& pFileName,
                                 const std::string& pFirstLine)
  : VirtualFileParser(pFileName),
    _beforeBegin(true),
    _firstLine(pFirstLine)
{
}

void Theology_Parser::processLine(const std::string& pLine, bool pAsContentBefore)
{
  // pAsContentBefore = Not empty line before

  // Ignore lines before the first line
  if (_beforeBegin)
  {
    if (pLine == _firstLine)
      _beforeBegin = false;
    return;
  }

  auto line = pLine;
  if (!pAsContentBefore)
  {
    line = removeBeginOfChapterNumber(line);
  }

  *_outputFile << line << std::endl;
}
