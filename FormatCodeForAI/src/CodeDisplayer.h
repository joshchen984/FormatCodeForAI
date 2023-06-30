#pragma once

#include <string>
#include <vector>
#include <set>
#include <filesystem>
#include <iostream>

class CodeDisplayer {
 public:
  CodeDisplayer(const std::string &folderPath, std::ostream& os) : mFileExtensions(), mIgnoredFiles(), mFolderPath(folderPath), mOutputStream(os) {}
  CodeDisplayer(const std::string& folderPath,
                const std::vector<std::string>& fileExtensions,
                const std::vector<std::string>& ignoredFiles, std::ostream& os)
      : mFolderPath(folderPath), mFileExtensions(fileExtensions.begin(), fileExtensions.end()), mIgnoredFiles(ignoredFiles.begin(), ignoredFiles.end()), mOutputStream(os) {}
  void createMessage() const;

 private:
  std::set<std::string> mFileExtensions;
  std::set<std::string> mIgnoredFiles;
  std::string mFolderPath;
  std::ostream& mOutputStream;

  bool isValidFile(const std::filesystem::directory_entry&) const;
  void display(std::string) const;
};
