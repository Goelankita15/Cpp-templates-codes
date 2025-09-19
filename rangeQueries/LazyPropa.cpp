#include<bits/stdc++.h>
using namespace std;
#define int   long long

vector<int> segTree, lazy;// just like segment Tree a lazy array
void build(vector<int>&arr, int start, int end, int index){
	if(start == end){
		segTree[index] = arr[start];
		return;
	}

	int mid = (start + end)/2;
	int left = 2*index+1, right = 2*index +2 ;
	build(arr, start, mid, left);
	build(arr, mid+1, end, right);
	segTree[index] = segTree[left] + segTree[right];
}
//updation of adding a value in range[l:r] in array in O[logn] time using lazy propagation
void update(vector<int>&arr, int start, int end, int index, int l,int r,  int value){

	//checking if index is lazy if yes then 
	//update the seg index 
	// and mark its child lazy if exists
	if(lazy[index] != 0){
		segTree[index] = (end-start+1)*lazy[index];
		if(start != end){
			lazy[2*index+1] += lazy[index];
			lazy[2*index+2] += lazy[index];
		}
		lazy[index] =0;
	}

	//if complete overlap
	//just make the index of segTree with newvalue
	if(start >= l && r >= end){
		segTree[index] += (end-start+1)*value;
		if(start != end){ // mark its children lazy
			lazy[2*index+1] += value;
			lazy[2*index+2] += value;
		}
		return;
	}

	//if(disjoint)
	if(l > end || r < start){
		return;
	}

	int mid = (start + end)/2;
	int left = 2*index+1, right = 2*index+2;
	update(arr, start, mid, left, l, r, value);
	update(arr, mid+1, end, right, l, r, value);

	segTree[index] = segTree[left] +segTree[right];
}
int query(vector<int>&arr, int start, int end, int pos, int index){
	//if lazy index is not equal to zero update the value 
	if(lazy[index] != 0){
		segTree[index] += (end-start+1)*lazy[index];
		if(start != end){
			lazy[2*index+1] += lazy[index];
			lazy[2*index+2] += lazy[index];
		}
		lazy[index] =0;
	}

	if(start == end){
		return segTree[index];
	}

	//partial 
	int mid = (start+end)/2;
	if(pos > mid){
		return query(arr, mid+1, end, pos, 2*index+2);
	}else{
		return query(arr,start, mid, pos, 2*index+1);
	}
}
int32_t main(){
	int n, q;
	cin >> n >> q;
	vector<int>arr(n);
	for(int i =0; i<n;i++){
		cin >> arr[i];
	}
	segTree.resize(4*n);
   	lazy.resize(4*n);
	build(arr, 0, n-1, 0);
	for(int i =0; i<q; i++){
		int a;
		cin >> a;
		if(a == 1){
			int b, c, d;
			cin >> b >> c>> d;
			b = b-1, c = c-1;
			update(arr, 0, n-1, 0,  b, c, d);
		}else{
			int c;
			cin >> c;
			c = c-1;
			cout << query(arr, 0, n-1, c, 0) << "\n";
		}
	}

	   	// cout<< query(arr, 0, n-1,1, 6, 1)+ 6*5 << "\n"; 
	   	// this question can be solved without lazy propagation
	return 0;
}