/*
   Fichier dictionnaire.cpp

   D�finition des m�thodes de dictionnaire

   Antoine Boutruche & S�bastien Vall�e

*/
		
		
template<typename Valeur>
	Dictionnaire<Valeur>::Dictionnaire(){}

template<typename Valeur>
    bool Dictionnaire<Valeur>::contientMot(string mot){ // vrai ssi la cha�ne mot figure dans le Dictionnaire
		return this->table.estClef(mot);
    }

template<typename Valeur>
    void Dictionnaire<Valeur>::ajouterMot(string mot, Valeur v){ // ajoute la cha�ne mot au Dictionnaire, avec la valeur v, mot �tant suppos� absent du Dictionnaire
		Objet obj;
		obj.occurrence = 1;
		obj.valeur = v;
		this->table.associer(mot,obj);//on l'ajoute
		
    }

template<typename Valeur>
    void Dictionnaire<Valeur>::associerMot(string mot, Valeur v){ // associe la valeur v � la cha�ne mot dans le Dictionnaire, mot pouvant �tre pr�sent ou absent du Dictionnaire
		Objet obj;
		if(this->table.estClef(mot)){//il faut incr�menter si pr�sent
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
    void Dictionnaire<Valeur>::supprimerMot(string mot){ // supprime l'�ventuelle cha�ne mot du Dictionnaire
		if(this->table.estClef(mot)){
        this->table.dissocier(mot);
		}
    }

template<typename Valeur>
    Objet Dictionnaire<Valeur>::valeurAssociee(string mot){ // donne la valeur correspondant � la cha�ne mot // (suppos�e figurer dans le Dictionnaire)
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
		cout<<"les "<<nombre<<" mots les plus fr�quents sont:"<<endl;
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
