#include <stdio.h>
#include <math.h>
#include <time.h>

#define upperlimits 0
#define lowerlimits 4
#define PI 3.14159265358979

long double calu_tem(int n,long double dx)
{
	int i;
	long double q;
	long double result;
	long double sum=0;

	for(i=1;i<n;i=i+2){
		q=i*dx;
		result=4*sqrt(1-pow(q,2));
		sum+=result;
	}
	return(sum);
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
	
	int n=1;
	long double pi_new;
	long double ERR=1;
	long double dx=1;
	long double tem;
	long double sum=0;

	start=clock();
	while(ERR>1.0e-13){
		n=n*2;
		dx=dx*0.5;

		tem=calu_tem(n,dx);
		sum+=tem;
		pi_new=calc_pi(sum,dx);

		ERR=fabs(PI-pi_new);
		printf("PI=%20.14Lf N=%10d\n",pi_new,n);
	}
	end=clock();
	printf("PI=%20.14Lf N=%10d\n",pi_new,n);
	printf("processing time %lf[sec]\n",(double)(end-start)/CLOCKS_PER_SEC);
}


















