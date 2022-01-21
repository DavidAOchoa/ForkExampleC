// Author of code is Team GeeksforGeeks and Kadam Patel.
#include <stdio.h>
#include <sys/types.h>

int main() {
    fork();
    fork();
    fork();
    printf("hello\n");
    return 0;
}

// Expected output
/*
    hello
    hello
    hello
    hello
    hello
    hello
    hello
    hello
*/