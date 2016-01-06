//
// Created by ado on 06.01.16.
//

#ifndef PO_AIRTICKET_H
#define PO_AIRTICKET_H


#include "ticket.h"

class AirTicket : ticket{
    int gate;
public:
    AirTicket(int);
    void showTicket();

};


#endif //PO_AIRTICKET_H
