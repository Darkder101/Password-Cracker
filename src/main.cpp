#include <iostream>
#include <string>
#include <unordered_map>
#include "attacks.hpp"

using namespace std;

// Simple command-line argument parser
unordered_map<string, string> parseArgs(int argc, char *argv[]) {
    unordered_map<string, string> args;
    for (int i = 1; i < argc - 1; i++) {
        string key = argv[i];
        if (key.rfind("--", 0) == 0) {
            args[key] = argv[i + 1];
            i++;
        }
    }
    return args;
}

int main(int argc, char *argv[]) {
    cout << "Password Cracker Tool - CLI Version\n";

    if (argc < 3) {
        cerr << "Usage:\n";
        cerr << "  --attack [brute|dict] --target <password> [other flags]\n";
        cerr << "Examples:\n";
        cerr << "  ./pwcrackr --attack brute --target cat --maxlen 4 --charset abc\n";
        cerr << "  ./pwcrackr --attack dict --target cat --wordlist wordlists/test.txt\n";
        return 1;
    }

    unordered_map<string, string> args = parseArgs(argc, argv);

    if (args.find("--attack") == args.end() || args.find("--target") == args.end()) {
        cerr << "Error: --attack and --target are required.\n";
        return 1;
    }

    string attackType = args["--attack"];
    string target = args["--target"];

    if (attackType == "brute") {
        if (args.find("--maxlen") == args.end() || args.find("--charset") == args.end()) {
            cerr << "Error: --maxlen and --charset are required for brute force.\n";
            return 1;
        }

        int maxLen = stoi(args["--maxlen"]);
        string charset = args["--charset"];
        runBruteForce(target, maxLen, charset);

    } else if (attackType == "dict") {
        if (args.find("--wordlist") == args.end()) {
            cerr << "Error: --wordlist is required for dictionary attack.\n";
            return 1;
        }

    }else {
        cerr << "Error: Unknown attack type. Use 'brute' or 'dict'.\n";
        return 1;
    }

    return 0;
}
