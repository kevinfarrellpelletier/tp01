#include <iostream>
int PGCD(int, int);
void simplify(int*, int*);

int main() {

	int numerator = 6;
	int denominator = 12;

	int pgcd = PGCD(numerator, denominator);
	std::cout << "Le PGCD est: " << pgcd << std::endl;

	simplify(&numerator, &denominator);
	std::cout << "La Fraction simplifiee est: " << numerator << "/" << denominator << std::endl;
}

int PGCD(int numerator, int denominator) {

	int min = (numerator > denominator) ? denominator : numerator;
	int pgcd = 1;

	for (int i = 1; i <= min; i++) {

		if ((numerator % i == 0) && (denominator % i == 0)) {

			pgcd = i;
		}
	}

	return pgcd;
}

void simplify(int* numerator, int* denominator) {

	int pgcd = PGCD(*numerator, *denominator);

	if (numerator == denominator) {

		*numerator = 1;
		*denominator = 1;
	}
	else {

		*numerator = (*numerator / pgcd);
		*denominator = (*denominator / pgcd);
	}
}