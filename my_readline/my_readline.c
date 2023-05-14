#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int READLINE_READ_SIZE = 20;
char* my_readline(int fd){
    
    char* res = (char*)malloc(READLINE_READ_SIZE*sizeof(char));
    int size;
    char* str = (char*)calloc(1, sizeof(char));
    int i = 0;
    for(;i<READLINE_READ_SIZE;i++){
        size = read(fd,str,1);
        if(size == 0){
            break;
        }
        if(strcmp(str, "\n") != 0){
            strcat(res,str);
        }else{
            break;
        }
    }
    if(size == 0 && strcmp(res,"") == 0) return NULL;
    return res;
}

int main(){
    char* string = NULL;
    int hf = open("input.txt",O_RDONLY);
    while((string = my_readline(hf)) != NULL){
        printf("%s\n",string);
        free(string);
    }
    close(hf);
    return 0;
}