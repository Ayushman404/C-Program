// To Check if A particular character present in the string;

#include <stdio.h>

void strContains(char str[], char ch);
int main(){
    char str[100]= "Wanderlust";
    char ch;
    scanf("%c", &ch);


    strContains(str, ch);
    return 0;
}

void strContains(char str[], char ch){

    int contains =0;
    int j;
    for(int i =0; str[i]!='\0'; i++){
        char s= str[i];
        if(s>=65 && s<=90){
            s+=32;
        }
        if(ch>=65 && ch<=90){
            ch+=32;
        }
        if(s==ch){
            contains++;
            j=i;
            break;
        }

    }
    if(contains){
        printf("Yes, The String contains the character '%c' at the index %d\n", ch, j);
    }
    else{
        printf("No, The character '%c' is not present in the string", ch);
    }
    
}