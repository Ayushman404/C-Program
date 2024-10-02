#include <stdio.h>

int max(int , int);
int max(int a , int b){
    if(a>b)return a;
    if(b>a)return b;
}
int min(int a, int b){
    return (a<b)?a:b;
}

int main(){
    int i, n, t;
    scanf("%d", &t);

    for (int j = 0; j < t; j++)
    {
        scanf("%d", &n);
        int sequence[n];
        for(int k = 0; k<n; k++){
            scanf("%d", sequence[k]);
        }

        for (int g = 0; g < n; g++)
        {
            /* code */
        }
        
        }

        
        
    
    
    return 0;
}