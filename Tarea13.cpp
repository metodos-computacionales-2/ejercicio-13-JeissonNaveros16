#include<iostream>

using namespace std;

void fillCauchy(int filas, int columnas, float **t);

void fillnipotent(int n, float **t);

void multiplica(int filas, int columnas, float **m, float **w, float **s);

int revisa(int filas, int columnas, float **t);

void copiaMatriz(int n, float **f, float **t);

void imprime(int filas, int columnas, float **t);


int main()
{
    cout<<"Tamanio de matriz de cauchy"<<endl;
    cout<<"Filas (n):"<<endl;
    int n1;
    cin>>n1;
    cout<<"Columnas (m):"<<endl;
    int n2;
    cin>>n2;
    
    float ** mat1 = new float *[n1];
    for (int i = 0; i < n1; i++)
    {
        mat1[i] = new float[n2];
    }
    fillCauchy(n1, n2, mat1);
    cout<<"\nLa primera matriz de Cauchy (primer factor) es: "<<endl;
    imprime(n1, n2, mat1);
    cout<<endl;
    
    float ** mat2 = new float *[n2];
    for (int i = 0; i < n2; i++)
    {
        mat2[i] = new float[n1];
    }
    fillCauchy(n2, n1, mat2);
    cout<<"\nLa segunda matriz de Cauchy (segundo factor) es: "<<endl;
    imprime(n2, n1, mat2);
    cout<<endl;
    
    // Matriz para guardar la multiplicación
    float ** mat3 = new float *[n1];
    for (int i = 0; i < n1; i++)
    {
        mat3[i] = new float[n1];
    }
    multiplica(n1, n2, mat1, mat2, mat3);
    cout<<"\nEl resultado de la multiplicacion de ambas matrices de Cauchy es: "<<endl;
    imprime(n1, n1, mat3);
    cout<<endl;
    
    // Matriz nilpotente
    cout<<"Tamaño de la matriz nilpotente (NxN)"<<endl;
    cout<<"N :"<<endl;
    int n;
    cin>>n;
    
    float ** mat4 = new float *[n];
    for (int i = 0; i < n; i++)
    {
        mat4[i] = new float[n];
    }
    fillnipotent(n, mat4);
    cout<<"\nLa matriz nilpotente correspondiente es: "<<endl;
    imprime(n, n, mat4);
    cout<<endl;
    
    float ** mat5 = new float *[n];
    for (int i = 0; i < n; i++)
    {
        mat5[i] = new float[n];
    }
    multiplica(n, n, mat4, mat4, mat5);
    int k = 2;
    while( revisa(n, n, mat5) == 1 )
    {
        float ** mat6 = new float *[n];
        for (int i = 0; i < n; i++)
        {
            mat6[i] = new float[n];
        }
        copiaMatriz(n, mat6, mat5);
        multiplica(n, n, mat6, mat4, mat5);
        k++;
    }
    
    cout<<"\nElevar la matriz nilpotente a la " << k << " da como resultado: "<<endl;
    imprime(n, n, mat5);
    cout<<endl;
    
    return 0;
}

void fillCauchy(int filas, int columnas, float **t)
{
    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            float temp = 1/(i+j+1.0);
            t[i][j] = temp;
        }
    }
}

void fillnipotent(int n, float **t)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if( i == 0 )
            {
                t[i][j] = 2;
            }
            else if( i == j+1 )
            {
                t[i][j] = n+2;
            }
            else
            {
                t[i][j] = 1;
            }
            if(j == n-1)
            {
                if( i == 0)
                {
                    t[i][j] = 1-n;
                }
                else
                {
                    t[i][j] = -n;
                }
            }
        }
    }
}

void multiplica(int filas, int columnas, float **m, float **w, float **s)
{
    for(int i = 0; i < filas; i++)
    {
        for(int h = 0; h < filas; h++)
        {
            float sum = 0;
            for(int k = 0; k < columnas; k++)
            {
                sum += m[i][k] * w[k][h];
            }
            s[i][h] = sum;
        }
    }
}

// Verifica si algún elemento no es cero
int revisa(int filas, int columnas, float **t)
{
    int resp = 0;
    for (int i = 0; i < filas && resp==0; i++)
    {
        for ( int j = 0; j < columnas && resp==0 ; j++)
        {
            if( t[i][j] != 0 )
            {
                resp = 1;
            }
        }
    }
    return resp;
}

void copiaMatriz(int n, float **f, float **t)
{
    for (int i = 0; i < n; i++)
    {
        for ( int j = 0; j < n; j++)
        {
            f[i][j] = t[i][j];
        }
    }
}

void imprime(int filas, int columnas, float **t)
{
    for (int i = 0; i < filas; i++)
    {
        for ( int j = 0; j < columnas; j++)
        {
            cout.precision(16);
            cout.setf(std::ios::scientific);
            cout<<" "<<t[i][j]<<" ";
        }
        cout<<endl;
    }
}