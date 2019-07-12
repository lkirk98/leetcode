/*
Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".
*/

class Solution {
public:
    string defangIPaddr(string address) {
        int prev_size = address.size();
        /* +6 for 6 added brackets, +1 for null terminator */
        char defang[prev_size + 7];
        
        int d_i = 0;
        for(int i = 0; i < prev_size; i++){
            if(address[i] == '.'){
                defang[d_i++] = '[';
                defang[d_i++] = '.';
                defang[d_i++] = ']';
            } else {
                defang[d_i++] = address[i];
            }
        }
        defang[d_i] = 0;
        
        return defang;
    }
};