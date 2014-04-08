#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main(){
	string n1 = "n1";
	string n2 = "n2";
	bool eras = false;
	
	if(typeid(n1)==typeid(string))
		eras = true;
	cout<<eras<<endl;
	
	return 0;
}
