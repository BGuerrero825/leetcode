#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
      auto height = grid.size();
      auto width = grid[0].size();
      int valid_squares = 0;
      // navigate every valid 3x3 magic square start (top left corner)
      for (int i=0; i <= (int)height - 3; i++) {
        for (int j=0; j <= (int)width - 3; j++) {
          int digit_exists[10] = { 0 };
          bool bad_grid = false;
          int magic_sum = 15;
          // iterate all 9 boxes from start
          for (int v=i; v < i+3; v++) {
            bad_grid = false;
            int hsum = 0;
            for (int h=j; h < j+3; h++) {
              if (grid[v][h] > 9) {
                bad_grid = true;
                break;
              }
              digit_exists[grid[v][h]] = 1;
              hsum += grid[v][h];
            }
            if (hsum != magic_sum) { 
              bad_grid = true; 
              break;
            }
          }
          // end iterate all 9 boxes from start

          // check sums to ensure mAgIc
          if (bad_grid ||
              grid[i][j] + grid[i+1][j] + grid[i+2][j] != magic_sum ||
              grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1] != magic_sum ||
              grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2] != magic_sum ||
              grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != magic_sum ||
              grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] != magic_sum
              ) {
            bad_grid = true;
          }

          // check each digit visited
          int digsum = 0;
          for (int d=1; d<10; d++) {
            digsum += digit_exists[d];
          }
          if (digsum != 9) {
            bad_grid = true;
          }
          if (!bad_grid) {
            valid_squares++;
          }
        }
      }
      // end navigate start of 3x3
      return valid_squares;
    }
};


int main() {
  Solution sol = Solution();
  vector<vector<int>> grid = {{3,10,2,3,4},{4,5,6,8,1},{8,8,1,6,8},{1,3,5,7,1},{9,4,9,2,9}};
  cout << sol.numMagicSquaresInside(grid) << endl;
}
