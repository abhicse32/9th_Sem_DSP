#include<stdio.h>
#include<math.h>


typedef struct complex_ complex;
struct complex_ {									/*declaring a structure complex since it is not a basic data type */
					float real;
					float imaginary;
				};


complex addition( complex complex1, complex complex2 );			/* prototype for addition function*/
complex substraction( complex complex1, complex complex2 );		/* prototype for substraction function*/
complex multiplication( complex complex1, complex complex2 );	/* prototype for multiplication function*/
complex division( complex complex1, complex complex2 );			/* prototype for division function*/
float distance( complex complex1, complex complex2 );			/* prototype for distance function*/




int main()
	{
		int menu;			/*menu is a variable which is used to choose what function to carry out*/
		complex complex1;	/*complex1 is a input number*/
		complex complex2;	/*complex2 is a input number*/

		do {
				scanf("%f %f",&complex1.real,&complex1.imaginary);
				scanf("%f %f",&complex2.real,&complex2.imaginary);
				scanf("%d",&menu);

				if ( menu == -1 || menu == 0 ) break;		/*condition for Terminating the program*/
				
				else if ( menu == 1 ) {
										complex result;		/* Declared for printing the value of the result obtained*/
										result = addition ( complex1, complex2 );
										if(result.imaginary > 0) printf("%f+%fi\n",result.real,result.imaginary);
										else if (result.imaginary<0) printf("%f%fi\n",result.real,result.imaginary);
										else printf("%f\n",result.real);
									  }
							 
				else if ( menu == 2 ) {
										complex result; /* Declared for printing the value of the result obtained*/
										result = substraction ( complex1, complex2 );
										if(result.imaginary > 0) printf("%f + %fi\n",result.real,result.imaginary);
										else if (result.imaginary<0) printf("%f %fi\n",result.real,result.imaginary);
										else printf("%f\n",result.real);
									  }

				else if ( menu == 3 ) {
										complex result; /* Declared for printing the value of the result obtained*/
										result = multiplication ( complex1, complex2 );
										if(result.imaginary > 0) printf("%f + %fi\n",result.real,result.imaginary);
										else if (result.imaginary<0) printf("%f %fi\n",result.real,result.imaginary);
										else printf("%f\n",result.real);
									  }

				else if ( menu == 4 ) {
										complex result; /* Declared for printing the value of the result obtained*/
										if(complex2.real!=0 || complex2.imaginary!=0) {result = division ( complex1, complex2 );
										if(result.imaginary > 0) printf("%f + %fi\n",result.real,result.imaginary);
										else if (result.imaginary<0) printf("%f %fi\n",result.real,result.imaginary);
										else printf("%f\n",result.real);}
						
										else printf("Cant be divided by zero");
									  }
				

				else if ( menu == 5 ) {
										float result; /* Declared for printing the value of the result obtained*/
										result = distance ( complex1, complex2 );
										printf("%f\n",result);
									  }
			
		    } while ( 1 );

	}


complex addition( complex complex1, complex complex2 )		/*this function just adds the 2 complex by adding the real and complex individually*/
	{
		complex result;		
		result.real = complex1.real + complex2.real;
		result.imaginary = complex1.imaginary + complex2.imaginary;
		return result;
	}

complex substraction( complex complex1, complex complex2 )	/*this function just adds the 2 complex by substracting the real and complex individually*/
	{
		complex result;
		result.real = complex1.real - complex2.real;
		result.imaginary = complex1.imaginary - complex2.imaginary;
		return result;
	}

complex multiplication ( complex complex1, complex complex2 )	/*this function multiplies two complex inputs and returns and complex*/
	{
		complex result;
		result.real = (complex1.real * complex2.real) - (complex1.imaginary * complex2.imaginary);
		result.imaginary = (complex1.imaginary * complex2.real) + (complex2.imaginary * complex1.real);
		return result;
	}

complex division( complex complex1, complex complex2 )		/*done by multpling numerator with denominators conjugate and dividing result by modulus*/
	{
		complex result;
		float modulus2;			/*for computing the modulus of the complex2*/
		complex2.imaginary = - complex2.imaginary;
		result = multiplication(complex1, complex2);
		modulus2 = (complex1.real * complex2.real)*(complex1.real * complex2.real);
		modulus2 = modulus2 + (complex1.imaginary * complex2.imaginary)*(complex1.imaginary * complex2.imaginary);
		result.real = result.real/modulus2 ;
		result.imaginary = result.imaginary/modulus2 ;		
		return result;
	}

float distance( complex complex1, complex complex2 )	/*found real distance, imaginary distance and applied pythogorous theorem*/
	{
		float result;
		float realdiff = complex1.real - complex2.real; 	/*to find the real distance*/
		float imaginarydiff = complex1.imaginary - complex2.imaginary;	/*to find the real distance*/
		result = (realdiff * realdiff ) + (imaginarydiff * imaginarydiff );
		result = sqrt(result);
		return result;
	}



								
	
