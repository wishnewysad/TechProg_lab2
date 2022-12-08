#include "aeroflot.h"

#include <iostream>
#include "getdata.h"

Aeroflot::Aeroflot()
{
    std::cout << "Destination:";
    std::cin >> dest;
    if(!*dest)
        throw "Incorrect input";

    std::cout << "Flight number:";
    number = get_int();
    if(number <= 0)
        throw "Incorrect input";

    std::cout << "Aircraft type:";
    std::cin >> type;
    if(!*type)
        throw "Incorrect input";
}

Aeroflot::Aeroflot(const char* dest, unsigned int number, const char* type)
{
    for (int i = 0; dest[i] != '\0'; ++i)
        this->dest[i] = dest[i];

    this->number = number;

    for (int i = 0; type[i] != '\0'; ++i)
        this->type[i] = type[i];
}

Aeroflot::Aeroflot(const Aeroflot &copy)
{
    for (int i = 0; copy.dest[i] != '\0'; ++i)
        this->dest[i] = copy.dest[i];

    this->number = copy.number;

    for (int i = 0; copy.type[i] != '\0'; ++i)
        this->type[i] = copy.type[i];
}

char* Aeroflot::get_dest()
{
    return dest;
}

unsigned Aeroflot::get_number()
{
    return number;
}

char* Aeroflot::get_type()
{
    return type;
}

void Aeroflot::show()
{
    std::cout << "Destination: " << dest << std::endl;
    std::cout << "Flight number: " << number << std::endl;
    std::cout << "Aircraft type: " << type << std::endl;
}


