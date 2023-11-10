#include <iostream>
#include <string>;
#include "file.h"
using  namespace std;
using  namespace nFile;

#define NAME_INPUT_FILE "log.CSV"
#define NAME_OUTPUT_FILE "resultLog.CSV"

void main()
{
	setlocale(LC_ALL, "Rus");
	cFile cFile(NAME_INPUT_FILE, NAME_OUTPUT_FILE);
	if (cFile.vOpenInputFile())
		cout << "�������� ����� " << NAME_INPUT_FILE << endl;
	else {
		cout << "!!! �������� ����� " << NAME_INPUT_FILE << " �� �������" << endl;
		system("pause");
		return;
	}
	if (cFile.vOpenOutputFile())
		cout << "������ � ���� " << NAME_OUTPUT_FILE << endl;
	else {
		cout << "�������� ����� " << NAME_OUTPUT_FILE << " �� �������" << endl;
		system("pause");
		return;
	}
	cFile.vFindInInputFileAndWrite("\"771\"", 15);//���� � 15 ��������

	cout << endl;
	cout << "�������� ����� " << NAME_OUTPUT_FILE << " ���������" << endl;

	system("pause");
}