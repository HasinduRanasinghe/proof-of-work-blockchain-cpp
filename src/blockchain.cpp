#include "blockchain.h"
#include <iostream>

Blockchain::Blockchain(uint32_t miningDifficulty) : difficulty(miningDifficulty) {
    // Clear existing chain
    chain.clear();
    
    // Create genesis block
    chain.push_back(std::make_unique<Block>(0, "0", "Genesis Block"));
    chain[0]->mineBlock(difficulty);
}

void Blockchain::addBlock(const std::string& data) {
    uint64_t index = chain.size();
    std::string previousHash = chain.back()->getHash();
    
    auto newBlock = std::make_unique<Block>(index, previousHash, data);
    newBlock->mineBlock(difficulty);
    
    chain.push_back(std::move(newBlock));
}

bool Blockchain::isChainValid() const {
    for (size_t i = 1; i < chain.size(); ++i) {
        const auto& currentBlock = chain[i];
        const auto& previousBlock = chain[i-1];
        
        // Check if current block's hash is valid
        if (currentBlock->getHash() != currentBlock->calculateHash()) {
            return false;
        }
        
        // Check if previous hash matches
        if (currentBlock->getPreviousHash() != previousBlock->getHash()) {
            return false;
        }
    }
    return true;
}