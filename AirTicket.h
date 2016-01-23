#ifndef PO_AIRTICKET_H
#define PO_AIRTICKET_H


#include "ticket.h"

class AirTicket : public ticket{
public:
    AirTicket(std::string);//std for IDE nervous state
    void showTicket();
    void operator>>(ofstream*);

};


#endif //PO_AIRTICKET_H
