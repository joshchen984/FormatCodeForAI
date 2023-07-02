#include "Application.h"

#include <memory>

#include "ArgParser.h"
#include "FileWriter.h"

Application::Application(int argc, char* argv[])
    : mArgs(argc, argv), mReader(mArgs.getInputDir(), mArgs.getExtensions(), mArgs.getIgnores()), mWriter(mArgs.getOutputStream()) {

}
