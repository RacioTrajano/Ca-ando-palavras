#include<stdio.h>
#include<string.h>

#define TAM_CHAVE 20
#define TAM_PALAVRA 50
#define PALAVRA_CHAVE 200



int main () {

int tam;
int cont=0;
int tam_chave;
int eh_substring=0;
int verica_string =0;
char chave[TAM_CHAVE]={0};
char string_leitura[PALAVRA_CHAVE]={0};
char matriz_palavra[PALAVRA_CHAVE][TAM_PALAVRA]={0};


// le a chave e coloca ela no formato de uma string
scanf("%s\n", chave);
tam_chave=strlen(chave);
chave[tam_chave ]= '\0';



// le as linha e quebra em palavras unicas

while (fgets(string_leitura,PALAVRA_CHAVE,stdin)!= NULL){
char* pedaco;
char* substring;
pedaco = strtok(string_leitura," ");

while(pedaco != NULL){
// verifica se o pedaço é chave é substring da palavra
  substring =strstr(pedaco,chave);
if (substring != NULL){
  tam =strlen(pedaco);
  pedaco[tam]= '\0';
  if(pedaco[tam+1] == '\n'){
      pedaco[tam+1] ='\0';
  }
  printf("%s\n", pedaco);
  
}
  pedaco = strtok(NULL, " ");

}
}



  return 0;
}