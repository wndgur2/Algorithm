#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%i", &n);
    char *arr = malloc(sizeof(char)*n*n);
    for (int i=0; i<n; i++)
        scanf("%s", &arr[i*n]);
    // for (int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         printf("%c ", arr[i*n+j]);
    //     }
    //     printf("\n");
    // }
    printf("%s", arr);
    
    free(arr);
}