#pragma once

#include <memory>

#include "ArgParser.h"
#include "FileReader.h"
#include "FileWriter.h"

class Application {
 public:
  Application(int argc, char* argv[]);

 private:
  ArgParser mArgs;
  FileReader mReader;
  FileWriter mWriter;
};
