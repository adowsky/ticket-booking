#include <string>
#include <vector>
#include <fstream>

#ifndef PO_TARGETDATABASE_H
#define PO_TARGETDATABASE_H

using namespace std;

class TargetDatabase {
public:
    TargetDatabase();
    void printSeaTravels();
    void printAirTravels();
    void printMixedTravels();
    string getSeaTravel(int);
    string getAirTravel(int);
    string getMixedTravel(int);
    int seaLength();
    int airLength();
    int mixedLength();
private:
    const string DB_PATH = "travels.db";
    const string SEA_KEY = "SEA";
    const string AIR_KEY = "AIR";
    const string MIX_KEY = "MIX";
    vector<string> seaTravels;
    vector<string> airTravels;
    vector<string> mixed;

};


#endif //PO_TARGETDATABASE_H
