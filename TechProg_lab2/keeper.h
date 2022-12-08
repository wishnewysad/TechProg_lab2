#ifndef __KEEPER_H__
#define __KEEPER_H__

#include "aeroflot.h"

class Keeper {
private:
    Aeroflot** flights;
    unsigned int count;

public:
    Keeper();
    ~Keeper();

    void show_same_type_flights(const char* type);
    void show_flights();

    void add_flight();
    void del_flight();

private:
    Aeroflot* create_new_flight();
    void append_flight_to_flights(Aeroflot* new_flight);
    void initialization(Aeroflot* flight);
    void sort_and_append(Aeroflot* flight);

    int choose_flight();
    void delete_flight_from_array(int flight);
};


#endif //__KEEPER_H__
