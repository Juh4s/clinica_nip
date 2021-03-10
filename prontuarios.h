char alergiasVerific[1000], evolucaoVerific[1000], medicamentosVerific[1000], arquivoTemporarioProntuario[50]="Prontuarios Novo.txt", arquivoPermanenteProntuario[50]="Prontuarios.txt";
char alergias[1000], evolucao[1000], medicamentos[1000];

void prontuarioAbrir(){
	
	FILE *prontuarios;
	verificacaoValidez3 = 1;
	
	do{
		system("cls");
		printf("\n\tTELA DE BUSCA DE PRONTU�RIO");
		printf("\n\n\tInsira o RG do paciente (EX: 00.000.000-0): ");
		fflush(stdin);
		fgets(rg, 20, stdin);
		rg[strcspn(rg, "\n\000")] = '\000';
			
		system("cls");
		printf("\n\tTELA DE BUSCA DE PRONTU�RIO");
		
		prontuarios = fopen("Prontuarios.txt","r");
		do{
			int t = fscanf(prontuarios," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n]", nomeVerific, generoVerific, rgVerific, cpfVerific, religiaoVerific, alergiasVerific, evolucaoVerific, medicamentosVerific);
			if(t == EOF){ 
				if(verificacaoValidez3 != 2){
					printf("\n\n\tProntu�rio n�o encontrada");
				}
				verificacaoValidez = 1;
				break;
			}else{
				verificacaoValidez = 2;
			}
			if(strcmp(rg,rgVerific) == 0){
				printf("\n\n\tNome do paciente: %s", nomeVerific);
				printf("\n\tG�nero: %s", generoVerific);
				printf("\n\tRG: %s", rgVerific);
				printf("\n\tCPF: %s", cpfVerific);
				printf("\n\tReligi�o: %s", religiaoVerific);
				printf("\n\tAlergias: %s", alergiasVerific);
				printf("\n\tEvolu��o: %s", evolucaoVerific);
				printf("\n\tMedicamentos: %s", medicamentosVerific);
				verificacaoValidez = 2;
				verificacaoValidez3 = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(prontuarios);
		verificacaoValidez3 = 1;
			
		printf("\n\n\t");
		system("pause");
		system("cls");
		printf("\n\tTELA DE BUSCA DE PRONTU�RIO");
		printf("\n\n\tDeseja abrir outro prontu�rio? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);
}

void prontuarioCriar(){
	
	FILE *prontuarios;
	
	do{
    	system("cls");
		printf("\n\tTELA DE CRIA��O DE PRONTU�RIO");
		printf("\n\n\tInsira o nome do paciente: ");
		fflush(stdin);
		fgets(nome, 200, stdin);
		printf("\tInsira o g�nero do paciente (M, F ou ND): ");
		fflush(stdin);
		fgets(genero, 10, stdin);
		genero[strcspn (genero, "\n\000")] = '\000';
		if(strcmp(genero,generoM) != 0 && strcmp(genero,generoF) != 0 && strcmp(genero,generoND) != 0){
			printf("\tG�nero inserido inv�lido, tente novamente");
			system("pause");
			continue;
		}
		printf("\tInsira o RG do paciente (EX: 00.000.000-0): ");
		fflush(stdin);
		fgets(rg, 20, stdin);
		if(strlen(rg) != 13){
			printf("\tRG inv�lido, tente novamente\n\t");
			system("pause");
			continue;
		}
  		printf("\tInsira o CPF do paciente (EX: 000.000.000-00): ");
		fflush(stdin);
		fgets(cpf, 20, stdin);
		if(strlen(cpf) != 15){
			printf("\tCPF inv�lido, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tInsira a religi�o do paciente: ");
		fflush(stdin);
		fgets(religiao, 100, stdin);
		printf("\tInsira as alergias do paciente: ");
		fflush(stdin);
		fgets(alergias, 1000, stdin);
		printf("\tInsira a evolu��o m�dica do paciente: ");
		fflush(stdin);
		fgets(evolucao, 1000, stdin);
		printf("\tInsira os medicamentos que o paciente toma: ");
		fflush(stdin);
		fgets(medicamentos, 1000, stdin);
		
		system("cls");
		printf("\n\tTELA DE CRIA��O DE PRONTU�RIO");
		printf("\n\n\tNome do paciente: %s", nome);
		printf("\tG�nero: %s", genero);
		printf("\n\tRG: %s", rg);
		printf("\tCPF: %s", cpf);
		printf("\tReligi�o: %s", religiao);
		printf("\tAlergias: %s", alergias);
		printf("\tEvolu��o: %s", evolucao);
		printf("\tMedicamentos: %s", medicamentos);
		
		printf("\n\tDeseja salvar esse prontu�rio? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
		
		if(verificacaoValidez == 1){
			prontuarios = fopen("Prontuarios.txt","a");
			if((prontuarios=fopen("Prontuarios.txt","a"))==NULL){
				puts("\n\n\tERRO: Arquivo de prontu�rios n�o encontrado/n�o foi poss�vel criar arquivo de prontu�rios");
				printf("\t");
				system("pause");
				continue;
			}
			fprintf(prontuarios,"%s%s\n%s%s%s%s%s%s", nome, genero, rg, cpf, religiao, alergias, evolucao, medicamentos);
			fclose(prontuarios);
		}
		
		system("cls");
		printf("\n\tTELA DE CRIA��O DE PRONTU�RIO");
		printf("\n\n\tDeseja criar outro prontu�rio? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);
}

void prontuarioEditar(){
	
	FILE *prontuarios;
	FILE *temporario;
	verificacaoValidez3 = 1;
	
	do{
    	system("cls");
		printf("\n\tTELA DE EDI��O DE PRONTU�RIO");
		printf("\n\n\tInsira o RG do paciente (EX: 00.000.000-0): ");
		fflush(stdin);
		fgets(rg, 20, stdin);
		rg[strcspn (rg, "\n\000")] = '\000';
		
		system("cls");
		prontuarios = fopen("Prontuarios.txt","r");
		temporario = fopen("Prontuarios Novo.txt","w+");
		
		do{
			int t = fscanf(prontuarios,"  %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n]", nomeVerific, generoVerific, rgVerific, cpfVerific, religiaoVerific, alergiasVerific, evolucaoVerific, medicamentosVerific);
			if(t == EOF){
				if(verificacaoValidez3 != 2){
					printf("\n\tTELA DE EDI��O DE PRONTU�RIO");
					printf("\n\n\tProntu�rio n�o encontrado\n\t");
				}
				verificacaoValidez = 1;
				break;
			}
			if(strcmp(rg,rgVerific) == 0){
				printf("\n\tTELA DE EDI��O DE PRONTU�RIOS");
				printf("\n\n\tNome do paciente: %s", nomeVerific);
				printf("\n\tG�nero: %s", generoVerific);
				printf("\n\tRG: %s", rgVerific);
				printf("\n\tCPF: %s", cpfVerific);
				printf("\n\tReligi�o: %s", religiaoVerific);
				printf("\n\tAlergias: %s", alergiasVerific);
				printf("\n\tEvolu��o: %s", evolucaoVerific);
				printf("\n\tMedicamentos: %s", medicamentosVerific);
		
				printf("\n\n\tTem certeza que deseja editar esse prontu�rio? Se sim, digite 1, e se n�o, digite 2: ");
				scanf("%d", &verificacaoValidez);
				
				if(verificacaoValidez == 1){
					do{
						system("cls");
						printf("\n\tTELA DE EDI��O DE PRONTU�RIO");
						printf("\n\tDeseja editar o nome do paciente? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){			
							printf("\tInsira o nome completo do paciente: ");
							fflush(stdin);
							fgets(nomeVerific, 200, stdin);
							nomeVerific[strcspn (nomeVerific, "\n\000")] = '\000';
						}
						printf("\n\tDeseja editar o g�nero do paciente? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){	
							printf("\tInsira o g�nero do paciente (M, F ou ND): ");
							fflush(stdin);
							fgets(generoVerific, 10, stdin);
							generoVerific[strcspn (generoVerific, "\n\000")] = '\000';
							if(strcmp(generoVerific,generoM) != 0 && strcmp(generoVerific,generoF) != 0 && strcmp(generoVerific,generoND) != 0){
								printf("\tG�nero inserido inv�lido, tente novamente\n\t");
								system("pause");
								continue;
							}
						}
						printf("\n\tDeseja editar o RG do paciente? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira o RG do paciente (EX: 00.000.000-0): ");
							fflush(stdin);
							fgets(rgVerific, 20, stdin);
							if(strlen(rgVerific) != 13){
								printf("\tRG inv�lido, tente novamente\n\t");
								system("pause");
								continue;
							}
							rgVerific[strcspn (rgVerific, "\n\000")] = '\000';
						}
						printf("\n\tDeseja editar o CPF do paciente? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){			
							printf("\tInsira o cpf do paciente (EX: 000.000.000-00): ");
							fflush(stdin);
							fgets(cpfVerific, 20, stdin);
							if(strlen(cpfVerific) != 15){
								printf("\tCPF inv�lido, tente novamente\n\t");
								system("pause");
								continue;	
							}
							cpfVerific[strcspn (cpfVerific, "\n")] = '\000';
						}
						printf("\n\tDeseja editar a religi�o do paciente? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){			
							printf("\tInsira a religi�o do paciente: ");
							fflush(stdin);
							fgets(religiaoVerific, 100, stdin);
							religiaoVerific[strcspn (religiaoVerific, "\n")] = '\000';
						}
						printf("\n\tDeseja editar as alergias do paciente? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){			
							printf("\tInsira as alergias do paciente: ");
							fflush(stdin);
							fgets(alergiasVerific, 1000, stdin);
							alergiasVerific[strcspn (alergiasVerific, "\n")] = '\000';
						}
						printf("\n\tDeseja editar a evolu��o m�dica do paciente? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){			
							printf("\tInsira a evolu��o m�dica do paciente: ");
							fflush(stdin);
							fgets(evolucaoVerific, 1000, stdin);
							evolucaoVerific[strcspn (evolucaoVerific, "\n")] = '\000';
						}
						printf("\n\tDeseja editar os medicamentos que o paciente toma? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){			
							printf("\tInsira os medicamentos que o paciente toma: ");
							fflush(stdin);
							fgets(medicamentosVerific, 1000, stdin);
							medicamentosVerific[strcspn (medicamentosVerific, "\n")] = '\000';
						}
						
						printf("\n\tSe deseja reiniciar o menu de edi��o (cancelando as edi��es feitas at� agora), digite 1.\n\tSe deseja sair da tela de edi��o (salvando as edi��es realizadas OU cancelando a edi��o, caso nada tenha sido editado), digite 2. ");
						printf("\n\tInsira a sua escolha: ");
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 2){
							fprintf(temporario,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", nomeVerific, generoVerific,rgVerific, cpfVerific, religiaoVerific, alergiasVerific, evolucaoVerific, medicamentosVerific);
							printf("\n\tEdi��o conclu�da\n\t");
							system("pause");
						}
					}while(verificacaoValidez == 1);
				}else if(verificacaoValidez == 2){
					fprintf(temporario,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", nomeVerific, generoVerific, rgVerific, cpfVerific, religiaoVerific, alergiasVerific, evolucaoVerific, medicamentosVerific);
					printf("\n\tEdi��o cancelada\n\t");
					system("pause");
				}
				verificacaoValidez = 2;
				verificacaoValidez3 = 2;
			}else{
				fprintf(temporario,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", nomeVerific, generoVerific,rgVerific, cpfVerific, religiaoVerific, alergiasVerific, evolucaoVerific, medicamentosVerific);
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(prontuarios);
		fclose(temporario);
		
		int ret2 = remove(arquivoPermanenteProntuario);
		if(ret2 != 0){
			printf("\n\n\tArquivo n�o foi deletado corretamente!\n\n\t");
			perror("Error: ");
			system("pause");
		}
		int ret = rename(arquivoTemporarioProntuario, arquivoPermanenteProntuario);
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
		printf("\n\tTELA DE EDI��O DE PRONTU�RIOS");
		printf("\n\n\tDeseja editar outro prontu�rio? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);
}

void prontuarioExcluir(){
	
	FILE *prontuarios;
	FILE *temporario;
	verificacaoValidez3 = 1;
	
	do{
    	system("cls");
		printf("\n\tTELA DE EXCLUS�O DE PRONTU�RIOS");
		printf("\n\n\tInsira o RG do paciente (EX: 00.000.000-0): ");
		fflush(stdin);
		fgets(rg, 20, stdin);
		rg[strcspn (rg, "\n\000")] = '\000';
		
		system("cls");
		prontuarios = fopen("Prontuarios.txt","r");
		temporario = fopen("Prontuarios Novo.txt","w+");
		
		do{
			int t = fscanf(prontuarios,"  %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n]", nomeVerific, generoVerific,rgVerific, cpfVerific, religiaoVerific, alergiasVerific, evolucaoVerific, medicamentosVerific);
			if(t == EOF){
				if(verificacaoValidez3 != 2){
					printf("\n\tTELA DE EXCLUS�O DE PRONTU�RIOS");
					printf("\n\n\tProntu�rio n�o encontrado");
				}
				verificacaoValidez = 1;
				break;
			}
			if(strcmp(rg,rgVerific) == 0){
				printf("\n\tTELA DE EXCLUS�O DE PRONTU�RIOS");
				printf("\n\n\tNome: %s", nomeVerific);
				printf("\n\tG�nero: %s", generoVerific);
				printf("\n\tRG: %s", rgVerific);
				printf("\n\tCPF: %s", cpfVerific);
				printf("\n\tReligi�o: %s", religiaoVerific);
				printf("\n\tAlergias: %s", alergiasVerific);
				printf("\n\tEvolu��o: %s", evolucaoVerific);
				printf("\n\tMedicamentos: %s", medicamentosVerific);
		
				printf("\n\n\tTem certeza que deseja excluir esse prontu�rio? Se sim, digite 1, e se n�o, digite 2: ");
				scanf("%d", &verificacaoValidez);
				
				if(verificacaoValidez == 1){
					printf("\n\tProntu�rio exclu�do com sucesso\n\t");
					system("pause");
				}else if(verificacaoValidez == 2){
					fprintf(temporario,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", nomeVerific, generoVerific, rgVerific, cpfVerific, religiaoVerific, alergiasVerific, evolucaoVerific, medicamentosVerific);
					printf("\n\tProntu�rio n�o foi exclu�do\n\t");
					system("pause");
				}
				verificacaoValidez = 2;
				verificacaoValidez3 = 2;
			}else{
				fprintf(temporario,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", nomeVerific, generoVerific, rgVerific, cpfVerific, religiaoVerific, alergiasVerific, evolucaoVerific, medicamentosVerific);
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(prontuarios);
		fclose(temporario);
		
		int ret2 = remove(arquivoPermanenteProntuario);
		if(ret2 != 0){
			printf("\n\n\tArquivo n�o foi deletado corretamente!\n\n\t");
			perror("Error: ");
			system("pause");
		}
		int ret = rename(arquivoTemporarioProntuario, arquivoPermanenteProntuario);
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
		printf("\n\tTELA DE EXCLUS�O DE PRONTU�RIOS");
		printf("\n\n\tDeseja excluir outro prontu�rio? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);
}
