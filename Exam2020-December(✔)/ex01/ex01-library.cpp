#include <iostream>
#include "ex01-library.h"
using namespace std;

// Task 1(a).  Implement this function
Complex **createMatrix(unsigned int m, unsigned int n, Complex c) {
    // Allocate memory for the matrix
    Complex **matrix = new Complex*[m];
    for (unsigned int i = 0; i < m; ++i) {
        matrix[i] = new Complex[n];
        for (unsigned int j = 0; j < n; ++j) {
            matrix[i][j] = c;  // Initialize each element with c
        }
    }
    return matrix;
}

// Task 1(b).  Implement this function
void displayMatrix(Complex **A, unsigned int m, unsigned int n) {
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            // Print the real part
            cout << A[i][j].re;
            // Print the imaginary part with appropriate sign
            if (A[i][j].im >= 0) {
                cout << "+" << A[i][j].im << "i";
            } else {
                cout << A[i][j].im << "i";
            }
            // Print space except for the last element in the row
            if (j < n - 1) {
                cout << " ";
            }
        }
        cout << endl;  // Newline after each row
    }
}

// Task 1(c).  Implement this function
Complex **createIdentityMatrix(unsigned int n) {
    // Create an n x n matrix initialized with 0 + 0i
    Complex **identity = createMatrix(n, n, {0, 0});
    // Set the diagonal elements to 1 + 0i
    for (unsigned int i = 0; i < n; ++i) {
        identity[i][i] = {1, 0};
    }
    return identity;  // Return the created identity matrix
}

// Task 1(d).  Implement this function
void multMatrix(Complex **A, Complex **B, Complex **C,
                unsigned int m, unsigned int n, unsigned int p) {
    // Initialize result matrix C with zeros
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < p; ++j) {
            C[i][j] = {0, 0};  // Set each element to 0+0i
        }
    }

    // Perform matrix multiplication
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < p; ++j) {
            for (unsigned int k = 0; k < n; ++k) {
                Complex prod = mult(A[i][k], B[k][j]);  // Multiply elements
                C[i][j] = add(C[i][j], prod);  // Add the result to the current sum
            }
        }
    }
}

// Do not modify
Complex add(Complex c, Complex d) {
    Complex result = { c.re + d.re, c.im + d.im };
    return result;
}

// Do not modify
Complex mult(Complex c, Complex d) {
    Complex result;
    result.re = (c.re * d.re) - (c.im * d.im);
    result.im = (c.re * d.im) + (c.im * d.re);
    return result;
}

// Do not modify
void deleteMatrix(Complex **A, unsigned int nRows) {
    for (unsigned int i = 0; i < nRows; i++) { delete[] A[i]; }
    delete[] A;
}
