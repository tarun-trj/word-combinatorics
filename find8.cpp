#include "utility.h"
#include "verify.h"

using namespace std;

int main() {
    string filename = "matrix4.txt";
    vector<vector<vector<char>>> matrices = readMatrices(filename);

    const int NUM = matrices.size();
    int number = 0;

    for(int i = 0; i < NUM; i++) {
        for(int j = 0; j < NUM; j++) {
            if(i == j) continue;
            vector<vector<char>> matrix8;
            matrix8 = join(matrices[i], matrices[j]);

            if(verify8(matrix8)){
                for(auto layer : matrix8) {for(auto c : layer) {cout << c;} cout << endl;}
                number++;
                cout << endl;
            }
        }
    }

    cout << number << endl;
    return 0;
}
