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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> to_delete;
        for(auto& item: nums) {
            to_delete[item] = 1;
        }
        ListNode* newHead = nullptr;
        while(head != nullptr) {
            if (to_delete[head->val]) {
                head = head->next;
                continue;
            } else if(newHead == nullptr) {
                newHead = head;
            }
            if (head->next == nullptr || !to_delete[head->next->val]) {
                head = head->next;
            } else {
                head->next = head->next->next;
            }
        }
        return newHead;
    }
};