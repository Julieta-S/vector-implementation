#include "vector.h"
using namespace vector_implementation;

template<class T>
vector<T>::vector() :arr_(nullptr), size_(0), last_(0) {}

template<class T>
vector<T>::vector(int num)
{
	try
	{
		if (num < 0)
		{
			throw "Invalid input";
		}
		else
		{
			size_ = num;
			last_ = 0;
		}
	}
	catch (const string& str)
	{
		cout << str;
		terminate();
	}
	try
	{
		arr_ = new T[size_];
	}
	catch (const bad_alloc& ex)
	{
		cout << ex.what();
		terminate();
	}
}

template<class T>
vector<T>::vector(T* arr, int num) :size_(num), last_(num)
{
	try
	{
		arr_ = new T[size_];
		for (int i = 0; i < num; ++i)
		{
			arr_[i] = arr[i];
		}
	}
	catch (const bad_alloc& ex)
	{
		cout << ex.what();
		terminate();
	}
	catch (...)
	{
		cout << " ";
		terminate();
	}
}

template<class T>
vector<T>::vector(const initializer_list<T>& init) :size_(init.size()), last_(init.size())
{
	try
	{
		arr_ = new T[size_];
	}
	catch (const bad_alloc& ex)
	{
		cout << ex.what();
		terminate();
	}

	int i = 0;
	auto itr = init.begin();
	for (; i < size_, itr != init.end(); ++i, ++itr)
	{
		arr_[i] = *itr;
	}
}

template<class T>
vector<T>::vector(const vector<T>& vec) :size_(vec.size_), last_(vec.last_)
{
	try
	{
		arr_ = new T[size_];
		for (int i = 0; i < size_; ++i)
		{
			arr_[i] = vec.arr_[i];
		}
	}
	catch (const bad_alloc& ex)
	{
		cout << ex.what();
		terminate();
	}
	catch (...)
	{
		cout << " ";
		terminate();
	}
}

template<class T>
vector<T>& vector<T>::operator=(const vector<T>& vec)
{
	if (&vec == this)
		return *this;
	size_ = vec.size;
	last_ = vec.last_;
	delete[] arr_;
	try
	{
		arr_ = new T[size_];
		for (int i = 0; i < size_; ++i)
		{
			arr_[i] = vec.arr_[i];
		}
	}
	catch (const bad_alloc& ex)
	{
		cout << ex.what();
		terminate();
	}
	catch (...)
	{
		cout << " ";
		terminate();
	}
	return *this;
}

template<class T>
vector<T>::vector(vector<T>&& vec)
{
	size_ = vec.size_;
	last_ = vec.last_;
	arr_ = vec.arr_;
	vec.arr_ = nullptr;
}

template<class T>
vector<T>& vector<T>::operator=(vector<T>&& vec)
{
	if (&vec == this)
		return *this;

	delete[] arr_;
	size_ = vec.size_;
	last_ = vec.last_;
	arr_ = vec.arr_;
	vec.arr_ = nullptr;

	return *this;
}

template<class T>
vector<T>::~vector<T>()
{
	delete[] arr_;
}

template<class T>
void vector<T>::push_back(const T& var)
{
	if (full())
	{
		size_ *= 2;
		T* ptr = new T[size_];
		int sizeVec = size();
		for (int i = 0; i < sizeVec; ++i)
		{
			ptr[i] = arr_[i];
		}
		delete[] arr_;
		arr_ = ptr;
		ptr = nullptr;
	}
	arr_[last_++] = var;
}

template<class T>
void vector<T>::pop_back()
{
	try
	{
		if (empty())
		{
			throw "The vector's empty";
		}
		else
		{
			--last_;
		}
	}
	catch (const string& str)
	{
		cout << str;
		terminate();
	}
	catch (...)
	{
		cout << " ";
		terminate();
	}
}

template<class T>
const T& vector<T>::operator[](int index)
{
	try
	{
		if (index < 0 || index >= size())
		{
			throw "Out_of_range";
		}
	}
	catch (const string& str)
	{
		cout << str;
		terminate();
	}
	return arr_[index];
}

template<class T>
const T& vector<T>::operator[](int index) const
{
	try
	{
		if (index < 0 || index >= size())
		{
			throw "Out_of_range";
		}
	}
	catch (const string& str)
	{
		cout << str;
		terminate();
	}
	return arr_[index];
}

template<class T>
bool vector<T>::empty() const
{
	return last_ == 0;
}

template<class T>
bool vector<T>::full() const
{
	return last_ == size_;
}

template<class T>
int vector<T>::size() const
{
	return last_;
}

template<class T>
void vector<T>::clear()
{
	size_ = 0;
	last_ = 0;
	arr_ = nullptr;
}

