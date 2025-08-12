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
    ListNode* swapPairs(ListNode* head) {

        ListNode* temp = head;

        if( head == NULL || head->next == NULL) return temp;

        
        ListNode* current = temp;
        ListNode* next = head->next;
        ListNode* secondNext = head->next->next;


        temp = next;
        temp->next = current;
        temp = temp->next;
        temp->next = secondNext;

        temp->next = swapPairs(temp->next);

        return next;


    }
};