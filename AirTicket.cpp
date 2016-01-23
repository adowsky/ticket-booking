
#include <iostream>
#include <fstream>
#include "AirTicket.h"

AirTicket::AirTicket(std::string str) : ticket(str) {}    //std for IDE nervous state

void AirTicket::showTicket() {
    cout<<"Rejestracja podrozy lotniczej do "<<destination<<endl
    <<"Zarejestrowane na "<<name<<". Wylot: "<<day<<"."<<month<<"."<<year<<endl;

}

void AirTicket::operator>>(ofstream* out) {
    *out<<"A ";
    ticket::operator>>(out);
}
