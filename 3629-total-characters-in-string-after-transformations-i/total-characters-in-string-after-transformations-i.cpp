#define MOD 1000000007
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        long long freq[26] = {};
        int res = 0;
        for(auto& ch: s) {
            freq[ch - 'a']++;
        }
        while(t--) {
            long long temp[26] = {};
            for(int i = 0; i < 26; i++) {
                if (freq[i]) {
                    if (i != 25) {
                        temp[i + 1] = freq[i];
                    } else {
                        temp[0] = (temp[0] + freq[i]) % MOD;
                        temp[1] = (temp[1] + freq[i]) % MOD;
                    }
                }
            }
            res = 0;
            for(int i = 0; i < 26; i++) {
                freq[i] = temp[i];
                res = (res + freq[i]) % MOD;
            }
        }
        return res;
    }
};