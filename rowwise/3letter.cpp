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

// Backtracking function to generate square-free words
void generateSquareFreeWords(string& current, int length, const vector<char>& evenAlphabet, const vector<char>& oddAlphabet, ofstream& outfile) {
    if (current.length() == length) {
        // Output the valid word to file as 0 for 'a', 1 for 'b', and 2 for 'c'
        for (auto it : current) {
            outfile << static_cast<int>(it - 'a');
        }
        outfile << endl;
        return;
    }

    // Determine if we are at an even or odd position
    int pos = current.length();
    
    // Even position: allow 'a', 'b', or 'c'
    if (pos % 2 == 0) {
        for (char ch : evenAlphabet) {
            current.push_back(ch);
            if (isSquareFree(current)) {
                generateSquareFreeWords(current, length, evenAlphabet, oddAlphabet, outfile);
            }
            current.pop_back(); // Backtrack
        }
    } 
    // Odd position: allow only 'b' or 'c'
    else {
        for (char ch : oddAlphabet) {
            current.push_back(ch);
            if (isSquareFree(current)) {
                generateSquareFreeWords(current, length, evenAlphabet, oddAlphabet, outfile);
            }
            current.pop_back(); // Backtrack
        }
    }
}

int main() {
    // Define the even alphabet (a, b, c) for even positions
    vector<char> evenAlphabet = {'a', 'b', 'c'};
    
    // Define the odd alphabet (b, c) for odd positions
    vector<char> oddAlphabet = {'b', 'c'};
    
    // Initialize an empty string to store the current word
    string current = "";
    
    // Open a file to save the generated words
    ofstream outfile("square_free_words_output.txt");
    
    // Check if the file is open
    if (!outfile.is_open()) {
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }
    
    // Generate all square-free words of length 8 and write them to the file
    int length = 8;
    generateSquareFreeWords(current, length, evenAlphabet, oddAlphabet, outfile);
    
    // Close the file
    outfile.close();

    return 0;
}
