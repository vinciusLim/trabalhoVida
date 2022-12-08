#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

struct st_DadosCliente
{
	char nome[100];
	char sobrenome[100];
	int idade;
	char telefone[100];
	char cpf[100];
	int id;
}

cliente[10];

struct st_DadosMedicamentos
{
	char nome[100];
	float precoCompra;
	float precoVenda;
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

float lucro(float faturamento, float despesa)
{
	return faturamento - despesa;
}

FILE *arquivo1, *arquivo2, *arquivo3, *arquivo4;

int main()
{
	int operacao, operacao_cliente, cont = 0, id = 0, numero_id, colaborador_id;
	int id_med = 0, cont_med = 0, operacao_medicamentos;
	int operacao_colaborador, cont_col = 0, id_col = 0;
	int operacao_venda, quantidadeCompra, numero_id2, quant_venda, numero_venda = 0;
	float valor_compra = 0, total_compra = 0, valor_venda = 0, total_venda = 0, historico_venda[10][5];
	char vazia[10] = { "0" };

	// Define o valor das páginas de código UTF8 e default do Windows
	UINT CPAGE_UTF8 = 65001;
	UINT CPAGE_DEFAULT = GetConsoleOutputCP();

	// Define codificação como sendo UTF-8
	SetConsoleOutputCP(CPAGE_UTF8);

	do {
		refaz_1: printf("\n\nDigitar operacao a ser seguida: \n1 - Atendimento ao cliente: \n2 - Cadastro de Medicamentos: \n3 - Cadastro de Colaborador: \n4 - Compra/Venda: \n0 - Fechar programa: \n");
		scanf("%d", &operacao);
		if (operacao > 4 || operacao < 0)
		{
			printf("\nOperação inválida, digite novamente\n");
			goto refaz_1;
		}

		switch (operacao)
		{
			case 1:
				refaz_2: printf("\nDigitar operação do cliente: \n1 - Cadastro:  \n2 - Consulta: \n3 - Alteracao: \n4 - Exclusão: \n0 - Sair da opcao cliente: \n");
				scanf("%d", &operacao_cliente);
				if (operacao_cliente > 4 || operacao_cliente < 0)
				{
					printf("\nOperação inválida, digite novamente\n");
					goto refaz_2;
				}

				switch (operacao_cliente)
				{
					case 1:

						printf("\n");
						fflush(stdin);

						printf("Digitar nome: ");
						scanf("%[^\n]s", cliente[cont].nome);
						fflush(stdin);

						printf("Digitar sobrenome: ");
						scanf("%[^\n]s", cliente[cont].sobrenome);
						fflush(stdin);

						printf("Digitar idade: ");
						scanf("%d", &cliente[cont].idade);
						fflush(stdin);

						printf("Digitar telefone: ");
						scanf("%[^\n]s", cliente[cont].telefone);
						fflush(stdin);

						printf("Digitar cpf: ");
						scanf("%[^\n]s", cliente[cont].cpf);
						fflush(stdin);

						id++;

						cliente[cont].id = id;

						cont++;
						break;

					case 2:

						arquivo1 = fopen("clientes.txt", "w+t");
						if (arquivo1 != NULL)
						{
							printf("\nArquivo criado com sucesso\n");
							for (int i = 0; i < cont; i++)
							{
								printf("\n\nCliente %d\nNome: %s\nSobrenome: %s\nIdade: %d\nTelefone: %s\nCPF: %s\nID: %d", (i + 1), cliente[i].nome, cliente[i].sobrenome, cliente[i].idade, cliente[i].telefone, cliente[i].cpf, cliente[i].id);
								fprintf(arquivo1, "\n\nCliente %d\nNome: %s\nSobrenome: %s\nIdade: %d\nTelefone: %s\nCPF: %s\nID: %d", (i + 1), cliente[i].nome, cliente[i].sobrenome, cliente[i].idade, cliente[i].telefone, cliente[i].cpf, cliente[i].id);
							}

							printf("\n");
						}
						else
						{
							printf("\nErro na criação do arquivo\n");
						}

						fclose(arquivo1);

						break;

					case 3:

						printf("Qual o numero do ID sera alterado:");
						scanf("%d", &numero_id);

						fflush(stdin);
						printf("Digitar nome: ");
						scanf("%[^\n]s", cliente[numero_id - 1].nome);

						fflush(stdin);
						printf("Digitar sobrenome: ");
						scanf("%[^\n]s", cliente[numero_id - 1].sobrenome);

						fflush(stdin);
						printf("Digitar idade: ");
						scanf("%d", &cliente[numero_id - 1].idade);

						fflush(stdin);
						printf("Digitar telefone: ");
						scanf("%[^\n]s", cliente[numero_id - 1].telefone);

						fflush(stdin);
						printf("Digitar cpf: ");
						scanf("%[^\n]s", cliente[numero_id - 1].cpf);
						break;

					case 4:

						printf("Qual o numero do ID sera excluido:");
						scanf("%d", &numero_id);

						strcpy(cliente[numero_id - 1].nome, vazia);
						strcpy(cliente[numero_id - 1].sobrenome, vazia);
						cliente[numero_id - 1].idade = 0;
						strcpy(cliente[numero_id - 1].telefone, vazia);
						strcpy(cliente[numero_id - 1].cpf, vazia);

						printf("Exclusão feita\n\n");
						break;

					case 0:

						printf("Você sai da opção de cliente");

						break;

					default:
						printf("\n");
						break;
				}

				break;
			case 2:
				refaz_3: printf("\nDigitar operacao do medicamento: \n1 - Cadastro: \n2 - Consulta: \n3 - Alteracao: \n4 - Exclusão: \n0 - Sair da opção medicamento: \n");
				scanf("%d", &operacao_medicamentos);
				if (operacao_medicamentos > 4 || operacao_medicamentos < 0)
				{
					printf("\nOperação inválida, digite novamente\n");

					goto refaz_3;
				}

				switch (operacao_medicamentos)
				{
					case 1:

						fflush(stdin);
						printf("Digitar nome: ");
						scanf("%[^\n]s", medicamento[cont_med].nome);

						fflush(stdin);
						printf("Digitar preço compra: ");
						scanf("%f", &medicamento[cont_med].precoCompra);

						fflush(stdin);
						printf("Digitar preço venda: ");
						scanf("%f", &medicamento[cont_med].precoVenda);

						fflush(stdin);
						printf("Digitar tarja: ");
						scanf("%[^\n]s", medicamento[cont_med].tarja);

						id_med++;

						medicamento[cont_med].id_medicamento = id_med;

						cont_med++;
						break;

					case 2:

						arquivo2 = fopen("medicamentos.txt", "w+t");
						if (arquivo2 != NULL)
						{
							printf("\nArquivo criado com sucesso\n");
							for (int i = 0; i < cont_med; i++)
							{
								printf("\n\nMedicamento %d\nNome: %s\nPreço de compra: %.2f\nPreço de venda: %.2f\nTarja: %s\nID: %d", (i + 1), medicamento[i].nome, medicamento[i].precoCompra, medicamento[i].precoVenda, medicamento[i].tarja, medicamento[i].id_medicamento);
								fprintf(arquivo2, "\n\nMedicamento %d\nNome: %s\nPreço de compra: %.2f\nPreço de venda: %.2f\nTarja: %s\nID: %d", (i + 1), medicamento[i].nome, medicamento[i].precoCompra, medicamento[i].precoVenda, medicamento[i].tarja, medicamento[i].id_medicamento);
							}

							printf("\n");
						}
						else
						{ 				("\nErro na criação do arquivo\n");
						}

						fclose(arquivo2);

						break;

					case 3:

						printf("Qual o numero do ID sera alterado: ");
						scanf("%d", &numero_id);

						fflush(stdin);
						printf("Digitar nome: ");
						scanf("%[^\n]s", medicamento[numero_id - 1].nome);

						fflush(stdin);
						printf("Digitar Preco compra: ");
						scanf("%f", &medicamento[numero_id - 1].precoCompra);

						fflush(stdin);
						printf("Digitar Preco venda: ");
						scanf("%f", &medicamento[numero_id - 1].precoVenda);

						fflush(stdin);
						printf("Digitar tarja: ");
						scanf("%[^\n]s", medicamento[numero_id - 1].tarja);
						break;

					case 4:

						printf("Qual o numero do ID sera excluido:");
						scanf("%d", &numero_id);

						strcpy(medicamento[numero_id - 1].nome, vazia);
						medicamento[numero_id - 1].precoCompra = 0;
						medicamento[numero_id - 1].precoVenda = 0;
						strcpy(medicamento[numero_id - 1].tarja, vazia);

						printf("Exclusão feita");

						break;

					case 0:

						printf("Você saiu da opção de medicamento");

						break;

					default:
						printf("\nOperacao não escolhida\n");
						break;
				}

				break;

			case 3:

				refaz_4: printf("\nDigitar operacao do Colaborador: \n1 - Cadastro: \n2 - Consulta: \n3 - Alteracao: \n4 - Exclusão: \n0 - Sair da opção cliente: \n");
				scanf("%d", &operacao_colaborador);
				if (operacao_colaborador > 4 || operacao_colaborador < 0)
				{
					printf("\nOperação inválida, digite novamente\n");
					goto refaz_4;
				}

				switch (operacao_colaborador)
				{
					case 1:

						fflush(stdin);
						printf("Digitar nome: ");
						scanf("%[^\n]s", colaborador[cont_col].nome);

						fflush(stdin);
						printf("Digitar sobrenome: ");
						scanf("%[^\n]s", colaborador[cont_col].sobrenome);

						fflush(stdin);
						printf("Digitar idade: ");
						scanf("%d", &colaborador[cont_col].idade);

						id_col++;

						colaborador[cont_col].id_colaborador = id_col;

						cont_col++;
						break;

					case 2:

						arquivo3 = fopen("colaboradores.txt", "w+t");
						if (arquivo3 != NULL)
						{
							printf("\nArquivo criado com sucesso\n");
							for (int i = 0; i < cont_col; i++)
							{
								printf("\n\nColaborador %d\nNome: %s\nSobrenome: %s\nIdade: %d\nID: %d\n", (i + 1), colaborador[i].nome, colaborador[i].sobrenome, colaborador[i].idade, colaborador[i].id_colaborador);
								fprintf(arquivo3, "\n\nColaborador %d\nNome: %s\nSobrenome: %s\nIdade: %d\nID: %d\n", (i + 1), colaborador[i].nome, colaborador[i].sobrenome, colaborador[i].idade, colaborador[i].id_colaborador);
							}

							printf("\n");
						}
						else
						{
							printf("\nErro na criação do arquivo\n");
						}

						fclose(arquivo3);

						break;

					case 3:

						printf("Qual o numero do ID sera alterado:");
						scanf("%d", &numero_id);

						fflush(stdin);
						printf("Digitar nome: ");
						scanf("%[^\n]s", colaborador[numero_id - 1].nome);

						fflush(stdin);
						printf("Digitar sobrenome: ");
						scanf("%[^\n]s", colaborador[numero_id - 1].sobrenome);

						fflush(stdin);
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

					case 0:

						printf("Você saiu da opção de colaborador");

						break;

					default:
						printf("\n\nOperacao não escolhida\n\n");
						break;
				}

				break;

			case 4:

				refaz_5: printf("\nDigitar operação de compra ou venda: \n1 - Compra de medicamento: \n2 - Conferir estoque: \n3 - Venda do Medicamento: \n4 - Relatorio financeiro: \n5 - Histórico de venda: \n0 - Sair da opção de Venda/Compra: \n");
				scanf("%d", &operacao_venda);
				if (operacao_venda > 5 || operacao_venda < 0)
				{
					printf("\nOperação inválida, digite novamente\n");
					goto refaz_5;
				}

				switch (operacao_venda)
				{
					case 1:

						printf("Escolher numero do ID do medicamento: ");
						scanf("%d", &numero_id);

						printf("Escolher quantidade do medicamento: ");
						scanf("%d", &quantidadeCompra);

						valor_compra = medicamento[numero_id - 1].precoCompra * quantidadeCompra;

						printf("\n\nO valor da compra foi: R$ %.2f", valor_compra);

						medicamento[numero_id].estoque = medicamento[numero_id].estoque + quantidadeCompra;

						printf("\nO estoque desse remédio é de %d unidades\n", medicamento[numero_id].estoque);

						total_compra = total_compra + valor_compra;

						break;

					case 2:

						for (int i = 0; i < cont_med; i++)
						{
							printf("\nEstoque do medicamento %d é: %d unidades", (i + 1), medicamento[i + 1].estoque);
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

						if (medicamento[numero_id2].estoque >= quant_venda)
						{
							medicamento[numero_id2].estoque = medicamento[numero_id2].estoque - quant_venda;

							valor_venda = medicamento[numero_id2 - 1].precoVenda * quant_venda;

							total_venda = total_venda + valor_venda;

							printf("A venda do colaborador: %s %s para o cliente: %s %s foi de R$ %.2f.", colaborador[colaborador_id - 1].nome, colaborador[colaborador_id - 1].sobrenome, cliente[numero_id - 1].nome, cliente[numero_id - 1].sobrenome, valor_venda);

							//id do vendedor
							historico_venda[numero_venda][0] = colaborador_id;
							//id do cliente
							historico_venda[numero_venda][1] = numero_id;
							//id do medicamento
							historico_venda[numero_venda][2] = numero_id2;
							//Quantidade comprada
							historico_venda[numero_venda][3] = quant_venda;
							//Valor da venda
							historico_venda[numero_venda][4] = valor_venda;

							numero_venda++;
						}
						else
						{
							printf("\nEstoque insuficiente para a quantidade exigida\n");
						}

						break;

					case 4:

						printf("\nO total gasto na compra de medicamentos é: R$ %.2f", total_compra);
						printf("\nO total arrecadado com a venda de medicamentos é: R$ %.2f\n", total_venda);

						printf("O lucro foi: R$ %.2f", lucro(total_venda, total_compra));

						break;

					case 5:

						arquivo4 = fopen("historico_de_venda.txt", "w+t");
						if (arquivo4 != NULL)
						{
							printf("\nArquivo criado com sucesso\n");
							for (int i = 0; i < numero_venda; i++)
							{
								printf("\n\nCompra: %d\ncolaborador: %.0f\ncliente: %.0f\nmedicamento: %.0f\nQuantidade: %.0f\nValor: %.2f\n", (i + 1), historico_venda[i][0], historico_venda[i][1], historico_venda[i][2], historico_venda[i][3], historico_venda[i][4]);
								fprintf(arquivo4, "\n\nCompra: %d\ncolaborador: %.0f\ncliente: %.0f\nmedicamento: %.0f\nQuantidade: %.0f\nValor: %.2f\n", (i + 1), historico_venda[i][0], historico_venda[i][1], historico_venda[i][2], historico_venda[i][3], historico_venda[i][4]);
							}

							printf("\n");
						}
						else
						{
							printf("\nErro na criação do arquivo\n");
						}

						fclose(arquivo4);

						break;

					case 0:

						printf("Você saiu da opção de Compra/Venda");

						break;

					default:

						printf("\nOperacao não escolhida");
						break;
				}

				break;

			case 0:

				printf("\nO programa foi encerrado");
				break;

			default:
				printf("\nOperação inválida");
				break;
		}
	} while (operacao != 0);

	return 0;
}
