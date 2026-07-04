class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // find the number of edges connected to the people
        vector<int> being_trusted(n + 1, 0);
        vector<int> trust_others(n + 1, 0);
        for (const auto& edge : trust){
            being_trusted[edge[1]]++;
            trust_others[edge[0]]++;
        }

        for (int i = 1; i < n + 1; i++){
            if (being_trusted[i] == n - 1 && trust_others[i] == 0){
                return i;
            }
        }

        return -1;
    }
};
