#include <string>
#include <iostream>

using std::cout, std::string;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        size_t idx = 0;
        size_t length = s.length();
        size_t largest_sub = 0;
        // substring start
        while (idx < length) {
            bool seen[256] = { 0 };
            size_t sub_len = 1;
            //cout << "start: " << s[idx] << "\n";
            seen[s[idx]] = 1;
            size_t jdx = idx + 1;
            while (jdx < length) {
                //cout << s[jdx] << "\n";
                if (seen[s[jdx]]) {
                    break;
                }
                seen[s[jdx]] = 1;
                sub_len++;
                jdx++;
                //cout << "iter sub_len: " << sub_len << "\n";
            }

            if (sub_len > largest_sub) {
                largest_sub = sub_len;
            }

            idx++;
            //cout << "\n";
        }

        //cout << "largest_sub: " << largest_sub << "\n";
        return largest_sub;
    }
};

int main() {
    Solution sully;
    string s = "hello!";
    sully.lengthOfLongestSubstring(s);
    return 0;
}