/*
Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].
*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int size = A.size();
        std::vector<std::vector<int>> B(size, std::vector<int>(size, 0));
        
        for(int i = 0; i < size; i++){
            int k = 0;
            for(int j = size - 1; j >= 0; j--){
                B[i][k++] = !A[i][j];
            }
        }
        return B;
    }
};