#include "holberton.h"
int _chdir(char *path)
{
  //change current wotking dirctory
  //set enviroment variable ""
  setenv("PWD", path, 1);

}
int main(void)
{
    printf("current working dir: %s\n", getenv("PWD"));
    _chdir("/root/");
    printf("after cd\n");
    printf("current working dir: %s\n", getenv("PWD"));
}