// Implement Queue using Linked List
// Link - https://practice.geeksforgeeks.org/problems/implement-queue-using-linked-list/1



void MyQueue:: push(int x) {
	QueueNode* element = new QueueNode(x);
	if (front == NULL) {
		front = element;
		rear = element;
	} else {
		rear -> next = element;
		rear = element;
	}
}

int MyQueue :: pop() {
	if (front == NULL) return -1;
	int ans = front -> data;
	QueueNode* temp = front;
	front = front -> next;
	delete temp;
	return ans;
}