#include "holberton.h"

char** splitStr(char* text,char*splitter){

    int i = 0;
    int len = 0;

    len=sizeof(text);

    printf("entered function\n");
    char **my_array = malloc(sizeof(char *) * len);


    char *new_str;
    int acountr=0;
    printf("%d\n", len);
    for (i = 0; i < len - 1; i++)
    {

        if(text[i] == splitter[0])
        {
            printf("entered id\n");
            my_array[acountr]=new_str;
            acountr++;
            new_str="";
        }
        else{
            new_str = &text[i];

        }
        printf("%c\n", text[i]);
    }

    printf("finished loop\n");
    return (my_array);

}
int main(void){

    int i;
    char *text = "/mnt/c/Users/Lenovo/AppData/Local/Microsoft/WindowsApps:/mnt/c/Users/Lenovo/.dotnet/tools:/mnt/c/Users/Lenovo/AppData/Local/Programs/Microsoft VS Code/bin:/mnt/c/Exercism:/mnt/c/Program Files/JetBrains/PyCharm Community Edition 2023.3.2/bin:/mnt/c/Users/Lenovo/AppData/Local/Programs/cursor/resources/app/bin:/snap/bin:/home/useradd/.vscode-server/data/User/globalStorage/github.copilot-chat/debugCommand";

    char** test = splitStr(text, ":");
    int len = sizeof(test);
    print_char_array(test, len);
    return 0;
}

