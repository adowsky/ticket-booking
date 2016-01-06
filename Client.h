#include "database.cpp"
#include "ticket.h"
#include "TargetDatabase.h"
#include <vector>
#include <string>
#include <iostream>
#ifndef PO_CLIENT_H
#define PO_CLIENT_H

using namespace std;

class Client {
public:
    Client();
    void addTicket(ticket*);
    void removeTicket(int);
    void showAllReservations();
    void commands(bool*);
    void help();
private:
    database<ticket>* db;
    TargetDatabase* tdb;
    string DATABASE_PATH = "tickets.db";
    bool showedHelp;
};


#endif //PO_CLIENT_H
