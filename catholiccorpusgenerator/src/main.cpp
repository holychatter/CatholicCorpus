#include "fileparsers/saintethereseavila_parser.hpp"
#include "fileparsers/generic_parser.hpp"
#include <memory>

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

  {
    auto parser = std::make_unique<Generic_Parser>(
          "Theologie_Catho/1_Methaphysique/M1.txt",
          " Hamlet, II.2 ");
    parser->run();
  }
  return 0;
}
