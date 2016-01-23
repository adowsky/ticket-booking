
#ifndef PO_SEATICKET_H
#define PO_SEATICKET_H


#include "ticket.h"

class SeaTicket : public ticket{
public:
    SeaTicket(string);
    void showTicket();
    void operator>>(ofstream*);
};


#endif //PO_SEATICKET_H
