/* Arquivo agenda.h - declaração de dados da Agenda Pessoal */

struct nodo_agenda { //nome da estrutura
       char nome[30];
       struct { // nao precisa declarar o nome da estrutura pq não será referencioada no programa
              char residencial[15];
              char celular[15];
              char comercial[15];
              } telefone; // variavel
       char email[30];
       struct {
              char log[50];
              char num[8];
              char bairro[20];
              char cidade[20];
              char estado[3]; // 1 caractere a mais para o \0
              char cep[10];
              } endereco;
              
       struct{
              char dia[3];
              char mes[3];
              char ano[5];
              } data_nascimento;
              
       struct nodo_agenda * prox; // o nome do tipo é necessario pois será referenciado

};     

typedef struct nodo_agenda contato;
void aborte (int);
int consulta (contato *, char [], contato * []);
void mystrupr(char *);
int ta_vazio(char []);
void inclusao (contato **, contato *);
void exclusao(contato **, contato * );
void alteracao(contato *);
void solicita_dados_contato(contato *);
void mostra_dados (contato *);
int escolhe_contato(int , contato * []);
char inclui_altera_exclui();
