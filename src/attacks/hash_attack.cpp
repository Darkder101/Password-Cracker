#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "..\include\hash_utils.hpp"
using namespace std;
using namespace std::chrono;

void runHashAttack(const string& targetHash, const string& wordlistPath, const string& hashType) {
    ifstream dict(wordlistPath);
    if (!dict.is_open()) {
        cerr << "❌ Cannot open wordlist: " << wordlistPath << endl;
        return;
    }

    cout << "\n[+] Starting Hash Comparison Attack...\n";
    string word;
    long long attempts = 0;
    bool found = false;

    auto start = high_resolution_clock::now();

    while (getline(dict, word)) {
        attempts++;

        string hash;
        if (hashType == "sha256")
            hash = sha256(word);
        else if (hashType == "md5")
            hash = md5(word);
        else {
            cerr << "❌ Unsupported hash type: " << hashType << endl;
            return;
        }

        if (hash == targetHash) {
            found = true;
            cout << "\n✅ Password cracked: " << word << endl;
            cout << "🔁 Attempts: " << attempts << endl;
            break;
        }
    }

    dict.close();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);

    if (!found) {
        cout << "❌ Hash not found in dictionary.\n";
    }

    cout << "⏱️ Time taken: " << duration.count() << " seconds\n";
}
