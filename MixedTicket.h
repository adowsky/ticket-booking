#ifndef PO_MIXEDTICKET_H
#define PO_MIXEDTICKET_H


#include "ticket.h"

class MixedTicket : public ticket{

public:
    MixedTicket(std::string);//std for IDE nervous state
    void showTicket();
    void operator>>(ofstream*);

};


#endif //PO_MIXEDTICKET_H
