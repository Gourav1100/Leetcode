static bool comp(const pair<int, string>& a, const pair<int, string>& b) {
    return a.first > b.first;
}
class Solution {
public:

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> l;
        for(int i = 0; i < n; i++) {
            l.push_back(make_pair(heights[i], names[i]));
        }
        sort(l.begin(), l.end(), comp);
        for(int i = 0; i < n; i++) {
            names[i] = l[i].second;
        }
        return names;
    }
};