#include "block.h"
#include <iostream>

Block::Block(uint64_t idx, const std::string& prevHash, const std::string& blockData)
    : index(idx), previousHash(prevHash), data(blockData), nonce(0), timestamp(std::time(nullptr)) {
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::string hashInput = std::to_string(index) + 
                             std::to_string(timestamp) + 
                             previousHash + 
                             data + 
                             std::to_string(nonce);
    return SHA256::hash(hashInput);
}

bool Block::mineBlock(uint32_t difficulty) {
    std::string target(difficulty, '0');
    
    while (hash.substr(0, difficulty) != target) {
        nonce++;
        hash = calculateHash();
    }
    
    std::cout << "Block mined: " << hash << std::endl;
    return true;
}