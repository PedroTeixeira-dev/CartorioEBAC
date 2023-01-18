#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocação de texto por região
#include <string.h> // Biblioteca responsavel por cuidar das strings

 int registro() //criando um funcao para cada opcao. Registrando as informacoes
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Voce escolheu o registro de nomes\n"); 
		
		
		printf("Digite o CPF a ser cadastrado:");
		scanf("%s", cpf);
		
		strcpy(arquivo,cpf); // responsavel por copiar o valor das strings
				
		FILE *file; // comando para os arquivos. criando o arquivo
		file = fopen(arquivo, "w"); //abrir um arquivo, que se chama "arquivo" e escrever nele("w")
		fprintf(file,"CPF:");
		fprintf(file, cpf); // salvo o valor da variavel
		fprintf(file,"\n");
		fclose(file); // fecho o arquivo
		
		printf("Digite o nome a ser cadastrado:");
		scanf("%s",nome);
		
		file = fopen(arquivo, "a");
		fprintf(file,"Nome:");
		fprintf(file, nome);
		fprintf(file, "\n");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado:");
		scanf("%s",sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file, "Sobrenome:");
		fprintf(file, sobrenome);
		fprintf(file,"\n");
		fclose(file);
		
		printf("Digite o cargo:");
		scanf("%s", cargo);
				
		file = fopen(arquivo, "a");
		fprintf(file,"Cargo:");
		fprintf(file, cargo);
		fprintf(file, "\n");
		fclose(file);
					
}
		

 int consulta() //criando um funcao para cada opcao
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	
	printf("Você escolheu consultar nomes\n"); 
		
		printf("Digite o CPF que deseja consultar:\n");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL)
		{
			printf("Não foi possíovel abrir o arquivo, não localizado. \n\n");	
			system("pause");		}	
			
		else {	
			
			printf("Essas são as informações do usuário: \n\n");
			while(fgets(conteudo, 200, file) != NULL)		
		{			
			printf("%s", conteudo);
			printf("\n");			
		}		
			system("pause");				
			}
}
 
 int deletar() //criando um funcao para cada opcao
{
	char cpf[40];
	
	
	printf("Você escolheu deletar nomes\n"); 
		
	printf("Digite o CPF do usuario que deseja deletar: ");
	scanf("%s", cpf);
	printf("\n");
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);		

	if(file != NULL)
	{
		remove(cpf);
		printf("Usuario deletado com sucesso!\n\n");		
		system("pause");
	}
	
	else
	{
		printf("O usuario nao se encontra no sistema.\n\n");
		system("pause");
	
	}	
	
	
	
}

 int main()
 {
 	int opcao=0;
 	int laco=1;
 	
 	for(laco=1;laco=1;)
 	{
	 
	 	system("cls");
	 
 		setlocale(LC_ALL,"Portuguese"); // Definindo o idioma
 	
 		printf("        Cartório da EBAC \n\n");
 		printf("Escolha a opção desejada do menu:\n\n");
 		printf("\t1 - Registrar nomes\n");
 		printf("\t2 - Consultar nomes \n");
 		printf("\t3 - Deletar nomes\n\n");
 	
 		printf("Opcao:");
	 
		scanf("%d",&opcao); //Lendo a opção do usuario
	
	 	system("cls"); //limpando o programa para a tela nao ficar poluida
	 	
	 	switch(opcao) //começando o sistema de escolha de opção
	 	{
	 		case 1:
	 			registro();
	 			break;
	 			
	 		case 2:
			 	consulta();
	 			break;
	 			
	 		case 3:
			 	deletar();
	 			break;
	 			
	 		default:
	 			printf("Escolha inválida \n");
	 			system("pause"); 
			 	break;
		 }
	 	
	}
 }
 
 
