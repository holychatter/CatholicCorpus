#include "fileparsers/saintethereseavila_parser.hpp"
#include "fileparsers/generic_parser.hpp"
#include <memory>

namespace
{
void runGenericParser(const std::string& pFileName,
                      const std::string& pFirstLine)
{
  auto parser = std::make_unique<Generic_Parser>(pFileName, pFirstLine);
  parser->run();
}

}

int main(int argc, char *argv[])
{
  {
    auto saintethereseavila_parser = std::make_unique<SainteThereseAvila_Parser>(
          "Carmel/SainteThereseAvila/livre_des_demeures.txt",
          "Prologue ");
    saintethereseavila_parser->run();
  }

  {
    auto saintethereseavila_parser = std::make_unique<SainteThereseAvila_Parser>(
          "Carmel/SainteThereseAvila/le_chemin_de_perfection.txt",
          "Prologue ");
    saintethereseavila_parser->run();
  }

  {
    auto saintethereseavila_parser = std::make_unique<SainteThereseAvila_Parser>(
          "Carmel/SainteThereseAvila/les_relations-2.txt",
          "Relation 1 - 1560 ");
    saintethereseavila_parser->run();
  }

  runGenericParser("Theologie_Catho/1_Methaphysique/M1.txt",
                   " Hamlet, II.2 ");

  runGenericParser("Theologie_Catho/1_Methaphysique/M2.txt",
                   "CRITIQUE DU REALISME : ");

  runGenericParser("Theologie_Catho/1_Methaphysique/M3.txt",
                   "Introduction : le tournant idéaliste de la métaphysique ");

  return 0;
}
