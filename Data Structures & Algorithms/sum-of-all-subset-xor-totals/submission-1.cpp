class Solution {
private:
    int res = 0;
    vector<int> subset;

    void printSubset(int currXor) {
        cout << "subset = [";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i + 1 < subset.size()) cout << ", ";
        }
        cout << "], xor = " << currXor << ", res = " << res << endl;
    }

    void backtrack(vector<int>& nums, int i, int currXor) {
        res += currXor;
        printSubset(currXor);

        for (int j = i; j < nums.size(); j++) {
            cout << "choose " << nums[j] << endl;

            subset.push_back(nums[j]); // choose
            backtrack(nums, j + 1, currXor ^ nums[j]); // explore

            cout << "undo " << nums[j] << endl;
            subset.pop_back(); // undo
        }
    }

public:
    int subsetXORSum(vector<int>& nums) {
        backtrack(nums, 0, 0);
        return res;
    }
};