#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

using namespace std;

//#include "DicoHash/dictionnaire.hpp"
#include "DicoArbre/dictionnaire.hpp"
int main(){
	cout<<"creation dico"<<endl;
	Dictionnaire<string> dico;
		cout<<"DEBUT AJOUT BONJOUR"<<endl;
		dico.ajouterMot("bonjour", "nom");
		cout<<"FIN AJOUT BONJOUR"<<endl<<endl;
		cout<<"DEBUT AJOUT BONSOIR"<<endl;
		dico.ajouterMot("bonsoir", "nom");
		cout<<"FIN AJOUT BONSOIR"<<endl<<endl;
		cout<<"ajout bonsoir"<<endl;
		dico.ajouterMot("bonsoir", "nom");
		cout<<"FIN AJOUT BONSOIR"<<endl<<endl;
		cout<<"ajout manifestation"<<endl;
		dico.ajouterMot("manifestation", "nom");
		cout<<"FIN AJOUT BONSOIR"<<endl<<endl;
		cout<<"--------------------	fin ajout----------------"<<endl;

		cout<<"bonsoir :"<<dico.valeurAssociee("bonsoir").occurrence<<endl;
		cout<<"bonjour :"<<dico.valeurAssociee("bonjour").occurrence<<endl;
		cout<<"manifestation :"<<dico.valeurAssociee("manifestation").occurrence<<endl;
		cout<<endl<<endl<<endl;

		cout<<"ajout bonjour"<<endl;
		dico.associerMot("bonjour", "nom");
		cout<<"ajout bonjour"<<endl;
		dico.associerMot("bonjour", "nom");
		cout<<"ajout bonjour"<<endl;		
		dico.associerMot("bonjour", "nom");
		cout<<"ajout bonsoir"<<endl;
		dico.associerMot("bonsoir", "nom");
		cout<<"ajout bonsoir"<<endl;
		dico.associerMot("bonsoir", "nom");
		cout<<"ajout manifestation"<<endl;
		dico.associerMot("manifestation", "nom");
		dico.associerMot("manifestation", "nom");
		dico.associerMot("manifestation", "nom");
		dico.associerMot("manifestation", "nom");
		dico.associerMot("manifestation", "nom");
		dico.associerMot("manifestation", "nom");
		dico.associerMot("manifestation", "nom");
		cout<<"ajout crotte"<<endl;
		dico.associerMot("crotte", "nom");
		
		cout<<endl;
		cout<<"3|||||||||||||||||||bonsoir :"<<dico.valeurAssociee("bonsoir").occurrence<<endl;
		cout<<"4|||||||||||||||||||bonjour :"<<dico.valeurAssociee("bonjour").occurrence<<endl;
		cout<<"2|||||||||||||||||||manifestation :"<<dico.valeurAssociee("manifestation").occurrence<<endl;
		

		cout<<endl<<endl<<"DEBUT MOTS LES PLUS FREQUENTS :"<<endl;

		dico.motsLesPlusFrequents(2);
		cout<<"fin"<<endl;

		return 0;
}
