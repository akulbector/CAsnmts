#include <stdio.h>




int main() {
	//Basically a boolean that will indicate whether the loop should run
	char running = '1';
	//Since initial value of pi is set to 4, the initial value of
	//n will need to be 2 since the first term is already used
	double pi=4.0;
	long long n=2;
	//epsilon precision value
	long double eps;


	//Take input
	printf("Precision: ");
	scanf("%Lf", &eps);

	while(running=='1') {
		
		//Calculate denominator for current term
		long long denom = n*2-1;

		//Uses denominator to figure out current and next term
		double this_term = 4.0/denom;
		double next_term = 4.0/(denom+2);

		//If the precision value is met
		if(next_term<eps) {
			//Change loop condition to false
			running='0';
		}

		//If n is even, subtract from pi
		//if n is odd, add to pi
		if(n%2==0) {
			pi = pi - this_term;
		}else {
			pi = pi + this_term;
		}

		//Next term
		n=n+1;
	}
	printf("Pi = %.10lf\n",pi);
	printf("Number of terms = %d\n",n);

}

