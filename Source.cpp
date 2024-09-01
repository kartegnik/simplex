#include "sparsematrix.h"

int main(){
	ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
	//cout.setf(ios::fixed), cout.precision(2);
	vector<vector<double>> a = { {1, 2}, {3, 4} };
	SparseMatrix spm(a);
	spm.print();
	cout << "\n";
	spm.etmrow(0, 1, 1.0);
	spm.print();
	cout << "\n";
	spm.etmcolomn(0, 1, -1.0);
	spm.print();
	cout << "\n";
	spm.etmrow(1, 0, -0.5);
	spm.print();
	cout << "\nspm.have(1, 0)= " << spm.have(1, 0);
}

