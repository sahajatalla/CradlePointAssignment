## Synopsis

Currently I created client and the server.  I wrote a small test program which exercises the following in a for loop:  Generates a random number, instantiates the client, makes the connection with the server, sends the unsigned number, gets the result of its primality and prints it.  This is the simulation of multiple clients interacting with the server.

The server gets connection request from the client, accepts the connection, gets the unsigned number whose primality is to be determined and assigns the task of determining the primality of the number to a task in the thread pool.  This task computes the primality of the number, and writes back the result to the client socket.

## How to build

Open the Visual Studio (I used visual studio 2015) solution file called client.sln and build all or rebuild all.  It generates the client.exe and the server.exe in the debug directory.  Go to the directory where the following executables are located and run as follows in separate command prompts:
 
1.	Start the server – server.exe localhost
2.	Start the client – client.exe

## Tests

The unit tests can be run from the Visual Studio when the solution is open; I only added few unit tests and more should be added.  To add more tests and hence more coverage, it is good idea to come up with smaller functions.

