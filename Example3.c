// Author of code is Team GeeksforGeeks and Kadam Patel.
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void forkExample()
{
    // Child process because return value zero
    if (fork() == 0)
        printf("Hello from Child!\n");
    else    
        printf("Hello from parent!\n");
}

int main()
{
    forkExample();
    return 0;
}

// Expected Output
/*
1.
    Hello from Child!
    Hello from Parent!
        (or)
    2.
    Hello from Parent!
    Hello from Child!
*/