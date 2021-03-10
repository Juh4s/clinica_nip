time_t t = time(NULL);
struct tm tm = *localtime(&t);
int verificacaoValidez, verificacaoValidez3, minuto, hora, dia, mes, ano, idade, numero, apartamento, menuEscolha;
char unidade[10], nome[200], rg[20], telefone[20], email[100], nomeMedico[200], cpf[20], cidade[100], uf[10], endereco[100], cep[20], profissao[100], casaOuPredio[10], religiao[100], genero[10];
float valorConsulta, salario; 

int minutoVerific, horaVerific, diaVerific, mesVerific, anoVerific, idadeVerific, numeroVerific, apartamentoVerific; //variaveis para fazer compara��o da informa��o inserida pelo usuario com a informa��o dos arquivos
char unidadeVerific[10], nomeVerific[200], rgVerific[20], telefoneVerific[20], emailVerific[100], nomeMedicoVerific[200], cpfVerific[20], ufVerific[10], cidadeVerific[100], enderecoVerific[100], casaOuPredioVerific[10], cepVerific[20], profissaoVerific[100], generoVerific[10]; 
float valorConsultaVerific, salarioVerific;
char unidadeA[10]="A", unidadeB[10]="B", unidadeC[10]="C", casa[10]="Casa", predio[10]="Predio", medico[20]="Medico", enfermeiro[20]="Enfermeiro", recepcionista[20]="Recepcionista", arquivoTemporarioAgendamentos[50]="Agendamentos Novo.txt", arquivoPermanenteAgendamentos[50]="Agendamentos.txt";
char generoM[10]="M",generoF[10]="F",generoND[10]="ND";

