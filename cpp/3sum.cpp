#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> answers;
    int max = *max_element(nums.begin(), nums.end());
    int min = *min_element(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i+1; j < nums.size(); j++) {
        int twosum = nums[i] + nums[j];
        if (twosum > -min || twosum < -max) {
          continue;
        }
        for (int k = j+1; k < nums.size(); k++) {
          if (nums[k] == -twosum) {
            vector<int> ans = {nums[i], nums[j], nums[k]};
            sort(ans.begin(), ans.end());
            bool dupe = false;
            for (vector<int> vec : answers) {
              if (vec == ans) {
                dupe = true; 
              }
            }
            if (!dupe) {
              answers.push_back(ans);
            }
          }
        }
      }
    }
    return answers;
  }
};


int main() {
  Solution sol;
  vector<int> nums = {-1,0,1,2,-1,-4};
  sol.threeSum(nums);
}
