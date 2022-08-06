
#include "misc.h"

void printMe(string type){
    if (type == "banner"){
        char banner[] = \
"   ######## ########   #######        ##    ###    ##    ##         ########   #######   #######  ##    ## \n \
     ##    ##     ## ##     ##       ##   ## ##   ###   ##         ##     ## ##     ## ##     ## ##   ## \n \
     ##    ##     ## ##     ##       ##  ##   ##  ####  ##         ##     ## ##     ## ##     ## ##  ## \n \
     ##    ########  ##     ##       ## ##     ## ## ## ## ####### ########  ##     ## ##     ## ##### \n \
     ##    ##   ##   ##     ## ##    ## ######### ##  ####         ##     ## ##     ## ##     ## ##  ## \n \
     ##    ##    ##  ##     ## ##    ## ##     ## ##   ###         ##     ## ##     ## ##     ## ##   ## \n \
     ##    ##     ##  #######   ######  ##     ## ##    ##         ########   #######   #######  ##    ##\n";
        cout << endl << banner << endl << endl;
    }

}

string codeName(string s1, string s2){
    string uniqueId = s1+s2;
    // https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/
    uniqueId.erase(remove(uniqueId.begin(), uniqueId.end(), ' '), uniqueId.end());
    // looks for upper case chars and sets to lowercase if found
    for(int i = 0; i<uniqueId.length(); i++){
        if(isupper(uniqueId[i])){
            uniqueId[i] = tolower(uniqueId[i]);
        }
    }
    return uniqueId;
}

