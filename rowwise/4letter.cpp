#include <iostream>
#include <vector>
#include <string>
#include <fstream> // For file handling

using namespace std;

// Function to check if a string is square-free
bool isSquareFree(const string& word) {
    int len = word.length();
    for (int i = 1; i <= len / 2; ++i) {
        for (int j = 0; j + 2 * i <= len; ++j) {
            if (word.substr(j, i) == word.substr(j + i, i)) {
                return false;
            }
        }
    }
    return true;
}

// Backtracking function to generate square-free words with fixed parity for letters
void generateSquareFreeWordsWithParity(string& current, int length, const vector<char>& evenAlphabet, const vector<char>& oddAlphabet, ofstream& outfile) {
    if (current.length() == length) {
        for(auto it : current) outfile << static_cast<int>(it - 'a');
        outfile << endl;
        return;
    }

    // Determine the position we are filling (even or odd)
    int pos = current.length();
    if (pos % 2 == 0) {
        // Even position: use letters from the even alphabet ('a', 'b')
        for (char ch : evenAlphabet) {
            current.push_back(ch);
            if (isSquareFree(current)) {
                generateSquareFreeWordsWithParity(current, length, evenAlphabet, oddAlphabet, outfile);
            }
            current.pop_back(); // Backtrack
        }
    } else {
        // Odd position: use letters from the odd alphabet ('c', 'd')
        for (char ch : oddAlphabet) {
            current.push_back(ch);
            if (isSquareFree(current)) {
                generateSquareFreeWordsWithParity(current, length, evenAlphabet, oddAlphabet, outfile);
            }
            current.pop_back(); // Backtrack
        }
    }
}

int main() {
    // Define the even alphabet (2 letters: a, b) for even positions
    vector<char> evenAlphabet = {'a', 'b'};
    
    // Define the odd alphabet (2 letters: c, d) for odd positions
    vector<char> oddAlphabet = {'c', 'd'};
    
    // Initialize an empty string to store the current word
    string current = "";
    
    // Open a file to store the generated words
    ofstream outfile("square_free_words_parity.txt");
    
    // Check if the file is open
    if (!outfile.is_open()) {
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }
    
    // Generate all square-free words of length 8 with fixed parity and write them to the file
    int length = 8;
    generateSquareFreeWordsWithParity(current, length, evenAlphabet, oddAlphabet, outfile);
    
    // Close the file
    outfile.close();

    return 0;
}
