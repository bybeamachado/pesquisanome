#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void limpezabuffer() // Limpar buffer
{ 
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}



void CadastrarNome(char nomes[10][40]) // Cadastrar nomes
{
    int i,j;
    system("cls");
	printf("Listagem de nomes\n\n");
    for (i = 0; i <= 9; i++) {
    	printf("Digite o %2do. nome: ", i + 1);
        fflush(stdin);
        fgets(nomes[i], 40, stdin);
    }
    printf("\nPressione Enter para retornar ao menu");
    getchar();
    system("cls");
}



void PesquisarNome(char nomes[10][40]) // Pesquisar nomes
{
    int i, acha;
    char PESQ[40], RESP, temp[40];
  	system("cls");
	printf("\nPesquisa sequencial de nomes\n\n");

    RESP = 'S';
    while (RESP == 'S' || RESP == 's') {
    printf("Entre o nome a ser pesquisado: ");
    fgets(PESQ, 40, stdin);
	PESQ[strcspn(PESQ, "\n")] = '\0';

    i = 0;
    acha = 0;

	while (i <= 9 && acha == 0) {
    strcpy(temp, nomes[i]);
	temp[strcspn(temp, "\n")] = '\0';

    if (strcmp(PESQ, temp) == 0)
        acha = 1;
    else
        i++;
    }

	if (acha == 1)
    printf("'%s' foi encontrado na POSICAO %d (ordem de cadastro).\n", PESQ, i + 1);
    else
    printf("\n'%s' nao foi localizado.\n", PESQ);

    printf("\nDeseja pesquisar outro nome? [S]IM / [N]AO: ");
    RESP = getchar();
	limpezabuffer();
	system("cls");
    }
}



void OrdenarNome(char nomes[10][40]) // Ordenar nomes em ordem alfabética
{
    int i, j, x[40];
system("cls");

    for (i = 0; i <= 8; i++)
    for (j = i + 1; j <= 9; j++)
    if (strcmp(nomes[i], nomes[j]) > 0) {
    strcpy(x, nomes[i]);
    strcpy(nomes[i], nomes[j]);
    strcpy(nomes[j], x);
    }

	printf("\n");
    for (i = 0; i <= 9; i++)
        printf("Nome: %2d --> %s", i + 1, nomes[i]);

    printf("\nPressione Enter para retornar ao menu");
    getchar();
    system("cls");
}


int main(void) // Função principal
{
    char nomes[10][40];
    int cadastrados = 0;
    int opcao;
    int i, j;

    do {
        printf("\n========= MENU =========\n");
    	printf("1. Cadastrar Nome\n");
    	printf("2. Pesquisar Nome\n");
    	printf("3. Apresentar Nomes em Ordem Alfabetica\n");
    	printf("4. Sair\n");
    	printf("========================\n");
    	printf("Escolha uma opcao: ");
    	scanf("%d", &opcao);
    	
        limpezabuffer();

        switch (opcao) {
            case 1:
                CadastrarNome(nomes);
                break;

            case 2:
                PesquisarNome(nomes);
                break;

            case 3:
                OrdenarNome(nomes);
                break;

            case 4:
               	system("cls");
    			printf("Encerrando o programa. Ate logo!\n");
                break;

            default:
                printf("Opcao invalida. Digite um numero entre 1 e 4.\n");
                printf("\nPressione Enter para tentar novamente");
                getchar();
                system("cls");
                break;
        }

    } while (opcao != 4);

    return 0;
}

