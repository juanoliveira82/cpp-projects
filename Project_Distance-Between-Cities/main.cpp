#include <iostream>
#include <cstdlib>
#include <fstream>
#include "split.hpp"

using namespace std;

fstream arquivoCep, arquivoMunicip;

void abreArquivoCEP();
void abreArquivoMunicip();

int main(){
    string linha1, linha2, cep1City, cep1CityEstate, cep2City, cep2CityEstate;

    int cep1, cep2;
    bool findCEP = false;

    cout<<"\n  CEP 1: "<<endl;
    cin>>cep1;
    cout<<"\n  CEP 2: "<<endl;
    cin>>cep2;

    abreArquivoCEP();
    while (arquivoCep.good()){
        getline(arquivoCep, linha1);
        if (linha1.size()==0)
            continue;
        vector<string> vCEP=split(linha1, ';');
        int cepCompareStart = atoi(vCEP[1].c_str());
        int cepCompareEnd = atoi(vCEP[2].c_str());
        if(cep1 >= cepCompareStart && cep1 <= cepCompareEnd){
            cep1City = vCEP[0];
            cep1CityEstate = vCEP[0]+"-"+vCEP[3];
            findCEP = true;
        }
    }
    if (!findCEP){
        cout << "Nenhuma cidade foi encontrada com esse CEP." << endl;
    }arquivoCep.close();

    abreArquivoCEP();
    while (arquivoCep.good()){
        getline(arquivoCep, linha1);
        if (linha1.size()==0)
            continue;
        vector<string> vCEP=split(linha1, ';');
        int cepCompareStart = atoi(vCEP[1].c_str());
        int cepCompareEnd = atoi(vCEP[2].c_str());
        if(cep2 >= cepCompareStart && cep2 <= cepCompareEnd){
            cep2City = vCEP[0];
            cep2CityEstate = vCEP[0]+"-"+vCEP[3];
            findCEP = true;
        }
    }
    if (!findCEP){
        cout << "Nenhuma cidade foi encontrada com esse CEP." << endl;
    }arquivoCep.close();

    /*
    ele vai procurar ASB
    qnd encontrar tem isso aq:
    4731;-22,88;-49,23;AGUAS DE SANTA BARBARA;SP
    ID;LATITUDE;LONGITUDE;MUNICIPIO;UF
    0    1        2            3    4
    */

    abreArquivoMunicip();
    while (arquivoMunicip.good()){
        getline(arquivoMunicip, linha2);
        if (linha2.size()==0)
            continue;
        vector<string> vMunicip=split(linha2, ';');
        if(cep1City == vMunicip[3]){
            cout<<"\nEncontrou a cidade 1\n";
            break;
        }
    }arquivoMunicip.close();

    abreArquivoMunicip();
    while (arquivoMunicip.good()){
        getline(arquivoMunicip, linha2);
        if (linha2.size()==0)
            continue;
        vector<string> vMunicip=split(linha2, ';');
        if(cep2City == vMunicip[3]){
            cout<<"\nEncontrou a cidade 2\n";
            break;
        }
    }arquivoMunicip.close();

    cout <<cep1CityEstate<<" -> "<<cep2CityEstate<<endl;

    return 0;
}

void abreArquivoCEP(){
    string cepCsv = "cep.csv";
    arquivoCep.open(cepCsv.c_str(), ios::in);
};
void abreArquivoMunicip(){
    string municipCsv = "municipios_br.csv";
    arquivoMunicip.open(municipCsv.c_str(), ios::in);
};
