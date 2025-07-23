#include "hash_utils.hpp"
#include <openssl/sha.h>
#include <openssl/md5.h>
#include <sstream>
#include <iomanip>

std::string sha256(const std::string& str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char*)str.c_str(), str.size(), hash);
    
    std::ostringstream oss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    
    return oss.str();
}

std::string md5(const std::string& str) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((const unsigned char*)str.c_str(), str.size(), digest);

    std::ostringstream oss;
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i)
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)digest[i];
    
    return oss.str();
}
