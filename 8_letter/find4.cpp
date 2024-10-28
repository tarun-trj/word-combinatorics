#include "../header/matrix_data.h"
#include "../header/verify.h"
#include "../header/utility.h"

using namespace std;

const int NUM = encode4.size();

int main() {
    string layerEven = "abcd";
    string layerOdd = "defg";
    vector<vector<char>> matrix4(4, vector<char>(4));  // Initialize as a 4x4 matrix
    int number = 0;

    string filename = "matrix4.txt";
    std::ofstream outFile(filename, std::ios::trunc); // Clear the file content

    // Generate and check 4x4 matrices
    for (int l0 = 0; l0 < NUM; l0++) {
        for (int i = 0; i < 4; i++) matrix4[0][i] = layerEven[encode4[l0][i] - 1];  // Row 0

        for (int l1 = 0; l1 < NUM; l1++) {
            for (int i = 0; i < 4; i++) matrix4[1][i] = layerOdd[encode4[l1][i] - 1];  // Row 1

            for (int l2 = 0; l2 < NUM; l2++) {
                for (int i = 0; i < 4; i++) matrix4[2][i] = layerEven[encode4[l2][i] - 1];  // Row 2

                for (int l3 = 0; l3 < NUM; l3++) {
                    for (int i = 0; i < 4; i++) matrix4[3][i] = layerOdd[encode4[l3][i] - 1];  // Row 3
                    

                    // Check if the matrix is square-free
                    if (verify4(matrix4)) {
                        // Show the generated matrix
                        show(matrix4, filename);
                        number++;
                    }

                    // No need to clear as we overwrite the matrix in the next iteration
                }
            }
        }
    }

    cout << "Number of square-free matrices: " << number << endl;

    return 0;
}
