/*
   Fichier MultiEns.hpp

   Définition du type Dictionnaire
*/



#ifndef DICTIONNAIRE_HPP
#define DICTIONNAIRE_HPP

#include "Hashage/Hashage.hpp"
using namespace std;

struct Objet{
			int occurrence;
			string valeur;
		};


template<typename Valeur>
class Dictionnaire{

    public:
		
		Hashage<string,Objet> table;
		
    
		Dictionnaire();
        bool contientMot(string mot); // vrai ssi la chaîne mot figure dans le dictionnaire
        void ajouterMot(string mot, Valeur v); // ajoute la chaîne mot au dictionnaire, avec la valeur v, // mot étant supposé absent du dictionnaire
        void associerMot(string mot, Valeur v); // associe la valeur v à la chaîne mot dans le dictionnaire, // mot pouvant être présent ou absent du dictionnaire
        void supprimerMot(string mot); // supprime l eventuelle chaîne mot du dictionnaire
        Objet valeurAssociee(string mot); // donne la valeur correspondant a la chaîne mot // (supposée figurer dans le dictionnaire)




};

#include "dictionnaire.cpp"


/******************************************************************************/

#endif // DICTIONNAIRE_HPP
