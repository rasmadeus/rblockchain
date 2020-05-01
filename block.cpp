#include "block.h"
#include "sha256.h"
#include <iostream>
#include <sstream>

Block::Block(uint32_t index, std::string const& data)
    : m_index{ index }
    , m_data{ data }
    , m_nonce{ 0 }
    , m_time{ 0 }

{
    m_hash = calculateHash();
}

std::string const& Block::hash() const
{
    return m_hash;
}

std::string const& Block::prevHash() const
{
    return m_prevHash;
}

void Block::setPrevHash(std::string const& hash)
{
    m_prevHash = hash;
}

void Block::mineBlock(uint32_t difficulty)
{
    while (true)
    {
        m_nonce++;
        m_hash = calculateHash();

        static std::string const zero(static_cast<std::size_t>(difficulty) + 1, '0');
        if (m_hash.substr(0, difficulty) == zero)
        {
            break;
        }
    }
}

std::string Block::calculateHash() const
{
    std::stringstream out;
    out << m_index << m_time << m_data << m_nonce << m_prevHash;
    return sha256(out.str());
}