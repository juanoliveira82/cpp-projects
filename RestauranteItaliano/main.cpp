// Author: Juan Oliveira
#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#define NMESAS 25
#define NPEDITENS 50

int MatrizMesa[NMESAS][NPEDITENS]={0};
int m=0, p=0, numMesa;
float total=0;

void mostrarMenu(){
    cout<<"\n  Mesa selecionada: "<<numMesa<<endl;
    cout<<"\n       COMIDAS        "<<endl;
    cout<<"  Cod |       Descricao      | Valor (R$)"<<endl;
    cout<<"  01 - Ravioli de Queijo            50,00"<<endl;
    cout<<"  02 - Fettuccine de Camaroes       80,00"<<endl;
    cout<<"  03 - Cappeletti Recheado          40,00"<<endl;
    cout<<"  04 - Espaguete com frutos do mar  87,00"<<endl;
    cout<<"\n        BEBIDAS        "<<endl;
    cout<<"  11 - Cerveja Artesanal            15,00"<<endl;
    cout<<"  12 - Suco Organico Natural        12,00"<<endl;
    cout<<"  13 - Vinho do Porto               20,00"<<endl;
    cout<<"  14 - Grappa Italiana              17,00"<<endl;
    cout<<"\n        SOBREMESAS     "<<endl;
    cout<<"  21 - Mousse de Chocolate          06,00"<<endl;
    cout<<"  22 - Doce de Nozes                09,00"<<endl;
    cout<<"\n        CAFFE ESPRESSO "<<endl;
    cout<<"  31 - Espresso Macchiato           12,00"<<endl;
    cout<<"  32 - Caffe Latte                  08,00"<<endl;
    cout<<"  33 - Mocca                        11,00"<<endl;
    cout<<"  34 - Cappuccino                   13,00"<<endl;
}

int main(){
    cout << "\n\tSistema de Restaurante Italiano"<<endl;
    cout<<"\n  Nosso restaurante possui 25 mesas, numeradas de 0 a 24.";
    cout<<"\n  Cada mesa pode pedir ate 50 itens."<<endl;
    string Nome;
    cout << "\n  Informe o nome do cliente: ";
    getline(cin, Nome); system("cls");
    int maisPed;
    realizaMaisPedido:
    cout << "\n  Informe a mesa desejada: ";
    cin >> numMesa; system("cls");
    for(p; p < NPEDITENS; p++){
        mostrarMenu();
        int codItens;
        cout << "\n  Para finalizar o pedido, informe (0)"<<endl;
        cout << "\n  Informe o codigo dos produtos desejados: ";
        cin >> codItens; system("cls");
        switch(codItens){
            case 00:
            system("cls");
            goto finalizaPedido;
            case 01:
            cout << "\n  Ravioli de Queijo - R$ 50,00"<<endl;
            total = total + 50.00;
            break;
            case 02:
            cout << "\n  Fettuccine de Camarões - R$ 80,00"<<endl;
            total = total + 80.00;
            break;
            case 03:
            cout << "\n  Cappeletti Recheado - R$ 40,00"<<endl;
            total = total + 40.00;
            break;
            case 04:
            cout << "\n  Espaguete com frutos do mar - R$ 87,00"<<endl;
            total = total + 87.00;
            break;
            case 11:
            cout << "\n  Cerveja Artesanal - R$ 15,00"<<endl;
            total = total + 15.00;
            break;
            case 12:
            cout << "\n  Suco Organico Natural - R$ 12,00"<<endl;
            total = total + 12.00;
            break;
            case 13:
            cout << "\n  Vinho do Porto - R$ 20,00"<<endl;
            total = total + 20.00;
            break;
            case 14:
            cout << "\n  Grappa Italiana - R$ 17,00"<<endl;
            total = total + 17.00;
            break;
            case 21:
            cout << "\n  Mousse de Chocolate - R$ 6,00"<<endl;;
            total = total + 6.00;
            break;
            case 22:
            cout << "\n  Doce de Nozes - R$ 9,00"<<endl;;
            total = total + 9.00;
            break;
            case 31:
            cout << "\n  Espresso Macchiato - R$ 12,00"<<endl;;
            total = total + 12.00;
            break;
            case 32:
            cout << "\n  Caffe Latte - R$ 8,00"<<endl;;
            total = total + 8.00;
            break;
            case 33:
            cout << "\n  Mocca - R$ 11,00"<<endl;;
            total = total + 11.00;
            break;
            case 34:
            cout << "\n  Cappuccino - R$ 13,00"<<endl;;
            total = total + 13.00;
            break;
            default:
            cout << "\n  Informe um codigo de produto valido."<<endl;
            p = p-1;
            break;
        } // fim switch itens
        cout<<fixed<<setprecision(2)<<"\n  Total: "<<total<<"\n";
    } // fim for itens pedidos
    finalizaPedido:
    cout << "\n\tSistema de Restaurante Italiano"<<endl;
    cout << "\n  Pedido finalizado."<<endl;
    cout << "\n  Cliente: "<<Nome<<"."<<endl;
    cout << "\n  Total: "<<fixed<<setprecision(2)<<total<<" reais."<<endl;
    if(total==0.00)
        goto finalizaProg;
    else{
        float grana, troco;
        cout <<"\n  Informe o valor pago: ";
        cin >> grana;
        troco = grana-total;
        cout<<"\n  Troco: "<<troco<<" reais."<<endl;
    }
    finalizaProg:
    cout << "\n  Obrigado, volte sempre!"<<endl;
    cout << "\n  Deseja realizar mais um pedido?"<<endl;
    cout << "\n  (1) Sim - (Qualquer tecla) Nao    ";
    cin >> maisPed;
    if(maisPed==1)
        goto realizaMaisPedido;
    else
        system("cls");
    exit(0);
}
