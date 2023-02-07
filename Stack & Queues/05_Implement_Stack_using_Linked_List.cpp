// Implement Stack using Linked List
// Link - https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/1



void MyStack ::push(int x) {
	StackNode* element = new StackNode(x);
	element -> next = top;
	top = element;
}

int MyStack ::pop() {
	if (top == NULL) return -1;
	int ans = top -> data;
	top = top -> next;
	return ans;
}