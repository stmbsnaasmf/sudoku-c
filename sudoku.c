#include <stdio.h>
#include <stdbool.h>

bool isSudokuRowValid(int matrix[9][9], int rowNo);
bool isSudokuColValid(int matrix[9][9], int colNo);
bool isSudokuSubMatrixValid(int matrix[9][9], int matrixNo);
bool isSudokuValid(int matrix[9][9]);
void printSudoku(int matrix[9][9]);

int main()
{
	int matrix[9][9] = { {9, 3, 0, 0, 7, 0, 0, 0, 0},
						 {6, 0, 0, 1, 9, 5, 0, 0, 0},
						 {0, 5, 8, 0, 0, 0, 0, 6, 0},
						 {8, 0, 0, 0, 6, 0, 0, 0, 3},
						 {4, 0, 0, 8, 0, 3, 0, 0, 1},
						 {7, 0, 0, 0, 2, 0, 0, 0, 6},
						 {0, 6, 0, 0, 0, 0, 2, 8, 0},
						 {0, 0, 0, 4, 1, 9, 0, 0, 5},
						 {0, 0, 0, 0, 8, 0, 0, 7, 9} };

//	int matrix[9][9] = { {9, 3, 0, 0, 7, 0, 0, 0, 0},
//						 {6, 0, 0, 1, 9, 5, 0, 0, 0},
//						 {0, 5, 8, 0, 0, 0, 0, 6, 0},
//						 {8, 0, 0, 0, 6, 0, 0, 0, 3},
//						 {4, 0, 0, 8, 0, 3, 0, 0, 1},
//						 {7, 0, 0, 0, 2, 0, 0, 0, 6},
//						 {0, 6, 0, 0, 0, 0, 2, 8, 0},
//						 {0, 0, 0, 4, 1, 9, 7, 0, 5},
//						 {0, 0, 0, 0, 8, 0, 0, 7, 9} };

	printSudoku(matrix);
	isSudokuValid(matrix);

	return 0;
}

//sm = 0, 1, 2, i = 0, 1, 2
//sm = 0, j = 0, 1, 2
//sm = 1, j = 3, 4, 5
//sm = 2, j = 6, 7, 8
//
//sm = 0, 1, 2 : 0
//sm = 3, 4, 5 : 3
//sm = 6, 7, 8 : 6

bool isSudokuSubMatrixValid(int matrix[9][9], int subMatrixNo)
{
	int rowStartNo = 0;

	if (0 == subMatrixNo || 1 == subMatrixNo || 2 == subMatrixNo)
	{
		rowStartNo = 0;
	}
	else if(3 == subMatrixNo || 4 == subMatrixNo || 5 == subMatrixNo)
	{
		rowStartNo = 3;
	}
	else if(6 == subMatrixNo || 7 == subMatrixNo || 8 == subMatrixNo)
	{
		rowStartNo = 6;
	}

	int subMatrixValues[9];
	int index = 0;
		
	for (int i = rowStartNo; i < rowStartNo + 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int number = matrix[i][j + 3 * (subMatrixNo % 3)];
			subMatrixValues[index++] = number;
		}
	}
		
	bool isValid = true;
	
	for (int i = 0; i < 9; i++)
	{
		int number = subMatrixValues[i];
		
		for (int j = 0; j < i; j++)
		{
			if (number != 0 && subMatrixValues[j] == number)
			{
				return false;
			}
		}
	}
	
	return true;
}

bool isSudokuValid(int matrix[9][9])
{
	bool isValid = true;

	for (int i = 0; i < 9; i++)
	{
		if (!isSudokuRowValid(matrix, i))
		{
			printf("Row %d is invalid.\n", i);
			isValid = false;
		}

		if (!isSudokuColValid(matrix, i))
		{
			printf("Col %d is invalid.\n", i);
			isValid = false;
		}

		if (!isSudokuSubMatrixValid(matrix, i))
		{
			printf("submatrix %d is invalid.\n", i);
			isValid = false;
		}
	}

	return isValid;
}

bool isSudokuColValid(int matrix[9][9], int colNo)
{
	for (int i = 0; i < 9; i++)
	{
		int number = matrix[i][colNo];

		for (int j = 0; j < i; j++)
		{
			if (number != 0 && matrix[j][colNo] == number)
			{
				return false;
			}
		}
	}

	return true;
}

bool isSudokuRowValid(int matrix[9][9], int rowNo)
{
	for (int i = 0; i < 9; i++)
	{
		int number = matrix[rowNo][i];

		for (int j = 0; j < i; j++)
		{
			if (number != 0 && matrix[rowNo][j] == number)
			{
				return false;
			}
		}
	}

	return true;
}

void printSudoku(int matrix[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", matrix[i][j]);

			if (2 == j % 3)
			{
				printf("\t");
			}
		}
		printf("\n");

		if (2 == i % 3)
		{
			printf("\n");
		}
	}
}
