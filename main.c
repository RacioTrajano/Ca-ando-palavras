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
char aux[TAM_PALAVRA]={0};
char chave[TAM_CHAVE]={0};
char string_leitura[PALAVRA_CHAVE]={0};
char matriz_palavra[PALAVRA_CHAVE][TAM_PALAVRA]={0};


// le a chave e coloca ela no formato de uma string
scanf(" %s", chave);
tam_chave=strlen(chave);
chave[tam_chave]= '\0';



// le as linha e quebra em palavras unicas

while (fgets(string_leitura,PALAVRA_CHAVE,stdin) != NULL){
char* pedaco;
char* substring;
pedaco = strtok(string_leitura," ");

while(pedaco != NULL){
// verifica se o pedaço é chave é substring da palavra
  substring =strstr(pedaco,chave);
if (substring != NULL){
  tam = strlen(pedaco);
  if(pedaco[tam-1] == '\n') {
      pedaco[tam-1]= '\0';
      
  } 
  strcpy(matriz_palavra[cont], pedaco);
  cont++;
}
  pedaco = strtok(NULL, " ");

}
}

for (int i=0; i< cont; i++){
  for (int j= i+1; j<=cont; j++){
    if(strcmp(matriz_palavra[i],matriz_palavra[j]) >0)
    {
      strcpy(aux, matriz_palavra[i]);
      strcpy(matriz_palavra[i],matriz_palavra[j]);
      strcpy(matriz_palavra[j],aux);
    }
  }
}




for (int i= 0; i<cont; i++)
printf("%s\n", matriz_palavra[i]);



  return 0;
}