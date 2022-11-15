//HOME WORK
#include<iostream>
#include<conio.h>
using namespace std;

//TODO:
//� Solution Functions �������� ������ Arrays, � � ��� ����������� ��������� ������� :
void FillRand(int arr[], const int SIZE, int minRand = 0, int maxRand = 100);	//? ? ? FillRand(? ? ? );	//��������� ������ ���������� ������� � �������� ��������� 
//																				//(�������� �� ��������� �� 0 �� 100)
void Print(int arr[], const int SIZE);		//? ? ? Print(? ? ? );		//������� ������ �� �����
int Sum(int arr[], const int SIZE);			//? ? ? Sum(? ? ? );		//���������� ����� ��������� �������
double Avg(int arr[], const int SIZE);		//? ? ? Avg(? ? ? );		//���������� �������-�������������� ��������� �������
int minValueIn(int arr[], const int SIZE);	//? ? ? minValueIn(? ? ? );//���������� ����������� �������� �� �������
int maxValueIn(int arr[], const int SIZE);	//? ? ? maxValueIn(? ? ? );//���������� ������������ �������� �� �������

void shiftLeft(int arr[], const int SIZE);	//? ? ? shiftLeft(? ? ? );	//��������� ����������� ����� ������� �� �������� ����� ��������� �����
void shiftRight(int arr[], const int SIZE);	//? ? ? shiftRight(? ? ? );//��������� ����������� ����� ������� �� �������� ����� ��������� ������
void Sort(int arr[], const int SIZE);		//? ? ? Sort(? ? ? );		//��������� ���������� ������� � ������� �����������
void UniqueRand(int arr[], const int SIZE);	//? ? ? UniqueRand(? ? ? );//��������� ������ ����������� ���������� ������� � �������� ���������
void Search(int arr[], const int SIZE);		//? ? ? Search(? ? ? );	//������� � ������� ������������� ��������, ������� �� �� �����,
//											//� ������� �� ����� ���������� ����������

void main()
{
	setlocale(LC_ALL, "Russian");

	cout << "\t\tHomeWork FUNCTIONS\n";
	cout << "\t\t***�������� ������� \"�������\"***\n\n";
	const int SIZE = 10;
	int arr[SIZE] = {};
	int uniqArr[SIZE] = {};
	//int arrCount[SIZE] = {};
	FillRand(arr, SIZE);			//��������� ������ ���������� ������� � �������� ��������� 
	Print(arr, SIZE);				//������� ������ �� �����
	cout << "\t����� ���� ��������� ������� �����: " << Sum(arr, SIZE) << endl;					//���������� ����� ��������� �������
	cout << "\t������-�������������� ���� ��������� ������� �����: " << Avg(arr, SIZE) << endl; //���������� �������-�������������� ��������� �������
	cout << "\t����������� �������� ������� �����: " << minValueIn(arr, SIZE) << endl;			//���������� ����������� �������� �� �������
	cout << "\t������������ �������� ������� �����: " << maxValueIn(arr, SIZE) << endl << endl;			//���������� ������������ �������� �� �������
	shiftLeft(arr, SIZE);			//��������� ����������� ����� ������� �� �������� ����� ��������� �����
	Print(arr, SIZE);
	shiftRight(arr, SIZE);			//��������� ����������� ����� ������� �� �������� ����� ��������� ������
	Print(arr, SIZE);
	cout << "\t\t���������� �������.\n";
	Sort(arr, SIZE);				//��������� ���������� ������� � ������� �����������
	Print(arr, SIZE);
	UniqueRand(uniqArr, SIZE);			//��������� ������ ����������� ���������� ������� � �������� ���������
	cout << "\n\t������ ���������� ��������:\n";
	Print(uniqArr, SIZE);
	cout << "\n\t����� ������������� �������� �� ������� arr[]:\n";
	Print(arr, SIZE);
	Search(arr, SIZE);				//������� � ������� ������������� ��������, ������� �� �� �����, � ������� �� ����� ���������� ����������
}

