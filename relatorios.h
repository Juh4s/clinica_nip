float valorTotal, media, notaTotalA, notaTotalB, notaTotalC, mediaA, mediaB, mediaC;
int i, a, b, c;

void relatorioFaturamentoUnidadeDiario(){
	
	FILE *agendamentos;
	
	do{
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: FATURAMENTO DI�RIO DA UNIDADE");
		printf("\n\n\tInsira a unidade da qual deseja ver o relat�rio (A, B ou C): ");
		fflush(stdin);
		fgets(unidade, 10, stdin); 
		unidade[strcspn (unidade, "\n\000")] = '\000'; 
		if(strcmp(unidade,unidadeA) != 0 && strcmp(unidade,unidadeB) != 0 && strcmp(unidade,unidadeC) != 0){ 
			printf("\tUnidade inserida inv�lida/n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tInsira a data da qual deseja o relat�rio:\n\tDia (Ex: 8): ");
		scanf("%d", &dia);
		if(dia <1 || dia >31){ //verifica se o dia � entre 1 e 31 (afinal, n�o existe dia 0 nem 32)
			printf("\tDia inserido n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tMes (Ex: 5): ");
		scanf("%d", &mes);
		if(mes <1 || mes >12){ //verifica se o mes � entre 1 e 12 (afinal, n�o existe mes 0 nem 13)
			printf("\tM�s inserido n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tAno (Ex: 2020): ");
		scanf("%d", &ano);
		
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: FATURAMENTO DI�RIO DA UNIDADE");
			
		agendamentos = fopen("Agendamentos.txt","r");
		do{ 
			int t = fscanf(agendamentos," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %d %d %d %d %[^\n] %f", unidadeVerific, nomeVerific, rgVerific, cpfVerific, telefoneVerific, emailVerific, &diaVerific, &mesVerific, &anoVerific, &horaVerific, &minutoVerific, nomeMedicoVerific, &valorConsultaVerific);
			if(t == EOF){ 
				verificacaoValidez = 1;
				break; //se acabou, quebra o do...while e segue em frente
			}else{
				verificacaoValidez = 2;
			}
			if(strcmp(unidade,unidadeVerific) == 0 && dia == diaVerific && mes == mesVerific && ano == anoVerific){
				printf("\n\n\tUnidade: %s", unidadeVerific);
				printf("\n\tNome do paciente: %s", nomeVerific);
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
				printf("\n\tM�dico(a)/enfermeiro(a) que atendendeu: %s", nomeMedicoVerific);
				printf("\n\tValor da consulta: R$ %.2f", valorConsultaVerific);
				
				valorTotal += valorConsultaVerific;
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(agendamentos);
		
		printf("\n\n\tO faturamento di�rio total da unidade %s no dia ", unidade);
		if(mes >= 10 && dia >= 10){ 
			printf("%d/%d/%d", dia, mes, ano);
		}else if(mes < 10 && dia >= 10){
			printf("%d/0%d/%d", dia, mes, ano);
		}else if(mes < 10 && dia < 10){
			printf("0%d/0%d/%d", dia, mes, ano);
		}else if(mes >= 10 && dia < 10){
			printf("0%d/%d/%d", dia, mes, ano);
		}
		printf(" foi: R$ %.2f\n\t", valorTotal);
		valorTotal = 0;
		system("pause");
		
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: FATURAMENTOS DI�RIO DA UNIDADE");
		printf("\n\n\tDeseja buscar o relat�rio de outro dia? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez ==1);
}

void relatorioFaturamentoUnidadeMensal(){
	
	FILE *agendamentos;
	
	do{	
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: FATURAMENTOS MENSAIS DA UNIDADE");
		printf("\n\n\tInsira a unidade da qual deseja ver o relat�rio (A, B ou C): ");
		fflush(stdin); 
		fgets(unidade, 10, stdin); 
		unidade[strcspn (unidade, "\n\000")] = '\000'; 
		if(strcmp(unidade,unidadeA) != 0 && strcmp(unidade,unidadeB) != 0 && strcmp(unidade,unidadeC) != 0){ 
			printf("\tUnidade inserida inv�lida/n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tInsira a data da qual deseja o relat�rio:\n\tM�s (Ex: 8): ");
		scanf("%d", &mes);
		if(mes <1 || mes >12){ //verifica se o mes � entre 1 e 12 (afinal, n�o existe mes 0 nem 13)
			printf("\tM�s inserido n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tAno (EX: 2020): ");
		scanf("%d", &ano);
		
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: FATURAMENTOS MENSAIS DA UNIDADE");
			
		agendamentos = fopen("Agendamentos.txt","r");
		do{ 
			int t = fscanf(agendamentos," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %d %d %d %d %[^\n] %f", unidadeVerific, nomeVerific, rgVerific, cpfVerific, telefoneVerific, emailVerific, &diaVerific, &mesVerific, &anoVerific, &horaVerific, &minutoVerific, nomeMedicoVerific, &valorConsultaVerific);
			if(t == EOF){
				verificacaoValidez = 1;
				break; 
			}else{
				verificacaoValidez = 2;
			}
			if(strcmp(unidade,unidadeVerific) == 0 && mes == mesVerific && ano == anoVerific){
				printf("\n\n\tUnidade: %s", unidadeVerific);
				printf("\n\tNome do paciente: %s", nomeVerific);
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
				printf("\n\tM�dico(a)/enfermeiro(a) que atendendeu: %s", nomeMedicoVerific);
				printf("\n\tValor da consulta: R$ %.2f", valorConsultaVerific);
			
				valorTotal += valorConsultaVerific;
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(agendamentos);
		
		printf("\n\n\tO faturamento mensal total da unidade %s no m�s ", unidade);
		if(mes >= 10){ 
			printf("%d/%d", mes, ano);
		}else if(mes < 10){
			printf("0%d/%d", mes, ano);
		}
		printf(" foi: R$ %.2f\n\t", valorTotal);
		valorTotal = 0;
		system("pause");
		
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: FATURAMENTOS MENSAIS DA UNIDADE");
		printf("\n\n\tDeseja buscar o relat�rio de outro m�s? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez ==1);
}

void relatorioFaturamentoRedeDiario(){
	
	FILE *agendamentos;
	
	do{
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: FATURAMENTO DI�RIO DA REDE");
		printf("\n\n\tInsira a data da qual deseja o relat�rio:\n\tDia (Ex: 8): ");
		scanf("%d", &dia);
		if(dia <1 || dia >31){ //verifica se o dia � entre 1 e 31 (afinal, n�o existe dia 0 nem 32)
			printf("\tDia inserido n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tMes (Ex: 5): ");
		scanf("%d", &mes);
		if(mes <1 || mes >12){ //verifica se o mes � entre 1 e 12 (afinal, n�o existe mes 0 nem 13)
			printf("\tM�s inserido n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tAno (Ex: 2020): ");
		scanf("%d", &ano);
		
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: FATURAMENTO DI�RIO DA REDE");
			
		agendamentos = fopen("Agendamentos.txt","r");
		do{ 
			int t = fscanf(agendamentos," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %d %d %d %d %[^\n] %f", unidadeVerific, nomeVerific, rgVerific, cpfVerific, telefoneVerific, emailVerific, &diaVerific, &mesVerific, &anoVerific, &horaVerific, &minutoVerific, nomeMedicoVerific, &valorConsultaVerific);
			if(t == EOF){ 
				verificacaoValidez = 1;
				break; //se acabou, quebra o do...while e segue em frente
			}else{
				verificacaoValidez = 2;
			}
			if(dia == diaVerific && mes == mesVerific && ano == anoVerific){
				printf("\n\n\tUnidade: %s", unidadeVerific);
				printf("\n\tNome do paciente: %s", nomeVerific);
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
				printf("\n\tM�dico(a)/enfermeiro(a) que atendendeu: %s", nomeMedicoVerific);
				printf("\n\tValor da consulta: R$ %.2f", valorConsultaVerific);
				
				valorTotal += valorConsultaVerific; 
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(agendamentos);
		
		printf("\n\n\tO faturamento di�rio total da rede no dia ");
		if(mes >= 10 && dia >= 10){ 
			printf("%d/%d/%d", dia, mes, ano);
		}else if(mes < 10 && dia >= 10){
			printf("%d/0%d/%d", dia, mes, ano);
		}else if(mes < 10 && dia < 10){
			printf("0%d/0%d/%d", dia, mes, ano);
		}else if(mes >= 10 && dia < 10){
			printf("0%d/%d/%d", dia, mes, ano);
		}
		printf(" foi: R$ %.2f\n\t", valorTotal);
		valorTotal = 0;
		system("pause");
		
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: FATURAMENTOS DI�RIO DA REDE");
		printf("\n\n\tDeseja buscar o relat�rio de outro dia? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez ==1);
}

void relatorioFaturamentoRedeMensal(){
	
	FILE *agendamentos;
	
	do{	
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: FATURAMENTOS MENSAIS DA REDE");
		printf("\n\n\tInsira a data da qual deseja o relat�rio:\n\tM�s (Ex: 8): ");
		scanf("%d", &mes);
		if(mes <1 || mes >12){ //verifica se o mes � entre 1 e 12 (afinal, n�o existe mes 0 nem 13)
			printf("\tM�s inserido n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tAno (EX: 2020): ");
		scanf("%d", &ano);
		
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: FATURAMENTOS MENSAIS DA REDE");
			
		agendamentos = fopen("Agendamentos.txt","r");
		do{ 
			int t = fscanf(agendamentos," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %d %d %d %d %[^\n] %f", unidadeVerific, nomeVerific, rgVerific, cpfVerific, telefoneVerific, emailVerific, &diaVerific, &mesVerific, &anoVerific, &horaVerific, &minutoVerific, nomeMedicoVerific, &valorConsultaVerific);
			if(t == EOF){
				verificacaoValidez = 1;
				break; 
			}else{
				verificacaoValidez = 2;
			}
			if(mes == mesVerific && ano == anoVerific){
				printf("\n\n\tUnidade: %s", unidadeVerific);
				printf("\n\tNome do paciente: %s", nomeVerific);
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
				printf("\n\tM�dico(a)/enfermeiro(a) que atendendeu: %s", nomeMedicoVerific);
				printf("\n\tValor da consulta: R$ %.2f", valorConsultaVerific);
			
				valorTotal += valorConsultaVerific;
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(agendamentos);
		
		printf("\n\n\tO faturamento mensal total da rede no m�s ");
		if(mes >= 10){ 
			printf("%d/%d", mes, ano);
		}else if(mes < 10){
			printf("0%d/%d", mes, ano);
		}
		printf(" foi: R$ %.2f\n\t", valorTotal);
		valorTotal = 0;
		system("pause");
		
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: FATURAMENTOS MENSAIS DA UNIDADE");
		printf("\n\n\tDeseja buscar o relat�rio de outro m�s? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez ==1);
}

void relatorioGastosUnidadeDiario(){
	
	FILE *gastos;
	
	do{
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: GASTOS DI�RIO DA UNIDADE");
		printf("\n\n\tInsira a unidade da qual deseja ver o relat�rio (A, B ou C): ");
		fflush(stdin); //limpa o input para evitar erros
		fgets(unidade, 10, stdin); //recebe input do usu�rio
		unidade[strcspn (unidade, "\n\000")] = '\000'; //remove o \n da informa��o inserida pelo usu�rio, afim de comparar essa informa��o inserida com a informa��o lida do arquivo corretamente
		if(strcmp(unidade,unidadeA) != 0 && strcmp(unidade,unidadeB) != 0 && strcmp(unidade,unidadeC) != 0){ //verifica se a unidade inserida � A, B ou C, e se n�o for nenhuma das 3, retorna um erro e reseta a tela
			printf("\tUnidade inserida inv�lida/n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tInsira a data da qual deseja o relat�rio:\n\tDia (EX: 8): ");
		scanf("%d", &dia);
		if(dia <1 || dia >31){ //verifica se o dia � entre 1 e 31 (afinal, n�o existe dia 0 nem 32)
			printf("\tDia inserido n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tMes (EX: 5): ");
		scanf("%d", &mes);
		if(mes <1 || mes >12){ //verifica se o mes � entre 1 e 12 (afinal, n�o existe mes 0 nem 13)
			printf("\tM�s inserido n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tAno (EX: 2020): ");
		scanf("%d", &ano);
		
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: GASTOS DI�RIO DA UNIDADE");
			
		gastos = fopen("Gastos.txt","r");
		do{ //loop para leitura dos dados do arquivo Gastos.txt
			int t = fscanf(gastos," %[^\n] %[^\n] %f %d %d %d", unidadeVerific, nomeGastoVerific, &valorGastoVerific, &diaVerific, &mesVerific, &anoVerific); //leitura dos dados do arquivo Gastos.txt
			if(t == EOF){ //verifica se o arquivo acabou (EOF = End Of File)
				verificacaoValidez = 1;
				break; //se acabou, quebra o do...while e segue em frente
			}else{
				verificacaoValidez = 2;
			}
			if(strcmp(unidade,unidadeVerific) == 0 && dia == diaVerific && mes == mesVerific && ano == anoVerific){ //compara as informa��es inseridas com as informa��es do arquivo
				printf("\n\n\tUnidade: %s\n\tNome do gasto: %s\n\tValor do gasto: R$ %.2f", unidadeVerific, nomeGastoVerific, valorGastoVerific); //printa os dados do arquivo na tela para todos os gastos da unidade e dia inserido pelo usuario
				if(mes >= 10 && dia >= 10){ //verifica��o com prop�sito totalmente est�tico
					printf("\n\tData do gasto: %d/%d/%d", dia, mes, ano);
				}else if(mes >= 10 && dia >= 10){
					printf("\n\tData do gasto: %d/0%d/%d", dia, mes, ano);
				}else if(mes >= 10 && dia >= 10){
					printf("\n\tData do gasto: 0%d/0%d/%d", dia, mes, ano);
				}else if(mes >= 10 && dia >= 10){
					printf("\n\tData do gasto: 0%d/%d/%d", dia, mes, ano);
				}
				valorTotal += valorGastoVerific; //c�lculo dos gastos totais do dia inserido pelo usu�rio
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(gastos);
		
		printf("\n\n\tO gasto di�rio total da unidade %s no dia ", unidade);
		if(mes >= 10 && dia >= 10){ //verifica��o com prop�sito totalmente est�tico
			printf("%d/%d/%d", dia, mes, ano);
		}else if(mes < 10 && dia >= 10){
			printf("%d/0%d/%d", dia, mes, ano);
		}else if(mes < 10 && dia < 10){
			printf("0%d/0%d/%d", dia, mes, ano);
		}else if(mes >= 10 && dia < 10){
			printf("0%d/%d/%d", dia, mes, ano);
		}
		printf(" foi: R$ %.2f\n\t", valorTotal);
		valorTotal = 0;
		system("pause");
		
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: GASTOS DI�RIO DA UNIDADE");
		printf("\n\n\tDeseja buscar o relat�rio de outro dia? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez ==1);
}

void relatorioGastosUnidadeMensal(){
	
	FILE *gastos;
	
	do{
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: GASTOS MENSAIS DA UNIDADE");
		printf("\n\n\tInsira a unidade da qual deseja ver o relat�rio (A, B ou C): ");
		fflush(stdin); //limpa o input para evitar erros
		fgets(unidade, 10, stdin); //recebe input do usu�rio
		unidade[strcspn (unidade, "\n\000")] = '\000'; //remove o \n da informa��o inserida pelo usu�rio, afim de comparar essa informa��o inserida com a informa��o lida do arquivo corretamente
		if(strcmp(unidade,unidadeA) != 0 && strcmp(unidade,unidadeB) != 0 && strcmp(unidade,unidadeC) != 0){ //verifica se a unidade inserida � A, B ou C, e se n�o for nenhuma das 3, retorna um erro e reseta a tela
			printf("\tUnidade inserida inv�lida/n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tInsira a data da qual deseja o relat�rio:\n\tM�s (EX: 8): ");
		scanf("%d", &mes);
		if(mes <1 || mes >12){ //verifica se o mes � entre 1 e 12 (afinal, n�o existe mes 0 nem 13)
			printf("\tM�s inserido n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tAno (EX: 2020): ");
		scanf("%d", &ano);
		
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: GASTOS MENSAIS DA UNIDADE");
			
		gastos = fopen("Gastos.txt","r");
		do{ //loop para leitura dos dados do arquivo Gastos.txt
			int t = fscanf(gastos," %[^\n] %[^\n] %f %d %d %d", unidadeVerific, nomeGastoVerific, &valorGastoVerific, &diaVerific, &mesVerific, &anoVerific); //leitura dos dados do arquivo Gastos.txt
			if(t == EOF){ //verifica se o arquivo acabou (EOF = End Of File)
				verificacaoValidez = 1;
				break; //se acabou, quebra o do...while e segue em frente
			}else{
				verificacaoValidez = 2;
			}
			if(strcmp(unidade,unidadeVerific) == 0 && mes == mesVerific && ano == anoVerific){ //compara as informa��es inseridas com as informa��es do arquivo
				printf("\n\n\tUnidade: %s\n\tNome do gasto: %s\n\tValor do gasto: R$ %.2f", unidadeVerific, nomeGastoVerific, valorGastoVerific); //printa os dados do arquivo na tela para todos os gastos da unidade e dia inserido pelo usuario
				if(mes >= 10 && diaVerific >= 10){ //verifica��o com prop�sito totalmente est�tico
					printf("\n\tData do gasto: %d/%d/%d", diaVerific, mes, ano);
				}else if(mes >= 10 && diaVerific >= 10){
					printf("\n\tData do gasto: %d/0%d/%d", diaVerific, mes, ano);
				}else if(mes >= 10 && diaVerific >= 10){
					printf("\n\tData do gasto: 0%d/0%d/%d", diaVerific, mes, ano);
				}else if(mes >= 10 && diaVerific >= 10){
					printf("\n\tData do gasto: 0%d/%d/%d", diaVerific, mes, ano);
				}
				valorTotal += valorGastoVerific; //c�lculo dos gastos totais do dia inserido pelo usu�rio
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(gastos);
		
		printf("\n\n\tO gasto mensal total da unidade %s no m�s ", unidade);
		if(mes >= 10){ //verifica��o com prop�sito totalmente est�tico
			printf("%d/%d", mes, ano);
		}else if(mes < 10){
			printf("0%d/%d", mes, ano);
		}
		printf(" foi: R$ %.2f\n\t", valorTotal);
		valorTotal = 0;
		system("pause");
		
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: GASTOS MENSAIS DA UNIDADE");
		printf("\n\n\tDeseja buscar o relat�rio de outro m�s? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez ==1);
}

void relatorioGastosRedeDiario(){
	
	FILE *gastos;
	
	do{
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: GASTOS DI�RIO DA REDE");
		printf("\n\n\tInsira a data da qual deseja o relat�rio:\n\tDia (EX: 8): ");
		scanf("%d", &dia);
		if(dia <1 || dia >31){ //verifica se o dia � entre 1 e 31 (afinal, n�o existe dia 0 nem 32)
			printf("\tDia inserido n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tMes (EX: 5): ");
		scanf("%d", &mes);
		if(mes <1 || mes >12){ //verifica se o mes � entre 1 e 12 (afinal, n�o existe mes 0 nem 13)
			printf("\tM�s inserido n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tAno (EX: 2020): ");
		scanf("%d", &ano);
		
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: GASTOS DI�RIO DA REDE");
			
		gastos = fopen("Gastos.txt","r");
		do{ //loop para leitura dos dados do arquivo Gastos.txt
			int t = fscanf(gastos," %[^\n] %[^\n] %f %d %d %d", unidadeVerific, nomeGastoVerific, &valorGastoVerific, &diaVerific, &mesVerific, &anoVerific); //leitura dos dados do arquivo Gastos.txt
			if(t == EOF){ //verifica se o arquivo acabou (EOF = End Of File)
				verificacaoValidez = 1;
				break; //se acabou, quebra o do...while e segue em frente
			}else{
				verificacaoValidez = 2;
			}
			if(dia == diaVerific && mes == mesVerific && ano == anoVerific){
				printf("\n\n\tUnidade: %s\n\tNome do gasto: %s\n\tValor do gasto: R$ %.2f", unidadeVerific, nomeGastoVerific, valorGastoVerific);
				if(mes >= 10 && dia >= 10){ //verifica��o com prop�sito totalmente est�tico
					printf("\n\tData do gasto: %d/%d/%d", dia, mes, ano);
				}else if(mes >= 10 && dia >= 10){
					printf("\n\tData do gasto: %d/0%d/%d", dia, mes, ano);
				}else if(mes >= 10 && dia >= 10){
					printf("\n\tData do gasto: 0%d/0%d/%d", dia, mes, ano);
				}else if(mes >= 10 && dia >= 10){
					printf("\n\tData do gasto: 0%d/%d/%d", dia, mes, ano);
				}
				valorTotal += valorGastoVerific;
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(gastos);
		
		printf("\n\n\tO gasto di�rio total da rede no dia ");
		if(mes >= 10 && dia >= 10){ //verifica��o com prop�sito totalmente est�tico
			printf("%d/%d/%d", dia, mes, ano);
		}else if(mes < 10 && dia >= 10){
			printf("%d/0%d/%d", dia, mes, ano);
		}else if(mes < 10 && dia < 10){
			printf("0%d/0%d/%d", dia, mes, ano);
		}else if(mes >= 10 && dia < 10){
			printf("0%d/%d/%d", dia, mes, ano);
		}
		printf(" foi: R$ %.2f\n\t", valorTotal);
		valorTotal = 0;
		system("pause");
		
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: GASTOS DI�RIO DA REDE");
		printf("\n\n\tDeseja buscar o relat�rio de outro dia? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez ==1);
}

void relatorioGastosRedeMensal(){
	
	FILE *gastos;
	
	do{
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: GASTOS MENSAIS DA REDE");
		printf("\n\n\tInsira a data da qual deseja o relat�rio:\n\tM�s (EX: 8): ");
		scanf("%d", &mes);
		if(mes <1 || mes >12){ //verifica se o mes � entre 1 e 12 (afinal, n�o existe mes 0 nem 13)
			printf("\tM�s inserido n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		printf("\tAno (EX: 2020): ");
		scanf("%d", &ano);
		
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: GASTOS MENSAIS DA UNIDADE");
			
		gastos = fopen("Gastos.txt","r");
		do{
			int t = fscanf(gastos," %[^\n] %[^\n] %f %d %d %d", unidadeVerific, nomeGastoVerific, &valorGastoVerific, &diaVerific, &mesVerific, &anoVerific);
			if(t == EOF){
				verificacaoValidez = 1;
				break;
			}else{
				verificacaoValidez = 2;
			}
			if(mes == mesVerific && ano == anoVerific){
				printf("\n\n\tUnidade: %s\n\tNome do gasto: %s\n\tValor do gasto: R$ %.2f", unidadeVerific, nomeGastoVerific, valorGastoVerific);
				if(mes >= 10 && diaVerific >= 10){ //verifica��o com prop�sito totalmente est�tico
					printf("\n\tData do gasto: %d/%d/%d", diaVerific, mes, ano);
				}else if(mes >= 10 && diaVerific >= 10){
					printf("\n\tData do gasto: %d/0%d/%d", diaVerific, mes, ano);
				}else if(mes >= 10 && diaVerific >= 10){
					printf("\n\tData do gasto: 0%d/0%d/%d", diaVerific, mes, ano);
				}else if(mes >= 10 && diaVerific >= 10){
					printf("\n\tData do gasto: 0%d/%d/%d", diaVerific, mes, ano);
				}
				valorTotal += valorGastoVerific;
				verificacaoValidez = 2;
			}
		}while(verificacaoValidez != 1);
		fclose(gastos);
		
		printf("\n\n\tO gasto mensal total da rede no m�s ");
		if(mes >= 10){ //verifica��o com prop�sito totalmente est�tico
			printf("%d/%d", mes, ano);
		}else if(mes < 10){
			printf("0%d/%d", mes, ano);
		}
		printf(" foi: R$ %.2f\n\t", valorTotal);
		valorTotal = 0;
		system("pause");
		
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: GASTOS MENSAIS DA REDE");
		printf("\n\n\tDeseja buscar o relat�rio de outro m�s? Se sim, digite 1, e se n�o, digite 2: ");
		scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez ==1);
}

void relatorioRankingAtendimentos(){
	
	FILE *agendamentos;
			
	system("cls");
	printf("\n\tTELA DE RELAT�RIO: RANKING DE ATENDIMENTO DAS UNIDADES");
	a = 0;
	b = 0;
	c = 0;
	
	agendamentos = fopen("Agendamentos.txt","r");
	do{
		int t = fscanf(agendamentos," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %d %d %d %d %[^\n] %f", unidadeVerific, nomeVerific, rgVerific, cpfVerific, telefoneVerific, emailVerific, &diaVerific, &mesVerific, &anoVerific, &horaVerific, &minutoVerific, nomeMedicoVerific, &valorConsultaVerific);
		if(t == EOF){
			verificacaoValidez = 1;
			break; 
		}else{
		verificacaoValidez = 2;
		printf("\n\n\tUnidade: %s", unidadeVerific);
		printf("\n\tNome do paciente: %s", nomeVerific);
		printf("\n\tRG do paciente: %s", rgVerific);
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
		}
		if(strcmp(unidadeVerific, unidadeA) == 0){
			a++;
		}else if(strcmp(unidadeVerific, unidadeB) == 0){
			b++;
		}else if(strcmp(unidadeVerific, unidadeC) == 0){
			c++;
		}
	}while(verificacaoValidez != 1);
	fclose(agendamentos);
	
	if(mediaA>mediaB && mediaA>mediaC){
		printf("\n\n\t1� Lugar - Unidade A: %d", a);
		if(b>c){
			printf("\n\t2� Lugar - Unidade B: %d", b);
			printf("\n\t3� Lugar - Unidade C: %d\n\n\t", c);
		}else if(c>b){
			printf("\n\t2� Lugar - Unidade C: %d", c);
			printf("\n\t3� Lugar - Unidade B: %d\n\n\t", b);
		}
	}else if(b>a && b>c){
		printf("\n\n\t1� Lugar - Unidade B: %d", b);
		if(a>c){
			printf("\n\t2� Lugar - Unidade A: %d", a);
			printf("\n\t3� Lugar - Unidade C: %d\n\n\t", c);
		}else if(c>a){
			printf("\n\t2� Lugar - Unidade C: %d", c);
			printf("\n\t3� Lugar - Unidade A: %d\n\n\t", a);
		}
	}else{
		printf("\n\n\t1� Lugar - Unidade C: %d", c);
		if(a>b){
			printf("\n\t2� Lugar - Unidade A: %d", a);
			printf("\n\t3� Lugar - Unidade B: %d\n\n\t", b);
		}else if(b>a){
			printf("\n\t2� Lugar - Unidade B: %d", b);
			printf("\n\t3� Lugar - Unidade A: %d\n\n\t", a);
		}
	}
	
	a = 0;
	b = 0;
	c = 0;
	
	system("pause");
}

void relatorioNotaRede(){
	
	FILE *avaliacao;
	
	system("cls");
	printf("\n\tTELA DE RELAT�RIO : M�DIA DA NOTA DA REDE");
	i = 0;
	
	avaliacao = fopen("Avaliacoes.txt","r");
		do{ 
			int t = fscanf(avaliacao," %[^\n] %[^\n] %[^\n] %d %[^\n] %d %d %d", unidadeVerific, nomeVerific, rgVerific, &notaAvaliacaoVerific, regAvaliacaoVerific, &diaVerific, &mesVerific, &anoVerific);
			if(t == EOF){
				verificacaoValidez = 1;
				break; 
			}else{
				verificacaoValidez = 2;
			}
			printf("\n\n\tUnidade: %s", unidadeVerific);
			printf("\n\tNome do paciente: %s", nomeVerific);
			printf("\n\tRG: %s", rgVerific);
			printf("\n\tNota: %d", notaAvaliacaoVerific);
			printf("\n\tAvalia��o registrada: %s", regAvaliacaoVerific);
			if(mesVerific >= 10 && diaVerific >= 10){
				printf("\n\tData da avalia��o: %d/%d/%d", diaVerific, mesVerific, anoVerific);
			}else if(mesVerific < 10 && diaVerific >= 10){
				printf("\n\tData da avalia��o: %d/0%d/%d", diaVerific, mesVerific, anoVerific);
			}else if(mesVerific < 10 && diaVerific < 10){
				printf("\n\tData da avalia��o: 0%d/0%d/%d", diaVerific, mesVerific, anoVerific);
			}else if(mesVerific >= 10 && diaVerific < 10){
				printf("\n\tData da avalia��o: 0%d/%d/%d", diaVerific, mesVerific, anoVerific);
			}
			valorTotal += notaAvaliacaoVerific;
			i++;
		}while(verificacaoValidez != 1);
		fclose(avaliacao);
		
		media = valorTotal/i;
		
		printf("\n\n\tA m�dia da nota da rede �: %.1f", media);
		valorTotal = 0;
		media = 0;
		
		printf("\n\n\t");
		system("pause");
	
}

void relatorioNotaUnidade(){
	
	FILE *avaliacao;
	
	do{
		
		system("cls");
		printf("\n\tTELA DE RELAT�RIO: M�DIA DA NOTA DA UNIDADE");
		printf("\n\n\tInsira a unidade da qual deseja ver o relat�rio (A, B ou C): ");
		fflush(stdin); 
		fgets(unidade, 10, stdin); 
		unidade[strcspn (unidade, "\n\000")] = '\000'; 
		if(strcmp(unidade,unidadeA) != 0 && strcmp(unidade,unidadeB) != 0 && strcmp(unidade,unidadeC) != 0){ 
			printf("\tUnidade inserida inv�lida/n�o existe, tente novamente\n\t");
			system("pause");
			continue;
		}
		
		system("cls");
		printf("\n\tTELA DE RELAT�RIO : M�DIA DA NOTA DA UNIDADE");
		i = 0;
		
		avaliacao = fopen("Avaliacoes.txt","r");
			do{ 
				int t = fscanf(avaliacao," %[^\n] %[^\n] %[^\n] %d %[^\n] %d %d %d", unidadeVerific, nomeVerific, rgVerific, &notaAvaliacaoVerific, regAvaliacaoVerific, &diaVerific, &mesVerific, &anoVerific);
				if(t == EOF){
					verificacaoValidez = 1;
					break; 
				}else{
					verificacaoValidez = 2;
				}if(strcmp(unidade,unidadeVerific) == 0){
					printf("\n\n\tUnidade: %s", unidadeVerific);
					printf("\n\tNome do paciente: %s", nomeVerific);
					printf("\n\tRG: %s", rgVerific);
					printf("\n\tNota: %d", notaAvaliacaoVerific);
					printf("\n\tAvalia��o registrada: %s", regAvaliacaoVerific);
					if(mesVerific >= 10 && diaVerific >= 10){
						printf("\n\tData da avalia��o: %d/%d/%d", diaVerific, mesVerific, anoVerific);
					}else if(mesVerific < 10 && diaVerific >= 10){
						printf("\n\tData da avalia��o: %d/0%d/%d", diaVerific, mesVerific, anoVerific);
					}else if(mesVerific < 10 && diaVerific < 10){
						printf("\n\tData da avalia��o: 0%d/0%d/%d", diaVerific, mesVerific, anoVerific);
					}else if(mesVerific >= 10 && diaVerific < 10){
						printf("\n\tData da avalia��o: 0%d/%d/%d", diaVerific, mesVerific, anoVerific);
					}
					valorTotal += notaAvaliacaoVerific;
					i++;
				}
			}while(verificacaoValidez != 1);
			fclose(avaliacao);
			
			media = valorTotal/i;
			
			printf("\n\n\tA m�dia da nota da unidade %s �: %.1f\n\t", unidade, media);
			valorTotal = 0;
			media = 0;
			system("pause");
			
			system("cls");
			printf("\n\tTELA DE RELAT�RIO: M�DIA DA NOTA DA UNIDADE");
			printf("\n\n\tDeseja buscar o relat�rio de outra unidade? Se sim, digite 1, e se n�o, digite 2: ");
			scanf("%d", &verificacaoValidez);
	}while(verificacaoValidez == 1);
}

void relatorioRankingNota(){
	
	FILE *avaliacao;
			
	system("cls");
	printf("\n\tTELA DE RELAT�RIO: RANKING DE NOTA DAS UNIDADES");
	a = 0;
	b = 0;
	c = 0;
	
	avaliacao = fopen("Avaliacoes.txt","r");
		do{ 
			int t = fscanf(avaliacao," %[^\n] %[^\n] %[^\n] %d %[^\n] %d %d %d", unidadeVerific, nomeVerific, rgVerific, &notaAvaliacaoVerific, regAvaliacaoVerific, &diaVerific, &mesVerific, &anoVerific);
			if(t == EOF){
				verificacaoValidez = 1;
				break; 
			}else{
			verificacaoValidez = 2;
			printf("\n\n\tUnidade: %s", unidadeVerific);
			printf("\n\tNome do paciente: %s", nomeVerific);
			printf("\n\tRG: %s", rgVerific);
			printf("\n\tNota: %d", notaAvaliacaoVerific);
			printf("\n\tAvalia��o registrada: %s", regAvaliacaoVerific);
			}
			if(mesVerific >= 10 && diaVerific >= 10){
				printf("\n\tData da avalia��o: %d/%d/%d", diaVerific, mesVerific, anoVerific);
			}else if(mesVerific < 10 && diaVerific >= 10){
				printf("\n\tData da avalia��o: %d/0%d/%d", diaVerific, mesVerific, anoVerific);
			}else if(mesVerific < 10 && diaVerific < 10){
				printf("\n\tData da avalia��o: 0%d/0%d/%d", diaVerific, mesVerific, anoVerific);
			}else if(mesVerific >= 10 && diaVerific < 10){
				printf("\n\tData da avalia��o: 0%d/%d/%d", diaVerific, mesVerific, anoVerific);
			}
			if(strcmp(unidadeVerific, unidadeA) == 0){
				notaTotalA += notaAvaliacaoVerific;
				a++;
			}else if(strcmp(unidadeVerific, unidadeB) == 0){
				notaTotalB += notaAvaliacaoVerific;
				b++;
			}else if(strcmp(unidadeVerific, unidadeC) == 0){
				notaTotalC += notaAvaliacaoVerific;
				c++;
			}
		}while(verificacaoValidez != 1);
		fclose(avaliacao);
		
		mediaA = notaTotalA/a;		
		mediaB = notaTotalB/b;		
		mediaC = notaTotalC/c;
		
		if(mediaA>mediaB && mediaA>mediaC){
			printf("\n\n\t1� Lugar - Unidade A: %.1f", mediaA);
			if(mediaB>mediaC){
				printf("\n\t2� Lugar - Unidade B: %.1f", mediaB);
				printf("\n\t3� Lugar - Unidade C: %.1f\n\n\t", mediaC);
			}else if(mediaC>mediaB){
				printf("\n\t2� Lugar - Unidade C: %.1f", mediaC);
				printf("\n\t3� Lugar - Unidade B: %.1f\n\n\t", mediaB);
			}
		}else if(mediaB>mediaA && mediaB>mediaC){
			printf("\n\n\t1� Lugar - Unidade B: %.1f", mediaB);
			if(mediaA>mediaC){
				printf("\n\t2� Lugar - Unidade A: %.1f", mediaA);
				printf("\n\t3� Lugar - Unidade C: %.1f\n\n\t", mediaC);
			}else if(mediaC>mediaA){
				printf("\n\t2� Lugar - Unidade C: %.1f", mediaC);
				printf("\n\t3� Lugar - Unidade A: %.1f\n\n\t", mediaA);
			}
		}else{
			printf("\n\n\t1� Lugar - Unidade C: %.1f", mediaC);
			if(mediaA>mediaB){
				printf("\n\t2� Lugar - Unidade A: %.1f", mediaA);
				printf("\n\t3� Lugar - Unidade B: %.1f\n\n\t", mediaB);
			}else if(mediaB>mediaA){
				printf("\n\t2� Lugar - Unidade B: %.1f", mediaB);
				printf("\n\t3� Lugar - Unidade A: %.1f\n\n\t", mediaA);
			}
		}
		
		mediaA = 0, notaTotalA = 0, a = 0;
		mediaB = 0, notaTotalB = 0, b = 0;
		mediaC = 0, notaTotalC = 0, c = 0;
		
		system("pause");
}
