#include <string>
#include <math.h>
#include <iostream>
using namespace std;

void tree(int i, int j, int p, int n, int k)
{
	if (i < 1) return;

	cout << j << endl;

	if (n == k)
		tree(i / 2, i / 2, p / 2, 1, k * 2);
	else
		tree(i, j + p, p, n + 1, k);
}

int main()
{
	tree(8, 8, 16, 1, 1);

	::getchar();
}