/**************************************************************************************************************************
 * Execution Time : 0 ms (leetcode test)
 **************************************************************************************************************************/


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

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val {1}, next {nullptr} {}
    ListNode(int x): val {x}, next {nullptr} {}
    ListNode(int x,ListNode *Next) : val{x}, next {Next} {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // get the list size
        int size = 1;
        ListNode *current = head;
        while(current->next) { ++size; current = current->next; }

        // if the deleted node is the head
        if(size == n){
            ListNode *temp = head;
            head = head->next;
            delete(temp);
            return head;
        }

        // set the current before the deleted node
        current = head;
        int index {0};

        while(index < size - n - 1){
            current = current->next;
            ++index;
        }

        // remove
        ListNode *temp = current->next;
        current->next = temp->next;
        delete(temp);

        return head;
    }
};