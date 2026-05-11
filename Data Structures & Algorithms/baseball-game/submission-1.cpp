class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> result;
        for (auto operation : operations) {
            // different possibilities
            if (operation == "+") {
                int addition = result[result.size() - 1] + result[result.size() - 2];
                result.push_back(addition);
            }
            else if (operation == "C") {
                result.pop_back();
            }
            else if (operation == "D") {
                int last_num = result.back();
                result.push_back(last_num * 2);
            }
            else {
                result.push_back(stoi(operation));
            }
        }

        int sum =0;
        for (auto v: result){
            sum += v;
        }

        return sum;
    }
};