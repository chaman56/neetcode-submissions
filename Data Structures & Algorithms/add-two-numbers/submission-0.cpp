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
    ListNode* add(ListNode* l1, ListNode* l2, int carry){
        if(l1 == NULL && l2 == NULL && carry==0)return nullptr;
        int s = carry;
        if(l1)s+=l1->val;
        if(l2)s+=l2->val;
        ListNode* node = new ListNode(s%10);
        node->next = add(l1?l1->next:NULL, l2?l2->next:NULL,s>9);
        return node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
};
