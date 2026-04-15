#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    string countAndSay(int n) {
      string out = "1";
      string tmp = "";
      if (n == 1) {
        return out;
      }
      for (int i = 1; i < n; i++) {
        int consec = 1;
        char prev = 0;
        tmp.assign("");
        for (int c = 0; c < out.size(); c++) {
          if (prev == 0) {
          }
          else if (out[c] == prev) {
            consec++;
          }
          else {
            tmp.append(to_string(consec));
            tmp.append(string(1, prev));
            consec = 1;
          }
          prev = out[c];
        }
        tmp.append(to_string(consec));
        tmp.append(string(1, prev));
        out.assign(tmp);
      }
      return out;
    }
};

int main() {
  Solution sol;
  string ans = sol.countAndSay(4);
  cout << ans << endl;
}

