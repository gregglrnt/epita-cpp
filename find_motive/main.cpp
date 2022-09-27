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

typedef std::map<std::string, int> StrIntMap;

void find_motive(std::istream& in, StrIntMap& words ,std::string w) {
    std::string s;
    while (in >> s) {
        // Find position of string and Check if position is -1 or not
        if(s.find(w)!= std::string::npos){
                ++words[s];
        }
    }
}


int main(int argc, char** argv) {

    if (argc < 3)
        return(EXIT_FAILURE);
    
    std::ifstream in(argv[1]);
    
    if (!in.is_open()){
        std::cout << "The file *" << argv[1] << "* could not be opened.";
        return 1;

    }
    else{
        std::string motive = argv[2];
        StrIntMap wo;
        find_motive(in,wo, motive);
        std::cout << " The file " << argv[1] << "contains " << wo.size() << " words containing the motive " << motive;
    }

    return 0;
}
