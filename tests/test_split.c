#include "../holberton.h"


int main(void){
    char cmd[]= "ls -l -a ../root";
    char** list = split(cmd," ");
    // list[0] is the command 
    // list [i] is the args
    print_char_array(list,2);
    return 0;
}