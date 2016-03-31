#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  
  FILE *fp;
  
  fp = popen("dig TXT +short o-o.myaddr.l.google.com @ns1.google.com","r");
  if (fp == NULL){
    printf("error exiting");
    exit(1);
  }
  
  int i = 0;
  char ipChar;
  char* ip =(char *)malloc(sizeof(&fp));
  while ((ipChar = fgetc(fp)) != EOF){
    ip[i++] = ipChar;
  }

  char* ipFinal = (char *)malloc(sizeof(ip)-(2*sizeof(char)));
  strncpy(ipFinal,ip+1, strlen(ip)-3);
  free(ip);

  printf("%s\n",ipFinal);
  
  free(ipFinal);
  pclose(fp);
  return 0;

}
