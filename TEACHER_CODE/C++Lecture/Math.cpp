#pragma once

static int Global_1 = 0;
//int Global_2 = 0;

int Extern = 0;

int Mul(int a, int b)
{
	Global_1 = 0;
	Extern = 200;

	return a * b;
}
