#include <stdio.h>
#include <stdlib.h>

FILE *processFile(char *, char *);
void closeFile(FILE *, char *);

FILE *processFile(char *fileName, char *state){
 FILE *fp;
 if((fp = fopen(fileName, state)) == NULL) {
  printf("file \"%s\" does not exist.\n", fileName);
  exit(1);
 }
 return fp;
}

void closeFile(FILE *fp, char *fileName){
 if(fclose(fp) == 0) printf("file \"%s\" closed.\n", fileName);
 else printf("file \"%s\" close failed.\n", fileName);
 return;
}
