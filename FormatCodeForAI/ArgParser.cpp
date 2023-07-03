#include "ArgParser.h"

#include <string>
#include <iostream>
#include <fstream>

#include <cxxopts.hpp>

ArgParser::ArgParser(int argc, char* argv[]) {
  mError = false;
  cxxopts::Options options("FormatCodeForAI", "This program reads your code and provides a message containing the contents of your code files, which can be conveniently pasted into ChatGPT for analysis.");

  // clang-format off
  options.add_options()
    ("i,input", "Folder to search", cxxopts::value<std::string>())
    ("e,extensions", "File extensions to consider (optional, reads all files if not provided)", cxxopts::value<std::vector<std::string>>())
    ("x,ignore", "Files to ignore (optional)", cxxopts::value<std::vector<std::string>>())
    ("o,output", "Output file path (optional, prints to console if not provided)", cxxopts::value<std::string>())
    ("h,help", "Print usage");
  // clang-format on
  cxxopts::ParseResult result = options.parse(argc, argv);

  if (result.count("help")) {
    mHelp = result["help"].as<bool>();
    mHelpMessage = options.help();
  } else {
    mHelp = false;

    try {
      mInputDir = result["input"].as<std::string>();
    } catch (cxxopts::exceptions::exception e) {
      mError = true;
      mErrorMessage = e.what();
    }


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
  }
}

std::ostream& ArgParser::getOutputStream() const {
  if (mOutputToConsole) return std::cout;
  static std::ofstream outputStream(mOutputPath);
  return outputStream;
}
