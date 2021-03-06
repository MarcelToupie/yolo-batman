/*
   Fichier MultiEns.hpp

   D�finition du type Dictionnaire
*/



#ifndef DICTIONNAIRE_HPP
#define DICTIONNAIRE_HPP
#include <vector>
#include "Hashage/Hashage.hpp"
using namespace std;

struct Objet{
			int occurrence;
			string valeur;
		};


template<typename Valeur>
class Dictionnaire{

    private:
		
		Hashage<string,Objet> table;
		void insertion(Objet,vector<Objet> * tabAjout);
		
    public:
		Dictionnaire();
        bool contientMot(string mot); // vrai ssi la cha�ne mot figure dans le dictionnaire
        void ajouterMot(string mot, Valeur v); // ajoute la cha�ne mot au dictionnaire, avec la valeur v, // mot �tant suppos� absent du dictionnaire
        void associerMot(string mot, Valeur v); // associe la valeur v � la cha�ne mot dans le dictionnaire, // mot pouvant �tre pr�sent ou absent du dictionnaire
        void supprimerMot(string mot); // supprime l eventuelle cha�ne mot du dictionnaire
        Objet valeurAssociee(string mot); // donne la valeur correspondant a la cha�ne mot // (suppos�e figurer dans le dictionnaire)
        void motsLesPlusFrequents(int nombre);// renvoi une AList avec les N nombre les plus frequents
		



};

#include "dictionnaire.cpp"


/******************************************************************************/

#endif // DICTIONNAIRE_HPP
