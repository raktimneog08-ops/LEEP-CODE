#include <vector>

using namespace std;

class Solution {
    int MOD = 1e9 + 7;
    
    typedef vector<vector<long long>> Matrix;
    
    // Helper function to multiply two matrices
    Matrix multiply(const Matrix& A, const Matrix& B) {
        int sz = A.size();
        Matrix C(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                if (A[i][k] == 0) continue; // Skip zero multipliers to optimize speed
                long long aik = A[i][k];
                for (int j = 0; j < sz; j++) {
                    C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }
    
    // Helper function for fast matrix exponentiation
    Matrix power(Matrix A, int p) {
        int sz = A.size();
        Matrix res(sz, vector<long long>(sz, 0));
        // Initialize as Identity matrix
        for (int i = 0; i < sz; i++) res[i][i] = 1; 
        
        while (p > 0) {
            if (p % 2 == 1) res = multiply(res, A);
            A = multiply(A, A);
            p /= 2;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        
        // Base case: arrays of length 1 have no constraints, return available element choices.
        if (n == 1) return m;
        
        int sz = 2 * m;
        Matrix T(sz, vector<long long>(sz, 0));
        
        // Populate the Transition Matrix T
        for (int y = 0; y < m; y++) {
            // From DOWN, x (requires going down to y, thus y < x). Next state is UP, y.
            for (int x = y + 1; x < m; x++) {
                T[y + m][x] = 1; 
            }
            // From UP, x (requires going up to y, thus y > x). Next state is DOWN, y.
            for (int x = 0; x < y; x++) {
                T[y][x + m] = 1;
            }
        }
        
        // Raise Transition matrix to the power of (n - 1)
        Matrix T_n_minus_1 = power(T, n - 1);
        
        long long total = 0;
        
        // Multiply by an initial vector of all 1s (all starts are valid) and sum the outcomes
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                total = (total + T_n_minus_1[i][j]) % MOD;
            }
        }
        
        return total;
    }
};