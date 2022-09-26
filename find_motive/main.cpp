//
//  main.cpp
//  findmotive
//
//  Created by pape ibrahima diawara on 26/09/2022.
//

#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;
typedef map<string, int> StrIntMap;

void find_motive(istream& in, StrIntMap& words ,string w) {
    string s;
    while (in >> s) {
        // Find position of string and Check if position is -1 or not
        if(s.find(w)!= string::npos){
                ++words[s];
        }
    }
}

int main(int argc, char** argv) {

    if (argc < 3)
        return(EXIT_FAILURE);
    
    ifstream in(argv[1]);
    
    if (!in.is_open())
        cout << "The file *" << argv[1] << "* could not be opened." << endl;
    else{
        string motive = argv[2];
        StrIntMap wo;
        find_motive(in, wo, motive);
        cout << motive << " occurred "
            << wo.size() << " times.\n";
    
    }

    return 0;
}
