/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> dirn = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> result = vector<vector<int>>(m, vector<int>(n, -1));
        int x = 0, y = 0, dir = 0;
        while(head != nullptr) {
            int next_x = x + dirn[dir][0], next_y = y + dirn[dir][1];
            if (result[x][y] == -1) {
                result[x][y] = head->val;
                head = head->next;
            }
            if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && result[next_x][next_y] == -1) {
                x = next_x;
                y = next_y;
            } else {
                dir = (dir + 1) % 4;
            }
        }
        return result;
    }
};