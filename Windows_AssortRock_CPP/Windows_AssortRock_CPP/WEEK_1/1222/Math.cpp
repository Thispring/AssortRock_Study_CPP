// 헤더파일을 이용해 분할 구현
#include "Math.h"

int Math_Global = 1;
static int Math_Global_S = 1;

int ex = 1;

int Mul(int a, int b) { return a * b; }