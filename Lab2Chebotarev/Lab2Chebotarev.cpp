#include <iostream>
#include "Windows.h"
#include <fstream>
#include <string>

void completeFirst()
{
	std::ifstream inFile;

	inFile.open("first.txt");

	if (inFile)
	{
		double sum = 0;
		double curNum;

		while (!inFile.eof())
		{
			inFile >> curNum;
			sum += curNum;
		}

		inFile.close();

		std::cout << sum;
	}
}

void completeSecond()
{
	std::ifstream inFile;

	inFile.open("first.txt");

	if (!inFile)
	{
		return;
	}

	int curNum;

	while (!inFile.eof())
	{
		int num;
		int digitSum = 0;

		inFile >> num;
		curNum = num;

		while (num > 0)
		{
			digitSum += num % 10;
			num /= 10;
		}

		std::cout << curNum << "=" << digitSum << std::endl;
	}

	inFile.close();
}

void completeThird()
{
	std::ifstream inFile;

	inFile.open("third.txt");

	if (!inFile)
	{
		std::cout << "file opening failure" << std::endl;
		return;
	}

	int lectureCount = 0;
	int practiceCount = 0;
	int labCount = 0;

	std::string currentLine;

	while (!inFile.eof())
	{
		std::getline(inFile, currentLine);
		
		if (currentLine.find("(лекц.)") != std::string::npos)
		{
			lectureCount++;
		}

		if (currentLine.find("(практ.)") != std::string::npos)
		{
			practiceCount++;
		}

		if (currentLine.find("(лаб.)") != std::string::npos)
		{
			labCount++;
		}
	}

	inFile.close();

	std::cout << "Лекций: " << lectureCount << std::endl;
	std::cout << "Практических: " << practiceCount << std::endl;
	std::cout << "Лабораторных: " << labCount << std::endl;
}

void completeFourth()
{
	std::ifstream inFile;
	inFile.open("fourth.txt");
	
	if (!inFile)
	{
		return;
	}

	std::string currentLine;
	std::string currentWord;
	int symbolCount = 0;
	int lineCount = 0;
	int wordCount = 0;
	char c;

	while (!inFile.eof())
	{
		inFile.get(c);
		symbolCount++;
		//std::cout << c;
	}

	inFile.clear();
	inFile.seekg(0, std::ios::beg);

	std::cout << inFile.tellg() << std::endl;
	while (!inFile.eof())
	{
		std::getline(inFile, currentLine);
		lineCount++;
		//std::cout << c;
	}

	inFile.clear();
	inFile.seekg(0, std::ios_base::beg);

	while (!inFile.eof())
	{
		inFile >> currentWord;
		wordCount++;
		std::cout << currentWord << std::endl;
	}

	std::cout << "symbolCount: " << symbolCount << " wordCount: " << wordCount << " lineCount: " << lineCount << std::endl;

	inFile.close();
}

void completeFifth()
{
	
}

void completeIndividualTask4()
{
	const char* s = "new line\n";

	std::ifstream iFile;
	iFile.open("individual.txt");

	if (!iFile)
	{
		std::cout << "couldn`t open file" << std::endl;
		return;
	}
	
	std::string oldLines;

	while (!iFile.eof())
	{
		std::string curLine;
		std::getline(iFile, curLine);
		oldLines += curLine + '\n';
	}

	//std::cout << oldLines << std::endl;

	iFile.close();
	iFile.clear();

	std::ofstream oFile;
	oFile.open("individual.txt", std::ios_base::trunc);

	if (!oFile)
	{
		std::cout << "couldn`t open file" << std::endl;
		return;
	}

	oFile.write(s, sizeof(s));
	//oFile.write((char*)&oldLines, sizeof(oldLines));
	oFile << oldLines;

	oFile.close();
}

int main()
{
	//completeFirst();
	//completeSecond();
	//completeThird();
	//completeFourth();
	//completeFifth();
	//completeIndividualTask4();
}

