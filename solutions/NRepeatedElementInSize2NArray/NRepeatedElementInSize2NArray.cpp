/*
In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

Return the element repeated N times.
*/

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        std::sort(A.begin(), A.end());
        int prev = A[0], len = A.size();
        for(int i = 1; i < len; i++){
            if(prev == A[i]){
                return prev;
            }
            prev = A[i];
        }
        return -1;
    }
};