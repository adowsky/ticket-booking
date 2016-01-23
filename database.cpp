#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

template <class T>
class database{
    vector<T*> db;
    string path;
public:
    database(std::string);//std for IDE nervous state
    void addRegistry(T*);
    T* getRegistry(int);
    void removeRegistry(int);
    int length();
    database* operator+=(T* t){
        this->addRegistry(t);
        return this;
    }
    database* operator-=(int i){
        this->removeRegistry(i);
        return this;
    }

};
template <class T>
database<T>::database (string path)
{
    this->path = path;
    ifstream in;
    in.open(path);
    T* tmp;
    if(in.is_open() && !in.eof()){
        while(!in.eof()) {
            string s;
            getline(in, s);
            if(s.length() > 0) {
                db.push_back((T *) (*tmp << s));
            }
        }
        in.close();
    }else{
        cout<<"Brak bazy rejestracji. Zostanie utworzona nowa baza!"<<endl;
    }
}
template <class T>
void database<T>::addRegistry(T *t) {
    db.push_back(t);
    ofstream out;
    out.open(path, ios::app);
    if(out.is_open()) {
        *t >> &out;
        out.close();
    }
}
template<class T>
T *database<T>::getRegistry(int i) {
    return db[i];
}
template<class T>
void database<T>::removeRegistry(int i) {
    if(i<db.size() && i>=0)
    {
        fstream out;
        fstream tmp;
        out.open(path, ios::in);
        tmp.open("tmp", ios::out);
        string s;
        for (int j = 0; j < i; ++j) {
            getline(out, s);
            tmp << s << endl;
        }
        getline(out, s);
        for (int j = i+1; j < db.size();++j){
            getline(out, s);
            tmp << s << endl;
        }
        out.close();
        tmp.close();
        out.open(path, ios::out);
        tmp.open("tmp", ios::in);
        out << tmp.rdbuf();
        out.close();
        tmp.close();
        db.erase(db.begin() + i);
    }
}
template<class T>
int database<T>::length() {
    return db.size();
}
