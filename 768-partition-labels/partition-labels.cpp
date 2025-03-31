class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int> v,result;
        for(int i=0;i<n;i++){
            int t=i;
            for(int j=i+1;j<n;j++){
                if(s[j]==s[i]){
                    t=j;
                }
            }
            v.push_back(t);
        }
        int start=-1,max=v[0];
        for(int i=0;i<n;i++){
            if(max==i){
                result.push_back(max-start);
                start=i;
            }
            if(v[i]>max){
                max=v[i];
                i--;
            }
        }
        return result;
    }
};