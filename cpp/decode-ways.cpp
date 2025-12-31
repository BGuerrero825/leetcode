#include <string>
#include <iostream>
#include <string_view>

using namespace std;
class Solution {
public:
    uint length = 0;
    int numDecodings(string s) {
      this->length = s.length();
      int result = 0;
      string_view sv(s);
      result = iterDecode(sv, 0);
      return result;
    }

    int iterDecode(string_view s, uint idx) {
      uint valid = 0;
      // cannot pase a lone 0
      if (s[0] == '0') {
        return 0;
      }

      // base case, if end of string
      if (idx + 1 >= this->length) {
        return 1;
      }

      // split path for double digits
      if ((s[0] == '1') ||
          (s[0] == '2' && (s[1] >= '0' && s[1] < '7'))) {
        //cout << string(idx, ' ') << "|" << s[0] << s[1] << "|" << endl;
        valid += iterDecode(s.substr(2), idx+2);
      }
      // continue path for single digit
      //cout << string(idx, ' ') << "|" << s[0] << "|" << endl;
      valid += iterDecode(s.substr(1), idx+1);

      return valid;
    }
};

int main() {
  Solution sol = Solution();
  uint ways = sol.numDecodings("2611055971756562");
  cout << "ways: " << ways << endl;

}
