#ifndef CATHOLICCORPUSGENERATOR_FILEPARSERS_THEOLOGY_PARSER_HPP
#define CATHOLICCORPUSGENERATOR_FILEPARSERS_THEOLOGY_PARSER_HPP

#include "virtualfileparser.hpp"
#include <string>

class Generic_Parser : public VirtualFileParser
{
public:
  Generic_Parser(const std::string& pFileName,
                 const std::string& pFirstLine);

protected:
  void processLine(const std::string& pLine, bool pAsContentBefore) override;
};

#endif // CATHOLICCORPUSGENERATOR_FILEPARSERS_THEOLOGY_PARSER_HPP
