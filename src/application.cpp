#include <iostream>
#include <string>
using namespace std;

#include "DicoHash/dictionnaire.hpp"



int main(){
	cout<<"creation dico"<<endl;
	Dictionnaire<string> dico;
		cout<<"ajout bonjour"<<endl;
		dico.ajouterMot("bonjour", "nom");
		cout<<"ajout bonsoir"<<endl;
		dico.ajouterMot("bonsoir", "nom");
		cout<<"ajout bonsoir"<<endl;
		dico.ajouterMot("bonsoir", "nom");
		cout<<"ajout manifestation"<<endl;
		dico.ajouterMot("manifestation", "nom");
		
		cout<<dico.valeurAssociee("bonsoir").occurrence<<endl;
		cout<<dico.valeurAssociee("bonjour").occurrence<<endl;
		
		cout<<endl<<endl<<endl;
		
		cout<<"ajout bonjour"<<endl;
		dico.associerMot("bonjour", "nom");
		dico.associerMot("bonjour", "nom");
		dico.associerMot("bonjour", "nom");
		cout<<"ajout bonsoir"<<endl;
		dico.associerMot("bonsoir", "nom");
		cout<<"ajout bonsoir"<<endl;
		dico.associerMot("bonsoir", "nom");
		cout<<"ajout manifestation"<<endl;
		dico.associerMot("manifestation", "nom");
		
		
		
		


		
		cout<<dico.valeurAssociee("bonsoir").occurrence<<endl;
		cout<<dico.valeurAssociee("bonjour").occurrence<<endl;
		cout<<dico.valeurAssociee("manifestation").occurrence<<endl;
		
		cout<<"fin"<<endl;
	}

