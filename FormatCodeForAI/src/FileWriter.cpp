#include "FileWriter.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

void FileWriter::writeFile(std::string filePath) const {
  fs::directory_entry file(filePath);

  if (file.is_regular_file()) {
    std::ifstream fileStream(filePath);
    if (fileStream.is_open()) {
      mOutputStream << "\n" << file.path().filename().string() << ":\n```\n";
      std::string line;
      while (std::getline(fileStream, line)) {
        mOutputStream << line << "\n";
      }
      mOutputStream << "```\n";

      fileStream.close();
    }
  }
}
