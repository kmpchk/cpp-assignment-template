#include <hw01.h>

bool isPrime(int num) {
    if (num <= 1) return false;
    for(int i = 2;i*i <= num;i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int hw01(int start, int end)
{
    if(start < 10) return -1;
    int sum = 0;
    bool foundPrime = false;
    for(int i = start;i<=end;i++) {
        if(isPrime(i)) {
            foundPrime = true;
            int firstSymb = i/10;
            int secondSymb = i%10;
            int sumOfSymbs = firstSymb + secondSymb;
            sum+=sumOfSymbs;
        }
    }
    return foundPrime ? sum:-1;
}
