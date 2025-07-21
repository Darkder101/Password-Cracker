#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

void runDictionaryAttack(const string& target, const string& dictPath) {
    ifstream dictFile(dictPath);
    if (!dictFile.is_open()) {
        cerr << "❌ Failed to open dictionary file: " << dictPath << endl;
        return;
    }

    cout << "\n[+] Starting Dictionary Attack...\n";
    long long attempts = 0;
    bool found = false;
    string word;

    auto start = high_resolution_clock::now();

    while (getline(dictFile, word)) {
        attempts++;
        if (word == target) {
            found = true;
            cout << "\n✅ Password cracked: " << word << endl;
            cout << "🔁 Attempts: " << attempts << endl;
            break;
        }
    }

    dictFile.close();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);

    if (!found) {
        cout << "❌ Password not found in dictionary.\n";
    }

    cout << "⏱️ Time taken: " << duration.count() << " seconds\n";
}
