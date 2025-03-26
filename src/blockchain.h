#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include <memory>
#include "block.h"

class Blockchain {
private:
    std::vector<std::unique_ptr<Block>> chain;
    uint32_t difficulty;

public:
    Blockchain(uint32_t miningDifficulty = 4);
    
    void addBlock(const std::string& data);
    bool isChainValid() const;
    
    const std::vector<std::unique_ptr<Block>>& getChain() const { return chain; }
};

#endif // BLOCKCHAIN_H