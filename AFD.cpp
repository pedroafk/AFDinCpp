#include <iostream>
#include <iterator>
#include <map>
#include <fstream>
#include <string>
using namespace std;

int main(){
    map<int,char> afd;
    fstream file;
    file.open("automato1.txt",ios::in);
    if(file.is_open()){
        string teste;
        while(getline(file,teste)){
            cout << teste << endl;
        }
    }

    file.close();
    return 0;
}