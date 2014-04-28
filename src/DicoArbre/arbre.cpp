template<typename T, typename Association>
Arbre<T,Association>::Arbre(T etiquette,Association assoc){
		etq = etiquette;
		nbFils = 0;
		associe = assoc;
		cout<<"assoc occu :"<<assoc.occurrence<<endl;
}

template<typename T, typename Association>
void Arbre<T,Association>::modifierAssocie(Association assoc){
	cout<<"DEBUT MODIF ASSOCIE"<<endl;
	cout<<"occu :"<<this->associe.occurrence<<" contre "<<assoc.occurrence<<endl;
		this->associe = assoc;
}

template<typename T, typename Association>
bool Arbre<T, Association>::estFeuille(){
	return (this->nbFils==0);
}

template<typename T, typename Association>
T Arbre<T, Association>::renvoiEtq(){
	return etq;
}

template<typename T, typename Association>
Arbre<T,Association> * Arbre<T, Association>::renvoiFils(T etiquette){
	Arbre<T,Association> * fils = NULL;
	bool trouve = false;
	int ii;
	cout<<"DEBUT BOUCLE RENVOIFILS"<<endl;
	cout<<"nbFils"<<this->nbFils<<endl;
	for(int i=0; i<this->nbFils && trouve == false ; i++){
		cout<<"boucle nb"<<i<<" || "<<this->lesFils[i]->renvoiEtq()<<endl;
		if(this->lesFils[i]->renvoiEtq() == etiquette){
			 fils = this->lesFils[i];
			 cout<<"i :"<<i<<endl; 
			 ii = i;
			 trouve = true;
			 cout<<"renvoi voulu :"<<etiquette<<" || renvoi fait :"<<this->lesFils[ii]->etq<<endl;
			}
	}
		
	
	return fils;
}

/*template<typename T, typename Association>
void Arbre<T, Association>::trousseauEtq(vector<K> * clfs, int &N){
    int i,j,taille;
        for(i = 0; i < nbFils; i++) { //on parcours tous les arbres fils
			clfs->push_back(lesFils[i].etq);
        }
}*/

template<typename T, typename Association>
void Arbre<T, Association>::ajouterFils(T etiquette,Association assoc){
	this->lesFils.push_back(new Arbre<T,Association>(etiquette,assoc));
	this->nbFils = this->nbFils+1;
}

template<typename T, typename Association>
Association Arbre<T,Association>::renvoiAssocie(){
	cout<<"DEBUT RENVOI ASSOCIE"<<endl;
	return (this->associe);
}

template<typename T, typename Association>
vector<Arbre<T,Association>*> Arbre<T,Association>::renvoiTousLesFils(){
	return (this->lesFils);
}


