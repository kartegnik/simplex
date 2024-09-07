#pragma once
#include <iostream>
#include <vector>
#include<set>
#include<map>
#include "sparseelement.h"
//#include "tools.h"


struct SparseMatrix {
private:
	int n;
	int m;
	std::vector<std::set<int>> spmi;
	std::vector<std::set<int>> spmj;
	std::map<std::pair<int, int>, double> spm;
public:
	/*
		Конструктор матрицы по умолчанию
	*/
	explicit SparseMatrix();
	/**/
	explicit SparseMatrix(int n, int m); //просто задать размеры а потом заполнять
	/*
		Создать разреженную матрицу
		n - длина
		m - ширина
		a - вектор из SparseElement
	*/
	explicit SparseMatrix(int n, int m, std::vector<SparseElement>& a);
	/*
		Создать разреденную матрицу из плотной
	*/
	explicit SparseMatrix(std::vector<std::vector<double>> &a); //задачать плотную матрицу
	/*
		Создать разреженную с диагональными элементами
	*/
	explicit SparseMatrix(std::vector<double> &a); //задачать диагональ
	/*
		Конструктор копирования
	*/
	SparseMatrix(SparseMatrix const& a);
	/*
		Оператор присваивания
	*/
	SparseMatrix& operator=(const SparseMatrix& other);
	/*
		Деструктор
	*/
	~SparseMatrix() {};
	/*
	Метод возвращает элемент на i и j позиции в матрице
	*/
	double get(int i, int j);
	/*
		Метод устанавливает в i и j позицию элемент v
	*/
	void set(int i, int j, double v);
	/*
		Метод добавляет в i и j позицию элемент v
	*/
	void addto(int i, int j, double v);
	/*
		Метод возвращает индексы столбцов элементов, которые есть в i строке
	*/
	std::set<int> indexrow(int i);
	/*
		Метод возварщает индексы строк элемнтов, которые есть в j стролбце
	*/
	std::set<int> indexcolumn(int j);
	/*
		Метод проверяет есть ли элемент в i и j позиции
	*/
	bool have(int i, int j);
	/*
		Метод возвращает размерность матрицы
		<длина, ширина>
	*/
	std::pair<int, int> getnm();
	/*
		Метод, прибавляющий к одной строке матрицы другую, умноженную на заданный скаляр
		Аргументы:
			x - индекс строки, к которой прибавляем
			y - индекс строки, которую прибавляем
			alpha - скаляр, на который умножается добавляемая строка
	*/
	void etomrow(int x, int y, double alpha); //сложить строки с коэффициентом у j строки, все добавляется в i строку
	/*
		Метод, прибавляющий к одному столбцу матрицы другой, умноженный на заданный скаляр 
		Аргументы:
			x - индекс столбца, к которому прибавляем
			y - индекс столбца, который прибавляем
			alpha - скаляр, на который умножается добавляемый столбец
	*/
	void etomcolumn(int x, int y, double alpha); // тоже но со столбцами
	/*
		Метод выводит всю матрицу
	*/
	void print();
	/*
		Метод проверяет i и j элемент находится в пределах матрицы
	*/
	bool in_matrix(int i, int j);
private:
	/*
		Вспомогательный метод для оператора присваивания
	*/
	void swap(SparseMatrix& tmp);
	/*
		Метод удаляет элемент на i и j позиции
	*/
	void del(int i, int j);
};
