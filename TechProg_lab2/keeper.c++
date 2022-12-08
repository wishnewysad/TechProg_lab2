#include "keeper.h"

#include <iostream>
#include "getdata.h"
#include <cstring>

Keeper::Keeper()
{
    count = 0;
    flights = nullptr;
}

Keeper::~Keeper()
{
    for (int i = 0; i < count; ++i) {
        delete flights[i];
    }

    delete[] flights;
}

void Keeper::show_same_type_flights(const char* type)
{
    if (count == 0)
        throw "There are no flights";

    bool isSame = false;
    for (int i = 0, j = 0; i < count; ++i) {
        if (!strcmp(flights[i]->get_type(), type)){
            std::cout << j++ + 1 << "." << std::endl;
            flights[i]->show();
            isSame = true;
        }
    }
    if (!isSame)
        std::cout << "There are no same type" << std::endl;

}

void Keeper::show_flights()
{
    if (count == 0)
        throw "There are no flights";

    for (int i = 0; i < count; ++i) {
        std::cout << i + 1 << ":" << std::endl;
        flights[i]->show();
    }
}

void Keeper::add_flight()
{
    Aeroflot* new_flight = create_new_flight();

    append_flight_to_flights(new_flight);
}


void Keeper::del_flight()
{
    if (count == 0)
        throw "There are no flights";

    int choice = choose_flight();

    delete_flight_from_array(choice);
}

void Keeper::delete_flight_from_array(int flight)
{
    auto** new_flights = new Aeroflot * [count - 1];
    for (int i = 0, j = 0; i < count; ++i) {
        if(i == (flight-1))
            continue;
        new_flights[j++] = flights[i];
    }
    --count;
    delete[] flights;
    flights = new_flights;
}

int Keeper::choose_flight()
{
    int choice;
    show_flights();
    std::cout << "Choose flight" << std::endl;
    choice = get_int();
    if(choice <= 0 || choice > count)
        throw "There is no such flight";

    return choice;
}

Aeroflot* Keeper::create_new_flight()
{
    auto* flight = new Aeroflot();

    return flight;
}

void Keeper::append_flight_to_flights(Aeroflot *new_flight)
{
    if (count == 0)
        initialization(new_flight);
    else
        sort_and_append(new_flight);
}

void Keeper::sort_and_append(Aeroflot *flight)
{
    Aeroflot** new_flights = new Aeroflot * [count + 1];
    bool isInsert = false;
    for (int i = 0, j = 0; i < count;) {
        if (strcmp(flights[i]->get_dest(), flight->get_dest()) >= 0 && !isInsert){
            new_flights[j++] = flight;
            isInsert = true;
        }
        new_flights[j++] = flights[i++];
    }

    ++count;
    if(!isInsert)
        new_flights[count - 1] = flight;

    delete[] flights;
    flights = new_flights;
}

void Keeper::initialization(Aeroflot* flight)
{
    flights = new Aeroflot*[1];
    flights[0] = flight;
    ++count;
}