#include <iostream>
#include <set>
#include <vector>
#include <string>

#include <cxxopts.hpp>

#include "FileReader.h"
#include "FileWriter.h"
#include "ArgParser.h"

int main(int argc, char *argv[]) {

  ArgParser arg(argc, argv);
  bool help = false;
  arg.getArgument<bool>("help", help);

  std::cout << help << std::endl;

  std::vector<std::string> testExts{".cpp", ".h"};
  std::vector<std::string> testIgnores;

  FileReader displayer("C:/Users/joshc/projects/cpp/Game/Game", testExts,
                          testIgnores);
  FileWriter writer(std::cout);
  auto files = displayer.getFiles();

  for (std::string& file : files) {
    writer.writeFile(file);
  }
}
