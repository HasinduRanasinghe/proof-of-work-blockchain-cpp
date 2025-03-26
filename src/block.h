#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <ctime>
#include "sha256.h"

class Block {
private:
    uint64_t index;
    time_t timestamp;
    std::string previousHash;
    std::string data;
    std::string hash;
    uint64_t nonce;

public:
    Block(uint64_t idx, const std::string& prevHash, const std::string& blockData);
    
    std::string calculateHash() const;
    bool mineBlock(uint32_t difficulty);
    
    // Getters
    std::string getHash() const { return hash; }
    std::string getPreviousHash() const { return previousHash; }
    uint64_t getIndex() const { return index; }
};

#endif // BLOCK_H