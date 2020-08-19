#include <iostream>
using namespace std;


class celula{
    private: 
    string nome;
    string sobrenome;

   public:
    celula()
    {
        cout << "Passou no método contrutor" << endl;
        nome = "Fulano";
        sobrenome = "De Tal";
    }
    
    celula(string s){
        cout << "Passou pelo construtor com parametro\n";
        sobrenome = s;
    }
    
    celula(string n, string s){
        nome = n;
        sobrenome = s;
    }
    
    void imprimirNome()
    {
        cout << nome << endl;
    }

    void setNome(string n)
    {
        nome = n;
    }
    string getNome()
    {
        return nome;
    }

    void setSobrenome(string s)
    {
        sobrenome = s;
    }

    string getSobrenome()
    {
        return sobrenome;
    }

};




int main(){

     celula teste("Christopher", "Antony");
    cout << "Seu nome completo: " << teste.getNome() << " " << teste.getSobrenome();
    teste.setNome("Josevaldo");
    cout << "Seu nome completo: " << teste.getNome() << " " << teste.getSobrenome();
    return 0;
}