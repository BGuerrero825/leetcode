#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> answers;
    sort(nums.begin(), nums.end());
    int min = nums[0];
    int max = nums[nums.size()-1];
    for (int i = 0; i < nums.size(); i++) {
      int j = i+1;
      int k = nums.size()-1;
      while(j < k) {
        long sum = nums[i] + nums[j] + nums[k];
        if (sum == 0) {
          vector<int> sumvec = vector<int> {nums[i], nums[j], nums[k]};
          bool dupe = false;
          for (vector<int> vec : answers) {
            if (sumvec == vec) {
              dupe = true; break;
            }
          }
          if (!dupe){
            answers.push_back(vector<int> {nums[i], nums[j], nums[k]});
          }
          j++;
        } else if (sum < 0) {
          j++;
        } else {
          k--;
        }
      }
    }
    return answers;
  }
};


int main() {
  Solution sol;
  vector<int> nums = {-1,0,1,2,-1,-4};
  vector<vector<int>> ans = sol.threeSum(nums);
  for (vector<int> vec : ans) {
    cout << "{";
    for (int num : vec) {
      cout << num << ",";
    }
    cout << "\b";
    cout << "}  ";
  }
  cout << endl;

}
