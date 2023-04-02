#include "saintethereseavila_parser.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <iomanip>

namespace fs = std::filesystem;

SainteThereseAvila_Parser::SainteThereseAvila_Parser(const std::string& pFileName,
                                                     const std::string& pFirstLine)
  : VirtualFileParser(pFileName),
    _beforeBegin(true),
    _firstLine(pFirstLine)
{
}

void SainteThereseAvila_Parser::processLine(const std::string& pLine, bool pAsContentBefore)
{
  // Ignore lines before the first line
  if (_beforeBegin)
  {
    if (pLine == _firstLine)
      _beforeBegin = false;
    return;
  }

  // Ignore lines that prefix with "Chapitre "
  const static std::string chapterPrefix = "Chapitre ";
  if (pLine.compare(0, chapterPrefix.size(), chapterPrefix) == 0)
    return;

  *_outputFile << pLine << std::endl;
}
