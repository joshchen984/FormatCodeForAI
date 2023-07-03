#include "Application.h"

#include <string>
#include <vector>
#include <stdexcept>

void Application::run() const {

  if (mArgs.isError()) throw std::invalid_argument(mArgs.getErrorMessage());
  std::vector<std::string> filePaths = mReader.getFiles();

  for (std::string& file : filePaths) {
    mWriter.writeFile(file);
  }
}
