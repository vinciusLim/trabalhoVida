#include <stdio.h>
#include <string.h>

struct st_DadosCliente
{
	char nome[100];
	char sobrenome[100];
	int idade;
	int telefone;
	int cpf;
	int id;
}

cliente[10];

struct st_DadosMedicamentos
{
	char nome[100];
	float precoCompra;
	float precoVenda;
	int peso;
	int quantidade;
	char tarja[10];
	int id_medicamento;
	int estoque;
}

medicamento[10];

struct st_DadosColaborador
{
	char nome[100];
	char sobrenome[100];
	int idade;
	int id_colaborador;
}

colaborador[10];

int main()
{
	int operacao, operacao_cliente, cont = 0, id = 0, numero_id, colaborador_id;
	int id_med = 0, cont_med = 0, operacao_medicamentos;
	int operacao_colaborador, cont_col = 0, id_col = 0;
	int operacao_venda, quantidadeCompra, numero_id2, quant_venda;
	float valor_compra = 0, total_compra = 0, valor_venda = 0, total_venda = 0;
	char vazia[10] = { "0" };

	do {
		printf("\n\nDigitar operacao a ser seguida: \n1 - Atendimento ao cliente: \n2 - Cadastro de Medicamentos: \n3 - Cadastro de Colaborador: \n4 - Compra/Venda: \n0 - Fechar programa: \n");
		scanf("%d", &operacao);

		switch (operacao)
		{
			case 1:
				printf("\nDigitar operacao do cliente: \n1 - Cadastro:  \n2 - Consulta: \n3 - Alteracao: \n4 - Exclusão: \n0 - Sair da opcao cliente: \n");
				scanf("%d", &operacao_cliente);
				switch (operacao_cliente)
				{
					case 1:

						printf("Digitar nome: ");
						scanf("%s", cliente[cont].nome);

						printf("Digitar sobrenome: ");
						scanf("%s", cliente[cont].sobrenome);

						printf("Digitar idade: ");
						scanf("%d", &cliente[cont].idade);

						printf("Digitar telefone: ");
						scanf("%d", &cliente[cont].telefone);

						printf("Digitar cpf: ");
						scanf("%d", &cliente[cont].cpf);

						id++;

						cliente[cont].id = id;

						cont++;
						break;

					case 2:
						for (int i = 0; i < cont; i++)
						{
							printf("\n\nCliente %d\nNome: %s\nSobrenome: %s\nIdade: %d\nTelefone: %d\nCPF: %d\nID: %d", (i + 1), cliente[i].nome, cliente[i].sobrenome, cliente[i].idade, cliente[i].telefone, cliente[i].cpf, cliente[i].id);
						}

						printf("\n");
						break;

					case 3:

						printf("Qual o numero do ID sera alterado:");
						scanf("%d", &numero_id);

						printf("Digitar nome: ");
						scanf("%s", cliente[numero_id - 1].nome);

						printf("Digitar sobrenome: ");
						scanf("%s", cliente[numero_id - 1].sobrenome);

						printf("Digitar idade: ");
						scanf("%d", &cliente[numero_id - 1].idade);

						printf("Digitar telefone: ");
						scanf("%d", &cliente[numero_id - 1].telefone);

						printf("Digitar cpf: ");
						scanf("%d", &cliente[numero_id - 1].cpf);
						break;

					case 4:

						printf("Qual o numero do ID sera excluido:");
						scanf("%d", &numero_id);

						strcpy(cliente[numero_id - 1].nome, vazia);
						strcpy(cliente[numero_id - 1].sobrenome, vazia);
						cliente[numero_id - 1].idade = 0;
						cliente[numero_id - 1].telefone = 0;
						cliente[numero_id - 1].cpf = 0;

						printf("Exclusão feita\n\n");

						break;

					default:
						printf("\nOperacao não escolhida");
						break;
				}

				break;
			case 2:
				printf("\nDigitar operacao do medicamento: \n1 - Cadastro: \n2 - Consulta: \n3 - Alteracao: \n4 - Exclusão: \n0 - Sair da opção medicamento: \n");
				scanf("%d", &operacao_medicamentos);
				switch (operacao_medicamentos)
				{
					case 1:
						printf("Digitar nome: ");
						scanf("%s", medicamento[cont_med].nome);

						printf("Digitar preço compra: ");
						scanf("%f", &medicamento[cont_med].precoCompra);

						printf("Digitar preço venda: ");
						scanf("%f", &medicamento[cont_med].precoVenda);

						printf("Digitar peso: ");
						scanf("%d", &medicamento[cont_med].peso);

						printf("Digitar quantidade: ");
						scanf("%d", &medicamento[cont_med].quantidade);

						printf("Digitar tarja: ");
						scanf("%s", medicamento[cont_med].tarja);

						id_med++;

						medicamento[cont_med].id_medicamento = id_med;

						cont_med++;
						break;

					case 2:
						for (int i = 0; i < cont_med; i++)
						{
							printf("\n\nMedicamento %d\nNome: %s\nPreço de compra: %.2f\nPreço de venda: %.2f\npeso: %dmg\nQuantidade: %d und por caixa\nTarja: %s\nID: %d", (i + 1), medicamento[i].nome, medicamento[i].precoCompra, medicamento[i].precoVenda, medicamento[i].peso, medicamento[i].quantidade, medicamento[i].tarja, medicamento[i].id_medicamento);
						}

						printf("\n");
						break;

					case 3:

						printf("Qual o numero do ID sera alterado:");
						scanf("%d", &numero_id);

						printf("Digitar nome: ");
						scanf("%s", medicamento[numero_id - 1].nome);

						printf("Digitar Preco compra: ");
						scanf("%f", &medicamento[numero_id - 1].precoCompra);

						printf("Digitar Preco venda: ");
						scanf("%f", &medicamento[numero_id - 1].precoVenda);

						printf("Digitar peso: ");
						scanf("%d", &medicamento[numero_id - 1].peso);

						printf("Digitar quantidade: ");
						scanf("%d", &medicamento[numero_id - 1].quantidade);

						printf("Digitar tarja: ");
						scanf("%s", medicamento[numero_id - 1].tarja);
						break;

					case 4:

						printf("Qual o numero do ID sera excluido:");
						scanf("%d", &numero_id);

						strcpy(medicamento[numero_id - 1].nome, vazia);
						medicamento[numero_id - 1].precoCompra = 0;
						medicamento[numero_id - 1].precoVenda = 0;
						medicamento[numero_id - 1].peso = 0;
						medicamento[numero_id - 1].quantidade = 0;
						strcpy(medicamento[numero_id - 1].tarja, vazia);

						printf("Exclusão feita");

						break;

					default:
						printf("\nOperacao não escolhida\n");
						break;
				}

				break;

			case 3:

				printf("\nDigitar operacao do Colaborador: \n1 - Cadastro: \n2 - Consulta: \n3 - Alteracao: \n4 - Exclusão: \n0 - Sair da opção cliente: \n");

				scanf("%d", &operacao_colaborador);
				switch (operacao_colaborador)
				{
					case 1:

						printf("Digitar nome: ");
						scanf("%s", colaborador[cont_col].nome);

						printf("Digitar sobrenome: ");
						scanf("%s", colaborador[cont_col].sobrenome);

						printf("Digitar idade: ");
						scanf("%d", &colaborador[cont_col].idade);

						id_col++;

						colaborador[cont_col].id_colaborador = id_col;

						cont_col++;
						break;

					case 2:

						for (int i = 0; i < cont_col; i++)
						{
							printf("\n\nColaborador %d\nNome: %s\nSobrenome: %s\nIdade: %d\nID: %d\n", (i + 1), colaborador[i].nome, colaborador[i].sobrenome, colaborador[i].idade, colaborador[i].id_colaborador);
						}

						printf("\n");
						break;

					case 3:

						printf("Qual o numero do ID sera alterado:");
						scanf("%d", &numero_id);

						printf("Digitar nome: ");
						scanf("%s", colaborador[numero_id - 1].nome);

						printf("Digitar sobrenome: ");
						scanf("%s", colaborador[numero_id - 1].sobrenome);

						printf("Digitar idade: ");
						scanf("%d", &colaborador[numero_id - 1].idade);

						break;

					case 4:

						printf("Qual o numero do ID sera excluido:");
						scanf("%d", &numero_id);

						strcpy(colaborador[numero_id - 1].nome, vazia);
						strcpy(colaborador[numero_id - 1].sobrenome, vazia);
						colaborador[numero_id - 1].idade = 0;

						printf("\n\nExclusão feita\n\n");

						break;

					default:
						printf("\n\nOperacao não escolhida\n\n");
						break;
				}

				break;

			case 4:

				printf("\nDigitar operação de compra ou venda: \n1 - Compra de medicamento: \n2 - Conferir estoque: \n3 - Venda do Medicamento: \n4 - Relatorio financeiro: \n0 - Sair da opção de Venda/Compra: \n");

				scanf("%d", &operacao_venda);
				switch (operacao_venda)
				{
					case 1:

						printf("Escolher numero do ID do medicamento: ");
						scanf("%d", &numero_id);

						printf("Escolher quantidade do medicamento: ");
						scanf("%d", &quantidadeCompra);

						valor_compra = medicamento[numero_id - 1].precoCompra * quantidadeCompra;

						printf("O valor da compra foi: R$ %.2f", valor_compra);

						medicamento[numero_id].estoque = medicamento[numero_id].estoque + quantidadeCompra;

						printf("\nO estoque desse remédio é de %d unidades\n", medicamento[numero_id].estoque);

						total_compra = total_compra + valor_compra;

						break;

					case 2:

						for (int i = 0; i < cont_med; i++)
						{
							printf("\nEstoque do medicamento %d é: %d ", (i + 1), medicamento[i + 1].estoque);
						};

						break;

					case 3:

						printf("Digitar ID do colaborador: ");
						scanf("%d", &colaborador_id);

						printf("Digitar ID do cliente: ");
						scanf("%d", &numero_id);

						printf("Digitar o ID do medicamento: ");
						scanf("%d", &numero_id2);

						printf("Digitar quantidade do medicamento: ");
						scanf("%d", &quant_venda);

						valor_venda = medicamento[numero_id2].precoVenda * quant_venda;

						total_venda = total_venda + valor_venda;

						printf("A venda do colaborador: %s %s para o cliente: %s %s foi de R$ %.2f.", colaborador[colaborador_id].nome, colaborador[colaborador_id].sobrenome, cliente[numero_id].nome, cliente[numero_id].sobrenome, valor_venda);
						break;

					case 4:

						printf("O total gasto na compra de medicamentos é: %.2f", total_compra);
						printf("\nO total arrecadado com a venda de medicamentos é: %.2f", total_venda);
						printf("\nO lucro com a venda de medicamentos é: %.2f", total_venda - total_compra);
						break;

					default:

						printf("\nOperacao não escolhida");
						break;
				}

				break;
		}
	} while (operacao != 0);
	printf("\nO programa foi encerrado");

	return 0;
}
