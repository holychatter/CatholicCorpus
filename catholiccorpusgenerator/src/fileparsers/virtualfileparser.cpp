#include "virtualfileparser.hpp"
#include <filesystem>
#include <iostream>
#include <iomanip>

#include "../util/util.hpp"

namespace fs = std::filesystem;
namespace
{
  const std::string _inputFolder = "../../input/";
  const std::string _outputFolder = "../../output/";
}

VirtualFileParser::VirtualFileParser(const std::string& pFilename)
  : _outputFile(),
    _filename(pFilename)
{
}


void VirtualFileParser::run()
{
  auto endofPathPosition = _filename.find_last_of('/');
  if (endofPathPosition != std::string::npos)
  {
    std::string relativePath = _filename.substr(0, endofPathPosition);
    std::cout << "relativePath :" << relativePath << std::endl;
    fs::create_directories(_outputFolder + relativePath);
  }

  std::string inputFilename = _inputFolder + _filename;
  std::string outputFilename = _outputFolder + _filename;

  std::ifstream inputFile(inputFilename.c_str(), std::ifstream::in);
  _outputFile = std::make_unique<std::ofstream>(outputFilename.c_str(), std::ifstream::out);

  if (!inputFile.is_open())
  {
    std::cerr << "File not found: " << inputFilename << std::endl;
    return;
  }

  std::string line;
  bool asContentBefore = false;

  while (getline(inputFile, line))
  {
    // Ignore specific lines
    if (line == "\014")
      continue;

    processLine(line, asContentBefore);
    asContentBefore = !isOnlySpace(line);
  }

  inputFile.close();
  _outputFile->close();
}
