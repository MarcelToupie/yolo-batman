/*
   Fichier MultiEns.hpp

   D�finition du type Dictionnaire
*/

#ifndef DICTIONNAIRE_HPP
#define DICTIONNAIRE_HPP

#include "Hashage.hpp"

template<typename Valeur>
class dictionnaire{

    private:
    public:
        bool contientMot(String mot); // vrai ssi la cha�ne mot figure dans le dictionnaire
        void ajouterMot(String mot, Valeur v); // ajoute la cha�ne mot au dictionnaire, avec la valeur v, // mot �tant suppos� absent du dictionnaire
        void associerMot(String mot, Valeur v); // associe la valeur v � la cha�ne mot dans le dictionnaire, // mot pouvant �tre pr�sent ou absent du dictionnaire
        void supprimerMot(String mot); // supprime l'�ventuelle cha�ne mot du dictionnaire
        Valeur valeurAssoci�e(String mot); // donne la valeur correspondant � la cha�ne mot // (suppos�e figurer dans le dictionnaire)




};

#include "dictionnaire.cpp"


/******************************************************************************/

#endif // DICTIONNAIRE_HPP
