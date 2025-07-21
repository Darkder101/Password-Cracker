#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    cout << "Dictionary Attack (Offline)\n";

    string target;
    cout << "Enter target password (plaintext): ";
    cin >> target;

    string filename;
    cout << "Enter dictionary file path: ";
    cin >> filename;

    ifstream dictFile(filename);
    if (!dictFile.is_open()) {
        cerr << "❌ Failed to open dictionary file.\n";
        return 1;
    }

    string word;
    long long attempts = 0;
    bool found = false;

    auto start = high_resolution_clock::now();

    while (getline(dictFile, word)) {
        attempts++;
        if (word == target) {
            found = true;
            cout << "\nPassword cracked: " << word << endl;
            cout << "Attempts: " << attempts << endl;
            break;
        }
    }

    dictFile.close();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);

    if (!found) {
        cout << "Password not found in dictionary.\n";
    }

    cout << "Time taken: " << duration.count() << " seconds\n";
    return 0;
}
