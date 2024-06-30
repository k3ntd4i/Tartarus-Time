#include<iostream>
#include<math.h>
#include<string.h>

using namespace std;

int main()
{
    long double combinaciones_por_segundo = 0, caracteres_disponibles = 0, longitud_contrasenia = 0, operador_tiempo[5] = {60,60,24,365};
    long double  a = 0, tiempo = 0;
    long int tiempo_entero = 0, n = 0;
    char unidad_tiempo[5][10] = {"segundo", "minuto", "hora", "dia", "anio"};

    cout<<"[+] Digite la cantidad de caracteres diferentes disponibles para usar: "; cin>>caracteres_disponibles;
    cout<<"[+] Digite la longitud de la contrasenia: "; cin>>longitud_contrasenia;
    cout<<"[+] Digite el numero de combinaciones por segundo del ataque: "; cin>>combinaciones_por_segundo;

    a = pow(caracteres_disponibles, longitud_contrasenia);
    tiempo = a / combinaciones_por_segundo;

    for (int i = 0; i < 4; i++)
    {
        if (tiempo >= 60 && i < 2)
        {
            tiempo /= operador_tiempo[i];
            n = i + 1;
        }
        else if (tiempo >= 24 && i < 3)
        {
            tiempo /= operador_tiempo[i];
            n++;
        }
        else if (tiempo >= 365)
        {
            tiempo /= operador_tiempo[i];
            n++;
        }
    }

    cout<<"\n[+] El tiempo que tomaria una contrasenia de "<<longitud_contrasenia<<" caracteres en ser descubierta es de: ";

    if (tiempo > 1)
    {
        tiempo_entero = tiempo;
        tiempo = tiempo_entero;
    }
    
    cout<<"\n[+] "<<tiempo<<" "<<unidad_tiempo[n];
    if (tiempo != 1)
    {
        cout<<"s\n\n";
    }
    else
    {
        cout<<"\n\n";
    }

    return 0;
}