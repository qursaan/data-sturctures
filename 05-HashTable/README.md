# Hash Table Project

## Task 1

- IP Log Counter using Hash Table:
You are tasked with implementing an IP Logger system using a hash table in C++. The goal is to efficiently store and retrieve the number of logs for each unique IP address.

1. Hash Table Implementation:
    - Create a class IPLogger to represent the hash table structure.
    - Implement a hash function named hashCode using the provided multiplicative hash function. The function should take an IP address as input and return the hash code.
    - The multiplicative hash function can be defined as follows:
    - hash code = ⌊z x convertIPtoInt(IP)2^w​⌋ mod 2^(w-d)
    - where z is a randomly chosen odd number in the range [1:2^w-1], w is the input size (2w representing the total number of possible IP addresses), and d is the hash table size (2d)
    - Create an array COUNT within the IPLogger class to store the count of logs for each IP.
2. IP to Integer Conversion:
   - Implement a function convertIPtoInt within the IPLogger class that takes an IP address (string) as input and converts it to a 32-bit integer using the following algorithm:
     - Split the IP address into its four octets.
     - Convert each octet to an integer.
     - Represent the IP address as a 32-bit integer by combining the four octets.
3. Logging Functionality
   - Implement a function logIP within the IPLogger class that takes an IP address as input and increments the log count for that IP address.
4. Constraints:
   - The IP addresses are in IPv4 format (e.g., "192.168.1.1").
   - You can assume that IP addresses provided for logging exist in the IPv4 address space.
   - z should be randomly chosen and odd in the range [1:2w-1]
   - The hash table size (2d) should be a power of 2 to fit the constraints of the hash function.
5. Testing and Demonstration
   - Provide an example usage of your IPLogger class by creating an instance of it, converting several IP addresses to integers, and logging some IPs multiple times.

