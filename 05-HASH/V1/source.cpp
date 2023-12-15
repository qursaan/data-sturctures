#include <iostream>
#include <string>
#include <cmath>

class IPLogger {
private:
    static const int TABLE_SIZE = 1024;  // Adjust the size based on your requirements
    int COUNT[TABLE_SIZE] = {0};         // Initialize log count array with zeros

    // Multiplicative hash parameters
    static const int W = 32;
    static const int D = 10;  // log2(TABLE_SIZE)
    static const int Z = 2654435769;  // A randomly chosen odd number in [1:2^W-1]

    // Hash function using multiplicative hashing
    int hashCode(const std::string& ip) {
        unsigned int ipInt = convertIPtoInt(ip);
        return (Z * ipInt) >> (W - D);
    }

public:
    // Convert IP address to a 32-bit integer
    unsigned int convertIPtoInt(const std::string& ip) {
        unsigned int result = 0;
        int octet;
        size_t start = 0, end = 0;

        for (int i = 0; i < 4; ++i) {
            end = ip.find('.', start);
            if (end == std::string::npos) {
                end = ip.length();
            }

            octet = std::stoi(ip.substr(start, end - start));
            result = (result << 8) | octet;

            start = end + 1;
        }

        return result;
    }

    // Log IP address
    void logIP(const std::string& ip) {
        int index = hashCode(ip);
        COUNT[index]++;
    }

    // Retrieve log count for a specific IP address
    int getLogCount(const std::string& ip) {
        int index = hashCode(ip);
        return COUNT[index];
    }
};

int main() {
    IPLogger ipLogger;

    // Example usage
    std::string ip1 = "192.168.1.1";
    std::string ip2 = "192.168.1.2";

    unsigned int int1 = ipLogger.convertIPtoInt(ip1);
    unsigned int int2 = ipLogger.convertIPtoInt(ip2);

    std::cout << "IP 1: " << ip1 << "\tAs integer: " << int1 << std::endl;
    std::cout << "IP 2: " << ip2 << "\tAs integer: " << int2 << std::endl;

    ipLogger.logIP(ip1);
    ipLogger.logIP(ip2);
    ipLogger.logIP(ip1);

    std::cout << "Log count for IP 1: " << ipLogger.getLogCount(ip1) << std::endl;
    std::cout << "Log count for IP 2: " << ipLogger.getLogCount(ip2) << std::endl;

    return 0;
}
