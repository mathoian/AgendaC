#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"


void aborte (int n){
     char msg[][50] = {" ", "Erro  alocacao memoria dinamica\n"};
     printf ("%s\n", msg[n]);
     exit(n);

     }

 // verificar na funcao inclusao a conversao de caracteres em caixa alta
int consulta (contato *agenda, char nome[], contato *contatos_encontrados[]){
// agenda � uma apontador pra um nodo do tipo contato
// contatos_encontrados � uma array de apontadores pra contato
   contato *pAux; // ponteiro auxiliar
   int cont=0;// cont armazena o numro de registros e � o indice do vetor contatos_encontrados
   char nome_contato[30];
   char nome_buscado[30];

   if ((pAux=(contato *) malloc(sizeof(contato))) == NULL)
      aborte(1);

   pAux=agenda;

   while (pAux!=NULL){
      strcpy(nome_contato, (pAux->nome)); //copia a cadeia  para nome_contato)
      mystrupr(nome_contato);
      strcpy(nome_buscado, (nome));//copia o nome passado por par�metro  para nome_buscado)
      mystrupr(nome_buscado);

      if (strstr(nome_contato, nome_buscado)!=NULL){
      /*se nome passado por paramentro estiver na cadeia
      apontado por paux retornar uma valor diferente de zero (null) */
      contatos_encontrados[cont++]=pAux;
      }
   pAux=pAux->prox;
   }
   return(cont);
}

//funcao converte caracteres em maiusculos
void mystrupr(char *s){
     while ((*s)!='\0'){
           *s=toupper(*s);
           s++;
           }
     }

// funcao verifica cadeia vazia
/*int ta_vazio(char *s){
    while ((*s)==' '||(*s)=='\t') s++;
    return(*s=='\0'?1:0); //retorna 1 t� vazia, retorna 0 n�o ta vazia
}*/

int ta_vazio(char s[]){
	int i=0;
    while (s[i]==' '|| s[i]=='\t') i++;
    return(s[i]=='\0'?1:0); //retorna 1 t� vazia, retorna 0 n�o ta vazia
}

// rotina de inclusao
void inclusao (contato **pAgenda, contato *novo){ //**pAgenda apontador para um apontador de contato
     char nome_contato[30];
     char nome_novo[30];
     contato *pAux, *pAnt;

      if (*pAgenda==NULL){ // verifica se agenda t� vazia
      *pAgenda = novo; // conteudo de pAgenda recebe endere�o de novo
      novo->prox=NULL;
      }
      else {
           strcpy(nome_novo,(novo->nome));
           mystrupr(nome_novo);
           strcpy(nome_contato, (*pAgenda)->nome);
           mystrupr(nome_contato);
           if (strcmp(nome_novo, nome_contato)<0) {// se o 1� for menor que o 2� retorna -1
              novo->prox=*pAgenda;// cria o link de prox do novo para o endre�o do 1� da lista
              *pAgenda=novo;
           }
           else {
                pAnt=pAux=*pAgenda; // as auxiliares recebem o valor incial de pAgenda
                while(strcmp (nome_novo, nome_contato) >=0){// condicao p/
                  pAnt=pAux; //pAnt guarda o endereco anterior e pAux guarda o prox
                  pAux=pAux->prox;// avanca o pAux
                  if (pAux==NULL) break; // caso pAux chegue no final da lista
                  strcpy(nome_contato, pAux->nome);
                  mystrupr(nome_contato);
                  }
           novo->prox=pAux;// o prox do novo (nome novo) recebe Null
           pAnt->prox=novo; // o prox do nome anterior recebe o endereco de novo
           }
      }
 system("CLS");
 printf ("\nRegistro incluido com sucesso!\n\n");

}

//rotina de exclusao

void exclusao(contato **pAgenda, contato * removido){
     contato * pAux, *pAnt;

     if (*pAgenda==NULL) free(removido);
     else {
          if (*pAgenda==removido){//se o numero a ser removido for o primeiro da lista
          *pAgenda=removido->prox;// Agenda recebe o prox de removido
          free(removido);
          }
          else{
               pAnt=pAux=*pAgenda;
               while (pAux!=removido){// enquanto o numero a ser removido for diferente de paux que guarda o endereco inicial de agenda
                     pAnt=pAux; // guanta o endereco do anterior
                     pAux=pAux->prox; // avanca o prox
                     if (pAux==NULL) break;// caso chegue no final da lista e n�o encotre
               }
          if (pAux !=NULL) pAnt->prox = pAux->prox; //
          free(removido);
          }
     }
  system("CLS");
 printf ("\nRegistro excluido com sucesso!\n\n");

}

