#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "split.hpp"

using namespace std;

int main(){
    system("title Pesquisa de cidades");

    int opcao=1;
    while (opcao==1 || opcao==2){

    fstream arquivo;
    string linha;
    string namefile = "cidades.csv";
    arquivo.open(namefile.c_str(), ios::in | ios::app);
    cout<<"======================================================="<<endl;
    cout<<"||                      MENU                         ||"<<endl;
    cout<<"||  Pesquisar por CEP                    opcao [1]   ||"<<endl;
    cout<<"||  Pesquisar por sigla de estado        opcao [2]   ||"<<endl;
    cout<<"||  Fechar programa                      opcao [0]   ||"<<endl;
    cout<<"======================================================="<<endl;
    cin>>opcao;
system("cls");
    if(opcao==1){
        int cepPesq;
        cout << "\n  Informe o CEP: ";
        cin >> cepPesq;
        while (arquivo.good()) {
            getline(arquivo, linha);
            vector<string> v = split(linha, ';');
            for(int i=0;i<v.size();i++){ // pesquisa cep
                int cepCompareStart = atoi(v[1].c_str());
                int cepCompareEnd = atoi(v[2].c_str());
                if(cepPesq >= cepCompareStart && cepPesq <= cepCompareEnd){
                    cout<<"\n  Cidade: " << v[0] << "\n  Estado: " << v[3] << endl;
                    break;
                }
            }
        }
    };
    if(opcao==2){
        string siglaPesq;
        cout << "\n  Informe a sigla do estado: ";
        cin >> siglaPesq;
        while (arquivo.good()) {
            getline(arquivo, linha);
            vector<string> v = split(linha, ';');
            for(int i=0;i<v.size();i++){ // pesquisa sigla estado
                if(v[3]==siglaPesq){
                    cout<<"\n  Cidade: "<<v[0]<<endl;
                    break;
                }
            }
        }
    };
    arquivo.close();
    if (opcao==0){
        break;
    }

    }


    return 0;
}
