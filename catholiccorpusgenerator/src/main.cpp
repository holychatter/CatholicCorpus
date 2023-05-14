#include "fileparsers/saintethereseavila_parser.hpp"
#include "fileparsers/generic_parser.hpp"
#include <memory>
#include <iostream>

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

  runGenericParser("Theologie_Catho/2_Hermeneutique_theologique/T1.txt",
                   "THESE : ");

  runGenericParser("Theologie_Catho/2_Hermeneutique_theologique/T2.txt",
                   "THESE : ");

  runGenericParser("Theologie_Catho/2_Hermeneutique_theologique/T3.txt",
                   "THESE : ");

  runGenericParser("Theologie_Catho/2_Hermeneutique_theologique/T4.txt",
                   "THESE : ");

  runGenericParser("Theologie_Catho/3_Doctrine_de_Dieu/T5.txt",
                   "[thèse non mise en forme]");

  runGenericParser("Theologie_Catho/3_Doctrine_de_Dieu/T6.txt",
                   "Thèse :");

  runGenericParser("Theologie_Catho/3_Doctrine_de_Dieu/T7.txt",
                   "         Thèse :");

  runGenericParser("Theologie_Catho/4_Ecclesiologie/T8.txt",
                   "THESE :");

  runGenericParser("Theologie_Catho/4_Ecclesiologie/T9.txt",
                   "THESE :");

  runGenericParser("Theologie_Catho/5_Theologie_sacramentelle/T10.txt",
                   "THESE :");

  runGenericParser("Theologie_Catho/5_Theologie_sacramentelle/T11.txt",
                   "THESE:");

  runGenericParser("Theologie_Catho/5_Theologie_sacramentelle/T12.txt",
                   "THESE :");

  runGenericParser("Theologie_Catho/5_Theologie_sacramentelle/T13.txt",
                   "THESE :");

  runGenericParser("Theologie_Catho/6_Anthropologie_theologique/T14.txt",
                   "THESE : ");

  runGenericParser("Theologie_Catho/6_Anthropologie_theologique/T15.txt",
                   "THESE : ");

  runGenericParser("Theologie_Catho/6_Anthropologie_theologique/T16.txt",
                   "THESE : ");

  runGenericParser("Therese_de_Lisieux/THERESE_DE_LISIEUX-Histoire_dune_ame.txt",
                   "Histoire d'une Ame");

  std::cout << "Finish to generate all files" << std::endl;

  return 0;
}