void agendamentoConsultar(){
	
	FILE *agendamentos;
	verificacaoValidez3 = 1;
	
	do{
		system("cls");
		printf("\n\tTELA DE CONSULTA DE AGENDAMENTO");
		printf("\n\n\t[1] Consultar pela data");
		printf("\n\t[2] Consultar pelos dados do paciente");
		printf("\n\t[3] Cancelar consulta");
		printf("\n\tInsira o n�mero correspondente � forma de busca que deseja (somente o n�mero): ");
		scanf("%d", &menuEscolha);
		
		switch(menuEscolha){
			case 1: //busca pela data
				do{
					system("cls");
					printf("\n\tTELA DE CONSULTA DE AGENDAMENTO");
					printf("\n\n\tInsira a unidade a qual esse agendamento pertence (A, B ou C): ");
					fflush(stdin);
					fgets(unidade, 10, stdin);
					unidade[strcspn (unidade, "\n\000")] = '\000';
					printf("\tInsira a data da consulta:\n\tDia (EX: 8): ");
					scanf("%d", &dia);
					printf("\tM�s (EX: 5): ");
					scanf("%d", &mes);
					printf("\tAno (EX: 2020): ");
					scanf("%d", &ano);
					printf("\tInsira o hor�rio da consulta:\n\tHora (Entre 8 e 20): ");
					scanf("%d", &hora);
					printf("\tMinuto (0, 15, 30 ou 45): ");
					scanf("%d", &minuto);
					
					system("cls");
					printf("\n\tTELA DE CONSULTA DE AGENDAMENTO");
					agendamentos = fopen("Agendamentos.txt","r");
					do{
						int t = fscanf(agendamentos," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %d %d %d %d %[^\n] %f", unidadeVerific, nomeVerific, rgVerific, cpfVerific, telefoneVerific, emailVerific, &diaVerific, &mesVerific, &anoVerific, &horaVerific, &minutoVerific, nomeMedicoVerific, &valorConsultaVerific);
						if(t == EOF){	
							if(verificacaoValidez3 != 2){
								printf("\n\n\tAgendamento inserido n�o encontrado.");
							}
							verificacaoValidez = 1;
						}else if(strcmp(unidade,unidadeVerific) == 0 && dia == diaVerific && mes == mesVerific && ano == anoVerific && hora == horaVerific && minuto == minutoVerific){
							printf("\n\n\tUnidade: %s", unidadeVerific);
							printf("\n\tNome do paciente: %s", nomeVerific);
							printf("\n\tRG do paciente: %s", rgVerific);
							printf("\n\tCPF do paciente: %s", cpfVerific);
							printf("\n\tTelefone do paciente: %s", telefoneVerific);
							printf("\n\tEmail do paciente: %s", emailVerific);
							if(mesVerific >= 10 && diaVerific >= 10){
								printf("\n\tData da consulta: %d/%d/%d", diaVerific, mesVerific, anoVerific);
							}else if(mesVerific < 10 && diaVerific >= 10){
								printf("\n\tData da consulta: %d/0%d/%d", diaVerific, mesVerific, anoVerific);
							}else if(mesVerific < 10 && diaVerific < 10){
								printf("\n\tData da consulta: 0%d/0%d/%d", diaVerific, mesVerific, anoVerific);
							}else if(mesVerific >= 10 && diaVerific < 10){
								printf("\n\tData da consulta: 0%d/%d/%d", diaVerific, mesVerific, anoVerific);
							}
							if(horaVerific >= 10 && minutoVerific != 0){
								printf("\n\tHor�rio da consulta: %d:%d", horaVerific, minutoVerific);
							}else if(horaVerific < 10 && minutoVerific != 0){
								printf("\n\tHor�rio da consulta: 0%d:%d", horaVerific, minutoVerific);
							}else if(horaVerific < 10 && minutoVerific == 0){
								printf("\n\tHor�rio da consulta: 0%d:0%d", horaVerific, minutoVerific);
							}else if(horaVerific >= 10 && minutoVerific == 0){
								printf("\n\tHor�rio da consulta: %d:0%d", horaVerific, minutoVerific);
							}
							printf("\n\tM�dico(a)/enfermeiro(a) que atender�: %s", nomeMedicoVerific);
							printf("\n\tValor da consulta: R$ %.2f", valorConsultaVerific);
							verificacaoValidez = 2;
							verificacaoValidez3 = 2;
						}else{
							verificacaoValidez = 2;
						}
					}while(verificacaoValidez != 1);
					fclose(agendamentos);
					verificacaoValidez3 = 1;
					printf("\n\n\tDeseja consultar outro agendamento pela data? Se sim, digite 1, e se n�o, digite 2: ");
					scanf("%d", &verificacaoValidez);
				}while(verificacaoValidez == 1);
				break;
			case 2: //busca pelos dados do paciente
				do{
					system("cls");
					printf("\n\tTELA DE CONSULTA DE AGENDAMENTO");
					printf("\n\n\tInsira a unidade a qual esse agendamento pertence (A, B ou C): ");
					fflush(stdin);
					fgets(unidade, 10, stdin);
					unidade[strcspn (unidade, "\n\000")] = '\000';
					printf("\tInsira o RG do paciente (EX: 00.000.000-0): ");
					fflush(stdin);
					fgets(rg, 20, stdin);
					if(strlen(rg) != 13){ //verifica se o RG tem 12 digitos (9 n�meros e 3 separadores)
						printf("\tRG inv�lido, tente novamente\n\t");
						system("pause");
						continue;
					}
					rg[strcspn (rg, "\n\000")] = '\000';
					
					system("cls");
					printf("\n\tTELA DE CONSULTA DE AGENDAMENTO");
					agendamentos = fopen("Agendamentos.txt","r");
					do{
						int t = fscanf(agendamentos," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %d %d %d %d %[^\n] %f", unidadeVerific, nomeVerific, rgVerific, cpfVerific, telefoneVerific, emailVerific, &diaVerific, &mesVerific, &anoVerific, &horaVerific, &minutoVerific, nomeMedicoVerific, &valorConsultaVerific);
						if(t == EOF){	
							if(verificacaoValidez3 != 2){
								printf("\n\n\tAgendamento inserido n�o encontrado.");
							}
							verificacaoValidez = 1;
						}else if(strcmp(unidade,unidadeVerific) == 0 && strcmp(rg,rgVerific) == 0){
							printf("\n\n\tUnidade: %s", unidadeVerific);
							printf("\n\tNome do paciente: %s", nomeVerific);
							printf("\n\tRG do paciente: %s", rgVerific);
							printf("\n\tCPF do paciente: %s", cpfVerific);
							printf("\n\tTelefone do paciente: %s", telefoneVerific);
							printf("\n\tEmail do paciente: %s", emailVerific);
							if(mesVerific >= 10 && diaVerific >= 10){
								printf("\n\tData da consulta: %d/%d/%d", diaVerific, mesVerific, anoVerific);
							}else if(mesVerific < 10 && diaVerific >= 10){
								printf("\n\tData da consulta: %d/0%d/%d", diaVerific, mesVerific, anoVerific);
							}else if(mesVerific < 10 && diaVerific < 10){
								printf("\n\tData da consulta: 0%d/0%d/%d", diaVerific, mesVerific, anoVerific);
							}else if(mesVerific >= 10 && diaVerific < 10){
								printf("\n\tData da consulta: 0%d/%d/%d", diaVerific, mesVerific, anoVerific);
							}
							if(horaVerific >= 10 && minutoVerific != 0){
								printf("\n\tHor�rio da consulta: %d:%d", horaVerific, minutoVerific);
							}else if(horaVerific < 10 && minutoVerific != 0){
								printf("\n\tHor�rio da consulta: 0%d:%d", horaVerific, minutoVerific);
							}else if(horaVerific < 10 && minutoVerific == 0){
								printf("\n\tHor�rio da consulta: 0%d:0%d", horaVerific, minutoVerific);
							}else if(horaVerific >= 10 && minutoVerific == 0){
								printf("\n\tHor�rio da consulta: %d:0%d", horaVerific, minutoVerific);
							}
							printf("\n\tM�dico(a)/enfermeiro(a) que atender�: %s", nomeMedicoVerific);
							printf("\n\tValor da consulta: R$ %.2f", valorConsultaVerific);
							verificacaoValidez = 2;
							verificacaoValidez3 = 2;
						}else{
							verificacaoValidez = 2;
						}
					}while(verificacaoValidez != 1);
					fclose(agendamentos);
					verificacaoValidez3 = 1;
					printf("\n\n\tDeseja consultar outro agendamento pelos dados do paciente? Se sim, digite 1, e se n�o, digite 2: ");
					scanf("%d", &verificacaoValidez);
				}while(verificacaoValidez == 1);
				break;
			default:
				verificacaoValidez = 2;
				continue;
		}
		
		system("cls");
		printf("\n\tTELA DE CONSULTA DE AGENDAMENTO");
		printf("\n\n\tDeseja consultar outro agendamento? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);
}

void agendamentoCriar(){

	FILE *agendamentos; //ponteiro do arquivo de agendamentos
	FILE *funcionarios;
	verificacaoValidez3 = 1;
	
	do{
    	system("cls");
		printf("\n\tTELA DE AGENDAMENTO");
		printf("\n\n\tInsira a unidade a qual esse agendamento pertence (A, B ou C): ");
		fflush(stdin); //limpa o input para evitar erros
		fgets(unidade, 10, stdin); //recebe input do usu�rio
		unidade[strcspn (unidade, "\n\000")] = '\000'; //remove o \n da informa��o inserida pelo usu�rio, afim de comparar essa informa��o inserida com a informa��o lida do arquivo corretamente
		if(strcmp(unidade,unidadeA) != 0 && strcmp(unidade,unidadeB) != 0 && strcmp(unidade,unidadeC) != 0){ //verifica se a unidade inserida � A, B ou C, e se n�o for nenhuma das 3, retorna um erro e reseta a tela
			printf("\tUnidade inserida inv�lida/n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tInsira o nome completo do paciente: ");
		fflush(stdin);
		fgets(nome, 200, stdin);
		printf("\tInsira o RG do paciente (EX: 00.000.000-0): ");
		fflush(stdin);
		fgets(rg, 20, stdin);
		if(strlen(rg) != 13){ //verifica se o RG tem 12 digitos (9 n�meros e 3 separadores)
			printf("\tRG inv�lido, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tInsira o CPF do paciente (EX: 000.000.000-00): ");
		fflush(stdin);
		fgets(cpf, 20, stdin);
		if(strlen(cpf) != 15){ //verifica se o RG tem 14 digitos (11 n�meros e 3 separadores)
			printf("\tCPF inv�lido, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tInsira o tefelone do paciente (EX: (11)93535-0202): ");
		fflush(stdin);
		fgets(telefone, 20, stdin);
		if(strlen(telefone) != 14 && strlen(telefone) != 15){ //verifica se o n�mero tem 13 ou 14 digitos (10/11 n�meros e 3 separadores)
			printf("\tTelefone inv�lido, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tInsira o email do paciente (EX: emailexemplo@gmail.com): ");
		fflush(stdin);
		fgets(email, 100, stdin);
		printf("\tInsira a data da consulta:\n\tAno (EX: 2020): ");
		scanf("%d", &ano);
		if(ano < tm.tm_year + 1900){ //verifica se o ano inserido � menor que o atual, ou seja, se o ano inserido ja passou
			printf("\tAno inserido j� passou, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tM�s (EX: 5): ");
		scanf("%d", &mes);
		if(mes <1 || mes >12){ //verifica se o mes � entre 1 e 12 (afinal, n�o existe mes 0 nem 13)
			printf("\tM�s inserido n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		if(ano == tm.tm_year + 1900){ //verifica se o ano inserido � o atual
			if(mes < tm.tm_mon + 1){ //verifica se o mes inserido � menor que o atual (ou seja, verifica se o mes inserido ja passou)
				printf("\tM�s inserido j� passou, tente novamente\n\t");
				system("pause");
				continue;
			}
		}
		printf("\tDia (EX: 8): ");
		scanf("%d", &dia);
		if(dia <1 || dia >31){ //verifica se o dia � entre 1 e 31 (afinal, n�o existe dia 0 nem 32)
			printf("\tDia inserido n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		if(ano == tm.tm_year + 1900){ //verifica se o ano inserido � o atual
			if(mes == tm.tm_mon + 1){ //verifica se o mes inserido � o atual
				if(dia <= tm.tm_mday){ //verifica se o dia inserido � menor ou igual que o atual (ou seja, verifica se o dia inserido ja passou ou � hoje)
					printf("\tDia inserido j� passou/� hoje, tente novamente\n\t");
					system("pause");
					continue;
				}
			}
		}
		printf("\tInsira o hor�rio da consulta:\n\tHora (Entre 8 e 20): ");
		scanf("%d", &hora);
		if(hora <8 || hora >20){
			printf("\tHora inserida fora do hor�rio de funcionamento, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tMinuto (0, 15, 30 ou 45): ");
		scanf("%d", &minuto);
		if(minuto != 0 && minuto != 15 && minuto != 30 && minuto != 45){
			printf("\tMinuto inv�lido, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tInsira o nome completo do m�dico(a)/enfermeiro(a) que ira atender o paciente: ");
		fflush(stdin);
		fgets(nomeMedico, 200, stdin);
		nomeMedico[strcspn (nomeMedico, "\n")] = '\000';
		
		funcionarios = fopen("Funcionarios.txt","r"); //verifica��o se o hor�rio inserido est� dispon�vel
		do{ //loop para leitura dos dados do arquivo Agendamentos.txt
			int t = fscanf(funcionarios," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %[^\n] %[^\n] %[^\n] %d %[^\n] %d %[^\n] %[^\n] %[^\n] %f", unidadeVerific, nomeMedicoVerific, generoVerific, rgVerific, cpfVerific, &idadeVerific, ufVerific, cidadeVerific, enderecoVerific, &numeroVerific, casaOuPredioVerific, &apartamentoVerific, cepVerific, telefoneVerific, profissaoVerific, &salarioVerific);
			if(strcmp(nomeMedico,nomeMedicoVerific) == 0 && strcmp(unidade,unidadeVerific) == 0){ //compara as informa��es inseridas com as informa��es do arquivo
				verificacaoValidez = 1;
			}else if(t == EOF){
				printf("\tM�dico(a)/enfermeiro(a) inserido n�o encontrado/n�o trabalha na unidade inserida, tente novamente.\n\t");
				system("pause");
				verificacaoValidez3 = 2;
				verificacaoValidez = 1;
			}else{
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(funcionarios);
		
		if(verificacaoValidez3 == 2){
			verificacaoValidez3 = 1;
			continue;
		}
		
		agendamentos = fopen("Agendamentos.txt","r"); 
		do{
			int t = fscanf(agendamentos," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %d %d %d %d %[^\n] %f", unidadeVerific, nomeVerific, rgVerific, cpfVerific, telefoneVerific, emailVerific, &diaVerific, &mesVerific, &anoVerific, &horaVerific, &minutoVerific, nomeMedicoVerific, &valorConsultaVerific);
			if(strcmp(unidade,unidadeVerific) == 0 && strcmp(nomeMedico,nomeMedicoVerific) == 0 && dia == diaVerific && mes == mesVerific && ano == anoVerific && hora == horaVerific && minuto == minutoVerific){
				printf("\tHor�rio indispon�vel, tente novamente");
				printf("\n\t");
				system("pause");
				verificacaoValidez = 2;
				break;
			}else if(t == EOF){
				verificacaoValidez = 1;
			}else{
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(agendamentos);
		
		if(verificacaoValidez == 2){
			verificacaoValidez = 1;
			continue;
		}
		printf("\tInsira o valor da consulta (ex: 850,50): ");
		scanf("%f", &valorConsulta);
		
		system("cls");
		printf("\n\n\tTELA DE AGENDAMENTO");
		printf("\n\n\tUnidade: %s", unidade);
		printf("\n\tNome do paciente: %s", nome);
		printf("\tRG do paciente: %s", rg);
		printf("\tCPF do paciente: %s", cpf);
		printf("\tTelefone do paciente: %s", telefone);
		printf("\tEmail do paciente: %s", email);
		if(mes >= 10 && dia >= 10){
			printf("\tData da consulta: %d/%d/%d", dia, mes, ano);
		}else if(mes < 10 && dia >= 10){
			printf("\tData da consulta: %d/0%d/%d", dia, mes, ano);
		}else if(mes < 10 && dia < 10){
			printf("\tData da consulta: 0%d/0%d/%d", dia, mes, ano);
		}else if(mes >= 10 && dia < 10){
			printf("\tData da consulta: 0%d/%d/%d", dia, mes, ano);
		}
		if(hora >= 10 && minuto != 0){
			printf("\n\tHor�rio da consulta: %d:%d", hora, minuto);
		}else if(hora < 10 && minuto != 0){
			printf("\n\tHor�rio da consulta: 0%d:%d", hora, minuto);
		}else if(hora < 10 && minuto == 0){
			printf("\n\tHor�rio da consulta: 0%d:0%d", hora, minuto);
		}else if(hora >= 10 && minuto == 0){
			printf("\n\tHor�rio da consulta: %d:0%d", hora, minuto);
		}
		printf("\n\tM�dico(a)/enfermeiro(a) que atender�: %s", nomeMedico);
		printf("\n\tValor da consulta: R$ %.2f", valorConsulta);
		
		printf("\n\n\tDeseja salvar esse agendamento? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
		
		if(verificacaoValidez == 1){
			agendamentos = fopen("Agendamentos.txt","a");
			if((agendamentos=fopen("Agendamentos.txt","a"))==NULL){
				puts("\n\n\tERRO: N�o foi poss�vel criar arquivo com agendamentos/Arquivo de agendamentos n�o encontrado!");
				printf("\t");
				system("pause");
				continue;
			}
			fprintf(agendamentos,"%s\n%s%s%s%s%s%d %d %d %d %d\n%s\n%.2f\n", unidade, nome, rg, cpf, telefone, email, dia, mes, ano, hora, minuto, nomeMedico, valorConsulta);
			fclose(agendamentos);
		}
		
		system("cls");
		printf("\n\tTELA DE AGENDAMENTO");
		printf("\n\n\tDeseja cadastrar outro agendamento? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);
	
}

void agendamentoEditar(){

	FILE *agendamentos; //ponteiro do arquivo de agendamentos antigo
	FILE *temporario; //ponteiro do arquivo de agendamentos novo
	verificacaoValidez3 = 1;
	
	do{
    	system("cls");
		printf("\n\tTELA DE EDI��O DE AGENDAMENTO");
		printf("\n\n\tInsira a unidade a qual esse agendamento pertence (A, B ou C): ");
		fflush(stdin);
		fgets(unidade, 10, stdin);
		unidade[strcspn (unidade, "\n\000")] = '\000';
		printf("\tInsira o RG do paciente (EX: 00.000.000-0): ");
		fflush(stdin);
		fgets(rg, 20, stdin);
		rg[strcspn (rg, "\n\000")] = '\000';
		printf("\tInsira a data da consulta:\n\tDia (EX: 8): ");
		scanf("%d", &dia);
		printf("\tM�s (EX: 5): ");
		scanf("%d", &mes);
		printf("\tAno (EX: 2020): ");
		scanf("%d", &ano);
		printf("\tInsira o hor�rio da consulta:\n\tHora (Entre 8 e 20): ");
		scanf("%d", &hora);
		printf("\tMinuto (0, 15, 30 ou 45): ");
		scanf("%d", &minuto);
		
		system("cls");
		agendamentos = fopen("Agendamentos.txt","r"); //verifica��o se o hor�rio inserido est� dispon�vel
		temporario = fopen("Agendamentos Novo.txt","w+");
		
		do{ //loop para leitura dos dados do arquivo Agendamentos.txt
			int t = fscanf(agendamentos," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %d %d %d %d %[^\n] %f", unidadeVerific, nomeVerific, rgVerific, cpfVerific, telefoneVerific, emailVerific, &diaVerific, &mesVerific, &anoVerific, &horaVerific, &minutoVerific, nomeMedicoVerific, &valorConsultaVerific);
			if(t == EOF){
				if(verificacaoValidez3 != 2){
					printf("\n\tTELA DE EDI��O DE AGENDAMENTO");
					printf("\n\n\tAgendamento inserido n�o encontrado\n\t");
				}
				verificacaoValidez = 1;
				break;
			}
			if(strcmp(unidade,unidadeVerific) == 0 && strcmp(rg,rgVerific) == 0 && dia == diaVerific && mes == mesVerific && ano == anoVerific && hora == horaVerific && minuto == minutoVerific){ //compara as informa��es inseridas com as informa��es do arquivo
				printf("\n\n\tTELA DE EDI��O DE AGENDAMENTO");
				printf("\n\n\tUnidade: %s", unidadeVerific);
				printf("\n\tNome do paciente: %s", nomeVerific);
				printf("\n\tRG do paciente: %s", rgVerific);
				printf("\n\tCPF do paciente: %s", cpfVerific);
				printf("\n\tTelefone do paciente: %s", telefoneVerific);
				printf("\n\tEmail do paciente: %s", emailVerific);
				if(mesVerific >= 10 && diaVerific >= 10){
					printf("\n\tData da consulta: %d/%d/%d", diaVerific, mesVerific, anoVerific);
				}else if(mesVerific < 10 && diaVerific >= 10){
					printf("\n\tData da consulta: %d/0%d/%d", diaVerific, mesVerific, anoVerific);
				}else if(mesVerific < 10 && diaVerific < 10){
					printf("\n\tData da consulta: 0%d/0%d/%d", diaVerific, mesVerific, anoVerific);
				}else if(mesVerific >= 10 && diaVerific < 10){
					printf("\n\tData da consulta: 0%d/%d/%d", diaVerific, mesVerific, anoVerific);
				}
				if(horaVerific >= 10 && minutoVerific != 0){
					printf("\n\tHor�rio da consulta: %d:%d", horaVerific, minutoVerific);
				}else if(horaVerific < 10 && minutoVerific != 0){
					printf("\n\tHor�rio da consulta: 0%d:%d", horaVerific, minutoVerific);
				}else if(horaVerific < 10 && minutoVerific == 0){
					printf("\n\tHor�rio da consulta: 0%d:0%d", horaVerific, minutoVerific);
				}else if(horaVerific >= 10 && minutoVerific == 0){
					printf("\n\tHor�rio da consulta: %d:0%d", horaVerific, minutoVerific);
				}
				printf("\n\tM�dico(a)/enfermeiro(a) que atender�: %s", nomeMedicoVerific);
				printf("\n\tValor da consulta: R$ %.2f", valorConsultaVerific);
		
				printf("\n\n\tTem certeza que deseja editar esse agendamento? Se sim, digite 1, e se n�o, digite 2: ");
				scanf("%d", &verificacaoValidez);
				
				if(verificacaoValidez == 1){
					do{
						system("cls");
						printf("\n\tTELA DE EDI��O DE AGENDAMENTO");
						printf("\n\n\tDeseja editar a unidade? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira a unidade a qual esse agendamento pertence (A, B ou C): ");
							fflush(stdin);
							fgets(unidadeVerific, 10, stdin);
							unidadeVerific[strcspn (unidadeVerific, "\n\000")] = '\000';
							if(strcmp(unidadeVerific,unidadeA) != 0 && strcmp(unidadeVerific,unidadeB) != 0 && strcmp(unidadeVerific,unidadeC) != 0){
								printf("\tUnidade inserida inv�lida/n�o existe, tente novamente\n\t");
								system("pause");
								continue;
							}
						}
						printf("\n\tDeseja editar a data? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){		
							printf("\tInsira a data da consulta:\n\tAno (EX: 2020): ");
							scanf("%d", &anoVerific);
							if(anoVerific < tm.tm_year + 1900){ //verifica se o ano inserido � menor que o atual, ou seja, se o ano inserido ja passou
								printf("\tAno inserido j� passou, tente novamente\n\t");
								system("pause");
								continue;
							}
							printf("\tM�s (EX: 5): ");
							scanf("%d", &mesVerific);
							if(mesVerific <1 || mesVerific >12){ //verifica se o mes � entre 1 e 12 (afinal, n�o existe mes 0 nem 13)
								printf("\tM�s inserido n�o existe, tente novamente\n\t");
								system("pause");
								continue;
							}
							if(anoVerific == tm.tm_year + 1900){ //verifica se o ano inserido � o atual
								if(mesVerific < tm.tm_mon + 1){ //verifica se o mes inserido � menor que o atual (ou seja, verifica se o mes inserido ja passou)
									printf("\tM�s inserido j� passou, tente novamente\n\t");
									system("pause");
									continue;
								}
							}
							printf("\tDia (EX: 8): ");
							scanf("%d", &diaVerific);
							if(diaVerific <1 || diaVerific >31){ //verifica se o dia � entre 1 e 31 (afinal, n�o existe dia 0 nem 32)
								printf("\tDia inserido n�o existe, tente novamente\n\t");
								system("pause");
								continue;
							}
							if(anoVerific == tm.tm_year + 1900){ //verifica se o ano inserido � o atual
								if(mesVerific == tm.tm_mon + 1){ //verifica se o mes inserido � o atual
									if(diaVerific <= tm.tm_mday){ //verifica se o dia inserido � menor ou igual que o atual (ou seja, verifica se o dia inserido ja passou ou � hoje)
										printf("\tDia inserido j� passou/� hoje, tente novamente\n\t");
										system("pause");
										continue;
									}
								}
							}
						}
						printf("\n\tDeseja editar o hor�rio? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){			
							printf("\tInsira o hor�rio da consulta:\n\tHora (Entre 8 e 20): ");
							scanf("%d", &horaVerific);
							if(horaVerific <8 || horaVerific >20){
								printf("\tHora inserida fora do hor�rio de funcionamento, tente novamente\n\t");
								system("pause");
								continue;
							}
							printf("\tMinuto (0, 15, 30 ou 45): ");
							scanf("%d", &minutoVerific);
							if(minutoVerific != 0 && minutoVerific != 15 && minutoVerific != 30 && minutoVerific != 45){
								printf("\tMinuto inv�lido, tente novamente\n\t");
								system("pause");
								continue;
							}
						}
						printf("\n\tDeseja editar o m�dico(a)/enfermeiro(a) que realizar� a consulta? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){			
							printf("\tInsira o nome completo do m�dico(a)/enfermeiro(a) que ira atender o paciente: ");
							fflush(stdin);
							fgets(nomeMedicoVerific, 200, stdin);
							nomeMedicoVerific[strcspn (nomeMedicoVerific, "\n")] = '\000';
						}
						printf("\n\tSe deseja reiniciar o menu de edi��o (cancelando as edi��es feitas at� agora), digite 1.\n\tSe deseja sair da tela de edi��o (salvando as edi��es realizadas OU cancelando a edi��o, caso nada tenha sido editado), digite 2. ");
						printf("\n\tInsira a sua escolha: ");
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 2){
							fprintf(temporario,"%s\n%s\n%s\n%s\n%s\n%s\n%d %d %d %d %d\n%s\n%.2f\n", unidadeVerific, nomeVerific, rgVerific, cpfVerific, telefoneVerific, emailVerific, diaVerific, mesVerific, anoVerific, horaVerific, minutoVerific, nomeMedicoVerific, valorConsultaVerific);
							printf("\n\tEdi��o conclu�da\n\t");
							system("pause");
						}
					}while(verificacaoValidez == 1);
				}else if(verificacaoValidez == 2){
					fprintf(temporario,"%s\n%s\n%s\n%s\n%s\n%s\n%d %d %d %d %d\n%s\n%.2f\n", unidadeVerific, nomeVerific, rgVerific, cpfVerific, telefoneVerific, emailVerific, diaVerific, mesVerific, anoVerific, horaVerific, minutoVerific, nomeMedicoVerific, valorConsultaVerific);
					printf("\n\tEdi��o cancelada\n\t");
					system("pause");
				}
				verificacaoValidez = 2;
				verificacaoValidez3 = 2;
			}else{
				fprintf(temporario,"%s\n%s\n%s\n%s\n%s\n%s\n%d %d %d %d %d\n%s\n%.2f\n", unidadeVerific, nomeVerific, rgVerific, cpfVerific, telefoneVerific, emailVerific, diaVerific, mesVerific, anoVerific, horaVerific, minutoVerific, nomeMedicoVerific, valorConsultaVerific);
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(agendamentos);
		fclose(temporario);
		
		int ret2 = remove(arquivoPermanenteAgendamentos);
		if(ret2 != 0){
			printf("\n\n\tArquivo n�o foi deletado corretamente!\n\n\t");
			perror("Error: ");
			system("pause");
		}
		int ret = rename(arquivoTemporarioAgendamentos, arquivoPermanenteAgendamentos);
		if(ret != 0){
			printf("\n\n\tArquivo n�o foi renomeado corretamente!\n\n\t");
			perror("Error: ");
			system("pause");
		}
		if(verificacaoValidez3 != 2){
			printf("\n\tDeseja procurar novamente? Se sim, digite 1, e se n�o, digite 2: ");
			scanf("%d", &verificacaoValidez);
			if(verificacaoValidez == 1){
				continue;
			}else{
				verificacaoValidez = 2;
				continue;
			}
		}
		system("cls");
		printf("\n\tTELA DE EDI��O DE AGENDAMENTO");
		printf("\n\n\tDeseja editar outro agendamento? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);	
}

void agendamentoCancelar(){

	FILE *agendamentos; //ponteiro do arquivo de agendamentos antigo
	FILE *temporario; //ponteiro do arquivo de agendamentos novo
	verificacaoValidez3 = 1;
	
	do{
    	system("cls");
		printf("\n\tTELA DE CANCELAMENTO DE AGENDAMENTO");
		printf("\n\n\tInsira a unidade a qual esse agendamento pertence (A, B ou C): ");
		fflush(stdin);
		fgets(unidade, 10, stdin);
		unidade[strcspn (unidade, "\n\000")] = '\000';
		printf("\tInsira o RG do paciente (EX: 00.000.000-0): ");
		fflush(stdin);
		fgets(rg, 20, stdin);
		rg[strcspn (rg, "\n\000")] = '\000';
		printf("\tInsira a data da consulta:\n\tDia (EX: 8): ");
		scanf("%d", &dia);
		printf("\tM�s (EX: 5): ");
		scanf("%d", &mes);
		printf("\tAno (EX: 2020): ");
		scanf("%d", &ano);
		printf("\tInsira o hor�rio da consulta:\n\tHora (Entre 8 e 20): ");
		scanf("%d", &hora);
		printf("\tMinuto (0, 15, 30 ou 45): ");
		scanf("%d", &minuto);
		
		system("cls");
		agendamentos = fopen("Agendamentos.txt","r"); //verifica��o se o hor�rio inserido est� dispon�vel
		temporario = fopen("Agendamentos Novo.txt","w+");
		
		do{ //loop para leitura dos dados do arquivo Agendamentos.txt
			int t = fscanf(agendamentos," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %d %d %d %d %[^\n] %f", unidadeVerific, nomeVerific, rgVerific, cpfVerific, telefoneVerific, emailVerific, &diaVerific, &mesVerific, &anoVerific, &horaVerific, &minutoVerific, nomeMedicoVerific, &valorConsultaVerific);
			if(t == EOF){
				if(verificacaoValidez3 != 2){
					printf("\n\tTELA DE CANCELAMENTO DE AGENDAMENTO");
					printf("\n\n\tAgendamento inserido n�o encontrado\n\t");
				}
				verificacaoValidez = 1;
				break;
			}
			if(strcmp(unidade,unidadeVerific) == 0 && strcmp(rg,rgVerific) == 0 && dia == diaVerific && mes == mesVerific && ano == anoVerific && hora == horaVerific && minuto == minutoVerific){ //compara as informa��es inseridas com as informa��es do arquivo
				printf("\n\n\tTELA DE CANCELAMENTO DE AGENDAMENTO");
				printf("\n\n\tUnidade: %s", unidadeVerific);
				printf("\n\tNome do paciente: %s", nomeVerific);
				printf("\n\tRG do paciente: %s", rgVerific);
				printf("\n\tCPF do paciente: %s", cpfVerific);
				printf("\n\tTelefone do paciente: %s", telefoneVerific);
				printf("\n\tEmail do paciente: %s", emailVerific);
				if(mesVerific >= 10 && diaVerific >= 10){
					printf("\n\tData da consulta: %d/%d/%d", diaVerific, mesVerific, anoVerific);
				}else if(mesVerific < 10 && diaVerific >= 10){
					printf("\n\tData da consulta: %d/0%d/%d", diaVerific, mesVerific, anoVerific);
				}else if(mesVerific < 10 && diaVerific < 10){
					printf("\n\tData da consulta: 0%d/0%d/%d", diaVerific, mesVerific, anoVerific);
				}else if(mesVerific >= 10 && diaVerific < 10){
					printf("\n\tData da consulta: 0%d/%d/%d", diaVerific, mesVerific, anoVerific);
				}
				if(horaVerific >= 10 && minutoVerific != 0){
					printf("\n\tHor�rio da consulta: %d:%d", horaVerific, minutoVerific);
				}else if(horaVerific < 10 && minutoVerific != 0){
					printf("\n\tHor�rio da consulta: 0%d:%d", horaVerific, minutoVerific);
				}else if(horaVerific < 10 && minutoVerific == 0){
					printf("\n\tHor�rio da consulta: 0%d:0%d", horaVerific, minutoVerific);
				}else if(horaVerific >= 10 && minutoVerific == 0){
					printf("\n\tHor�rio da consulta: %d:0%d", horaVerific, minutoVerific);
				}
				printf("\n\tM�dico(a)/enfermeiro(a) que atender�: %s", nomeMedicoVerific);
				printf("\n\tValor da consulta: R$ %.2f", valorConsultaVerific);
		
				printf("\n\n\tTem certeza que deseja cancelar esse agendamento? Se sim, digite 1, e se n�o, digite 2: ");
				scanf("%d", &verificacaoValidez);
				
				if(verificacaoValidez == 1){
					printf("\n\tAgendamento cancelado com sucesso\n\t");
					system("pause");
				}else if(verificacaoValidez == 2){
					fprintf(temporario,"%s\n%s\n%s\n%s\n%s\n%s\n%d %d %d %d %d\n%s\n%.2f\n", unidadeVerific, nomeVerific, rgVerific, cpfVerific, telefoneVerific, emailVerific, diaVerific, mesVerific, anoVerific, horaVerific, minutoVerific, nomeMedicoVerific, valorConsultaVerific);
					printf("\n\tAgendamento n�o foi cancelado\n\t");
					system("pause");
				}
				verificacaoValidez = 2;
				verificacaoValidez3 = 2;
			}else{
				fprintf(temporario,"%s\n%s\n%s\n%s\n%s\n%s\n%d %d %d %d %d\n%s\n%.2f\n", unidadeVerific, nomeVerific, rgVerific, cpfVerific, telefoneVerific, emailVerific, diaVerific, mesVerific, anoVerific, horaVerific, minutoVerific, nomeMedicoVerific, valorConsultaVerific);
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(agendamentos);
		fclose(temporario);
		
		int ret2 = remove(arquivoPermanenteAgendamentos);
		if(ret2 != 0){
			printf("\n\n\tArquivo n�o foi deletado corretamente!\n\n\t");
			perror("Error: ");
			system("pause");
		}
		int ret = rename(arquivoTemporarioAgendamentos, arquivoPermanenteAgendamentos);
		if(ret != 0){
			printf("\n\n\tArquivo n�o foi renomeado corretamente!\n\n\t");
			perror("Error: ");
			system("pause");
		}
		if(verificacaoValidez3 != 2){
			printf("\n\tDeseja procurar novamente? Se sim, digite 1, e se n�o, digite 2: ");
			scanf("%d", &verificacaoValidez);
			if(verificacaoValidez == 1){
				continue;
			}else{
				verificacaoValidez = 2;
				continue;
			}
		}		
		system("cls");
		printf("\n\tTELA DE CANCELAMENTO DE AGENDAMENTO");
		printf("\n\n\tDeseja cancelar outro agendamento? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);
	
}
