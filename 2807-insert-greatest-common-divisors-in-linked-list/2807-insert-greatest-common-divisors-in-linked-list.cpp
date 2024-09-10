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
    int gcd(int a, int b) {
        if (a == 0) return b;
        if (b > a) return gcd(b, a);
        return gcd(a % b, b);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* root = head;
        while(head->next != nullptr) {
            head->next = new ListNode(gcd(head->val, head->next->val), head->next);
            head = head->next->next;
        }
        return root;
    }
};