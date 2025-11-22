#include <stdio.h>
#include <string.h>

/**
 * @brief Estrutura para representar os livros do acervo.
 */
struct Livro {
    int codigo;         ///< Codigo identificador do livro
    char titulo[50];    ///< Titulo do livro 
    char autor[30];     ///< Nome do autor
    char area[30];      ///< Area tematica do livro
    int ano;            ///< Ano de publicacao do livro
    char editora[30];   ///< Nome da editora do livro
};

/**
 * @defgroup Acervo Funções relacionadas ao acervo de livros
 * @{
 */

/**
 * @brief Função para limpar o buffer do teclado.
 * @ingroup Acervo
 */
void limpar_buffer();

/**
 * @brief Função para salvar o acervo em arquivo de texto.
 * @ingroup Acervo
 */
void salvarAcervo(struct Livro acervo[], int qtd); 

/**
 * @brief Função para carregar o acervo se existir.
 * @ingroup Acervo
 */
int carregarAcervo(struct Livro acervo[]); 

/**
 * @brief Função para cadastrar os livros no acervo.
 * @ingroup Acervo
 */
int cadastrarLivros(struct Livro acervo[], int qtdAtual, int tamanhoMax);

/**
 * @brief Função para imprimir os livros cadastrados no acervo.
 * @ingroup Acervo
 */
void imprimirLivros(struct Livro acervo[], int qtd);

/**
 * @brief Função para pesquisar pelo codigo informado os livros no acervo.
 * @ingroup Acervo
 */
void pesquisarLivros(struct Livro acervo[], int qtd);

/**
 * @brief Função para ordenar os livros do acervo.
 * @ingroup Acervo
 */
void ordenarLivros(struct Livro acervo[], int qtd);

/** @} */

/**
 * @brief Função principal do programa.
 *
 * @details Exibe o menu principal, gerencia a interação com o usuário
 * e chama as funções responsáveis por cadastrar, imprimir, pesquisar,
 * ordenar e salvar os livros do acervo.
 *
 * @return Retorna 0 ao finalizar.
 */
