/*
Student Name: Thomas Beton
Student Number: C10386145
*/

#include<stdio.h>;
#include<stdlib.h>;
#include<time.h>;

// Booleans
bool isPrimeOne = false;
bool isPrimeTwo = false;
bool isFlagged = false;

// Prime Number Ints
int primeOne = 4;
int primeTwo = 4;

// Misc variables
int i = 0;
int n = 0;
int s = 0;
int phi = 0;
int C = 0;
int M = 0;
int e = 0;
int d = 0;
char option;

// Randomly generate a number for primeOne between 100 - 500 and determin if it is a prime number.
// ... If it is a prime number the loop will exit.
void primeOneCalculate()
{
	do
	{
		for(i = 2 ; i < primeOne ; i++)
		{
			if(primeOne % i == 0)
			{
				isPrimeOne = false;
				primeOne = rand() % 500;
				break;
			}
			isPrimeOne = true;
		}
	}while(isPrimeOne == false || primeOne < 100);
}

// Randomly generate a number for primeTwo between 100 - 500 and determin if it is a prime number.
// ... If it is a prime number the loop will exit.
void primeTwoCalculate()
{
	do
	{
		for(i = 2 ; i < primeTwo ; i++)
		{
			if(primeTwo % i == 0)
			{
				isPrimeTwo = false;
				primeTwo = rand() % 500;
				break;
			}
			isPrimeTwo = true;
		}
	}while(isPrimeTwo == false || primeTwo < 100);
}

void checkFlag()
{
	for(i = 3 ; (e % i == 0) && (phi % i == 0) ; i+=2)
	{
		isFlagged = true;

		return;
	}
	isFlagged = false;
}

void encryptInput()
{
	// Assigning a value to C.
	C = 1;

	// Encryption loop.
	for(i = 0 ; i < e ; i++)
	{
		C = C * M % n;
		C = C % n;
	}
	printf("Encrypted Input: %d", C);
}

// Decrypt method
void decryptInput()
{
	// Assigning a value to M.
	M = 1;

	// Decryption loop.
	for(i = 0 ; i < d ; i++)
	{
		M = M * C % n;
		M = M % n;
	}
	printf("Decrypted Input: %d", M);
}

void main()
{
	// Used for randomly generating the number values.
	srand(time(0));

	// START goto for restarting the program.
	START:

	// Initialise primeOne and primeTwo to a non-prime number.
	// ... This allows the functions to search for a new prime number value.
	primeOne = 4;
	primeTwo = 4;

	// Clears the window and ready the program.
	system("cls");
	printf("Press Enter to start the program.");
	getchar();

	// Clears the window and runs the Calculate methods to find prime number values.
	system("cls");
	primeOneCalculate();
	primeTwoCalculate();

	// Prints out the Prime number values from primeOne and primeTwo.
	printf("The First Prime Number: %d\n", primeOne);
	printf("The Second Prime Number: %d\n\n", primeTwo);

	// Calculate the product of primeOne and primeTwo.
	// ... Calculate the product of (primeOne - 1) and (primeTwo - 1).
	n = primeOne * primeTwo;
	phi = (primeOne - 1) * (primeTwo - 1);

	// Print the value of phi.
	printf("F(n) phi value is: %d\n\n", phi);

	do
	{
		printf("Input 'e' which is a prime number and also less than the phi value: ", n);
		scanf("%d", &e);
		printf("\n");

		checkFlag();
	}while(isFlagged == 1);

	// Assign a value to d.
	d = 1;

	do
	{
		s = (d*e)%phi;
		d++;
	}while(s != 1);

	// Assign a new value to d.
	d = d - 1;

	// Print the Public and Private Key
	printf("The Public Key: (%d, %d)\n", e, n);
	printf("The Private Key: (%d, %d)\n\n\n", d, n);

	// Take input and calculate.
	printf("Input the numbers to be encrypted: ");
	scanf("%d", &M);
	encryptInput();

	// Take input and calculate.
	printf("\n\nInput the returned Cipher to be decrypted: ");
	scanf("%d", &C);
	decryptInput();

	// Options to restart or exit the program.
	printf("\n\nInput 'Y' or 'N' to restart or exit the program.");
	OPTION:
	scanf("%c", &option);

	if(option == 'Y')
	{
		goto START;
	}
	else if(option == 'N')
	{
		exit(NULL);
	}
	else
	{
		goto OPTION;
	}
}