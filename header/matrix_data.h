#ifndef MATRIX_DATA_H
#define MATRIX_DATA_H

#include <vector>

const std::vector<std::vector<int>> encode4 = {
    {1,3,1,4},
    {1,3,2,3},
    {1,4,1,3},
    {2,3,1,3},
    {1,3,2,4},
    {2,3,1,4},
    {1,4,2,3},
    {2,4,1,3},
    {2,4,2,3},
    {2,4,1,4},
    {2,3,2,4},
    {1,4,2,4}
};

const std::vector<std::vector<int>> encode3 = {
    {1,3,1,2},
    {1,2,1,3},
    {1,3,2,3},
    {1,2,3,2},
    {3,2,1,3},
    {3,2,1,2},
    {2,3,1,2},
    {2,3,1,3}
};


#endif // MATRIX_DATA_H
