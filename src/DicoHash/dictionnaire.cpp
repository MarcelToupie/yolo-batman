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
				this->table->associer(mot,obj);//sinon on l'ajoute
		}
    }

template<typename Valeur>
    void Dictionnaire<Valeur>::supprimerMot(string mot){ // supprime l'éventuelle chaîne mot du Dictionnaire
		if(this->table.estClef(mot)){
        this->table.dissocier(mot);
		}
    }

template<typename Valeur>
    Valeur Dictionnaire<Valeur>::valeurAssociee(string mot){ // donne la valeur correspondant à la chaîne mot // (supposée figurer dans le Dictionnaire)
		return(this->table->valeurAssociee(mot).valeur);
    }
