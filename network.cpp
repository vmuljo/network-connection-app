
#include "network.h"
#include <limits>
#include "misc.h"
#include <fstream>

Network::Network(){
    head = NULL;
    tail = NULL;
    count = 0;
}


Network::Network(string fileName){
    // TODO: complete this method!
    // Implement it in one single line!
    // You may need to implement the load method before this!
}

Network::~Network(){ 
    //Deallocates the dynamically allocated objects
    delete head;
    delete tail;
}


void Network::push_front(Person* newEntry){
    newEntry->prev = NULL;
    newEntry->next = head;

    if (head != NULL)
        head->prev = newEntry;
    else
        tail = newEntry;
    
    head = newEntry;
    count++;
}


void Network::push_back(Person* newEntry){
    // Adds a new Person (newEntry) to the back of LL
    newEntry->prev = tail;
    newEntry->next = NULL;

    if(tail != NULL){
        tail->next = newEntry;
    }
    else{
        head = newEntry;
    }

    tail = newEntry;
    count++;

}


Person* Network::search(Person* searchEntry){
    // Searches the Network for searchEntry
    // if found, returns a pointer to it, else returns NULL
    if(head == NULL){
        return NULL;
    }
    Person* start = head;
    Person* end = tail;
    //loop that checks both ends of the linked list
    while(start != end || start != NULL){
        //Checks the start of list
        if(*start==*searchEntry){
            return start;
        }
        else{ //if not at start, move to next object in list
            // cout << "Not in start" << endl;
            start = start->next;
        }
        //Checks end of list
        if(*end==*searchEntry){
            return end;
        }
        else{
            //if not at end, move to previous object in list
            end = end->prev;
        }
    }

    return NULL; //return a null pointer if no matches found
}


Person* Network::search(string fname, string lname){
    // New == for Person, only based on fname and lname
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    // Note: two ways to implement this, 1st making a new Person with fname and lname and and using search(Person*), 2nd using fname and lname directly. 
    // Check if the list is empty first (tail should be NULL as well when head is)
    if(head == NULL){
        return NULL;
    }
    Person* start = head;
    Person* end = tail;
    
    //Check both ends of the list and compare the names of each object
    while(start != end || start != NULL){
        if(start->f_name == fname && start->l_name == lname){
            return start;
        }
        else{
            start = start->next;
        }

        if(end->f_name == fname && end->l_name == lname){
            return end;
        }
        else{
            end = end->prev;
        }
    }

    return NULL;
}


void Network::printDB(){
    // Leave me alone! I know how to print! 
    // Note: Notice that we don't need to update this even after adding to Personattributes
    // This is a feature of OOP, classes are supposed to take care of themselves!
    cout << "Number of connections: " << count << endl;
    cout << "------------------------------" << endl;
    Person* ptr = head;
    while(ptr != NULL){
        ptr->print_person();
        cout << "------------------------------" << endl;
        ptr = ptr->next;
    }
}


bool Network::remove(string fname, string lname){
    // We modified the definition of == for Person in Person definition itself, 
    // So we should not be worried about changes we made in Person to modify this method!
    Person* p = search(fname, lname);
    //if a match is found,
    if(p != NULL){
        //if p is at the head
        if(p == head){
            head = p->next;
            head->prev = NULL;
            delete p;
            count--;
            return true;
        }
        //if p is at the tail
        if(p == tail){
            tail = p->prev;
            tail->next = NULL;
            delete p;
            count--;
            return true;
        }
        //if p is somewhere in the middle of the list
        if(p->prev != NULL && p->next != NULL){
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
            count--;
            return true;
        }
    }
    return false; // If no match found

}


// void Network::sendEmail(string addr, string subject, string content, string attachment=""){
//     // Sending a command looks like:
//     // echo "content" | mailx -s "subject" -a "attachment" addr;
//     // TODO: Search how you can run a unix command in C++
//     // TODO: You need to add double quotation character (") to both sides of strings for this command. Adding other characters (like ? in code below) should be easy, but double quotation says: I'm a character but not a typical character! 
//     // string new_str = '?' + old_str + '?'
//     // TODO: Complete this method
// }


