//≈≈–ÚÀ„∑®
#include<iostream>
using namespace std;
 
 

void swap(int &a, int &b ){
	int c = a;
	a = b;
	b = c;
}

//BubleSort
//Each iteration, the least element buble up.
void BubleSort(int *P, int n){
	for(int i=0;i<n;i++){
		for(int j=n-1; j>i; j--){
			if(P[j] < P[j-1])
				swap(P[j],P[j-1]);
		}
	}
}


//insertion sort
//Form the left to right, in each iteration, insert the element in appropriate place
void InsertionSort(int *P, int n){
	for(int i=1;i<n;i++){
		for(int j=i;j>0;j--){
		if(P[j] < P[j-1])
			swap(P[j], P[j-1]);
		}
	}
}

//selection sort
//Each iteration, the greatest element in the unsorted part is selected to put them in order.
void SelectionSort(int *P, int n){
	int curr;
	for(int i=0; i<n ;i++){
		curr = i;
		for(int j=i+1; j<n ;j++){
			if(P[curr]>P[j]){
				curr = j;
			}
		}
		if(i != curr)
		swap(P[i],P[curr]);
	}
}
//insertion sort for shell sort
void insert2(int *P, int n, int incr){
	for(int i=1;i<n;i+=incr){
		for(int j=i;j>0;j-=incr){
		if(P[j] < P[j-1])
			swap(P[j], P[j-incr]);
		}
	}
}

//shell sort
void shellsort(int *P, int n){
	for(int i=n/2; i>2 ;i/=2){
		for(int j=0;j<i;j++){
			insert2(&P[j], n-j, i);
		}
	}
	insert2(P, n, 1);
}


//meger sort
void MergeSort(int *P, int *temp, int begin, int end){
	if(end == begin)
	return;
		int mid = (begin + end)/2;
		MergeSort(P, temp, begin, mid);
		MergeSort(P, temp, mid+1, end);
		//copy the P array
		for(int i=begin; i<end+1;i++)
			temp[i] = P[i];
		//merge the tew sorted part into one sorted array
		int i1 = begin;
		int i2 = mid+1;
		for(int curr=begin;curr<end+1;curr++){
			if(i1 == mid+1)
				P[curr] = temp[i2++];
			else if(i2 > end)
				P[curr] = temp[i1++];
			else if(temp[i1] < temp[i2])
				P[curr] = temp[i1++];
			else 
				P[curr] = temp[i2++];	
		}
}

//quick sort
void Qsort(int *P, int begin, int end){
	if (begin < end){
		//The right most element is chosen to be pivot element
		int Pivot = P[end];
		//put the element less than pivot on the left handside, and the greater element on the other side	
		int i = begin-1;
		for(int j=begin; j<end; j++){
			if(P[j] < Pivot){
				i = i+1;
				swap(P[i],P[j]);
			}
		}
		swap(P[i+1],P[end]);
		//Quick sort the left hand sides array of pivot
		Qsort(P,begin, i);
		//Quick sort the right hand sides array of pivot
		Qsort(P,i+2, end);
	}
}
void Min_Heapify(int *P, int i, int n){
	int lc = i*2;
	int rc = i*2+1;
	int min;
	if(lc < n && P[lc]<P[i]) 
		min = lc;
	else
		min = i;
		
	if(rc < n && P[rc]<P[min])
		min = rc;
	
	if( i != min){
		swap(P[min], P[i]);
		Min_Heapify(P, min, n);
	}
}

void BuildHeap(int *P, int n){
	for(int i=n/2; i>=0; i--){
		Min_Heapify(P, i, n);
	}
}
//heapsort
void HeapSort(int *P, int n){
	BuildHeap(P,n);
	int heapsize = n;
	for(int i=n;i>=2;i--){
		swap(P[0], P[i-1]);
		Min_Heapify(P,0,--heapsize);
	}
}

//binsort
void BinSort(int *P, int n){
	const int size = 10000;
	int bin[1000];
	for(int i=0;i<n;i++){
		bin[P[i]] = 1; 
	}
	int j = 0;
	for(int i=0;i<1000;i++){
		if(bin[i] == 1)
			P[j++] = i;
		if(j == n)
			break;
	}
}

int pow(int a, int P){
	int pro = 1;
	if(P == 0)
		return 1;
	for(int i=0;i<P;i++){
		pro = pro*a;
	}
	return pro;
}

//countsort
void CountSort(int *P, int n){
	int C[10];
	int B[10];
	for(int i=0;i<10;i++){
		C[i] = 0;
		B[i] = 0;
	}
	//memset(B,0,sizeof(B));
	//memset(C,0,sizeof(C));
	for(int i=0;i<n;i++){
		C[P[i]] += 1;
	}
	for(int i=1;i<n;i++){
		C[i] += C[i-1];
	}
	for(int i=n-1;i>=0;i--){
		B[C[P[i]]-1] = P[i];
		C[P[i]]--;	
	}
	for(int i=0;i<n;i++){
		P[i] = B[i];
	}
}

void CountForRadix(int *P, int *B, int *radix, int n){
	int C[10];
	for(int i=0;i<10;i++){
		C[i] = 0;
	}
	
	for(int i=0;i<n;i++){
		C[radix[i]] += 1;
	}
	for(int i=1;i<n;i++){
		C[i] += C[i-1];
	}
	for(int i=n-1;i>=0;i--){
		B[C[radix[i]]-1] = P[i];
		C[radix[i]]--;	
	}		
}

//radixsort
 void RadixSort(int *P, int K, int n){
 	int radix[10];
 	int B[100];
 	for(int i=0;i<100;i++){
 		B[i] = 0;
	 }
 	for(int i=0;i<10;i++){
 		radix[i] = 0;
	 }
	//memset(Bucket, -1, sizeof(Bucket))
	for(int i=0;i<K;i++){
 		for(int j=0;j<n;j++){
 			radix[j] = (P[j]/pow(10,i))%10;	
		}
		CountForRadix(P,B,radix,n);
		for(int i=0;i<n;i++){
		P[i] = B[i];
		}
	}
 }
 

int main(){
	int temp[10];
	int test[10] = {0,3,22,53,21,43,21,1,6,8};
	RadixSort(test, 2, 10);
	for(int i=0;i<10;i++){
		cout << test[i] << " ";
	}
}
