#include <iostream>
using namespace std;

class celula
{
private:
	string nome;
	float mediaFinal;
	celula * proxima;
public:
	celula()
	{
		proxima = NULL;
	}
	celula(string n)
	{
		nome = n;
	}
	celula(string n, celula *p)
	{
		nome = n;
		proxima = p;
	}
	celula(string n, float m, celula *p){
		nome = n;
		mediaFinal = m;
		proxima = p;
	}
	string getNome()
	{
		return nome;
	}
	void setNome(string n)
	{
		nome = n;
	}

	celula * getProxima()
	{
		return proxima;
	}

	void setProxima(celula * l)
	{
		proxima = l;
	}
	float getMediaFinal(){
		return mediaFinal;
	}
	void setMediaFinal(float m){
		mediaFinal = m;
	}
};

class lista{
	private: 
		celula *inicio;
    
 	public:
 		lista(){
			 inicio = NULL;
		 }
		 
		 	celula *getInicio(){
		return inicio;
	}
	
	void inserirInicio(string nome){
		celula *nova = new celula();
		nova->setNome(nome);
		nova->setProxima(inicio);
		inicio = nova;
	}
	
	 void inserirFim(string n){
	
		if(inicio == NULL){
			inserirInicio(n);
		}
		else
		{
			celula *aux = inicio;
			while(aux->getProxima() != NULL)
			{
				aux = aux->getProxima();
			}
			celula *nova = new celula(n, NULL);
			aux->setProxima(nova); 
		}
	}
	
	void imprimir(){
		if(inicio == NULL){
			cout << "Lista vazia";
		}
		else{
			celula *aux = inicio;
			while(aux!=NULL){
				cout << aux->getNome() <<endl;
				aux = aux->getProxima();
			}
		}
	}
	
	void esvaziar(){
		celula *aux = inicio;
		while(aux != NULL){
			inicio = inicio -> getProxima();
			delete aux;
			aux = inicio;
		}
		cout << endl << "Lista esvaziada com sucesso!";
	}
	
};


int main(){
	lista alunos;
	alunos.inserirInicio("Christopher");
	alunos.inserirInicio("Jose");
	alunos.inserirFim("Joao");
	alunos.imprimir();

	
	
	
	
	return 0;
}