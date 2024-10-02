#include <stdio.h>
#include <math.h>

int main(){
    
    int n, arr[10], total;
    total = 0;
    printf("Enter the NO. ");
    scanf("%d", &n);
    int NoOfDigits=0;

    for (int i = 0; n>0; i++)
    {
        arr[i] = n%10;
        n/=10;
        NoOfDigits++;
        
    }

    for (int j = 0; j < NoOfDigits; j++)
    {
        total = total + arr[j]*pow(10, (NoOfDigits-j-1));
        printf("\n%d", arr[j]);
    }

    printf("%d", total);
    
    
    return 0;
}