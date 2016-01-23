#include <iostream>
#include <fstream>
#include "MixedTicket.h"

MixedTicket::MixedTicket(std::string str) : ticket(str) {

}

void MixedTicket::showTicket() {
    cout<<"(L): podroz lotnicza, (M): podroz morska"<<endl;
    cout<<"Rejestracja podrozy mieszanej do "<<destination<<endl
    <<"Zarejestrowane na "<<name<<". Wylot: "<<day<<"."<<month<<"."<<year<<endl;

}

void MixedTicket::operator>>(ofstream* out) {
    *out<<"M ";
    ticket::operator>>(out);
}