#include<iostream>
#include<fstream>
#include<string>
#include<limits>
#include<algorithm>

using namespace std;

int main() {

	setlocale(LC_ALL, "RU");

	char ch;
	int numberOfLetters = 0; // ����������� ����
	string letters;
	int countCombinationFind = 0; // ���������� ��������� ����
	int choice;
	char letter;//����� ������� ����� �����
	string combinationOfLetters; // ��������� ���� ������� ����� �����

	cout << "������� ����� ������� ������ �����: ";
	cin >> letter;

	cout << "������� ��������� ���� ������� ������ �����: ";
	cin >> combinationOfLetters;

	fstream file("testpr.txt");

	if (!file.is_open()) {
		cout << "������ �������� �����!!!";
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

	cout << "���������� ����: " << numberOfLetters << endl;
	cout << "���������� ��������� ����: " << countCombinationFind << endl;
}