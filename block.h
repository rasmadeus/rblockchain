#pragma once

#include <cstdint>
#include <string>
#include <time.h>

class Block
{
public:
    Block(uint32_t index, std::string const& data);

    std::string const& hash() const;
    std::string const& prevHash() const;
    void setPrevHash(std::string const& hash);
    void mineBlock(uint32_t difficulty);

private:
    std::string calculateHash() const;

private:
    uint32_t m_index;
    int64_t m_nonce;
    std::string m_data;
    std::string m_hash;
    std::string m_prevHash;
    time_t m_time;
};
