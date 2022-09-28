#include <iostream>

int main() {
    int x;
    
    while(std::cin>>x) {
    
        bool is_prime = true;

        for (int i = x; i >= 2; i--) {
            if (x % i == 0) is_prime = false; break;
        }

        if( x == 0 || x == 1 ) is_prime = false;

        if (is_prime) std::cout << x << " is a prime : True \n";
        else std::cout << x << " is a prime : False \n";
    }
    
    exit; 
}