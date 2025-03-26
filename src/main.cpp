#include <iostream>
#include <string>
#include <limits>
#include "blockchain.h"

void printMenu() {
    std::cout << "\n--- Blockchain Menu ---\n";
    std::cout << "1. Add Block\n";
    std::cout << "2. Check Blockchain Validity\n";
    std::cout << "3. View Blockchain Details\n";
    std::cout << "4. Change Mining Difficulty\n";
    std::cout << "5. Exit\n";
    std::cout << "\nEnter your choice: ";
}

int main() {
    int difficulty = 4;
    Blockchain blockchain(difficulty);

    while (true) {
        printMenu();
        
        int choice;
        std::cin >> choice;

        std::cout<<std::endl;

        // Clear input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::string data;
                std::cout << "Enter block data: ";
                std::getline(std::cin, data);
                
                std::cout << "Mining block..." << std::endl;
                blockchain.addBlock(data);
                break;
            }
            case 2: {
                bool isValid = blockchain.isChainValid();
                std::cout << "Blockchain Validity: " 
                          << (isValid ? "Valid" : "Invalid") << std::endl;
                break;
            }
            case 3: {
                const auto& chain = blockchain.getChain();
                std::cout << "Blockchain Details:" << std::endl;
                for (size_t i = 0; i < chain.size(); ++i) {
                    std::cout << "Block #" << i << std::endl;
                    std::cout << "  Hash: " << chain[i]->getHash() << std::endl;
                    std::cout << "  Previous Hash: " << chain[i]->getPreviousHash() << std::endl;
                }
                break;
            }
            case 4: {
                std::cout << "Enter new mining difficulty: ";
                std::cin >> difficulty;
                // Recreate blockchain with new difficulty
                blockchain = Blockchain(difficulty);
                std::cout << "Mining difficulty set to " << difficulty << std::endl;
                break;
            }
            case 5:
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}