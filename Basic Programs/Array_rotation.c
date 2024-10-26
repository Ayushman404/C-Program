#include <stdio.h>

void rightShift(int n, int arr[]){
        
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
    }

}

void leftShift(int n, int arr[]){

    for (int i = n-2; i >=0; i--)
    {
        int temp = arr[i];
        arr[i] = arr[n-1];
        arr[n-1] = temp;
    }
}
int main()
{
    int size, dir, indexShift;
    printf("Enter the Size Of Array: ");
    scanf("%d", &size);

    int arr[size];

    for(int i =0; i<size; i++){

        printf("Enter the %d position element of Array: ", i+1);
        scanf("%d", &arr[i]);
    }

    for(int i =0; i<size; i++){

        printf("%d ", arr[i]);
        
    }

    printf("\nDirection of Rotation (0-right or 1-left): ");
    scanf("%d", &dir);

    printf("Enter the No. of index want to Shift: ");
    scanf("%d", &indexShift);


    printf("\n\n");

    if(dir==1){
        for (int i = 0; i < indexShift; i++)
        {
            leftShift(size, arr);
        }  
    }
    else if(dir==0){
        for (int i = 0; i < indexShift; i++)
        {
            rightShift(size, arr);
        } 
    }
    else{
        printf("Invalid Direction of Rotation Input:\n");
    }
    
    printf("The Shifted Array is: \n");

    for(int k =0; k<size; k++){

        printf("%d ", arr[k]);
        
    }
   
    return 0;
}