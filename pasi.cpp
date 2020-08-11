/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

// constraints
#define MAXN 100+5

// input data
int N, M, x, y, K, i, j;
int gifts[MAXN][MAXN];
long long result=0;

int abs(int a){
    if(a>0)
        return a;
    else
        return 0-a;
}

void possibilita(int X, int Y, int Tempo,long long regali_cosegnati)
{
    if(Tempo!=K)
    {
        int x_1=-1;
        int x_2=-1;
        int y_1=-1;
        int y_2=-1;
        if(x<0)
            x_1=regali_cosegnati+gifts[X-1][Y];
        if(x>N)
            x_2=regali_cosegnati+gifts[X+1][Y];
        if(y<0)
            y_1=regali_cosegnati+gifts[X][Y-1];
        if(y>N)
            y_2=regali_cosegnati+gifts[X][Y+1];

        if(abs(x-X)+abs(y-Y)==Tempo)
        {
            if(abs(x-X)==Tempo)
            {
                if(x<X)
                {
                    possibilita(X-1,Y,Tempo+1,x_1+regali_cosegnati);
                }
                else
                {
                    possibilita(X+1,Y,Tempo+1,x_2+regali_cosegnati);
                }
            }
            else if(abs(y-Y)==Tempo)
            {
                if(y<Y)
                {
                    possibilita(X,Y-1,Tempo+1,y_1+regali_cosegnati);
                }
                else
                {
                    possibilita(X,Y+1,Tempo+1,y_2+regali_cosegnati);
                }
            }
            else
            {
                if(x<X)
                {
                    if(y<Y)
                    {
                        if(x_1>y_1)
                            possibilita(X-1,Y,Tempo+1,x_1+regali_cosegnati);
                        else
                            possibilita(X,Y-1,Tempo+1,y_1+regali_cosegnati);
                    }
                    else
                    {
                        if(y_2>x_1)
                            possibilita(X,Y+1,Tempo+1,y_2+regali_cosegnati);
                        else
                            possibilita(X-1,Y,Tempo+1,x_1+regali_cosegnati);
                    }
                }
                else
                {

                    if(y<Y)
                    {
                        if(y_2>x_2)
                            possibilita(X,Y+1,Tempo+1,y_2+regali_cosegnati);
                        else
                            possibilita(X+1,Y,Tempo+1,x_2+regali_cosegnati);
                    }
                    else
                    {
                        if(x_2>y_1)
                            possibilita(X+1,Y,Tempo+1,x_2+regali_cosegnati);
                        else
                            possibilita(X,Y-1,Tempo+1,y_1+regali_cosegnati);
                    }

                }
            }
        }else{
            if(x_1>x_2){
                if(x_1>y_1){
                    if(x_1>y_2){
                        possibilita(X-1,Y,Tempo+1,x_1+regali_cosegnati);
                    }
                    else
                    {
                        possibilita(X,Y+1,Tempo+1,y_2+regali_cosegnati);
                    }
                }
                else{
                    if(y_1>y_2){
                        possibilita(X,Y-1,Tempo+1,y_1+regali_cosegnati);
                    }else{
                        possibilita(X,Y+1,Tempo+1,y_2+regali_cosegnati);
                    }
                }

            }
            else{
                if(x_2>y_1){
                    if(x_2>y_2){
                        possibilita(X+1,Y,Tempo+1,x_2+regali_cosegnati);
                    }
                    else
                    {
                        possibilita(X,Y+1,Tempo+1,y_2+regali_cosegnati);
                    }
                }
                else{
                    if(y_1>y_2){
                        possibilita(X,Y-1,Tempo+1,y_1+regali_cosegnati);
                    }else{
                        possibilita(X,Y+1,Tempo+1,y_2+regali_cosegnati);
                    }
                }
            }
        }
    }
    else
    {
        if(regali_cosegnati>result && x==X && y==Y)
            result=regali_cosegnati;
    }
}

int main()
{
    //  uncomment the following lines if you want to read/write from files
    //  freopen("input0.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);

    assert(5 == scanf("%d %d %d %d %d", &N, &M, &x, &y, &K));
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= M; j++)
        {
            assert(1 == scanf("%d", &gifts[i][j]));
        }
    }
    possibilita(x,y,0,0);
    // insert your code here

    printf("%lld\n", result);  // change 42 with actual answer
    return 0;
}
