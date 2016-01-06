//
// Created by ado on 06.01.16.
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
            in>>buffer;
            if(buffer.compare(SEA_KEY) == 0){
                current = &seaTravels;
            }else if(buffer.compare(AIR_KEY) == 0){

            }else if(buffer.compare(MIX_KEY) == 0){

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
    cout<<"POLACZENIA MORSKIE"<<endl;
    for(int i=0; i<seaTravels.size();++i){
        cout<<i<<" "<<seaTravels[i]<<endl;
    }
}

void TargetDatabase::printAirTravels() {
    cout<<"POLACZENIA POWIETRZNE"<<endl;
    for(int i=0; i<airTravels.size();++i){
        cout<<i<<" "<<airTravels[i]<<endl;
    }
}

void TargetDatabase::printMixedTravels() {
    cout<<"POLACZENIA MIESZANE"<<endl;
    for(int i=0; i<mixed.size();++i){
        cout<<i<<" "<<mixed[i]<<endl;
    }
}

//Class test
/**
int main(){
    TargetDatabase* db = new TargetDatabase();
    db->printSeaTravels();
    db->printAirTravels();
    db->printMixedTravels();
    return 0;
}*/
