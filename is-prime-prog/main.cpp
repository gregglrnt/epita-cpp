#include <iostream>

int main() 
{   std::cout << "Entrez un nombre \n";
    int x;
    
    while(std::cin>>x) {
    
        bool is_prime = true;

        for (int i = 2; i <= x; i++) {
            if (x % 2 == 0) is_prime = false; break;
        }

        if (is_prime) std::cout << x << " est premier \n";
        else std::cout << x << " n'est pas premier \n";
    }
    
    exit; 
}