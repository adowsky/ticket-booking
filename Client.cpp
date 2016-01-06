//
// Created by ado on 06.01.16.
//

#include "Client.h"

Client::Client() {
    db = new database<ticket>(DATABASE_PATH);
    showedHelp = false;
    tdb = new TargetDatabase();
}

void Client::addTicket(ticket* t) {
    db->addRegistry(t);
    cout<<"Rezerwacja dodana pomyślnie!"<<endl;
}

void Client::removeTicket(int i) {
    db->removeRegistry(i);
    cout<<"Rezerwacja usunięta!"<<endl;
}

void Client::showAllReservations() {
    for(int i=0;i<db->length();++i){
        db->getRegistry(i)->showTicket();
    }
}

void Client::commands(bool * run) {
    if(!showedHelp){
        help();
        showedHelp = true;
    }
    //TODO interpretacja comendy
}

void Client::help() {
    cout<<"***** Dostępne funkcje *****"<<endl;
    cout<<"travels : Wypisuje dostępne połaczenia"<<endl
    <<"register : Uruchamia procedure rejestracji nowego biletu"<<endl
    <<"remove : Usuwa rejestracje o podanym identyfikatorze"<<endl
    <<"help : Wypisuje dostepne funkcje systemu"<<endl
    <<"exit : Konczy działanie programu"<<endl
    <<"Zyczymy milego korzystania z programu!"<<endl;
}
