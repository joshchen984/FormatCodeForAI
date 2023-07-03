#pragma once

#include <string>
#include <vector>
#include <iostream>

#include <cxxopts.hpp>


class ArgParser {
 public:
  ArgParser(int argc, char* argv[]);

  std::string getInputDir() const { return mInputDir; }
  std::vector<std::string> getExtensions() const { return mExtensions; }
  std::vector<std::string> getIgnores() const { return mIgnores; }
  std::string getOutputPath() const { return mOutputPath; }
  bool isOutputToConsole() const { return mOutputToConsole; }
  bool getHelp() const { return mHelp; }
  std::string getHelpMessage() const { return mHelpMessage; }

  std::ostream& getOutputStream() const;
  bool isError() const { return mError; }
  std::string getErrorMessage() const { return mErrorMessage; }
 private:
  std::string mInputDir;
  std::vector<std::string> mExtensions;
  std::vector<std::string> mIgnores;
  std::string mOutputPath;
  bool mOutputToConsole;
  bool mHelp;
  std::string mHelpMessage;

  bool mError;
  std::string mErrorMessage;
};
