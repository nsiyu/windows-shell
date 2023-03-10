#pragma once
#define MAX_LINE_LENGTH 1024
#define MAX_HISTORY_LENGTH 1024

#include <string>
#include <windows.h>
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
    std::string path = "";

public:
    void run();
    void dir();
    void parse_input(char** args, char* input);
    void handle_cd_command(char** args);
    std::string get_current_dir();
    std::string get_computer_name();
    void cls();
    Shell() {
        std::cout << "My Personal Terminal [Version 0.1]" << std::endl;
        std::cout << "(c)nsiyu.All rights reserved." << std::endl << std::endl;
        working_directory += "C:\\Users\\" + get_computer_name();
        SetCurrentDirectory(working_directory.c_str());
    }
};
