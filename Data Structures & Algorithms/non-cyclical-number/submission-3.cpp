class Solution {
private:
    int numberConversion(int n){
        int converted = 0;
        while (n > 0){
            converted += pow(n % 10, 2);
            n /= 10;
            //std::cout << converted << std::endl;
        }

        return converted;
    }
public:
    bool isHappy(int n) {
        // Since the problem asks us to detect repetitive number
        // We can use set to do this
        unordered_set<int> uset;
        int currNum = n; 
        while (currNum != 1){
            currNum = numberConversion(currNum);
            auto result = uset.insert(currNum);
            if (not result.second){
                return false;
            }
        }
        
        return true;

    }
};
