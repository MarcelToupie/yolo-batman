/*
   Fichier dictionnaire.cpp

   Définition des méthodes de dictionnaire

   Antoine Boutruche & Sébastien Vallée

*/
		
		
template<typename Valeur>
	Dictionnaire<Valeur>::Dictionnaire(){
		Objet obj;
		obj.occurrence = -1;
		obj.valeur = "initiale";
		this->pandora = new Arbre<char,Objet>('\0',obj);
		}

template<typename Valeur>
    bool Dictionnaire<Valeur>::contientMot(string mot){ // vrai ssi la chaîne mot figure dans le Dictionnaire
		Arbre<char ,Objet> * navy = pandora;
		int i = 0;
		while(navy != NULL && i< mot.length()){ 
			navy = pandora->renvoiFils(mot[i]);
			i++;
		}
		if(navy = NULL) return false;
		else if (navy->renvoiAssocie().occurrence>0) return true;
		else return false;
    }

template<typename Valeur>
    void Dictionnaire<Valeur>::ajouterMot(string mot, Valeur v){ // ajoute la chaîne mot au Dictionnaire, avec la valeur v, mot étant supposé absent du Dictionnaire
		cout<<"*******DEBUT FONCTION AJOUTERMOT ******"<<mot<<endl;
		Objet obj;
		Arbre<char,Objet> * navy = pandora;
		Arbre<char,Objet> * navyprecedent = NULL;
		unsigned i = 0;
		while(navy != NULL && i < mot.length()){
			navyprecedent = navy;
			cout<<"fils voulu :"<<mot[i]<<endl;
			navy = navy->renvoiFils(mot[i]);
			if(navy !=NULL)
				cout<<"fils renvoye:"<<navy->renvoiEtq()<<endl;
			
			i++;
		}
		cout<<" **FIN BOUCLE FILS CONNUSS**"<<endl;
		unsigned j;
		if(navy == NULL){
			cout<<"--NAVY NULL"<<endl;
			for(j = (i-1); j < mot.length()-1;j++){
					obj.occurrence = 0;
					obj.valeur = "rien";
					navyprecedent->ajouterFils(mot[j],obj);
					navyprecedent = navyprecedent->renvoiFils(mot[j]);
			}
			obj.occurrence =1;
			obj.valeur = v;
			navyprecedent->ajouterFils(mot[mot.length()-1],obj);
		}
		else{
			cout<<"--NAVY NON NULL--"<<endl;
			obj.occurrence =1;
			obj.valeur = v;
			navy->modifierAssocie(obj);
		}
		cout<<"FIN FONCTION AJOUTERMOT"<<endl;
    }

template<typename Valeur>
    void Dictionnaire<Valeur>::associerMot(string mot, Valeur v){ // associe la valeur v à la chaîne mot dans le Dictionnaire, mot pouvant être présent ou absent du Dictionnaire
		Objet obj;
		Arbre<char,Objet> * navy = pandora;
		Arbre<char, Objet> * navyprecedent = NULL;
		unsigned i = 0;
		while(navy != NULL && i < mot.length()){ 
			navyprecedent = navy;
			navy = navy->renvoiFils(mot[i]);
			i++;
		}
		if(navy == NULL){
			for(i = (i-1); i < mot.length()-1;i++){
					obj.occurrence = 0;
					obj.valeur = "rien";
					navyprecedent->ajouterFils(mot[i],obj);
					navyprecedent = navyprecedent->renvoiFils(mot[i]);
			}
			obj.occurrence =1;
			obj.valeur = v;
			navyprecedent->ajouterFils(mot[mot.length()-1],obj);
		}
		else{
			obj.occurrence = navy->renvoiAssocie().occurrence +1;
			obj.valeur = v;
			navy->modifierAssocie(obj);
		}
		
    }

template<typename Valeur>
    void Dictionnaire<Valeur>::supprimerMot(string mot){ // supprime l'éventuelle chaîne mot du Dictionnaire
		Objet obj;
		Arbre<char,Objet> * navy = pandora;
		Arbre<char,Objet> * navyprecedent = NULL;
		unsigned i = 0;
		while(navy != NULL && i < mot.length()){ 
			navyprecedent = navy;
			navy = pandora->renvoiFils(mot[i]);
			i++;
		}
		if(navy != NULL){
			obj.occurrence = 0;
			obj.valeur = "vide";
			navy->modifierAssocie(obj);
		}
    }

