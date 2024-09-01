#pragma once
#include <iostream>
#include <vector>
#include<set>
#include<map>

using namespace std;

struct SparseMatrix {
private:
	int n;
	int m;
	vector<std::set<int>> spmi;
	vector<std::set<int>> spmj;
	map<pair<int, int>, double> spm;
public:
	explicit SparseMatrix(int n, int m); //просто задать размеры а потом заполнять
	explicit SparseMatrix(vector<vector<double>> a); //задачать плотную матрицу
	explicit SparseMatrix(vector<double> a); //задачать диагональ
	SparseMatrix(SparseMatrix const& a);
	SparseMatrix& operator=(const SparseMatrix& other);
	~SparseMatrix() {};

	double get(int i, int j);
	void set(int i, int j, double v);
	vector<int> indexrow(int i);
	vector<int> indexcolomn(int j);
private:
	void swap(SparseMatrix& tmp);
	bool in_matrix(int i, int j);
	bool have(int i, int j);
	void del(int i, int j);
};