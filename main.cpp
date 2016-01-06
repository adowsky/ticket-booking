#include <iostream>
#include "Client.h"

using namespace std;

int main() {
    Client* c = new Client();
    bool run = true;
    cout<<"********************************************"<<endl<<
          "******** System rezerwacji biletow *********"<<endl<<
          "********************************************"<<endl;
    while(run){
        c->commands(&run);
    }
    return 0;
}