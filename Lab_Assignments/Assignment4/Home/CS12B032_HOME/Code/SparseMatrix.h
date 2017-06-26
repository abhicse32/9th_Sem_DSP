#ifndef SPARCE_H
#define SPARCE_H
#include "List.h"

typedef struct Matrix{
	LList** row_lst;
	int n_rows;
	int n_cols;
}Matrix;

Matrix initialize(int,int);
/*Multiply an M x N matrix with N X 1 vector*/
Matrix matrix_vect_multiply(Matrix mat, Matrix vect);

/*Add two matrices*/
Matrix add(Matrix, Matrix);

/*Subtract Matrix b from a*/
Matrix subtract(Matrix a, Matrix b);

#endif