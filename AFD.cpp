#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
using namespace std;

int main(){
    fstream file;
    string estado, alfabeto, i, F, qtPalavras;
    string *palavras = NULL;
    string auxToTransit;
    string *transit = NULL;

    string quantTransit;


    file.open("automato1.txt",ios::in);

    if(file.is_open()){
        getline(file,estado); //Pega o estado na linha 1;
        getline(file,alfabeto); //Pega o alfabeto na linha 2;
        getline(file,i); //Pega o estado inicial na linha 3;
        getline(file,F); //Pega o estado final na linha 4;
        getline(file,qtPalavras); //Pega o número de palavras na linha 5; (string) --> 3 palavras
        
        palavras = new string[stoi(qtPalavras)]; //Aloca a quantidade de palavras;

        for(int j=0; j<stoi(qtPalavras); j++){
            getline(file,palavras[j]); //Preenche a lista de palavras automaticamente;
        }

        getline(file,quantTransit); //Pega quantas transições;

        transit = new string[stoi(quantTransit)];

        for(int j=0; j<stoi(quantTransit); j++){
            getline(file,transit[j]); //Preenche a lista de transições automaticamente;
        }
        
    }
    cout << "Estado " << estado << endl;
    cout << "Alfabeto " << alfabeto << endl;
    cout << "Est.Inicial " << i << endl;
    cout << "Est.Final " << F << endl;
    cout << "QuantPalavras " << qtPalavras << endl;
    cout << "Palavra 1 " << palavras[0] << endl;
    cout << "Palavra 2 " << palavras[1] << endl;
    cout << "Palavra 3 " << palavras[2] << endl;

    cout << "QuantTransit " << quantTransit << endl;
    cout << "Transicao " << transit[4] << endl;

    file.close();
    delete [] palavras;
    delete [] transit;
    return 0;
}