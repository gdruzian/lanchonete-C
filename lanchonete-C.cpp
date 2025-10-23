#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>


struct Produtos{
	int codigo;
	char nome[100];
	float preco;
};

struct Clientes{
	int codigo;
	char nome[100];
};

struct Pedidos{
	int codCliente;
	int codProduto;
	int quantidade;
};

struct Produtos cardapio[100];
struct Clientes listadeclientes[100];
struct Pedidos comandadepedidos[100];

int totprodutos = 0;
int totclientes = 0;
int totpedidos = 0;

void salvardados() {
    FILE *f;

    f = fopen("produtos.txt", "w");
    for (int i = 0; i < totprodutos; i++) {
        fprintf(f, "%d;%s;%.2f\n",
            cardapio[i].codigo,
            cardapio[i].nome,
            cardapio[i].preco);
    }
    fclose(f);

    f = fopen("clientes.txt", "w");
    for (int i = 0; i < totclientes; i++) {
        fprintf(f, "%d;%s\n",
            listadeclientes[i].codigo,
            listadeclientes[i].nome);
    }
    fclose(f);

    f = fopen("pedidos.txt", "w");
    for (int i = 0; i < totpedidos; i++) {
        fprintf(f, "%d;%d;%d\n",
            comandadepedidos[i].codCliente,
            comandadepedidos[i].codProduto,
            comandadepedidos[i].quantidade);
    }
    fclose(f);
}

void carregardados() {
    FILE *f;

    f = fopen("produtos.txt", "r");
    if (f != NULL) {
        while (fscanf(f, "%d;%49[^;];%f\n",
                      &cardapio[totprodutos].codigo,
                      cardapio[totprodutos].nome,
                      &cardapio[totprodutos].preco) != EOF) {
            totprodutos++;
        }
        fclose(f);
    }

    f = fopen("clientes.txt", "r");
    if (f != NULL) {
        while (fscanf(f, "%d;%99[^\n]\n",
                      &listadeclientes[totclientes].codigo,
                      listadeclientes[totclientes].nome) != EOF) {
            totclientes++;
        }
        fclose(f);
    }

    f = fopen("pedidos.txt", "r");
    if (f != NULL) {
        while (fscanf(f, "%d;%d;%d\n",
                      &comandadepedidos[totpedidos].codCliente,
                      &comandadepedidos[totpedidos].codProduto,
                      &comandadepedidos[totpedidos].quantidade) != EOF) {
            totpedidos++;
        }
        fclose(f);
    }
}

void cadastrocliente() {
	 
	 if(totclientes >= 100) {
	 	printf("\nErro: Máximo de cliente atingido!");
	 	return;
	 }
	 
	printf("\n=== Cadastro de novo cliente! ===\n");
	 
	printf("\nDigite o nome do cliente: ");
	scanf(" %[^\n]", listadeclientes[totclientes].nome);
	
	printf("\nDigite o código do cliente: ");
	scanf("%d", &listadeclientes[totclientes].codigo);
	
	printf("\nCliente '%s' cadastrado com sucesso!", listadeclientes[totclientes].nome);
	printf("\n========================================");
	
	totclientes++;
}

void listarcliente() {
	
	if(totclientes == 0){
		printf("\nErro: Nenhum cliente cadastrado ainda!");
		return;
	}
	
	printf("\n===== Clientes =====");
	
	for(int i = 0; i < totclientes; i++) {
		printf("\nNome: %s | Código: %d", 
		listadeclientes[i].nome, 
		listadeclientes[i].codigo);
	}
	printf("========================");
}

void cadastroproduto() {
	
	if (totprodutos >= 100) {
		printf("Erro: Máximo de produtos cadastrados!");
		return;
	}
	
	printf("\n=== Cadastro de novo produto ===\n");
	printf("\nDigite o código do produto: ");
	scanf("%d", &cardapio[totprodutos].codigo);
	
	getchar();
	
	printf("\nDigite o nome do produto: ");
	scanf(" %[^\n]", cardapio[totprodutos].nome);
	
	printf("\nDigite o preço do produto: ");
	scanf("%f", &cardapio[totprodutos].preco);

	printf("\nProduto '%s' cadastrado com sucesso!\n", cardapio[totprodutos].nome);

	totprodutos++;
}

