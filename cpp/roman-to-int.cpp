#include <string>
#include <iostream>

class Solution {
public:
    int romanToInt(std::string s) {
        char prev = '\0';
        int sum = 0;
        for (std::size_t idx = 0; idx < s.length(); idx++) {
            char curr = s[idx];

            if (curr == 'M') {
                sum += 1000;
                if (prev == 'C') {
                    sum -= 200;
                }
            }
            else if (curr == 'D') {
                sum += 500;
                if (prev == 'C') {
                    sum -= 200;
                }
            }
            else if (curr == 'C') {
                sum += 100;
                if (prev == 'X') {
                    sum -= 20;
                }
            }
            else if (curr == 'L') {
                sum += 50;
                if (prev == 'X') {
                    sum -= 20;
                }
            }
            else if (curr == 'X') {
                sum += 10;
                if (prev == 'I') {
                    sum -= 2;
                }
            }
            else if (curr == 'V') {
                sum += 5;
                if (prev == 'I') {
                    sum -= 2;
                }
            }
            else if (curr == 'I') {
                sum += 1;
            }
            else {
                std::cout << "Invalid roman numeral!";
                return 0;
            }

            prev = curr;
        }

        return sum;
    }
};


int main() {
    Solution solution = Solution();
    std::cout << solution.romanToInt("MCMXCIV");
    std::cout << std::endl;
}
