#include "virtualfileparser.hpp"
#include <filesystem>
#include <iostream>
#include <iomanip>

namespace fs = std::filesystem;
namespace
{
  const std::string _inputFolder = "../../input/";
  const std::string _outputFolder = "../../output/";
}

VirtualFileParser::VirtualFileParser(const std::string& pRelativePath,
                                     const std::string& pFilename)
  : _outputFile(),
    _relativePath(pRelativePath),
    _filename(pFilename)
{
}


void VirtualFileParser::run()
{
  fs::create_directories(_outputFolder + _relativePath);

  std::string inputFilename = _inputFolder + _filename;
  std::string outputFilename = _outputFolder + _filename;

  std::ifstream inputFile(inputFilename.c_str(), std::ifstream::in);
  _outputFile = std::make_unique<std::ofstream>(outputFilename.c_str(), std::ifstream::out);

  if (!inputFile.is_open())
  {
    std::cerr << "File not found: " << inputFilename << std::endl;
  }

  std::string line;
  bool beforeBegin = true;

  while (getline(inputFile, line))
  {
    processLine(line);
  }

  inputFile.close();
  _outputFile->close();
}
