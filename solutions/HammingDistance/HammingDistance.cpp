/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int bit = 0;
        int result = 0;
        bool done = false;
        while (bit < 32 && !done){
            /* Check each bit of x against corresponding bit in y */
            int cur_bit = 1 << bit;
            int temp = ((x & cur_bit) ^ (y & cur_bit)) >> bit;
            result += temp;
            
            bit++;
            if(cur_bit > x && cur_bit > y){
                done = true;
            }
        }
        return result;
    }
};