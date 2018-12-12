#include <iostream>
#include <bitset>
#include "src/operations.h"

int main() {
    std::cout << encode((const unsigned char*)"it's wednesday my dudes") << std::endl;

    /** word:           it's wednesday my dudes
        online:         aXQncyB3ZWRuZXNkYXkgbXkgZHVkZXM=
        my:             aXQncyB3ZWRuZXNkYXkgbXkgZHVkZXM=
        status:         Perfect
    */

    std::cout << decode((const unsigned char*)"aXQncyB3ZWRuZXNkYXkgbXkgZHVkZXM=") << std::endl;

    std::cout << std::endl << "MAIN TESTING SITUATION" << std:: endl;
    std::cout << decode((const unsigned char*)encode((const unsigned char*)"it's wednesday my dudes"));

    return 0;
}

