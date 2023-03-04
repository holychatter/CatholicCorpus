#ifndef CATHOLICCORPUSGENERATOR_FILEPARSERS_SAINTETHERESEAVILA_PARSER_HPP
#define CATHOLICCORPUSGENERATOR_FILEPARSERS_SAINTETHERESEAVILA_PARSER_HPP

#include "virtualfileparser.hpp"
#include <string>

class SainteThereseAvila_Parser : public VirtualFileParser
{
public:
  SainteThereseAvila_Parser(const std::string& pFileName,
                            const std::string& pFirstLine);

protected:
  void processLine(const std::string& pLine, bool pAsContentBefore) override;

private:
  bool _beforeBegin;
  std::string _firstLine;
};

#endif // CATHOLICCORPUSGENERATOR_FILEPARSERS_SAINTETHERESEAVILA_PARSER_HPP
