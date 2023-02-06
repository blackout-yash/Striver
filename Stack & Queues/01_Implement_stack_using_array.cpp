// Implement stack using array
// Link - https://practice.geeksforgeeks.org/problems/implement-stack-using-array/1



void MyStack :: push(int x) {
	arr[++top] = x;
}

int MyStack :: pop() {
	if (top == -1) return -1;
	return arr[top--];
}