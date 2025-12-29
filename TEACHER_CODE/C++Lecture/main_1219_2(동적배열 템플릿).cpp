#include "Arr.h"



int main()
{
	Arr<int> array;

	array.push_back(10);
	array.push_back(20);
	array.push_back(30);

	int a = 0;
	a = array[0];
	a = array[1];
	a = array[2];


	Arr<float> arrayFloat;

	arrayFloat.push_back(1.1f);
	arrayFloat.push_back(2.2f);
	arrayFloat.push_back(3.3f);

	float f = 0;
	f = arrayFloat[0];
	f = arrayFloat[1];
	f = arrayFloat[2];




	return 0;
}