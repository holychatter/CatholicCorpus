#include "generic_parser.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "../util/util.hpp"

namespace fs = std::filesystem;

Generic_Parser::Generic_Parser(const std::string& pFileName,
                               const std::string& pFirstLine)
  : VirtualFileParser(pFileName, pFirstLine)
{
}

void Generic_Parser::processLine(const std::string& pLine, bool pAsContentBefore)
{
  *_outputFile << pLine << std::endl;
}
