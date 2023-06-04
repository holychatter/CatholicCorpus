#ifndef CATHOLICCORPUSGENERATOR_EXTERNALREQUESTER_EXTERNALREQUESTER_HPP
#define CATHOLICCORPUSGENERATOR_EXTERNALREQUESTER_EXTERNALREQUESTER_HPP

#include <string>


class ExternalRequester
{
public:
  virtual ~ExternalRequester() {}

  virtual void readWebPage(std::string& pRes,
                           const std::string& pUrl) const = 0;

};


#endif // CATHOLICCORPUSGENERATOR_EXTERNALREQUESTER_EXTERNALREQUESTER_HPP
