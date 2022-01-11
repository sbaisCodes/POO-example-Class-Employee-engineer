#include<iostream>
#include<cstdlib>
#include<cstring>

#ifndef EMPLOYE_H
#define EMPLOYE_H
using namespace std;

// PARTIE A
class Employe{
	private: 
	   char* nom_employer;
	   double salary;
	
	public:
		Employe(char* name = "NONE"){
			salary = 0.0;
			nom_employer = (char*)malloc(sizeof(name));
			strcpy(nom_employer, name);
		}
		Employe(char* name, double sal){
			salary = sal;
			nom_employer = (char*)malloc(sizeof(name));
			strcpy(nom_employer, name);
		}
		 friend  ostream& operator<<(ostream& out, const Employe& E);
		double virtual salaire() = 0;
		void saisir_Emplo(){
			cout<< "Enter name of employe: ";
		     cin>>nom_employer;
		     cout<< "Enter salaire : ";
		     cin>>salary;
		}
		char* getNom(){
			return nom_employer;
		}
		double getEmpSalary(){
			return salary;
		}
};

ostream& operator<<(ostream& out, const Employe& E){
	out<<"\n NOM EMPLOYER : "<< E.nom_employer <<" ------  _SALAIRE = "<< E.salary;
	
	return out;
}



// PARTIE B // we can keep this class empty :)
class ExpManqCode{
	public:
		char* nomInge;
		ExpManqCode(char* name){
			nomInge = (char*)malloc(sizeof(name));
			strcpy(nomInge, name);
		}
		
};


class Ingenieur : public Employe{
	protected : 
	    int code;
	    char* nom_ing;
	public:
		Ingenieur(){
			code = 0;
			nom_ing = (char*)malloc(sizeof("NONE"));
			strcpy(nom_ing, "NONE");
		}
		Ingenieur(char* name, int _code = 0){
			code = _code;
			nom_ing = (char*)malloc(sizeof(name));
			strcpy(nom_ing, name);
		}
		void saisirCode(int _code){
			if(_code == 0){
				ExpManqCode objExp(nom_ing);
				cout<<"\n-- i am in the saisirCode: il y a exception \n";
				cout<<"NOM : "<< nom_ing<< "\n";
				throw objExp;
			}else{
				code = _code;
			}
		}
		
		char* getNom_ing(){
			return nom_ing;
		}
		
		void setNom_ing(char* name){
			nom_ing = (char*)malloc(sizeof(name));
			strcpy(nom_ing, name);
		}
		
		double salaire(){
			cout<<">Salaire Ingenieur : 10 000DH"<<endl;
		}
		
		friend ostream& operator<<(ostream& flux, const Ingenieur& ing);
		
};


inline ostream& operator<<(ostream& out, const Ingenieur& ing){
	out<<"\n NOM Ingenieur : "<< ing.nom_ing <<" ------  _Code = "<< ing.code<<endl;
	
	return out;
}




#endif
