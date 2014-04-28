/*
   Fichier dictionnaire.cpp

   Définition des méthodes de dictionnaire

   Antoine Boutruche & Sébastien Vallée

*/
		
		
template<typename Valeur>
	Dictionnaire<Valeur>::Dictionnaire(){}

template<typename Valeur>
    bool Dictionnaire<Valeur>::contientMot(string mot){ // vrai ssi la chaîne mot figure dans le Dictionnaire
		return this->table.estClef(mot);
    }

template<typename Valeur>
    void Dictionnaire<Valeur>::ajouterMot(string mot, Valeur v){ // ajoute la chaîne mot au Dictionnaire, avec la valeur v, mot étant supposé absent du Dictionnaire
		Objet obj;
		obj.occurrence = 1;
		obj.valeur = v;
		this->table.associer(mot,obj);//on l'ajoute
		
    }

template<typename Valeur>
    void Dictionnaire<Valeur>::associerMot(string mot, Valeur v){ // associe la valeur v à la chaîne mot dans le Dictionnaire, mot pouvant être présent ou absent du Dictionnaire
		Objet obj;
		if(this->table.estClef(mot)){//il faut incrémenter si présent
				obj = this->table.valeurAssociee(mot);
				obj.occurrence = obj.occurrence+1;
				obj.valeur = v;		
				this->table.associer(mot,obj);
		}
		else{
				obj.occurrence = 1;
				obj.valeur = v;
				this->table.associer(mot,obj);//sinon on l'ajoute
		}
    }

template<typename Valeur>
    void Dictionnaire<Valeur>::supprimerMot(string mot){ // supprime l'éventuelle chaîne mot du Dictionnaire
		if(this->table.estClef(mot)){
        this->table.dissocier(mot);
		}
    }

template<typename Valeur>
    Objet Dictionnaire<Valeur>::valeurAssociee(string mot){ // donne la valeur correspondant à la chaîne mot // (supposée figurer dans le Dictionnaire)
		return(this->table.valeurAssociee(mot));
    }
 
template<typename Valeur>   
    void  Dictionnaire<Valeur>::motsLesPlusFrequents(int nombre){
		Objet objInit;
		objInit.occurrence =-1;
		objInit.valeur = "vide";
		
		Objet swap;
		Objet swap2;
		vector<Objet> listeMots(nombre,objInit);
		vector<string> * clfs = new vector<string>();
		int N=0;
		
		this->table.trousseau(clfs,N);
		for(int i = 0;i<clfs->size();i++){
			objInit.valeur = clfs->at(i);
			objInit.occurrence = this->table.valeurAssociee(clfs->at(i)).occurrence;
			insertion(objInit,&listeMots);
						
			}
		int i=0;
		cout<<"les "<<nombre<<" mots les plus fréquents sont:"<<endl;
		while(i<listeMots.size() && listeMots[i].occurrence != -1){
			cout<<listeMots[i].valeur<<" : "<<listeMots[i].occurrence<<endl;
			i = i +1;
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
