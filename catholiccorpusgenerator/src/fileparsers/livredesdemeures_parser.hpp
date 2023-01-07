#ifndef CATHOLICCORPUSGENERATOR_FILEPARSERS_LIVREDESDEMEURES_PARSER_HPP
#define CATHOLICCORPUSGENERATOR_FILEPARSERS_LIVREDESDEMEURES_PARSER_HPP

#include "virtualfileparser.hpp"
#include <string>

class LivreDesDemeures_Parser : public VirtualFileParser
{
public:
  LivreDesDemeures_Parser();

protected:
  void processLine(const std::string& pLine) override;

private:
  bool _beforeBegin;
};

#endif // CATHOLICCORPUSGENERATOR_FILEPARSERS_LIVREDESDEMEURES_PARSER_HPP
