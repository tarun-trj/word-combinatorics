#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>  // For std::find

using namespace std;

// Helper function to print the matrix to the file
void printMatrix(const vector<vector<char>>& matrix, ofstream& outfile) {
    for (const auto& row : matrix) {
        for (char ch : row) {
            outfile << ch << " ";
        }
        outfile << endl;
    }
    outfile << endl; // Separate each matrix by a blank line
}

// Function to check if a string matches the allowed letters for a specific row
bool isValidForRow(const string& row, const vector<char>& validLetters) {
    for (char ch : row) {
        if (find(validLetters.begin(), validLetters.end(), ch) == validLetters.end()) {
            return false; // Invalid character found
        }
    }
    return true;
}

// Function to generate matrices from file data
void generateMatricesFromFile(ifstream& infile, ofstream& outfile) {
    string line;
    vector<vector<char>> matrix(4, vector<char>(8)); // 4 rows, 8 columns

    // Define allowed letter sets for each row
    vector<char> firstRowSet = {'a', 'b', 'c'};        // Row 1
    vector<char> secondFourthRowSet = {'d', 'e', 'f', 'g'}; // Row 2 and Row 4
    vector<char> thirdRowSet = {'a', 'h', 'i'};        // Row 3

    while (getline(infile, line)) {
        matrix[0] = vector<char>(line.begin(), line.end());
        matrix[1] = vector<char>(line.begin(), line.end());
        matrix[2] = vector<char>(line.begin(), line.end());
        matrix[3] = vector<char>(line.begin(), line.end());

        // Print the valid matrix to the output file
        printMatrix(matrix, outfile);
    }
}

int main() {
    // Open the input file where sequences are stored
    ifstream infile("square_free_words_output.txt");

    // Open the output file where the matrices will be saved
    ofstream outfile("generated_matrices_from_file.txt");

    // Check if files are open
    if (!infile.is_open()) {
        cerr << "Error: Could not open input file!" << endl;
        return 1;
    }
    if (!outfile.is_open()) {
        cerr << "Error: Could not open output file!" << endl;
        return 1;
    }

    // Generate matrices from the input file and write them to the output file
    generateMatricesFromFile(infile, outfile);

    // Close the files
    infile.close();
    outfile.close();

    return 0;
}
