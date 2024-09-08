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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;
        int length = 0;
        ListNode* node = head;
        while(node != nullptr) {
            length++;
            node = node->next;
        }
        int quo = length / k, rem = length % k, index = 0, next_index = 0;
        node = head;
        ListNode* prev = nullptr;
        while(node != nullptr) {
            if (index == next_index) {
                if (prev != nullptr) {
                    prev->next = nullptr;
                }
                result.push_back(node);
                next_index += quo + (rem-- > 0 ? 1 : 0);
            }
            prev = node;
            node = node->next;
            index++;
        }
        while(result.size() != k) result.push_back(nullptr);
        return result;
    }
};