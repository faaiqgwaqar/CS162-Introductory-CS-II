#ifndef WAQARF_MATRIX_HPP
#define WAQARF_MATRIX_HPP

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

template <class T>
class Matrix {
	private:
		int rows;
		int cols;
		T** data;
	public:
		Matrix(int,int);
		~Matrix();
		int getRows();
		int getCols();
		T& at(int, int);
		void add(Matrix<T>&);
};

#endif
