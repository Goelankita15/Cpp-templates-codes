#include<bits/stdc++.h>
using namespace std;
int extended_gcd(int a, int b, int &x, int &y){
	if(b == 0){
		//gcd(a, 0) = a
		// ax + 0y = a
		x = 1;
		y = 0;
		return a;
	}

	int x1 , y1;
	int g = extended_gcd(b, a%b, x1, y1);
	x = y1;
	y = x1 - (a/b)*y1;
	return g;
}
int find_solution(int a, int b, int c, int &x, int &y){
	int x0, y0;
	int g = extended_gcd(abs(a), abs(b), x0, y0); // finding the gcd with the help of extendex euclid algorithm 
	//and also finding the value of x0 and y0 to get the soltuion of the LDA
	if(c % g){
		return 0;
	}

	x = x0 * c/g;
	y = y0 * c/g;

	if(a < 0) x = -x;
	if(b < 0) y = -y;
	return 1;
}

//ax + by = g    //gcd(81, 57)
	// a1*x1 + b1*y1 = g  // gcd(57, 24)

	//a1 = b , b1 = a %b
	// bx1 + (a % b)y1 = g
	// b*x1 + (a - (a/b)*b)y1 = g;
	// a*y1 + b(x1 - (a/b)y1) = g // ax + by = c
	
	// ################################
	// # [x = y1 and y = x1-(a/b)*y1] #
	//#################################
void solve_LDA(){
	int a, b, c;
	cin >> a >> b >> c;
	//LDA : ax + by = c
	int x, y;
	if(!find_solution(a, b, c, x, y)){
		cout << "No solution exists\n";
	}else{
		find_solution(a, b, c, x, y);
		cout << "Value of x is : "<< x <<" and"<< " Value of y is: "<< y << "\n";
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve_LDA();
	}
}