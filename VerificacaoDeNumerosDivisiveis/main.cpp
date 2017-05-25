#include <iostream>

using namespace std;

int main(){
    cout <<"\n\tVerificacao de numeros divisiveis"<< endl;
    int x, y;
    cout <<" Insira um numero para verificacao: ";
    cin >> x;
    y = x / 2;
    cout << 1 << endl;
    for(int i=2; i<=y; i++){
        if(x%i==0){
            cout << i << endl;
        }
    }
    return 0;
}
// Made by: Juan Carlos Cardoso de Oliveira.
