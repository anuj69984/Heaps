#include <iostream>
#include <climits>
using namespace std;

//Time complexity for Building a Binary Heap is O(n)

class Minheap{
	int *A;
	int heap_size;
	int capacity;

public :
	Minheap (int capacity); // constructor
	void minhepify(int i);
	int left(int i){
		return (2*i)+1;
	}
	int right(int i){
		return (2*i)+2;
	}
	int parent(int i){
		return (i-1)/2;
	}

	int extractMin();

	void DecreaseKey(int i, int new_val);

	int getmin();

	void deleteKey(int i);
	void insert(int k);
};
int Minheap::getmin(){
	return A[0];
}
void swap(int *x, int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

Minheap ::Minheap(int cap){
	heap_size=0;
	capacity=cap;
	A= new int[cap];
}

// O(n.logn)
void Minheap::minhepify(int i){
	int l=left(i);
	int r=right(i);
	int smallest=i;
	if(l<heap_size && A[l]<A[i])
		smallest=l;
	if(r<heap_size && A[r]<A[smallest])
		smallest=r;
	if(smallest!=i){
		swap(&A[i],&A[smallest]);
		minhepify(smallest);
	}
} 

int Minheap::extractMin(){
	if(heap_size<=0){
		return INT_MAX;
	}
	if(heap_size==1){
		heap_size--;
		return A[0];
	}
	int root=A[0];
	A[0]=A[heap_size-1];
	heap_size--;
	minhepify(0);
return root;	
}

void Minheap::DecreaseKey(int i, int new_val){
	A[i]=new_val;
	while(i!=0 && A[parent(i)] >A[i]){
		swap(&A[i],&A[parent(i)]);
		i=parent(i);
	}
}

void Minheap::deleteKey(int i){
	DecreaseKey(i,INT_MIN);
	extractMin();
}

void Minheap::insert(int k){
	if(heap_size ==capacity){
		cout<<"heap overflow !\n";
		return;
	}
	heap_size++;
	int i=heap_size-1;
	A[i]=k;
	while(i!=0 && A[parent(i)] >A[i]){
		swap(&A[i],&A[parent(i)]);
		i=parent(i);
	}
}

int main(int argc, char const *argv[])
{
	int cap,k;
	cout<<"Enter the capacity of heap : ";
	cin>>cap;
	Minheap h(cap);
	cout<<"Enter the elements in heap : ";
	for (int i = 0; i < cap; ++i)
	{
		cin>>k;
		h.insert(k);
	}
	cout<<"Minimum element is : "<<h.getmin()<<endl;
	h.DecreaseKey(4,1);
	cout<<"Minimum element is : "<<h.getmin()<<endl;
	h.extractMin();
	cout<<"Minimum element is : "<<h.getmin()<<endl;
	return 0;
}