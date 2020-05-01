#include "blockchain.h"
#include <iostream>

void main()
{
    Blockchain blockchain;

    for (uint32_t i = 1; i < 4; ++i) {
        std::cout << "Mine block " << i << "\n";
        blockchain.addBlock({ i, "Block " + std::to_string(i) });
    }
}
