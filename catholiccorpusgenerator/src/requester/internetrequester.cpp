#include "internetrequester.hpp"
#include <iostream>
#include <curl/curl.h>


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string* userp)
{
  size_t res = 0;
  if (userp != nullptr)
  {
    userp->append(static_cast<char*>(contents), size * nmemb);
    res = size * nmemb;
  }
  return res;
}


void InternetRequester::readWebPage(std::string& pRes,
                                    const std::string& pUrl) const
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if (curl)
  {
    std::cout << "read_web_page: " << pUrl << std::endl;
    curl_easy_setopt(curl, CURLOPT_URL, pUrl.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &pRes);
    res = curl_easy_perform(curl);
    std::cout << res << std::endl;
    curl_easy_cleanup(curl);
  }
}


void InternetRequester::pingPage(const std::string& pUrl) const
{
  CURL *curl;
  CURLcode res1;

  curl = curl_easy_init();
  if (curl)
  {
    std::cout << "ping_web_page: " << pUrl << std::endl;
    curl_easy_setopt(curl, CURLOPT_URL, pUrl.c_str());
    res1 = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
  }
}
