#include <iostream>

 

using namespace std;

 

class celula
{
private:
    string nome;
    celula *proxima;
public:
    celula(){
        proxima = NULL;    
    }
    
 	celula(string n, celula *proxima){
		 setNome(n);
		 setProxima(proxima);
		 
	 }
    
    void setNome(string n){
        nome = n;
    }
    
    string getNome(){
        return nome;
    }
    
    void setProxima(celula *c){
        proxima = c;
    }
    
    celula * getProxima(){
        return proxima;
    }
    
    
};

 

class lista
{
private:
    celula * inicio;
public:
    lista(){
        inicio = NULL;
    }
    
    celula * getInicio(){
        return inicio;
    }
    
    void inserirInicio(string nome){
        celula * nova = new celula(nome, inicio);
        inicio = nova;
    }
    
    void inserirFim(string n){
		celula *nova = new celula;
		nova->setNome(n);
		nova->setProxima(NULL);
		if(inicio == NULL){
			inicio = nova;
		}
		else{
			celula *aux = inicio;
			while(aux->getProxima() != NULL){
				aux = aux->getProxima();
			}
		}
	}
    
    
    
    void imprimir(){
        if(inicio == NULL){
            cout << "Lista vazia" << endl;
        }
        else{
            celula *aux = inicio;
            while(aux != NULL){
                cout << aux->getNome() << endl;
                aux = aux->getProxima();
            }
        }
    }
    
};

 

int main()
{
    lista alunos;
    alunos.inserirInicio("Mailson");
    alunos.inserirInicio("Queiroz");
    alunos.inserirInicio("Miguel");
    alunos.inserirFim("Ana");
    alunos.imprimir();
    return 0;
}