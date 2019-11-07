#include <iostream>
#include <string.h>
#include <map>

using namespace std;

int numeropersonas;
int monto;
int cantidadregalados;

string nombre;
string amistades;

int main () {

    while (cin>>numeropersonas) {

        string nombres[numeropersonas];
        memset(nombres, 0, numeropersonas*sizeof(string));
        map<string, int> conjunto;

        for (int i = 0; i < numeropersonas; ++i) {
            cin>>nombre;
            nombres[i]=nombre;
            conjunto[nombre] = 0;
        }

        for (int j = 0; j < numeropersonas; ++j) {
            cin >>nombre>>monto>>cantidadregalados;

            if (cantidadregalados > 0) {
                //Le sumamos el residuo en caso no se pueda dividir exacto entre los que recibiran
                conjunto[nombre]=conjunto[nombre]+monto%cantidadregalados;
                //cout<<monto%cantidadregalados<<endl;
                //Le restamos al que regala
                conjunto[nombre]=conjunto[nombre]-monto;

                for (int k = 0; k < cantidadregalados; ++k) {

                    cin>>amistades;
                    //Le sumamos a los que recibieron regalos.
                    conjunto[amistades] = conjunto[amistades]+monto/cantidadregalados;
                }
            }

        }

        for (int l = 0; l < numeropersonas; ++l) {

            cout<<nombres[l]<<" "<<conjunto[nombres[l]]<<endl;

        }
    }
}