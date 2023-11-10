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
		cout << "Загрузка файла " << NAME_INPUT_FILE << endl;
	else {
		cout << "!!! Загрузка файла " << NAME_INPUT_FILE << " не удалась" << endl;
		system("pause");
		return;
	}
	if (cFile.vOpenOutputFile())
		cout << "Запись в файл " << NAME_OUTPUT_FILE << endl;
	else {
		cout << "Загрузка файла " << NAME_OUTPUT_FILE << " не удалась" << endl;
		system("pause");
		return;
	}
	cFile.vFindInInputFileAndWrite("\"771\"", 15);//ищем с 15 элемента

	cout << endl;
	cout << "Создание файла " << NAME_OUTPUT_FILE << " завершена" << endl;

	system("pause");
}