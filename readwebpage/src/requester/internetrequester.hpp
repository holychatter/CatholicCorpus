#ifndef CATHOLICCORPUSGENERATOR_EXTERNALREQUESTER_INTERNETREQUESTER_HPP
#define CATHOLICCORPUSGENERATOR_EXTERNALREQUESTER_INTERNETREQUESTER_HPP

#include "externalrequester.hpp"

class InternetRequester : public ExternalRequester
{
public:

  virtual void readWebPage(std::string& pRes,
                           const std::string& pUrl) const;
  void pingPage(const std::string& pUrl) const;
};



#endif // CATHOLICCORPUSGENERATOR_EXTERNALREQUESTER_INTERNETREQUESTER_HPP
