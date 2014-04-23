/*
* File : Hashage.cpp
* Fichier contenant l'implémentation de la classe Hashage
* Authors : Francois Hallereau & Sébastien Vallée
*/

#include "Hashage.hpp"
#include <typeinfo>
#include <fstream>
//---------------------------------------

//Constructeur
template<typename K, typename V>
Hashage<K,V>::Hashage() {}


//Destructeur
template<typename K, typename V>
Hashage<K,V>::~Hashage() {}


//Fonctions de hachage
template<typename K, typename V>
	int Hashage<K,V>::hash(float cle) {
		return ( (int)((int)cle%(TAILLE-1)) );
	}
template<typename K, typename V>
	int Hashage<K,V>::hash(int cle) {
		return (int)(cle%(TAILLE-1));
	}
template<typename K, typename V>
	int Hashage<K,V>::hash(string cle) {
		int sum=0;
				for(int i = 0 ; i< cle.length(); i++){
					sum = sum + int(cle[i]);
					cout<<sum<<endl;
				}
				int modulo = sum%(TAILLE-1);
				return (int)abs(sum%(TAILLE-1));
	}


   
//ajoute le couple (clf,valr) ou change la valeur associée à clf s'il y en avait une
template <typename K,typename V>
void Hashage<K,V>::associer(K clf,V valr){
	int hashageur = hash(clf);
	this->list[hashageur].associer(clf,valr);
}

template <typename K,typename V>
bool Hashage<K,V>::estVide(){
    bool res = true;
    for(int i=0;i<TAILLE;i++){
        if(!this->list[i].estALVide())
            res=false;
    }
    return res;
}


template <typename K,typename V>
V Hashage<K,V>::valeurAssociee(K clf){
    return this->list[hash(clf)].valeurAssociee(clf);
}

template <typename K,typename V>
void Hashage<K,V>::dissocier(K clf){
    this->list[hash(clf)].dissocier(clf);
}


template <typename K,typename V>
bool Hashage<K,V>::estClef(K cle){
    return this->list[hash(cle)].estClef(cle);
}

template <typename K,typename V>
void Hashage<K,V>::trousseau(vector<K> * clfs, int &N ){
    K* temp;
    int i,j,taille;
    if(! this->estVide() ) {
		cout<<"ca passe"<<endl;
        for(i = 0; i < TAILLE; i++) { //on parcours toutes les AList de la table de hashage
			cout<<"boubou"<<endl;
            temp = new K[100]; //on crée un tableau temporaire stockant les clés de la AList courante
            this->list[i].trousseau(temp,taille); //on applique trousseau(...) sur la AList courante
            N += taille; //on met à jour la taille de N
            cout<<"TAILLE :" <<taille<<endl;
            cout<<"N :" <<N<<endl;

            for(j = 0; j < taille; j++) { //on parcours le liste des clefs dans le tableau temporaire
				cout<<"WTF"<<endl;
                clfs->push_back("lol"); //on l'ajoute au tableau de réponse
                cout<<"WHYYYY"<<endl;
            }
            delete[] temp;
        }
    }
    cout<<N<<endl;
}
