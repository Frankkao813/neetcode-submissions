/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    private:
    Node* quadTreeHelper(vector<vector<int>>& grid, int row, int col, int n){
        // check if all the number if the grid is the same
        bool gridSame = true;
        int first = grid[row][col];
        for (int i = row; i < row + n; i++){
            for (int j = col; j < col + n; j++){
                if (grid[i][j] != first){
                    gridSame = false;
                    break;
                }
            }
        }

        // if true, this is the leaf
        // first param is true if the value == 1. This is the requirement of the question
        if (gridSame){
            return new Node(first == 1, true);
        }

        int half = n /2;
        // the value of the nonleaf node can be anything
        Node* root = new Node(true, false);
        root -> topLeft = quadTreeHelper(grid, row, col, half);
        root -> topRight = quadTreeHelper(grid, row, col + half, half);
        root -> bottomLeft = quadTreeHelper(grid, row + half, col , half);
        root -> bottomRight = quadTreeHelper(grid, row + half, col + half, half);
    
        return root;
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return quadTreeHelper(grid, 0, 0, n);

    }
};