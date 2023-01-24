#include <iostream>
#include <fstream>

using namespace std;

int pilstymas(int n1, int n3, int n5, int N, ofstream& rez, int k1, int k3, int k5);

int main()
{
    int n1, n3, n5, N, islaidos, k1, k3, k5;
    ifstream duom("Duomenys.txt");
    duom >> n1 >> n3 >> n5 >> N >> islaidos >> k1 >> k3 >> k5;
    ofstream rez("Rezultatai.txt");
    rez << pilstymas(n1, n3, n5, N, rez, k1, k3, k5) - islaidos;
    duom.close();
    rez.close();
    return 0;
}

int pilstymas(int n1, int  n3, int  n5, int  N, ofstream& rez, int k1, int k3, int k5)
{
    int N1 = 0, N3 = 0, N5 = 0;
    for (int i = 0; i < n5; i++)
    {
        if (N >= 5)
        {
            N -= 5;
            N5++;
        }
    }
    for (int i = 0; i < n3; i++)
    {
        if (N >= 3)
        {
            N -= 3;
            N3++;
        }
    }
    for (int i = 0; i < n1; i++)
    {
        if (N >= 1)
        {
            N -= 1;
            N1++;
        }
    }
    rez << N1 << ' ' << N3 << ' ' << N5 << ' ' << N << '\n';
    rez << n1-N1 << ' ' << n3-N3 << ' ' << n5-N5 << '\n';
    rez << (N % 5) % 3 << ' ' << (N % 5) / 3 << ' ' << N / 5 << '\n';
    return N1 * k1 + N3 * k3 + N5 * k5 + ((N % 5) % 3) * k1 + ((N % 5) / 3) * k3 + (N / 5) * k5;
}