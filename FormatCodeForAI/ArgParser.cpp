#include "ArgParser.h"

#include <string>

ArgParser::ArgParser(int argc, char* argv[]) {
  cxxopts::Options options("FormatCodeForAI", "This program...");

  // clang-format off
  options.add_options()
    ("i,input", "Folder to search", cxxopts::value<std::string>())
    ("e,extensions", "File extensions to read", cxxopts::value<std::vector<std::string>>())
    ("x,ignore", "Files to ignore", cxxopts::value<std::vector<std::string>>())
    ("o,output", "Output file path", cxxopts::value<std::string>())
    ("h,help", "Print usage");
  // clang-format on
  mResult = options.parse(argc, argv);
  //  if (result.count("help")) {
  //  std::cout << options.help() << std::endl;
  //  return 0;
  //}
}

