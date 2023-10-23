#include <iostream>
#include <cmath>
using namespace std;

//! S0
double S0(const int k, const int N)
{
    double s = 0;
    for (int i = k; i <= N; i++) {
         s += (i  * i * 1.0) / (k * k + N * N);
    }
    return s;
}

//! S1
double S1(const int k, const int N, const int i)
{
    if (i > N)
        return 0;
    else
        return (i * i * 1.0) / (k * k + N * N) + S1(k, N, i + 1);
}

//! S2
double S2(const int k, const int N, const int i)
{
    if (i < k)
        return 0;
    else
        return (i * i * 1.0) / (k * k + N * N) + S2(k, N, i - 1);
}

//! S3
double S3(const int k, const int N, const int i, double t)
{
    t = t + (i * i * 1.0) / (k * k + N * N);
    if (i >= N)
        return t;
    else
        return S3(k, N, i + 1, t);
}

//! S4
double S4(const int k, const int N, const int i, double t)
{
    t = t + (i * i  * 1.0) / (k * k + N * N);
    if (i <= k)
        return t;
    else
        return S4(k, N, i - 1, t);
}

int main() {
    int k, N;
    cout << "k = "; cin >> k;
    cout << "N = "; cin >> N;
    cout << "(iter) S0 = " << S0(k, N) << endl;
    cout << "(rec up ++) S1 = " << S1(k, N, k) << endl;
    cout << "(rec up --) S2 = " << S2(k, N, N) << endl;
    cout << "(rec down ++) S3 = " << S3(k, N, k, 0) << endl;
    cout << "(rec down --) S4 = " << S4(k, N, N, 0) << endl;
    return 0;
}

