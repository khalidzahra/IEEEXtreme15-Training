/*
    Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

    k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

    You may not alter the values in the list's nodes, only nodes themselves may be changed.
*/

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        return reverseList(head, k, getLength(head));
    }
    ListNode* reverseList(ListNode *head, int k, int length) {
        if (length < k) return head;
        int count = 0;
        ListNode* curr = head, *end = nullptr;
        while (count < k) {
            ListNode* next = curr->next;
            curr->next = end;
            end = curr;
            curr = next;
            count++;
        }
        head->next = reverseList(curr, k, length - k);
        return end;
    }

    int getLength(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
};
