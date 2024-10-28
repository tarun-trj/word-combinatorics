#ifndef UTILITY_H
#define UTILITY_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void show(const vector<vector<char>>& matrix, const string& filename = "matrix_output.txt") {
    ofstream outFile(filename, ios::app); // Open file in append mode

    if (!outFile) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }

    for (const auto& layer : matrix) {
        for (const auto& character : layer) {
            outFile << character << " "; // Write character to file
        }
        outFile << endl; // New line for the next row
    }

    outFile.close(); // Close the file
}

// Function to clear the matrix
void clear(vector<vector<char>>& matrix) {
    for (auto& layer : matrix) {
        layer.clear();
        layer.resize(4);  // Resize to 4 to maintain the 4x4 structure
    }
}

vector<vector<vector<char>>> readMatrices(const string& filename) {
    vector<vector<vector<char>>> matrices;
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "Error opening file: " << filename << endl;
        return matrices;
    }

    string line;
    while (getline(inFile, line)) {
        vector<vector<char>> matrix(4, vector<char>(4)); // Initialize a 4x4 matrix
        int row = 0;

        do {
            stringstream ss(line);
            char ch;
            int col = 0;
            while (ss >> ch) {
                matrix[row][col++] = ch; // Fill the matrix
            }
            row++;
        } while (row < 4 && getline(inFile, line)); // Continue reading until 4 rows are read

        matrices.push_back(matrix);
    }

    inFile.close();
    return matrices; // Return the list of matrices
}

vector<vector<char>> join(vector<vector<char>> matrix1, vector<vector<char>> matrix2) {
    int LAYERS = matrix1.size();
    vector<vector<char>> tmp = matrix1;
    for(int i = 0; i < LAYERS; i++) {
        tmp[i].insert(tmp[i].end(), matrix2[i].begin(), matrix2[i].end());
    }

    return tmp;
}

#endif // UTILITY_H
