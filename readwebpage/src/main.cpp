#include "requester/internetrequester.hpp"
#include <memory>
#include <iostream>
#include <fstream>



int main(int argc, char *argv[])
{
  // read the parameters
  std::string url;
  std::string output;
  for (int i = 0; i < argc; ++i)
  {
    if ((i + 1) < argc)
    {
      const std::string currAgrv = argv[i];
      if (currAgrv == "--url")
        url = argv[i + 1];
      else if (currAgrv == "--output")
        output = argv[i + 1];
    }
  }

  // Print doc in case of wrong parameters
  if (url == "" || output == "")
  {
    std::cout << "usage ./readwebpage --url <url> --output <path_of_outputfile>" << std::endl;
    return 1;
  }
  //"https://www.vatican.va/content/francesco/en/audiences/2023.index.html"


  // Request web page
  InternetRequester internetResquester;
  std::string htmlContent;
  internetResquester.readWebPage(htmlContent, url);

  std::cout << "htmlContent:" << htmlContent << std::endl;

  std::ofstream outfile(output.c_str());
  outfile << htmlContent;
  outfile.close();
  return 0;
}
