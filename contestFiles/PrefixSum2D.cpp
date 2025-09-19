//prefix sum in 2d matrix


/*
    //row wise
    for (int i=0; i<n; i++){
        for (int j=1; j<m; j++) ps[i][j]+=ps[i][j-1];
    }

    //then column wise
    for (int j=0; j<m; j++){
        for (int i=1; i<n; i++) ps[i][j]+=ps[i-1][j];
    }

*/



//another way to do this
/*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            prefix[i][j] = (v[i][j] == 'g')? 1:0;
            if (i > 0) prefix[i][j] += prefix[i - 1][j];
            if (j > 0) prefix[i][j] += prefix[i][j - 1];
            if (i > 0 && j > 0) prefix[i][j] -= prefix[i - 1][j - 1];
        }
    }
*/


/*
    //sum of a submatrix
    auto compute = [&](int i, int j){
        int rx = min(n-1, i+k-1), ry = min(m-1, j+k-1);
        int lx = max(0LL,i-k+1), ly = max(0LL, j-k+1);
        int total = p[rx][ry];

        if (lx > 0) total -= p[lx - 1][ry];
        if (ly > 0) total -= p[rx][ly - 1];
        if (lx > 0 && ly > 0) total += p[lx - 1][ly - 1];

        return total;
    };
*/