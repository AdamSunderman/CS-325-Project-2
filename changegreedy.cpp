#include <iostream>
#include <string>
#include <vector>

using namespace std;
std::vector<int> changegreedy(std::vector<int> V, int A);

int main()
{
	std::vector<int> V = { 1, 3, 7, 12 };
	int A = 29;
	changegreedy(V, A);
	return 0;
}

std::vector<int> changegreedy(std::vector<int> V, int A)
{
	int length = V.size();
	std::vector<int> C(length);
	for (int i = 0; i < length; i++)
		C[i] = 0;
	for (int i = length - 1; i >= 0; i--)
	{
		if (A >= V[i])
		{
			A -= V[i];
			C[i] += 1;
			i += 1;
		}
	}

	return C;
}