// funcao altera��o

void alteracao(contato * sol_cont){
  char opcao;
   printf ("Alterar nome [%s] ? [s] Sim [n] Nao\n", sol_cont->nome);
   opcao=getchar();
   if (opcao=='s'){
   	  printf ("Digite o novo nome:\n");
   	  fflush(stdin);
   	  gets(sol_cont->nome);
   }
   fflush(stdin);
   printf("Telefones\n");
   printf ("Alterar Residencial [%s] ? [s] Sim [n] Nao\n", sol_cont->telefone.residencial);
   opcao=getchar();
   if (opcao=='s'){
     printf ("Digite o novo numero:\n");
     fflush(stdin);
     gets (sol_cont->telefone.residencial);
   }
   fflush(stdin);
   printf ("Alterar Celular [%s] ? [s] Sim [n] Nao\n", sol_cont->telefone.celular);
   opcao=getchar();
   if (opcao=='s'){
     printf ("Digite o novo numero:\n");
     fflush(stdin);
     gets (sol_cont->telefone.celular);
   }
   fflush(stdin);
   printf ("Alterar Comercial [%s] ? [s] Sim [n] Nao\n", sol_cont->telefone.comercial);
   opcao=getchar();
   if (opcao=='s'){
     printf ("Digite o novo numero:\n");
     fflush(stdin);
     gets (sol_cont->telefone.comercial);
   }
   fflush(stdin);
   printf ("Alterar e-mail [%s] ? [s] Sim [n] Nao\n", sol_cont->email);
   opcao=getchar();
   if (opcao=='s'){
     printf ("Digite o novo e-mail:\n");
     fflush(stdin);
     gets (sol_cont->email);
   }
  fflush(stdin);
  printf ("\n");
  printf ("Endereco:\n");
  printf ("Alterar Logradouro [%s] ? [s] Sim [n] Nao\n", sol_cont->endereco.log);
  opcao=getchar();
  if (opcao=='s'){
     printf ("Digite o novo Logradouro:\n");
     fflush(stdin);
     gets (sol_cont->endereco.log);
   }
   fflush(stdin);
   printf ("Alterar Numero [%s] ? [s] Sim [n] Nao\n", sol_cont->endereco.num);
  opcao=getchar();
  if (opcao=='s'){
     printf ("Digite o novo Numero:\n");
     fflush(stdin);
     gets (sol_cont->endereco.num);
   }
  fflush(stdin);
  printf ("Alterar Bairro [%s] ? [s] Sim [n] Nao\n", sol_cont->endereco.bairro);
  opcao=getchar();
  if (opcao=='s'){
     printf ("Digite o novo Bairro:\n");
     fflush(stdin);
     gets (sol_cont->endereco.bairro);
   }
   fflush(stdin);
  printf ("Alterar Cidade [%s] ? [s] Sim [n] Nao\n", sol_cont->endereco.cidade);
  opcao=getchar();
  if (opcao=='s'){
     printf ("Digite o novo Cidade:\n");
     fflush(stdin);
     gets (sol_cont->endereco.cidade);
   }
   fflush(stdin);
  printf ("Alterar Estado [%s] ? [s] Sim [n] Nao\n", sol_cont->endereco.estado);
  opcao=getchar();
  if (opcao=='s'){
     printf ("Digite o novo Estado:\n");
     fflush(stdin);
     gets (sol_cont->endereco.estado);
   }
   fflush(stdin);
   printf ("Alterar CEP [%s] ? [s] Sim [n] Nao\n", sol_cont->endereco.cep);
  opcao=getchar();
  if (opcao=='s'){
     printf ("Digite o novo CEP:\n");
     fflush(stdin);
     gets (sol_cont->endereco.cep);
   }
     fflush(stdin);

     printf ("\n");
     printf ("Data de nascimento:\n");
     printf ("Alterar dia [%s] ? [s] Sim [n] Nao\n", sol_cont->data_nascimento.dia);
     opcao=getchar();
      if (opcao=='s'){
         printf ("Digite o novo dia:\n");
         fflush(stdin);
         gets (sol_cont->data_nascimento.dia);
       }
      fflush(stdin);
     printf ("Alterar mes [%s] ? [s] Sim [n] Nao\n", sol_cont->data_nascimento.mes);
     opcao=getchar();
      if (opcao=='s'){
         printf ("Digite o novo mes:\n");
         fflush(stdin);
         gets (sol_cont->data_nascimento.mes);
       }
      fflush(stdin);
     printf ("Alterar ano [%s] ? [s] Sim [n] Nao\n", sol_cont->data_nascimento.ano);
     opcao=getchar();
      if (opcao=='s'){
         printf ("Digite o novo Ano:\n");
         fflush(stdin);
         gets (sol_cont->data_nascimento.ano);
       }
	 //fflush(stdin);
	  fflush(stdin);
	 system("CLS");
     printf ("\nRegistro alterado com sucesso!\n\n");
	 }

