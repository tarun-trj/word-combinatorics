#ifndef VERIFY_H
#define VERIFY_H

#include <vector>
#include <string>
#include <iostream>

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

// Function to check square freeness in 4x4
bool verify4(const std::vector<std::vector<char>>& matrix) {
    int n = matrix.size();

    //if(n != 4) std::cout << "error" << std::endl;
    //for(int i = 0; i < n; i++) if(matrix[i].size() != 4) std::cout << "done fucked up\n";

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
    
    // check both diagonals
    std::string diag, antidiag;
    for(int i = 0; i < 4; i++) {
        diag += matrix[i][i];
        antidiag += matrix[3 - i][i];
    }

    if(!isSquareFree(diag) || !isSquareFree(antidiag)) return false;

    return true; // All words are square-free
}

// square freeness in 8x4
bool verify8(std::vector<std::vector<char>> &matrix) {
    // slices of 4X4
    for(int i = 0; i < 4; i++) {
        std::vector<std::vector<char>> tmp(4);
        for(int j = 0; j < 4; j++) {
            tmp[j].insert(tmp[j].begin(), matrix[j].begin() + i, matrix[j].begin() + i + 4);
        }

        if(!verify4(tmp)) return false;
    }

    // long diagonals of whihch only 4 exist
    std::vector<std::string> extras;

    extras.push_back(std::string(1,matrix[0][0]) + matrix[1][2] + matrix[2][4] + matrix[3][6]);
    extras.push_back(std::string(1,matrix[0][1]) + matrix[1][3] + matrix[2][5] + matrix[3][7]);
    extras.push_back(std::string(1,matrix[3][0]) + matrix[2][2] + matrix[1][4] + matrix[0][6]);
    extras.push_back(std::string(1,matrix[3][1]) + matrix[2][3] + matrix[1][5] + matrix[0][7]);

    for(auto it : extras) if(!isSquareFree(it)) return false;
    
    // 8 letter squares
    for(auto layer : matrix) {
        std::string word;
        for(auto c : layer) word += c;

        if(!isSquareFree(word)) return false;
    }

    return true;
    
}

bool verify9(std::vector<std::vector<char>> &matrix) {
    // 8 letter rows
    for(auto layer : matrix) {
        std::string word;
        for(auto letter : layer) word += letter;

        if(!isSquareFree(word)) return false;
    }

    // long diagonals
    std::vector<std::string> extras;
    extras.push_back(std::string(1, matrix[0][0]) + matrix[1][2] + matrix[2][4] + matrix[3][6]);
    extras.push_back(std::string(1, matrix[0][1]) + matrix[1][3] + matrix[2][5] + matrix[3][7]);
    extras.push_back(std::string(1, matrix[3][0]) + matrix[2][2] + matrix[1][4] + matrix[0][6]);
    extras.push_back(std::string(1, matrix[3][1]) + matrix[2][3] + matrix[1][5] + matrix[0][7]);

    for (const auto& it : extras) {
        if (!isSquareFree(it)) return false;
    }
    
    // columns
    for (int i = 0; i < 8; ++i) {
        std::string word;
        for (int k = 0; k < 4; ++k) {
            word += matrix[k][i];
        }
        if (!isSquareFree(word)) return false;
    }
    
    // slopes of 1*1 or 1*-1
    for (int i = 0; i <= 4; ++i) {
        std::string dia, anti;
        for (int k = 0; k < 4; ++k) {
            dia += matrix[k][i + k];
            anti += matrix[3 - k][i + k];
        }
        if (!isSquareFree(dia) || !isSquareFree(anti)) return false;
    }

    return true;
}


#endif // VERIFY_H
