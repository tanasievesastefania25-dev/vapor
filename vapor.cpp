#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
 
 using namespace std;

 class Vapor {
	 private:
	 int capacitate;
	 int nrPersoaneImbarcate;
	 int* varstePasageri;
	 char* numeCapitan;
	 int nrBilete;
	 public:
		 Vapor() {
			 this->capacitate=100;
			 this->nrPersoaneImbarcate=5;
			 this->varstePasageri=new int[5];
			 this->varstePasageri[0]=12;
			 this->varstePasageri[1]=34;
			 this->varstePasageri[2]=56;
			 this->varstePasageri[3]=23;
			 this->varstePasageri[4]=59;
			 this->numeCapitan=new char[strlen("numeNA")+1];
			 strcpy(this->numeCapitan, "numeNA");
			 this->nrBilete=10;

	 }
		 Vapor(int capacitateInit, int nrPersoaneImbarcateInit, const int* varstePasageriInit, const char* numeCapitanInit, int nrBileteInit)
		 {
			 if (capacitateInit > 0)
				 this->capacitate = capacitateInit;
			 else
				 this->capacitate = 0;

			 if (nrPersoaneImbarcateInit >= 0 && nrPersoaneImbarcateInit <= this->capacitate)
				 this->nrPersoaneImbarcate = nrPersoaneImbarcateInit;
			 else
				 this->nrPersoaneImbarcate = 0;

			 if (this->nrPersoaneImbarcate > 0 && varstePasageriInit != nullptr)
			 {
				 this->varstePasageri = new int[this->nrPersoaneImbarcate];
				 for (int i = 0; i < this->nrPersoaneImbarcate; i++)
				 {
					 this->varstePasageri[i] = varstePasageriInit[i];
				 }
			 }
			 else
			 {
				 this->nrPersoaneImbarcate = 0;
				 this->varstePasageri = nullptr;
			 }

			 if (numeCapitanInit != nullptr && strlen(numeCapitanInit) > 0)
			 {
				 this->numeCapitan = new char[strlen(numeCapitanInit) + 1];
				 strcpy(this->numeCapitan, numeCapitanInit);
			 }
			 else
			 {
				 this->numeCapitan = new char[strlen("NA") + 1];
				 strcpy(this->numeCapitan, "NA");
			 }

			 if (nrBileteInit >= 0)
				 this->nrBilete = nrBileteInit;
			 else
				 this->nrBilete = 0;
		 }
		 ~Vapor()
		 { 
			 if(this->numeCapitan !=nullptr)
			 {
				 delete[] this->numeCapitan;
				 
		 }
		 if (this->varstePasageri != nullptr)
		 {
			 delete[] this->varstePasageri;
		 }
		 }
		 Vapor(const Vapor& v) {
		 this->capacitate=v.capacitate;
		 this->nrPersoaneImbarcate=v.nrPersoaneImbarcate;
		 this->nrBilete=v.nrBilete;
		 this->numeCapitan=new char[strlen(v.numeCapitan)+1];
		 strcpy(this->numeCapitan, v.numeCapitan);
		 if(v.varstePasageri != nullptr && v.nrPersoaneImbarcate >0)
		 { 
		 this->varstePasageri=new int[v.nrPersoaneImbarcate];
		 for (int i = 0; i < v.nrPersoaneImbarcate; i++)
		 {
			 this->varstePasageri[i] = v.varstePasageri[i];
		 }
		 }
		 else
		 {
			 this->varstePasageri=nullptr;
		 }
		 }
		 char* getNumeCapitan()
		 {
			 char* copieNumeCapitan=new char[strlen(this->numeCapitan)+1];
			 strcpy(copieNumeCapitan,this->numeCapitan);
			 return copieNumeCapitan;

		 }
		 void setNumeCapitan( const char* numeCapitanNou)
		 {
		 if(numeCapitanNou != nullptr)
		 { 
			 if (this->numeCapitan != nullptr)
			 {
				 delete[]this->numeCapitan;

		 }
		 this->numeCapitan=new char[strlen(numeCapitanNou)+1];
		 strcpy(this->numeCapitan, numeCapitanNou);
		 }
		 }
		 int getNrBilete()
		 {
			 return this->nrBilete;
		 }
		 void setNrBilete(int nrBileteNoi)
		 {
			 if (nrBileteNoi >= 0)
			 {
				 this->nrBilete=nrBileteNoi;
			 }
		 }
		 Vapor& operator=(const Vapor& v)
		 {
			 if (numeCapitan != nullptr)
			 {
				 delete[] this->numeCapitan;
			 }
			 
			 if (varstePasageri !=nullptr)
			 {
				 delete[] this->varstePasageri;

			 }
			
			 this->capacitate=v.capacitate;
			 this->nrPersoaneImbarcate=v.nrPersoaneImbarcate;
			 this->nrBilete=v.nrBilete;
			 this->numeCapitan=new char[strlen(v.numeCapitan)+1];
			 strcpy(this->numeCapitan, v.numeCapitan);
			 if (v.varstePasageri != nullptr && v.nrPersoaneImbarcate > 0)
			 {
              this->varstePasageri=new int[v.nrPersoaneImbarcate];
			  for (int i = 0; i < v.nrPersoaneImbarcate;i++)
			  {
				  this->varstePasageri[i]=v.varstePasageri[i];
				  
			  }
			  
			 }
			 return *this;
		 }
		 friend ostream& operator<<(ostream& out, const Vapor& v)
		 {
			 out<<v.capacitate<<", ";
			 out<<v.nrBilete<<", ";
			 out<<v.nrPersoaneImbarcate<<", ";
			 for (int i = 0;i < v.nrPersoaneImbarcate;i++)
			 {
				 out<<v.varstePasageri[i]<<"' ";
			 }
			 out<<v.numeCapitan<<", ";
			 out<<v.varstePasageri<<", ";
			 return out;
		 }
		 
 };
 int main()
 {
	 Vapor v1;

	 int varste[]={12,34,56,23,59};
	 Vapor v2(100,5,varste,"Popescu",10);
	 Vapor v3(0,50,nullptr,"",-3);
	 Vapor v4=v2;

	 
	 cout << v1 << endl;
	 cout << v2 << endl;
	 cout << v3 << endl;
	 cout << v4 << endl;


 }