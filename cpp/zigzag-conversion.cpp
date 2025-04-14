#include <vector>
class Solution {
public:
    string convert(string s, int numRows) {
        //init vector
        vector<vector<char>> lines;
        for(int i=0; i<numRows; i++){
            vector<char> v = {};
            lines.push_back(v);
        }
        int dir = 1;
        int line = 0;
        int i = 0;
        if(numRows == 1){
            return s;
        }
        //iterate through input string until null
        while(s[i]){
            //push to current line
            lines[line].push_back(s[i]);
            //if line num about to hit a row boundary, flip dir
            if((dir == 1 && line == numRows-1) || (dir == -1 && line == 0)){
                dir *= -1;
            }
            line += dir;
            i++;
            
        }
        string out = "";
        for(i=0;i<numRows;i++){
            for(int j=0;j<lines[i].size();j++){
                out += lines[i][j];
            }
        }
        return out;
    }
};