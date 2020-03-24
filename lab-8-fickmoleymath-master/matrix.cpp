#include "matrix.hpp"

using namespace std;

template <class T>
Matrix<T>::Matrix(int newRows,int newCols){
	rows = newRows;
	cols = newCols;
	data = new T*[rows];
	for (int i = 0; i < rows; ++i)
		data[i] = new T[cols];
}

template <class T>
int Matrix<T>::getRows(){
	return rows;
}

template <class T>
int Matrix<T>::getCols(){
	return cols;
}

template <class T>
T& Matrix<T>::at(int atRow, int atCol){
	try{
		if(atRow < 0 || atRow > rows || atCol < 0 || atCol > cols)
		throw 404;
	}
	catch(...){
		cout << "Out of Range\n";
	}
	return data[atRow][atCol];
}

template <class T>
void Matrix<T>::add(Matrix<T>& other){
	bool caught = false;
		if(rows != other.getRows() || cols != other.getCols())
		throw 404;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			//T num = other[i][j];
			if (caught == true)
				break;
			data[i][j] += other.at(i,j);
		}
	}
}

template <class T>
Matrix<T>::~Matrix(){
//	for(int i = 0; i < rows; i++){
//		delete [] data;
//	}

//	delete data;
}

template class Matrix<int>;
template class Matrix<float>;