void FillRand(int arr[], const int SIZE,  int minRand, int maxRand)	//��������� ������ ���������� ������� � �������� ��������� (�������� �� ��������� �� 0 �� 100)
{
	if (minRand == maxRand) maxRand++;
	if (minRand > maxRand)
	{
		int buffer = minRand;
		minRand = maxRand;
		maxRand = buffer;
	}
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}

void Print(int arr[], const int SIZE)				//������� ������ �� �����
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << '\t' << arr[i];
	}
	cout << endl;
}

int Sum(int arr[], const int SIZE)					//���������� ����� ��������� �������
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		sum += arr[i];
	}
	return sum;
}

double Avg(int arr[], const int SIZE)				//���������� �������-�������������� ��������� �������
{
	return (double)Sum(arr, SIZE) / SIZE;
}

int minValueIn(int arr[], const int SIZE)			//���������� ����������� �������� �� �������
{
	int min = arr[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (arr[i] < min) min = arr[i];
	}
	return min;
}

int maxValueIn(int arr[], const int SIZE)			//���������� ������������ �������� �� �������
{
	int max = arr[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

void shiftLeft(int arr[], const int SIZE)			//��������� ����������� ����� ������� �� �������� ����� ��������� �����
{
	int shift;
	cout << "������� ���������� �����, �� ������� ����� �������� ������ �����: "; cin >> shift;
	for (int j = 0; j < shift; j++)
	{
		int temp = arr[0];
		for (int i = 1; i < SIZE; i++)
		{
			arr[i - 1] = arr[i];
		}
		arr[SIZE - 1] = temp;
	}
}

void shiftRight(int arr[], const int SIZE)			//��������� ����������� ����� ������� �� �������� ����� ��������� ������
{
	int shift;
	cout << "������� ���������� �����, �� ������� ����� �������� ������ ������: "; cin >> shift;
	for (int j = 0; j < shift; j++)
	{
		int temp = arr[SIZE - 1];
		for (int i = SIZE - 1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = temp;
	}
}

void Sort(int arr[], const int SIZE)				//��������� ���������� ������� � ������� �����������
{
	for (int i = 0; i < SIZE; i++)
	{
		int min = arr[i];
		for (int j = i + 1; j < SIZE; j++)
		{
			if (arr[j] < arr[i])
			{
				min = arr[j];
				arr[j] = arr[i];
				arr[i] = min;
			}
		}
	}
}

void UniqueRand(int arr[], const int SIZE)			//��������� ������ ����������� ���������� ������� � �������� ���������
{
	int limit;
	cout << "������ ������� " << SIZE << " �����. ������� ����������� ������������� �������� ������� : ";
	if (_getch() == 13) limit = 100;
	else cin >> limit;
	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		bool uniq = true;
		do
		{
			arr[i] = rand() % (limit + 1);
			for (int j = 0; j < i; j++)
			{
				if (arr[i] == arr[j]) uniq = false;
			}
			uniq = !uniq;
		} while (uniq);
	}
}

void Search(int arr[], const int SIZE)				//������� � ������� ������������� ��������, ������� �� �� �����, � ������� �� ����� ���������� ����������
{
	bool printing = false;
	for (int i = 0; i < SIZE; i++)
	{
		int count = 0;
		bool counting = true;
		for (int j = i + 1; j < SIZE; j++)
		{
			if (arr[i] == arr[j]) count++;
			for (int l = 0; l < i; l++)
			{
				if (arr[i] == arr[l])
				{
					counting = false;
					count = 0;
				}
			}
			if (count == 1 && counting)
			{
				cout << "\t������������� ��������: ";
				counting = false;
				printing = true;
			}
		}
		if (count > 0) cout << arr[i] << " ����������� " << count + 1 << (((count - 1) % 10 < 5) ? " ����.\n" : " ���.\n");
	}
	if (!printing) cout << "������������� �������� �� ����������.\n";
}
