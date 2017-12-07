#include <iostream>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <string>
#include "split.hpp"

using namespace std;

fstream arquivoCep, arquivoMunicip;

void abreArquivoCEP();
void abreArquivoMunicip();

int main(){
    string linha,cep1City,cep1CityEstate,cep2City,cep2CityEstate,City1Latitude,City1Longitude,City2Latitude,City2Longitude;
    int cep1, cep2;
    bool findCEP = false;
    cout<<"\n\tDistancia entre cidades"<<endl;
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

    cout<<"\n Cidade 1 - Latitude: ";
    cout<<City1Latitude<<" Longitude: "<<City1Longitude<<endl;
    cout<<" Cidade 2 - Latitude: ";
    cout<<City2Latitude<<" Longitude: "<<City2Longitude<<endl;

    /* conta */
    double A,B,C,R,PI;
    double distCidades, Cid1Lat, Cid2Lat, Cid1Long, Cid2Long, CidLong, valorRadiano;
    PI = 3.1415926536;
    R = 6372.795477598;

    Cid1Lat = atof(City1Latitude.c_str());
    cout<<"\n Cidade 1 Latitude: "<<Cid1Lat<<endl;
    Cid1Long = atof(City1Longitude.c_str());
    cout<<"\n Cidade 1 Longitude: "<<Cid1Long<<endl;
    Cid2Lat = atof(City2Latitude.c_str());
    cout<<"\n Cidade 2 Latitude: "<<Cid2Lat<<endl;
    Cid2Long = atof(City2Longitude.c_str());
    cout<<"\n Cidade 2 Longitude: "<<Cid2Long<<endl;
    CidLong = Cid1Long - Cid2Long;
    cout<<"\n Longitude Overall: "<<CidLong<<endl;

    A = (sin(Cid1Lat)) * (sin(Cid2Lat));
    cout<<"\n"<<A<<endl;
    B = (cos(Cid1Lat)) * (cos(Cid2Lat));
    cout<<"\n"<<B<<endl;
    C = cos(CidLong);
    cout<<"\n"<<C<<endl;

    distCidades = R * (acos(A + B * C));
    cout<<"\n"<<distCidades<<endl;

    valorRadiano = distCidades * PI / 180;

    cout<< "\n dist: "<<valorRadiano<<" KM"<<endl;

    /* Cornélio Procópio-PR;86300000;Leópolis-PR;86330000; 10,120 KM */

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
