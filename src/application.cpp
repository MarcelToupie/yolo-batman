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
		
		cout<<"fin"<<endl;
	}

