#include <iostream>

bool est_premier(int x)
{
    if (x <= 1) {
        return false;
    }

    for (int i = 2; i <= x/2; ++i) {
        if (x % i == 0) {
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
