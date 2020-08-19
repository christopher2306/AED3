#include <iostream>

using namespace std;

class celula
{
private:
	string nome;
	string sexo;
	int idade;
	char alcool;
	celula * proxima;
public:
	celula()
	{
		proxima = NULL;
	}
	celula(string n, char s, int i, char resp)
	{
		nome = n;
		sexo = s;
		idade = i;
		alcool = resp;
		
	}
	
	celula(string n, string s, int i, char resp, celula *p){
		nome = n;
		sexo = s;
		idade = i;
		alcool = resp;
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
	
		string getSexo()
	{
		return sexo;
	}
	void setSexo(string s)
	{
		sexo = s;
	}
	
		int getIdade()
	{
		return idade;
	}
	void setIdade(int i)
	{
		idade = i;
	}
	
		char getAlcool()
	{
		return alcool;
	}
	void setAlcool(char resp)
	{
		alcool = resp;
	}

	celula * getProxima()
	{
		return proxima;
	}

	void setProxima(celula * l)
	{
		proxima = l;
	}
};


class lista
{
private:
	celula * inicio;

public:
	lista()
	{
		inicio = NULL;
	}
	lista(celula *i)
	{
		inicio = i;
	}
	~lista()
	{
		esvaziar();
		cout << "\nPassou no metodo destrutor";
	}
	celula * getInicio()
	{
		return inicio;
	}

	void setInicio(celula *i)
	{
		inicio = i;
	}

	void inserirInicio(string n,string s, int i, char resp )
	{
		celula *nova = new celula;
		nova->setNome(n);
		nova->setSexo(s);
		nova->setIdade(i);
		nova->setAlcool(resp);
		nova->setProxima(inicio);
		inicio = nova;
	}

	void inserirFim(string n, string s, int i, char resp)
	{
		celula *nova = new celula(n, s, i, resp, NULL);
		//nova->setNome(n);
		//nova->setProxima(NULL);
		if(inicio == NULL)
		{
			inicio = nova;
		}
		else
		{
			celula *aux = inicio;
			while(aux->getProxima() != NULL)
			{
				aux = aux->getProxima();
			}
			aux->setProxima(nova);
		}
	}


	void imprimir()
	{
		if(inicio == NULL)
		{
			cout << "Lista vazia.\n";
		}
		else
		{
			celula *aux = inicio;
				cout << "SEJA BEM VINDO AO NOSSO CHURRASCO" << endl << "Segue a lista dos convidados: " << endl;
			while(aux != NULL)
			{
			
				cout << aux->getNome() << endl << "Qual o sexo?" << aux->getSexo() << endl << "Qual a idade?" << aux->getIdade() << endl << "Você ingeri bebidas alcoolicas?" << " " << aux->getAlcool() << endl << endl;
				aux = aux->getProxima();
			}
		}
	}

	void esvaziar()
	{
		celula *aux = inicio;
		while(aux != NULL)
		{
			inicio = inicio->getProxima();
			delete aux;
			aux = inicio;
		}
		cout << "\nLista esvaziada com sucesso.";
	}


};

int main()
{
	lista listaChurrasco;
	listaChurrasco.inserirInicio("Christopher", "M", 20, 's');
	listaChurrasco.inserirInicio("Savio", "M", 19, 'n');
	listaChurrasco.inserirInicio("Eduardo", "M", 19, 's');
	listaChurrasco.inserirInicio("Giovani", "M", 22, 's');
	listaChurrasco.imprimir();
	listaChurrasco.esvaziar();

	return 0;
}