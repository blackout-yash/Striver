// Implement Queue using array
// Link - https://practice.geeksforgeeks.org/problems/implement-queue-using-array/1



void MyQueue :: push(int x) {
	arr[rear] = x;
	rear++;
}

int MyQueue :: pop() {
	if (front == rear) return -1;
	return arr[front++];
}