
#include "person.h"
#include "misc.h"
// g++ person_test.cpp contact.cpp person.cpp Date.cpp -o test_person

Person::Person(){
    // I'm already done! 
    set_person();
}


Person::~Person(){
    delete birthdate;
    delete phone;
    delete email;
    // TODO: complete the method!
}


Person::Person(string fname, string lname, string bdate, string email, string phone){
    // TODO: Complete this method!
    // phone and email strings are in full version  
    f_name = fname;
    l_name = lname;
    birthdate = new Date(bdate);
    this->email = new Email("" ,email);
    this->phone = new Phone("", phone);
    uniqueId = codeName(f_name, l_name);

}


Person::Person(string filename){
    set_person(filename);
}


void Person::set_person(){
    // prompts for the information of the user from the terminal
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    // TODO: complete this method!
    
    string temp;
    string type;

    cout << "First Name: ";
    // pay attention to how we read first name, as it can have spaces!
    std::getline(std::cin,f_name);

	cout << "Last Name: ";
    std::getline(std::cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,temp);
    // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(temp); 

    cout << "Type of email address: ";
    // code here
    std::getline(std::cin, type);
    cout << "Email address: ";
    std::getline(std::cin, temp);
    email = new Email(type, temp);
    // code here

    cout << "Type of phone number: ";
    // code here
    std::getline(std::cin, type);
    cout << "Phone number: ";
    std::getline(std::cin, temp);
    phone = new Phone(type, temp);
    
    uniqueId = codeName(f_name, l_name);
}


void Person::set_person(string filename){
    // reads a Person from a file
    // Look at person_template files as examples.     
    // Phone number in files can have '-' or not.
    // TODO: Complete this method!
    ifstream personInfo(filename);
    ofstream test("test.txt");
    string temp;
    if(personInfo.is_open()){
        std::getline(personInfo, temp);
        f_name = temp.substr(0, temp.length()-1); //Did this because getline seemed to have added the newline character to the end of f_name or l_name, which caused the output to not run properly.
        
        // test << temp.substr(0, temp.length()-1);
        std::getline(personInfo, temp);
        l_name = temp.substr(0, temp.length()-1);
        // test << l_name << f_name;
        std::getline(personInfo, temp);
        // cout << l_name;
        birthdate = new Date(temp);

        std::getline(personInfo, temp);
        string type_ = temp.substr(1, temp.find(')')-1);
        temp = temp.substr(temp.find(' ')+1, temp.length()-1);
        phone = new Phone(type_, temp);
        
        std::getline(personInfo, temp);
        type_ = temp.substr(1, temp.find(')')-1);
        cout << type_ << endl;
        temp = temp.substr(temp.find(' ')+1, temp.length()-1);
        email = new Email(type_, temp);

        uniqueId = codeName(f_name, l_name);
    }
    // cout << l_name;
    personInfo.close();
    // cout << l_name << "0";

    // test << l_name << ", " << f_name << endl;
}

void Person::makeFriend(Person* newFriend){
    myfriends.push_back(newFriend);
}

bool Person::operator==(const Person& rhs){
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
    if ( (f_name == rhs.f_name) && 
         (l_name == rhs.l_name) && 
         (*birthdate == *rhs.birthdate) /*&&
         (*email == *rhs.email) &&
         (*phone == *rhs.phone)*/)
        return true;
    else
        return false;
}

bool Person::operator!=(const Person& rhs){ 
    // TODO: Complete this method!
    return !(*this == rhs);
}

void Person::print_friends(){
    for(int i = 0; i<myfriends.size(); i++){
        // myfriends[i]->print_person();
        cout << myfriends[i]->uniqueId << endl;
    }
}

void Person::print_person(){
    // Already implemented for you! Do not change!
	cout << l_name <<", " << f_name << endl;
	birthdate->print_date("Month D, YYYY");
    email->print();
    phone->print();
    print_friends();
}

