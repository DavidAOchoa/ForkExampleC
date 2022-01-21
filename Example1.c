// Author of code is Team GeeksforGeeks and Kadam Patel.
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main() {

    // Make two process which run same
    // program after this instruction
    fork();

    printf("Hello World!\n");
    return 0;
}

// Expected output
/* 
    Hello World!
    Hello World!
*/