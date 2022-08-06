
#ifndef NETWORK_H
#define NETWORK_H

#include "person.h"
#include "Date.h"
// You may need to add more libraries 
#include <stdlib.h>
class Network{

    private:
        Person* head;
        Person* tail;
        int count; 
        Person* search(Person* searchEntry);
        Person* search(string fname, string lname);

    public:
        Network();
        Network(string fileName);
        ~Network();
        void push_front(Person* newEntry);
        void push_back(Person* newEntry);
        void printDB();
        bool remove(string fname, string lname);
        void showMenu();
};

#endif
