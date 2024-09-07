#include "simplex.h"

using namespace std;

Simplex::Simplex(SparseMatrix& spm, std::vector<double>& b, std::vector<double>& c) {
	this->n = spm.getnm().first;
	this->m = spm.getnm().second;
	this->spm = spm;
	this->b = b;
	this->c = c;
}

Simplex::Simplex(const Simplex& a) {
	this->n = a.n;
	this->m = a.m;
	this->spm = a.spm;
	this->b = a.b;
	this->c = a.c;
}

Simplex& Simplex::operator=(Simplex const& other) {
	if (this != &other) {
		Simplex(other).swap(*this);
	}
	return *this;
}

void Simplex::swap(Simplex& tmp) {
	std::swap(n, tmp.n);
	std::swap(m, tmp.m);
	std::swap(spm, tmp.spm);
	std::swap(b, tmp.b);
	std::swap(c, tmp.c);
}
/*преобразование матрицы в каноничную форму + строка целевой функции + столбец ограничений*/
void Simplex::rcf(SparseMatrix &a) {
	;
}

