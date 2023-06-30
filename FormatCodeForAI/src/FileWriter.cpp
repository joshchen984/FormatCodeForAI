#include "FileWriter.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

void FileWriter::writeFile(std::string filePath) const {
  if (fs::exists(filePath) && fs::is_regular_file(filePath)) {
    std::ifstream file(filePath);
    if (file.is_open()) {
      mOutputStream << "```\n";
      std::string line;
      while (std::getline(file, line)) {
        mOutputStream << line << "\n";
      }
      mOutputStream << "```\n";

      file.close();
    }
  }
}
