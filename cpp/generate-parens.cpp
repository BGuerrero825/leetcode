#include <string>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> valids;
        place_paren(1, 0, 0, "", n, valids);
        return valids;
    }

    void place_paren(bool putleft, int lcount, int rcount, string seq, int n, vector<string> &valids) {
        if (putleft) {
            if (lcount + 1 > n) {
                return;
            }
            seq = seq.append("(");
            lcount++;
        }
        else if (!putleft) {
            if (rcount + 1 > lcount) {
                return;
            }
            seq = seq.append(")");
            rcount++;
        }

        if (lcount == n && rcount == n) {
            valids.push_back(seq);
        }

        place_paren(1, lcount, rcount, seq, n, valids);
        place_paren(0, lcount, rcount, seq, n, valids);

        return;
    }
};
