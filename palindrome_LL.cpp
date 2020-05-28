#include <iostream>
#include <string>



/*Definition for singly-linked list.*/
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


bool isPalindrome(ListNode* head) {
  if (!head || !head->next) {
    return true;
  }
  std::string x;
  ListNode* prev = NULL;
  ListNode* cur = head;
  ListNode* after = head->next;

  while (cur) {
    x.push_back(cur->val);
    cur->next = prev;
    prev = cur;
    cur = after;
    if (after) 
      after = after->next;
  }
  for (int i = 0; i < x.size()/2; ++i) {
    if (x[i] != x[x.size()-1-i] ) {
      return false;
    }
  }
  return true;
}




int main() {
  /*TEST A: */
  ListNode* head = new ListNode(5);
  head->next = new ListNode(7);
  head->next->next = new ListNode(3);
  isPalindrome(head);
  return 0;
}