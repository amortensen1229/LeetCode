#include <iostream>

/*Definition for singly-linked list.*/
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

  ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* cur = head;
    ListNode* after = head->next;
    while (cur) {
      cur->next = prev;
      prev = cur;
      cur = after;
      if (after) after = after->next;
    }
    return prev;
  }



int main() {
  return 0;
}