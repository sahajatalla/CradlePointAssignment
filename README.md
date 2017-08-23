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
C:\Users\sahaja2016\cp\git_test_getting\CradlePointAssignment\Debug>server.exe
Number received: 81
thread id is  : 0 socket is : 160 : 0, num is 81
Bytes sent: 5
Number received: 685
thread id is  : 1 socket is : 160 : 1, num is 685
Bytes sent: 5
Number received: 135
thread id is  : 2 socket is : 160 : 2, num is 135
Bytes sent: 5
Number received: 96
thread id is  : 3 socket is : 160 : 3, num is 96
Bytes sent: 5
Number received: 208
thread id is  : 4 socket is : 160 : 4, num is 208
Bytes sent: 5
Number received: 34
thread id is  : 5 socket is : 160 : 5, num is 34
Bytes sent: 5
Number received: 10
thread id is  : 6 socket is : 160 : 6, num is 10
Bytes sent: 5
Number received: 267
thread id is  : 7 socket is : 160 : 7, num is 267
Bytes sent: 5
Number received: 705
thread id is  : 8 socket is : 160 : 8, num is 705
Bytes sent: 5
Number received: 987
thread id is  : 9 socket is : 160 : 9, num is 987
Bytes sent: 5


## Sample Output - Client window

C:\Users\sahaja2016\cp\git_test_getting\CradlePointAssignment\Debug>client
host
Bytes Sent: 4
Socket is 288 : Primality of  81  is  false
Connection closed
Bytes Sent: 4
Socket is 288 : Primality of  685  is  false
Connection closed
Bytes Sent: 4
Socket is 288 : Primality of  135  is  false
Connection closed
Bytes Sent: 4
Socket is 288 : Primality of  96  is  false
Connection closed
Bytes Sent: 4
Socket is 288 : Primality of  208  is  false
Connection closed
Bytes Sent: 4
Socket is 288 : Primality of  34  is  false
Connection closed
Bytes Sent: 4
Socket is 288 : Primality of  10  is  false
Connection closed
Bytes Sent: 4
Socket is 288 : Primality of  267  is  false
Connection closed
Bytes Sent: 4
Socket is 288 : Primality of  705  is  false
Connection closed
Bytes Sent: 4
Socket is 288 : Primality of  987  is  false
Connection closed
604
