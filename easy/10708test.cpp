#include <iostream>
#include <cmath>
using namespace std;
#define SIZE 10000007

int primes[SIZE], pointer, factors[SIZE] = { 0, -1 };
bool notprime[SIZE] = { true, true };

int Factors(int number) {
	if (!notprime[number])
		return 1;
	int amount = 0, buffer = sqrt(number);
	for (int i = 0; primes[i] <= buffer; i++)
		if (!(number % primes[i])) {
			do {
				number /= primes[i], amount++;
			} while (!(number % primes[i]));
			buffer = sqrt(number);
		}
	if (number > 1) 
		amount++;
	return amount;
}

void Initialize() {
	//cout << "101\n";
	for (int i = 2; i < SIZE; i++) {
		factors[i] = -1;
		if (!notprime[i])
		{
			primes[pointer] = i, pointer++;
			//cout << i <<"\n";
		}
		for (int j = 0; i * primes[j] < SIZE && j < pointer; j++)
			notprime[i * primes[j]] = true;
	}
	//cout << "101\n";
	int buffer = 0;
	for (int i = 2; buffer += Factors(i), buffer < SIZE; i++)
	{
		factors[buffer] = i;
	}
	//cout << "101\n";
		
}

int main() {
	//cin.sync_with_stdio(false), cin.tie(0), cout.tie(0);
	Initialize();
	int number, times = 1;
	while (cin >> number, number >= 0) {
		cout << "Case " << times++ << ": ";
		if (factors[number] == -1)
			cout << "Not possible.";
		else
			cout << factors[number] << '!';
		cout << '\n';
	}
}

