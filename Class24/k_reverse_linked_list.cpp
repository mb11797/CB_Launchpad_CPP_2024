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
    
    ListNode*reverseKGroup(ListNode*&head, int k, int lenOfLL){
        if(lenOfLL < k){
            return head;
        }
        
        // Step - 1: Reverse k Nodes
        ListNode*prev = NULL, *curr = head, *nxt;
        int i=0;
        while(i < k){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            i++;
        }
        
        // Step-2: Recursive call and self work after that to point head to next k group ka new Head
        head->next = reverseKGroup(curr, k, lenOfLL-k);
        return prev;
    }
    
    int length(ListNode*head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head->next;
        }
        return len;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int lenOfLL = length(head);
        
        head = reverseKGroup(head, k, lenOfLL);
        return head;
    }
};