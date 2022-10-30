//Project FUNCTION
#include<iostream>
using namespace std;

//TODO:
//0. ������� ������ �� ��������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//1. � ������ Functions �������� ������� ? ? ? Power(? ? ? ), ������� �������� ��������� �����
//� ��������� �������;

int Add(int a, int b); // �������� ������� (���������� ������� - function declaration)
int Sub(int a, int b);
int Mul(int a, int b);
int Div(int a, int b);
// ��������� ������� Power()
double Power(int a, int b);

void main()
{
	setlocale(LC_ALL, "Russian");

	int a, b;
	cout << "������� ��� �����: "; cin >> a >> b;
	int c = Add(a, b); // ������������� ������� (����� ������� - Function call)
	cout << a << " + " << b << " = " << c << endl;
	cout << a << " - " << b << " = " << Sub(a, b) << endl;
	cout << a << " * " << b << " = " << Mul(a, b) << endl;
	cout << a << " / " << b << " = " << Div(a, b) << endl;
	//��������� ������� Power()
	cout << a << " ^ " << b << " = " << Power(a, b) << endl;
}

int Add(int a, int b) // ���������� ������� (����������� ������� - Function definition)
{
	int sum = a + b;
	return sum;
}
int Sub(int a, int b)
{
	return a - b;
}
int Mul(int a, int b)
{
	return a * b;
}
int Div(int a, int b)
{
	return a / b;
}
// ��������� ������� Power()
double Power(int a, int b)
{
	double pow = 1;
	int c = (b > 0) ? b : -b;
	while (c-- > 0)
	{
		pow *= a;
	}
	return (b > 0) ? pow : 1 / pow;
}