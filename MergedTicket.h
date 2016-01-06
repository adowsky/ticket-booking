//
// Created by ado on 06.01.16.
//

#ifndef PO_MERGEDTICKET_H
#define PO_MERGEDTICKET_H


#include "ticket.h"

class MixedTicket : ticket{
    ticket* travel;
    int length;
public:
    MixedTicket();
    void showTicket();
    void addTravel(ticket*);
};


#endif //PO_MERGEDTICKET_H
