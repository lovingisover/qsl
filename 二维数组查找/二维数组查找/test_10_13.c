#define _CRT_SECURE_NO_WARNINGS 1

bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
	if (matrix == NULL || matrixSize == 0 || *matrixColSize == 0)
	{
		return false;
	}
	for (int i = 0, j = *matrixColSize - 1; i < matrixSize&&j >= 0;)
	{
		if (target < matrix[i][j])
			j--;
		else if (target > matrix[i][j])
			i++;
		else
			return true;
	}
	return false;
}