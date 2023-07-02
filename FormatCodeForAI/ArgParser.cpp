#include "ArgParser.h"

#include <string>
#include <iostream>
#include <fstream>

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
  cxxopts::ParseResult result = options.parse(argc, argv);

  mInputDir = result["input"].as<std::string>();

  if (result.count("extensions")) {
    mExtensions = result["extensions"].as<std::vector<std::string>>();
  }
  if (result.count("ignore")) {
    mIgnores = result["ignore"].as<std::vector<std::string>>();
  }

  if (result.count("output")) {
    mOutputPath = result["output"].as<std::string>();
    mOutputToConsole = false;
  } else {
    mOutputToConsole = true;
  }

  if (result.count("help")) {
    mHelp = result["help"].as<bool>();
  } else {
    mHelp = false;
  }
  mHelpMessage = options.help();
}

std::ostream& ArgParser::getOutputStream() const {
  if (mOutputToConsole) return std::cout;
  std::ofstream outputStream(mOutputPath);
  return outputStream;
}
