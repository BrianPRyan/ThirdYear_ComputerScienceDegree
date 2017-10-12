//function exercise 3

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;

//using namespace std;

int question(string prompt);
int question();

int main ()
{
	int num1 = question("Enter a number: \n");
	cout << "Thanks for supplying number value: " << num1 << "\n";
	
	int num2 = question();
	cout << "Thanks for supplying number value: " << num2 << "\n";
	
	
	return 0;
}

int question(string prompt)
{

	int num;

	cout << prompt;
	cin >> num;
	return num;
	
}

int question()
{

	int num1;

	cout << "Please enter a number: \n";
	cin >> num1;
	return num1;
	
}
