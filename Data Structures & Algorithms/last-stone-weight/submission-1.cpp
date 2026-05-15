class Solution {
    // Method: max heap -> Since we are comparing the two biggest element in the total stones
    priority_queue<int> pq;
public:
    int lastStoneWeight(vector<int>& stones) {
        for (int stone: stones){
            pq.push(stone);
        }
        while (pq.size() > 1){
            int s1 = pq.top(); pq.pop();
            int s2 = pq.top(); pq.pop();
            if (s1 == s2){
                continue;
            }
            else {
                // the stone with the smaller weight is destroyed
                int newS = s1 - s2;
                pq.push(newS);
            }
        }

        return pq.size() == 0? 0: pq.top();
    }
};
