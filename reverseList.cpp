/**
 * 反转链表
 * Definition for singly-linked list.
 */
#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL;
        while(head) {
            ListNode *temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        return pre;
    }
};