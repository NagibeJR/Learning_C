#include <iostream>
#include <math.h>
using namespace std;

void Circunferencia(float& raio, float& area, float& areafinal)
{
    area = (3.14*raio);
    areafinal = (area*area);
    }
int main()
{
    float raio,area = 0, areafinal = 0;
    cin >> raio;

    Circunferencia(raio,area,areafinal);
    cout << "A area do circulo e: " << areafinal << endl;
    return 0;
}
