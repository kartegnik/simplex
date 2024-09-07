#pragma once
#include "sparsematrix.h"


struct Simplex {
private:
	int n;
	int m;
	SparseMatrix spm;
	std::vector<double> b;
	std::vector<double> c;
public:
	explicit Simplex(SparseMatrix& spm, std::vector<double>& b, std::vector<double>& c);
	Simplex(const Simplex& a);
	Simplex& operator=(const Simplex& other);
	~Simplex() {};
	void swap(Simplex& tmp);
	void rcf(SparseMatrix& a);
};