#include <cstddef>
#include <vector>
//#include <iostream>
using namespace std;
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    size_t idx1 = 0;
    size_t idx2 = 0;  
    size_t combinedSize = nums1.size() + nums2.size();
    double prev_val = 0.0;
    double val = 0.0;
    for (unsigned idx = 0; idx < combinedSize; idx++) {
      bool take1 = true; 
      if (idx1 >= nums1.size()) {
        take1 = false;
      } 
      else if (idx2 >= nums2.size()) {
        take1 = true;
      } 
      else if (nums2[idx2] < nums1[idx1]) {
        take1 = false;
      }
      if (take1) {
        val = nums1[idx1];
        idx1++;
      } else {
        val = nums2[idx2];
        idx2++;
      }

      if (idx >= (combinedSize / 2)) {
        if (combinedSize % 2 == 1) {
          return (double)val;
        }
        else if (combinedSize % 2 == 0) {
          return (double)(prev_val + val) / 2;
        }

      }
      prev_val = val;

    }
    return 0;
  }
};
