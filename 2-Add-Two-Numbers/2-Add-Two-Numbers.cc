#include <iostream>

/**************************************************************************************************************************
 * Execution Time : 0 ms (leetcode test)
 **************************************************************************************************************************/


class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() { this->val = 0; this->next = nullptr; }
    ListNode(int x) { this->val = x ; this->next = nullptr; };
    ListNode(int x, ListNode *next) { this->val = x; this->next = next; }
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode((l1->val + l2->val) % 10);
        ListNode *last = result;
        int rest = (l1->val + l2->val) / 10;

        l1 = l1->next; l2 = l2->next;

        while(l1 && l2){
            int sum = l1->val + l2->val + rest;
            rest = sum / 10;
            sum = sum % 10;

            ListNode *newElement = new ListNode(sum);
            last->next = newElement;
            last = newElement;


            // to next
            l1 = l1->next; l2 = l2->next;
        }

        if(!l1){
            while(l2){
                ListNode *newElement = new ListNode((l2->val + rest) % 10);
                last->next = newElement;
                last = newElement;
                rest = (l2->val+rest) / 10;
                l2 = l2->next;
            }
        } else if (!l2) {
            while(l1){
                ListNode *newElement = new ListNode((l1->val + rest) % 10);
                last->next = newElement;
                last = newElement;
                rest = (l1->val+rest) / 10;
                l1 = l1->next;
            }
        }

        if(rest != 0){
            ListNode *newElement = new ListNode(rest);
            last->next = newElement;
        }

        return result;
    }
};