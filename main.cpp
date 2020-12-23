#include <stdio.h>
#include <string.h>
#include <getopt.h>

int main(int argc, char** argv) {
    const char* helpMessage = "Options:\n"
        "-h, --help - get help message\n"
        "-v, --version - print version of program\n"
        "-l[<val1>,...], --list=[<num1>,...] - print list of arguments\n";

    struct visited {
        bool h = false;
        bool l = false;
        bool v = false;
    }visited;

    static struct option longopts[] = {
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'v'},
        {"list", required_argument, 0, 'l'},
        {0, 0, 0, 0},
    };

    const char* optstring = "hvl:";
    int option_index;
    int rez;


    while ((rez = getopt_long(argc, argv, optstring,
        longopts, &option_index)) != -1) {
        switch (rez) {
            case 'h': {
                if (!visited.h) {
                    printf("%s\n", helpMessage);
                    visited.h = true;
                }
                break;
            }
            case 'v': {
                if (!visited.v) {
                    printf("version: 0.1.0\n");
                    visited.v = true;
                }
                break;
            }
            case 'l': {
                if (!visited.l) {
                    printf("List arguments: { ");
                    char* elem = strtok(optarg, ",");
                    while (elem != NULL) {
                        printf("%s ", elem);
                        elem = strtok(NULL, ",");
                    }
                    printf("}\n");
                    visited.l = true;
                }
                break;
            }
            default: {
                printf("type -h to see the list of arguments\n");
                return 0;
            }
        }
    }
    return 0;
}