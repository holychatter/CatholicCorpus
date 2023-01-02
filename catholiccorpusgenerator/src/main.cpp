#include <iostream>
#include <fstream>
#include <iomanip>
#include <filesystem>
namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
  std::string inputFolder = "../../input/";
  std::string outputFolder = "../../output/";

  fs::create_directories(outputFolder + "Carmel/SainteThereseAvila/");

  std::string filename = "Carmel/SainteThereseAvila/livre_des_demeures.txt";
  std::string inputFilename = inputFolder + filename;
  std::string outputFilename = outputFolder + filename;

  std::cout << "Hello" << std::endl;

  std::ifstream inputFile(inputFilename.c_str(), std::ifstream::in);
  std::ofstream outputFile(outputFilename.c_str(), std::ifstream::out);

  if (!inputFile.is_open())
  {
    std::cerr << "File not found: " << inputFilename << std::endl;
  }

  std::string line;
  bool beforeBegin = true;

  while (getline(inputFile, line))
  {
    if (beforeBegin)
    {
      if (line == "Prologue ")
        beforeBegin = false;
      continue;
    }

    if (line == "\014")
      continue;

    const static std::string chapterPrefix = "Chapitre ";
    if (line.compare(0, chapterPrefix.size(), chapterPrefix) == 0)
      continue;

    std::cout << line << std::endl;
    outputFile << line << std::endl;
  }

  inputFile.close();
  outputFile.close();

  return 0;
}
