#include "livredesdemeures_parser.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <iomanip>

namespace fs = std::filesystem;

LivreDesDemeures_Parser::LivreDesDemeures_Parser()
 : VirtualFileParser("Carmel/SainteThereseAvila/livre_des_demeures.txt"),
   _beforeBegin(true)
{
}

void LivreDesDemeures_Parser::processLine(const std::string& pLine)
{
    if (_beforeBegin)
    {
      if (pLine == "Prologue ")
        _beforeBegin = false;
      return;
    }

    if (pLine == "\014")
      return;

    const static std::string chapterPrefix = "Chapitre ";
    if (pLine.compare(0, chapterPrefix.size(), chapterPrefix) == 0)
      return;

    *_outputFile << pLine << std::endl;
}
