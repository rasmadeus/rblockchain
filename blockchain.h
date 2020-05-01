#pragma once

#include <vector>
#include "block.h"

class Blockchain
{
public:
    void addBlock(Block&& block);

private:
    Block const& lastBlock() const;

private:
    uint32_t m_difficulty{ 6 };
    std::vector<Block> m_chain{ { 0, "Hello world!" }, };
};