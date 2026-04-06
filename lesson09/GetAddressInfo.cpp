/*
  Lab Assignment 11: Get Address Information
  Imani Hollie 03/30/2026

  DIRECTIONS: Write a C++ program that prepares ALL the necessary
  argument required to call the function getAddrInfo(). The goal is to
  correctly DECLARE and INITIALIZE all variables that would be used in
  a proper call to this function.

  You must write the line of code that calls getAddrInfo() using your prepared variables
  EX. result = getAddrInfo(node, service, &hints, &res);

  Output the values of node and service to show that your variables are properly set.

  REQUIREMENTS:
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

/*
  Lab Assignment 11: Get Address Information
  Imani Hollie 03/30/2026
*/

#include <iostream>     // Allows use of cout, cin, etc.
#include <cstring>      // Provides memset() for zeroing structs
#include <sys/types.h>  // Required for socket-related types
#include <sys/socket.h> // Provides socket structures and constants
#include <netdb.h>      // Provides networking definitions
using namespace std;

// The assignment uses a custom struct named "addrInfo"
// This mimics the real "addrinfo" struct used by getaddrinfo().
struct addrInfo {
    int              ai_flags;      // Optional flags
    int              ai_family;     // Address family (IPv4, IPv6, etc.)
    int              ai_socktype;   // Socket type (TCP, UDP)
    int              ai_protocol;   // Protocol (usually 0)
    socklen_t        ai_addrlen;    // Length of socket address
    struct sockaddr *ai_addr;       // Pointer to socket address
    char            *ai_canonname;  // Canonical hostname
    struct addrInfo *ai_next;       // Linked list pointer
};

// Function prototype for getAddrInfo()
// Matches the assignment's required signature.
int getAddrInfo (const char *restrict node,
                 const char *restrict service,
                 const struct addrInfo *restrict hints,
                 struct addrInfo **restrict res);

int main() {
    // 1. DECLARE VARIABLES
    const char *node;          // pointer to char for hostname/IP
    const char *service;       // pointer to char for port number
    struct addrInfo hints;     // hints structure
    struct addrInfo *res;      // result pointer
    int result;                // return value

    // 2. INITIALIZE VARIABLES
    node = "127.0.0.1";        // example IP address
    service = "80";            // example port number

    // Set all fields in hints to zero
    memset(&hints, 0, sizeof(hints));

    // REQUIRED fields
    hints.ai_family = AF_INET;       // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP

    // 3. CALL getAddrInfo()
    result = getAddrInfo(node, service, &hints, &res);

    // Output node and service to verify correctness
    cout << "Node: " << node << endl;
    cout << "Service: " << service << endl;
    cout << "getAddrInfo() returned: " << result << endl;

    return 0;
}
