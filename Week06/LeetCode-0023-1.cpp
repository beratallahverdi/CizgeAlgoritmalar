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
#include <queue>

class Solution {
public:
    // This is the brute-force O(nk) algorithm
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        if (lists.size() == 1) return lists[0];

        ListNode *head = NULL, **tail = &head;

        while (1){
            int minIndex = -1;
            for (size_t i=0; i<lists.size(); i++){
                if (lists[i] == NULL) continue;
                if (minIndex < 0 || lists[i]->val < lists[minIndex]->val){
                    minIndex = i;
                } //end-if
            } //end-for

            if (minIndex < 0) break; // All elements consumed

            *tail = lists[minIndex];
            lists[minIndex] = lists[minIndex]->next;

            tail = &(*tail)->next;
        } //end-while

        return head;
    } //end-mergeKLists
};