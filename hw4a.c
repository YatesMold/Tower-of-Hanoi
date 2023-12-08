#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void move(int n, int start, int end, char** A, char** B, char** C);
int find_lvl(int n, char** P);
int tower(int n, int start, int end, int ath, char* A[], char*B[], char*C[]){
    if(n==1){
        move(n,start, end, A, B, C);
    }else{
        int temp=ath-(start+end);
        tower(n-1, start, temp, ath,  A, B, C);
        move( n,start, end, A, B, C);
        tower(n-1, temp, end, ath, A, B, C);
    }
}

int main()
{   int n;
    char **A;
    char **B;
    char **C;
    scanf("%d", &n);
    A=(char**)malloc((n+1)*sizeof(char*));
    B=(char**)malloc((n+1)*sizeof(char*));
    C=(char**)malloc((n+1)*sizeof(char*));
    int i;
    long temp;
    for(i=0;i<=n;i++){
        if (i==n){
            A[i]="|";
            B[i]="|";
            C[i]="|";
        }else{
            char* value = (char*)malloc((i * 2 + 2) * sizeof(char));
            int index = 0;
            for (int j = 0; j < i * 2; j++) {
                value[index] = i + '0';
                index++;
            }
            value[index] = '\0';
            A[i] = value;
          
        }
    }
    int start = 1, end = 3;
    int ath= n +start+end;
    tower(n, start, end, ath, A, B,C);
    free(A);
    free(B);
    free(C);
    
    return 0;
}

void move(int n,int start, int end, char* A[], char*B[], char*C[]){
    int start_lvl;
    int end_lvl;
    switch (start){
        case 1:
         start_lvl=find_lvl(n,A);
         break;
        case 2:
         start_lvl=find_lvl(n,B);
         break;
        case 3:
         start_lvl=find_lvl(n,C);
         break;
    }
    switch (end){
        case 1:
         end_lvl=find_lvl(n,A)+1;
         break;
        case 2:
         end_lvl=find_lvl(n,B)+1;
         break;
        case 3:
         end_lvl=find_lvl(n,C)+1;
         break;
    }
    if(start==1){
        if(end==2){
            B[end_lvl]=A[start_lvl];
            A[start_lvl]='|';
        }else if(end==3){
            C[end_lvl]=A[start_lvl];
            A[start_lvl]='|';
        }
    }else if(start==2){
        if(end==1){
            A[end_lvl]=B[start_lvl];
            B[start_lvl]="|";
        }else if(end==3){
            C[end_lvl]=B[start_lvl];
            B[start_lvl]="|";
        }
    }else if(start==3){
        if(end==2){
            B[end_lvl]=C[start_lvl];
            C[start_lvl]="|";
        }else if(end==1){
            A[end_lvl]=C[start_lvl];
            C[start_lvl]="|";
        }
    }
    int length;
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
        printf("%*s%s\n", distance, "", A[i]);
        printf("%*s%s\n", distance, "", B[i]);
        printf("%*s%s\n", distance, "", C[i]);
        
    }
    for(int i=1;i<=((n+2)*3+2);i++){
            printf("-");
        } 
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

int find_lvl(int n, char** P){
    int lvl;
    for(int i=0;i<=n;i++){
        if(strcmp(P[i], "|")==0){
            lvl=i-1;
            break;
        }
    }
    return lvl;
}