#include "string.h"
#include "CalcAverage.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
int CalculateAverage::studentNum = 0;
CalculateAverage::CalculateAverage(string filepath){
	cout << "********----- Welcome to GPA calcualting program -----********" << '\n'<<endl;
	ifstream myfile(filepath);
	int id;
	double phGrade, mathGrade, chGrade;
	string name;

	if (myfile.is_open())
	{
		while (myfile >> id >> name >> mathGrade >> phGrade >> chGrade)
		{
			setInfo(id, name, mathGrade, phGrade, chGrade);
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}

void CalculateAverage::setInfo( int inpID, string inpName, double inpGrade1, double inpGrade2, double inpGrade3){
	list[studentNum][0] = inpID;
	studentName = inpName;
	list[studentNum][1] = inpGrade1;
	list[studentNum][2] = inpGrade2;
	list[studentNum][3] = inpGrade3;
	studentNum++;
}

void CalculateAverage::printList(){
	cout << "Student Grades with ID:" <<'\n'<< endl;
	for (int j = 0; j < studentNum; j++){

		cout << "ID: "<< list[j][0] << " => \tMath= " << list[j][1]<< " \t Physics= " << list[j][2] << "\tChemistry= " << list[j][3] << '\n';
	}
	cout << "---------------------------------------------------------" << endl;
}

void CalculateAverage::getStuGPA(){
	//cout << "Student GPAs with ID:" << '\n'<<endl;
	for (int j = 0; j < studentNum; j++){
		list[j][4] = (list[j][1] + list[j][2] + list[j][3]) / 3;
		//cout <<"ID: " << list[j][0] << " => \tMath= " << list[j][1]
		//	<< " \t Physics= " << list[j][2] << "\tChemistry= " << list[j][3] << "\tGPA= " << list[j][4] << '\n';
	}
	//cout << "---------------------------------------------------------" << endl;
}

void CalculateAverage::sortStuGPA(){
	cout << "Student GPAs with ID: (Highest -> Lowest)" << '\n' << endl;
	double temp[5];
	for (int i = 0; i <= studentNum; i++){
		for (int j = i + 1; j <= studentNum; j++){
			if (list[i][5-1]<list[j][5-1])
			{
				for (int k = 0; k < 5; k++){
					temp[k] = list[j][k];
					list[j][k] = list[i][k];
					list[i][k] = temp[k];
				}
			}
		}
	}

	for (int h = 0; h < studentNum; h++)
	{
		cout << "ID: " << list[h][0] << " => \tMath= " << list[h][1]
			<< " \t Physics= " << list[h][2] << "\tChemistry= " << list[h][3] << "\tGPA= " << list[h][4] << '\n';
	}
	cout << "---------------------------------------------------------" << endl;
}

double CalculateAverage::getClassGPA(){
	double clGPA, sum = 0;
	for (int i = 0; i < studentNum; i++){
		sum += list[i][4];
	}
	clGPA = sum / studentNum;
	cout << "class GPA = " << clGPA << endl;
	return clGPA;
}