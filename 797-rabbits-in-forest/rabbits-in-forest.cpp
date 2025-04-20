class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> says;
        int res = 0;
        for(auto& answer: answers) {
            says[answer]++;
        }
        for(auto& say: says) {
            res += (ceil((float)say.second / (say.first + 1)) * (say.first + 1));
        }
        return res;
    }
};