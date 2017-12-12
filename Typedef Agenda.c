#include <stdio.h>
#include <stdlib.h>

int main () {

	typedef	struct {

		char nome[20];
		int celular;

	} agenda;

	agenda agenda_celular, conjunto_estrutura[20];

	strcpy(agenda_celular.nome, "Maria");
	agenda_celular.celular = 726258;

	conjunto_estrutura[2].nome[2] = "Jo�o";
	conjunto_estrutura[2].celular = 85858;

	system("pause");
	return(0);

}
