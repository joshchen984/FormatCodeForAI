# CMakeList.txt : CMake project for FormatCodeForAI, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (FormatCodeForAI   "FileReader.cpp" "FileReader.h" "FileWriter.cpp" "FileWriter.h" "main.cpp" "ArgParser.cpp" "ArgParser.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET FormatCodeForAI PROPERTY CXX_STANDARD 20)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC cxxopts)

target_link_libraries(${PROJECT_NAME} PUBLIC cxxopts)

# TODO: Add tests and install targets if needed.
