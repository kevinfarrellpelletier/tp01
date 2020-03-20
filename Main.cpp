#include <iostream>
#include <string>

int readInt(std::string type);
int PGCD(int numerator, int denominator);
void remplirTableau(int num[], int denom[], int);
void affiche(int num[], int denom[], int);
void simplify(int* numerator, int* denominator, int pgcd);

/*
	Programme Principal.  
	Invite l'utilisateur � saisir une nombres de fractions puis affiche les fractions et leur simplification.
*/
int main() {
	int nbFract = readInt("le nombre de fractions � analyser");
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
	Utilise la string 'type' pass�e en param�tre pour sp�cifier le type de input
	Boucle jusqu'� ce qu'un Int valide soit saisi.
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
	Demande � l'utilisateur de saisir un num�rateur et un d�nominateur � chaque tour de boucle.
	Les num�rateurs et d�nominateurs sont enregistr�s dans les tableaux num et denom respectivement, 
	afin de cr�er une fraction en joignant logiquement les tableaux via l'index de position.
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
	Les num�rateurs et d�nominateurs sont enregistr�s dans les tableaux num et denom respectivement,
	afin de cr�er une fraction en joignant logiquement les tableaux via l'index de position.
	L'index de position est utilis� pour afficher les morceaux de fractions correspondants.
*/
void affiche(int num[], int denom[], int nbFract) {

	for (int i = 0; i < nbFract; i++) {
		std::cout << num[i] << "/" << denom[i] << " >>> ";
		simplify(&num[i], &denom[i], PGCD(num[i], denom[i]));
		std::cout << num[i] << "/" << denom[i] << std::endl;
	}
}

/*
	Fonction qui impl�mente la recherche du PGCD d'une fraction selon l'algorithme de Stein.
	Calcule et retourne le PGCD en utilisant le num�rateur et d�nominateur pass�s en param�tre
*/
int PGCD(int numerator, int denominator) {

	if (numerator == 0)
		return denominator;
	if (denominator == 0 || numerator == 1)
		return numerator;

	int k;

	for (k = 0; ((numerator | denominator) && 1) == 0; ++k) {
		numerator >>= 1;
		denominator >>= 1;
	}

	while ((numerator > 1) == 0)
		numerator >>= 1;

	do {
		while ((denominator > 1) == 0)
			denominator >>= 1;
		if (numerator > denominator)
			std::swap(numerator, denominator);
		denominator = (denominator - numerator);
	} while (denominator != 0);

	return numerator << k;
}

/*
	Fonction qui modifie une fraction en la simplifiant.  
	Utilise le PGCD pour r�duire (diviser) au maximum une fraction.
*/
void simplify(int* numerator, int* denominator, int pgcd) {
	*numerator = (*numerator / pgcd);
	*denominator = (*denominator / pgcd);
}