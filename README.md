# atividade_avaliativa3
Implementar um sistema de controle de estoque com as funcionalidades de cadastrar produtos, consultar produtos, gerar relatório de produtos e remover produtos do estoque.
Funções que deverão estar presentes no código:

Função que inicializa uma lista vazia; (0,5 ponto)
Função que adiciona um novo produto à lista de estoque. Ela solicita ao usuário informações como código, descrição, quantidade e valor do produto. (0,5 ponto)
Função que percorre a lista de estoque e imprime um relatório com as informações de cada produto, incluindo código, descrição, quantidade e valor. (0,5 ponto)
Função que permite ao usuário pesquisar um produto pelo código. (0,5 ponto)
Função que permite ao usuário remover um produto do estoque.
Ela solicita o código do produto a ser removido e busca na lista o produto correspondente.
Se encontrar o produto, o remove da lista. Caso contrário, exibe uma mensagem informando que o produto não está cadastrado. (1,0 ponto)
O sistema deverá exibir um menu com as opções disponíveis e realizar as chamadas correspondentes às funções acima, de acordo com a escolha do usuário.
O loop deverá continuar até que o usuário escolha sair do programa.

Descrição do codigo feito:

estrutura de dados:
typedef struct Produto: Define uma estrutura chamada Produto que contém informações sobre o produto, como código (cd), nome, quantidade, descrição, preço e um ponteiro para o próximo produto na lista.
Função:
Produto *criarListaVazia(): inicializa uma lista de produtos vazia e retorna um ponteiro nulo.
Produto *criarProduto(): Aloca memória dinamicamente para um novo produto, inicializa seus campos, gera código aleatório e retorna um ponteiro para o novo produto.
void cadastrar(Produto **estoque): Solicita informações do usuário sobre produtos e cadastros na lista de estoque.
void adicionarProduto(Produto **estoque): Semelhante ao registro, adiciona um novo produto à lista de inventário, mas pode aceitá-lo com segurança por um longo período de tempo.
void buscar(Produto *estoque):Permite ao usuário pesquisar produtos na lista de estoque por código e exibir as informações encontradas.
void imprimir(Produto *estoque):Imprime informações sobre todos os produtos da lista de inventário.
void excluir(Produto **estoque): Permite que os usuários excluam produtos da lista de inventário com base no código.
void imprimirRelatorioProduto(Produto *estoque): Imprime um relatório detalhado de todos os produtos da lista de estoque, incluindo código, nome, descrição, quantidade, preço e estoque total de cada produto.

funcao main:
inicializa com rand para gerar codigos aleatórios para os produtos cadastrados
cria uma lista de estoque inicialmente vazia,
criado um switch para assim o usuario decidir qual seria a opcao digitada pelo usuario, que ira continuar até o usuario decidir sair,
libera a memória alocada para a lista de estoque no final do programa. free(temp);

Observações:
O código faz uso de ponteiros e alocação dinâmica de memória.
Utilize a função rand para gerar códigos de produtos aleatórios.
Lida com a entrada do usuário para cadastrar produtos e realizar outras operações.
Apresenta funções para pesquisar, imprimir, excluir e adicionar produtos à lista de estoque.
Inclui uma função para imprimir um relatório detalhado dos produtos no estoque.
Limpa a memória alocada no final do programa.
Por fim, o código constitui um sistema básico de gerenciamento de estoque, oferecendo funcionalidades essenciais para manipular produtos em uma lista encadeada.

