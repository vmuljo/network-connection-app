
#ifndef PERSON_H
#define PERSON_H

#include "Date.h"
#include "contact.h"
#include "fstream"
#include <vector>

class Person{
    friend class Network;

private:
	string f_name;
	string l_name;
	Date *birthdate;
    Email *email;
    Phone *phone;
    // the following to attributes are used in the linked list.
    Person* next;
    Person* prev;
    string uniqueId;

public: 
    Person();
    ~Person();
    Person(string filename);
    Person(string f_name, string l_name, string bdate, string email, string phone);
	void print_person();
	void set_person();
	void set_person(string filename);
    std::vector<Person*> myfriends;
    void print_friends();
    void makeFriend(Person* newFriend);
    bool operator==(const Person& rhs);
    bool operator!=(const Person& rhs);
   
};


#endif
