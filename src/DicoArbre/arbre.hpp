
template<typename T, typename Association>
class Arbre{


	private:
		T etq;
		vector<Arbre<T,Association>*> lesFils;
		int nbFils;
		Association associe;
		
	

	public:
		Arbre(T etiquette,Association assoc);
		void modifierAssocie(Association assoc);
		bool estFeuille();//retourne vrai si l'arbre est une feuille
		T renvoiEtq();//retourne l'étiquette de l'arbre
		Arbre<T,Association> * renvoiFils(T etiquettes);//renvoi les fils de l'arbre
		void ajouterFils(T etq,Association assoc);//ajoute un fils à l'arbre
		Association renvoiAssocie();//renvoi l'objet associé à l'étiquette
		vector<Arbre<T,Association>*> renvoiTousLesFils();
		
};

#include "arbre.cpp"
