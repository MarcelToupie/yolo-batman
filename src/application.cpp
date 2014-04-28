#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <sstream>
#include <cmath>
//#include <regex>
using namespace std;

//#include "DicoHash/dictionnaire.hpp"
#include "DicoArbre/dictionnaire.hpp"



int main(){

	cout<<"Bievenue utilisateur"<<endl;
	cout<<"Pour utliser un de vos documents, vous devez prealablement le placer dans le repertoire res/Documents du projet yolo-batman"<<endl;

	cout<<"voici la liste des documents presents :"<<endl;
		DIR * rep = opendir("../res/Documents");

		if (rep == NULL)
			cout<<"erreur, le dossier Documents n existe plus, impossible de faire des traitements"<<endl;
		else{
			struct dirent * ent;

			while ((ent = readdir(rep)) != NULL)
			{
				printf("%s\n", ent->d_name);
			}
            cout<<endl;
			closedir(rep);
		}

	string nomFichier;
	cout<<"veuillez entrer le nom du fichier que vous voulez utiliser : "<<endl;
	cin>>nomFichier;




    Dictionnaire<string> dico;


	string cheminFichier = "../res/Documents/";
	cheminFichier = cheminFichier + nomFichier;
	ifstream fichier(cheminFichier.c_str());

   if(fichier)
   {
      //L'ouverture s'est bien passée, on peut donc lire

      string mot; //Une variable pour stocker les mots lues
      char * writable;
	  cout<<"begin him"<<endl;
      while(fichier >> mot) //Tant qu'on n'est pas à la fin, on lit
      {
		if((int)mot[0]==(int)'-'){
				mot.erase(mot.begin());
		}
		if((int)mot[mot.length()-1]==(int)'-'){
			mot.erase(mot.end());
		}
		if((int)mot[1]==(int)'\''){
				mot.erase(mot.begin(),mot.begin()+2);
		}
		
		
			 writable = new char[mot.size() + 1];
			copy(mot.begin(), mot.end(), writable);
			writable[mot.size()] = '\0';
		if(writable != NULL){
			writable = strtok(writable,",:;!.\"+/*1234567890?&");
		}

		if(writable != NULL){
			cout<<writable<<endl;
			dico.associerMot(mot, "rien");
        //Gestion probleme fermeture automatique du fichier//
		}
	}
	dico.motsLesPlusFrequents(10);
}
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }
   cout<<"finish him"<<endl;

   return 0;
	}

