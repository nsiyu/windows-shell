#pragma once
#define MAX_LINE_LENGTH 1024
#define MAX_HISTORY_LENGTH 1024

#include <string>
#include <iostream>
class Shell {
private:
    char history[MAX_HISTORY_LENGTH][MAX_LINE_LENGTH];
    int history_index;
    int history_length;
    int current_index;
    char input[MAX_LINE_LENGTH];
    char* args[MAX_LINE_LENGTH / 2 + 1];
    std::string working_directory = "";

public:
    void run();
    void parse_input(char** args, char* input);
    void handle_cd_command(char** args);
    std::string get_current_dir();
    std::string get_computer_name();
    Shell() {
        std::cout << "Microsoft Windows [Version 10.0.22621.963]" << std::endl;
        std::cout << "(c)Microsoft Corporation.All rights reserved." << std::endl << std::endl;
        working_directory += "C:\\Users\\" + get_computer_name() + ">";
    }
};
