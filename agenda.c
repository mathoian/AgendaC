#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"



int main()
{
    char nome[30]="xxx";
    int nreg, indice;
    contato *agenda = NULL;
    contato *contatos[100];
    contato *novo;
    char op;
    printf ("----------------------------------------------------------\n");
	printf("\t\tAGENDA PESSOAL\n");
    printf ("----------------------------------------------------------\n");
	while (!(ta_vazio(nome))){
          printf("Digite um nome a seguir para buscar ou incluir na agenda: \n");
          //printf("retorno %d\n",ta_vazio(nome));
          gets (nome);
          printf("\n");
          //printf("retorno %d\n",ta_vazio(nome));
          if (ta_vazio(nome)) break;
          nreg=consulta(agenda,nome,contatos);
          //nreg=0;
          if (nreg==0){ // caso n�o acho nenhum contato
             printf("Incluindo novo registro: \n");
			 novo=(contato*)malloc(sizeof(contato));
             if (novo==NULL)
             aborte(1);
             strcpy(novo->nome, nome) ;
             solicita_dados_contato(novo);
             inclusao (&agenda, novo);

		  }
          else if (nreg==1){
               scanf("%*c");
               printf("Encontrado 1 registro: \n");
			   mostra_dados (contatos[0]);
               op=inclui_altera_exclui();
               if (op=='A')
                  alteracao(contatos[0]);
               else if (op=='E')
                  exclusao(&agenda, contatos[0]);
               else if (op=='I')
			   {
               novo=(contato*) malloc (sizeof(contato));
                    if (novo==NULL)
                    aborte(1);
               printf("Digite um nome a seguir para incluir na agenda: \n");
               gets (nome);
               printf("\n");
               strcpy(novo->nome, nome) ;
               solicita_dados_contato(novo);
               inclusao (&agenda, novo);
               }
          }
          else { //nreg > 1
          scanf("%*c");
  	         printf("Encontrado %d registros: \n", nreg);
             indice=escolhe_contato (nreg, contatos);
             mostra_dados(contatos[indice]);
             op=inclui_altera_exclui();
             if (op=='A')
                  alteracao(contatos[indice]);
             else if (op=='E')
                  exclusao (&agenda, contatos[indice]);
             else if (op=='I'){
                  novo=(contato*)malloc(sizeof(contato));
                  if (novo==NULL) aborte(1);
                  //strcpy(novo->nome, nome) ;
                  printf("Digite um nome a seguir para incluir na agenda: \n");
          		  gets (nome);
          		  printf("\n");
          		  strcpy(novo->nome, nome);
                  solicita_dados_contato(novo);
                  inclusao (&agenda, novo);
               }
          }

    }

  //  system("PAUSE");
   return 0;
}
