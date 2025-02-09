// SAOD_SECTION_1_3_TASK_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <regex>
#include <windows.h>

using namespace std;

const int ARRAY_SIZE = 10;

int arraySize = 0;



int validIntegerInput(string message) {
	string input;
	regex valid("[1-9][0-9]*");
	do {
		cout << message;
		cin >> input;
	} while (!regex_match(input, valid));
	return stoi(input);
}


struct List {
	string data;
} list[ARRAY_SIZE];

void initList() {
	for (int i = 0; i < ARRAY_SIZE; i++) list[i].data = "";
	arraySize = 0;
}

bool isFull() {
	return arraySize == ARRAY_SIZE;
}

bool isEmpty() {
	return arraySize == 0;
}

void push(string data) {
	if (isFull()) {
		cout << "Список переполнен - Добавление невозможно" << endl;
		return;
	}
	if (isEmpty()) {
		cout << "Список пуст - Добавлено в первую ячейку" << endl;
		list[0].data = data;
		arraySize++;
		return;
	}

	bool isLast = true;
	for (int i = 0; i < arraySize; i++) {
		if (data < list[0].data) {
			if (i == arraySize) list[i].data = data;
			else if (0 <= i < arraySize) {
				for (int j = arraySize; j > i; j--)
					list[j].data = list[j - 1].data;
				list[i].data = data;
			}
			isLast = false;
			cout << "Добавлено в ячейку №" << i + 1 << endl;
			break;
		}
	}

	if (isLast) {
		list[arraySize].data = data;
		cout << "Добавлено в последнюю ячейку" << endl;
	}
	arraySize++;
}

void printList() {
	if (isEmpty()) {
		cout << "Список пуст" << endl;
		return;
	}
	for (int i = 0; i < arraySize; i++) {
		cout << "№" << i + 1 << " - " << list[i].data << endl;
	}
}

void pop(string value) {
	if (isEmpty()) {
		cout << "Список пуст - Удаление невозможно" << endl;
		return;
	}
	bool isFound = false;
	for (int i = 0; i < arraySize; i++) {
		if (list[i].data == value) {
			isFound = true;
			list[i].data = "";
			for (int j = i; j < arraySize; j++){
				list[j].data = list[j + 1].data;
				list[j + 1].data = "";
			}
			cout << "Элемент №" << i << " удален. Новый разсер списка: " << --arraySize << endl;
		}
	}
}

void find(string value) {
	if (isEmpty()) {
		cout << "Список пуст - Поиск невозможен" << endl;
		return;
	}
	bool isFound = false;
	for (int i = 0; i < arraySize; i++) {
		if (list[i].data == value) {
			isFound = true;
			cout << "Элемент найден в ячейке №" << i + 1 << endl;
		}
	}
	if (!isFound) cout << "Элемент не найден" << endl;
}

void sort() {
	if (isEmpty()) {
		cout << "Список пуст - Сортировка невозможна" << endl;
		return;
	}
	for (int i = 0; i < arraySize; i++) {
		for (int j = 0; j < arraySize - 1; j++) {
			if (list[j].data > list[j + 1].data) {
				string temp = list[j].data;
				list[j].data = list[j + 1].data;
				list[j + 1].data = temp;
			}
		}
	}
	cout << "Список отсортирован" << endl;
}

void clear() {
	for (int i = 0; i < arraySize; i++) list[i].data = "";
	arraySize = 0;
	cout << "Список очищен" << endl;
}
void menu(bool& exit) {
	cout << "Меню:" << endl;
	cout << "1. Вывод текущего состояния списка на экран" << endl;;
	cout << "2. Проверка пустоты списка" << endl;;
	cout << "3. Проверка полноты списка" << endl;;
	cout << "4. Добавить элемент в список" << endl;;
	cout << "5. Удалить элемент из списка" << endl;;
	cout << "6. Поиск элемента с заданной информационной частью" << endl;;
	cout << "7. Отсортировать список" << endl;;
	cout << "8. Очистить список" << endl;;
	cout << "0. Завершить работу программы" << endl;;

	int choice = validIntegerInput("Выберите действие: ");
	string value;
	switch (choice) {
	case 1:
		printList();
		break;
	case 2:
		cout << "Список " << (isEmpty() ? "пуст" : "не пуст") << endl;
		break;

	case 3:
		cout << "Список " << (isFull() ? "полон" : "не полон") << endl;
		break;

	case 4:
		cout << "Введите значение: ";
		cin >> value;
		push(value);
		break;

	case 5:
		cout << "Введите значение: ";
		cin >> value;
		pop(value);
		break;

	case 6:
		cout << "Введите значение: ";
		cin >> value;
		find(value);
		break;

	case 7:
		sort();
		break;
	case 8:
		clear();
		break;
	case 0:
		exit = true;
		break;
	}

}


int main() {
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	initList();
	bool exit = false;
	while (!exit) {
		menu(exit);
	}

}