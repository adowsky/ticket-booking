//
// Created by ado on 06.01.16.
//

#ifndef PO_SEATICKET_H
#define PO_SEATICKET_H


#include "ticket.h"

class SeaTicket : ticket{
    int dock;
public:
    SeaTicket(int);
    void showTicket();
};


#endif //PO_SEATICKET_H
