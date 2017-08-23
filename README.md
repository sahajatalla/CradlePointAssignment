## Synopsis

Currently I created client and the server.  I wrote a small test program which exercises the following in a for loop:  Generates a random number, instantiates the client, makes the connection with the server, sends the unsigned number, gets the result of its primality and prints it.  This is the simulation of multiple clients interacting with the server.

The server gets connection request from the client, accepts the connection, gets the unsigned number whose primality is to be determined and assigns the task of determining the primality of the number to a task in the thread pool.  This task computes the primality of the number, and writes back the result to the client socket.

## How to build

Open the Visual Studio (I used visual studio 2015) solution file called client.sln and build all or rebuild all.  It generates the client.exe and the server.exe in the debug directory.  Go to the directory where the following executables are located and run as follows in separate command prompts:
 
1.	Start the server – server.exe localhost
2.	Start the client – client.exe

## Tests

The unit tests can be run from the Visual Studio when the solution is open; I only added few unit tests and more should be added.  To add more tests and hence more coverage, it is good idea to come up with smaller functions.

## Sample Output - Server window

C:\Users\sahaja2016\cp\git_test_getting\CradlePointAssignment\Debug>server
Number received: 914
thread id is   socket is 160 : 0, num is 914Bytes sent: 5
Number received: 170
thread id is   socket is 160 : 1, num is 170Bytes sent: 5
Number received: 560
thread id is   socket is 160 : 2, num is 560Bytes sent: 5
Number received: 744
thread id is   socket is 160 : 3, num is 744Bytes sent: 5
Number received: 402
thread id is   socket is 160 : 4, num is 402Bytes sent: 5
Number received: 419
thread id is   socket is 160 : 5, num is 419Bytes sent: 4
Number received: 344
thread id is   socket is 160 : 6, num is 344Bytes sent: 5
Number received: 602
thread id is   socket is 160 : 7, num is 602Bytes sent: 5
Number received: 3
thread id is   socket is 160 : 8, num is 3Bytes sent: 4
Number received: 533
thread id is   socket is 160 : 9, num is 533Bytes sent: 5

## Sample Output - Client window

C:\Users\sahaja2016\cp\git_test_getting\CradlePointAssignment\Debug>client local
host
some random numbers between 1 and 10: Bytes Sent: 4
Socket is 288 : Primality of  914  is  false
Connection closed
Bytes Sent: 4
Socket is 288 : Primality of  170  is  false
Connection closed
Bytes Sent: 4
Socket is 288 : Primality of  560  is  false
Connection closed
Bytes Sent: 4
Socket is 288 : Primality of  744  is  false
Connection closed
Bytes Sent: 4
Socket is 288 : Primality of  402  is  false
Connection closed
Bytes Sent: 4
Socket is 288 : Primality of  419  is  true
Connection closed
Bytes Sent: 4
Socket is 288 : Primality of  344  is  false

