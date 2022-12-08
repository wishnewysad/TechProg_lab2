#include <iostream>

#include "keeper.h"
#include "file_utils.h"
#include "getdata.h"

#define MAX_BUFFER 64

void try_delete_flight(Keeper& UI)
{
    try {
        UI.del_flight();
    }
    catch (const char* msg){
        std::cout << msg << std::endl;
    }
}

void try_show_flights(Keeper& UI)
{
    try {
        UI.show_flights();
    }
    catch (const char* msg){
        std::cout << msg << std::endl;
    }
}

void try_show_flights_with_certain_type(Keeper& UI)
{
    char type[MAX_BUFFER];
    std::cout << "Type:";
    std::cin >> type;
    try {
        UI.show_same_type_flights(type);
    }
    catch (const char* msg){
        std::cout << msg << std::endl;
    }
}

void keeper_switch(Keeper& UI, const int& choice, bool& work)
{
    switch (choice) {
        case 1:
            UI.add_flight();
            break;
        case 2:
            try_delete_flight(UI);
            break;
        case 3:
            try_show_flights(UI);
            break;
        case 4:
            try_show_flights_with_certain_type(UI);
            break;
        default:
            work = false;
            break;
    }
}

void aeroflot_loop()
{
    Keeper UI;
    int choice;
    bool work = true;

    do {
        std::cout << "1. Add new flight\n"
                     "2. Delete flight\n"
                     "3. Show all flights\n"
                     "4. Show flights with same type\n"
                     "5. Exit" << std::endl;

        std::cin >> choice;

        keeper_switch(UI, choice, work);
    } while (work);
}

void file()
{
    try {
        char file_name[MAX_BUFFER];
        std::cout << "File name:";
        std::cin >> file_name;
        read_from_file(file_name);

    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

void main_switch(const int& choice, bool& work)
{
    switch (choice) {
        case 1:
            aeroflot_loop();
            break;

        case 2:
            file();
            break;

        case 3:
            work = false;
            break;

        default:
            std::cout << "Incorrect input" << std::endl;
            break;
    }
}

void main_loop()
{
    int choice;
    bool work = true;
    do {
        std::cout << "1. AEROFLOT\n"
                     "2. File\n"
                     "3. Exit" << std::endl;
        choice = get_int();

        main_switch(choice, work);
    } while (work);
}

int main()
{
    main_loop();

    return 0;
}