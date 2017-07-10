
#include "string.h"
#include <iostream>
#include <cstring>
#include <fstream>

class CalculateAverage {
private:
	int studentID;
	std::string studentName;
public:
	static int studentNum;
	CalculateAverage(std::string filepath);
	void setInfo(int inpID, std::string inpName, double inpGrade1, double inpGrade2, double inpGrade3);
	void printList();
	void getStuGPA();
	void sortStuGPA();
	double getClassGPA();
	double GPAarray[50];
	double list[50][5];
};