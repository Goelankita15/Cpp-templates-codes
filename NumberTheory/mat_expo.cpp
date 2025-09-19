#include<bits/stdc++.h>
using namespace std;

// we have a matrix a raise it to the power n
int mod = 1e9+7;
void mat_mul(vector<vector<int>>&a, vector<vector<int>>&b, int n){
    vector<vector<int>>c(2, vector<int>(2));
    for(int i =0; i<2; i++){
        for(int j =0; j<2; j++){
            c[i][j] = 0;
            for(int k =0; k<2; k++){
                c[i][j] = ((a[i][k]*b[k][j]) % mod + c[i][j]) % mod;
            }
        }
    }

    for(int i =0; i<2; i++){
        for(int j =0; j<2; j++){
            a[i][j] = c[i][j];
        }
    }
}
void mat_expo(vector<vector<int>>&mat, int n){
    vector<vector<int>>ide(2, vector<int>(2));
    for(int i =0; i<2; i++){
        for(int j =0; j<2; j++){
            if(i == j){
                ide[i][j] = 1;
            }else{
                ide[i][j] = 0;
            }
        }
    }

    while(n > 0){
        if(n % 2){
            mat_mul(ide, mat);
            n--;
        }else{
            mat_mul(mat, mat);
            n = n/2;
        }
    }

    for(int i =0; i<2; i++){
        for(int j =0; j<2; j++){
            mat[i][j] = ide[i][j];
        }
    }
}
int main(){
    int n
    cin >> n;
    vector<vector<int>>mat(2, vector<int>(2));
    mat[0][0] = 1;
    mat[0][1] = 1;
    mat[1][0] = 1;
    mat[1][1] = 0;

    mat_expo(mat, n);
    cout << mat[0][1];
}