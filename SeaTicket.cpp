
#include <iostream>
#include <fstream>
#include "SeaTicket.h"

SeaTicket::SeaTicket(std::string str) : ticket(str) { }

void SeaTicket::showTicket() {
    cout << "Rejestracja podrozy morskiej do " << destination << endl
    << "Zarejestrowane na " << name << ". Wylot: " << day << "." << month << "." << year << endl;

}
void SeaTicket::operator>>(ofstream* out) {
    *out<<"S ";
    ticket::operator>>(out);
}
