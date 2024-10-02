#include <stdio.h>

int main(){
    int t, a, b, c, min;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &a, &b);
        min = 50;
        for (int c = a; c<=b ; c++)
        {
            //(c-a)+(b-c)
            if(min>((c-a)+(b-c))){
                min = (c-a)+(b-c);
            }
        }

        printf("%d\n", min);
        
        
    }
    
    return 0;
}