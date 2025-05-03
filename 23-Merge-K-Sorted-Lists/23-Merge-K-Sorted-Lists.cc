#include <vector>

/**************************************************************************************************************************
 * Execution Time : 186 ms (leetcode test)
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
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // Get a new vector contain the currents NodeList.
        std::vector<ListNode *> currents(lists.size());
        for(int index = 0 ; index < currents.size() ; ++index) currents[index] = lists[index];

        // Iterate all lists
        ListNode *result = new ListNode();
        ListNode *resultCurrent = result;
        while(this->atLestOneNotNull(currents)){
            int indexMin = getMin(currents);

            ListNode *newNode = new ListNode(currents[indexMin]->val);
            resultCurrent->next = newNode;
            resultCurrent = newNode;

            currents[indexMin] = currents[indexMin]->next;
        }

        return result->next;
    }

    int getMin(std::vector<ListNode*>& currents){
        int index = 0;
        while(index < currents.size() && !currents[index]) ++index;

        if (index == currents.size()) return -1;

        int indexMin = index;
        for (++index ; index < currents.size(); ++index)
            if (currents[index] && currents[index]->val < currents[indexMin]->val)
                indexMin = index;

        return indexMin;
    }

    bool atLestOneNotNull(std::vector<ListNode*>& currents){
        for(auto node: currents) if(node) return true;
        return false;
    }
};