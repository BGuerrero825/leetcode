#include <vector>
#include <cstring>
#include <cstdint>

class Solution {
    public:
        bool isValidSudoku(std::vector< std::vector<char> > & board) {
            if (!isValidRows(board)) {
                return false; 
            }
            if (!isValidCols(board)) {
                return false; 
            }
            if (!isValidBoxes(board)) {
                return false;
            }
            return true; 
        };

        bool isValidRows(std::vector< std::vector<char> > & board) {
            bool seen[10] = { 0 };
            for (uint8_t i=0; i<board.size(); i++) { // iter row
                memset(seen, 0, sizeof(seen));
                for (uint8_t j=0; j<board[i].size(); j++) { // iter col
                    if (board[i][j] == '.') {
                        continue;
                    }
                    uint8_t curr = (uint8_t)(board[i][j] - '0');
                    if (seen[curr]) {
                        return false;
                    }
                    seen[curr] = true;
                }
            }
            return true;
        };


        bool isValidCols(std::vector< std::vector<char> > & board) {
            bool seen[10] = { 0 };
            for (uint8_t i=0; i<board[i].size(); i++) { // iter col
                memset(seen, 0, sizeof(seen));
                for (uint8_t j=0; j<board.size(); j++) { // iter row
                    if (board[j][i] == '.') {
                        continue;
                    }
                    uint8_t curr = (uint8_t)(board[j][i] - '0');
                    if (seen[curr]) {
                        return false;
                    }
                    seen[curr] = true;
                }
            }
            return true;
        };


        bool isValidBoxes(std::vector< std::vector<char> > & board) {
            bool seen[10] = { 0 };
            for (uint8_t b=0; b<27; b+=3) { // iter box
                uint8_t x = b % 9;
                uint8_t y = (b / 9) * 3;
                memset(seen, 0, sizeof(seen));
                for (uint8_t i=y; i<y+3; i++) { // iter row
                    for (uint8_t j=x; j<x+3; j++) { // iter col
                        if (board[i][j] == '.') {
                            continue;
                        }
                        uint8_t curr = (uint8_t)(board[i][j] - '0');
                        if (seen[curr]) {
                            return false;
                        }
                        seen[curr] = true;
                    }
                }
            }
            return true;
        };
};