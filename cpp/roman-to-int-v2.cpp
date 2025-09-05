#include <string>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> rti = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int sum = 0;
        for (std::size_t idx = 0; idx < s.length(); idx++) {
            int curr = rti[s[idx]];
            int next = idx + 1 < s.length() ? rti[s[idx+1]] : 0;

            if (next > curr) {
                sum -= curr;
            } else {
                sum += curr;
            }
        }
        return sum;
    }
};

int main() {
    Solution solution = Solution();
    std::cout << solution.romanToInt("DCXXI");
    std::cout << std::endl;
}
