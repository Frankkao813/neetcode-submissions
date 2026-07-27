class Solution {
private:
    vector<int> curr;
    vector<vector<int>> result;
    void backtrack(int n, int k, int index){
        // success
        if (curr.size() == k){
            result.push_back(curr);
            return;
        }
        if (index > n){
            return;
        }
        
        // choose the number
        curr.push_back(index);
        backtrack(n, k, index + 1);

        curr.pop_back();
        backtrack(n, k, index + 1);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return result;
    }
};