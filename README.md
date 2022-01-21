## GeeksForGeeks notes on Fork() in C
- Fork system call is used for creating a new process, which is called ***child process***, which runs concurrently with the process that makes the fork() call (parent process).
	- After a new child process is created, both processes will execute the next instruction following the fork() system call.
	- A child process uses the same pc(program counter), same CPU registers, same open files which use in the parent process
- It takes no parameters and returns an integer value. below are different values returned by fork().

**Negative Value:** creation fo a child process was unsuccessful
**Zero:** Returned to the newly created child process.
**Positive Value:** Returned to parent or caller. The value contains PID(process ID) of new created child process.

![C__Users_Docho_Documents_Spring22_DavidsObsidianVault_forkEx](https://user-images.githubusercontent.com/47507543/150599191-8bbd7555-8283-4031-bb5c-7d935920ec66.png)

***Please note that the above program does not compile in Windows Enviroment***

1. Predict the output of the following program:![C__Users_Docho_Documents_Spring22_DavidsObsidianVault_ForkExProb1](https://user-images.githubusercontent.com/47507543/150599242-3cbbe05b-7b1c-4c8b-8562-1e6942278f71.png)

2. Calculate the number of times hello is printed:![C__Users_Docho_Documents_Spring22_DavidsObsidianVault_ForkExProb2](https://user-images.githubusercontent.com/47507543/150599272-6b236aef-57bc-4377-b47a-259c02fec9d8.png)

The number of times 'hello' is printed is equal to the number of process created. Total Number of Processes = 2^n, where n is number of fork system calls. So here n = 3, 2^3 = 8

Let us put some label names for the three lines:

![C__Users_Docho_Documents_Spring22_DavidsObsidianVault_forkProcess1](https://user-images.githubusercontent.com/47507543/150599290-b4182438-c0df-4e08-84c8-8282c4e45367.png)

- So there are total eight processes (new child processes and one original process)
- If we want ot represent the relationship between the processes as a tree hierarchy it would be the following:
	- The Main Process: P0
	- Processes created by the 1st fork: P1
	- Processes created by the 2nd fork: P2, P3
	- Processes created by the 3rd fork: P4, P5, P6, P7

![C__Users_Docho_Documents_Spring22_DavidsObsidianVault_ForkProgramProcessesTree](https://user-images.githubusercontent.com/47507543/150599488-b46d8484-39c2-4bb0-bd11-59ad2cfb3d1c.png)

3. Predict the output of the following program:

![C__Users_Docho_Documents_Spring22_DavidsObsidianVault_ForkExProb3](https://user-images.githubusercontent.com/47507543/150599566-55dc4e9d-6122-4338-827b-b37ce8ffe921.png)

Output:
1.
Hello from Child!
Hello from Parent!
	(or)
2.
Hello form Parent!
Hello from Child!

- In the above code, a child proces is created. fork() returns 0 in the child process and positive integer in the parent process.
	- Here, two outputs are possible because the parent process and child process are runnign concurrently. So we don't know whether the OS will first give control to the parent process or the child process.
- **Important:**
	- Parent process and child process  are running the same program, but it does not mean they are identical. OS allocate different data and states for these two processes, and control flow fo these processes can be different. See next example:

4. Predict the Output of the following Program:
5. 
![C__Users_Docho_Documents_Spring22_DavidsObsidianVault_ForkExProb4](https://user-images.githubusercontent.com/47507543/150599676-8252bb88-f639-45b9-936d-da484f4359e4.png)

Output:
Parent has x = 0
Child has x = 2
	(or)
Child has x =2
Parent has x = 0

- Here, global variable change in one process does not affect two other processes because data/state of two processes are different. And also parent and child run simultaneously so two outputs are possible.
