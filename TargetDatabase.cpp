//
// Database for travels.
//

#include <iostream>
#include "TargetDatabase.h"


TargetDatabase::TargetDatabase() {
    ifstream in;
    in.open(DB_PATH, ios::in);
    if(in.is_open()){
        vector<string>* current;
        string buffer;
        while(!in.eof()){
            getline(in, buffer);
            if(buffer.compare(SEA_KEY) == 0){
                current = &seaTravels;
            }else if(buffer.compare(AIR_KEY) == 0){
                current = &airTravels;
            }else if(buffer.compare(MIX_KEY) == 0){
                current = &mixed;
            }else{
                current->push_back(buffer);
            }
        }
        in.close();
    }else{
        cout<<"Problem z plikiem! Program moze nie dzialac prawidlowo"<<endl;
    }
}

void TargetDatabase::printSeaTravels() {
    cout<<"POLACZENIA MORSKIE \t"<<"Ilosc: "<<seaTravels.size()<<endl;
    for(int i=0; i<seaTravels.size();++i){
        cout<<"M"<<i<<" "<<seaTravels[i]<<endl;
    }
}

void TargetDatabase::printAirTravels() {
    cout<<"POLACZENIA POWIETRZNE\t"<< "Ilosc: "<<airTravels.size()<<endl;
    for(int i=0; i<airTravels.size();++i){
        cout<<"L"<<i<<" "<<airTravels[i]<<endl;
    }
}

void TargetDatabase::printMixedTravels() {
    cout<<"POLACZENIA MIESZANE\t"<<"Ilosc: "<<mixed.size()<<endl;
    for(int i=0; i<mixed.size();++i){
        cout<<"R"<<i<<" "<<mixed[i]<<endl;
    }
}

string TargetDatabase::getSeaTravel(int i) {
    return seaTravels[i];
}

string TargetDatabase::getAirTravel(int i) {
    return airTravels[i];
}

string TargetDatabase::getMixedTravel(int i) {
    return mixed[i];
}

int TargetDatabase::seaLength() {
    return seaTravels.size();
}

int TargetDatabase::airLength() {
    return airTravels.size();
}

int TargetDatabase::mixedLength() {
    return mixed.size();
}
