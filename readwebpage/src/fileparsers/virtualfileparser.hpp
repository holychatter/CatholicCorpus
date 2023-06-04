#ifndef CATHOLICCORPUSGENERATOR_FILEPARSERS_VIRTUALFILEPARSER_HPP
#define CATHOLICCORPUSGENERATOR_FILEPARSERS_VIRTUALFILEPARSER_HPP

#include <string>
#include <fstream>
#include <memory>

class VirtualFileParser
{
public:
  VirtualFileParser(const std::string& pFileName,
                    const std::string& pFirstLine);
  void run();

protected:
  std::unique_ptr<std::ofstream> _outputFile;

  virtual void processLine(const std::string& pLine, bool pAsContentBefore) = 0;

private:
  std::string _filename;
  bool _beforeBegin;
  std::string _firstLine;
};

#endif // CATHOLICCORPUSGENERATOR_FILEPARSERS_VIRTUALFILEPARSER_HPP
