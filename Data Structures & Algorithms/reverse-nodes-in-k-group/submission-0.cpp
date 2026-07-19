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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = new ListNode(), *prevk = start;
        start->next = head, prevk->next = head;
        while(true){
            ListNode* nextk = head;
            for(int i = 0; i<k; i++){
                if(nextk == NULL) return start->next;
                nextk = nextk->next;
            }
            ListNode* temp = head->next, *prev = head;
            while(temp!=nextk){
                ListNode* tmp = temp->next;
                temp->next = prev;
                prev = temp;
                temp = tmp;
            }
            prevk->next = prev;
            head->next = nextk;
            prevk = head;
            head = nextk;
        }
        return start->next;
    }
};
