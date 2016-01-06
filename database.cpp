//
// Created by ado on 06.01.16.
//
#include <vector>
#include <string>
using namespace std;
template <class T>
class database{
    vector<T*> db;

public:
    database(string);
    void addRegistry(T*);
    T* getRegistry(int);
    void removeRegistry(int);
    int length();

};