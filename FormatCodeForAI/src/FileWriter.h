#pragma once

#include <iostream>

class FileWriter {
 public:
  FileWriter(std::ostream& os) : mOutputStream(os){}
  void writeFile(std::string) const;

 private:
  std::ostream& mOutputStream;
};
