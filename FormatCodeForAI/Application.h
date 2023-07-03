#pragma once

#include <string>

#include "ArgParser.h"
#include "FileReader.h"
#include "FileWriter.h"

class Application {
 public:
  Application(int argc, char* argv[])
      : mArgs(argc, argv),
        mReader(mArgs.getInputDir(), mArgs.getExtensions(), mArgs.getIgnores()),
        mWriter(mArgs.getOutputStream()) {}

  bool isHelp() const { return mArgs.getHelp(); }
  std::string getHelpMessage() const { return mArgs.getHelpMessage(); }

  void run() const;
 private:
  ArgParser mArgs;
  FileReader mReader;
  FileWriter mWriter;
};
