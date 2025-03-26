# Interactive Proof-of-Work Blockchain in C++

## Overview

This is a comprehensive, interactive implementation of a basic blockchain using C++ and a proof-of-work mining mechanism. The project demonstrates core blockchain concepts including block creation, cryptographic hashing, mining, and chain validation.

### Features

- Interactive command-line blockchain interface
- Proof-of-work mining algorithm
- Dynamic block creation
- Blockchain validity verification
- Adjustable mining difficulty
- SHA256 cryptographic hashing using OpenSSL

### Project Structure

```
proof-of-work-blockchain-cpp/
│
├── CMakeLists.txt        # Build configuration
├── README.md             # Project documentation
│
├── src/                  # Source code
│   ├── main.cpp          # Main application
│   ├── block.cpp         # Block implementation
│   ├── block.h           # Block class definition
│   ├── blockchain.cpp    # Blockchain implementation
│   └── blockchain.h      # Blockchain class definition
│
└── include/              # Header files
    └── sha256.h          # Cryptographic hashing utility
```

### Prerequisites

- C++17 compatible compiler
- CMake (version 3.10 or higher)
- OpenSSL development libraries

## Setup Guide

### Linux

#### Installation Dependencies

```bash
sudo apt update
sudo apt install cmake libssl-dev build-essential
```

#### Building the Project

```bash
# Create build directory
mkdir build
cd build

# Generate build files
cmake ..

# Build the project
cmake --build .
```

#### Usage

After building, run the blockchain executable

```bash
./blockchain
```

## Core Components

- Block: Represents individual blocks in the chain

    - Contains index, timestamp, data, hash, and previous hash
    - Implements proof-of-work mining


- Blockchain: Manages the entire chain of blocks

    - Creates genesis block
    - Adds new blocks
    - Validates blockchain integrity


- SHA256: Cryptographic hashing utility

    - Uses OpenSSL's EVP interface
    - Generates unique hash for block data

## Proof-of-Work Mining
The mining process involves finding a hash that starts with a specific number of zeros, determined by the difficulty level. This requires computational work, simulating the mining process in cryptocurrencies.

## Interactive Menu Options

- Add Block

    - Enter custom data for a new block
    - Automatically mines the block with the current difficulty

- Check Blockchain Validity

    - Verifies the integrity of the entire blockchain
    - Checks hash connections between blocks

- View Blockchain Details

    - Displays information for each block
    - Shows block index, current hash, and previous hash

- Change Mining Difficulty

    - Dynamically adjust proof-of-work complexity
    - Higher difficulty increases mining time and computational requirements

- Exit

    - Terminate the blockchain application

## Customization

- Adjust mining difficulty in the main application
- Modify block data structure
- Extend hashing or validation logic
