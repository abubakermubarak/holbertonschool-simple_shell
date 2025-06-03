#include "holberton.h"

int _chdir(char *path)
{
  //change current wotking dirctory
  //set enviroment variable ""
  /* check if file exists using stat */
  st t;
  int len;
  char *dir;
  dir = envo[1].value;
  len = strlen(dir);

  if(strcmp (path, "..") == 0)
  {
    while (dir[len] != '/')
    {
      len--;
    }
    dir[len + 1] = '\0';
    path  = dir;
    /* remove from last untill reaching '/'*/
  }
  if (stat(path, t) == 0)
  {
    set_env("PWD", path, 1);
    return (0);
  }
  printf("bash: cd: %s: NO such file or directory\n", path);
  return (-1);
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