#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
using namespace std;

void constroiAutomato(string estado, string alfabeto, string i, string F, string *palavras, string *transit,
string qtPalavras, string quantTransit){
    // cout << "Estado " << estado << endl; //1234e
    // cout << "Alfabeto " << alfabeto << endl; //ab
    // cout << "Est.Inicial " << i << endl; //1
    // cout << "Est.Final " << F << endl; //4
    // cout << "QuantPalavras " << qtPalavras << endl; //3
    // cout << "Palavra 1 " << palavras[0] << endl; //abaaa
    // cout << "Palavra 2 " << palavras[1] << endl; //abbababa
    // cout << "Palavra 3 " << palavras[2] << endl; //abaabaaba
    // cout << "QuantTransit " << quantTransit << endl; //5
    // cout << "Transicao " << transit[4] << endl; //ee
}

int main(){
    fstream file;
    string estado, alfabeto, i, F, qtPalavras, quantTransit;
    string *palavras = NULL;
    string *transit = NULL;


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

    constroiAutomato(estado,alfabeto,i,F,palavras,transit, qtPalavras, quantTransit);
    

    file.close();
    delete [] palavras;
    delete [] transit;
    return 0;
}