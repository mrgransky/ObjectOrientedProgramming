#include <iostream>
#include <stdlib.h>
using namespace std;

const int row = 9;
const int col = 5;

int main(int argc, char *argv[])
{
	double num[row][col] = { { 12, 4, 3, 2, 2.8 }, 
							 { 19, 3, 2, 4, 3.6 }, 
						     { 11, 5, 4, 3, 4.3 }, 
							 { 13, 2, 4, 5, 3.4 }, 
							 { 27, 3, 3, 4, 3.8 }, 
							 { 18, 2, 3, 2, 2.3 },
							 { 22, 4, 5, 5, 4.6 },
							 { 15, 2, 2, 3, 2.35},
							 { 33, 4, 4, 3, 4.1 },
					   };
	double temp[col];
	for (int i = 0; i <= row; i++){
		for (int j = i + 1; j <= row; j++){
			if (num[i][col-1]<num[j][col-1])
			{
				for (int k = 0; k < col; k++){
					temp[k] = num[j][k];
					num[j][k] = num[i][k];
					num[i][k] = temp[k];
				}
			}
		}
	}

	for (int i = 0; i < row; i++)
	{
		for ( int j = 0; j < col; j++)
		{
			cout << "num = " << num[i][j] << endl;
		}
		cout << "\n" << endl;
	}
	char ch;
	cin >> ch;
	return 0;
}

