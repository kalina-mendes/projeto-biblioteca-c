#include <stdio.h>
#include <string.h>

#define TAMANHO_ACERVO 20

struct Livro {
    int codigo;
    char titulo[50];
    char autor[30];
    char area[30];
    int ano;
    char editora[30];
};

void limpar_buffer(); //Função usada para limpar o buffer do teclado. Necessária quando usamos scanf seguido de fgets.
void salvarAcervo(struct Livro acervo[], int qtd); //Salva o acervo atual em um arquivo texto (acervo.txt).
int carregarAcervo(struct Livro acervo[]); //Carrega o acervo do arquivo acervo.txt (se existir).
int cadastrarLivros(struct Livro acervo[], int qtdAtual, int tamanhoMax); //Cadastra novos livros no acervo.
void imprimirLivros(struct Livro acervo[], int qtd); //Imprime todos os livros cadastrados.
void pesquisarLivros(struct Livro acervo[], int qtd); //Pesquisa um livro pelo código informado.
void ordenarLivros(struct Livro acervo[], int qtd); //Ordena os livros pelo ano usando Bubble Sort.

int main(void) {

    struct Livro acervo[TAMANHO_ACERVO];
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
                qtdLivros = cadastrarLivros(acervo, qtdLivros, TAMANHO_ACERVO);
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

void limpar_buffer(){ // Descarta caracteres até encontrar '\n'
    int c;
    while((c = getchar()) != '\n' && c != EOF){}
}

void salvarAcervo(struct Livro acervo[], int qtd) { // Abre arquivo para escrita (sobrescreve o conteúdo)
    FILE *arq = fopen("acervo.txt", "w");
    if(!arq){
        printf("Erro ao salvar arquivo!\n");
        return;
    }

    for(int i = 0; i < qtd; i++){ // Salva cada livro em uma linha separada
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

int carregarAcervo(struct Livro acervo[]) { // Abre arquivo para leitura
    FILE *arq = fopen("acervo.txt", "r");
    if(!arq){
        printf("Primeira execucao, nenhum arquivo encontrado.\n");
        return 0;
    }

    int qtd = 0;

    while(qtd < TAMANHO_ACERVO && 
        fscanf(arq, "%d;%49[^;];%29[^;];%29[^;];%d;%29[^\n]\n",
            &acervo[qtd].codigo,
            acervo[qtd].titulo,
            acervo[qtd].autor,
            acervo[qtd].area,
            &acervo[qtd].ano,
            acervo[qtd].editora) == 6) // Lê cada linha do arquivo até acabar ou chegar ao limite
    {
        qtd++;
    }

    fclose(arq);
    printf("Acervo carregado: %d livros.\n", qtd);
    return qtd;
}

int cadastrarLivros(struct Livro acervo[], int qtdAtual, int tamanhoMax){ // Pergunta quantos novos livros serão cadastrados

    int qtdNova;
    printf("Quantos livros deseja cadastrar (max %d)? ", tamanhoMax - qtdAtual);
    scanf("%d", &qtdNova);
    limpar_buffer();

    if(qtdNova < 1 || qtdAtual + qtdNova > tamanhoMax){ // Validação da quantidade pedida
        printf("Quantidade invalida!\n");
        return qtdAtual;
    }

    for(int i = qtdAtual; i < qtdAtual + qtdNova; i++){ // Realiza o cadastro dos novos livros

        printf("\n-----CADASTRO %d-----\n", i + 1);

        printf("Codigo: ");
        scanf("%d", &acervo[i].codigo);
        limpar_buffer();

        printf("Titulo: ");
        fgets(acervo[i].titulo, 50, stdin); // fgets usado para strings, removendo a quebra de linha
        acervo[i].titulo[strcspn(acervo[i].titulo, "\n")] = 0;

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

    return qtdAtual + qtdNova; // Retorna a nova quantidade total
}

void imprimirLivros(struct Livro acervo[], int qtd){
    printf("\n-----LISTA DE LIVROS-----\n");
    for(int i = 0; i < qtd; i++){  // Percorre o vetor imprimindo cada livro
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

    for(int i = 0; i < qtd; i++){ // Busca linear pelo código
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

    for(int i = 0; i < qtd - 1; i++){  // Bubble Sort para ordenar por ano
        for(int j = 0; j < qtd - 1 - i; j++){
            if(acervo[j].ano > acervo[j+1].ano){
                temp = acervo[j];
                acervo[j] = acervo[j+1];
                acervo[j+1] = temp;
            }
        }
    }

    printf("\nLivros ordenados! Veja na opcao 2.\n");
}
