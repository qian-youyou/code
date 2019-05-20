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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head, *tmp_p;
        head = new ListNode(0);
        tmp_p = head;
        int tmp_x = 0;
        while(l1 != NULL || l2 != NULL || tmp_x != 0){
            int a, b;
            if(l1){
                a = l1->val;
                l1 = l1->next;
            }else{
                a = 0;
            }
            if(l2){
                b = l2->val;
                l2 = l2->next;
            }else{
                b = 0;
            }
            solve(head, a, b, tmp_x);
        }
        head = tmp_p->next;
        delete tmp_p;
        return head;
    }
private:
    void solve(ListNode* &head, int a, int b, int &c){
        head->next = new ListNode(0);
        head = head->next;
        head->val = (a + b + c) % 10;
        c = (a + b + c) / 10;
    }
};