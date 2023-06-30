#include "FileReader.h"

#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

std::vector<std::string> FileReader::findFiles() {
  std::vector<std::string> filePaths;

  for (const auto& entry : fs::directory_iterator(mFolderPath)) {
    if (entry.is_regular_file()) {
      if (isValidFile(entry)) {
        filePaths.push_back(entry.path().string());    
      }
    } else {
      // entry is directory or special nonreadable file
    }
  }
  return filePaths;
}


bool FileReader::isValidFile(const fs::directory_entry& file) const {
  if (mFileExtensions.find(file.path().extension().string()) !=
          mFileExtensions.end() &&
      mIgnoredFiles.find(file.path().filename().string()) ==
          mIgnoredFiles.end()) {
    return true;
  }
  return false;
}
