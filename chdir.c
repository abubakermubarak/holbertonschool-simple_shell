#include "holberton.h"

int _chdir(char *path)
{
  //change current wotking dirctory
  //set enviroment variable ""
  set_env("PWD", path, 1);

}
/*
int main(void)
{
  //int _setenv(char *name, char *value, int overwtite);
  _chdir("/root/");
  int len = sizeof(envo) / sizeof(var);
  for(int i = 0; i < len; i++)
  {
    printf("%s=%s\n", envo[i].name, envo[i].value);
  }
}
*/