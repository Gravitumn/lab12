#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sum=0;
    for(int i=0;i<N;i++){
        sum+=A[i];
    }
    B[0]=sum/N;
    double sum1=0;
    for(int i=0;i<N;i++){
        sum1+=pow(A[i]-B[0],2);
    }
    B[1]=sqrt(sum1/N);
    double sum2=1;
    for(int i=0;i<N;i++){
        sum2*=A[i];
    }
    B[2]=pow(sum2,1.0/N);
    double sum3=0;
    for(int i=0;i<N;i++){
        sum3+=1.0/A[i];
    }
    B[3]=N/sum3;
    double max=B[0],min=B[0];
    for(int i=0;i<N;i++){
        if(max<A[i])max=A[i];
        else if(min>A[i])min=A[i];
    }
    B[4]=max;
    B[5]=min;
}
