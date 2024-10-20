#ifndef VERIFY_H
#define VERIFY_H

#include <vector>
#include <string>


// Helper function to check if a string is square-free
bool isSquareFree(const std::string& word) {
    int n = word.size();
    for (int length = 1; length <= n / 2; ++length) {
        for (int i = 0; i + 2 * length <= n; ++i) {
            if (word.substr(i, length) == word.substr(i + length, length)) {
                return false; // Found a square
            }
        }
    }
    return true;
}

// Function to extract and check all slopes from the matrix
bool verify4(const std::vector<std::vector<char>>& matrix) {
    int n = matrix.size();
    
    // Check rows (horizontal)
    for (int i = 0; i < n; ++i) {
        std::string rowWord = "";
        for (int j = 0; j < n; ++j) {
            rowWord += matrix[i][j];
        }
        if (!isSquareFree(rowWord)) return false;
    }
    
    // Check columns (vertical)
    for (int j = 0; j < n; ++j) {
        std::string colWord = "";
        for (int i = 0; i < n; ++i) {
            colWord += matrix[i][j];
        }
        if (!isSquareFree(colWord)) return false;
    }
    
    // Check diagonals (top-left to bottom-right)
    for (int k = -n + 1; k < n; ++k) {
        std::string diagWord = "";
        for (int i = 0; i < n; ++i) {
            int j = i + k;
            if (j >= 0 && j < n) {
                diagWord += matrix[i][j];
            }
        }
        if (!isSquareFree(diagWord)) return false;
    }
    
    // Check anti-diagonals (top-right to bottom-left)
    for (int k = 0; k < 2 * n - 1; ++k) {
        std::string antiDiagWord = "";
        for (int i = 0; i < n; ++i) {
            int j = k - i;
            if (j >= 0 && j < n) {
                antiDiagWord += matrix[i][j];
            }
        }
        if (!isSquareFree(antiDiagWord)) return false;
    }

    return true; // All words are square-free
}

bool verify8(vector<vector<char>> &matrix) {
    for(int i = 0; i < 4; i++) {
        vector<vector<char>> tmp(4);
        for(int j = 0; j < 4; j++) {
            tmp[j].insert(tmp[j].begin(), matrix[j].begin() + i, matrix[j].begin() + i + 4);
        }

        if(!verify4(tmp)) return false;
    }

    vector<string> extras;

    extras.push_back(string(1,matrix[0][0]) + matrix[1][2] + matrix[2][4] + matrix[3][6]);
    extras.push_back(string(1,matrix[0][1]) + matrix[1][3] + matrix[2][5] + matrix[3][7]);
    extras.push_back(string(1,matrix[3][0]) + matrix[2][2] + matrix[1][4] + matrix[0][6]);
    extras.push_back(string(1,matrix[3][1]) + matrix[2][3] + matrix[1][5] + matrix[0][7]);


    for(auto it : extras) if(!isSquareFree(it)) return false;
    
    for(auto layer : matrix) {
        string word;
        for(auto c : layer) word += c;

        if(!isSquareFree(word)) return false;
    }

    return true;
    
}

#endif // VERIFY_H
