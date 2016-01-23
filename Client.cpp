#include <limits>
#include "Client.h"
#include "AirTicket.h"
#include "SeaTicket.h"
#include "MixedTicket.h"

Client::Client() {
    db = new database<ticket>(DATABASE_PATH);
    showedHelp = false;
    tdb = new TargetDatabase();
}

void Client::addTicket(ticket* t) {
    db->addRegistry(t);
    cout<<"Rezerwacja dodana pomyslnie!"<<endl;
}

void Client::removeTicket(int i) {
    db->removeRegistry(i);
    cout<<"Rezerwacja usunieta!"<<endl;
}

void Client::showAllReservations() {
    if(db->length()  == 0){
        cout<<"Obecnie nie ma ani jednej rezerwacji!"<<endl;
        return;
    }
    for(int i=0;i<db->length();++i){
        cout<<"#"<<i<<": ";
        db->getRegistry(i)->showTicket();
    }
}

void Client::commands(bool * run) {
    if(!showedHelp){
        help();
        showedHelp = true;
    }
    cout<<"Podaj komende: ";
    string cmd;
    cin>>cmd;
    cin.sync();
    if(cmd.compare("travels") == 0){
        tdb->printSeaTravels();
        tdb->printAirTravels();
        tdb->printMixedTravels();
    }else if(cmd.compare("register") == 0){
        tdb->printSeaTravels();
        tdb->printAirTravels();
        tdb->printMixedTravels();
        cout<<"Podaj identyfikator podrozy: ";
        char c;
        int n;
        cin>>c;
        cin>>n;
        ticket* t;
        if(c=='L' && tdb->airLength() > n && n>=0){
            t = new AirTicket(tdb->getAirTravel(n));
        }else if(c=='M' && tdb->seaLength() > n && n>=0){
            t = new SeaTicket(tdb->getSeaTravel(n));
        }else if(c=='R' && tdb->mixedLength() > n && n>=0){
            t = new MixedTicket((std::string)tdb->getMixedTravel(n));
        }else{
            cout<<"Blad! Sprobuj ponownie! Identyfikatory podrozy dostepne po uzyciu funkcji travels"<<endl;
            return;
        }
        cout<<"Podaj imie: ";
        string name;
        cin>>name;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"Podaj nazwisko: ";
        string tmp;
        cin>>tmp;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        name.append(" ");
        name.append(tmp);
        cout<<"Miasto zamieszkania: ";
        cin>>tmp;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        t->setOwner(name, tmp);
        cout<<"Data wylotu (dd mm yyyy): ";
        int d,m,y;
        if(cin>>d && cin>>m && cin>>y)
            if(d>0 && d<32 && m>0 && m<13 && y>2015) {
                t->setDate(d, m, y);
                addTicket(t);
            }else{
                delete(t);
                cout<<"Podales niepoprawne dane! Rejestracja przerwana!"<<endl;
        }else{
            delete(t);
            cout<<"Podales niepoprawne dane! Rejestracja przerwana!"<<endl;
        }
    }else if(cmd.compare("remove") == 0){
        cout<<"Podaj idetyfikator rejstracji: ";
        int n;
        cin>>n;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        removeTicket(n);
    }else if(cmd.compare("help") == 0){
        help();
    }else if(cmd.compare("reservations") == 0){
        showAllReservations();
    }
    else if(cmd.compare("exit") == 0){
        *run = false;
    }else
        cout<<"Blad! Niepoprawna komenda!"<<endl;
}

void Client::help() {
    cout<<"***** Dostepne funkcje *****"<<endl;
    cout<<"travels : Wypisuje dostepne polaczenia"<<endl
    <<"register : Uruchamia procedure rejestracji nowego biletu"<<endl
    <<"remove : Usuwa rejestracje o podanym identyfikatorze"<<endl
    <<"reservations : Wypisuje wszystkie zapisane rejestracje"<<endl
    <<"help : Wypisuje dostepne funkcje systemu"<<endl
    <<"exit : Konczy działanie programu"<<endl
    <<"Zyczymy milego korzystania z programu!"<<endl;
}
