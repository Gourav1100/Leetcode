class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<vector<int>> arr;
        int n = dominoes.size();
        for(int i = 0; i < n; i++) {
            if(dominoes[i] == 'L') {
                arr.push_back({i, -1});
            } else if(dominoes[i] == 'R') {
                arr.push_back({i, 1});
            }
        }
        if(arr.size() == 0) {
            return dominoes;
        }
        int j = 0, m = arr.size();
        string result = "";
        for(int i = 0; i < n; i++) {
            if(j == m) {
                result += ".";
            } else if(arr[j][1] == -1 && i <= arr[j][0]) {
                if(i == arr[j][0]) {
                    j++;
                }
                result += "L";
            } else if(arr[j][1] == 1 && i < arr[j][0]) {
                result += ".";
            } else if(arr[j][1] == 1 && i >= arr[j][0]) {
                if(j + 1 < m && arr[j + 1][1] == -1) {
                    int gap = arr[j + 1][0] - arr[j][0] + 1;
                    if(i < arr[j][0] + (gap >> 1)) {
                        result += "R";
                    } else if(i == (arr[j][0] + (gap >> 1)) && ((gap >> 1) << 1) != gap) {
                        result += ".";
                    } else {
                        result += "L";
                    }
                    if(i == arr[j + 1][0] - 1) {
                        j++;
                    }
                } else if(j + 1 < m) {
                    result += "R";
                    if(i == arr[j + 1][0] - 1) {
                        j++;
                    }
                } else {
                    result += "R";
                }
            }
        }
        return result;
    }
};