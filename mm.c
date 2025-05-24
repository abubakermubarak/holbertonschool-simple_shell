#include "holberton.h"

char** splitStr(char* text,char*splitter){

    int i = 0;
    int len = 0;
    splitter = ",";
    len=sizeof(text);
    char * my_array[len];
    char *new_str;
    int acountr=0;
    for (i = 0; i < len - 1; i++)
    {
        if(text[i] == splitter[0])
        {
            my_array[acountr]=new_str;
            acountr++;

            new_str="";
        }
        new_str = &text[i];
    }



}
int main(void){

    int i, len;
    char text[] = {"adskhbad,ljadn,alkdni,daaa"};
    for (i = 0; i < len - 1; i++){
        char *new_arr[] = &text[i];

    }
    printf("%s\n", splitStr(text, ","));
}



/*    char *path = getenv("PATH");
    //filename=ls
char *dir = strtok(path, ":");
printf("%s\n",dir);
return 0;
}
*/