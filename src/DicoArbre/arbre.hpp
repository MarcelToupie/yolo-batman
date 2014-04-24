
template<typename T, typename Association>

class Arbre{


	private:
		T etq;
		Arbre lesFils[15];
		int nbFils = 0;
		Association associe;
		
	

	public:
		bool estFeuille();//retourne vrai si l'arbre est une feuille
		T etq();//retourne l'étiquette de l'arbre
		Arbre renvoiFils(T etq);//renvoi les fils de l'arbre
		Arbre ajouterFils(T etq,Association assoc);//ajoute un fils à l'arbre
		Association renvoiAssocie();//renvoi l'objet associé à l'étiquette
		
}

#include<arbre.cpp>
