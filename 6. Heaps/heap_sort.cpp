#include <iostream>
using namespace std;

void heapify(int A[], int n, int i){
	int largest=i;
	int left= (2*i)+1;
	int right=(2*i)+2;
	if(left < n && A[left] > A[largest])
		largest=left;
	if(right < n && A[right] > A[largest])
		largest=right;
	if(largest != i){
		swap(A[i],A[largest]);
		heapify(A,n,largest);
	}
}

void heapsort(int A[], int n){
	for (int i = n/2 -1; i >=0 ; i--)
	{
		heapify(A,n,i);
	}
	for (int i = n-1; i >=0 ; i--)
	{
		swap(A[0],A[i]);
		heapify(A,i,0);
	}
}
void print(int A[], int n){
	for (int i = 0; i < n; ++i)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the size of heap : ";
	cin>>n;

	int A[n];
	cout<<"Enter the elements : ";
	for (int i = 0; i < n; ++i)
	{
		cin>>A[i];/* code */
	}
	cout<<"After heapifying : ";
	heapify(A,n,0);
	print(A,n);
	cout<<"After sorting : ";
	heapsort(A,n);
	print(A,n);
	return 0;
}