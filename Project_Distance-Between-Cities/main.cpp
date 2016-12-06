#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include "split.hpp"

using namespace std;

fstream arquivoCep, arquivoMunicip;

void abreArquivoCEP();
void abreArquivoMunicip();

int main(){
    string linha,cep1City,cep1CityEstate,cep2City,cep2CityEstate,City1Latitude,City1Longitude,City2Latitude,City2Longitude;
    int cep1, cep2;
    bool findCEP = false;
    cout<<"\n\tDistance Between Cities"<<endl;
    cout<<"\n  CEP 1: ";
    cin>>cep1;
    cout<<"\n  CEP 2: ";
    cin>>cep2;

    abreArquivoCEP();
    while (arquivoCep.good()){
        getline(arquivoCep, linha);
        if (linha.size()==0)
            continue;
        vector<string> v=split(linha, ';');
        int cepCompareStart = atoi(v[1].c_str());
        int cepCompareEnd = atoi(v[2].c_str());
        if(cep1 >= cepCompareStart && cep1 <= cepCompareEnd){
            cep1City = v[0];
            cep1CityEstate = v[0]+"-"+v[3];
            findCEP = true;
        }
    }
    if (!findCEP){
        cout << "Nenhuma cidade foi encontrada com esse CEP." << endl;
    }arquivoCep.close();
    abreArquivoCEP();
    while (arquivoCep.good()){
        getline(arquivoCep, linha);
        if (linha.size()==0)
            continue;
        vector<string> v=split(linha, ';');
        int cepCompareStart = atoi(v[1].c_str());
        int cepCompareEnd = atoi(v[2].c_str());
        if(cep2 >= cepCompareStart && cep2 <= cepCompareEnd){
            cep2City = v[0];
            cep2CityEstate = v[0]+"-"+v[3];
            findCEP = true;
        }
    }
    if (!findCEP){
        cout << "Nenhuma cidade foi encontrada com esse CEP." << endl;
    }arquivoCep.close();
    abreArquivoMunicip();
    while (arquivoMunicip.good()){
        getline(arquivoMunicip, linha);
        if (linha.size()==0)
            continue;
        vector<string> v=split(linha, ';');
        if(cep1City == v[3]){
            City1Latitude = v[1];
            City1Longitude = v[2];
            break;
        }
    }arquivoMunicip.close();
    abreArquivoMunicip();
    while (arquivoMunicip.good()){
        getline(arquivoMunicip, linha);
        if (linha.size()==0)
            continue;
        vector<string> v=split(linha, ';');
        if(cep2City == v[3]){
            City2Latitude = v[1];
            City2Longitude = v[2];
            break;
        }
    }arquivoMunicip.close();

    cout<<"\nCIDADE 1: "<<cep1City<<endl;
    cout<<"LATITUDE: "<<City1Latitude<<"\nLONGITUDE: "<<City1Longitude<<endl;

    cout<<"\nCIDADE 2: "<<cep2City<<endl;
    cout<<"LATITUDE: "<<City2Latitude<<"\nLONGITUDE: "<<City2Longitude<<endl;

    /* conta */
    DIST (A, B) = R ∗ acos(α + β ∗ δ);

    α = sen(City1Latitude) ∗ sen(City2Latitude);
    β = cos(City1Latitude) ∗ cos(City2Latitude);
    δ = cos(A.lon − B.lon);

    R = 6372, 795477598;

    cout<<"\n"<<cep1CityEstate<<" -> "<<cep2CityEstate<<endl;

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
