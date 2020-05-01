#include "blockchain.h"

void Blockchain::addBlock(Block&& block)
{
    m_chain.emplace_back(std::move(block));
    m_chain.back().setPrevHash((m_chain.cend() - 2)->prevHash());
    m_chain.back().mineBlock(m_difficulty);
}

Block const& Blockchain::lastBlock() const
{
    return m_chain.back();
}