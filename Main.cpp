#include <iostream>
#include <string>

int readInt(std::string type);
int PGCD(int numerator, int denominator);
void remplirTableau(int num[], int denom[], int);
void affiche(int num[], int denom[], int);
void simplify(int* numerator, int* denominator);

/*
	Programme Principal.  
	Invite l'utilisateur à saisir une nombres de fractions puis affiche les fractions et leur simplification.
*/
int main() {
	int nbFract = readInt("le nombre de fractions à analyser");
	int* numTab = new int[nbFract];
	int* denomTab = new int[nbFract];

	remplirTableau(numTab, denomTab, nbFract);
	affiche(numTab, denomTab, nbFract);
	delete[] numTab;
	delete[] denomTab;

	return 0;
}

/*
	Fonction permettant de saisir un Int au clavier.
	Utilise la string 'type' passée en paramètre pour spécifier le type de input
	Boucle jusqu'à ce qu'un Int valide soit saisi.
*/
int readInt(std::string type) {
	int value;
	bool valide = false;

	while (!valide) {
		std::cout << "Saisir " << type << ": ";
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

/*
	Fonction permettant de remplir un tableau avec des fractions.
	Utilise nbFract pour boucler N fois afin de remplir le tableau.
	Demande à l'utilisateur de saisir un numérateur et un dénominateur à chaque tour de boucle.
	Les numérateurs et dénominateurs sont enregistrés dans les tableaux num et denom respectivement, 
	afin de créer une fraction en joignant logiquement les tableaux via l'index de position.
*/
void remplirTableau(int num[], int denom[], int nbFract) {

	for (int i = 0; i < nbFract; i++) {
		num[i] = readInt("le numerateur de la fraction " + std::to_string(i + 1));
		denom[i] = readInt("le denominateur de la fraction " + std::to_string(i + 1));
	}
}

/*
	Fonction qui affiche le contenu du tableau.
	Utilise nbFract pour boucler N fois afin de remplir le tableau.
	Les numérateurs et dénominateurs sont enregistrés dans les tableaux num et denom respectivement,
	afin de créer une fraction en joignant logiquement les tableaux via l'index de position.
	L'index de position est utilisé pour afficher les morceaux de fractions correspondants
*/
void affiche(int num[], int denom[], int nbFract) {

	for (int i = 0; i < nbFract; i++) {
		std::cout << num[i] << "/" << denom[i] << " >>> ";
		simplify(&num[i], &denom[i]);
		std::cout << num[i] << "/" << denom[i] << std::endl;
	}
}

/*
	Fonction qui implémente la recherche du PGCD d'une fraction selon l'algorithme de Stein.
	Calcule et retourne le PGCD en utilisant le numérateur et dénominateur passés en paramètre
*/
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

/*
	Fonction qui modifie une fraction en la simplifiant.  
	Utilise le PGCD pour réduire (diviser) au maximum une fraction.
*/
void simplify(int* numerator, int* denominator) {
	int pgcd = PGCD(*numerator, *denominator);
	*numerator = (*numerator / pgcd);
	*denominator = (*denominator / pgcd);
}