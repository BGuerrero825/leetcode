#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    string countAndSay(int n) {
      if (n == 1) return "1";

      string current = "1";

      for (int iter = 2; iter <= n; iter++) {
        string next = "";
        next.reserve(current.size() * 2);
        for (int ch = 0; ch < current.size(); ch++) {
          int consec = 1;
          while (ch+1 < current.size() && current[ch] == current[ch+1]) {
            consec++;
            ch++;
          }
          next.push_back(consec+'0');
          next.push_back(current[ch]);
        }
        current = std::move(next);
      }
      return current;
    }
};

int main() {
  Solution sol;
  string ans = sol.countAndSay(20);
  cout << ans << endl;
}

