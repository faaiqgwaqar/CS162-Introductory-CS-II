#include "matrix.hpp"

using namespace std;

int main() {
	Matrix<int> A(5,5);
	Matrix<int> B(5,5);
	
	for(int i = 0; i < A.getRows(); ++i){
		for(int j = 0; j < A.getCols(); ++j){
			A.at(i,j) = 2;
		}
	}

	for(int i = 0; i < B.getRows(); ++i){
		for(int j = 0; j <  B.getCols(); ++j){
			B.at(i,j) = 5;
		}
	}

	A.add(B);

	for(int i = 0; i < A.getRows(); i++){
		for(int j = 0; j < A.getRows(); j++){
			cout << A.at(i,j) << " ";
		}
		cout << "\n";
	}
	
	cout << "\n\n";

	Matrix<float> C(5,5);
	Matrix<float> D(5,5);
	
	for(int i = 0; i < C.getRows(); ++i){
		for(int j = 0; j < C.getCols(); ++j){
			C.at(i,j) = 2.7;
		}
	}

	for(int i = 0; i < D.getRows(); ++i){
		for(int j = 0; j <  D.getCols(); ++j){
			D.at(i,j) = 5.4;
		}
	}

	C.add(D);

	for(int i = 0; i < C.getRows(); i++){
		for(int j = 0; j < C.getRows(); j++){
			cout << C.at(i,j) << " ";
		}
		cout << "\n";
	}

	cout << "out of bounds throw checking\n";
	D.at(6,5);
	cout << "\n\n";

	cout << "size mismatch throw checking\n";
	Matrix<int> E(4,7);
	Matrix<int> F(3,6);
	E.add(F);

	return 0;
}

