class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> warmerDays(n, 0);
        stack<pair<int, int>> st; // {temp, day}
        for (int i = 0; i < n; i++){
            // check if the temperature is warmer then the item on the stack
            int currTemp = temperatures[i];
            while (!st.empty() && currTemp > st.top().first){
                int dayResolved = st.top().second;
                warmerDays[dayResolved] = i - dayResolved;
                st.pop(); // we processed the day, pop from the stack
            }
            st.push({currTemp, i});
        }

        return warmerDays;
    }
};
