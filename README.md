# Format Code For AI

FormatCodeForAI reads your code and provides a message containing the contents of your code files, which can be conveniently pasted into ChatGPT for analysis.


## Arguments

| Argument                  | Description                                                                                                                                                             | Usage                                     |
|---------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------|
| `-i, --input [folder path]`      | Specifies the folder path where the program will search for files.                                                                                                      | `--input /path/to/folder` or `-i /path/to/folder` |
| `-e, --extensions [extensions]`  | Specifies the file extensions to be considered during the search. Separate multiple extensions with commas.                                                             | `--extensions .h,.cpp,.py` or `-e .h,.cpp,.py` |
| `-x, --ignore [files]`           | Specifies a list of files to be ignored during the search. Separate multiple files with commas.                                                                        | `--ignore file1.h,file2.cpp` or `-x file1.h,file2.cpp` |
| `-o, --output [file path]`       | Specifies the file path where the program will output the message. If not provided, the message will be printed to the standard output stream.    | `--output /path/to/output.txt` or `-o /path/to/output.txt` |
| `-h, --help`                    | Displays the program's help message, providing information about the available command line options and their usage.                                                   | `--help` or `-h`                          |

## Installation

Need c++17
