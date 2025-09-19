
class{
public:
    int n;
    vector<vector<int>> grid;
    Matrix(int n, vector<vector<int>> g) {
        this->n = n;
        grid = g;
    }

    Matrix operator*(const Matrix& a) {
        vector<vector<int>> x(n, vector<int>(n, 0));
        Matrix c(n, x);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c.grid[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    c.grid[i][j] = mod_add(c.grid[i][j],mod_mul(grid[i][k], a.grid[k][j], mod), mod);
                }
            }
        }
        return c;
    }

    Matrix powerUptoK(int k) {
        vector<vector<int>> x(n, vector<int>(n, 0));
        Matrix res(n, x); // Identity Matrix
        for (int i = 0; i < n; i++) {
            res.grid[i][i] = 1;
        }
        
        Matrix base(n, grid);
        while (k > 0) {
            if (k % 2 == 1) {
                res = res * base;
                k--;
            }else{
                base = base * base;
                k /= 2;
            }
        }
        return res;
    }
};