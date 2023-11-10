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
		* @brief  Открывает nameInputFile на чтение
		* @retval Bool Удалось открыть или нет
		*/
		bool vOpenInputFile();
		/**
		* @brief  Открывает nameOutputFile на чтение
		* @retval Bool Удалось открыть или нет
		*/
		bool vOpenOutputFile();
		/**
		* @brief  выполняет поиск и запись найденных id
		* @note
		* @param  id: какой id ищем
		* @param  num: с какого элемента строки начинать поиск
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