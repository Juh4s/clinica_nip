char arquivoTemporarioAvaliacoes[50]="Avaliacoes Novo.txt", arquivoPermanenteAvaliacoes[50]="Avaliacoes.txt";
char regAvaliacaoVerific[1000], regAvaliacao[1000];
int notaAvaliacao, notaAvaliacaoVerific;

void avaliacaoConsultar(){
	
	FILE *avaliacao;
	verificacaoValidez3 = 1;
	
	do{
		system("cls");
		printf("\n\tTELA DE CONSULTA DE AVALIAÇÃO");
		printf("\n\n\t[1] Consultar pela data");
		printf("\n\t[2] Consultar pelos dados do paciente");
		printf("\n\t[3] Cancelar consulta");
		printf("\n\tInsira o número correspondente à forma de busca que deseja (somente o número): ");
		scanf("%d", &menuEscolha);
		
		switch(menuEscolha){
			case 1: //busca pela data
				do{
					system("cls");
					printf("\n\tTELA DE CONSULTA DE AVALIAÇÃO");
					printf("\n\n\tInsira a unidade a qual essa avaliação pertence (A, B ou C): ");
					fflush(stdin);
					fgets(unidade, 10, stdin);
					unidade[strcspn (unidade, "\n\000")] = '\000';
					printf("\tInsira a data da avaliação:\n\tDia (EX: 8): ");
					scanf("%d", &dia);
					printf("\tMês (EX: 5): ");
					scanf("%d", &mes);
					printf("\tAno (EX: 2020): ");
					scanf("%d", &ano);
					
					system("cls");
					printf("\n\tTELA DE CONSULTA DE AVALIAÇÃO");
					avaliacao = fopen("Avaliacoes.txt","r");
					
					do{
						int t = fscanf(avaliacao," %[^\n] %[^\n] %[^\n] %d %[^\n] %d %d %d", unidadeVerific, nomeVerific, rgVerific, &notaAvaliacaoVerific, regAvaliacaoVerific, &diaVerific, &mesVerific, &anoVerific);
						if(t == EOF){	
							if(verificacaoValidez3 != 2){
								printf("\n\n\tAvaliação inserida não encontrada\n\t");
							}
							verificacaoValidez = 1;
						}else if(strcmp(unidade,unidadeVerific) == 0 && dia == diaVerific && mes == mesVerific && ano == anoVerific && hora == horaVerific && minuto == minutoVerific){
							printf("\n\n\tUnidade: %s", unidadeVerific);
							printf("\n\tNome do paciente: %s", nomeVerific);
							printf("\n\tRG do paciente: %s", rgVerific);
							printf("\n\tNota: %d", notaAvaliacaoVerific);
							printf("\n\tAvaliação registrada: %s", regAvaliacaoVerific);
							if(mesVerific >= 10 && diaVerific >= 10){
								printf("\n\tData da consulta: %d/%d/%d", diaVerific, mesVerific, anoVerific);
							}else if(mesVerific < 10 && diaVerific >= 10){
								printf("\n\tData da consulta: %d/0%d/%d", diaVerific, mesVerific, anoVerific);
							}else if(mesVerific < 10 && diaVerific < 10){
								printf("\n\tData da consulta: 0%d/0%d/%d", diaVerific, mesVerific, anoVerific);
							}else if(mesVerific >= 10 && diaVerific < 10){
								printf("\n\tData da consulta: 0%d/%d/%d", diaVerific, mesVerific, anoVerific);
							}
							
							verificacaoValidez = 2;
							verificacaoValidez3 = 2;
						}else{
							verificacaoValidez = 2;
						}
					}while(verificacaoValidez != 1);
					fclose(avaliacao);
					verificacaoValidez3 = 1;
					printf("\n\n\tDeseja consultar outra avaliação pela data? Se sim, digite 1, e se não, digite 2: ");
					scanf("%d", &verificacaoValidez);
				}while(verificacaoValidez == 1);
				break;
			case 2: //busca pelos dados do paciente
				do{
					system("cls");
					printf("\n\tTELA DE CONSULTA DE AVALIAÇÃO");
					printf("\n\n\tInsira a unidade a qual essa avaliação pertence (A, B ou C): ");
					fflush(stdin);
					fgets(unidade, 10, stdin);
					unidade[strcspn (unidade, "\n\000")] = '\000';
					printf("\tInsira o RG do paciente (EX: 00.000.000-0): ");
					fflush(stdin);
					fgets(rg, 20, stdin);
					if(strlen(rg) != 13){ //verifica se o RG tem 12 digitos (9 números e 3 separadores)
						printf("\tRG inválido, tente novamente\n\t");
						system("pause");
						continue;
					}
					rg[strcspn (rg, "\n\000")] = '\000';
					
					system("cls");
					printf("\n\tTELA DE CONSULTA DE AVALIAÇÃO");
					avaliacao = fopen("Avaliacoes.txt","r");
					do{
						int t = fscanf(avaliacao," %[^\n] %[^\n] %[^\n] %d %[^\n] %d %d %d", unidadeVerific, nomeVerific, rgVerific, &notaAvaliacaoVerific, regAvaliacaoVerific, &diaVerific, &mesVerific, &anoVerific);
						if(t == EOF){	
							if(verificacaoValidez3 != 2){
								printf("\n\n\tAvaliação inserida não encontrado.");
							}
							verificacaoValidez = 1;
						}else if(strcmp(unidade,unidadeVerific) == 0 && strcmp(rg,rgVerific) == 0){
							printf("\n\n\tUnidade: %s", unidadeVerific);
							printf("\n\tNome do paciente: %s", nomeVerific);
							printf("\n\tRG do paciente: %s", rgVerific);
							printf("\n\tNota: %d", notaAvaliacaoVerific);
							printf("\n\tAvaliação registrada: %s", regAvaliacaoVerific);
							if(mesVerific >= 10 && diaVerific >= 10){
								printf("\n\tData da consulta: %d/%d/%d", diaVerific, mesVerific, anoVerific);
							}else if(mesVerific < 10 && diaVerific >= 10){
								printf("\n\tData da consulta: %d/0%d/%d", diaVerific, mesVerific, anoVerific);
							}else if(mesVerific < 10 && diaVerific < 10){
								printf("\n\tData da consulta: 0%d/0%d/%d", diaVerific, mesVerific, anoVerific);
							}else if(mesVerific >= 10 && diaVerific < 10){
								printf("\n\tData da consulta: 0%d/%d/%d", diaVerific, mesVerific, anoVerific);
							}
							
							verificacaoValidez = 2;
							verificacaoValidez3 = 2;
						}else{
							verificacaoValidez = 2;
						}
					}while(verificacaoValidez != 1);
					fclose(avaliacao);
					verificacaoValidez3 = 1;
					printf("\n\n\tDeseja consultar outra avaliação pelos dados do paciente? Se sim, digite 1, e se não, digite 2: ");
					scanf("%d", &verificacaoValidez);
				}while(verificacaoValidez == 1);
				break;
			default:
				verificacaoValidez = 2;
				continue;
		}
		
		system("cls");
		printf("\n\tTELA DE CONSULTA DE AVALIAÇÃO");
		printf("\n\n\tDeseja consultar outra avaliação? Se sim, digite 1, e se não, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);
	
}

void avaliacaoCriar(){

	FILE *avaliacao;
	
	do{    	
		system("cls");
		
		printf("\n\tTELA DE REGISTRO DE AVALIAÇÃO");
		printf("\n\n\tInsira a unidade a qual essa avaliação pertence (A, B ou C): ");
		fflush(stdin); //limpa o input para evitar erros
		fgets(unidade, 10, stdin); //recebe input do usuário
		unidade[strcspn (unidade, "\n\000")] = '\000'; //remove o \n da informação inserida pelo usuário, afim de comparar essa informação inserida com a informação lida do arquivo corretamente
		if(strcmp(unidade,unidadeA) != 0 && strcmp(unidade,unidadeB) != 0 && strcmp(unidade,unidadeC) != 0){ //verifica se a unidade inserida é A, B ou C, e se não for nenhuma das 3, retorna um erro e reseta a tela
			printf("\tUnidade inserida inválida/não existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tInsira o nome completo do paciente: ");
		fflush(stdin);
		fgets(nome, 100, stdin);
		printf("\tInsira o RG do paciente (EX: 00.000.000-0): ");
		fflush(stdin);
		fgets(rg, 20, stdin);
		if(strlen(rg) != 13){ //verifica se o CPF tem a quantidade de caracteres correta (11 numeros e 3 separadores)
			printf("\tRG inválido, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tInsira a nota do cliente (De 1 a 10): ");
		scanf("%d", &notaAvaliacao);
		if(notaAvaliacao <1 || notaAvaliacao >10){ //verifica se a nota é entre 1 e 10
			printf("\tNota inserida inválida, tente novamente\n\t");
			system("pause");
			continue;
		}		
		printf("\tO(A) cliente deseja registrar uma recomendação ou reclamação? Se sim, digite 1, e se não, digite 2: ");			
		scanf("%d", &verificacaoValidez);
		if(verificacaoValidez == 1){
			printf("\tInsira a opinião do cliente (até 1000 caracteres): ");
			fflush(stdin);
			fgets(regAvaliacao, 1000, stdin);
		}else{
			strcpy(regAvaliacao, "ND\n");
		}
		
  		system("cls");
		printf("\n\tTELA DE REGISTRO DE AVALIAÇÃO");
		printf("\n\n\tUnidade: %s", unidade);
		printf("\n\tNome do paciente: %s", nome);
		printf("\tRG: %s", rg);
		printf("\tNota: %d", notaAvaliacao);
		printf("\n\tAvaliação registrada: %s", regAvaliacao);
		if(tm.tm_mon + 1 >= 10 && tm.tm_mday >= 10){
			printf("\tData da avaliação: %d/%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
		}else if(tm.tm_mon + 1 < 10 && tm.tm_mday >= 10){
			printf("\tData da avaliação: %d/0%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
		}else if(tm.tm_mon + 1 < 10 && tm.tm_mday < 10){
			printf("\tData da avaliação: 0%d/0%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
		}else if(tm.tm_mon + 1 >= 10 && tm.tm_mday < 10){
			printf("\tData da avaliação: 0%d/%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
		}
		
		printf("\n\n\tDeseja manter este registro? Se sim, digite 1, e se não, digite 2: ");
		scanf("%d", &verificacaoValidez);
		if(verificacaoValidez == 1){
			avaliacao = fopen("Avaliacoes.txt","a");
			if((avaliacao=fopen("Avaliacoes.txt","a"))==NULL){
				puts("\n\n\tERRO: Não foi possível criar arquivo com avaliações/Arquivo de avaliações não encontrado!");
				printf("\t");
				system("pause");
				continue;
			}
			fprintf(avaliacao,"%s\n%s%s%d\n%s%d %d %d\n", unidade, nome, rg, notaAvaliacao, regAvaliacao, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
			fclose(avaliacao);
		}
		
		system("cls");
		printf("\n\tTELA DE REGISTRO DE AVALIAÇÃO");
		printf("\n\n\tDeseja cadastrar outra avaliação? Se sim, digite 1, e se não, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);	
		
}

void avaliacaoExcluir(){

	FILE *avaliacao;
	FILE *temporario;
	verificacaoValidez3 = 1;
	  		
  	do{
		system("cls");
		printf("\n\tTELA DE EXCLUSÃO DE AVALIAÇÃO");
		printf("\n\n\tInsira a unidade a qual essa avaliação pertence (A, B ou C): ");
		fflush(stdin);
		fgets(unidade, 10, stdin);
		unidade[strcspn (unidade, "\n\000")] = '\000';
		printf("\tInsira o RG do paciente (EX: 00.000.000-0): ");
		fflush(stdin);
		fgets(rg, 20, stdin);
		rg[strcspn (rg, "\n\000")] = '\000';
		printf("\tInsira a data da avaliação:\n\tDia (EX: 8): ");
		scanf("%d", &dia);
		printf("\tMês (EX: 5): ");
		scanf("%d", &mes);
		printf("\tAno (EX: 2020): ");
		scanf("%d", &ano);
		
		system("cls");
		avaliacao = fopen("Avaliacoes.txt","r"); //verificação se o horário inserido está disponível
		temporario = fopen("Avaliacoes Novo.txt","w+");
		
		do{
			int t = fscanf(avaliacao," %[^\n] %[^\n] %[^\n] %d %[^\n] %d %d %d", unidadeVerific, nomeVerific, rgVerific, &notaAvaliacaoVerific, regAvaliacaoVerific, &diaVerific, &mesVerific, &anoVerific);
			if(t == EOF){
				if(verificacaoValidez3 != 2){
					printf("\n\tTELA DE EXCLUSÃO DE AVALIAÇÃO");
					printf("\n\n\tAvaliação inserida não encontrada\n\t");
				}
				verificacaoValidez = 1;
				break;
			}
			if(strcmp(unidade,unidadeVerific) == 0 && strcmp(rg,rgVerific) == 0 && dia == diaVerific && mes == mesVerific && ano == anoVerific){
				printf("\n\tTELA DE EXCLUSÃO DE AVALIAÇÃO");
				printf("\n\n\tUnidade: %s", unidadeVerific);
				printf("\n\tNome do paciente: %s", nomeVerific);
				printf("\n\tRG: %s", rgVerific);
				printf("\n\tNota: %d", notaAvaliacaoVerific);
				printf("\n\tAvaliação registrada: %s", regAvaliacaoVerific);
				if(mesVerific >= 10 && diaVerific >= 10){
					printf("\n\tData da avaliação: %d/%d/%d", diaVerific, mesVerific, anoVerific);
				}else if(mesVerific < 10 && diaVerific >= 10){
					printf("\n\tData da avaliação: %d/0%d/%d", diaVerific, mesVerific, anoVerific);
				}else if(mesVerific < 10 && diaVerific < 10){
					printf("\n\tData da avaliação: 0%d/0%d/%d", diaVerific, mesVerific, anoVerific);
				}else if(mesVerific >= 10 && diaVerific < 10){
					printf("\n\tData da avaliação: 0%d/%d/%d", diaVerific, mesVerific, anoVerific);
				}
		
				printf("\n\n\tTem certeza que deseja excluir essa avaliação? Se sim, digite 1, e se não, digite 2: ");
				scanf("%d", &verificacaoValidez);
				
				if(verificacaoValidez == 1){
					printf("\n\tAvaliação excluída com sucesso\n\t");
					system("pause");
				}else if(verificacaoValidez == 2){
					fprintf(temporario,"%s\n%s\n%s\n%d\n%s\n%d %d %d\n", unidadeVerific, nomeVerific, rgVerific, notaAvaliacaoVerific, regAvaliacaoVerific, diaVerific, mesVerific, anoVerific);
					printf("\n\tAvaliação não foi excluída\n\t");
					system("pause");
				}
				verificacaoValidez = 2;
				verificacaoValidez3 = 2;
			}else{
				fprintf(temporario,"%s\n%s\n%s\n%d\n%s\n%d %d %d\n", unidadeVerific, nomeVerific, rgVerific, notaAvaliacaoVerific, regAvaliacaoVerific, diaVerific, mesVerific, anoVerific);
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(avaliacao);
		fclose(temporario);
		
		int ret2 = remove(arquivoPermanenteAvaliacoes);
		if(ret2 != 0){
			printf("\n\n\tArquivo não foi deletado corretamente!\n\n\t");
			perror("Error: ");
			system("pause");
		}
		int ret = rename(arquivoTemporarioAvaliacoes, arquivoPermanenteAvaliacoes);
		if(ret != 0){
			printf("\n\n\tArquivo não foi renomeado corretamente!\n\n\t");
			perror("Error: ");
			system("pause");
		}
		if(verificacaoValidez3 != 2){
			printf("\n\tDeseja procurar novamente? Se sim, digite 1, e se não, digite 2: ");
			scanf("%d", &verificacaoValidez);
			if(verificacaoValidez == 1){
				continue;
			}else{
				verificacaoValidez = 2;
				continue;
			}
		}
		
		system("cls");
		printf("\n\tTELA DE EXCLUSÃO DE AVALIAÇÃO");
		printf("\n\n\tDeseja excluir outra avaliação? Se sim, digite 1, e se não, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);		
	
}
