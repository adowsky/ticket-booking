#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#ifndef PO_TICKET_H
#define PO_TICKET_H

using namespace std;


class ticket {
protected:
    string name;
    string address;
    string destination;
    int day;
    int month;
    int year;

public:
    ticket(std::string);
    virtual void showTicket() =0;
    void setDate(int,int,int);
    void setOwner(string,string);
    ticket* operator<<(string);
    virtual void operator>> (ofstream*);
};


#endif //PO_TICKET_H
