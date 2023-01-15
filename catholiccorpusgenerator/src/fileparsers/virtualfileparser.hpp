#ifndef CATHOLICCORPUSGENERATOR_FILEPARSERS_VIRTUALFILEPARSER_HPP
#define CATHOLICCORPUSGENERATOR_FILEPARSERS_VIRTUALFILEPARSER_HPP

#include <string>
#include <fstream>
#include <memory>

class VirtualFileParser
{
public:
  VirtualFileParser(const std::string& pFilename);
  void run();

protected:
  std::unique_ptr<std::ofstream> _outputFile;

  virtual void processLine(const std::string& pLine) = 0;

private:
  std::string _filename;
};

#endif // CATHOLICCORPUSGENERATOR_FILEPARSERS_VIRTUALFILEPARSER_HPP