int main(void) {

    struct Livro acervo[20];
    int menu;
    int qtdLivros = 0;

    qtdLivros = carregarAcervo(acervo);

    do {
        printf("\n------------MENU------------\n");
        printf("1 - Cadastrar livros\n");
        printf("2 - Imprimir todos os livros\n");
        printf("3 - Pesquisar livro por codigo\n");
        printf("4 - Ordenar livros por ano\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &menu);
        limpar_buffer();

        switch(menu) {

            case 1:
                qtdLivros = cadastrarLivros(acervo, qtdLivros, 20);
                break;

            case 2:
                if(qtdLivros == 0) {
                    printf("\nNenhum livro cadastrado!\n");
                } else {
                    imprimirLivros(acervo, qtdLivros);
                }
                break;

            case 3:
                if(qtdLivros == 0) {
                    printf("\nNenhum livro cadastrado!\n");
                } else {
                    pesquisarLivros(acervo, qtdLivros);
                }
                break;

            case 4:
                if(qtdLivros == 0) {
                    printf("\nNenhum livro cadastrado!\n");
                } else {
                    ordenarLivros(acervo, qtdLivros);
                }
                break;

            case 5:
                printf("\nSaindo...\n");
                salvarAcervo(acervo, qtdLivros);
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(menu != 5);

    return 0;
}

void limpar_buffer(){ 
    int c;
    while((c = getchar()) != '\n' && c != EOF){}
}

void salvarAcervo(struct Livro acervo[], int qtd) { //Grava cada livro no arquivo em formato CSV simples.
    FILE *arq = fopen("acervo.txt", "w");
    if(!arq){
        printf("Erro ao salvar arquivo!\n");
        return;
    }

    for(int i = 0; i < qtd; i++){ 
        fprintf(arq, "%d;%s;%s;%s;%d;%s\n",
            acervo[i].codigo,
            acervo[i].titulo,
            acervo[i].autor,
            acervo[i].area,
            acervo[i].ano,
            acervo[i].editora);
    }

    fclose(arq);
    printf("Acervo salvo!\n");
}

int carregarAcervo(struct Livro acervo[]) { //Carrega o acervo de livros salvos (se existir).
    FILE *arq = fopen("acervo.txt", "r");
    if(!arq){
        printf("Primeira execucao, nenhum arquivo encontrado.\n");
        return 0;
    }

    int qtd = 0;

    while(qtd < 20 &&
        fscanf(arq, "%d;%49[^;];%29[^;];%29[^;];%d;%29[^\n]\n",
            &acervo[qtd].codigo,
            acervo[qtd].titulo,
            acervo[qtd].autor,
            acervo[qtd].area,
            &acervo[qtd].ano,
            acervo[qtd].editora) == 6) 
    {
        qtd++;
    }

    fclose(arq);
    printf("Acervo carregado: %d livros.\n", qtd);
    return qtd;
}

int cadastrarLivros(struct Livro acervo[], int qtdAtual, int tamanhoMax){ 

    int qtdNova;
    printf("Quantos livros deseja cadastrar (max %d)? ", tamanhoMax - qtdAtual);
    scanf("%d", &qtdNova);
    limpar_buffer();

    if(qtdNova < 1 || qtdAtual + qtdNova > tamanhoMax){
        printf("Quantidade invalida!\n");
        return qtdAtual;
    }

    for(int i = qtdAtual; i < qtdAtual + qtdNova; i++){ 

        printf("\n-----CADASTRO %d-----\n", i + 1);

        printf("Codigo: ");
        scanf("%d", &acervo[i].codigo);
        limpar_buffer();

        printf("Titulo: ");
        fgets(acervo[i].titulo, 50, stdin); 
        acervo[i].titulo[strcspn(acervo[i].titulo, "\n")] = 0; //Remove o \n do final.

        printf("Autor: ");
        fgets(acervo[i].autor, 30, stdin);
        acervo[i].autor[strcspn(acervo[i].autor, "\n")] = 0;

        printf("Area: ");
        fgets(acervo[i].area, 30, stdin);
        acervo[i].area[strcspn(acervo[i].area, "\n")] = 0;

        printf("Ano: ");
        scanf("%d", &acervo[i].ano);
        limpar_buffer();

        printf("Editora: ");
        fgets(acervo[i].editora, 30, stdin);
        acervo[i].editora[strcspn(acervo[i].editora, "\n")] = 0;
    }

    return qtdAtual + qtdNova;
}

void imprimirLivros(struct Livro acervo[], int qtd){ //Imprime cada livro cadastrado.
    printf("\n-----LISTA DE LIVROS-----\n");
    for(int i = 0; i < qtd; i++){  
        printf("\nCodigo: %d\nTitulo: %s\nAutor: %s\nArea: %s\nAno: %d\nEditora: %s\n", 
            acervo[i].codigo,
            acervo[i].titulo,
            acervo[i].autor,
            acervo[i].area,
            acervo[i].ano,
            acervo[i].editora);
        printf("-------------------------\n");
    }
}

void pesquisarLivros(struct Livro acervo[], int qtd){
    int codigo, encontrado = 0;

    printf("\nDigite o codigo do livro: ");
    scanf("%d", &codigo);

    for(int i = 0; i < qtd; i++){ //Procura um livro com o código informado.
        if(acervo[i].codigo == codigo){
            printf("\n-----LIVRO ENCONTRADO-----\n");
            printf("Codigo: %d\nTitulo: %s\nAutor: %s\nArea: %s\nAno: %d\nEditora: %s\n",
                acervo[i].codigo,
                acervo[i].titulo,
                acervo[i].autor,
                acervo[i].area,
                acervo[i].ano,
                acervo[i].editora);
            printf("---------------------------\n");
            encontrado = 1;
            break;
        }
    }

    if(!encontrado){
        printf("\nLivro nao encontrado.\n");
    }
}

void ordenarLivros(struct Livro acervo[], int qtd){
    struct Livro temp;

    for(int i = 0; i < qtd - 1; i++){  
        for(int j = 0; j < qtd - 1 - i; j++){
            if(acervo[j].ano > acervo[j+1].ano){ //Compara os anos: se o livro atual (j) for mais novo que o próximo (j+1).
                temp = acervo[j];
                acervo[j] = acervo[j+1];
                acervo[j+1] = temp;
            }
        }
    }

    printf("\nLivros ordenados! Veja na opcao 2.\n");
}
