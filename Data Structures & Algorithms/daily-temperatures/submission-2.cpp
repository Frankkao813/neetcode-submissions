class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // method: monotonic decreasing stack
        int n = temperatures.size();
        vector<int> warmerDays(n, 0);
        stack<std::pair<int, int>> st;
        for (int i = 0; i < n; i++){
            // We encounter the warmer weather
            // One warmer day can resolve multiple previous colder days.
            while (!st.empty() && temperatures[i] > st.top().second){
                auto [day, temp] = st.top();
                st.pop();
                warmerDays[day] = i - day;
            }

            st.push({i, temperatures[i]}); // {day, temperature}
        }

        return warmerDays;
    }
};
