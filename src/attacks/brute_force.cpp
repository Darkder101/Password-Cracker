#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

bool bruteForceFound = false;
long long bruteForceAttempts = 0;

void recursiveBrute(string current, const string& charset, int maxLength, const string& target) {
    if (bruteForceFound || current.length() > maxLength) return;

    if (!current.empty()) {
        bruteForceAttempts++;
        if (current == target) {
            bruteForceFound = true;
            cout << "\n[!] Password cracked: " << current << endl;
            cout << "[!] Attempts: " << bruteForceAttempts << endl;
            return;
        }
    }

    for (char c : charset) {
        recursiveBrute(current + c, charset, maxLength, target);
        if (bruteForceFound) break;
    }
}

void runBruteForce(const string& target, int maxLength, const string& charset) {
    bruteForceFound = false;
    bruteForceAttempts = 0;

    cout << "\n[+] Starting Brute Force Attack...\n";
    auto start = high_resolution_clock::now();

    recursiveBrute("", charset, maxLength, target);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);

    if (!bruteForceFound) {
        cout << "[!] Password not found in given length and charset.\n";
    }

    cout << "[!] Time taken: " << duration.count() << " seconds\n";
}
