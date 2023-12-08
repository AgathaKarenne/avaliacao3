#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int cd;
    char nome[50];
    int quantidade;
    char descricao[100];
    float preco;
    struct Produto *prox;
} Produto;

// função que inicializa uma lista vazia
Produto *criarListaVazia()
{
    return NULL;
}
// função para criar codigos de produto
Produto *criarProduto()
{
    Produto *novoProduto;
    novoProduto = (Produto *)malloc(sizeof(Produto));
    if (novoProduto == NULL)
    {
        printf("Erro de alocacao\n");
        exit(EXIT_FAILURE);
    }
    novoProduto->cd = rand(); // usar rand para gerar codigos aleatorios para os produtos
    novoProduto->prox = NULL;
    return novoProduto;
}
// função para adicionar caracteristicas dos produtos a lista
void cadastrar(Produto **estoque) //** ponteiro que aponta para outro ponteiro
{
    printf("\nCadastro dos Produtos\n");

    Produto *novoProduto = criarProduto();

    printf("Digite o nome do produto: ");
    scanf("%s", novoProduto->nome);

    printf("Informe a quantidade do produto: ");
    scanf("%d", &novoProduto->quantidade);

    printf("Informe o preco individual do produto: ");
    scanf("%f", &novoProduto->preco);

    novoProduto->prox = *estoque;
    *estoque = novoProduto;

    printf("Produto cadastrado com sucesso!\n");
}
// função que adiciona um novo produto à lista de estoque. Ela solicita ao usuário informações como código, descrição, quantidade e valor do produto.
void adicionaProduto(Produto **estoque)
{

    printf("\nAdicionar novo produto a lista cadastrar\n");
    // chamar o novo codigo de um novo produto
    Produto *novoProduto = criarProduto();

    printf("Digite o nome do novo produto:");
    scanf("%s", novoProduto->nome);

    printf("Descreva o produto:");
    getchar(); // Limpar o buffer do teclado
    fgets(novoProduto->descricao, sizeof(novoProduto->descricao), stdin);
    novoProduto->descricao[strcspn(novoProduto->descricao, "\n")] = '\0'; // Remover o caractere de nova linha

    printf("Informe a quantidade do produto: ");
    scanf("%d", &novoProduto->quantidade);

    printf("Informe o preco individual do produto: ");
    scanf("%f", &novoProduto->preco);

    novoProduto->prox = *estoque;
    *estoque = novoProduto;

    // imprimir mensagem para mostrar cadastro do produto
    printf("Novo produto cadastrado com sucesso!\n");
}
// função que busca produto pelo codigo fornecido
// função que permite ao usuário pesquisar um produto pelo código.
void buscar(Produto *estoque)
{
    int cd;
    printf("Buscar Produto\n");

    printf("Código do produto: ");
    scanf("%d", &cd);

    Produto *atual = estoque;

    while (atual != NULL)
    {
        if (atual->cd == cd)
        {
            printf("Produto encontrado:\n");
            printf("Código: %d\n", atual->cd);
            printf("Nome: %s\n", atual->nome);
            printf("Quantidade: %d\n", atual->quantidade);
            printf("Preço: %.2f\n", atual->preco);
            return;
        }
        atual = atual->prox;
    }

    printf("Produto não encontrado.\n");
}
// imprimir todos os produtos
void imprimir(Produto *estoque)
{
    printf("Lista de Produtos\n");

    if (estoque == NULL)
    {
        printf("Estoque vazio.\n");
        return;
    }

    Produto *atual = estoque;

    while (atual != NULL)
    {
        printf("Código: %d, Nome: %s, Quantidade: %d, Preço: %.2f\n",
               atual->cd, atual->nome, atual->quantidade, atual->preco);
        atual = atual->prox;
    }
}
// Função que permite ao usuário remover um produto do estoque.
// Ela solicita o código do produto a ser removido e busca na lista o produto correspondente.
// Se encontrar o produto, o remove da lista. Caso contrário, exibe uma mensagem informando que o produto não está cadastrado.
void excluir(Produto **estoque)
{
    int codigo;
    printf("Excluir Produto\n");

    printf("Código do produto: ");
    scanf("%d", &codigo);

    Produto *atual = *estoque;
    Produto *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->cd == codigo)
        {
            if (anterior == NULL)
            {
                *estoque = atual->prox;
            }
            else
            {
                anterior->prox = atual->prox;
            }

            free(atual);
            printf("Produto removido com sucesso!\n");
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }

    printf("Produto não encontrado.\n");
    return;
}
// função que percorre a lista de estoque e imprime um relatório com as informações de cada produto, incluindo código, descrição, quantidade e valor.
void imprimirRelatorioProduto(Produto *estoque)
{

    printf("\nRelatorio Dos Produtos\n");

    // trazer o estoque dos produtos
    Produto *atual = estoque;

    // se a lista atual for diferente de nulo imprima as caracteristicas da lista
    while (atual != NULL)
    {
        printf("Código: %d\n", atual->cd);
        printf("Nome: %s\n", atual->nome);
        printf("Descricao: %c\n", atual->descricao);
        printf("Quantidade: %d\n", atual->quantidade);
        printf("Preço: %.2f\n", atual->preco);
        // calculo geral dos produtos:quanto ficaria comprar todas as quantidades de produtos dados pelo algoritimo
        printf("Total do Estoque de Produtos: R$ %.2f\n", atual->quantidade * atual->preco);

        // atual lista deve receber os proximos detalhes da lista
        atual = atual->prox;
    }
}
main()
{
    srand((unsigned int)time(NULL)); // gerar sempre codigos diferentes
    Produto *estoque = criarListaVazia();
    int opcao;

    do
    {
        printf("\n1: Cadastrar Produto");
        printf("\n2: Imprimir Estoque");
        printf("\n3: Buscar Produto");
        printf("\n4: Excluir Produto");
        // adiciona um novo produto à lista de estoque. Ela solicita ao usuário informações como código, descrição, quantidade e valor do produto.
        printf("\n5: Adicionar Novo Produto");
        // imprimir relatorio detalhado da lista de produtos cadastrados
        printf("\n6: Imprimir Relatorio Dos Produtos");
        printf("\n0: Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrar(&estoque);
            break;
        case 2:
            imprimir(estoque);
            break;
        case 3:
            buscar(estoque);
            break;
        case 4:
            excluir(&estoque);
            break;
        case 5:
            adicionaProduto(&estoque);
            break;
        case 6:
            imprimirRelatorioProduto(estoque);
            break;
        case 0:
            printf("Programa encerrado!\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    // Limpar a memória alocada
    Produto *atual = estoque;
    while (atual != NULL)
    {
        Produto *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}
