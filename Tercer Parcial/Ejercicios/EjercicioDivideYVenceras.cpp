#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Función para encontrar la sublista de máxima suma usando Divide y Vencerás
pair<int, pair<int, int>> maxCrossingSum(vector<int>& arr, int left, int mid, int right) {
    int sum = 0;
    int left_sum = INT_MIN, left_index = mid;
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
            left_index = i;
        }
    }
    
    sum = 0;
    int right_sum = INT_MIN, right_index = mid + 1;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
            right_index = i;
        }
    }
    
    return {left_sum + right_sum, {left_index, right_index}};
}

pair<int, pair<int, int>> maxSubArrayDivideAndConquer(vector<int>& arr, int left, int right) {
    if (left == right) {
        return {arr[left], {left, right}};
    }
    
    int mid = left + (right - left) / 2;
    auto left_result = maxSubArrayDivideAndConquer(arr, left, mid);
    auto right_result = maxSubArrayDivideAndConquer(arr, mid + 1, right);
    auto cross_result = maxCrossingSum(arr, left, mid, right);
    
    if (left_result.first >= right_result.first && left_result.first >= cross_result.first)
        return left_result;
    else if (right_result.first >= left_result.first && right_result.first >= cross_result.first)
        return right_result;
    else
        return cross_result;
}

int main() {
    int n;
    cout << "Ingrese el tamaño de la lista: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Ingrese los elementos de la lista: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    auto result = maxSubArrayDivideAndConquer(arr, 0, n - 1);
    cout << "Sublista con suma maxima: [";
    for (int i = result.second.first; i <= result.second.second; i++) {
        cout << arr[i] << (i < result.second.second ? ", " : "");
    }
    cout << "] con suma " << result.first << endl;
    
    system("pause");
    return 0;
}
