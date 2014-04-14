#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <dirent.h>
using namespace std;

#include "DicoHash/dictionnaire.hpp"



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

      while(fichier >> mot) //Tant qu'on n'est pas à la fin, on lit
      {
		cout<<mot<<endl;
         dico.ajouterMot(mot, "rien");
         //Gestion fermeture automatique du fichier
      }
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }
   cout<<"finish him"<<endl;

   return 0;
	}

