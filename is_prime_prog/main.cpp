/// pape ibrahima diawara
#include <iostream>

bool est_premier(int p)
{
    
    if (p <= 1) {
        return false;
    }

    for (int i = 2; i <= p/2; ++i) {
        if (p % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    int n;
    while(std::cin >> n)
    {
        if(est_premier(n))
        {
            std::cout << n << " is a prime: True\n";
        }else
            std::cout << n << " is a prime: False\n";
    }
    return 0;
}
