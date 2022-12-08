#ifndef __AEROFLOT_H__
#define __AEROFLOT_H__

class Aeroflot {
private:
    char dest[64];
    unsigned number;
    char type[64];

public:
    Aeroflot();
    Aeroflot(const char* dest, unsigned number, const char* type);
    Aeroflot(const Aeroflot& copy);

    char* get_dest();
    unsigned get_number();
    char* get_type();

    void show();
};

#endif //__AEROFLOT_H__
