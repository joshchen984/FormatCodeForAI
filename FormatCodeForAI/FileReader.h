#pragma once

#include <string>
#include <vector>
#include <set>
#include <filesystem>

class FileReader {
 public:
  explicit FileReader(const std::string& folderPath): mFolderPath(folderPath), mFileExtensions(), mIgnoredFiles() {}
  FileReader(const std::string& folderPath,
                const std::vector<std::string>& fileExtensions,
                const std::vector<std::string>& ignoredFiles)
      : mFolderPath(folderPath), mFileExtensions(fileExtensions.begin(), fileExtensions.end()), mIgnoredFiles(ignoredFiles.begin(), ignoredFiles.end()) {}

  std::vector<std::string> getFiles();
 private:
  std::string mFolderPath;
  std::set<std::string> mFileExtensions;
  std::set<std::string> mIgnoredFiles;

  bool isValidFile(const std::filesystem::directory_entry&) const;
};
