#include <iostream>
#include<cstdlib>
#include<cstring>
#include "employe.h"
using namespace std;
int main(int argc, char** argv) {
	
	
	try{
		Ingenieur Ing1("salah"), Ing2, Ing3("Sbai", 17);
		cout<<"\n ---- Objet creers ------ \n";
		cout<<"Ing1(\"salah\"), Ing2, Ing3(\"Sbai\", 17) \n";
	  Ing2.saisir_Emplo();
	  Ing2.saisirCode(1);
	  Ing2.setNom_ing("Elon");
	  cout<<Ing2<<endl;
	  cout<<"Salaire Ing2: "<< Ing2.getEmpSalary();
	  Ing1.saisirCode(53);
	  cout<<Ing1;
	
	  cout<<Ing3<<endl;
		
	}
	catch(ExpManqCode l){
		cout<<"\tManque de code"<<endl;
		
	}
	
	
	
	
	return 0;
}
