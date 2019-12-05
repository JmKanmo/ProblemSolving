#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	ListNode* head1 = l1;
	ListNode* head2 = l2;
	ListNode* ret = new ListNode(0);
	ListNode* pointer = ret;
	ListNode* newNode = NULL;
	bool flag = false;

	while (true)
	{
 		if (head1 != NULL && head2 != NULL)
		{
			int n = head1->val + head2->val;
			pointer->val += n;
		}
		else
		{
			if (head1 != NULL)
			{
				pointer->val += head1->val;
			}
			if (head2 != NULL) {
				pointer->val += head2->val;
			}
		}

		if (head1 == NULL && head2 == NULL) {
			break;
		}
		else {
			
			if (pointer->val>= 10) {
				pointer->val -= 10;
				if (pointer->next == NULL) {
					newNode = new ListNode(1);
					pointer->next = newNode;
					pointer = newNode;
				}
				else if (head1->next != NULL || head2->next != NULL) {
					newNode = new ListNode(1);
					pointer->next = newNode;
					pointer = newNode;
				}
			}
			else {
				if ((head1 != NULL && head1->next != NULL) || (head2 != NULL && head2->next != NULL)) {
					newNode = new ListNode(0);
					pointer->next = newNode;
					pointer = newNode;
				}
			}
		}
		if (head1 != NULL) head1 = head1->next;
		if (head2 != NULL) head2 = head2->next;
	}
	return ret;
}



int main()
            {
	ListNode* temp1 = (ListNode*)malloc(sizeof(ListNode*));
	temp1->val = 1;                                          
	temp1->next = NULL;

	ListNode* temp2 = (ListNode*)malloc(sizeof(ListNode*));
	temp2->val = 9;
	temp2->next = (ListNode*)malloc(sizeof(ListNode*));
	temp2->next->val = 9;
	temp2->next->next = NULL;

	addTwoNumbers(temp1, temp2);
	return 0;
}