class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // calculate the occurence of the character
        priority_queue<pair<int, char>> occurence;
        if (a > 0) occurence.push({a, 'a'});
        if (b > 0) occurence.push({b, 'b'});
        if (c > 0) occurence.push({c, 'c'});

        string result;
        while (!occurence.empty()){
            auto current = occurence.top();
            occurence.pop();
            // scenario: the charatcer is not used
            int str_length = result.size();
            // we check that if we insert this character, 
            // whether the last element or the second to last element is the same element
            if (result.size() >= 2 && result[str_length - 1] == current.second && 
                result[str_length - 2] == current.second){
                    // no available character to use
                    if (occurence.empty()){
                        break;
                    }
                    auto second_char = occurence.top();
                    occurence.pop();
                    result.push_back(second_char.second);
                    second_char.first -= 1;
                    if (second_char.first > 0){
                        occurence.push(second_char);
                    }
                    
                    // push back the first
                    occurence.push(current);
                }
            else{
                result.push_back(current.second);
                current.first -= 1;
                if (current.first > 0){
                    occurence.push(current);
                }
            }
        }

        return result;
    }
};