char nomeGasto[100], religiaoVerific[100], nomeGastoVerific[100], login[30], senha[30], loginSalvo[30], senhaSalva[30];
char arquivoTemporarioCadastroPaciente[50]="Pacientes Novo.txt", arquivoPermanenteCadastroPaciente[50]="Pacientes.txt", arquivoTemporarioCadastroFuncionario[50]="Funcionarios Novo.txt", arquivoPermanenteCadastroFuncionario[50]="Funcionarios.txt", arquivoTemporarioContas[50]="Contas Novo.txt", arquivoPermanenteContas[50]="Contas.txt",  arquivoTemporarioGastos[50]="Gastos Novo.txt", arquivoPermanenteGastos[50]="Gastos.txt";
float valorGasto, valorGastoVerific;

void cadastroPacienteConsultar(){
	
	FILE *pacientes;
	verificacaoValidez3 = 1;
	
	do{
		system("cls");
		printf("\n\tTELA DE CONSULTA DE CADASTRO DE PACIENTE");
		printf("\n\n\t[1] Consultar pelo nome");
		printf("\n\t[2] Consultar pelo RG");
		printf("\n\t[3] Cancelar consulta");
		printf("\n\tInsira o n�mero correspondente � forma de busca que deseja (somente o n�mero): ");
		scanf("%d", &menuEscolha);
		
		switch(menuEscolha){
			case 1:
				do{
					system("cls");
					printf("\n\tTELA DE CONSULTA DE CADASTRO DE PACIENTE");
					printf("\n\n\tInsira o nome do paciente: ");
					fflush(stdin);
					fgets(nome, 200, stdin);
					nome[strcspn (nome, "\n\000")] = '\000';
											
					system("cls");
					printf("\n\tTELA DE CONSULTA DE CADASTRO DE PACIENTE");
					pacientes = fopen("Pacientes.txt","r");
					do{
						int t = fscanf(pacientes," %[^\n] %[^\n] %[^\n] %[^\n] %d %[^\n] %[^\n] %[^\n] %d %[^\n] %d %[^\n] %[^\n] %[^\n]", nomeVerific, generoVerific, rgVerific, cpfVerific, &idadeVerific, ufVerific, cidadeVerific, enderecoVerific, &numeroVerific, casaOuPredioVerific, &apartamentoVerific, cepVerific, telefoneVerific, religiaoVerific);
						if(t == EOF){	
							if(verificacaoValidez3 != 2){
								printf("\n\n\tCadastro inserido n�o encontrado.");
							}
							verificacaoValidez = 1;
						}else if(strcmp(nome,nomeVerific) == 0){
							printf("\n\n\tNome do paciente: %s", nomeVerific);
							printf("\n\tGenero: %s", generoVerific);
							printf("\n\tRG: %s", rgVerific);
							printf("\n\tCPF: %s", cpfVerific);
							printf("\n\tIdade: %d", idadeVerific);
							printf("\n\tEstado: %s", ufVerific);
							printf("\n\tCidade: %s", cidadeVerific);
							printf("\n\tEndere�o: %s", enderecoVerific);
							printf("\n\tN�mero: %d", numeroVerific);
							printf("\n\tTipo de resid�ncia: %s", casaOuPredioVerific);
							if(strcmp(casaOuPredioVerific, predio) == 0){
								printf("\n\tApartamento: %d", apartamentoVerific);
							}
							printf("\n\tCEP: %s", cepVerific);
							printf("\n\tTelefone: %s", telefoneVerific);
							printf("\n\tReligi�o: %s", religiaoVerific);
							verificacaoValidez = 2;
							verificacaoValidez3 = 2;
						}else{
							verificacaoValidez = 2;
						}
					}while(verificacaoValidez != 1);
					fclose(pacientes);
					verificacaoValidez3 = 1;
					printf("\n\n\tDeseja consultar outro cadastro pelo nome? Se sim, digite 1, e se n�o, digite 2: ");
					scanf("%d", &verificacaoValidez);
				}while(verificacaoValidez == 1);
				break;
			case 2:
				do{
					system("cls");
					printf("\n\tTELA DE CONSULTA DE CADASTRO DE PACIENTE");
					printf("\n\n\tInsira o RG do paciente (EX: 00.000.000-0): ");
					fflush(stdin);
					fgets(rg, 20, stdin);
					rg[strcspn (rg, "\n\000")] = '\000';
											
					system("cls");
					printf("\n\tTELA DE CONSULTA DE CADASTRO DE PACIENTE");
					pacientes = fopen("Pacientes.txt","r");
					do{
						int t = fscanf(pacientes," %[^\n] %[^\n] %[^\n] %[^\n] %d %[^\n] %[^\n] %[^\n] %d %[^\n] %d %[^\n] %[^\n] %[^\n]", nomeVerific, generoVerific, rgVerific, cpfVerific, &idadeVerific, ufVerific, cidadeVerific, enderecoVerific, &numeroVerific, casaOuPredioVerific, &apartamentoVerific, cepVerific, telefoneVerific, religiaoVerific);
						if(t == EOF){	
							if(verificacaoValidez3 != 2){
								printf("\n\n\tCadastro inserido n�o encontrado.");
							}
							verificacaoValidez = 1;
						}else if(strcmp(rg,rgVerific) == 0){
							printf("\n\n\tNome do paciente: %s", nomeVerific);
							printf("\n\tGenero: %s", generoVerific);
							printf("\n\tRG: %s", rgVerific);
							printf("\n\tCPF: %s", cpfVerific);
							printf("\n\tIdade: %d", idadeVerific);
							printf("\n\tEstado: %s", ufVerific);
							printf("\n\tCidade: %s", cidadeVerific);
							printf("\n\tEndere�o: %s", enderecoVerific);
							printf("\n\tN�mero: %d", numeroVerific);
							printf("\n\tTipo de resid�ncia: %s", casaOuPredioVerific);
							if(strcmp(casaOuPredioVerific, predio) == 0){
								printf("\n\tApartamento: %d", apartamentoVerific);
							}
							printf("\n\tCEP: %s", cepVerific);
							printf("\n\tTelefone: %s", telefoneVerific);
							printf("\n\tReligi�o: %s", religiaoVerific);
							verificacaoValidez = 2;
							verificacaoValidez3 = 2;
						}else{
							verificacaoValidez = 2;
						}
					}while(verificacaoValidez != 1);
					fclose(pacientes);
					verificacaoValidez3 = 1;
					printf("\n\n\tDeseja consultar outro cadastro pelo RG? Se sim, digite 1, e se n�o, digite 2: ");
					scanf("%d", &verificacaoValidez);
				}while(verificacaoValidez == 1);
				break;
			default:
				verificacaoValidez = 2;
				continue;
		}
		
		system("cls");
		printf("\n\tTELA DE CONSULTA DE CADASTRO DE PACIENTE");
		printf("\n\n\tDeseja consultar outro cadastro? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);
}

void cadastroPaciente(){

	FILE *pacientes;
  		
  	do{
		system("cls");
		printf("\n\tTELA DE CADASTRO DE PACIENTES");
		printf("\n\n\tInsira o nome completo do paciente: ");
		fflush(stdin);
		fgets(nome, 200, stdin);
		printf("\tInsira o g�nero do paciente (M, F ou ND): ");
		fflush(stdin);
		fgets(genero, 10, stdin);
		genero[strcspn (genero, "\n\000")] = '\000';
		if(strcmp(genero,generoM) != 0 && strcmp(genero,generoF) != 0 && strcmp(genero,generoND) != 0){
			printf("\tG�nero inserido inv�lido, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tInsira o RG (EX: 00.000.000-0): ");
		fflush(stdin);
		fgets(rg, 20, stdin);
		if(strlen(rg) != 13){ //verifica se o RG tem 12 digitos (9 n�meros e 3 separadores)
			printf("\tRG inv�lido, tente novamente\n\t");
			system("pause");
			continue;
		}			
		printf("\tInsira o CPF (EX: 000.000.000-00): ");
		fflush(stdin);
		fgets(cpf, 20, stdin);
		if(strlen(cpf) != 15){
			printf("\tCPF inv�lido, tente novamente\n\t");
			system("pause");
			continue;	
		}	
		printf("\tInsira a idade: ");
		scanf("%d", &idade);
		printf("\tInsira o Estado (EX: SP): ");
		fflush(stdin);
		fgets(uf, 10, stdin);
		if(strlen(uf) != 3){
			printf("\tEstado inv�lido, tente novamente\n\t");
			system("pause");
			continue;
		}		
		printf("\tInsira a cidade: ");
		fflush(stdin);
		fgets(cidade, 100, stdin);
		printf("\tInsira o endere�o (somente nome da rua): ");
		fflush(stdin);
		fgets(endereco, 100, stdin);			
		printf("\tInsira o n�mero: ");
		scanf("%d", &numero);
		printf("\tTipo de resid�ncia (Insira Casa ou Predio): ");
		fflush(stdin);
		fgets(casaOuPredio, 10, stdin);
		casaOuPredio[strcspn (casaOuPredio, "\n")] = '\000'; //remove o \n da informa��o inserida pelo usu�rio, afim de comparar essa informa��o inserida com outra informa��o corretamente
		if(strcmp(casaOuPredio, casa) != 0 && strcmp(casaOuPredio, predio) != 0){
			printf("\tInforma��o inv�lida, tente novamente\n\t");
			system("pause");
			continue;
		}
		if(strcmp(casaOuPredio, predio) == 0){
			printf("\tInsira o n�mero do apartamento: ");
			scanf("%d", &apartamento);
		}else{
			apartamento = 0;
		}	
		printf("\tInsira o CEP(Ex:00000-000): ");
		fflush(stdin);
		fgets(cep, 20, stdin);
		if(strlen(cep) != 10){
			printf("\tCPF inv�lido, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tInsira o tefelone do paciente (EX: (11)93535-0202): ");
		fflush(stdin);
		fgets(telefone, 20, stdin);
		if(strlen(telefone) != 14 && strlen(telefone) != 15){ 
			printf("\tTelefone inv�lido, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tInsira a religi�o do paciente: ");
		fflush(stdin);
		fgets(religiao, 100, stdin);
		
		system("cls");
		printf("\n\tTELA DE CADASTRO DE PACIENTES");
		printf("\n\n\tNome do paciente: %s", nome);
		printf("\tGenero: %s", genero);
		printf("\n\tRG: %s", rg);
		printf("\tCPF: %s", cpf);
		printf("\tIdade: %d", idade);
		printf("\n\tEstado: %s", uf);
		printf("\tCidade: %s", cidade);
		printf("\tEndere�o: %s", endereco);
		printf("\tN�mero: %d", numero);
		printf("\n\tTipo de resid�ncia: %s", casaOuPredio);
		if(strcmp(casaOuPredio, predio) == 0){
			printf("\n\tApartamento: %d", apartamento);
		}
		printf("\n\tCEP: %s", cep);
		printf("\tTelefone: %s", telefone);
		printf("\tReligi�o: %s", religiao);
		printf("\n\tDeseja manter este cadastro? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	
		if(verificacaoValidez == 1){
			pacientes = fopen("Pacientes.txt","a");
			if((pacientes=fopen("Pacientes.txt","a"))==NULL){
				puts("\n\n\tERRO: N�o foi poss�vel criar arquivo com pacientes/Arquivo de pacientes n�o encontrado!");
				printf("\t");
				system("pause");
				continue;
			}
			fprintf(pacientes,"%s%s\n%s%s%d\n%s%s%s%d\n%s\n%d\n%s%s%s", nome, genero, rg, cpf, idade, uf, cidade, endereco, numero, casaOuPredio, apartamento, cep, telefone, religiao);
			fclose(pacientes);
		}
		
		system("cls");
		printf("\n\tTELA DE CADASTRO DE PACIENTES");
		printf("\n\n\tDeseja cadastrar outro paciente? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);		
	
}

void cadastroPacienteEditar(){

	FILE *pacientes;
	FILE *temporario;
	verificacaoValidez3 = 1;
	
	do{
    	system("cls");
		printf("\n\tTELA DE EDI��O DE CADASTRO DE PACIENTE");
		printf("\n\n\tInsira o RG do paciente (EX: 00.000.000-0): ");
		fflush(stdin);
		fgets(rg, 20, stdin);
		rg[strcspn (rg, "\n\000")] = '\000';
		
		system("cls");
		pacientes = fopen("Pacientes.txt","r");
		temporario = fopen("Pacientes Novo.txt","w+");
		
		do{ //loop para leitura dos dados do arquivo Agendamentos.txt
			int t = fscanf(pacientes," %[^\n] %[^\n] %[^\n] %[^\n] %d %[^\n] %[^\n] %[^\n] %d %[^\n] %d %[^\n] %[^\n] %[^\n]", nomeVerific, generoVerific, rgVerific, cpfVerific, &idadeVerific, ufVerific, cidadeVerific, enderecoVerific, &numeroVerific, casaOuPredioVerific, &apartamentoVerific, cepVerific, telefoneVerific, religiaoVerific);
			if(t == EOF){
				if(verificacaoValidez3 != 2){
					printf("\n\tTELA DE EDI��O DE CADASTRO DE PACIENTE");
					printf("\n\n\tCadastro inserido n�o encontrado\n\t");
				}
				verificacaoValidez = 1;
				break;
			}
			if(strcmp(rg,rgVerific) == 0){
				printf("\n\tTELA DE EDI��O DE CADASTRO DE PACIENTE");
				printf("\n\n\tNome do paciente: %s", nomeVerific);
				printf("\n\tGenero: %s", generoVerific);
				printf("\n\tRG: %s", rgVerific);
				printf("\n\tCPF: %s", cpfVerific);
				printf("\n\tIdade: %d", idadeVerific);
				printf("\n\tEstado: %s", ufVerific);
				printf("\n\tCidade: %s", cidadeVerific);
				printf("\n\tEndere�o: %s", enderecoVerific);
				printf("\n\tN�mero: %d", numeroVerific);
				printf("\n\tTipo de resid�ncia: %s", casaOuPredioVerific);
				if(strcmp(casaOuPredioVerific, predio) == 0){
					printf("\n\tApartamento: %d", apartamentoVerific);
				}
				printf("\n\tCEP: %s", cepVerific);
				printf("\n\tTelefone: %s", telefoneVerific);
				printf("\n\tReligi�o: %s", religiaoVerific);
		
				printf("\n\n\tTem certeza que deseja editar esse cadastro? Se sim, digite 1, e se n�o, digite 2: ");
				scanf("%d", &verificacaoValidez);
				
				if(verificacaoValidez == 1){
					do{
						system("cls");
						printf("\n\tTELA DE EDI��O DE CADASTRO DE PACIENTE");
						printf("\n\n\tDeseja editar o nome? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira o nome do paciente: ");
							fflush(stdin);
							fgets(nomeVerific, 200, stdin);
							nomeVerific[strcspn (nomeVerific, "\n\000")] = '\000';
						}
						printf("\n\tDeseja editar o g�nero? Se sim, digite 1, e se n�o, digite 2: ");			
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
						printf("\n\tDeseja editar o RG? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira o RG (EX: 00.000.000-0): ");
							fflush(stdin);
							fgets(rgVerific, 20, stdin);
							if(strlen(rgVerific) != 13){ //verifica se o RG tem 12 digitos (9 n�meros e 3 separadores)
								printf("\tRG inv�lido, tente novamente\n\t");
								system("pause");
								continue;
							}
							rgVerific[strcspn (rgVerific, "\n\000")] = '\000';
						}
						printf("\n\tDeseja editar o CPF? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira o CPF (EX: 000.000.000-00): ");
							fflush(stdin);
							fgets(cpfVerific, 20, stdin);
							if(strlen(cpfVerific) != 15){
								printf("\tCPF inv�lido, tente novamente\n\t");
								system("pause");
								continue;	
							}
							cpfVerific[strcspn (cpfVerific, "\n\000")] = '\000';
						}
						printf("\n\tDeseja editar a idade? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira a idade: ");
							scanf("%d", &idadeVerific);
						}
						printf("\n\tDeseja editar o Estado? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira o Estado (EX: SP): ");
							fflush(stdin);
							fgets(ufVerific, 10, stdin);
							ufVerific[strcspn (ufVerific, "\n\000")] = '\000';
							if(strlen(ufVerific) != 2){
								printf("\tCPF inv�lido, tente novamente\n\t");
								system("pause");
								continue;	
							}
						}
						printf("\n\tDeseja editar a cidade? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira a cidade: ");
							fflush(stdin);
							fgets(cidadeVerific, 100, stdin);
							cidadeVerific[strcspn (cidadeVerific, "\n\000")] = '\000';
						}
						printf("\n\tDeseja editar o endere�o? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira o endere�o (somente nome da rua): ");
							fflush(stdin);
							fgets(enderecoVerific, 100, stdin);
							enderecoVerific[strcspn (enderecoVerific, "\n\000")] = '\000';
							printf("\tInsira o n�mero: ");
							scanf("%d", &numeroVerific);
							printf("\tTipo de resid�ncia (Insira Casa ou Predio): ");
							fflush(stdin);
							fgets(casaOuPredioVerific, 10, stdin);
							casaOuPredioVerific[strcspn (casaOuPredioVerific, "\n")] = '\000'; //remove o \n da informa��o inserida pelo usu�rio, afim de comparar essa informa��o inserida com outra informa��o corretamente
							if(strcmp(casaOuPredioVerific, casa) != 0 && strcmp(casaOuPredioVerific, predio) != 0){
								printf("\tInforma��o inv�lida, tente novamente\n\t");
								system("pause");
								continue;
							}
							if(strcmp(casaOuPredioVerific, predio) == 0){
								printf("\tInsira o n�mero do apartamento: ");
								scanf("%d", &apartamentoVerific);
							}else{
								apartamentoVerific = 0;
							}	
							printf("\tInsira o CEP(Ex:00000-000): ");
							fflush(stdin);
							fgets(cepVerific, 20, stdin);
							if(strlen(cepVerific) != 10){
								printf("\tCPF inv�lido, tente novamente\n\t");
								system("pause");
								continue;
							}
							cepVerific[strcspn (cepVerific, "\n\000")] = '\000';
						}
						printf("\n\tDeseja editar o telefone? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira o tefelone do paciente (EX: (11)93535-0202): ");
							fflush(stdin);
							fgets(telefoneVerific, 20, stdin);
							if(strlen(telefoneVerific) != 14 && strlen(telefoneVerific) != 15){ 
								printf("\tTelefone inv�lido, tente novamente\n\t");
								system("pause");
								continue;
							}
							telefoneVerific[strcspn (telefoneVerific, "\n\000")] = '\000';
						}
						printf("\n\tDeseja editar a religi�o? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira a religi�o do paciente: ");
							fflush(stdin);
							fgets(religiaoVerific, 100, stdin);
							religiaoVerific[strcspn (religiaoVerific, "\n\000")] = '\000';
						}
						
						printf("\n\tSe deseja reiniciar o menu de edi��o (cancelando as edi��es feitas at� agora), digite 1.\n\tSe deseja sair da tela de edi��o (salvando as edi��es realizadas OU cancelando a edi��o, caso nada tenha sido editado), digite 2. ");
						printf("\n\tInsira a sua escolha: ");
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 2){
							fprintf(temporario,"%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n%d\n%s\n%d\n%s\n%s\n%s\n", nomeVerific, generoVerific, rgVerific, cpfVerific, idadeVerific, ufVerific, cidadeVerific, enderecoVerific, numeroVerific, casaOuPredioVerific, apartamentoVerific, cepVerific, telefoneVerific, religiaoVerific);
							printf("\n\tEdi��o conclu�da\n\t");
							system("pause");
						}
					}while(verificacaoValidez == 1);
				}else if(verificacaoValidez == 2){
					fprintf(temporario,"%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n%d\n%s\n%d\n%s\n%s\n%s\n", nomeVerific, generoVerific, rgVerific, cpfVerific, idadeVerific, ufVerific, cidadeVerific, enderecoVerific, numeroVerific, casaOuPredioVerific, apartamentoVerific, cepVerific, telefoneVerific, religiaoVerific);
					printf("\n\tEdi��o cancelada\n\t");
					system("pause");
				}
				verificacaoValidez = 2;
				verificacaoValidez3 = 2;
			}else{
				fprintf(temporario,"%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n%d\n%s\n%d\n%s\n%s\n%s\n", nomeVerific, generoVerific, rgVerific, cpfVerific, idadeVerific, ufVerific, cidadeVerific, enderecoVerific, numeroVerific, casaOuPredioVerific, apartamentoVerific, cepVerific, telefoneVerific, religiaoVerific);
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(pacientes);
		fclose(temporario);
		
		int ret2 = remove(arquivoPermanenteCadastroPaciente);
		if(ret2 != 0){
			printf("\n\n\tArquivo n�o foi deletado corretamente!\n\n\t");
			perror("Error: ");
			system("pause");
		}
		int ret = rename(arquivoTemporarioCadastroPaciente, arquivoPermanenteCadastroPaciente);
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
		printf("\n\tTELA DE EDI��O DE CADASTRO DE PACIENTE");
		printf("\n\n\tDeseja editar outro cadastro? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);	
}

void cadastroPacienteExcluir(){

	FILE *pacientes;
	FILE *temporario;
	verificacaoValidez3 = 1;
	
	do{
    	system("cls");
		printf("\n\tTELA DE EXCLUS�O DE CADASTRO DE PACIENTE");
		printf("\n\n\tInsira o RG do paciente (EX: 00.000.000-0): ");
		fflush(stdin);
		fgets(rg, 20, stdin);
		rg[strcspn (rg, "\n\000")] = '\000';
		
		system("cls");
		pacientes = fopen("Pacientes.txt","r");
		temporario = fopen("Pacientes Novo.txt","w+");
		
		do{ //loop para leitura dos dados do arquivo Agendamentos.txt
			int t = fscanf(pacientes," %[^\n] %[^\n] %[^\n] %[^\n] %d %[^\n] %[^\n] %[^\n] %d %[^\n] %d %[^\n] %[^\n] %[^\n]", nomeVerific, generoVerific, rgVerific, cpfVerific, &idadeVerific, ufVerific, cidadeVerific, enderecoVerific, &numeroVerific, casaOuPredioVerific, &apartamentoVerific, cepVerific, telefoneVerific, religiaoVerific);
			if(t == EOF){
				if(verificacaoValidez3 != 2){
					printf("\n\tTELA DE EXCLUS�O DE CADASTRO DE PACIENTE");
					printf("\n\n\tPaciente inserido n�o encontrado\n\t");
				}
				verificacaoValidez = 1;
				break;
			}
			if(strcmp(rg,rgVerific) == 0){
				printf("\n\n\tTELA DE EXCLUS�O DE CADASTRO DE PACIENTE");
				printf("\n\n\tNome do paciente: %s", nomeVerific);
				printf("\n\tGenero: %s", generoVerific);
				printf("\n\tRG: %s", rgVerific);
				printf("\n\tCPF: %s", cpfVerific);
				printf("\n\tIdade: %d", idadeVerific);
				printf("\n\tEstado: %s", ufVerific);
				printf("\n\tCidade: %s", cidadeVerific);
				printf("\n\tEndere�o: %s", enderecoVerific);
				printf("\n\tN�mero: %d", numeroVerific);
				printf("\n\tTipo de resid�ncia: %s", casaOuPredioVerific);
				if(strcmp(casaOuPredioVerific, predio) == 0){
					printf("\n\tApartamento: %d", apartamentoVerific);
				}
				printf("\n\tCEP: %s", cepVerific);
				printf("\n\tTelefone: %s", telefoneVerific);
				printf("\n\tReligi�o: %s", religiaoVerific);
		
				printf("\n\n\tTem certeza que deseja excluir esse cadastro? Se sim, digite 1, e se n�o, digite 2: ");
				scanf("%d", &verificacaoValidez);
				
				if(verificacaoValidez == 1){
					printf("\n\tCadastro exclu�do com sucesso\n\t");
					system("pause");
				}else if(verificacaoValidez == 2){
					fprintf(temporario,"%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n%d\n%s\n%d\n%s\n%s\n%s\n", nomeVerific, generoVerific, rgVerific, cpfVerific, idadeVerific, ufVerific, cidadeVerific, enderecoVerific, numeroVerific, casaOuPredioVerific, apartamentoVerific, cepVerific, telefoneVerific, religiaoVerific);
					printf("\n\tCadastro n�o foi exclu�do\n\t");
					system("pause");
				}
				verificacaoValidez = 2;
				verificacaoValidez3 = 2;
			}else{
				fprintf(temporario,"%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n%d\n%s\n%d\n%s\n%s\n%s\n", nomeVerific, generoVerific, rgVerific, cpfVerific, idadeVerific, ufVerific, cidadeVerific, enderecoVerific, numeroVerific, casaOuPredioVerific, apartamentoVerific, cepVerific, telefoneVerific, religiaoVerific);
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(pacientes);
		fclose(temporario);
		
		int ret2 = remove(arquivoPermanenteCadastroPaciente);
		if(ret2 != 0){
			printf("\n\n\tArquivo n�o foi deletado corretamente!\n\n\t");
			perror("Error: ");
			system("pause");
		}
		int ret = rename(arquivoTemporarioCadastroPaciente, arquivoPermanenteCadastroPaciente);
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
		printf("\n\tTELA DE EXCLUS�O DE CADASTRO DE PACIENTE");
		printf("\n\n\tDeseja excluir outro cadastro? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);
	
}

void cadastroFuncionarioConsultar(){
	
	FILE *funcionarios;
	verificacaoValidez3 = 1;
	
	do{
		system("cls");
		printf("\n\tTELA DE CONSULTA DE CADASTRO DE FUNCION�RIO");
		printf("\n\n\t[1] Consultar pelo nome");
		printf("\n\t[2] Consultar pelo RG");
		printf("\n\t[3] Cancelar consulta");
		printf("\n\tInsira o n�mero correspondente � forma de busca que deseja (somente o n�mero): ");
		scanf("%d", &menuEscolha);
		
		switch(menuEscolha){
			case 1:
				do{
					system("cls");
					printf("\n\tTELA DE CONSULTA DE CADASTRO DE FUNCION�RIO");
					printf("\n\n\tInsira o nome do funcion�rio: ");
					fflush(stdin);
					fgets(nome, 200, stdin);
					nome[strcspn (nome, "\n\000")] = '\000';
											
					system("cls");
					printf("\n\tTELA DE CONSULTA DE CADASTRO DE FUNCION�RIO");
					funcionarios = fopen("Funcionarios.txt","r");
					do{
						int t = fscanf(funcionarios," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %[^\n] %[^\n] %[^\n] %d %[^\n] %d %[^\n] %[^\n] %[^\n] %f", unidadeVerific, nomeVerific, generoVerific, rgVerific, cpfVerific, &idadeVerific, ufVerific, cidadeVerific, enderecoVerific, &numeroVerific, casaOuPredioVerific, &apartamentoVerific, cepVerific, telefoneVerific, profissaoVerific, &salarioVerific);
						if(t == EOF){	
							if(verificacaoValidez3 != 2){
								printf("\n\n\tCadastro inserido n�o encontrado.");
							}
							verificacaoValidez = 1;
						}else if(strcmp(nome,nomeVerific) == 0){
							printf("\n\n\tUnidade: %s", unidadeVerific);
							printf("\n\tNome do(a) funcion�rio(a): %s", nomeVerific);
							printf("\n\tGenero: %s", generoVerific);
							printf("\n\tRG: %s", rgVerific);
							printf("\n\tCPF: %s", cpfVerific);
							printf("\n\tIdade: %d", idadeVerific);
							printf("\n\tEstado: %s", ufVerific);
							printf("\n\tCidade: %s", cidadeVerific);
							printf("\n\tEndere�o: %s", enderecoVerific);
							printf("\n\tN�mero: %d", numeroVerific);
							printf("\n\tTipo de resid�ncia: %s", casaOuPredioVerific);
							if(strcmp(casaOuPredioVerific, predio) == 0){
								printf("\n\tApartamento: %d", apartamentoVerific);
							}
							printf("\n\tCEP: %s", cepVerific);
							printf("\n\tTelefone: %s", telefoneVerific);
							printf("\n\tProfiss�o: %s", profissaoVerific);
							printf("\n\tSal�rio: R$ %.2f", salarioVerific);
							verificacaoValidez = 2;
							verificacaoValidez3 = 2;
						}else{
							verificacaoValidez = 2;
						}
					}while(verificacaoValidez != 1);
					fclose(funcionarios);
					verificacaoValidez3 = 1;
					printf("\n\n\tDeseja consultar outro cadastro pelo nome? Se sim, digite 1, e se n�o, digite 2: ");
					scanf("%d", &verificacaoValidez);
				}while(verificacaoValidez == 1);
				break;
			case 2:
				do{
					system("cls");
					printf("\n\tTELA DE CONSULTA DE CADASTRO DE FUNCION�RIO");
					printf("\n\n\tInsira o RG do funcion�rio: ");
					fflush(stdin);
					fgets(rg, 20, stdin);
					rg[strcspn (rg, "\n\000")] = '\000';
											
					system("cls");
					printf("\n\tTELA DE CONSULTA DE CADASTRO DE FUNCION�RIO");
					funcionarios = fopen("Funcionarios.txt","r");
					do{
						int t = fscanf(funcionarios," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %[^\n] %[^\n] %[^\n] %d %[^\n] %d %[^\n] %[^\n] %[^\n] %f", unidadeVerific, nomeVerific, generoVerific, rgVerific, cpfVerific, &idadeVerific, ufVerific, cidadeVerific, enderecoVerific, &numeroVerific, casaOuPredioVerific, &apartamentoVerific, cepVerific, telefoneVerific, profissaoVerific, &salarioVerific);
						if(t == EOF){	
							if(verificacaoValidez3 != 2){
								printf("\n\n\tCadastro inserido n�o encontrado.");
							}
							verificacaoValidez = 1;
						}else if(strcmp(rg,rgVerific) == 0){
							printf("\n\n\tUnidade: %s", unidadeVerific);
							printf("\n\tNome do(a) funcion�rio(a): %s", nomeVerific);
							printf("\n\tGenero: %s", generoVerific);
							printf("\n\tRG: %s", rgVerific);
							printf("\n\tCPF: %s", cpfVerific);
							printf("\n\tIdade: %d", idadeVerific);
							printf("\n\tEstado: %s", ufVerific);
							printf("\n\tCidade: %s", cidadeVerific);
							printf("\n\tEndere�o: %s", enderecoVerific);
							printf("\n\tN�mero: %d", numeroVerific);
							printf("\n\tTipo de resid�ncia: %s", casaOuPredioVerific);
							if(strcmp(casaOuPredioVerific, predio) == 0){
								printf("\n\tApartamento: %d", apartamentoVerific);
							}
							printf("\n\tCEP: %s", cepVerific);
							printf("\n\tTelefone: %s", telefoneVerific);
							printf("\n\tProfiss�o: %s", profissaoVerific);
							printf("\n\tSal�rio: R$ %.2f", salarioVerific);
							verificacaoValidez = 2;
							verificacaoValidez3 = 2;
						}else{
							verificacaoValidez = 2;
						}
					}while(verificacaoValidez != 1);
					fclose(funcionarios);
					verificacaoValidez3 = 1;
					printf("\n\n\tDeseja consultar outro cadastro pelo RG? Se sim, digite 1, e se n�o, digite 2: ");
					scanf("%d", &verificacaoValidez);
				}while(verificacaoValidez == 1);
				break;
			default:
				verificacaoValidez = 2;
				continue;
		}
		
		system("cls");
		printf("\n\tTELA DE CONSULTA DE CADASTRO DE FUNCION�RIO");
		printf("\n\n\tDeseja consultar outro cadastro? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);
}

void cadastroFuncionario(){

	FILE *funcionarios;
  		
  	do{
		system("cls");
		printf("\n\tTELA DE CADASTRO DE FUNCION�RIOS");
		printf("\n\n\tInsira a qual unidade esse funcion�rio est� designado (A, B ou C): ");
		fflush(stdin); //limpa o input para evitar erros
		fgets(unidade, 10, stdin); //recebe input do usu�rio
		unidade[strcspn (unidade, "\n\000")] = '\000'; //remove o \n da informa��o inserida pelo usu�rio, afim de comparar essa informa��o inserida com a informa��o lida do arquivo corretamente
		if(strcmp(unidade,unidadeA) != 0 && strcmp(unidade,unidadeB) != 0 && strcmp(unidade,unidadeC) != 0){ //verifica se a unidade inserida � A, B ou C, e se n�o for nenhuma das 3, retorna um erro e reseta a tela
			printf("\tUnidade inserida inv�lida/n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tInsira o nome completo do(a) funcion�rio(a): ");
		fflush(stdin);
		fgets(nome, 200, stdin);
		printf("\tInsira o g�nero do(a) funcion�rio(a) (M, F ou ND): ");
		fflush(stdin);
		fgets(genero, 10, stdin);
		genero[strcspn (genero, "\n\000")] = '\000';
		if(strcmp(genero,generoM) != 0 && strcmp(genero,generoF) != 0 && strcmp(genero,generoND) != 0){
			printf("\tG�nero inserido inv�lido, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tInsira o RG (EX: 00.000.000-0): ");
		fflush(stdin);
		fgets(rg, 20, stdin);
		if(strlen(rg) != 13){ //verifica se o RG tem 12 digitos (9 n�meros e 3 separadores)
			printf("\tRG inv�lido, tente novamente\n\t");
			system("pause");
			continue;
		}			
		printf("\tInsira o CPF (EX: 000.000.000-00): ");
		fflush(stdin);
		fgets(cpf, 20, stdin);
		if(strlen(cpf) != 15){
			printf("\tCPF inv�lido, tente novamente\n\t");
			system("pause");
			continue;	
		}	
		printf("\tInsira a idade: ");
		scanf("%d", &idade);
		printf("\tInsira o Estado (EX: SP): ");
		fflush(stdin);
		fgets(uf, 10, stdin);
		if(strlen(uf) != 3){
			printf("\tEstado inv�lido, tente novamente\n\t");
			system("pause");
			continue;
		}		
		printf("\tInsira a cidade: ");
		fflush(stdin);
		fgets(cidade, 100, stdin);
		printf("\tInsira o endere�o (somente nome da rua): ");
		fflush(stdin);
		fgets(endereco, 100, stdin);			
		printf("\tInsira o n�mero: ");
		scanf("%d", &numero);
		printf("\tTipo de resid�ncia (Insira Casa ou Predio): ");
		fflush(stdin);
		fgets(casaOuPredio, 10, stdin);
		casaOuPredio[strcspn (casaOuPredio, "\n")] = '\000'; //remove o \n da informa��o inserida pelo usu�rio, afim de comparar essa informa��o inserida com outra informa��o corretamente
		if(strcmp(casaOuPredio, casa) != 0 && strcmp(casaOuPredio, predio) != 0){
			printf("\tInforma��o inv�lida, tente novamente\n\t");
			system("pause");
			continue;
		}
		if(strcmp(casaOuPredio, predio) == 0){
			printf("\tInsira o n�mero do apartamento: ");
			scanf("%d", &apartamento);
		}else{
			apartamento = 0;
		}	
		printf("\tInsira o CEP(Ex:00000-000): ");
		fflush(stdin);
		fgets(cep, 20, stdin);
		if(strlen(cep) != 10){
			printf("\tCPF inv�lido, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tInsira o tefelone do(a) funcion�rio(a) (EX: (11)93535-0202): ");
		fflush(stdin);
		fgets(telefone, 20, stdin);
		if(strlen(telefone) != 14 && strlen(telefone) != 15){ 
			printf("\tTelefone inv�lido, tente novamente\n\t");
			system("pause");
			continue;
		}	
		printf("\tInsira a profiss�o (Medico, Enfermeiro ou Recepcionista): ");
		fflush(stdin);
		fgets(profissao, 100, stdin);
		profissao[strcspn (profissao, "\n")] = '\000';
		if(strcmp(profissao,medico) != 0 && strcmp(profissao,enfermeiro) != 0 && strcmp(profissao,recepcionista) != 0){
			printf("\tProfiss�o inserida inv�lida/n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tInsira o sal�rio (EX: 2500,50): ");
		scanf("%f", &salario);
		
		system("cls");
		printf("\n\tTELA DE CADASTRO DE FUNCION�RIOS");
		printf("\n\n\tUnidade: %s", unidade);
		printf("\n\tNome do(a) funcion�rio(a): %s", nome);
		printf("\n\tG�nero: %s", genero);
		printf("\tRG: %s", rg);
		printf("\tCPF: %s", cpf);
		printf("\tIdade: %d", idade);
		printf("\n\tEstado: %s", uf);
		printf("\tCidade: %s", cidade);
		printf("\tEndere�o: %s", endereco);
		printf("\tN�mero: %d", numero);
		printf("\n\tTipo de resid�ncia: %s", casaOuPredio);
		if(strcmp(casaOuPredio, predio) == 0){
			printf("\n\tApartamento: %d", apartamento);
		}
		printf("\n\tCEP: %s", cep);
		printf("\tTelefone: %s", telefone);
		printf("\tProfiss�o: %s", profissao);
		printf("\n\tSal�rio: R$ %.2f", salario);
		printf("\n\n\tDeseja manter este cadastro? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	
		if(verificacaoValidez == 1){
			funcionarios = fopen("Funcionarios.txt","a");
			if((funcionarios=fopen("Funcionarios.txt","a"))==NULL){
				puts("\n\n\tERRO: N�o foi poss�vel criar arquivo com funcion�rios/Arquivo de funcion�rios n�o encontrado!");
				printf("\t");
				system("pause");
				continue;
			}
			fprintf(funcionarios,"%s\n%s%s\n%s%s%d\n%s%s%s%d\n%s\n%d\n%s%s%s\n%.2f\n", unidade, nome, genero, rg, cpf, idade, uf, cidade, endereco, numero, casaOuPredio, apartamento, cep, telefone, profissao, salario);
			fclose(funcionarios);
		}
		
		system("cls");
		printf("\n\tTELA DE CADASTRO DE FUNCION�RIOS");
		printf("\n\n\tDeseja cadastrar outro(a) funcion�rio(a)? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);
			
}

void cadastroFuncionarioEditar(){

	FILE *funcionarios;
	FILE *temporario;
	verificacaoValidez3 = 1;
	
	do{
    	system("cls");
		printf("\n\tTELA DE EDI��O DE CADASTRO DE FUNCION�RIO");
		printf("\n\n\tInsira o RG do funcion�rio (EX: 00.000.000-0): ");
		fflush(stdin);
		fgets(rg, 20, stdin);
		rg[strcspn (rg, "\n\000")] = '\000';
		
		system("cls");
		funcionarios = fopen("Funcionarios.txt","r");
		temporario = fopen("Funcionarios Novo.txt","w+");
		
		do{
			int t = fscanf(funcionarios," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %[^\n] %[^\n] %[^\n] %d %[^\n] %d %[^\n] %[^\n] %[^\n] %f", unidadeVerific, nomeVerific, generoVerific, rgVerific, cpfVerific, &idadeVerific, ufVerific, cidadeVerific, enderecoVerific, &numeroVerific, casaOuPredioVerific, &apartamentoVerific, cepVerific, telefoneVerific, profissaoVerific, &salarioVerific);
			if(t == EOF){
				if(verificacaoValidez3 != 2){
					printf("\n\tTELA DE EDI��O DE CADASTRO DE FUNCION�RIO");
					printf("\n\n\tCadastro inserido n�o encontrado\n\t");
				}
				verificacaoValidez = 1;
				break;
			}
			if(strcmp(rg,rgVerific) == 0){
				printf("\n\tTELA DE EDI��O DE CADASTRO DE FUNCION�RIO");
				printf("\n\n\tUnidade: %s", unidadeVerific);
				printf("\n\tNome do(a) funcion�rio(a): %s", nomeVerific);
				printf("\n\tGenero: %s", generoVerific);
				printf("\n\tRG: %s", rgVerific);
				printf("\n\tCPF: %s", cpfVerific);
				printf("\n\tIdade: %d", idadeVerific);
				printf("\n\tEstado: %s", ufVerific);
				printf("\n\tCidade: %s", cidadeVerific);
				printf("\n\tEndere�o: %s", enderecoVerific);
				printf("\n\tN�mero: %d", numeroVerific);
				printf("\n\tTipo de resid�ncia: %s", casaOuPredioVerific);
				if(strcmp(casaOuPredioVerific, predio) == 0){
					printf("\n\tApartamento: %d", apartamentoVerific);
				}
				printf("\n\tCEP: %s", cepVerific);
				printf("\n\tTelefone: %s", telefoneVerific);
				printf("\n\tProfiss�o: %s", profissaoVerific);
				printf("\n\tSal�rio: R$ %.2f", salarioVerific);
				
				printf("\n\n\tTem certeza que deseja editar esse cadastro? Se sim, digite 1, e se n�o, digite 2: ");
				scanf("%d", &verificacaoValidez);
				
				if(verificacaoValidez == 1){
					do{
						system("cls");
						printf("\n\tTELA DE EDI��O DE CADASTRO DE FUNCION�RIO");
						printf("\n\n\tDeseja editar a unidade? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira a qual unidade esse funcion�rio(a) est� designado (A, B ou C): ");
							fflush(stdin);
							fgets(unidadeVerific, 10, stdin);
							unidadeVerific[strcspn (unidadeVerific, "\n\000")] = '\000';
							if(strcmp(unidadeVerific,unidadeA) != 0 && strcmp(unidadeVerific,unidadeB) != 0 && strcmp(unidadeVerific,unidadeC) != 0){
								printf("\tUnidade inserida inv�lida/n�o existe, tente novamente\n\t");
								system("pause");
								continue;
							}
						}
						printf("\n\tDeseja editar o nome? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira o nome do(a) funcion�rio(a): ");
							fflush(stdin);
							fgets(nomeVerific, 200, stdin);
							nomeVerific[strcspn (nomeVerific, "\n\000")] = '\000';
						}
						printf("\n\tDeseja editar o g�nero? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira o g�nero do(a) funcion�rio(a) (M, F ou ND): ");
							fflush(stdin);
							fgets(generoVerific, 10, stdin);
							generoVerific[strcspn (generoVerific, "\n\000")] = '\000';
							if(strcmp(generoVerific,generoM) != 0 && strcmp(generoVerific,generoF) != 0 && strcmp(generoVerific,generoND) != 0){
								printf("\tG�nero inserido inv�lido, tente novamente\n\t");
								system("pause");
								continue;
							}
						}
						printf("\n\tDeseja editar o RG? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira o RG (EX: 00.000.000-0): ");
							fflush(stdin);
							fgets(rgVerific, 20, stdin);
							if(strlen(rgVerific) != 13){ //verifica se o RG tem 12 digitos (9 n�meros e 3 separadores)
								printf("\tRG inv�lido, tente novamente\n\t");
								system("pause");
								continue;
							}
							rgVerific[strcspn (rgVerific, "\n\000")] = '\000';
						}
						printf("\n\tDeseja editar o CPF? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira o CPF (EX: 000.000.000-00): ");
							fflush(stdin);
							fgets(cpfVerific, 20, stdin);
							if(strlen(cpfVerific) != 15){
								printf("\tCPF inv�lido, tente novamente\n\t");
								system("pause");
								continue;	
							}
							cpfVerific[strcspn (cpfVerific, "\n\000")] = '\000';
						}
						printf("\n\tDeseja editar a idade? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira a idade: ");
							scanf("%d", &idadeVerific);
						}
						printf("\n\tDeseja editar o Estado? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira o Estado (EX: SP): ");
							fflush(stdin);
							fgets(ufVerific, 10, stdin);
							ufVerific[strcspn (ufVerific, "\n\000")] = '\000';
							if(strlen(ufVerific) != 2){
								printf("\tCPF inv�lido, tente novamente\n\t");
								system("pause");
								continue;	
							}
						}
						printf("\n\tDeseja editar a cidade? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira a cidade: ");
							fflush(stdin);
							fgets(cidadeVerific, 100, stdin);
							cidadeVerific[strcspn (cidadeVerific, "\n\000")] = '\000';
						}
						printf("\n\tDeseja editar o endere�o? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira o endere�o (somente nome da rua): ");
							fflush(stdin);
							fgets(enderecoVerific, 100, stdin);
							enderecoVerific[strcspn (enderecoVerific, "\n\000")] = '\000';
							printf("\tInsira o n�mero: ");
							scanf("%d", &numeroVerific);
							printf("\tTipo de resid�ncia (Insira Casa ou Predio): ");
							fflush(stdin);
							fgets(casaOuPredioVerific, 10, stdin);
							casaOuPredioVerific[strcspn (casaOuPredioVerific, "\n")] = '\000'; //remove o \n da informa��o inserida pelo usu�rio, afim de comparar essa informa��o inserida com outra informa��o corretamente
							if(strcmp(casaOuPredioVerific, casa) != 0 && strcmp(casaOuPredioVerific, predio) != 0){
								printf("\tInforma��o inv�lida, tente novamente\n\t");
								system("pause");
								continue;
							}
							if(strcmp(casaOuPredioVerific, predio) == 0){
								printf("\tInsira o n�mero do apartamento: ");
								scanf("%d", &apartamentoVerific);
							}else{
								apartamentoVerific = 0;
							}	
							printf("\tInsira o CEP(Ex:00000-000): ");
							fflush(stdin);
							fgets(cepVerific, 20, stdin);
							if(strlen(cepVerific) != 10){
								printf("\tCPF inv�lido, tente novamente\n\t");
								system("pause");
								continue;
							}
							cepVerific[strcspn (cepVerific, "\n\000")] = '\000';
						}
						printf("\n\tDeseja editar o telefone? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira o tefelone do(a) funcion�rio(a) (EX: (11)93535-0202): ");
							fflush(stdin);
							fgets(telefoneVerific, 20, stdin);
							if(strlen(telefoneVerific) != 14 && strlen(telefoneVerific) != 15){ 
								printf("\tTelefone inv�lido, tente novamente\n\t");
								system("pause");
								continue;
							}
							telefoneVerific[strcspn (telefoneVerific, "\n\000")] = '\000';
						}
						printf("\n\tDeseja editar a profiss�o? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira a profiss�o (Medico, Enfermeiro ou Recepcionista): ");
							fflush(stdin);
							fgets(profissaoVerific, 100, stdin);
							profissaoVerific[strcspn (profissaoVerific, "\n\000")] = '\000';
						}
						printf("\n\tDeseja editar o sal�rio? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira o sal�rio (EX: 2500,50): ");
							scanf("%f", &salarioVerific);
						}
						
						printf("\n\tSe deseja reiniciar o menu de edi��o (cancelando as edi��es feitas at� agora), digite 1.\n\tSe deseja sair da tela de edi��o (salvando as edi��es realizadas OU cancelando a edi��o, caso nada tenha sido editado), digite 2. ");
						printf("\n\tInsira a sua escolha: ");
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 2){
							fprintf(temporario,"%s\n%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n%d\n%s\n%d\n%s\n%s\n%s\n%.2f\n", unidadeVerific, nomeVerific, generoVerific, rgVerific, cpfVerific, idadeVerific, ufVerific, cidadeVerific, enderecoVerific, numeroVerific, casaOuPredioVerific, apartamentoVerific, cepVerific, telefoneVerific, profissaoVerific, salarioVerific);
							printf("\n\tEdi��o conclu�da\n\t");
							system("pause");
						}
					}while(verificacaoValidez == 1);
				}else if(verificacaoValidez == 2){
					fprintf(temporario,"%s\n%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n%d\n%s\n%d\n%s\n%s\n%s\n%.2f\n", unidadeVerific, nomeVerific, generoVerific, rgVerific, cpfVerific, idadeVerific, ufVerific, cidadeVerific, enderecoVerific, numeroVerific, casaOuPredioVerific, apartamentoVerific, cepVerific, telefoneVerific, profissaoVerific, salarioVerific);
					printf("\n\tEdi��o cancelada\n\t");
					system("pause");
				}
				verificacaoValidez = 2;
				verificacaoValidez3 = 2;
			}else{
				fprintf(temporario,"%s\n%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n%d\n%s\n%d\n%s\n%s\n%s\n%.2f\n", unidadeVerific, nomeVerific, generoVerific, rgVerific, cpfVerific, idadeVerific, ufVerific, cidadeVerific, enderecoVerific, numeroVerific, casaOuPredioVerific, apartamentoVerific, cepVerific, telefoneVerific, profissaoVerific, salarioVerific);
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(funcionarios);
		fclose(temporario);
		
		int ret2 = remove(arquivoPermanenteCadastroFuncionario);
		if(ret2 != 0){
			printf("\n\n\tArquivo n�o foi deletado corretamente!\n\n\t");
			perror("Error: ");
			system("pause");
		}
		int ret = rename(arquivoTemporarioCadastroFuncionario, arquivoPermanenteCadastroFuncionario);
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
		printf("\n\tTELA DE EDI��O DE CADASTRO DE FUNCION�RIO");
		printf("\n\n\tDeseja editar outro cadastro? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);	
}

void cadastroFuncionarioExcluir(){

	FILE *funcionarios;
	FILE *temporario;
	verificacaoValidez3 = 1;
	
	do{
    	system("cls");
		printf("\n\tTELA DE EXCLUS�O DE CADASTRO DE FUNCION�RIO");
		printf("\n\n\tInsira o RG do funcion�rio (EX: 00.000.000-0): ");
		fflush(stdin);
		fgets(rg, 20, stdin);
		rg[strcspn (rg, "\n\000")] = '\000';
		
		system("cls");
		funcionarios = fopen("Funcionarios.txt","r");
		temporario = fopen("Funcionarios Novo.txt","w+");
		
		do{ //loop para leitura dos dados do arquivo Agendamentos.txt
			int t = fscanf(funcionarios," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %[^\n] %[^\n] %[^\n] %d %[^\n] %d %[^\n] %[^\n] %[^\n] %f", unidadeVerific, nomeVerific, generoVerific, rgVerific, cpfVerific, &idadeVerific, ufVerific, cidadeVerific, enderecoVerific, &numeroVerific, casaOuPredioVerific, &apartamentoVerific, cepVerific, telefoneVerific, profissaoVerific, &salarioVerific);
			if(t == EOF){
				if(verificacaoValidez3 != 2){
					printf("\n\tTELA DE EXCLUS�O DE CADASTRO DE FUNCION�RIO");
					printf("\n\n\tFuncion�rio inserido n�o encontrado\n\t");
				}
				verificacaoValidez = 1;
				break;
			}
			if(strcmp(rg,rgVerific) == 0){
				printf("\n\tTELA DE EXCLUS�O DE CADASTRO DE FUNCION�RIO");
				printf("\n\n\tUnidade: %s", unidadeVerific);
				printf("\n\tNome do(a) funcion�rio(a): %s", nomeVerific);
				printf("\n\tGenero: %s", generoVerific);
				printf("\n\tRG: %s", rgVerific);
				printf("\n\tCPF: %s", cpfVerific);
				printf("\n\tIdade: %d", idadeVerific);
				printf("\n\tEstado: %s", ufVerific);
				printf("\n\tCidade: %s", cidadeVerific);
				printf("\n\tEndere�o: %s", enderecoVerific);
				printf("\n\tN�mero: %d", numeroVerific);
				printf("\n\tTipo de resid�ncia: %s", casaOuPredioVerific);
				if(strcmp(casaOuPredioVerific, predio) == 0){
					printf("\n\tApartamento: %d", apartamentoVerific);
				}
				printf("\n\tCEP: %s", cepVerific);
				printf("\n\tTelefone: %s", telefoneVerific);
				printf("\n\tProfiss�o: %s", profissaoVerific);
				printf("\n\tSal�rio: R$ %.2f", salarioVerific);
		
				printf("\n\n\tTem certeza que deseja excluir esse cadastro? Se sim, digite 1, e se n�o, digite 2: ");
				scanf("%d", &verificacaoValidez);
				
				if(verificacaoValidez == 1){
					printf("\n\tCadastro exclu�do com sucesso\n\t");
					system("pause");
				}else if(verificacaoValidez == 2){
					fprintf(temporario,"%s\n%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n%d\n%s\n%d\n%s\n%s\n%s\n%.2f\n", unidadeVerific, nomeVerific, generoVerific, rgVerific, cpfVerific, idadeVerific, ufVerific, cidadeVerific, enderecoVerific, numeroVerific, casaOuPredioVerific, apartamentoVerific, cepVerific, telefoneVerific, profissaoVerific, salarioVerific);
					printf("\n\tCadastro n�o foi exclu�do\n\t");
					system("pause");
				}
				verificacaoValidez = 2;
				verificacaoValidez3 = 2;
			}else{
				fprintf(temporario,"%s\n%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n%d\n%s\n%d\n%s\n%s\n%s\n%.2f\n", unidadeVerific, nomeVerific, generoVerific, rgVerific, cpfVerific, idadeVerific, ufVerific, cidadeVerific, enderecoVerific, numeroVerific, casaOuPredioVerific, apartamentoVerific, cepVerific, telefoneVerific, profissaoVerific, salarioVerific);
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(funcionarios);
		fclose(temporario);
		
		int ret2 = remove(arquivoPermanenteCadastroFuncionario);
		if(ret2 != 0){
			printf("\n\n\tArquivo n�o foi deletado corretamente!\n\n\t");
			perror("Error: ");
			system("pause");
		}
		int ret = rename(arquivoTemporarioCadastroFuncionario, arquivoPermanenteCadastroFuncionario);
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
		printf("\n\tTELA DE EXCLUS�O DE CADASTRO DE FUNCION�RIO");
		printf("\n\n\tDeseja excluir outro cadastro? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);
	
}

void cadastroGastoConsultar(){
	
	FILE *gastos;
	verificacaoValidez3 = 1;
	
	do{
		system("cls");
		printf("\n\tTELA DE CONSULTA DE GASTO");
		printf("\n\n\tInsira o nome do gasto: ");
		fflush(stdin);
		fgets(nomeGasto, 100, stdin);
		nomeGasto[strcspn (nomeGasto, "\n\000")] = '\000';
								
		system("cls");
		printf("\n\tTELA DE CONSULTA DE GASTO");
		gastos = fopen("Gastos.txt","r");		
		do{
			int t = fscanf(gastos," %[^\n] %[^\n] %f %d %d %d", unidadeVerific, nomeGastoVerific,  &valorGastoVerific, &diaVerific, &mesVerific, &anoVerific);
			if(t == EOF){	
				if(verificacaoValidez3 != 2){
					printf("\n\n\tGasto inserido n�o encontrado");
				}
				verificacaoValidez = 1;
			}else if(strcmp(nomeGasto,nomeGastoVerific) == 0){
				printf("\n\n\tUnidade: %s", unidadeVerific);
				printf("\n\tNome do Gasto: %s", nomeGastoVerific);
				printf("\n\tValor do gasto: R$ %.2f", valorGastoVerific);
				if(mesVerific >= 10 && diaVerific >= 10){
					printf("\n\tData de registro: %d/%d/%d", diaVerific, mesVerific, anoVerific);
				}else if(mesVerific < 10 && diaVerific >= 10){
					printf("\n\tData de registro: %d/0%d/%d", diaVerific, mesVerific, anoVerific);
				}else if(mesVerific < 10 && diaVerific < 10){
					printf("\n\tData de registro: 0%d/0%d/%d", diaVerific, mesVerific, anoVerific);
				}else if(mesVerific >= 10 && diaVerific < 10){
					printf("\n\tData de registro: 0%d/%d/%d", diaVerific, mesVerific, anoVerific);
				}
				verificacaoValidez = 2;
				verificacaoValidez3 = 2;
			}else{
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(gastos);
		
		printf("\n\n\t");
		system("pause");
		system("cls");
		printf("\n\tTELA DE CONSULTA DE GASTO");
		printf("\n\n\tDeseja consultar outro gasto? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);
}

void cadastroGasto(){

	FILE *gastos; //ponteiro do arquivo de gastos
	
	do{
    	system("cls");
		printf("\n\tTELA DE CADASTRO DE GASTO");
		printf("\n\n\tInsiria a unidade a qual esse cadastro pertence (A, B ou C): ");
		fflush(stdin); //limpa o input para evitar erros
		fgets(unidade, 10, stdin); //recebe input do usu�rio
		printf("\tInsira um nome para o gasto: ");
		fflush(stdin);
		fgets(nomeGasto, 100, stdin);
		printf("\tInsira o valor do gasto (ex: 850,50): ");
		scanf("%f", &valorGasto);
  	
		system("cls");
		printf("\n\n\tTELA DE CADASTRO DE GASTO");
		printf("\n\n\tUnidade: %s", unidade);
		printf("\tNome do gasto: %s", nomeGasto);
		printf("\tValor do gasto: R$ %.2f", valorGasto);
		printf("\n\tData do gasto: %d/%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
		printf("\n\n\tDeseja salvar esse gasto? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
		
		if(verificacaoValidez == 1){
			gastos = fopen("Gastos.txt","a"); //abre o arquivo de gastos no modo "append", onde informa��es novas que s�o salvas, s�o incluidas no final do arquivo
			if((gastos=fopen("Gastos.txt","a"))==NULL){ //verifica��o para caso o arquivo de gastos n�o for encontrado/n�o for poss�vel cria-lo
				puts("\n\n\tERRO: N�o foi poss�vel criar arquivo de gastos/Arquivo de gastos n�o encontrado!");
				printf("\t");
				system("pause");
				continue;
			}
			fprintf(gastos,"%s%s%.2f\n%d %d %d\n", unidade, nomeGasto, valorGasto, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900); //salva os dados inseridos no arquivo de gastos
			fclose(gastos); //fecha o arquivo de gastos
		}
		
		system("cls");
		printf("\n\tTELA DE CADASTRO DE GASTO");
		printf("\n\n\tDeseja cadastrar outro gasto? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);
	
}

void cadastroGastoEditar(){

	FILE *gastos;
	FILE *temporario;
	verificacaoValidez3 = 1;
	
	do{
    	system("cls");
		printf("\n\tTELA DE EDI��O DE GASTOS");
		printf("\n\n\tInsira a unidade a qual esse agendamento pertence (A, B ou C): ");
		fflush(stdin);
		fgets(unidade, 10, stdin);
		unidade[strcspn (unidade, "\n\000")] = '\000';
		printf("\tInsira o nome do gasto: ");
		fflush(stdin);
		fgets(nomeGasto, 100, stdin);
		nomeGasto[strcspn (nomeGasto, "\n\000")] = '\000';
		printf("\tInsira a data da da inser��o do gasto:\n\tDia (EX: 8): ");
		scanf("%d", &dia);
		printf("\tM�s (EX: 5): ");
		scanf("%d", &mes);
		printf("\tAno (EX: 2020): ");
		scanf("%d", &ano);
			
		system("cls");
		gastos = fopen("Gastos.txt","r");
		temporario = fopen("Gastos Novo.txt","w+");
		
		do{
			int t = fscanf(gastos," %[^\n] %[^\n] %f %d %d %d", unidadeVerific, nomeGastoVerific,  &valorGastoVerific, &diaVerific, &mesVerific, &anoVerific);
			if(t == EOF){
				if(verificacaoValidez3 != 2){
					printf("\n\tTELA DE EDI��O DE GASTOS");
					printf("\n\n\tGasto inserido n�o encontrado\n\t");
				}
				verificacaoValidez = 1;
				break;
			}
			if(strcmp(unidade,unidadeVerific) == 0 && strcmp(nomeGasto,nomeGastoVerific) == 0 && dia == diaVerific && mes == mesVerific && ano == anoVerific){
				printf("\n\n\tTELA DE EDI��O DE GASTOS");
				printf("\n\n\tUnidade: %s", unidadeVerific);
				printf("\n\tNome do Gasto: %s", nomeGastoVerific);
				printf("\n\tValor do gasto: R$ %.2f", valorGastoVerific);
				if(mesVerific >= 10 && diaVerific >= 10){
					printf("\n\tData de registro: %d/%d/%d", diaVerific, mesVerific, anoVerific);
				}else if(mesVerific < 10 && diaVerific >= 10){
					printf("\n\tData de registro: %d/0%d/%d", diaVerific, mesVerific, anoVerific);
				}else if(mesVerific < 10 && diaVerific < 10){
					printf("\n\tData de registro: 0%d/0%d/%d", diaVerific, mesVerific, anoVerific);
				}else if(mesVerific >= 10 && diaVerific < 10){
					printf("\n\tData de registro: 0%d/%d/%d", diaVerific, mesVerific, anoVerific);
				}
				
				printf("\n\n\tTem certeza que deseja editar esse gasto? Se sim, digite 1, e se n�o, digite 2: ");
				scanf("%d", &verificacaoValidez);
				
				if(verificacaoValidez == 1){
					do{
						system("cls");
						printf("\n\tTELA DE EDI��O DE GASTOS");
						printf("\n\n\tDeseja editar a unidade? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){
							printf("\tInsira a unidade a qual esse gasto pertence (A, B ou C): ");
							fflush(stdin);
							fgets(unidadeVerific, 10, stdin);
							unidadeVerific[strcspn (unidadeVerific, "\n\000")] = '\000';
							if(strcmp(unidadeVerific,unidadeA) != 0 && strcmp(unidadeVerific,unidadeB) != 0 && strcmp(unidadeVerific,unidadeC) != 0){
								printf("\tUnidade inserida inv�lida/n�o existe, tente novamente\n\t");
								system("pause");
								continue;
							}
						}
						printf("\n\tDeseja editar o nome do gasto? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){			
							printf("\tInsira o nome do gasto: ");
							fflush(stdin);
							fgets(nomeGastoVerific, 100, stdin);
							nomeGastoVerific[strcspn (nomeGastoVerific, "\n")] = '\000';
						}
						printf("\n\tDeseja editar o valor do gasto? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
							if(verificacaoValidez == 1){			
							printf("\tInsira o valor do gasto (ex: 850,50): ");
							scanf("%f", &valorGastoVerific);
						}
						printf("\n\tDeseja editar a data? Se sim, digite 1, e se n�o, digite 2: ");			
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 1){		
							printf("\tInsira a data do gasto:\n\tDia (EX: 5): ");
							scanf("%d", &diaVerific);
							if(diaVerific <1 || diaVerific >31){ //verifica se o dia � entre 1 e 31 (afinal, n�o existe dia 0 nem 32)
								printf("\tDia inserido n�o existe, tente novamente\n\t");
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
							printf("\tAno (EX: 2020): ");
							scanf("%d", &anoVerific);
						}

						printf("\n\tSe deseja reiniciar o menu de edi��o (cancelando as edi��es feitas at� agora), digite 1.\n\tSe deseja sair da tela de edi��o (salvando as edi��es realizadas OU cancelando a edi��o, caso nada tenha sido editado), digite 2. ");
						printf("\n\tInsira a sua escolha: ");
						scanf("%d", &verificacaoValidez);
						if(verificacaoValidez == 2){
							fprintf(temporario,"%s\n%s\n%.2f\n%d %d %d\n", unidadeVerific, nomeGastoVerific, valorGastoVerific, diaVerific, mesVerific, anoVerific);
							printf("\n\tEdi��o conclu�da\n\t");
							system("pause");
						}
					}while(verificacaoValidez == 1);
				}else if(verificacaoValidez == 2){
					fprintf(temporario,"%s\n%s\n%.2f\n%d %d %d\n", unidadeVerific, nomeGastoVerific, valorGastoVerific, diaVerific, mesVerific, anoVerific);
					printf("\n\tEdi��o cancelada\n\t");
					system("pause");
				}
				verificacaoValidez = 2;
				verificacaoValidez3 = 2;
			}else{
				fprintf(temporario,"%s\n%s\n%.2f\n%d %d %d\n", unidadeVerific, nomeGastoVerific, valorGastoVerific, diaVerific, mesVerific, anoVerific);
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(gastos);
		fclose(temporario);
		
		int ret2 = remove(arquivoPermanenteGastos);
		if(ret2 != 0){
			printf("\n\n\tArquivo n�o foi deletado corretamente!\n\n\t");
			perror("Error: ");
			system("pause");
		}
		int ret = rename(arquivoTemporarioGastos, arquivoPermanenteGastos);
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
		printf("\n\tTELA DE EDI��O DE GASTOS");
		printf("\n\n\tDeseja editar outro gasto? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);	
}

void cadastroGastoExcluir(){

	FILE *gastos;
	FILE *temporario;
	verificacaoValidez3 = 1;
	
	do{
    	system("cls");
		printf("\n\tTELA DE EXCLUS�O DE GASTO");
		printf("\n\n\tInsira o nome do gasto: ");
		fflush(stdin);
		fgets(nomeGasto, 100, stdin);
		nomeGasto[strcspn (nomeGasto, "\n\000")] = '\000';
		
		system("cls");
		gastos = fopen("Gastos.txt","r");
		temporario = fopen("Gastos Novo.txt","w+");
		
		do{
			int t = fscanf(gastos," %[^\n] %[^\n] %f %d %d %d", unidadeVerific, nomeGastoVerific,  &valorGastoVerific, &diaVerific, &mesVerific, &anoVerific);
			if(t == EOF){
				if(verificacaoValidez3 != 2){
					printf("\n\tTELA DE EXCLUS�O DE GASTO");
					printf("\n\n\tGasto inserido n�o encontrado\n\t");
				}
				verificacaoValidez = 1;
				break;
			}
			if(strcmp(nomeGasto,nomeGastoVerific) == 0){
				printf("\n\tTELA DE EXCLUS�O DE GASTO");
				printf("\n\n\tUnidade: %s", unidadeVerific);
				printf("\n\tNome do Gasto: %s", nomeGastoVerific);
				printf("\n\tValor do gasto: R$ %.2f", valorGastoVerific);
				if(mesVerific >= 10 && diaVerific >= 10){
					printf("\n\tData de registro: %d/%d/%d", diaVerific, mesVerific, anoVerific);
				}else if(mesVerific < 10 && diaVerific >= 10){
					printf("\n\tData de registro: %d/0%d/%d", diaVerific, mesVerific, anoVerific);
				}else if(mesVerific < 10 && diaVerific < 10){
					printf("\n\tData de registro: 0%d/0%d/%d", diaVerific, mesVerific, anoVerific);
				}else if(mesVerific >= 10 && diaVerific < 10){
					printf("\n\tData de registro: 0%d/%d/%d", diaVerific, mesVerific, anoVerific);
				}
		
				printf("\n\n\tTem certeza que deseja excluir esse gasto? Se sim, digite 1, e se n�o, digite 2: ");
				scanf("%d", &verificacaoValidez);
				
				if(verificacaoValidez == 1){
					printf("\n\tGasto exclu�do com sucesso\n\t");
					system("pause");
				}else if(verificacaoValidez == 2){
					fprintf(temporario,"%s\n%s\n%.2f\n%d %d %d\n", unidadeVerific, nomeGastoVerific, valorGastoVerific, diaVerific, mesVerific, anoVerific);
					printf("\n\tGasto n�o foi exclu�do\n\t");
					system("pause");
				}
				verificacaoValidez = 2;
				verificacaoValidez3 = 2;
			}else{
				fprintf(temporario,"%s\n%s\n%.2f\n%d %d %d\n", unidadeVerific, nomeGastoVerific, valorGastoVerific, diaVerific, mesVerific, anoVerific);
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(gastos);
		fclose(temporario);
		
		int ret2 = remove(arquivoPermanenteGastos);
		if(ret2 != 0){
			printf("\n\n\tArquivo n�o foi deletado corretamente!\n\n\t");
			perror("Error: ");
			system("pause");
		}
		int ret = rename(arquivoTemporarioGastos, arquivoPermanenteGastos);
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
		printf("\n\tTELA DE EXCLUS�O DE GASTO");
		printf("\n\n\tDeseja excluir outro gasto? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);
	
}

void contaCriar(){

	FILE *contas;
  		
  	do{
		system("cls");
		printf("\n\tTELA DE CRIA��O DE CONTA");
		printf("\n\n\tInsira o login: ");
		fflush(stdin);
		fgets(login, 100, stdin);
		login[strcspn (login, "\n\000")] = '\000';
		printf("\tInsira a senha: ");
		fflush(stdin);
		fgets(senha, 100, stdin);
		senha[strcspn (senha, "\n\000")] = '\000';
		
		contas = fopen("Contas.txt","r"); 
		do{
			int t = fscanf(contas," %[^\n] %[^\n]",loginSalvo,senhaSalva);
			if(strcmp(login,loginSalvo) == 0 && strcmp(senha,senhaSalva) == 0){
				printf("\tEsta conta j� est� cadastrada, tente novamente.");
				printf("\n\t");
				system("pause");
				verificacaoValidez = 2;
				break;
			}else if(t == EOF){
				verificacaoValidez = 1;
			}else{
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez == 2);
		fclose(contas);
		
		if(verificacaoValidez == 2){
			verificacaoValidez = 1;
			continue;
		}
		
		system("cls");
		printf("\n\tTELA DE CRIA��O DE CONTA");
		printf("\n\n\tLogin: %s", login);
		printf("\n\tSenha: %s", senha);
		printf("\n\tDeseja salvar essa conta? Se sim, digite 1, e se n�o, digite 2: ");
		
		scanf("%d", &verificacaoValidez);
		if(verificacaoValidez == 1){
			contas = fopen("Contas.txt","a");
			if((contas=fopen("Contas.txt","a"))==NULL){
				puts("\n\n\tERRO: N�o foi poss�vel criar arquivo com contas/Arquivo de contas n�o encontrado!");
				printf("\t");
				system("pause");
				continue;
			}
			fprintf(contas,"%s\n%s\n", login, senha);
			fclose(contas);
		}
		
		system("cls");
		printf("\n\tTELA DE CRIA��O DE CONTA");
		printf("\n\n\tDeseja cadastrar outra conta? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);		
	
}

void contaExcluir(){

	FILE *contas;
	FILE *temporario;
	verificacaoValidez3 = 1;
	  		
  	do{
		system("cls");
		printf("\n\tTELA DE EXCLUS�O DE CONTA");
		printf("\n\n\tInsira o login que deseja excluir: ");
		fflush(stdin);
		fgets(login, 100, stdin);
		login[strcspn (login, "\n\000")] = '\000';
		printf("\tInsira a senha: ");
		fflush(stdin);
		fgets(senha, 100, stdin);
		senha[strcspn (senha, "\n\000")] = '\000';
		
		system("cls");
		contas = fopen("Contas.txt","r"); //verifica��o se o hor�rio inserido est� dispon�vel
		temporario = fopen("Contas Novo.txt","w+");
		
		do{
			int t = fscanf(contas," %[^\n] %[^\n]",loginSalvo,senhaSalva);
			if(t == EOF){
				if(verificacaoValidez3 != 2){
					printf("\n\tTELA DE EXCLUS�O DE CONTA");
					printf("\n\n\tConta inserida n�o encontrada\n\t");
				}
				verificacaoValidez = 1;
				break;
			}
			if(strcmp(login,loginSalvo) == 0 && strcmp(senha,senhaSalva) == 0){
				printf("\n\tTELA DE EXCLUS�O DE CONTA");
				printf("\n\n\tLogin: %s", loginSalvo);
				printf("\n\tSenha: %s", senhaSalva);
		
				printf("\n\n\tTem certeza que deseja excluir essa conta? Se sim, digite 1, e se n�o, digite 2: ");
				scanf("%d", &verificacaoValidez);
				
				if(verificacaoValidez == 1){
					printf("\n\tConta exclu�da com sucesso\n\t");
					system("pause");
				}else if(verificacaoValidez == 2){
					fprintf(temporario,"%s\n%s\n", loginSalvo, senhaSalva);
					printf("\n\tConta n�o foi exclu�da\n\t");
					system("pause");
				}
				verificacaoValidez = 2;
				verificacaoValidez3 = 2;
			}else{
				fprintf(temporario,"%s\n%s\n", loginSalvo, senhaSalva);
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(contas);
		fclose(temporario);
		
		int ret2 = remove(arquivoPermanenteContas);
		if(ret2 != 0){
			printf("\n\n\tArquivo n�o foi deletado corretamente!\n\n\t");
			perror("Error: ");
			system("pause");
		}
		int ret = rename(arquivoTemporarioContas, arquivoPermanenteContas);
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
		printf("\n\tTELA DE EXCLUS�O DE CONTA");
		printf("\n\n\tDeseja excluir outra conta? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);		
	
}