template<typename Valeur>
    Objet Dictionnaire<Valeur>::valeurAssociee(string mot){ // donne la valeur correspondant à la chaîne mot // (supposée figurer dans le Dictionnaire)
		Objet obj;
		Arbre<char,Objet> * navy = pandora;
		unsigned i = 0;
		while(i < mot.length()){
			cout<<"recherche de:"<<mot[i]<<endl;
			navy = navy->renvoiFils(mot[i]);
			cout<<navy->renvoiAssocie().occurrence<<endl;
			i++;
		}
		cout<<"fin boucle"<<endl;
		return (navy->renvoiAssocie());
    }
 
template<typename Valeur>   
void  Dictionnaire<Valeur>::motsLesPlusFrequents(int nombre){
		Objet objInit;
		objInit.occurrence =-1;
		objInit.valeur = "vide";
		
		vector<Objet> listeMots(nombre,objInit);
		
		this->parcoursEnProfondeur(this->pandora,&listeMots,nombre,"");
		
		int i=0;
		cout<<"les "<<nombre<<" mots les plus frйquents sont:"<<endl;
		while(i<listeMots.size() && listeMots[i].occurrence != -1){
					cout<<listeMots[i].valeur<<" : "<<listeMots[i].occurrence<<endl;
					i = i +1;
		}
		
		
	}
template<typename Valeur>
void  Dictionnaire<Valeur>::parcoursEnProfondeur(Arbre<char,Objet> * arbre,vector<Objet> * tableau,int nombre,string lettres){
		cout<<"-----debut parcours en profondeur: ";
		
		Objet objInit;
		objInit.occurrence =-1;
		objInit.valeur = "vide";
		
		Objet obj;
		
		lettres=lettres + arbre->renvoiEtq() ;
		cout<<lettres<<endl;
		cout<<"chutt"<<endl;
		
		if(arbre->renvoiAssocie().occurrence >0){
			obj.valeur = lettres;
			obj.occurrence = arbre->renvoiAssocie().occurrence; 
			insertion(obj,tableau);
		}
		
		if(!arbre->estFeuille()){
			vector<Arbre<char,Objet>*> fils = arbre->renvoiTousLesFils();
			
			for (int unsigned i=0;i<fils.size();i++){
					vector<Objet> tableauTemp(nombre,objInit);
					
					parcoursEnProfondeur(fils[i],&tableauTemp,nombre,lettres);
					cout<<"!!!!!!!!!!!!!!INSERTION !!!!!!!!!!!!!!!!!!"<<endl;
					insertion(&tableauTemp,tableau);
					cout<<"!!!!!!!!!!!!!!FIN INSERTION !!!!!!!!!!!!!!!!!!"<<endl;
			}
		}
}

template<typename Valeur>
void Dictionnaire<Valeur>::insertion(vector<Objet> * tabElements,vector<Objet> * tabAjout){
	cout<<"INSERTION vecteur"<<endl;
	Objet swap;
	Objet swap2;
	
	for(int i = 0;i<tabElements->size();i++){
		int j = 0;
		bool trouve=false;
		while(j<tabAjout->size() && trouve==false){
			if(tabAjout->at(j).occurrence==-1 ){
					tabAjout->at(j) = tabElements->at(i);
					trouve=true;
								
			}
			else if(tabElements->at(i).occurrence>tabAjout->at(j).occurrence){
				swap = tabAjout->at(j);
				int k=j+1;
				while(k<tabAjout->size() && tabAjout->at(k).occurrence != -1){
					swap2=tabAjout->at(k);
					tabAjout->at(k) = swap;
					swap = swap2;

					k = k+1;
				}
				tabAjout->at(j) = tabElements->at(i);
				trouve=true;
			}
							
				j = j+1;
		}
	}
}

template<typename Valeur>
void Dictionnaire<Valeur>::insertion(Objet objet,vector<Objet> * tabAjout){
	cout<<"INSERTION objet"<<endl;
	Objet swap;
	Objet swap2;
	
	int j = 0;
	bool trouve=false;
	while(j<tabAjout->size() && trouve==false){
		if(tabAjout->at(j).occurrence==-1 ){
				tabAjout->at(j) = objet;
				trouve=true;
								
		}
		else if(objet.occurrence>tabAjout->at(j).occurrence){
			swap = tabAjout->at(j);
			int k=j+1;
			while(k<tabAjout->size() && tabAjout->at(k).occurrence != -1){
				swap2=tabAjout->at(k);
				tabAjout->at(k) = swap;
				swap = swap2;

				k = k+1;
			}
			tabAjout->at(j) = objet;
			trouve=true;
		}
							
			j = j+1;
	}
}
