#pragma once

#include <string>
#include <cxxopts.hpp>

#include <iostream>

class ArgParser {
 public:
  ArgParser(int argc, char* argv[]);

  
  template<typename T>
  bool getArgument(std::string, T&);

 private:
  cxxopts::ParseResult mResult;
};

template <typename T>
bool ArgParser::getArgument(std::string argument, T& container) {
  if (mResult.count(argument)) {
    container = mResult[argument].as<T>();
    return true;
  }
  return false;
}
