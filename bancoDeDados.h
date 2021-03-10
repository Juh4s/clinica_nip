void exibirAgendamentos(){
	
	FILE *agendamentos;
	
	system("cls");
	printf("\n\tBANCO DE DADOS: AGENDAMENTOS");
	
	agendamentos = fopen("Agendamentos.txt","r");
		do{ 
			int t = fscanf(agendamentos," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %d %d %d %d %[^\n] %f", unidadeVerific, nomeVerific, rgVerific, cpfVerific, telefoneVerific, emailVerific, &diaVerific, &mesVerific, &anoVerific, &horaVerific, &minutoVerific, nomeMedicoVerific, &valorConsultaVerific);
			if(t == EOF){
				verificacaoValidez = 1;
				break; 
			}else{
				verificacaoValidez = 2;
			}			
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
				printf("\n\tHorário da consulta: %d:%d", horaVerific, minutoVerific);
			}else if(horaVerific < 10 && minutoVerific != 0){
				printf("\n\tHorário da consulta: 0%d:%d", horaVerific, minutoVerific);
			}else if(horaVerific < 10 && minutoVerific == 0){
				printf("\n\tHorário da consulta: 0%d:0%d", horaVerific, minutoVerific);
			}else if(horaVerific >= 10 && minutoVerific == 0){
				printf("\n\tHorário da consulta: %d:0%d", horaVerific, minutoVerific);
			}
			printf("\n\tMédico(a)/enfermeiro(a) que atendendeu: %s", nomeMedicoVerific);
			printf("\n\tValor da consulta: R$ %.2f", valorConsultaVerific);
			
		}while(verificacaoValidez != 1);
		fclose(agendamentos);
		
		printf("\n\n\t");
		system("pause");
	
}

void exibirAvaliacoes(){
	
	FILE *avaliacao;
	
	system("cls");
	printf("\n\tBANCO DE DADOS: AVALIAÇÕES");
	
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
		}while(verificacaoValidez != 1);
		fclose(avaliacao);
		
		printf("\n\n\t");
		system("pause");
	
}

void exibirFuncionarios(){
	
	FILE *funcionarios;
	
	system("cls");
	printf("\n\tBANCO DE DADOS: FUNCIONÁRIOS");
	
	funcionarios = fopen("Funcionarios.txt","r");
		do{ 
			int t = fscanf(funcionarios," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %[^\n] %[^\n] %[^\n] %d %[^\n] %d %[^\n] %[^\n] %[^\n] %f", unidadeVerific, nomeVerific, generoVerific, rgVerific, cpfVerific, &idadeVerific, ufVerific, cidadeVerific, enderecoVerific, &numeroVerific, casaOuPredioVerific, &apartamentoVerific, cepVerific, telefoneVerific, profissaoVerific, &salarioVerific);
			if(t == EOF){
				verificacaoValidez = 1;
				break; 
			}else{
				verificacaoValidez = 2;
			}
			printf("\n\n\tUnidade: %s", unidadeVerific);
			printf("\n\tNome do(a) funcionário(a): %s", nomeVerific);
			printf("\n\tGenero: %s", generoVerific);
			printf("\n\tRG: %s", rgVerific);
			printf("\n\tCPF: %s", cpfVerific);
			printf("\n\tIdade: %d", idadeVerific);
			printf("\n\tEstado: %s", ufVerific);
			printf("\n\tCidade: %s", cidadeVerific);
			printf("\n\tEndereço: %s", enderecoVerific);
			printf("\n\tNúmero: %d", numeroVerific);
			printf("\n\tTipo de residência: %s", casaOuPredioVerific);
			if(strcmp(casaOuPredioVerific, predio) == 0){
				printf("\n\tApartamento: %d", apartamentoVerific);
			}
			printf("\n\tCEP: %s", cepVerific);
			printf("\n\tTelefone: %s", telefoneVerific);
			printf("\n\tProfissão: %s", profissaoVerific);
			printf("\n\tSalário: R$ %.2f", salarioVerific);
		}while(verificacaoValidez != 1);
		fclose(funcionarios);
		
		printf("\n\n\t");
		system("pause");
	
}

void exibirGastos(){

	FILE *gastos;
	
	system("cls");
	printf("\n\tBANCO DE DADOS: FUNCIONÁRIOS");
	
	gastos = fopen("Gastos.txt","r");
		do{ 
			int t = fscanf(gastos," %[^\n] %[^\n] %f %d %d %d", unidadeVerific, nomeGastoVerific, &valorGastoVerific, &diaVerific, &mesVerific, &anoVerific);
			if(t == EOF){
				verificacaoValidez = 1;
				break; 
			}else{
				verificacaoValidez = 2;
			}
			printf("\n\n\tUnidade: %s\n\tNome do gasto: %s\n\tValor do gasto: R$ %.2f", unidadeVerific, nomeGastoVerific, valorGastoVerific);
			if(mes >= 10 && diaVerific >= 10){ //verificação com propósito totalmente estético
				printf("\n\tData do gasto: %d/%d/%d", diaVerific, mes, ano);
			}else if(mes >= 10 && diaVerific >= 10){
				printf("\n\tData do gasto: %d/0%d/%d", diaVerific, mes, ano);
			}else if(mes >= 10 && diaVerific >= 10){
				printf("\n\tData do gasto: 0%d/0%d/%d", diaVerific, mes, ano);
			}else if(mes >= 10 && diaVerific >= 10){
				printf("\n\tData do gasto: 0%d/%d/%d", diaVerific, mes, ano);
			}
		}while(verificacaoValidez != 1);
		fclose(gastos);
		
		printf("\n\n\t");
		system("pause");

}

void exibirPacientes(){

	FILE *pacientes;
	
	system("cls");
	printf("\n\tBANCO DE DADOS: FUNCIONÁRIOS");
	
	pacientes = fopen("Pacientes.txt","r");
		do{ 
			int t = fscanf(pacientes," %[^\n] %[^\n] %[^\n] %[^\n] %d %[^\n] %[^\n] %[^\n] %d %[^\n] %d %[^\n] %[^\n] %[^\n]", nomeVerific, generoVerific, rgVerific, cpfVerific, &idadeVerific, ufVerific, cidadeVerific, enderecoVerific, &numeroVerific, casaOuPredioVerific, &apartamentoVerific, cepVerific, telefoneVerific, religiaoVerific);
			if(t == EOF){
				verificacaoValidez = 1;
				break; 
			}else{
				verificacaoValidez = 2;
			}
			printf("\n\n\tNome do paciente: %s", nomeVerific);
			printf("\n\tGenero: %s", generoVerific);
			printf("\n\tRG: %s", rgVerific);
			printf("\n\tCPF: %s", cpfVerific);
			printf("\n\tIdade: %d", idadeVerific);
			printf("\n\tEstado: %s", ufVerific);
			printf("\n\tCidade: %s", cidadeVerific);
			printf("\n\tEndereço: %s", enderecoVerific);
			printf("\n\tNúmero: %d", numeroVerific);
			printf("\n\tTipo de residência: %s", casaOuPredioVerific);
			if(strcmp(casaOuPredioVerific, predio) == 0){
				printf("\n\tApartamento: %d", apartamentoVerific);
			}
			printf("\n\tCEP: %s", cepVerific);
			printf("\n\tTelefone: %s", telefoneVerific);
			printf("\n\tReligião: %s", religiaoVerific);
		}while(verificacaoValidez != 1);
		fclose(pacientes);
		
		printf("\n\n\t");
		system("pause");

}
