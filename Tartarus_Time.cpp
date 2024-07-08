#include <iostream>
#include <cmath>
#include <string>

int main()
{
    long double combinaciones_por_segundo{};
    unsigned int caracteres_disponibles{};
    unsigned int longitud_contrasenia{};

    std::cout << "[+] Digite la cantidad de caracteres diferentes disponibles para usar: ";
    std::cin >> caracteres_disponibles;

    std::cout << "[+] Digite la longitud de la contrasenia: ";
    std::cin >> longitud_contrasenia;
    
    std::cout << "[+] Digite el numero de combinaciones por segundo soportados en el ataque: ";
    std::cin >> combinaciones_por_segundo;
    combinaciones_por_segundo = std::abs(combinaciones_por_segundo);

    long double permutacion{ std::pow(caracteres_disponibles, longitud_contrasenia) };
    long double tiempo{ permutacion / combinaciones_por_segundo }; // segundos

    int operador_tiempo[4] { 60, 60, 24, 365 };
 
    std::string unidad_tiempo[5] { "segundo", "minuto", "hora", "dia", "anio" };
    int indice_unidad_tiempo{ 0 };

    for (int i{0}; (i < 4) && (tiempo >= operador_tiempo[i]); i++)
    {
        tiempo /= operador_tiempo[i];
        indice_unidad_tiempo++;
    }

    std::cout
        << "\n[+] El tiempo que tomaria romper una contrasenia con las condiciones digitadas es de: "
        << "\n[+] " << tiempo << ' ' << unidad_tiempo[indice_unidad_tiempo];

    (tiempo == 1) ? std::cout << '\n' : std::cout << "s\n";

    return 0;
}
