#include <math.h>

int isPrime (int input) {
    if (input == 1)
        return 0;
    if (input == 2)
        return 1;
    if (input % 2 == 0)
        return 0;
    for (int i=3; i<=sqrt(input); i+=2)
        if (input % i == 0)
            return 0;
    return 1;
}