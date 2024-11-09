//Find the salted form of a password entered by user if the salt is "123"
//& added at the end.

#include <stdio.h>
#include<string.h>
int countVowels(char str[]);
void salting(char password[]);
int main(){
    //  char password[100];
    //  scanf("%s", password);
    
    // salting(password);
    char str[100]= "AeIobc";

    printf("The no of vowels in the string is %d", countVowels(str));




    return 0;
}

int countVowels(char str[]){
    int count =0;
    int i=0;

    while(str[i]!='\0'){
        char ch = str[i];
        if(ch>=65 && ch<=90){
            ch +=32;
        }
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            count++;
        }


        i++;
    }
    return count;
}
// void salting(char password[]){
//     char salt[]= "123";
//     char newPass[200];

//     strcpy(newPass, password);
//     strcat(newPass, salt);
//     puts(newPass);
// }