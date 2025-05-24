#include "holberton.h"

int main(void){
    
char *path = getenv("PATH");
printf("%s\n",path);
list_t* dir = split(path, ":");
size_t len=sizeof(dir)/sizeof(*dir);
printf("the len %ld\n",len);
    return 0;
}