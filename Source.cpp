#include "sparsematrix.h"

int main(){
	vector<vector<double>> a = { {1, 0}, {3, 2} };
	SparseMatrix spm(a);
	vector<int> b = spm.indexrow(0);
	for (int i = 0; i < b.size(); ++i) cout << b[i] << " ";
	cout << "\n";
	b = spm.indexrow(1);
	for (int i = 0; i < b.size(); ++i) cout << b[i] << " ";
	cout << "\n";

}
// 1  0 -> [0]
// 3  2 -> [0, 1]
