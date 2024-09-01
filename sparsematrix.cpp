#include "sparsematrix.h"

SparseMatrix::SparseMatrix(int n = 0, int m = 0) : n(n), m(m) {
	spmi.resize(n);
	spmj.resize(m);
};

SparseMatrix::SparseMatrix(vector<vector<double>> &a) : SparseMatrix(a.size(), a[0].size()) {	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (abs(a[i][j]) > eps)
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

void SparseMatrix::swap(SparseMatrix& tmp) {
	std::swap(n, tmp.n);
	std::swap(m, tmp.m);
	std::swap(spmi, tmp.spmi);
	std::swap(spmj, tmp.spmj);
	std::swap(spm, tmp.spm);
}

bool SparseMatrix::have(int i, int j) {// есть ли в i и j элемент матрицы
	return ((spmi[i].find(j) != spmi[i].end()) && (spmj[j].find(i) != spmj[j].end()));
}

bool SparseMatrix::in_matrix(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

pair<int, int> SparseMatrix::getnm() {
	return { this->n, this->m };
}

double SparseMatrix::get(int i, int j) {
	if (have(i, j))
		return spm[{i, j}];
	return 0.0;
}

void SparseMatrix::set(int i, int j, double v) {
	if (abs(v) > eps) {
		spmi[i].insert(j);
		spmj[j].insert(i);
		spm[{i, j}] += v;
		if (abs(spm[{i, j}]) < eps) // может конечно можно пораньше не подумать что получится 0, и сразу не добавлять но пока так
			del(i, j);
	}
}

vector<int> SparseMatrix::indexrow(int i) {
	vector<int> tmp;
	for (auto j : spmi[i])
		tmp.push_back(j);
	return tmp;
}

vector<int> SparseMatrix::indexcolomn(int j) {
	vector<int> tmp;
	for (auto i : spmj[j])
		tmp.push_back(i);
	return tmp;
}

void SparseMatrix::del(int i, int j) {
	spmi[i].erase(j);
	spmj[j].erase(i);
	spm.erase({ i, j });
}

void SparseMatrix::etmrow(int x, int y, double alpha) { //x - номер первой строки, у - номер 2 строки
	vector<int> str = indexrow(y); //вектор spmi[y] - где есть не нулевые элементы 
	for (int k = 0; k < str.size(); ++k)
		set(x, str[k], alpha * spm[{y, str[k]}]);
}

void SparseMatrix::etmcolomn(int x, int y, double alpha) {//здесь столбцы
	vector<int> str = indexcolomn(y);
	for (int k = 0; k < str.size(); ++k)
		set(str[k], x, alpha * spm[{str[k], y}]);
}

void SparseMatrix::print() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout.setf(ios::left);
			cout << get(i, j) << "\t";
		}
		cout << "\n";
	}
}
