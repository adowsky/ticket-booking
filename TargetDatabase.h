//
// Created by ado on 06.01.16.
//
#include <string>
#include <vector>
#ifndef PO_TARGETDATABASE_H
#define PO_TARGETDATABASE_H

using namespace std;

class TargetDatabase {
public:
    TargetDatabase();
    void printSeaTravels();
    void printAirTravels();
    void printMixedTravels();
private:
    const string db_path = "travels.db";
    vector<string> seaTravels;
    vector<string> airTravels;
    vector<string> mixed;

};


#endif //PO_TARGETDATABASE_H
