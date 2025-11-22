# 📚 Sistema de Gerenciamento de Acervo de Livros

Sistema simples de gerenciamento de biblioteca desenvolvido em C para cadastro, consulta e organização de livros.

## 🚀 Funcionalidades

- **Cadastrar livros**: Adicione novos livros ao acervo com informações completas
- **Listar livros**: Visualize todos os livros cadastrados
- **Pesquisar por código**: Encontre livros específicos através do código identificador
- **Ordenar por ano**: Organize o acervo por ano de publicação
- **Persistência de dados**: Os dados são salvos automaticamente em arquivo de texto

## 📋 Informações Armazenadas

Cada livro contém os seguintes dados:
- Código identificador
- Título
- Autor
- Área temática
- Ano de publicação
- Editora

## 🛠️ Compilação e Execução

### Requisitos
- Compilador C (GCC, Clang, etc.)
- Sistema operacional: Windows, Linux ou macOS
- **Sem dependências externas**: utiliza apenas bibliotecas padrão (`stdio.h` e `string.h`)

### Compilar

```bash
gcc acervo.c -o acervo
```

### Executar

**Linux/macOS:**
```bash
./acervo
```

**Windows:**
```bash
acervo.exe
```

## 💾 Armazenamento

Os dados são salvos no arquivo `acervo.txt` no formato CSV (separado por ponto e vírgula). O arquivo é criado automaticamente ao sair do programa e carregado na próxima execução.

## 📖 Como Usar

1. Execute o programa
2. Escolha uma das opções do menu:

| Opção | Funcionalidade |
|-------|----------------|
| `1` | Cadastrar novos livros |
| `2` | Visualizar todos os livros |
| `3` | Pesquisar livro por código |
| `4` | Ordenar livros por ano |
| `5` | Sair (salva automaticamente) |

## ⚙️ Limitações

- Capacidade máxima: 20 livros
- Tamanho máximo do título: 50 caracteres
- Tamanho máximo dos demais campos de texto: 30 caracteres

## 📝 Exemplo de Uso

```
------------MENU------------
1 - Cadastrar livros
2 - Imprimir todos os livros
3 - Pesquisar livro por codigo
4 - Ordenar livros por ano
5 - Sair
Escolha uma opcao: 1

Quantos livros deseja cadastrar (max 20)? 1

-----CADASTRO 1-----
Codigo: 101
Titulo: Clean Code
Autor: Robert C. Martin
Area: Programacao
Ano: 2008
Editora: Prentice Hall
```

## 🔧 Estrutura do Código

- `struct Livro`: Estrutura para representação dos livros
- `main()`: Função principal com loop do menu
- `cadastrarLivros()`: Cadastro de novos livros
- `imprimirLivros()`: Listagem do acervo
- `pesquisarLivros()`: Busca por código
- `ordenarLivros()`: Ordenação por ano (Bubble Sort)
- `salvarAcervo()`: Persistência em arquivo
- `carregarAcervo()`: Carregamento dos dados salvos

## 📚 Documentação

O código possui **documentação completa em formato Doxygen**, incluindo:
- Descrição detalhada de todas as funções
- Documentação da estrutura de dados
- Agrupamento lógico das funções (`@defgroup` e `@ingroup`)
- Comentários sobre parâmetros e comportamento

### Gerar Documentação HTML

Para gerar a documentação automaticamente com Doxygen:

1. Instale o Doxygen:
   ```bash
   # Ubuntu/Debian
   sudo apt-get install doxygen
   
   # macOS
   brew install doxygen
   
   # Windows
   # Baixe em: https://www.doxygen.nl/download.html
   ```

2. Crie um arquivo de configuração:
   ```bash
   doxygen -g Doxyfile
   ```

3. Gere a documentação:
   ```bash
   doxygen Doxyfile
   ```

4. Abra a documentação gerada em `html/index.html`

## 👨‍💻 Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou pull requests.
