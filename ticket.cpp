#include <fstream>
#include "ticket.h"
#include "AirTicket.h"
#include "SeaTicket.h"
#include "MixedTicket.h"

long ticket::nextId = 0;

ticket::ticket(std::string dest) {//std for IDE nervous state
    this->destination = dest;
    id = nextId++;
}

void ticket::setDate(int d, int m, int y) {
    this->day = d;
    this->month = m;
    this->year = y;
}

void ticket::setOwner(string name, string address) {
    this->name = name;
    this->address = address;
}
void ticket::setId(long i){
    this->id=i;
    if(nextId <= id)
        nextId = id+1;
}
long ticket::getId(){
    return id;
}
void ticket::setNextId(long next) {
    this->nextId = next;
}
ticket *ticket::operator<<(string s) {
        ticket* result;
        stringstream ss;
        ss<<s;
        char type;
        ss>>type;
    long id;
    ss >> id;
        int len = 0;
        ss>>len;
        char* tmp = new char[len + 1];
        ss.read(&tmp[0], 1);
        ss.read(&tmp[0], len);
        string dst;
        dst.assign(&tmp[0], len);
        if(type == 'A'){
            result = new AirTicket(dst);
        }else if(type == 'S'){
            result = new SeaTicket(dst);
        }else if(type == 'M'){
            result = new MixedTicket(dst);
        }else
            return nullptr;
        result->id = id;
        if(id >= nextId){
            nextId = id+1;
        }
        ss>>len;
        delete[](tmp);
        tmp = new char[len + 1];
        ss.read(&tmp[0], 1);
        ss.read(&tmp[0], len);
        result->name.assign(&tmp[0], len);
        delete[](tmp);
        ss>>len;
        tmp = new char[len + 1];
        ss.read(&tmp[0], 1);
        ss.read(&tmp[0], len);
        result->address.assign(&tmp[0], len);
        delete[](tmp);
        ss>>result->day;
        ss>>result->month;
        ss>>result->year;
        return result;
}

void ticket::operator>>(ofstream* out) {
    stringstream ss;
    ss<<id<<" "<<destination.length()<<" "<<destination <<" "
    <<name.length()<<" "<<name<<" "
    <<address.length()<<" "<<address<<" "
    <<day<<" "<<month<<" "<<year<<endl;
    *out<<ss.rdbuf();
}

bool ticket::operator==(long i) {
    return (i == id);
}
