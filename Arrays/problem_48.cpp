//Problem: 836. Rectangle Overlap

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool overlapX = rec1[0] < rec2[2] && rec1[2] > rec2[0];
        bool overlapY = rec1[1] < rec2[3] && rec1[3] > rec2[1];
        return(overlapX && overlapY);
    }
};

//Time Complexity: O(1) - The code does not use any loops (for or while) and does not rely on the size of an input growing.
//Space Complexity: O(1) - The code does not create any dynamic structures like arrays, vectors, or hash maps.