class Solution {
private:
    vector<vector<int>> result;
    vector<int> curr;
    void backtrack(vector<int>& candidates, int index, int remaining){
        if (remaining == 0){
            result.push_back(curr);
            return;
        }
        if (remaining < 0 || index >= candidates.size()) return;

        // select the element
        curr.push_back(candidates[index]);
        backtrack(candidates, index + 1, remaining - candidates[index]);
        
        curr.pop_back();

        int nextIndex = index + 1;
        while (nextIndex < candidates.size() && 
            candidates[nextIndex] == candidates[index]){
                nextIndex++;
            }
        backtrack(candidates, nextIndex, remaining);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target);
        return result;
    }
};
