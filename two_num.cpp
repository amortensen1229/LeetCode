#include <vector>
#include <cmath>
#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
(2 -> 4 -> 3) & (5 -> 6 -> 4)
return (7 -> 0 -> 8)
*/

ListNode* solution(ListNode* l1, ListNode* l2) {
  ListNode* temp;
  ListNode* head;
  if (l1->val + l2->val >= 10) {
    temp = new ListNode((l1->val + l2->val) % 10);
    head = temp;
    if (l1->next && l2->next) { //both have next
      l1->next->val++;
    } else if (l1->next) { //only l1 has next
      l1->next->val++;
    } else if (l2->next) { //only l2 has next
      l2->next->val++;
    } else { //neither have a next
      temp->next = new ListNode(1);
    }
  } else {
    temp = new ListNode((l1->val + l2->val) % 10);
    head = temp;
  }

  l1 = l1->next;
  l2 = l2->next;
  while (l1 && l2) {
    if (l1->val + l2->val >= 10) {
      temp->next = new ListNode((l1->val + l2->val) % 10);
      if (l1->next && l2->next) { //both have next
        l1->next->val++;
      } else if (l1->next) { //only l1 has next
        l1->next->val++;
      } else if (l2->next) { //only l2 has next
        l2->next->val++;
      } else { //neither have a next
        temp->next->next = new ListNode(1);
      }
    } else {
      temp->next = new ListNode((l1->val + l2->val) % 10);
    }
    //advance:
    l1 = l1->next;
    l2 = l2->next;
    temp = temp->next;

  }

  if (!l1 && !l2) { //reached end of both:
    return head;
  }
  else if (!l1) { // reached end of l1 first:
    while (l2) {
      if (l2->val >= 10) {
        temp->next = new ListNode(l2->val % 10);
        if (l2->next) {
          l2->next->val++;
        } else {
          temp->next->next = new ListNode(1);
        }
      } else {
        temp->next = new ListNode(l2->val);
      }
      l2 = l2->next;
      temp = temp->next;
    }
    return head;
  }

  else if (!l2) { //reached end of l2 first:
    while (l1) {
      if (l1->val >= 10) {
        temp->next = new ListNode(l1->val % 10);
        if (l1->next) {
          l1->next->val++;
        } else {
          temp->next->next = new ListNode(1);
        }
      } else {
        temp->next = new ListNode(l1->val);
      }
      l1 = l1->next;
      temp = temp->next;
    }
    return head;
  }
  return head;
}






  /*
  ListNode* temp;
  ListNode* head;
  if (l1->val + l2->val >= 10) {
    temp = new ListNode((l1->val + l2->val) % 10);
    temp->next = new ListNode((l1->val + l2->val) / 10);
    head = temp; //set head
    temp = temp->next; //advance temp
  } else {
    temp = new ListNode(l1->val + l2->val);
    head = temp; //set head
  }

  l1 = l1->next;
  l2 = l2->next;
  temp = temp->next;
  //now we are on second node:



  while (l1 && l2) { //while both nodes exist:
    if (l1->val + l2->val >= 10) {
      temp = new ListNode((l1->val + l2->val) % 10);
      temp->next = new ListNode((l1->val + l2->val) / 10);
      head = temp;
      temp = temp->next;
    } else {
      temp = new ListNode(l1->val + l2->val);
      head = temp;
    }  
    temp = temp->next;  
    l1 = l1->next;
    l2 = l2->next; 
  }

}
*/

int main() {

  ListNode* l1 = new ListNode(9);
  l1->next = new ListNode(9);


  ListNode* l2 = new ListNode(1);


  ListNode* ret = solution(l1, l2);

  while (ret) {
    std::cout << ret->val;
    ret = ret->next;
  }
  std::cout << std::endl;
  return 0;
}
  /*
  TEST CASE 1:
  ListNode* l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  ListNode* l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  TEST CASE 2:
  ListNode* l1 = new ListNode(9);
  ListNode* l2 = new ListNode(1);
  l2->next = new ListNode(9);
  l2->next->next = new ListNode(9);
  l2->next->next->next = new ListNode(9);
  l2->next->next->next->next = new ListNode(9);
  l2->next->next->next->next->next = new ListNode(9);
  l2->next->next->next->next->next->next = new ListNode(9);
  l2->next->next->next->next->next->next->next = new ListNode(9);
  l2->next->next->next->next->next->next->next->next = new ListNode(9);
  l2->next->next->next->next->next->next->next->next->next = new ListNode(9);
  */
