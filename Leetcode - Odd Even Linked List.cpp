/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return head;
        else {
            ListNode* x = head->next;
            ListNode* now = head;
            int odd = 0;
            while(now){
                odd = 1-odd;
                ListNode* temp = now->next;
                if (odd == 1){
                    if (temp == NULL){
                        now->next = x;
                        break;
                    }
                    else if (temp->next == NULL){
                        now -> next = x;
                        break;
                    }
                }
                now->next = temp->next;
                now = temp;
            }
            return head;
        }
    }
};
