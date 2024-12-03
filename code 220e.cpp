#include <iostream>
using namespace std;

void drum(int &i, int &j, int &n, int &p, int &s, int &caz, int &Lmin, int d[51][51], int dmin[51])
{
    int k, q, t, u, z, amsuccesor, contor, contor0, contor2, linia, Lcurent, serepeta;
    int a[51], m[2788][51], v[51], y[51];
    Lcurent = 0;
    contor0 = 0;

    if (caz == 1)
        for (i = 1; i <= n; ++i)
            v[i] = i;
    if (caz == 3)
        for (i = 1; i <= n; ++i)
            v[i] = i;
    if (caz == 2)
    {
        v[n] = s;
        for (i = 1; i <= s - 1; ++i)
            v[i] = i;
        for (i = s; i <= n - 1; ++i)
            v[i] = i+1;
    }
    for (i = 1; i <= n; ++i)
    {
        m[1] [i] = v[i];
        if (i < n)
        {
            Lcurent = Lcurent + d[v[i]][v[i + 1]];
            if (d[v[i]][v[i + 1]] == 0)
                contor0 = 1;
        }
    }
    if (caz == 3)
    {
        Lcurent = Lcurent + d[v[n]][p];
        if (d[v[n]][p] == 0)
            contor0 = 1;
    }
    if (caz != 2 && v[1] == p && contor0 == 0)
    {
        Lmin = Lcurent;
        for (q = 1; q <= n; ++q)
            dmin[q] = v[q];
    }
    if (caz == 2 && v[1] == p && contor0 == 0 && v[n] == s)
    {
        Lmin = Lcurent;
        for (q = 1; q <= n; ++q)
            dmin[q] = v[q];
    }

    contor = 1;
    linia = 1;
    i = n + 1;
    for (k = 1; k <= n; ++k)
    {
        y[k] = 1;
        a[k] = k;
    }
    while (i > 1)
    {
        i = i - 1;

        do
        {
            for (t = i; t <= n; ++t)
                y[a[t]] = 0;
            amsuccesor = 0;
            contor2 = 0;
            for (j = 1; j < n; ++j)
            {
                if (v[i] == j)
                    contor2 = 1;
                if (contor2 == 1 && v[i] != j + 1 && y[j + 1] == 0)
                {
                    v[i] = j + 1;
                    y[j + 1] = 1;
                    a[i] = j + 1;
                    amsuccesor = 1;

                    for (u = i + 1; u <= n; ++u)
                        for (k = 1; k <= n; ++k)
                            if (y[k] == 0)
                            {
                                v[u] = k;
                                y[k] = 1;
                                a[u] = k;
                                break;
                            }

                    serepeta = 0;
                    for (z = 1; z <= linia; ++z)
                    {
                        contor = 0;
                        for (t = 1; t <= n; ++t)
                            if (m[z][t] != v[t])
                                contor = 1;
                        if (contor == 0)
                            serepeta = 1;
                    }
                    if (serepeta == 0)
                    {
                        ++linia;
                        Lcurent = 0;
                        contor0 = 0;
                        for (q = 1; q <= n; ++q)
                        {
                            m[linia][q] = v[q];
                            if (q < n)
                            {
                                Lcurent = Lcurent + d[v[q]][v[q + 1]];
                                if (d[v[q]][v[q + 1]] == 0)
                                    contor0 = 1;
                            }
                        }
                        if (caz == 3)
                        {
                            Lcurent = Lcurent + d[v[n]][p];
                            if (d[v[n]][p] == 0)
                                contor0 = 1;
                        }
                        if (caz != 2 && Lmin == -3 && v[1] == p && contor0 == 0)
                        {
                            Lmin = Lcurent;
                            for (q = 1; q <= n; ++q)
                                dmin[q] = v[q];
                        }
                        if (caz == 2 && Lmin == -3 && v[1] == p && contor0 == 0 && v[n] == s)
                        {
                            Lmin = Lcurent;
                            for (q = 1; q <= n; ++q)
                                dmin[q] = v[q];
                        }
                        if (caz != 2 && Lmin != -3 && Lcurent <  Lmin && v[1] == p && contor0 == 0)
                        {
                            Lmin = Lcurent;
                            for (q = 1; q <= n; ++q)
                                dmin[q] = v[q];
                        }
                        if (caz == 2 && Lmin != -3 && Lcurent <  Lmin && v[1] == p && contor0 == 0 && v[n] == s)
                        {
                            Lmin = Lcurent;
                            for (q = 1; q <= n; ++q)
                                dmin[q] = v[q];
                        }
                    }
                    i = n - 1;
                    break;
                }
            }
        }
        while (v[i] < n && amsuccesor == 1);
    }
    if (caz == 3 && Lmin != -3)
        dmin[n + 1] = p;
}

int main()
{
    int i, j, n, p, s, caz, Lmin;
    int d[51][51], dmin[51];
    string b[100];
    cout << endl;
    cout << "Enter the number of localities N > 1: ";
    cin >> n;
    cout << endl;
    for (i = 1; i <= n; ++i)
    {
        cout << "Enter the name of the locality with the number " << i << ": ";
        cin >> b[i];
    }
    cout << endl;
    cout << "Enter the number of the departure locality P: ";
    cin >> p;
    cout << "Enter the number of the arrival town S. If you do not want to specify it, enter the digit 0: ";
    cin >> s;
    cout << endl;
    cout << "Enter the distances between localities, in kilometers. If you do not want to specify the distance between 2 localities, enter the digit 0." << endl;
    for (i = 1; i <= n; ++i)
    {
        for (j = i + 1; j <= n; ++j)
        {
            cout << "Enter the distance between locality " << i << " and locality " << j << ": ";
            cin >> d[i][j];
            d[j][i] = d[i][j];
        }
    }
    Lmin = -3;
    caz = 1;
    if  (s != 0 && s != p)
        caz = 2;
    if  (s != 0 && s == p)
        caz = 3;

    drum(i, j, n, p, s, caz, Lmin, d, dmin);
    cout << endl;
    if  (Lmin == -3)
        cout << "There is no road that meets the required conditions.";
    if  (Lmin != -3)
    {
        cout << "The shortest possible road (in terms of number of kilometers traveled) is:";
        if (caz == 3)
            ++n;
        for (i = 1 ; i <= n; ++i)
            cout << " "<< b[dmin[i]];
        cout << "." << endl << "The total length of this road is " << Lmin << " km.";
    }
    cout << endl;
}
