
#include "CalcAverage.h"
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	CalculateAverage temp("E:/LTH/Thesis_supplements/ObjectOrientedProgramming/OOP_EX1/OOP_EX1/GPACalc.txt");
	temp.printList();
	temp.getStuGPA();
	temp.sortStuGPA();
	cout << "Number of students in the calss: " << temp.studentNum << endl;
	cout << "---------------------------------------------------------" << endl;
	temp.getClassGPA();
	char st;
	cin >> st;
	return 0;
}
