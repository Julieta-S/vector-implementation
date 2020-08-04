#include <iostream>
#include <string>
#include <exception>
using namespace std;

namespace vector_implementation
{
	template<class T>
	class vector
	{
	public:
		vector();
		vector(int num);
		vector(T* arr, int num);
		vector(const initializer_list<T>& init);
		vector(const vector<T>& vec);
		vector& operator=(const vector<T>& vec);
		vector(vector<T>&& vec);
		vector& operator=(vector<T>&& vec);
		~vector();
		void push_back(const T& var);
		void pop_back();
		const T& operator[](int index);
		const T& operator[](int index) const;
		bool empty() const;
		bool full() const;
		int size() const;
		void clear();
	private:
		T *arr_;
		int size_;
		int last_;
	};
}
#pragma once

