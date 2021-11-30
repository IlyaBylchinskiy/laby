#include <iostream>
#include <string>
using namespace std;


class MathException : public exception
{
protected:
	string op_name; //имя операции
	long val1; //значение левого операнда операции
	long val2; //значение правого операнда операции
public:
	MathException();
	MathException(string name_op, long v1, long v2) : op_name(name_op), val1(v1), val2(v2) {}
	virtual string Message() = 0;
};
//переполнение сверху
class OverflowException : MathException
{

public:
	OverflowException(string name_op, long v1, long v2) : MathException(name_op, v1, v2)
	{
		op_name = name_op;
		val1 = v1;
		val2 = v2;
	}
	string Message()
	{
		string msg = "Переполнение сверху";
		return msg;
	}
};
//переполнение сверху
class UnderflowException : public MathException
{
public:
	UnderflowException(string name_op, long v1, long v2) : MathException(name_op, v1, v2)
	{
		op_name = name_op;
		val1 = v1;
		val2 = v2;
	}
	string Message()
	{
		return "UnderflowException";
	}
};
//деление на 0
class ZdivideException : public MathException {
public:
	ZdivideException(string name_op, long v1, long v2) : MathException(name_op, v1, v2)
	{
		op_name = name_op;
		val1 = v1;
		val2 = v2;
	}
	string Message()
	{
		return "ZeroDivideException";
	}
};


class Math
{
public:
	long Add(long a, long b); //сложение (a + b)
	long Sub(long a, long b); //вычитание (a - b)
	long Mul(long a, long b); //умножение (a * b)
	long Div(long a, long b); //деление (a / b)
	long Mod(long a, long b); //остаток от деления (a % b)
};

long Math::Add(long a, long b)
{
	long sum = a + b;
	if (sum > 2147483647) { throw OverflowException("Sum", a, b); }
	return a + b;
}
long Math::Sub(long a, long b)
{
	long result = a - b;
	if (result < -2147483647) { throw UnderflowException("Sub", a, b); }
	return a - b;
}
long Math::Mul(long a, long b)
{
	long sum = a * b;
	if (sum > 2147483647) { throw OverflowException("Multy", a, b); }
	return sum;
}
long Math::Div(long a, long b)
{
	if (b == 0) { throw ZdivideException("Divide", a, b); }
	return a / b;
}
long Math::Mod(long a, long b)
{
	if (b == 0) { throw ZdivideException("Divide", a, b); }
	return a % b;
}

int main()
{
	setlocale(LC_ALL, "rus");
	try
	{

		Math a;
		cout << a.Add(5, 5) << endl << endl;
		cout << a.Div(5, 1) << endl << endl;
		cout << a.Mod(20, 2) << endl << endl;
		cout << a.Mul(878, 48482) << endl << endl;
		cout << a.Div(15, 0) << endl << endl;
	}
	catch (OverflowException& ex)
	{

		cout << ex.Message() << endl;
	}
	catch (UnderflowException& ex)
	{
		cout << ex.Message() << endl;
	}
	catch (ZdivideException& ex)
	{
		cout << ex.Message();
	}
}