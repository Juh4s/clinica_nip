#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include "agendamentos.h"
#include "cadastros.h"
#include "avaliacoes.h"
#include "relatorios.h"
#include "bancoDeDados.h"
#include "prontuarios.h"

char senhaAdmin1[20], senhaAdmin2[20]="t4EbN7hnUVL0XHb";
int verificacaoValidez2, verificacaoLogin, verificacaoSenha;

int main(){

	FILE *contas; //ponteiro do arquivo onde as contas estão salvas
	system("color F0"); //altera a cor da fonte e do background
	setlocale(LC_ALL, "portuguese"); //define a língua utilizada pelo programa

	do{
		system("cls"); //limpa a tela
		printf("\t _________   __          __   ___    __   __   _________   _________ 	   ___    __   __   _________ ");
		printf("\n\t|   ______| |  |        |  | |   \\  |  | |  | |   ______| |   ___   |     |   \\  |  | |  | |   ___   |");
		printf("\n\t|  |        |  |        |  | |    \\ |  | |  | |  |        |  |   |  |     |    \\ |  | |  | |  |   |  |");
		printf("\n\t|  |        |  |        |  | |  |  \\|  | |  | |  |        |  |___|  |     |  |  \\|  | |  | |  |___|  |");
		printf("\n\t|  |        |  |        |  | |  |\\     | |  | |  |        |   ___   |     |  |\\     | |  | |   ______|");
		printf("\n\t|  |______  |  |______  |  | |  | \\    | |  | |  |______  |  |	 |  |     |  | \\    | |  | |  |");
		printf("\n\t|_________| |_________| |__| |__|  \\___| |__| |_________| |__|	 |__|     |__|  \\___| |__| |__|");
		//printa o banner da clínica

		printf("\n\n\tBem-vindo! Por favor, insira o seu login e a sua senha.");
		printf("\n\tLogin: ");
		scanf("%s", login); //recebe o login inserido pelo usuario
		printf("\tSenha: ");
		scanf("%s", senha); //recebe a senha inserida pelo usuario
	
		contas = fopen("Contas.txt","r");
		do{
			int t = fscanf(contas," %[^\n] %[^\n]",loginSalvo,senhaSalva);
			if(t == EOF){
				verificacaoValidez = 1;
				break;
			}
			if(strcmp(login,loginSalvo) == 0 && strcmp(senha,senhaSalva) == 0){
				verificacaoLogin = 1;
				verificacaoSenha = 1;
				verificacaoValidez = 1;
				break;
			}else if(strcmp(login,loginSalvo) == 0 && strcmp(senha,senhaSalva) != 0){
				verificacaoLogin = 1;
				verificacaoSenha = 2;
				verificacaoValidez = 1;
				break;
			}else if(strcmp(login,loginSalvo) != 0 && strcmp(senha,senhaSalva) == 0){
				verificacaoLogin = 2;
				verificacaoSenha = 1;
				verificacaoValidez = 1;
				break;
			}else if(strcmp(login,loginSalvo) != 0 && strcmp(senha,senhaSalva) != 0){
				verificacaoLogin = 2;
				verificacaoSenha = 2;
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);	
		fclose(contas);
				
		if(verificacaoLogin == 1 && verificacaoSenha == 1){
			printf("\n\tLogin efetuado com sucesso!\n\t");
			system("pause");
			verificacaoValidez = 1;
		}else if(verificacaoLogin == 2 && verificacaoSenha == 1){
			printf("\n\tLogin incorreto, tente novamente\n\t");
			system("pause");
			verificacaoValidez = 2;
		}else if(verificacaoLogin == 1 && verificacaoSenha == 2){
			printf("\n\tSenha incorreta, tente novamente\n\t");
			system("pause");
			verificacaoValidez = 2;
		}else if(verificacaoLogin == 2 && verificacaoSenha == 2){
			printf("\n\tLogin e senha incorretos, tente novamente\n\t");
			system("pause");
			verificacaoValidez = 2;
		}
		
	}while(verificacaoValidez != 1);

	do{
		system("cls");
		printf("\t _________   __          __   ___    __   __   _________   _________ 	   ___    __   __   _________ ");
		printf("\n\t|   ______| |  |        |  | |   \\  |  | |  | |   ______| |   ___   |     |   \\  |  | |  | |   ___   |");
		printf("\n\t|  |        |  |        |  | |    \\ |  | |  | |  |        |  |   |  |     |    \\ |  | |  | |  |   |  |");
		printf("\n\t|  |        |  |        |  | |  |  \\|  | |  | |  |        |  |___|  |     |  |  \\|  | |  | |  |___|  |");
		printf("\n\t|  |        |  |        |  | |  |\\     | |  | |  |        |   ___   |     |  |\\     | |  | |   ______|");
		printf("\n\t|  |______  |  |______  |  | |  | \\    | |  | |  |______  |  |	 |  |     |  | \\    | |  | |  |");
		printf("\n\t|_________| |_________| |__| |__|  \\___| |__| |_________| |__|	 |__|     |__|  \\___| |__| |__|");

		printf("\n\n\t[1] Agendamentos");
		printf("\n\t[2] Relatórios");
		printf("\n\t[3] Cadastros");
		printf("\n\t[4] Prontuários");
		printf("\n\t[5] Avaliações");
		printf("\n\t[6] Banco de dados");
		printf("\n\t[7] Tema do Programa");
		printf("\n\t[8] Encerrar programa");
		printf("\n\tInsira o número correspondente ao menu que deseja (somente o número): ");
		scanf("%d", &menuEscolha); //recebe escolha do usuário (qual menu abrir)

		switch(menuEscolha){ //menu principal
			case 1: //agendamentos
				do{
					system("cls");
					printf("\n\n\t[1] Consultar agendamentos");
					printf("\n\t[2] Realizar agendamento");
					printf("\n\t[3] Editar agendamento");
					printf("\n\t[4] Cancelar agendamento");
					printf("\n\t[5] Voltar ao menu principal");
					printf("\n\tInsira o número correspondente à opção que deseja (somente o número): ");
					scanf("%d", &menuEscolha);

					switch(menuEscolha){ //submenu de agendamentos
						case 1:
							agendamentoConsultar();
							verificacaoValidez = 1;
							break;
						case 2:
							agendamentoCriar();
							verificacaoValidez = 1;
							break;
						case 3:
							agendamentoEditar();
							verificacaoValidez = 1;
							break;
						case 4:
							agendamentoCancelar();
							verificacaoValidez = 1;
							break;
						case 5:
							verificacaoValidez = 1;
							break;
						default: //opção caso o usuário insira algo inválido
							verificacaoValidez = 2;
							break;
					}
				}while(verificacaoValidez == 2); //fim agendamentos
				break;
			case 2: //relatórios
				do{
					system("cls");
					printf("\n\n\t[1] Relatórios de faturamento");
					printf("\n\t[2] Relatórios de gastos");
					printf("\n\t[3] Relatórios de pacientes");
					printf("\n\t[4] Voltar ao menu principal");
					printf("\n\tInsira o número correspondente ao menu que deseja (somente o número): ");
					scanf("%d", &menuEscolha);

					switch(menuEscolha){ //submenu de relatorios
						case 1: //relatorios de faturamento
							do{
								system("cls");
								printf("\n\n\t[1] Faturamento diário da unidade");
								printf("\n\t[2] Faturamento mensal da unidade");
								printf("\n\t[3] Faturamento diário da rede");
								printf("\n\t[4] Faturamento mensal da rede");
								printf("\n\t[5] Voltar ao menu principal");
								printf("\n\tInsira o número correspondete à opção que deseja (somente o número): ");
								scanf("%d", &menuEscolha);

								switch(menuEscolha){
									case 1:
										relatorioFaturamentoUnidadeDiario();
										verificacaoValidez2 = 1;
										break;
									case 2:
										relatorioFaturamentoUnidadeMensal();
										verificacaoValidez2 = 1;
									break;
									case 3:
										relatorioFaturamentoRedeDiario();
										verificacaoValidez2 = 1;
										break;
									case 4:
										relatorioFaturamentoRedeMensal();
										verificacaoValidez2 = 1;
										break;
									case 5:
										verificacaoValidez2 = 1;
										break;
									default:
										verificacaoValidez2 = 2;
										break;
								}
								verificacaoValidez = 1;
							}while(verificacaoValidez2 == 2);
							break;
						case 2: //relatorios de gastos
							do{
								system("cls");
								printf("\n\n\t[1] Gasto diário da unidade");
								printf("\n\t[2] Gasto mensal da unidade");
								printf("\n\t[3] Gasto diário da rede");
								printf("\n\t[4] Gasto mensal da rede");
								printf("\n\t[5] Voltar ao menu principal");
								printf("\n\tInsira o número correspondete à opção que deseja (somente o número): ");
								scanf("%d", &menuEscolha);

								switch(menuEscolha){
									case 1:
										relatorioGastosUnidadeDiario();
										verificacaoValidez2 = 1;
										break;
									case 2:
										relatorioGastosUnidadeMensal();
										verificacaoValidez2 = 1;
										break;
									case 3:
										relatorioGastosRedeDiario();
										verificacaoValidez2 = 1;
										break;
									case 4:
										relatorioGastosRedeMensal();
										verificacaoValidez2 = 1;
										break;
									case 5:
										verificacaoValidez2 = 1;
										break;
									default:
										verificacaoValidez2 = 2;
										break;
								}
								verificacaoValidez = 1;
							}while(verificacaoValidez2 == 2);
							break;
						case 3: //relatorios de pacientes
							do{
								system("cls");
								printf("\n\n\t[1] Ranking de atendimentos");
								printf("\n\t[2] Média da nota da rede");
								printf("\n\t[3] Média da nota das unidades");
								printf("\n\t[4] Ranking de nota das unidades");
								printf("\n\t[5] Voltar ao menu principal");
								printf("\n\tInsira o número correspondete à opção que deseja (somente o número): ");
								scanf("%d", &menuEscolha);

								switch(menuEscolha){
									case 1:
										relatorioRankingAtendimentos();
										verificacaoValidez2 = 1;
										break;
									case 2:
										relatorioNotaRede();
										verificacaoValidez2 = 1;
										break;
									case 3:
										relatorioNotaUnidade();
										verificacaoValidez2 = 1;
										break;
									case 4:
										relatorioRankingNota();
										verificacaoValidez2 = 1;
										break;
									case 5:
										verificacaoValidez2 = 1;
										break;
									default:
										verificacaoValidez2 = 2;
										break;
								}
								verificacaoValidez = 1;
							}while(verificacaoValidez2 == 2);
							break;
						case 4:
							verificacaoValidez = 1;
							break;
						default:
							verificacaoValidez = 2;
							break;
					}
				}while(verificacaoValidez == 2); //fim relatorios
				break;
			case 3: //cadastros
				do{
					system("cls");
					printf("\n\n\t[1] Pacientes");
					printf("\n\t[2] Funcionários");
					printf("\n\t[3] Gastos");
					printf("\n\t[4] Contas");
					printf("\n\t[5] Voltar ao menu principal");
					printf("\n\tInsira o número correspondete ao menu que deseja (somente o número): ");
					scanf("%d", &menuEscolha);

					switch(menuEscolha){
						case 1:
							do{
								system("cls");
								printf("\n\n\t[1] Consultar paciente");
								printf("\n\t[2] Cadastro de paciente");
								printf("\n\t[3] Edição de cadastro de paciente");
								printf("\n\t[4] Excluir cadastro de paciente");
								printf("\n\t[5] Voltar ao menu principal");
								printf("\n\tInsira o número correspondete à opção que deseja (somente o número): ");
								scanf("%d", &menuEscolha);

								switch(menuEscolha){
									case 1:
										cadastroPacienteConsultar();
										verificacaoValidez2 = 1;
										break;
									case 2:
										cadastroPaciente();
										verificacaoValidez2 = 1;
									break;
									case 3:
										cadastroPacienteEditar();
										verificacaoValidez2 = 1;
										break;
									case 4:
										cadastroPacienteExcluir();
										verificacaoValidez2 = 1;
										break;
									case 5:
										verificacaoValidez2 = 1;
										break;
									default:
										verificacaoValidez2 = 2;
										break;
								}
								verificacaoValidez = 1;
							}while(verificacaoValidez2 == 2);
							break;
						case 2:
							do{
								system("cls");
								printf("\n\n\t[1] Consultar funcionário");
								printf("\n\t[2] Cadastro de funcionário");
								printf("\n\t[3] Edição de cadastro de funcionário");
								printf("\n\t[4] Excluir cadastro de funcionário");
								printf("\n\t[5] Voltar ao menu principal");
								printf("\n\tInsira o número correspondete à opção que deseja (somente o número): ");
								scanf("%d", &menuEscolha);

								switch(menuEscolha){
									case 1:
										cadastroFuncionarioConsultar();
										verificacaoValidez2 = 1;
										break;
									case 2:
										cadastroFuncionario();
										verificacaoValidez2 = 1;
									break;
									case 3:
										cadastroFuncionarioEditar();
										verificacaoValidez2 = 1;
										break;
									case 4:
										cadastroFuncionarioExcluir();
										verificacaoValidez2 = 1;
										break;
									case 5:
										verificacaoValidez2 = 1;
										break;
									default:
										verificacaoValidez2 = 2;
										break;
								}
								verificacaoValidez = 1;
							}while(verificacaoValidez2 == 2);
							break;
						case 3:
							do{
								system("cls");
								printf("\n\n\t[1] Consultar gasto");
								printf("\n\t[2] Cadastro de gasto");
								printf("\n\t[3] Edição de cadastro de gasto");
								printf("\n\t[4] Excluir cadastro de gasto");
								printf("\n\t[5] Voltar ao menu principal");
								printf("\n\tInsira o número correspondete à opção que deseja (somente o número): ");
								scanf("%d", &menuEscolha);

								switch(menuEscolha){
									case 1:
										cadastroGastoConsultar();
										verificacaoValidez2 = 1;
										break;
									case 2:
										cadastroGasto();
										verificacaoValidez2 = 1;
									break;
									case 3:
										cadastroGastoEditar();
										verificacaoValidez2 = 1;
										break;
									case 4:
										cadastroGastoExcluir();
										verificacaoValidez2 = 1;
										break;
									case 5:
										verificacaoValidez2 = 1;
										break;
									default:
										verificacaoValidez2 = 2;
										break;
								}
								verificacaoValidez = 1;
							}while(verificacaoValidez2 == 2);
							break;
						case 4:
							do{
								system("cls");
								printf("\n\n\t[1] Criar conta");
								printf("\n\t[2] Excluir conta");
								printf("\n\t[3] Voltar ao menu principal");
								printf("\n\tInsira o número correspondete à opção que deseja (somente o número): ");
								scanf("%d", &menuEscolha);

								switch(menuEscolha){
									case 1:										
										printf("\n\tInsira a senha de admin: ");
										fflush(stdin);
										fgets(senhaAdmin1, 20, stdin);
										senhaAdmin1[strcspn (senhaAdmin1, "\n\000")] = '\000';
										if(strcmp(senhaAdmin1,senhaAdmin2) == 0){
											contaCriar();
											verificacaoValidez2 = 1;
											break;
										}else{
											printf("\n\tSenha incorreta, tente novamente\n\t");
											verificacaoValidez2 = 2;
											system("pause");
											break;
										}
									case 2:
										printf("\n\tInsira a senha de admin: ");
										fflush(stdin);
										fgets(senhaAdmin1, 20, stdin);
										senhaAdmin1[strcspn (senhaAdmin1, "\n\000")] = '\000';
										if(strcmp(senhaAdmin1,senhaAdmin2) == 0){
											contaExcluir();
											verificacaoValidez = 1;
											break;
										}else{
											printf("\n\tSenha incorreta, tente novamente\n\t");
											verificacaoValidez = 2;
											system("pause");
											break;
										}
									case 3:
										verificacaoValidez2 = 1;
										break;
									default:
										verificacaoValidez2 = 2;
										break;
								}
								verificacaoValidez = 1;
							}while(verificacaoValidez2 == 2);
							break;
						case 5:
							verificacaoValidez = 1;
							break;
						default:
							verificacaoValidez = 2;
							break;
					}
				}while(verificacaoValidez == 2);
				break;
			case 4: //prontuários
				do{
					system("cls");
					printf("\n\n\t[1] Abrir prontuário");
					printf("\n\t[2] Criar prontuário");
					printf("\n\t[3] Editar prontuário");
					printf("\n\t[4] Excluir prontuário");
					printf("\n\t[5] Voltar ao menu principal");
					printf("\n\tInsira o número correspondente à opção que deseja (somente o número): ");
					scanf("%d", &menuEscolha);

					switch(menuEscolha){
						case 1:
							prontuarioAbrir();
							verificacaoValidez = 1;
							break;
						case 2:			
							prontuarioCriar();				
							verificacaoValidez = 1;
							break;
						case 3:
							prontuarioEditar();
							verificacaoValidez = 1;
							break;
						case 4:
							prontuarioExcluir();
							verificacaoValidez = 1;
							break;
						case 5:
							verificacaoValidez = 1;
							break;
						default:
							verificacaoValidez = 2;
							break;
					}
				}while(verificacaoValidez == 2);
				break;
			case 5: //avaliações dos clientes
				do{
					system("cls");
					printf("\n\n\t[1] Consultar avaliação");
					printf("\n\t[2] Registrar avaliação");
					printf("\n\t[3] Excluir avaliação");
					printf("\n\t[4] Voltar ao menu principal");
					printf("\n\tInsira o número correspondente à opção que deseja (somente o número): ");
					scanf("%d", &menuEscolha);

					switch(menuEscolha){
						case 1:
							avaliacaoConsultar();
							verificacaoValidez = 1;
							break;
						case 2:
							avaliacaoCriar();
							verificacaoValidez = 1;
							break;
						case 3:
							avaliacaoExcluir();
							verificacaoValidez = 1;
							break;
						case 4:
							verificacaoValidez = 1;
							break;
						default:
							verificacaoValidez = 2;
							break;
					}
				}while(verificacaoValidez == 2);
				break;
			case 6: //banco de dados
				do{
					system("cls");
					printf("\n\n\t[1] Exibir todos os agendamentos");
					printf("\n\t[2] Exibir todos as avaliações");
					printf("\n\t[3] Exibir todos os funcionários");
					printf("\n\t[4] Exibir todos os gastos");
					printf("\n\t[5] Exibir todos os pacientes");
					printf("\n\t[6] Voltar ao menu principal");
					printf("\n\tInsira o número correspondente à opção que deseja (somente o número): ");
					scanf("%d", &menuEscolha);

					switch(menuEscolha){
						case 1:
							exibirAgendamentos();
							verificacaoValidez = 1;
							break;
						case 2:
							exibirAvaliacoes();
							verificacaoValidez = 1;
							break;
						case 3:
							exibirFuncionarios();
							verificacaoValidez = 1;
							break;
						case 4:
							exibirGastos();
							verificacaoValidez = 1;
							break;
						case 5:
							exibirPacientes();
							verificacaoValidez = 1;
							break;
						case 6:
							verificacaoValidez = 1;
							break;
						default:
							verificacaoValidez = 2;
							break;
					}
				}while(verificacaoValidez == 2);
				break;
			case 7: //tema do programa
				do{
					system("cls");
					printf("\n\n\t[1] Modo Normal");
					printf("\n\t[2] Modo Dark");
					printf("\n\t[3] Modo Natalino");
					printf("\n\t[4] Modo Matrix");
					printf("\n\t[5] Modo Tela Azul");
					printf("\n\t[6] Voltar ao menu principal");
					printf("\n\tInsira o número correspondente ao modo que deseja (somente o número): ");
					scanf("%d", &menuEscolha);

					switch(menuEscolha){
						case 1: //normal
							system("color F0");
							verificacaoValidez = 1;
						case 2: //dark
							system("color 0F");
							verificacaoValidez = 1;
							break;
						case 3: //natalino
							system("color 24");
							verificacaoValidez = 1;
							break;
						case 4: //matrix
							system("color 0A");
							verificacaoValidez = 1;
							break;
						case 5: //tela azul
							system("color 1F");
							verificacaoValidez = 1;
							break;
						case 6:
							verificacaoValidez = 1;
							break;
						default:
							verificacaoValidez = 2;
							break;
					}
				}while(verificacaoValidez == 2);
				break;
			default:			
				system("cls");
				printf("\t _________   __          __   ___    __   __   _________   _________ 	   ___    __   __   _________ ");
				printf("\n\t|   ______| |  |        |  | |   \\  |  | |  | |   ______| |   ___   |     |   \\  |  | |  | |   ___   |");
				printf("\n\t|  |        |  |        |  | |    \\ |  | |  | |  |        |  |   |  |     |    \\ |  | |  | |  |   |  |");
				printf("\n\t|  |        |  |        |  | |  |  \\|  | |  | |  |        |  |___|  |     |  |  \\|  | |  | |  |___|  |");
				printf("\n\t|  |        |  |        |  | |  |\\     | |  | |  |        |   ___   |     |  |\\     | |  | |   ______|");
				printf("\n\t|  |______  |  |______  |  | |  | \\    | |  | |  |______  |  |	 |  |     |  | \\    | |  | |  |");
				printf("\n\t|_________| |_________| |__| |__|  \\___| |__| |_________| |__|	 |__|     |__|  \\___| |__| |__|");
				printf("\n\n\tTem certeza que deseja finalizar o programa? Se sim, digite 1, e se não, digite 2: ");
				scanf("%d", &verificacaoValidez);
				if(verificacaoValidez == 1){
					verificacaoValidez = 2;
				}else if(verificacaoValidez == 2){
					verificacaoValidez = 1;
				}
				break;
		} //fim do menu principal
	system("cls");
	}while(verificacaoValidez == 1);

	system("cls");
	printf("\n\tPROGRAMA ENCERRADO");
	return 0;
}
