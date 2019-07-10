/*
Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
*/

class Solution {
public:
    string toLowerCase(string str) {
        int len = str.length();
        for(int i = 0; i < len; i++){
            char c = str[i];
            if(c >= 65 && c <= 90){
                str[i] += 32;
            }
        }
        return str;
    }
};