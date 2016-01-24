#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#ifndef PO_TICKET_H
#define PO_TICKET_H

using namespace std;


class ticket {
    static long nextId;
protected:
    string name;
    string address;
    string destination;
    int day;
    int month;
    int year;
    long id;

public:
    ticket(std::string);//std for IDE nervous state
    virtual void showTicket() =0;
    void setDate(int,int,int);
    void setOwner(string,string);
    void setId(long);
    long getId();
    void setNextId(long);
    ticket* operator<<(string);
    virtual void operator>> (ofstream*);
    bool operator==(long);
};


#endif //PO_TICKET_H
