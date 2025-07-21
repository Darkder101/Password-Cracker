#include <iostream> 
#include <string> 
#include <chrono>

using namespace std; 
using namespace std::chrono; 

// Declaring Global Variables. 
string target; 
bool found = false; 
long long attempts = 0;

//brute-force function 
void bruteforce(string current , const string &charset , int maxlength){
    if(found) return; 

    if(current.length() > maxlength) return; 

    if(!current.empty()){
        attempts++; 
        if(current == target){
            found = true; 
            cout << "\nPassword cracked: " << current << endl;
             cout << "Attempts: " << attempts << endl;
             return;
        }
    }

    for(char c : charset){
        bruteforce(current + c , charset , maxlength);
        if (found) break; 
    }
}


int main(){
    cout << "Basic Brute Force Password Cracker (Offline)\n";
    cout << "Enter target password (plaintext) : ";
    cin >> target; 

    int maxlength; 
    cout << "Enter maximum password length to try: ";
    cin >> maxlength;

    string charset = "abcdefghijklmnopqrstuvwxyz";
    cout << "Using charset: " << charset << endl; 

    auto start = high_resolution_clock::now();

    bruteforce("" , charset , maxlength);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end-start);

    if(!found){
        cout << "❌ Password not found in given length and charset.\n";
    }

    cout << "Time taken: " << duration.count() << " seconds\n";
    return 0;
}