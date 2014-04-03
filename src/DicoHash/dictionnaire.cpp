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
				this->table->associer(mot,obj);//sinon on l'ajoute
		}
    }

template<typename Valeur>
    void Dictionnaire<Valeur>::supprimerMot(string mot){ // supprime l'�ventuelle cha�ne mot du Dictionnaire
		if(this->table.estClef(mot)){
        this->table.dissocier(mot);
		}
    }

template<typename Valeur>
    Valeur Dictionnaire<Valeur>::valeurAssociee(string mot){ // donne la valeur correspondant � la cha�ne mot // (suppos�e figurer dans le Dictionnaire)
		return(this->table->valeurAssociee(mot).valeur);
    }
