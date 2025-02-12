#include <iostream>
#include <vector>
#include <cmath>  

using namespace std;


int devolution_cambio(double x, const vector<double>& monedas) {
    if (x <= 0) {  
        return 0;
    } else {
        
        int c = floor(x / monedas[0]);
        cout << monedas[0] << " ";  
        
        x = round((x - c * monedas[0]) * 100) / 100.0;  
        
        
        return c + devolution_cambio(x, vector<double>(monedas.begin() + 1, monedas.end()));
    }
}

int main() {
    vector<double> monedas = {2.0, 1.0, 0.5, 0.2, 0.1};  
    double x = 5.34;  
    cout << "Cambio para " << x << ": ";
    devolution_cambio(x, monedas);
    cout << endl;

    return 0;
}



