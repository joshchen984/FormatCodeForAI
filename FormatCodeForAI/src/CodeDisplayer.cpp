#include "CodeDisplayer.h"

#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

void CodeDisplayer::createMessage() const {
  for (const auto& entry : fs::directory_iterator(mFolderPath)) {
    if (entry.is_regular_file()) {
      if (isValidFile(entry)) {
        // format file
      }
    } else {
      // entry is directory or special nonreadable file
    }
  }
}

void CodeDisplayer::display(std::string filePath) const {
  if (fs::exists(filePath) && fs::is_regular_file(filePath)) {
    std::ifstream file(filePath);
    if (file.is_open()) {
      //
    }
  }
}

bool CodeDisplayer::isValidFile(const fs::directory_entry& file) const {
  if (mFileExtensions.find(file.path().extension().string()) !=
          mFileExtensions.end() &&
      mIgnoredFiles.find(file.path().filename().string()) ==
          mIgnoredFiles.end()) {
    return true;
  }
  return false;
}
