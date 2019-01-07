#include <stdio.h>
#include <math.h>
#include <time.h>

#define upperlimits 0
#define lowerlimits 4
#define PI 3.14159265358979


long double roof(int number)
{
	long i;
	float x, y;
	const long double f=1.5F;
		x=number*0.5F;
		y=number;
		i=*(long*)&y;
		i=0x5f3759df-(i>>1);
		y=*(float*)&i;
		y=y*(f-(x*y*y));
		y=y*(f-(x*y*y));
	return (number*y);
}

long double calc_pi(long double x,long double dx)
{
	long double pi;
	pi=(x*2+upperlimits+lowerlimits)*dx*(0.5);
	return(pi);
}

int main()
{
	clock_t start,end;

	int i;	
	int n=1;
	int n2;
	int i2;
	int ni;
	long double result;
	long double sumtem=0;
	long double q;
	long double pi_new;
	long double ERR=1;
	long double dx=1;
	long double tem;
	long double sum=0;

	start=clock();
	while(ERR>1.0e-13){
		n=n*2;
		dx=dx*0.5;
		n2=n*n;
			for(i=1;i<n;i=i+2){
				i2=i*i;
				ni=n2-i2;
				result=(n/4)*roof(ni);
				sumtem+=result;
			}
		sum+=sumtem;
		pi_new=calc_pi(sum,dx);

		ERR=fabs(PI-pi_new);
		printf("PI=%20.14Lf N=%10d\n",pi_new,n);
	}
	end=clock();
	printf("PI=%20.14Lf N=%10d\n",pi_new,n);
	printf("processing time %lf[sec]\n",(double)(end-start)/CLOCKS_PER_SEC);
}