void listarproduto(){
	
	if (totprodutos == 0) {
		printf("Erro: Nenhum produto cadastrado ainda!");
		return;
	}
	
	printf("\n==== Produtos (%d cadastrados) ====", totprodutos);
	
	for(int i = 0; i < totprodutos; i++){
		printf("\n Nome: %s | Código: %d | Preço: R$%.2f",
		 cardapio[i].nome, 
		 cardapio[i].codigo,
		 cardapio[i].preco);
	}
	printf("======================================");
}

void listarpedido() {
	
	if(totpedidos == 0){
		printf("\nErro: Nenhum pedido feito até o momento!");
		return;
	}
	
	printf("\n==== Pedidos Realizados ====\n");
	
	for(int i = 0; i < totpedidos; i++){
		printf("\nCódigo do cliente: %d", comandadepedidos[i].codCliente);
		printf("\nCódigo do produto: %d", comandadepedidos[i].codProduto);
		printf("\nQuantidade do produto: %d", comandadepedidos[i].quantidade);
	}
	printf("\n================================");
}

void realizarpedido(){
	int codProduto, codCliente, quantidade;
	
	printf("\n=== Realizar Novo Pedido! ===\n");
	
	printf("\nDigite o código do cliente: ");
	scanf("%d", &codCliente);
	
	printf("\nDigite o código do produto: ");
	scanf("%d", &codProduto);
	
	printf("\nDigite a quantidade do pedido: ");
	scanf("%d", &quantidade);
	
	if (quantidade <= 0) {
		printf("\nErro: A quantidade deve ser maior do que zero!");
		return;
	}
	
	int cliente = 0;
	
	for(int i = 0; i < totclientes;i++) {
		if(listadeclientes[i].codigo == codCliente) {
			cliente = 1;
			break;
		}
	}
	
	if (cliente == 0) {
		printf("Erro: Cliente com código '%d' não existe!", codCliente);
		return;
	}
	
	int produto = 0;
	
	for(int i = 0; i < totprodutos; i++) {
		if(cardapio[i].codigo == codProduto){
			produto = 1;
			break;
		}
	}
	
	if (produto == 0) {
		printf("\nErro: Produto código '%d' não existe!", codProduto);
		return;
	}

	if(totpedidos < 100) {
		comandadepedidos[totpedidos].codCliente = codCliente;
		comandadepedidos[totpedidos].codProduto = codProduto;
		comandadepedidos[totpedidos].quantidade = quantidade;
		totpedidos++;
		printf("\nPedido registrado!\n");
	}else{
		printf("\nErro: Quantidade de pedidos máximos atingidos!\n");
	}	
}

int main() {
	setlocale(LC_ALL, "");
	
	carregardados();
	
	int opcao;
	
	do{
		printf("\n===== MENU =====\n");
		printf("1. Cadastrar produto\n");
		printf("2. Cadastrar cliente\n");
		printf("3. Realizar Pedido\n");
		printf("4. Listar Produtos\n");
		printf("5. Listar Clientes\n");
		printf("6. Listar Pedidos\n");
		printf("0. Sair do programa\n");
		printf("=====================");
		printf("\nEscolha uma opção: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				cadastroproduto();
				salvardados();
				break;
			case 2:
				cadastrocliente();
				salvardados();
				break;
			case 3:
				realizarpedido();
				salvardados();
				break;
			case 4:
				listarproduto();
				break;
			case 5:
				listarcliente();
				break;
			case 6:
				listarpedido();
				break;
			case 0:
				printf("Encerrando programa!");
				break;
			default: 
				printf("Erro: Opção inválida!");
				break;
		}
	} while (opcao != 0);
	
	return 0;
}
