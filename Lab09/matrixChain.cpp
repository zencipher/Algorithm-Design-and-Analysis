#include <iostream>
#include <stdio.h>
#include <limits.h>
#define MAX_INT 2147483647

using namespace std;

long int m[20][20];
int s[20][20];
int p[20],i,j,n;

// print sequence

// use of backtracking here

void print_optimal(int i,int j){

    if (i == j)
        cout<<"A"<<i-1;

    else{

        cout<<"(";
        print_optimal(i, s[i][j]);
        print_optimal(s[i][j] + 1, j);

        cout<<")";
    }
	
}


void matrix_chain_multiply(){

    long int q;
    
    int k;
    
    for(i=n;i>0;i--){
        for(j=i;j<=n;j++){
            if(i==j)
                m[i][j]=0;

            else{

                for(k=i;k<j;k++){

                    q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                    
                    if(q<m[i][j]){

                        m[i][j]=q;
                        
                        s[i][j]=k;
                    }
                }
            }
        }
    }

    cout<<m[1][n]<<endl;
}

int main(){
    int k;

// input from user
    cin>>n;

// initlize matrix to zero and infinity

    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++){
    
            m[i][i]=0;
            
            m[i][j]=MAX_INT ;
            
            s[i][j]=0;
        
        }


    for(k=0;k<=n;k++)

        cin>>p[k];

    //find order of mutiply
    
    matrix_chain_multiply();
    
    //Print sequnece
    
    print_optimal(1,n);
	cout << endl;

}
