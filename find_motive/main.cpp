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


unsigned find_motive(std::istream& in,std::string w) {
    std::string s;
    int count=0;
    while (in >> s) {
        // Find position of string and Check if position is -1 or not
        if(s.find(w)!= std::string::npos){
            count++;
        }
    }
    return count;
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
        std::cout << " The file " << argv[1] << "contains " << find_motive(in, motive) << " words containing the motive " << motive;
    }
    
    return 0;
}
