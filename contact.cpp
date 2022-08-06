
#include "contact.h"
// TODO: Add needed libraries! 
// g++ test_contact.cpp contact.cpp -o test_contact

Email::Email(){
    set_contact();
}

Email::Email(string type, string email_addr){
    this->type = type;
    this->email_addr = email_addr;// TODO: Complete me!
}


void Email::set_contact(){
    // TODO: Do not change the prompts!
	
    cout << "Enter the type of email address: ";
    // some code here
    cin >> type;
    cout << "Enter email address: ";
    cin >> email_addr;
    
    // some code here
}


string Email::get_contact(string style){
    // Note: We have default argument in declaration and not in definition!
    if (style=="full")
	    return "Email (" + type + "): " + email_addr;
    else 
        return "Email: " + email_addr;
}


void Email::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}

Phone::Phone(){
    set_contact();
}
Phone::Phone(string type, string num){
    // TODO: It is possible that num includes "-" or not, manage it!
    // TODO: Complete this method!
    // Note: We don't want to use C++11! stol is not valid!
    // The code has been covered in the discussion session

    /* Note: Understand your own TA's bug!
     * This code has a bug, can you understand why?
    long int area_code = atoi(num.substr(0, 3).c_str());
    long int  number = atoi(num.substr(3).c_str()); 
    this->phone_num = area_code*10000000 + number; 
    */
    this->type = type;

    //Want to store phone_num without '-' for potential cases where we may need pure numerical form
    while(num.find('-') != string::npos){ 
        num = num.substr(0, num.find('-')) + num.substr(num.find('-')+1);
    }
    phone_num = num;
    //Check if there is anything other than a -?
}


void Phone::set_contact(){
    // TODO: Complete this method
    // Use the same prompts as given!
	cout <<"Enter the type of phone number: ";
    cin >> type;
	cout << "Enter the phone number: ";
    cin >> phone_num;
    //Want to store phone_num without '-' for potential cases where we may need pure numerical form
    while(phone_num.find('-') != string::npos){ //or just check if == -1?
        phone_num = phone_num.substr(0, phone_num.find('-')) + phone_num.substr(phone_num.find('-')+1);
    }
}


string Phone::get_contact(string style){
    // TODO: Complete this method, get hint from Email 
    // The code has been covered in discussion session 

    /* Note: Understand your own TA's bug!
     * This code has a bug, can you understand it!
    int x1 = (phone_num/10000000);
	int x2 = ((phone_num)/10000)%1000;
	int x3 = phone_num%10000;
    */ 
   // if there are no dashes, means the phone number is not in the proper format and the following code puts it in proper format.
    if(phone_num.find('-') == string::npos){
        phone_num = phone_num.substr(0, 3) + "-" + phone_num.substr(3, 3) + "-" + phone_num.substr(6);
    }
    if (style=="full")
	    return "Phone (" + type + "): " + phone_num;
    else 
        return "Phone: " + phone_num;
}


void Phone::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}


