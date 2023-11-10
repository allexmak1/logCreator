#include "file.h"
using  namespace nFile;

cFile::cFile(string nameInputFile, string nameOutputFile)
{
	this->nameInputFile = nameInputFile;
	this->nameOutputFile = nameOutputFile;
}

cFile::~cFile()
{
	inputFile.close();
	outputFile.close();
}

bool cFile::vOpenInputFile() {
	inputFile.open(nameInputFile, fstream::in);
	if (inputFile.is_open())
		return true;
	else
		return false;
}

bool cFile::vOpenOutputFile() {

	outputFile.open(nameOutputFile, ios::trunc | ios::in | ios::out);//trunc - затираем
	//outputFile.open(nameOutputFile, fstream::in | fstream::out | fstream::app);

	if (outputFile.is_open())
		return true;
	else
		return false;
}

void cFile::vFindInInputFileAndWrite(string id, int num) {
	string textLine;
	bool isStart = false;
	bool isEnd = false;
	int zeroAdc = 0;
	float energy = 0;
	string rezult = " ";
	string strAdcHexHight, strAdcHexLow;
	int pos, adc, prBar = 0;;
	// выборка по строкам
	while (!inputFile.eof()) {
		getline(inputFile, textLine);
		//парсим
		if (textLine.find("\"103C940\"", num) != string::npos) {
			isStart = true;
			//outputFile << textLine << "\n";
			//todo убрать повторы
		}
		else if (textLine.find("\"904201F\"", num) != string::npos) {
			if (isStart)isEnd = true;
			isStart = false;
			//outputFile << textLine << "\n";
		}
		else if (textLine.find("\"904A01F\"", num) != string::npos) {
			pos = textLine.find("\";\"", 27);
			strAdcHexLow.assign(textLine, pos + 10, 2);
			strAdcHexHight.assign(textLine, pos + 13, 2);
			//energy = (stoul(("0x" + strAdcHexHight + strAdcHexLow), nullptr, 16)) / 100;
			energy = (stoul(("0x" + strAdcHexHight + strAdcHexLow), nullptr, 16));

		}
		else if (textLine.find("\"888\"", num) != string::npos) {
			pos = textLine.find("\";\"", 27);
			strAdcHexLow.assign(textLine, pos + 3, 2);
			strAdcHexHight.assign(textLine, pos + 6, 2);
			zeroAdc = stoul(("0x" + strAdcHexHight + strAdcHexLow), nullptr, 16);//to int

			rezult.assign(textLine, pos + 21, 2);

		}
		else if (isStart) {
			if (textLine.find(id, num) != string::npos) {
				//так быстрее чем erase		
				pos = textLine.find("\";\"", 27);
				strAdcHexLow.assign(textLine, pos + 3, 2);
				strAdcHexHight.assign(textLine, pos + 6, 2);
				adc = stoul(("0x" + strAdcHexHight + strAdcHexLow), nullptr, 16);
				outputFile << textLine << ";\"ADC: \";\"" << adc << "\"\n";
			}
		}
		else if (isEnd) {
			isEnd = false;

			outputFile << "\"ZERO_ADC: " << zeroAdc << "\"\n";
			outputFile << "\"ENERGY: " << energy << "\"\n";

			switch (stoi(rezult))
			{
			case 0:
				outputFile << "\"REZULT: 0 – Нет закусывания.\"\n";
				break;
			case 1:
				outputFile << "\"REZULT: 1 – Есть закусывание. Ударное центрирование снаряда. (Udar > 1)\"\n";
				break;
			case 2:
				outputFile << "\"REZULT: 2 – Есть закусывание. Ударное центрирование снаряда. (Udar > 0)\"\n";
				break;
			case 3:
				outputFile << "\"REZULT: 3 – Есть закусывание.   (Udar <= 0)\"\n";
				break;
			case 4:
				outputFile << "\"REZULT: 4 – Нет закусывания! Удар в     каморе! Неисправность досылателя! (Udar > 0)\"\n";
				break;
			case 5:
				outputFile << "\"REZULT: 5 – Превышено время досылки! Нет закусывания! Ударов требуемой энергетики не выявлено!   Неисправность досылателя!\"\n";
				break;
			default:
				outputFile << "\"REZULT: error\"\n";
				break;
			}
		}
		//progress bar
		if (++prBar > 20000) {
			prBar = 0;
			cout << ".";
		}
	}

}
