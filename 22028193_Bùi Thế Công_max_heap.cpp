
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;

void heapify(int arr[], int n, int i)
{

	int parent = (i - 1) / 2;

	if (arr[parent] > 0) {
		if (arr[i] > arr[parent]) {
			swap(arr[i], arr[parent]);
			heapify(arr, n, parent);
		}
	}
}
void sink_down(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (arr[largest] < arr[left] && left < n) {
        largest = left;
    }
    if (arr[largest] < arr[right] && right < n) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[largest], arr[i]);
        sink_down(arr, n, largest);
    }
}
void removeMaxElement(int arr[], int &n) {
    if (n <= 0) {
        return;
    }
    int last_element = arr[n - 1];
    arr[0] = last_element;
    n--;
    sink_down(arr, n, 0);
}
void insertNode(int arr[], int& n, int key)
{
	n = n + 1;
	arr[n - 1] = key;
	heapify(arr, n, n - 1);
}



void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";

	cout << endl;
}

int getMaxElement(int arr[], int n) {
    if (n > 0) {
        return arr[0];
    }
    else{
        return INT_MIN;
    }
}


int main()
{
	int arr[MAX] = {};

	int n = 0;
    for (int i = 0; i < 9; i++) {
        int key; cin >> key;
        insertNode(arr, n, key);
	}
    cout << n << endl;
	printArray(arr, n);
	cout << getMaxElement(arr, n) << endl;
	removeMaxElement(arr, n);
	cout << n << endl;
	printArray(arr, n);

	return 0;
}
