#include <iostream>
#include <deque>
using namespace std;

int main()
{
	int mas[8];
	int k;
	cout << "Enter mas: ";
	for (int i = 0; i < 8; i++)
	{
		cin >> k;
		mas[i] = k;
	}
	deque<int> deq;
	for (int i = 0; i < 8; i++)
	{
		if (mas[i] < 0) {
			{
				deq.push_back(mas[i]);
				continue;
			}

		}
	}
	for (int i = 0; i < 8; i++)
	{
		if (mas[i] >= 0) {
			deq.push_back(mas[i]);
		}
	}
	cout << "\n\n";

	for (int i = 0; i < deq.size(); i++)
	{
		cout << " " << deq[i];
	}
}