// funcao solicita dados contato

void solicita_dados_contato(contato * sol_cont){

     printf("Telefones\n");
     printf (" Residencial:");
     gets (sol_cont->telefone.residencial);;
     printf (" Celular:");
     gets (sol_cont->telefone.celular);
     printf (" Comercial:");
     gets (sol_cont->telefone.comercial);
     printf ("\n");
     printf ("e-mail:");
     gets (sol_cont-> email);
     printf ("\n");
     printf ("Endereco:\n");
     printf (" Logradouro:");
     gets (sol_cont->endereco.log);
     printf (" Numero:");
     gets (sol_cont->endereco.num);
     printf (" Bairro:");
     gets (sol_cont->endereco.bairro);;
     printf (" Cidade:");
     gets (sol_cont->endereco.cidade);
     printf (" Estado:");
     gets (sol_cont->endereco.estado);
     printf (" Cep:");
     gets (sol_cont->endereco.cep);
     printf ("\n");
     printf ("Data de nascimento:\n");
     printf (" Dia:");
     gets(sol_cont->data_nascimento.dia);
     fflush(stdin);
     printf (" Mes:");
     gets(sol_cont->data_nascimento.mes);
     fflush(stdin);
     printf (" Ano:");
     gets(sol_cont->data_nascimento.ano);
	 fflush(stdin);

}
// funcao Mostra Dados

void mostra_dados (contato *cont){

     printf ("\nDados do Contato\n");
     printf ("----------------------------------------------------------\n");
     printf ("Nome: %s\n\n", cont->nome);
	 printf ("Telefones:\n");
     printf (" Residencial: %s    ", cont->telefone.residencial);
     printf (" Celular: %s    ", cont->telefone.celular);
     printf (" Comercial: %s\n\n", cont->telefone.comercial);
	 printf ("e-mail:%s\n\n", cont-> email);
	 printf ("Endereco:\n");
     printf (" Logradouro:%s    ", cont->endereco.log);
     printf (" Numero:%s\n", cont->endereco.num);
     printf (" Bairro:%s    ", cont->endereco.bairro);
     printf (" Cidade:%s\n", cont->endereco.cidade);
     printf (" Estado:%s    ", cont->endereco.estado);
     printf (" Cep:%s\n\n", cont->endereco.cep);
	 printf ("Data de nascimento: %s/",cont->data_nascimento.dia);
	 printf ("%s/",cont->data_nascimento.mes);
	 printf ("%s\n",cont->data_nascimento.ano );
     printf ("----------------------------------------------------------\n\n");

}


// funcao escolha contato caso a busca retorne mais de 1 registro

int escolhe_contato(int n, contato * contatos[]){
    int i, opcao=0;

    printf ("Escolha um contato pelo numero:\n");
    for (i=0; i<n; i++)
        printf ("%d - %s\n", i+1, contatos[i]->nome);
    while (!(opcao>=1) && (opcao<=n)){
          printf ("Contato escolhido:\n");
          scanf ("%d", &opcao);
          fflush(stdin);
    }
    return (opcao-1);
}


// funcao inclui altera exclui dados do contato

char inclui_altera_exclui(){
     char opcao='x';

     while (strchr("IANEiane", opcao)==NULL){
           printf ("Escola uma opcao:\n ");
		   printf ("[I]ncluir novo contato\n ");
           printf ("[A]lterar contato\n ");
           printf ("[E]xcluir contato\n ");
           printf ("[N]ova consulta\n ");
           opcao=getchar();
           fflush(stdin);
           system("CLS");
     }
     return(toupper(opcao));
}
