#include<iostream>
using namespace std;
int main() {
	int numbers[] = { 2,99,13,5 };
	int result = 0;
	for (int i = 0; i < sizeof(numbers[0]); i++)
		result = result + numbers[i];
	cout << result << endl;
}