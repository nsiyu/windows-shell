#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "Shell.h"
#include <iostream>

#define MAX_LINE_LENGTH 1024
#define MAX_HISTORY_LENGTH 1024

//Runs the program
void Shell::run() {
    while (true) {
        std::cout << get_current_dir();
        fgets(input, MAX_LINE_LENGTH, stdin);
        parse_input(args, input);
        if (strcmp(args[0], "exit") == 0) {
            break;
        }
        else if (strcmp(args[0], "cd") == 0) {
            handle_cd_command(args);
        }
        else if (strcmp(args[0], "cls") == 0) {
            cls();
        }
        else {
            std::cout << "\'" << args[0] << "\'" << " is not recognized as an internal or external command," << std::endl;
            std::cout << "operable program or batch file." << std::endl;
        }
    }
}

//Parses the first word in input into args[0] in proper format
void Shell::parse_input(char** args, char* input) {
    int i = 0;
    while (*input != '\0') {
        // Skip leading whitespace
        while (*input == ' ' || *input == '\t') {
            input++;
        }
        // End of input reached
        if (*input == '\0') {
            break;
        }
        // Save start of argument
        args[i++] = input;
        // Find end of argument
        bool in_quotes = false;
        while (*input != '\0' && (!isspace(*input) || in_quotes)) {
            if (*input == '\\') {
                input++;
                if (*input == '\0') {
                    break;
                }
            }
            else if (*input == '"') {
                in_quotes = !in_quotes;
            }
            input++;
        }
        // Terminate argument
        if (*input != '\0') {
            *input++ = '\0';
        }
    }
    args[i] = NULL;
}

//Changes from one directory to another
void Shell::handle_cd_command(char** args) {
    if (input == NULL) {
        fprintf(stderr, "Error: expected a directory path\n");
    }
    else {
        if (SetCurrentDirectory(input) == 0) {
            fprintf(stderr, "Error: failed to change directory\n");
        }
    }
}

//Gets the current working directory
std::string Shell::get_current_dir() {
    return working_directory;
}

//Gets user PC name
std::string Shell::get_computer_name() {
    // Get the size of the computer name
    DWORD size = MAX_COMPUTERNAME_LENGTH + 1;
    std::string name(size, '\0');

    // Get the computer name
    if (GetComputerNameEx(ComputerNameDnsHostname, &name[0], &size)) {
        // Trim the string to the actual size
        name.resize(size);
        return name;
    }
    else {
        // Return an empty string on error
        return "";
    }
}

void Shell::cls() {
    std::system("cls");
}