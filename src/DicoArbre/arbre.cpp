Arbre<T,Association>::Arbre(T etq,assoation assoc){
		this->etq=etq;
		associe = assoc;
}

void Arbre<T,Association>::modifierAssocie(Assocation assoc){
		this->associe = assoc;
}
template<typename T, typename Association>
bool Arbre<T, Association>::estFeuille(Arbre a){
	return nbFils==0;
}

template<typename T, typename Association>
T Arbre<T, Association>::etq(Arbre a){
	return etq;
}

template<typename T, typename Association>
Arbre Arbre<T, Association>::renvoiFils(T etq){
	Arbre fils = NULL;
	for(int i=0; i<nbFils; i++){
		if(lesFils[i].etq = etq) fils = tab[i]; 
	}
	
	return fils;
}

template<typename T, typename Association>
Arbre Arbre<T, Association>::ajouterFils(T etq,Association assoc){
	lesFils[nbFils] = new Arbre(etq,assoc);
	++nbFils;
}

template<typename T, typename Association>
Association Arbre<T, Association>::renvoiAssocie(){
	return associe;
}


