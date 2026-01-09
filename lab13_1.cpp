#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}
void stat(const double a[], int n, double result[]) {
    double sum = 0.0, geo_log_sum = 0.0, harm_sum = 0.0;
    double max_val = a[0], min_val = a[0];
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        geo_log_sum += log(a[i]);
        harm_sum += 1.0 / a[i];
        if (a[i] > max_val) max_val = a[i];
        if (a[i] < min_val) min_val = a[i];
    }
    result[0] = sum / n;
    double sd_sum = 0.0;
    for (int i = 0; i < n; ++i)
        sd_sum += (a[i] - result[0]) * (a[i] - result[0]);
    result[1] = sqrt(sd_sum / n);
    result[2] = exp(geo_log_sum / n);
    result[3] = n / harm_sum;
    result[4] = max_val;
    result[5] = min_val;
}
