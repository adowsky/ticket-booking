//
// Created by ado on 06.01.16.
//
#include <string>
#ifndef PO_TICKET_H
#define PO_TICKET_H

using namespace std;

class ticket {
    string name;
    string adres;
    int day;
    int month;
    int year;

public:
    ticket();
    virtual void showTicket() =0;
    void setDate(int,int,int);
    void setOwner(string,string);

};


#endif //PO_TICKET_H
