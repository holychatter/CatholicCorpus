#include "fileparsers/livredesdemeures_parser.hpp"
#include <memory>

int main(int argc, char *argv[])
{
  auto livredesdemeures_parser = std::make_unique<LivreDesDemeures_Parser>();
  livredesdemeures_parser->run();
  return 0;
}
