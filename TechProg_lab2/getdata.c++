#include "getdata.h"

#include <iostream>
#include <limits>

int get_int() {
    int temp;
    std::cin >> temp;
    while (std::cin.fail() || std::cin.get() != '\n') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.sync();
        std::cout << "Enter again:";
        std::cin >> temp;
    }
    return temp;
}