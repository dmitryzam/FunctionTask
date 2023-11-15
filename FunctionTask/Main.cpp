#include<iostream>
#include<ctime>
#include<cstdlib>
#include<algorithm>

// Модуль 5. Занятие 39. Прорешиваем функции + прототипы.
void typeof(int num)    { std::cout << "INT\n"; }
void typeof(double num) { std::cout << "DOUBLE\n"; }
void typeof(char num)   { std::cout << "CHAR\n"; }
int sum_AB(int A, int B); // Прототип функции sum_AB

// Заполнение массива случайными числами:
template<typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}
// Вывод массива в консоь:
template<typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}
// 
template<typename T>
void middle_sort(T arr[], const int length);

template<typename T>
void move_arr(T arr[], const int length, int steps);



int main() {
	setlocale(LC_ALL, "RU");
	int n, m;
	// Задача 1. Тип данных числа.
	/*
	std::cout << "Задача 1.\n";
	std::cout << "7 - "; typeof(7);
	std::cout << "0.15 - "; typeof(0.15);
	std::cout << "'E' - "; typeof('E');
	std::cout << std::endl;
	
	// Задача 2. Рекурсивная сумма диапазона.
	std::cout << "Задача 2.\nВведите начало диапазона -> ";
	std::cin >> n;
	std::cout << "Введите конец диапазона -> ";
	std::cin >> m;
	std::cout << "Сумма чисел от  " << n << " до " << m << " = " << sum_AB(n, m) << "\n\n";
	
	// Задача 3. Cортировка середины. Пузырьковая сортировка
	std::cout << "Задача 3.\nВыводится изначальный массив:\n";
	const int size3 = 10;
	int arr3[size3]{};
	fill_arr(arr3, size3, -20, 21);
	print_arr(arr3, size3);

	middle_sort(arr3, size3);
	std::cout << "Итоговый массив:\n";
	print_arr(arr3, size3);
	*/
	// Задача 4. Циклический сдвиг
	std::cout << "Задача 4\nИзначальный массив:\n";
	const int size4 = 5;
	int arr4[size4]{ 1, 2, 3, 4, 5 };
	print_arr(arr4, size4);
	std::cout << "Введите кол-во сдвигов -> ";
	std::cin >> n;
	move_arr(arr4, size4, n);
	std::cout << "Итоговый массив:\n";
	print_arr(arr4, size4);

	return 0;
}
// Реализация функции sum_AB:
int sum_AB(int A, int B) {
	if (A > B)
		std::swap(A, B);
	if (A == B)
		return A;
	return sum_AB(A, B - 1) + B;
}
// Реализация функции middle_sort:
template<typename T>
void middle_sort(T arr[], const int length) {
	int first_neg = -1, last_neg = -1;
	for (int i = 0; i < length; i++)
		if (arr[i] < 0) {
			first_neg = i;
			break;
		}
	for (int i = length-1; i >=0; i--)
		if (arr[i] < 0) {
			last_neg = i;
			break;
		}
	/*
	for (int i = last_neg - 1; i > first_neg + 1; i--)
		for (int j = first_neg + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
	*/
	// Быстрая сортировка
	if (first_neg != -1 && first_neg != last_neg)
		std::sort(arr + first_neg + 1, arr + last_neg);
}

template<typename T>
void move_arr(T arr[], const int length, int steps) {
	if (steps < 0)
		for (int j = 0; j < -steps; j++)
			for (int i = 0; i < length - 1; i++)
			std::swap(arr[i], arr[i + 1]);
		else
			for (int j = 0; j < steps; j++)
				for (int i = length - 2; i >= 0; i--)
					std::swap(arr[i], arr[i + 1]);
}

