#include <iostream>
using namespace std;

template <typename T, int size>
class Vector
{
	T vec[size];
public:
	Vector()
	{
		for (int i = 0; i < size; i++)
		{
			vec[i] = 0;
		}
	}

	T& operator[](int index) { return vec[index]; }
	template <class T, int size>
	friend ostream& operator<<(ostream& os, Vector<T, size>& vec);
	template <class T, int size>
	friend istream& operator>>(istream&, Vector<T, size>&);
};
template <class T, int size>
ostream& operator<<(ostream& os, Vector<T, size>& vec)
{

	cout << "VEC:" << endl;
	for (int i = 0; i < size; i++)
	{
		os << vec[i] << endl;
	}
	return os;
}
template <class T, int size>
istream& operator>>(istream& is, Vector<T, size>& vec)
{
	for (int i = 0; i < size; i++)
	{
		is >> vec[i];
	}
	return is;

}






int main()
{

	Vector<int, 5> vec;
	cin >> vec;
	cout << vec << endl;
}