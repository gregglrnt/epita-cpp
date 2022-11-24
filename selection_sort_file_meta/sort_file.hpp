#include <iostream>
#include <fstream>

#include <string>

#include <list>
#include <vector>
#include <deque>

#include <tuple>

#include "my_sort.hpp"

template <class type, class cont>
void read_file_to_cont(std::ifstream &fi , cont& co) {
    type myelm;
    while (fi >> myelm) {
        co.push_back(myelm);
    }
}

template<class cont>
void read_file_to_cont(std::ifstream &fi, cont& co) {
    while (char c = fi.get()) {
        co.push_back(c);
        fi.get(); // useless character
    }
}

template <class type, class cont>
void read_and_sort(std::ifstream& fi, std::ofstream& fo, auto l) {
    cont container = {};
    read_file_to_cont<type, cont>(fi, container);
    my_selection_sort(container.begin(), container.end(), l);
    for (type &myelm : container)
        fo << myelm << std::endl;
}

template <class type>
void read_and_sort_decide_container(std::ifstream& fi, std::ofstream& fo, auto l) {
    char Line2;
    fi >> Line2;
    fo << Line2 << std::endl;
    switch(Line2)
    {
        case 'l':
            read_and_sort<type, std::list<type>>(fi, fo, l);
            break;
        case 'v':
            read_and_sort<type, std::vector<type>>(fi, fo, l);
            break;
        case 'd':
            read_and_sort<type, std::deque<type>>(fi, fo, l);
            break;
    }
}

void read_and_sort_decide_valuetype(std::ifstream& fi, std::ofstream& fo) {
    char Line1;
    fi >> Line1;
    fo << Line1 << std::endl;
    switch(Line1)
    {
        case 'i':
            read_and_sort_decide_container<int>(fi, fo, [](int l, int r) -> bool {
                return std::make_tuple(l%2, l) < std::make_tuple(r%2, r); });
            break;
        case 'u':
            read_and_sort_decide_container<unsigned >(fi, fo, [](unsigned l, unsigned r) -> bool {
                return std::make_tuple(l%2, l) < std::make_tuple(r%2, r); });
            break;
        case 'f':
            read_and_sort_decide_container<float>(fi, fo, [](float l, float r)->bool {return l > r; });
            break;
        case 'd':
            read_and_sort_decide_container<double>(fi, fo, [](double l, double r)->bool {return l > r; });
            break;
        case 'c':
            read_and_sort_decide_container<char>(fi, fo, [](char l, char r) -> bool {
                return std::make_tuple(l%2, l) < std::make_tuple(r%2, r); });
            break;
        case 's':
            read_and_sort_decide_container<std::string>(fi, fo, [](std::string l, std::string r)->bool {return l > r; });
            break;
    }
}
