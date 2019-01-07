#include <stdio.h>
#include <math.h>
#include <time.h>

#define upperlimits 0
#define lowerlimits 4
#define PI 3.14159265358979

long double calu_tem(int n,long double dx)
{
	int i;
	long double y;
	long double x=n;
	long double z;
	long double result,result1,result2,result3,result4,result5,result6,result7;
	long double sum=0;
	long double q=0,q1,q2,q3,q4,q5,q6,q7;

	z=4/x;
	if(n<16){

		for(i=1;i<n;i+=2){

			y=i;

			q=x*x-y*y;
			result=z*sqrt(q);

			sum+=result;
		}
			return(sum);
		}else{
		for(i=1;i<n;i+=16){
			y=i;
			q=x*x-y*y;
			result=z*sqrt(q);

			q1=x*x-(y+2)*(y+2);
			result1=z*sqrt(q1);

			q2=x*x-(y+4)*(y+4);
			result2=z*sqrt(q2);

			q3=x*x-(y+6)*(y+6);
			result3=z*sqrt(q3);

			q4=x*x-(y+8)*(y+8);
			result4=z*sqrt(q4);

			q5=x*x-(y+10)*(y+10);
			result5=z*sqrt(q5);

			q6=x*x-(y+12)*(y+12);
			result6=z*sqrt(q6);

			q7=x*x-(y+14)*(y+14);
			result7=z*sqrt(q7);

			sum+=(result+result1+result2+result3+result4+result5+result6+result7);
		}
			return(sum);
		}
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
		pi_new=(sum*2+upperlimits+lowerlimits)*dx*(0.5);

		ERR=fabs(PI-pi_new);
		printf("PI=%20.14Lf N=%10d\n",pi_new,n);
	}
	end=clock();

	printf("PI=%20.14Lf N=%10d\n",pi_new,n);
	printf("processing time %lf[sec]\n",(double)(end-start)/CLOCKS_PER_SEC);
}

