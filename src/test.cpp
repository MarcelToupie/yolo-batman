#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

#include "DicoHash/dictionnaire.hpp"
int main(){
	/*string n1 = "n1";
	string n2 = "n2";
	bool eras = false;

	if(typeid(n1)==typeid(string))
		eras = true;
	cout<<eras<<endl;*/

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
		cout<<"ajout crotte"<<endl;
		dico.associerMot("crotte", "nom");
		



		dico.motsLesPlusFrequents(2);
		cout<<"fin"<<endl;

		return 0;
}
