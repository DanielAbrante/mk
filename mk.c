#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char *filename = argv[1];
  char file[50];

  int isFilenameValid = -1;
  int len = strlen(filename);

  if (filename[len - 2] == '.' && filename[len - 1] == 'c') {
    isFilenameValid = 0;
    strncpy(file, filename, len - 2);
    file[len - 2] = '\0';
  }

  if (isFilenameValid == -1) {
    printf("\nProvidencie um arquivo.c válido");
    return -1;
  }

  char cmd[100];
  snprintf(cmd, sizeof(cmd), "gcc %s -Wall -Wextra -pedantic -o %s", filename,
           file);
  system(cmd);

  return 0;
}
