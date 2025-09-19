#include <bits/stdc++.h>
using namespace std;

class minStack{
public:
	// Time complexity is O[n]
	stack<pair<int, int>> s;	

	void push(int x){
		if(s.empty()){
			s.push({x, x});
		}else{
			int newmin = min(x, s.top().second);
			s.push({x, newmin});
		}
	}

	int pop(){
		if(!s.empty()){
			int removed = s.top().first;
			s.pop();
			return removed;
		}else{
			return -1;
		}
	}

	int getMin(){
		if(!s.empty()){
			return s.top().second;
		}else{
			return -1;
		}
	}
	bool empty(){
		return s.empty();
	}
};

class minQueue{
public:
	minStack front, back;
	// each element goes with three operations at max ((1.push, 2.pop, 3.move))
	//so time complexity is 3*O[n]
	//push back
	void push(int x){
		back.push(x);
	}
	//pop front
	void pop(){
		if(front.empty()){
			while(!back.empty()){
				int el = back.pop();
				front.push(el);
			}
			front.pop();
		}else{
			front.pop();
		}
	}

	int getMin(){
		int min1 = (front.empty())? 1e9: front.getMin();
		int min2 = (back.empty())? 1e9: back.getMin();
		if(min(min1, min2) == 1e9){
			return -1;
		}else{
			return min(min1, min2);
		}
	}

	void printQueue(){
		stack<pair<int, int>> temp;
		while(!front.empty()){
			int el = front.pop();
			temp.push({el, el});
			cout << el << " ";
		}
		while(!temp.empty()){
			front.push(temp.top().first);
			temp.pop();
		}
		while(!back.empty()){
			int el = back.pop();
			temp.push({el, el});
			cout << el << " ";
		}
		while(!temp.empty()){
			back.push(temp.top().first);
			temp.pop();
		}
		cout << endl;
	}


};


class minDeque{
public:
	//time complexity O[n*n];
	/*
		but we need not to push all the elements in front ms and then in back ms again and again
	    just move half of the elements so that for atleast half of elements we need not to perfrom any operation just constant operation
	    then time complexity will be O[n];

	    But How Don't Know!
	*/
	minStack front, back;
	void push_back(int x){
		back.push(x);
	}
	void push_front(int x){
		front.push(x);
	}
	void pop_front(){
		if(front.empty()){
			while(!back.empty()){
				int el = back.pop();
				front.push(el);
			}
		}
		front.pop();
	}
	void pop_back(){
		if(back.empty()){
			while(!front.empty()){
				int el = front.pop();
				back.push(el);
			}
		}
		back.pop();
	}
	int getMin(){
		int min1 = (front.empty())? 1e9: front.getMin();
		int min2 = (back.empty())? 1e9: back.getMin();
		if(min(min1, min2) == 1e9){
			return -1;
		}else{
			return min(min1, min2);
		}
	}
};

// function for finding the min(max(subarrays of length len))hr
int fun(vector<int>&a, int len){
	minQueue q;
	minStack s;
	for(int i = 0; i<len; i++){
		q.push(-a[i]);
	}

	int mini = q.getMin();
	s.push(-mini);
	for(int i = len; i<a.size(); i++){
		q.pop();
		q.push(-a[i]);
		int mini = q.getMin();
		s.push(-mini);
	}
	return s.getMin();
}
int main(){
	int n, q;
	cin >> n >> q;
	vector<int>a(n);
	for(int i =0; i<n; i++){
		cin >> a[i];
	}

	for(int i =0; i<q; i++){
		int q;
		cin >> q;
		cout << fun(a, q) << "\n";
	}
    return 0; 
}
