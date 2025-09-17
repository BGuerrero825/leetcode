#include <string>
#include <iostream>
#include <vector>

class Solution {
public:
    std::string commonPrefix(std::vector<std::string>& strs) {
        int offset = 0;
        // update offset into strings
        while (offset < strs[0].length()) {
            char compare = strs[0][offset];
            // compare each string char if long enough
            for (int idx = 0; idx < strs.size(); idx++) {
                if (strs[idx].length() <= offset || 
                    strs[idx][offset] != compare) {
                    return strs[0].substr(0, offset);
                }
            }
            offset++;
        }
        return strs[0].substr(0, offset);
    }
};


int main() {
    Solution solution = Solution();
    std::vector<std::string> strs = {"bugbugbug", "buggo", "bubug"};
    std::cout << solution.commonPrefix(strs) << '\n';
}
