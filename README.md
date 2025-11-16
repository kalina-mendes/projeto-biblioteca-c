📚 Sistema de Gerenciamento de Acervo de Livros em C

📖 Descrição do Projeto

Este é um sistema simples desenvolvido em linguagem C para gerenciar um acervo de livros. Ele utiliza **structs** para definir a estrutura dos livros e realiza manipulação de **arquivos de texto** (`acervo.txt`) para garantir a persistência dos dados entre as execuções do programa.

✨ Funcionalidades

O programa oferece as seguintes opções através de um menu interativo:

* **Cadastrar Livros:** Adiciona novos livros ao acervo, solicitando informações como código, título, autor, área, ano e editora.
* **Imprimir Acervo:** Exibe a lista completa de todos os livros cadastrados.
* **Pesquisar Livro:** Busca e exibe os detalhes de um livro específico usando seu código.
* **Ordenar Livros:** Organiza o acervo por **ano de publicação** utilizando o algoritmo **Bubble Sort**.
* **Persistência de Dados:** Carrega o acervo salvo no arquivo `acervo.txt` ao iniciar e salva automaticamente os dados ao sair do programa (Opção 5).

💻 Como Compilar e Executar

Para rodar este projeto, você precisa ter um compilador C (como o **GCC**) instalado em seu sistema.

-> Compilação
1. Navegue até a pasta do projeto no seu terminal.
2. Compile o código com o GCC:

```bash
gcc gerenciamento_livros.c -o biblioteca
Execute o programa:

Bash

./biblioteca
⚙️ Tecnologia Utilizada
Linguagem: C

Ferramentas: GCC (GNU Compiler Collection)

✍️ Autor
Kalina Mendes

Este projeto foi desenvolvido como exercício de programação estruturada em C.
