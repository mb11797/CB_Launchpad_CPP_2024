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
    
    ListNode*midPoint(ListNode*head){
        ListNode*slow = head;
        ListNode*fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode*reverse(ListNode*&head){
        ListNode*prev = NULL;
        ListNode*curr = head;
        ListNode*nxt;
        
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode*midNode = midPoint(head);
        ListNode*reversedHead = reverse(midNode);
        
        while(head != NULL && reversedHead != NULL){
            if(head->val != reversedHead->val){
                return false;
            }
            head = head->next;
            reversedHead = reversedHead->next;
        }
        return true;        
    }
};