#ifndef ATTACKS_HPP
#define ATTACKS_HPP

#include <string>

void runBruteForce(const std::string& target, int maxLength, const std::string& charset);
void runDictionaryAttack(const std::string& target, const std::string& dictPath);
void runHashAttack(const std::string& targetHash, const std::string& wordlistPath, const std::string& hashType);

#endif
