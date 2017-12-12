#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//come�a fazendo uma estrutura onde vai ser buscado os dados do contato para a agenda.
struct Contato{
  char nome[100];
  int  telefone;
};

int main(){
  //o ponteiro  para  o endre�o do conteudo buscado na estruturas dinamicas com os dados da agenda.
  struct Contato *agenda;
  int cap; //Capacidade do vetor (tamanho real do vetor).
  int n;   //Numero de contatos cadastrados (tamanho usado).
  int opc; //Opcao do menu selecionada.
  int i;
  FILE *fp;

  //Abrindo arquivo em modo de leitura ("r" = read).
  fp = fopen("agenda.dat","r");

  //Se retorna NULL eh pq nao encontrou o arquivo.
  //Isso acontece na primeira vez que rodamos o programa.
  if(fp==NULL){
    n = 0;    //Base de dados inicialmente vazia.
    cap = 20; //Fixamos uma capacidade inicial (ex: 20).

    //Alocammos o vetor de estruturas de forma
    //dinamica conforme a capacidade.
    agenda = (struct Contato *)malloc(sizeof(struct Contato)*cap);
  }
  else{ //Arquivo encontrado, logo procedemos com a leitura.

    //Le o numero de registros.
    fread(&n, sizeof(int), 1, fp);

    //A capacidade deve ser maior ou igual a "n" (ex: n*2).
    cap = n*2;

    //Alocammos o vetor de estruturas de forma
    //dinamica conforme a capacidade.
    agenda = (struct Contato *)malloc(sizeof(struct Contato)*cap);

    //Leitura dos dados dos registros do arquivo para o vetor.
    fread(agenda, sizeof(struct Contato), n, fp);

    //Fecha arquivo apos leitura.
    fclose(fp);
  }

  do{
    //Exibe o menu de opcoes.
    printf("*** Menu ***\n");
    printf("1) Cadastrar contato.\n");
    printf("2) Exibir contatos.\n");
    printf("3) Apagar.\n");
    printf("4) Sair.\n");
    //Le a opcao selecionada.
    scanf("%d",&opc);

    if(opc==1){
      //Inserir novo contato no final do vetor.

      if(n==cap){
	//Capacidade esgotada, devemos aumentar o
	//vetor usando "realloc" (ex: dobrar capacidade).
	     cap *= 2;
         agenda = realloc(agenda, sizeof(struct Contato)*cap);
      }
      //Leitura dos dados.
      printf("Digite o nome: ");
      scanf(" %[^\n]",agenda[n].nome);
      printf("Digite o telefone: ");
      scanf("%d",&agenda[n].telefone);
      n++; //Incrementa numero de registros cadastrados.
    }
    else if(opc==2){
      //Exibe todos contatos cadastrados.
      for(i=0; i<n; i++){
	    printf("*** Contato %d ***\n",i+1);
        printf("Nome: %s\n",agenda[i].nome);
	    printf("Telefone: %d\n",agenda[i].telefone);
      }
    }
    else if(opc==3){
      //Apaga um contato
      char nome[100];
      int j;
      scanf("%s",&nome);
      for(i=0; i<n; i++){
             if (strcmp(agenda[i].nome, nome)==0){
             	for(j=i+1; j<n; j++){
                         strcpy(agenda[j-1].nome,agenda[j].nome);
                         agenda[j-1].telefone=agenda[j].telefone;
                 }
               n--;
               i=n;
              }
      }
    }
    //Enquanto nao for opcao de saida continua mostrando menu.
  }while(opc!=4);

  if(n>0){
    //Se existe algum contato cadastrado
    //entao grava para o disco.

    //Abre arquivo em modo de gravacao ("w" = write).
    fp = fopen("agenda.dat","w");

    //Grava o numero de contatos no inicio do arquivo.
    fwrite(&n, sizeof(int), 1, fp);

    //Grava os dados do vetor no arquivo.
    fwrite(agenda, sizeof(struct Contato), n, fp);


    //Fecha arquivo apos a gravacao.
    fclose(fp);
  }

  //Libera a memoria alocada do vetor.
  free(agenda);
    fgets;

}
