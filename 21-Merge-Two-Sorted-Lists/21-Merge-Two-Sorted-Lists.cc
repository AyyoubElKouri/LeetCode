#include <algorithm>

/**************************************************************************************************************************
 * Execution Time : 0 ms (leetcode test)
 **************************************************************************************************************************/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // If one of the two is empty
        if(!list1) return list2;
        if(!list2) return list1;

        // Handle the first node
        ListNode *result = new ListNode(std::min(list1->val, list2->val));
        ListNode *resultCurrent = result;

        ListNode *list1Current = list1;
        ListNode *list2Current = list2;

        if(list1->val > list2->val) list2Current = list2Current->next;
        else list1Current = list1Current->next;

        while(list1Current && list2Current){
            // Create the new node
            ListNode *newNode = new ListNode();
            resultCurrent->next = newNode;
            resultCurrent = newNode;

            newNode->val = std::min(list1Current->val, list2Current->val);

            if(list1Current->val > list2Current->val) list2Current = list2Current->next;
            else list1Current = list1Current->next;
        }

        while(list1Current){
            ListNode *newNode = new ListNode();
            resultCurrent->next = newNode;
            resultCurrent = newNode;

            newNode->val = list1Current->val;
            list1Current = list1Current->next;
        }

        while(list2Current){
            ListNode *newNode = new ListNode();
            resultCurrent->next = newNode;
            resultCurrent = newNode;

            newNode->val = list2Current->val;
            list2Current = list2Current->next;
        }

        return result;
    }
};