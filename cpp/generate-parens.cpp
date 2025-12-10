#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> valids;
        place_paren(n, n, "", valids);
        return valids;
    }

    void place_paren(int lcount, int rcount, string seq, vector<string> &valids) {
        if (lcount == 0 && rcount == 0) {
            valids.push_back(seq);
        }

        if (lcount - 1 >= 0) {
            place_paren(lcount-1, rcount, seq.append("("), valids);
            seq.pop_back();
        }

        if (rcount - 1 >= lcount) {
            place_paren(lcount, rcount-1, seq.append(")"), valids);
        }

        return;
    }
};
