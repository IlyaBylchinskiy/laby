#include <iostream>
using namespace std;

class Date
{
	int d;
	int m;
	int y;

public:
	Date() {  }
	//Date(int d = 15, int m = 9, int y = 2021) : d(d), m(m), y(y) { cout << "Вызвался конструктор с параметрами " << endl; }
	void operator=(const Date&);//копирование даты
	Date& operator+=(const Date&);//добавление даты
	Date& operator-=(const Date&);//вычитание даты
	Date& operator+=(int);//добавить дни
	Date& operator-=(int);//вычесть дни
	friend ostream& operator<<(ostream& os, const Date&);//вывод
	friend istream& operator>>(istream& is, Date& date);
	friend Date Convert(Date date); // конвертирование даты
	int GetDay() { return d; }
	int GetMonth() { return m; }
	int GetYear() { return y; }

};
Date& Date:: operator-=(int days)
{
	Date temp;
	temp.d = this->d - days;
	temp.m = this->GetMonth();
	temp.y = this->GetYear();
	temp = Convert(temp);
	return temp;
}

Date& Date:: operator+=(int days)
{
	Date temp;
	temp.d = this->d + days;
	temp.m = this->GetMonth();
	temp.y = this->GetYear();
	temp = Convert(temp);
	return temp;
}


Date& Date ::operator-=(const Date& date)
{
	Date temp;
	temp.y = this->y - date.y;
	temp.m = this->m - date.m;
	temp.d = this->d - date.d;
	temp = Convert(temp);
	return temp;

}
void Date::operator=(const Date& date2)
{
	//cout << "Вызвался оператор =" << this << endl;
	d = date2.d;
	m = date2.m;
	y = date2.y;
}

Date& Date ::operator+=(const Date& date)
{
	Date temp;
	temp.d = this->d + date.d;
	temp.m = this->m + date.m;
	temp.y = this->y + date.y;
	temp = Convert(temp);
	return temp;

}
Date Convert(Date date)
{
	Date temp;
	int dd = 0, mm = 0, yy = 0;
	if (date.d < 0 || date.m < 0 || date.y < 0)
	{
		while (date.d < 0) mm--, date.d += 12;
		while (date.m < 0) yy--, date.m = date.m + 12;
		if (date.y < 0) cout << "WRONG DATE, PLS CHECK UR INFORMATION!!";
	}
	temp.d = date.d + dd;
	while (temp.d > 30) mm++, temp.d = temp.d - 30;
	if (temp.d == 0) temp.d++;
	temp.m = date.m + mm;
	while (temp.m > 12) yy++, temp.m = temp.m - 12;
	if (temp.m == 0) temp.m++;
	temp.y = date.y + yy;
	return temp;
}

istream& operator>>(istream& is, Date& date)
{
	is >> date.d;
	is >> date.m;
	is >> date.y;
	return is;
}

ostream& operator<<(ostream& os, const Date& date)
{
	os << "\tYour date\n" << date.d << "." << date.m << "." << date.y << endl;
	return os;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	Date date;
	Date date2;
	cout << "Введите первую дату: " << endl;
	cin >> date;
	cout << "Введите вторую дату: " << endl;
	cin >> date2;
	cout << date;
	cout << date2;
	date2 = date;
	cout << date2;
	Date sum;
	sum = date2 += date;

	cout << "Наша сумма: " << sum;

	Date diff;
	diff = sum -= date2;
	cout << "Разность: " << diff << endl;

	cout << "Добавим 5 дней к разности: " << endl;
	diff = diff += 5;
	cout << diff;

	cout << "Убавим 15 дней от разности" << endl;
	diff = diff -= 15;
	cout << diff;



}