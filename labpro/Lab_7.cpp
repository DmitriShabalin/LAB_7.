#include<iostream>
#include<fstream>
#include<string>
#include<limits>
#include<algorithm>

using namespace std;

int main() {

	setlocale(LC_ALL, "RU");

	char ch;
	int numberOfLetters = 0; // колличество букв
	string letters;
	int countCombinationFind = 0; // количество сочетаний букв
	int choice;
	char letter;//буква которую нужно найти
	string combinationOfLetters; // сочетание букв которое нужно найти

	cout << "Введите букву которую хотите найти: ";
	cin >> letter;

	cout << "Введите сочетание букв которое хотите найти: ";
	cin >> combinationOfLetters;

	fstream file("testpr.txt");

	if (!file.is_open()) {
		cout << "Ошибка открытия файла!!!";
	}

	if (file.is_open()) {
		while (file.get(ch)) {
			if (letter == ch) {
				++numberOfLetters;
			}
		}
		file.close();
	}

	if (file.is_open()) {
		while (getline(file, letters)) {
			size_t pos = 0;

			while ((pos = letters.find(combinationOfLetters, pos)) != (string::npos)) {
				++countCombinationFind;
				pos += combinationOfLetters.length();
			}
		}
		file.close();
	}

	cout << "Количество букв: " << numberOfLetters << endl;
	cout << "Количество сочетаний букв: " << countCombinationFind << endl;
}