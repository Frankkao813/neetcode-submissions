class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        while (low <= high){
            int mid = low + (high - low) / 2;
            // be aware that the number might overflow
            long long number = 1LL * mid * mid;
            if (number == x){
                return mid;
            }

            if (number > x){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return high;
    }
};