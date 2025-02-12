#include <iostream>
using namespace std;


int digitos_impares(int n) {
    if (n == 0) {
        return 0;  
    } else {
       
        int current_digit_is_odd = (n % 10) % 2 != 0 ? 1 : 0;  
        return current_digit_is_odd + digitos_impares(n / 10);  
    }
}

int main() {
    int n = 727368238;  
    cout << "El número de dígitos impares en " << n << " es: " << digitos_impares(n) << endl;
    system("pause");
    return 0;
}



