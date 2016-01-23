#ifndef PO_AIRTICKET_H
#define PO_AIRTICKET_H


#include "ticket.h"

class AirTicket : public ticket{
public:
    AirTicket(std::string);
    void showTicket();
    void operator>>(ofstream*);

};


#endif //PO_AIRTICKET_H
