#pragma once

#include <iostream>
#include <string>
#include <fstream>
using  namespace std;

namespace nFile {

	class cFile
	{
	public:
		cFile(string nameInputFile, string nameOutputFile);
		~cFile();
		/**
		* @brief  ��������� nameInputFile �� ������
		* @retval Bool ������� ������� ��� ���
		*/
		bool vOpenInputFile();
		/**
		* @brief  ��������� nameOutputFile �� ������
		* @retval Bool ������� ������� ��� ���
		*/
		bool vOpenOutputFile();
		/**
		* @brief  ��������� ����� � ������ ��������� id
		* @note
		* @param  id: ����� id ����
		* @param  num: � ������ �������� ������ �������� �����
		* @retval none
		*/
		void vFindInInputFileAndWrite(string id, int num);

	private:
		fstream inputFile;
		fstream outputFile;
		string nameInputFile;
		string nameOutputFile;

	};

}