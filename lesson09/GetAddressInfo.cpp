/*
  Lab Assignment 11: Get Address Information
  Imani Hollie 03/30/2026

  Directions: Write a C++ program that prepares ALL the necessary
  argument required to call the function getAddrInfo(). The goal is to
  correctly DECLARE and INITIALIZE all variables that would be used in
  a proper call to this function.

  You must write the line of code that calls getAddrInfo() using your prepared variables
  EX. result = getAddrInfo(node, service, &hints, &res);

  Output the values of node and service to showthat your variables are properly set

  

  Requirements:
  1. DECLARE the following variables:
  - A pointer to char for the node (hostname or IP address)
  - A pointer to char for the service (port number as text)
  - A struct addrInfo variable named hints
  - A point to struct addrInfo named res
  - An integer variable to store the return value
  2. INITIALIZE the variables as follows:
  - Assign a value to node (EX. "localhost" or "127.0.0.1")
  - Assign a value to service (EX. "80")
  - Initialize the hints structure:
    - Set all field to 0
    - Set at least the following fields:
      - ai_family
      - ai_socktype
  3. RESEARCH valid values for:
  - ai_family
  - ai_socktype
*/

#include <string>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
using namespace std;

struct Node {
  int z;
  struct Node next;
  string str;
  char ch[20];
};

int getAddrInfo (const char *restrict node,
                    const char *restrict service,
                    const struct addrInfo *restrict hints,
                    struct addrInfo **restrict res);

int main() {
  // Set up the environment to call getAddrInfo
  cout << "Hello World!";
  return 0;
}
