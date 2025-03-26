#ifndef SHA256_H
#define SHA256_H

#include <string>
#include <iomanip>
#include <sstream>
#include <openssl/evp.h>

class SHA256 {
public:
    static std::string hash(const std::string& input) {
        EVP_MD_CTX* mdCtx = EVP_MD_CTX_new();
        if (!mdCtx) {
            return "";
        }

        unsigned char hash[EVP_MAX_MD_SIZE];
        unsigned int hashLen;

        if (EVP_DigestInit_ex(mdCtx, EVP_sha256(), nullptr) != 1) {
            EVP_MD_CTX_free(mdCtx);
            return "";
        }

        if (EVP_DigestUpdate(mdCtx, input.c_str(), input.size()) != 1) {
            EVP_MD_CTX_free(mdCtx);
            return "";
        }

        if (EVP_DigestFinal_ex(mdCtx, hash, &hashLen) != 1) {
            EVP_MD_CTX_free(mdCtx);
            return "";
        }

        EVP_MD_CTX_free(mdCtx);

        std::stringstream ss;
        for(unsigned int i = 0; i < hashLen; i++) {
            ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
        }
        return ss.str();
    }
};

#endif // SHA256_H