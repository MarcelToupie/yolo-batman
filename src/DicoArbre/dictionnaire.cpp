/*
   Fichier dictionnaire.cpp

   Définition des méthodes de dictionnaire

   Antoine Boutruche & Sébastien Vallée

*/
		
		
template<typename Valeur>
	Dictionnaire<Valeur>::Dictionnaire(){}

template<typename Valeur>
    bool Dictionnaire<Valeur>::contientMot(string mot){ // vrai ssi la chaîne mot figure dans le Dictionnaire
		Arbre<Valeur> navy = pandora;
		int i = 0;
		while(navy != NULL && i< mot.length()){ 
			navy = pandora.renvoiFils(mot[i]);
			i++;
		}
		if(navy = NULL) return false;
		else if (navy.renvoiAssocie().occurrence>0) return true;
		else return false;
    }

template<typename Valeur>
    void Dictionnaire<Valeur>::ajouterMot(string mot, Valeur v){ // ajoute la chaîne mot au Dictionnaire, avec la valeur v, mot étant supposé absent du Dictionnaire
		Objet obj;
		Arbre<Valeur> navy = pandora;
		Arbre<Valeur> navyprecedent = NULL;
		int i = 0;
		while(navy != NULL && i < mot.length()){ 
			navyprecedent = navy;
			navy = pandora.renvoiFils(mot[i]);
			i++;
		}
		if(navy = NULL){
			for(i = i-1; i < mot.length()-1;i++){
					obj.occurence = 0;
					obj.valeur = "rien";
					navyprecedent.ajouterFils(mot[i],obj);
					navyprecedent = navyprecedent.renvoiFils(mot[i]);
			}
			obj.occurrence =1;
			obj.valeur = v;
			navyprecedent.ajouterFils(mot[mot.length()-1],obj);
		else{
			obj.occurrence =1;
			obj.valeur = v;
			navy.modifierAssocie(mot[mot.length-1],obj);
		}
    }

template<typename Valeur>
    void Dictionnaire<Valeur>::associerMot(string mot, Valeur v){ // associe la valeur v à la chaîne mot dans le Dictionnaire, mot pouvant être présent ou absent du Dictionnaire
		Objet obj;
		Arbre<Valeur> navy = pandora;
		Arbre<Valeur> navyprecedent = NULL;
		int i = 0;
		while(navy != NULL && i < mot.length()){ 
			navyprecedent = navy;
			navy = pandora.renvoiFils(mot[i]);
			i++;
		}
		if(navy = NULL){
			for(i = i-1; i < mot.length()-1;i++){
					obj.occurence = 0;
					obj.valeur = "rien";
					navyprecedent.ajouterFils(mot[i],obj);
					navyprecedent = navyprecedent.renvoiFils(mot[i]);
			}
			obj.occurrence =1;
			obj.valeur = v;
			navyprecedent.ajouterFils(mot[mot.length()-1],obj);
		else{
			obj.occurrence = navy.renvoiAssocie().occurrence +1;
			obj.valeur = v;
			navy.modifierAssocie(mot[mot.length-1],obj);
		}
		
    }

template<typename Valeur>
    void Dictionnaire<Valeur>::supprimerMot(string mot){ // supprime l'éventuelle chaîne mot du Dictionnaire
		Objet obj;
		Arbre<Valeur> navy = pandora;
		Arbre<Valeur> navyprecedent = NULL;
		int i = 0;
		while(navy != NULL && i < mot.length()){ 
			navyprecedent = navy;
			navy = pandora.renvoiFils(mot[i]);
			i++;
		}
		if(navy != NULL){
			obj.occurrence = 0;
			obj.valeur = v;
			navy.modifierAssocie(mot[mot.length-1],obj);
		}
    }

template<typename Valeur>
    Objet Dictionnaire<Valeur>::valeurAssociee(string mot){ // donne la valeur correspondant à la chaîne mot // (supposée figurer dans le Dictionnaire)
		Objet obj;
		Arbre<Valeur> navy = pandora;
		int i = 0;
		while(i < mot.length()){
			navy = pandora.renvoiFils(mot[i]);
			i++;
		}
		return (navy.renvoiAssocie());
    }
 
template<typename Valeur>   
    void  Dictionnaire<Valeur>::motsLesPlusFrequents(int nombre){
		;
		
		
		
	}
		
