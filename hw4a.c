#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void move(int n, int start, int end, char** A, char** B, char** C, int const_n);
int find_lvl(int const_n, char** P);
void tower(int n, int start, int end, int ath, char* A[], char*B[], char*C[], int const_n){
    printf("enter tower\n");
    if(n==1){
        move(n,start, end, A, B, C, const_n);
    }else{
        int temp=ath-(start+end);
        printf("temp=%d, n=%d\n", temp, n-1);
        tower(n-1, start, temp, ath,  A, B, C, const_n);
        printf("about to enter tower move\n");
        move( n,start, end, A, B, C, const_n);
        tower(n-1, temp, end, ath, A, B, C, const_n);
    }
}

int main()
{   
    int n;
    scanf("%d", &n);
    char **A;
    char **B;
    char **C;
    int const_n=n;
    A=(char**)malloc((n+1)*sizeof(char*));
    B=(char**)malloc((n+1)*sizeof(char*));
    C=(char**)malloc((n+1)*sizeof(char*));
    int i;
    
    for(i=0;i<=n;i++){
        
        if (i==n){
            A[i] = (char*)malloc(2 * sizeof(char)); 
            strcpy(A[i], "|");

            B[i] = (char*)malloc(2 * sizeof(char)); 
            strcpy(B[i], "|");

            C[i] = (char*)malloc(2 * sizeof(char)); 
            strcpy(C[i], "|");
            printf("A[%d]: %s\n", i, A[i]);
            printf("B[%d]: %s\n", i, B[i]);
            printf("C[%d]: %s\n", i, C[i]);
        }else{
            char* value = (char*)malloc((i * 2 + 2) * sizeof(char));
            int index = 0;
            for (int j = 0; j < i * 2+1; j++) {
                value[index] = (i+1) + '0';
                index++;
            }
            value[index] = '\0';
            A[i] = value;
            B[i] = (char*)malloc(2 * sizeof(char)); 
            strcpy(B[i], "|");
            C[i] = (char*)malloc(2 * sizeof(char)); 
            strcpy(C[i], "|");
            printf("A[%d]: %s\n", i, A[i]);
            printf("B[%d]: %s\n", i, B[i]);
            printf("C[%d]: %s\n", i, C[i]);
        }
    }
    int start = 1, end = 3;
    int ath= n +start+end;
    tower(n, start, end, ath, A, B,C, const_n);
    for(int i=n;i>=0;i--){
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
    

    return 0;
}





void move(int n,int start, int end, char* A[], char*B[], char*C[], int const_n){
    printf("Enter move\n");
    int start_lvl;
    int end_lvl;
    switch (start) {
        case 1:
            start_lvl = find_lvl(n, A);
            break;
        case 2:
            start_lvl = find_lvl(n, B);
            break;
        case 3:
            start_lvl = find_lvl(n, C);
            break;
    }
    switch (end) {
        case 1:
            end_lvl = find_lvl(n, A) + 1;
            break;
        case 2:
            end_lvl = find_lvl(n, B) + 1;
            break;
        case 3:
            end_lvl = find_lvl(n, C) + 1;
            break;
    }
    printf("start_lvl: %d\n", start_lvl);
    printf("end_lvl: %d\n", end_lvl);
    if (start == 1) {
        if (end == 2) {
            B[end_lvl] = A[start_lvl];
            printf("DONE Switch\n");
            A[start_lvl] = "|";
            printf("Took |\n");
        } else if (end == 3) {
            C[end_lvl] = A[start_lvl];
            printf("DONE Switch\n");
            A[start_lvl] = "|";
            printf("Took |\n");
        }
    } else if (start == 2) {
        if (end == 1) {
            A[end_lvl] = B[start_lvl];
            printf("DONE Switch\n");   
            B[start_lvl] = "|";
            printf("Took |\n");
        } else if (end == 3) {
            C[end_lvl] = B[start_lvl];
            printf("DONE Switch\n");
            B[start_lvl] = "|";
            printf("Took |\n");
        }
    } else if (start == 3) {
        if (end == 2) {
            B[end_lvl] = C[start_lvl];
            printf("DONE Switch\n");
            C[start_lvl] = "|";
            printf("Took |\n");
        } else if (end == 1) {
            A[end_lvl] = C[start_lvl];
            printf("DONE Switch\n");
            C[start_lvl] = "|";
            printf("Took |\n");
        }
    }
    printf("Switch done without fault\n");
    int length=0;
    int max_length = 0;
    for (int i = 0; i < n; i++) {
        length = 0;
        while (A[i][length] != '\0') {
            length++;
        }
        if (length > max_length) {
            max_length = length;
        }
    }
     for (int i = n; i>=0; i--) {
        int distance = (max_length - length) / 2;
        printf("%*s%s\n", distance, " ", A[i]);
        printf("%*s%s\n", distance, " ", B[i]);
        printf("%*s%s\n", distance, " ", C[i]);
        
    }
    for(int i=1;i<=((n+2)*3+2);i++){
            printf("-");
        } 
        printf("\n\n");
    if(start==1){
        if(end==2){
           printf("A -> B\n");
        }else if(end==3){
           printf("A -> C\n"); 
        }
    }else if(start==2){
        if(end==1){
            printf("B -> A\n");
        }else if(end==3){
            printf("B -> C\n");
        }
    }else if(start==3){
        if(end==2){
            printf("C -> B\n");
        }else if(end==1){
            printf("C -> A\n");
        }
    } 
}

int find_lvl(int const_n, char** P){
    printf("find level\n");
    int lvl=0;
    for(int i=0;i<const_n;i++){
        printf("lvl in find_lvl: %d i in find level %d\n", lvl, i);
        if(strcmp(P[i], "|")==0){
            if(i==0){
                lvl=0;
                break;
            }else{
                lvl=i-1;
                break;
            }
            
            
            
        }
    }
    
    return lvl;
}
