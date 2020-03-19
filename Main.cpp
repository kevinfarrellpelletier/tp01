// ConsoleApplication1.cpp : définit le point d'entrée pour l'application console.
#include <iostream>

int readInt();
int PGCD(int numerator, int denominator);
void remplirTableau(int num[], int denom[], int);
void affiche(int num[], int denom[], int);
void simplify(int* numerator, int* denominator);

int main() {

	int nbFract;

	std::cout << "Saisir le nombre de fractions à analyser :" << std::endl;
	std::cin >> nbFract;

	int* numTab = new int[nbFract];
	int* denomTab = new int[nbFract];

	remplirTableau(numTab, denomTab, nbFract);

	affiche(numTab, denomTab, nbFract);
}

int readInt() {

	int value;
	bool valide = false;

	while (!valide) {

		std::cout << "Entrez la valeur: ";
		std::cin >> value;

		if (!std::cin.fail() && value > 0) {

			valide = true;
		}
		else {

			std::cout << "CE N'EST PAS UN INT VALIDE (DOIT ETRE PLUS GRAND QUE 0 ET ETRE UN NOMBRE ENTIER) !!!!" << std::endl;
			std::cin.clear();
			std::cin.ignore(999, '\n');
			std::cout << std::endl;
		}
	}

	return value;
}

void remplirTableau(int num[], int denom[], int nbFract) {

	for (int i = 0; i < nbFract; i++) {
		std::cout << "Saisir le numerateur de la fraction " << (i + 1) << " : " << std::endl;
		num[i] = readInt();

		std::cout << "Saisir le denominateur de la fraction " << (i + 1) << " : " << std::endl;
		denom[i] = readInt();
	}
}

void affiche(int num[], int denom[], int nbFract) {



	for (int i = 0; i < nbFract; i++) {

		std::cout << num[i] << "/" << denom[i] << " >>> ";
		simplify(&num[i], &denom[i]);
		std::cout << num[i] << "/" << denom[i] << std::endl;
	}
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
	*numerator = (*numerator / pgcd);
	*denominator = (*denominator / pgcd);
}