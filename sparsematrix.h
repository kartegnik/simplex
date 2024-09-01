#pragma once
#include <iostream>
#include <vector>
#include<set>
#include<map>

using namespace std;
const double eps = 1e-9;


struct SparseMatrix {
private:
	int n;
	int m;
	vector<std::set<int>> spmi;
	vector<std::set<int>> spmj;
	map<pair<int, int>, double> spm;
public:
	explicit SparseMatrix(int n, int m); //просто задать размеры а потом заполнять
	explicit SparseMatrix(vector<vector<double>> &a); //задачать плотную матрицу
	explicit SparseMatrix(vector<double> a); //задачать диагональ
	SparseMatrix(SparseMatrix const& a);
	SparseMatrix& operator=(const SparseMatrix& other);
	~SparseMatrix() {};

	double get(int i, int j);
	void set(int i, int j, double v);
	vector<int> indexrow(int i);
	vector<int> indexcolomn(int j);
	bool have(int i, int j);
	pair<int, int> getnm();
	void etmrow(int i, int j, double alpha); //сложить сткроки с коэффициентом у j строки, все добавляется в i строку
	void etmcolomn(int i, int j, double alpha); // тоже но со столбцами
	void print(); // какая-то странная получилась реализация
	bool in_matrix(int i, int j);
private:
	void swap(SparseMatrix& tmp);
	void del(int i, int j);
};
