#include <iostream>
#include <exception>

#include <cxxopts.hpp>

#include "Application.h"

int main(int argc, char *argv[]) {

  Application app(argc, argv);
  if (app.isHelp()) {
    std::cout << app.getHelpMessage() << std::endl;
    return 0;
  }
  try {
    app.run();
  } catch (std::exception e) {
    std::cout << e.what() << std::endl;
    return 1;
  }

  return 0;
}
