#include "vector.h"
#include "vector.cpp"

int main()
{
	vector<int> v1(5), v2(5);
	for (int i = 1; i <= 5; ++i)
	{
		v1.push_back(i * 10);
		v2.push_back(i);
	}

	vector<int> v3(v1);
	v3.pop_back();
	for (int i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	vector<int> v4(move(v3));
	for (int i = 0; i < v4.size(); ++i)
	{
		cout << v4[i] << " ";
	}
	cout << endl;

	vector<int> v5 = move(v2);
	for (int i = 0; i < v5.size(); ++i)
	{
		cout << v5[i] << " ";
	}
	cout << endl;

	const int n = 3;
	int arr[n] = { 1,2,3 };
	vector<int> v6(arr, n);
	for (int i = 0; i < v6.size(); ++i)
	{
		cout << v6[i] << " ";
	}
	cout << endl;

	vector<int> v7{ 1,2,3,4 };
	for (int i = 0; i < v7.size(); ++i)
	{
		cout << v7[i] << " ";
	}
}