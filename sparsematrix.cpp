#include "sparsematrix.h"

SparseMatrix::SparseMatrix(int n = 0, int m = 0) : n(n), m(m) {
	spmi.resize(n);
	spmj.resize(m);
};

SparseMatrix::SparseMatrix(vector<vector<double>> a) : SparseMatrix(a.size(), a[0].size()) {	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j])
				this->set(i, j, a[i][j]);
		}
	}
}

SparseMatrix::SparseMatrix(vector<double> a) :SparseMatrix(a.size(), a.size()) {
	for (int i = 0; i < n; ++i) {
		if (a[i])
			this->set(i, i, a[i]);
	}
}

SparseMatrix::SparseMatrix(SparseMatrix const &a):n(a.n), m(a.m) {
	this->spmi = a.spmi;
	this->spmj = a.spmj;
	this->spm = a.spm;
}

SparseMatrix &SparseMatrix::operator=(SparseMatrix const& other) {
	if (this != &other) {
		SparseMatrix(other).swap(*this);
	}
	return *this;
}

bool SparseMatrix::have(int i, int j) {// есть ли в i и j элемент матрицы
	return ((spmi[i].find(i) != spmi[i].end()) && (spmj[j].find(j) != spmj[j].end()));
}

bool SparseMatrix::in_matrix(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

void SparseMatrix::swap(SparseMatrix& tmp) {
	std::swap(n, tmp.n);
	std::swap(m, tmp.m);
	std::swap(spmi, tmp.spmi);
	std::swap(spmj, tmp.spmj);
	std::swap(spm, tmp.spm);
}

double SparseMatrix::get(int i, int j) {
	if (have(i, j))
		return spm[{i, j}];
	return 0.0;
}

void SparseMatrix::set(int i, int j, double v) {
	if (v) {
		spmi[i].insert(i);
		spmj[j].insert(j);
		spm[{i, j}] += v;
	}
}

vector<int> SparseMatrix::indexrow(int i) {
	vector<int> tmp;
	for (auto j : spmj[i])
		tmp.push_back(j);
	return tmp;
}

vector<int> SparseMatrix::indexcolomn(int j) {
	vector<int> tmp;
	for (auto i : spmi[j])
		tmp.push_back(i);
	return tmp;
}

void SparseMatrix::del(int i, int j) {
	spmi[i].erase(i);
	spmj[j].erase(j);
	spm.erase({ i, j });
}