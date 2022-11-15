//HOME WORK
#include<iostream>
#include<conio.h>
using namespace std;

//TODO:
//В Solution Functions добавить проект Arrays, и в нем реализовать следующие функции :
void FillRand(int arr[], const int SIZE, int minRand = 0, int maxRand = 100);	//? ? ? FillRand(? ? ? );	//заполняет массив случайными числами в заданном диапазоне 
//																				//(диапазон по умолчанию от 0 до 100)
void Print(int arr[], const int SIZE);		//? ? ? Print(? ? ? );		//выводит массив на экран
int Sum(int arr[], const int SIZE);			//? ? ? Sum(? ? ? );		//возвращает сумму элементов массива
double Avg(int arr[], const int SIZE);		//? ? ? Avg(? ? ? );		//возвращает среднее-арифметическое элементов массива
int minValueIn(int arr[], const int SIZE);	//? ? ? minValueIn(? ? ? );//возвращает минимальное значение из массива
int maxValueIn(int arr[], const int SIZE);	//? ? ? maxValueIn(? ? ? );//возвращает максимальное значение из массива

void shiftLeft(int arr[], const int SIZE);	//? ? ? shiftLeft(? ? ? );	//выполняет циклический сдвиг массива на заданное число элементов влево
void shiftRight(int arr[], const int SIZE);	//? ? ? shiftRight(? ? ? );//выполняет циклический сдвиг массива на заданное число элементов вправо
void Sort(int arr[], const int SIZE);		//? ? ? Sort(? ? ? );		//выполняет сортировку массива в порядке возрастания
void UniqueRand(int arr[], const int SIZE);	//? ? ? UniqueRand(? ? ? );//заполняет массив уникальными случайными числами в заданном диапазоне
void Search(int arr[], const int SIZE);		//? ? ? Search(? ? ? );	//находит в массиве повторяюшиеся значения, выводит их на экран,
//											//и выводит на экран количество повторений

void main()
{
	setlocale(LC_ALL, "Russian");

	cout << "\t\tHomeWork FUNCTIONS\n";
	cout << "\t\t***Домашнее задание \"Функции\"***\n\n";
	const int SIZE = 10;
	int arr[SIZE] = {};
	int uniqArr[SIZE] = {};
	//int arrCount[SIZE] = {};
	FillRand(arr, SIZE);			//заполняет массив случайными числами в заданном диапазоне 
	Print(arr, SIZE);				//выводит массив на экран
	cout << "\tСумма всех элементов массива равна: " << Sum(arr, SIZE) << endl;					//возвращает сумму элементов массива
	cout << "\tСредне-арифметическое всех элементов массива равно: " << Avg(arr, SIZE) << endl; //возвращает среднее-арифметическое элементов массива
	cout << "\tМинимальное значение массива равно: " << minValueIn(arr, SIZE) << endl;			//возвращает минимальное значение из массива
	cout << "\tМаксимальное значение массива равно: " << maxValueIn(arr, SIZE) << endl << endl;			//возвращает максимальное значение из массива
	shiftLeft(arr, SIZE);			//выполняет циклический сдвиг массива на заданное число элементов влево
	Print(arr, SIZE);
	shiftRight(arr, SIZE);			//выполняет циклический сдвиг массива на заданное число элементов вправо
	Print(arr, SIZE);
	cout << "\t\tСортировка массива.\n";
	Sort(arr, SIZE);				//выполняет сортировку массива в порядке возрастания
	Print(arr, SIZE);
	UniqueRand(uniqArr, SIZE);			//заполняет массив уникальными случайными числами в заданном диапазоне
	cout << "\n\tМассив уникальных значений:\n";
	Print(uniqArr, SIZE);
	cout << "\n\tПоиск повторяющихся значений из массива arr[]:\n";
	Print(arr, SIZE);
	Search(arr, SIZE);				//находит в массиве повторяюшиеся значения, выводит их на экран, и выводит на экран количество повторений
}

void FillRand(int arr[], const int SIZE,  int minRand, int maxRand)	//заполняет массив случайными числами в заданном диапазоне (диапазон по умолчанию от 0 до 100)
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

void Print(int arr[], const int SIZE)				//выводит массив на экран
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << '\t' << arr[i];
	}
	cout << endl;
}

int Sum(int arr[], const int SIZE)					//возвращает сумму элементов массива
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		sum += arr[i];
	}
	return sum;
}

double Avg(int arr[], const int SIZE)				//возвращает среднее-арифметическое элементов массива
{
	return (double)Sum(arr, SIZE) / SIZE;
}

int minValueIn(int arr[], const int SIZE)			//возвращает минимальное значение из массива
{
	int min = arr[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (arr[i] < min) min = arr[i];
	}
	return min;
}

int maxValueIn(int arr[], const int SIZE)			//возвращает максимальное значение из массива
{
	int max = arr[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

void shiftLeft(int arr[], const int SIZE)			//выполняет циклический сдвиг массива на заданное число элементов влево
{
	int shift;
	cout << "Введите количество ячеек, на сколько нужно сдвинуть массив влево: "; cin >> shift;
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

void shiftRight(int arr[], const int SIZE)			//выполняет циклический сдвиг массива на заданное число элементов вправо
{
	int shift;
	cout << "Введите количество ячеек, на сколько нужно сдвинуть массив вправо: "; cin >> shift;
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

void Sort(int arr[], const int SIZE)				//выполняет сортировку массива в порядке возрастания
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

void UniqueRand(int arr[], const int SIZE)			//заполняет массив уникальными случайными числами в заданном диапазоне
{
	int limit;
	cout << "Размер массива " << SIZE << " ячеек. Введите ограничение максимального значения массива : ";
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

void Search(int arr[], const int SIZE)				//находит в массиве повторяюшиеся значения, выводит их на экран, и выводит на экран количество повторений
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
				cout << "\tПовторяющееся значение: ";
				counting = false;
				printing = true;
			}
		}
		if (count > 0) cout << arr[i] << " повторяется " << count + 1 << (((count - 1) % 10 < 5) ? " раза.\n" : " раз.\n");
	}
	if (!printing) cout << "Повторяющихся значений не обнаружено.\n";
}