void Network::showMenu(){
    // TODO: Complete this method!
    // All the prompts are given to you, 
    // You should add code before, between and after prompts!
    
    int opt;
    while(1){
        cout << "\033[2J\033[1;1H";
        printMe("banner"); // from misc library
        // printDB(); debugging purposes
        cout << "Select from below: \n";
        cout << "1. Save network database \n";
        cout << "2. Load network database \n";
        cout << "3. Add a new connection \n";
        cout << "4. Remove a connection \n";
        cout << "5. Search \n";
        cout << "6. Connect \n";
        cout << "\nSelect an option ... ";
        
        if (cin >> opt) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Wrong option! " << endl;
            return;
        }
        
        // You may need these variables! Add more if you want!
        string fname, lname, fileName, bdate;
        cout << "\033[2J\033[1;1H";

        if (opt==1){
            // TODO: Complete me!
            cout << "Saving network database \n";
            cout << "Enter the name of the save file: ";
            cout << "Network saved in " << fileName << endl;
        }
        else if (opt==2){
            // TODO: Complete me!
            cout << "Loading network database \n";
            // TODO: print all the files in this same directory that have ".db" format
            // Take a look into sample_files.cpp 
            cout << "Enter the name of the load file: "; 
            cin >> fileName;
            // If file with name FILENAME does not exist: 
            cout << "File FILENAME does not exist!" << endl;
            // If file is loaded successfully, also print the count of connections in it: 
            cout << "Network loaded from " << fileName << " with " << count << " connections \n";
        }
        else if (opt == 3){
            // TODO: Complete me!
            // TODO: use push_front, and not push_back 
            // Add a new Person ONLY if it does not exists!
            cout << "Adding a new person \n";
            Person* p = new Person; //Calls base constructor and uses set_person() in Person class
            Person* find = search(p); //Person pointer to look if it exists;
            
            if(find == NULL){ //If not a duplicate person:
                // find->print_person();
                push_front(p);
            }
            else{ //If a duplicate is found, delete the new dynamically allocated Person
                // find->print_person();
                delete p;
                cout << "Person already exists!" << endl;
            }
        }
        else if (opt == 4){
            // TODO: Complete me!
            cout << "Removing a connection \n";
            cout << "First Name: ";
            cin >> fname;
            cout << "Last Name: ";
            cin >> lname;
            bool found = remove(fname, lname);
            if(found){
                cout << "Remove Successful!" << endl;
            }
            else{cout << "Connection not found!" << endl;}
            // if found, cout << "Remove Successful! \n";
            // if not found: cout << "Connection not found! \n";
        }
        else if (opt==5){
            // TODO: Complete me!
            cout << "Searching: \n";
            cout << "First Name: ";
            cin >> fname;
            cout << "Last Name: ";
            cin >> lname;
            Person* p = search(fname, lname);
            if(p != NULL){
                p->print_person();
            }
            else{
                cout << "Not found!" << endl;
            }
            // if found: print connection
            // if not, cout << "Not found! \n";
        }
        else if (opt==6){
            cout << "Make friends" << endl;
            cout << "Person 1" << endl;
            cout << "First Name: ";
            cin >> fname;
            cout << "Last Name: ";;
            cin >> lname;
            Person* p1 = search(fname, lname);
            if(p1 != NULL){
                cout << "Person 2" << endl;
                cout << "First Name: ";
                cin >> fname;
                cout << "Last Name: ";;
                cin >> lname;
                Person* p2 = search(fname, lname);
                bool found = false;
                for(int i = 0; i<p1->myfriends.size(); i++){
                    if(p1->myfriends[i] == p2){
                        found = true;
                        break;
                    }
                }
                if(!found){
                    if(p2!= NULL && p2 != p1){
                    
                        cout << endl;
                        p1->makeFriend(p2);
                        p2->makeFriend(p1);
                        cout << "Added to friends list." << endl;
                    }
                    else if(p2 == p1){
                        cout << "Can not add the same person together";
                    }

                    else{
                        cout << "Person not found" << endl;
                    }
                }
                else{cout << "Already friends with this person." << endl;}
                
            }
            else{
                cout << "Person not found" << endl;
            }
        }
        
        else
            cout << "Nothing matched!\n";
        
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\nPress Enter key to go back to main menu ... ";
        string temp;
        std::getline (std::cin, temp);
        cout << "\033[2J\033[1;1H";
    }
}


