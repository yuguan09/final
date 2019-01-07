#include <stdio.h>

long double roof(int number)
{
	long i;
	float x, y;
	const float f=1.5F;
		x=number*0.5F;
		y=number;
		i=*(long*)&y;
		i=0x5f3759df-(i>>1);
		y=*(float*)&i;
		y=y*(f-(x*y*y));
		y=y*(f-(x*y*y));
return number*y;
}

int main()
{
	int x;
	long double number;
	printf("number\n");
	scanf("%d",&x);
	
	number=roof(x);
	printf("%20.14Lf\n",number);
}
