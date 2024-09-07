#include "sparsematrix.h"

using namespace std;

double const eps = 1e-9;

SparseMatrix::SparseMatrix() : SparseMatrix(0, 0){}

SparseMatrix::SparseMatrix(int n = 0, int m = 0) : n(n), m(m) {
	spmi.resize(n);
	spmj.resize(m);
};

SparseMatrix::SparseMatrix(int n, int m, std::vector<SparseElement>& a) : SparseMatrix(n, m) {
	for (int i = 0; i < a.size(); ++i)
		this->set(a[i].i, a[i].j, a[i].v);
}

SparseMatrix::SparseMatrix(vector<vector<double>> &a) : SparseMatrix(a.size(), a[0].size()) {	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (abs(a[i][j]) > eps)
			//if (Tools::NE(a[i][j], 0))
				this->set(i, j, a[i][j]);
		}
	}
}

SparseMatrix::SparseMatrix(vector<double> &a) : SparseMatrix(a.size(), a.size()) {
	for (int i = 0; i < n; ++i) {
		if (abs(a[i]) > eps)
			this->addto(i, i, a[i]);
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

void SparseMatrix::swap(SparseMatrix& tmp){
	std::swap(n, tmp.n);
	std::swap(m, tmp.m);
	std::swap(spmi, tmp.spmi);
	std::swap(spmj, tmp.spmj);
	std::swap(spm, tmp.spm);
}

bool SparseMatrix::have(int i, int j) {
	return ((spmi[i].find(j) != spmi[i].end()) && (spmj[j].find(i) != spmj[j].end()));
}

bool SparseMatrix::in_matrix(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

pair<int, int> SparseMatrix::getnm() {
	return { this->n, this->m };
}

double SparseMatrix::get(int i, int j){
	if (have(i, j))
		return spm[{i, j}];
	return 0.0;
}

void SparseMatrix::set(int i, int j, double v) {
	if (abs(v) > eps){
	//if (Tools::NE(v, 0)) {
		spmi[i].insert(j);
		spmj[j].insert(i);
		spm[{i, j}] = v;
	}
}

void SparseMatrix::addto(int i, int j, double v) {
	if (abs(v) > eps){
	//if (Tools::NE(v, 0)) {
		spmi[i].insert(j);
		spmj[j].insert(i);
		spm[{i, j}] += v;
		if (abs(spm[{i, j}]) < eps)
		//if (Tools::NE(spm[{i, j}], 0)) // может конечно можно пораньше подумать что получится 0, и сразу не добавлять но пока так
			del(i, j);
	}
}

set<int> SparseMatrix::indexrow(int i) {
	return spmi[i];
}

set<int> SparseMatrix::indexcolumn(int j) {
	return spmj[j];
}

void SparseMatrix::del(int i, int j) {
	spmi[i].erase(j);
	spmj[j].erase(i);
	spm.erase({ i, j });
}

void SparseMatrix::etomrow(int x, int y, double alpha) { //x - номер первой строки, у - номер 2 строки
	//set<int> str = indexrow(y); //вектор spmi[y] - где есть не нулевые элементы 
	for (int k : indexrow(y))
		addto(x, k, alpha * spm[{y, k}]);
}

void SparseMatrix::etomcolumn(int x, int y, double alpha) {//здесь столбцы
	for (int k : indexcolumn(y))
		addto(k, x, alpha * spm[{k, y}]);
}

void SparseMatrix::print(){
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout.setf(ios::left);
			cout << get(i, j) << "  ";
		}
		cout << "\n";
	}
}
