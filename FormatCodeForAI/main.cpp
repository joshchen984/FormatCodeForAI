#include <iostream>
#include <set>

#include "FileReader.h"
#include "FileWriter.h"

int main(int argc, char *argv[]) {
  std::vector<std::string> testExts{".cpp", ".h"};
  std::vector<std::string> testIgnores;

  FileReader displayer("C:/Users/joshc/projects/cpp/Game/Game", testExts,
                          testIgnores);
  FileWriter writer(std::cout);
  auto files = displayer.getFiles();

  for (auto file : files) {
    writer.writeFile(file);
  }
}
