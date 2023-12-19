#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <stdlib.h> //biblioteca de oloca��o de espa�o em mem�ria 
#include <string.h> //biblioteca respons�vel por cuidar das string
 
 
int registro() //Fun��o responsavel por registrar os usu�rios no sistema
{
	//inicio cria��o de variaveis/string
	char cpf[40];
	char nome[40];
	char cargo[40];
	char arquivo[40];	
	char sobrenome[40];
	//final da cria��o de variaveis/string
	
	printf("Informe o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s referece a string /armazenar string
	
	strcpy(arquivo , cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria um arquivo
	file = fopen(arquivo, "w"); //cria um arquivo e o "w" significa escrever
	fprintf(file,cpf); //fprintf salva o arquivo/salvar arquivo na variavel cpf
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //acessar e incluir mais informa��es
	fprintf(file,","); //salvar no arquivo "file"
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //incluir arquivo
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");

}

int consulta() //fun��o respon�vel por consultar us�ario no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char cpf[40];
    char conteudo[200];
   
    printf("Digite o cpf a ser consultado: ");
    scanf("%s",cpf); //Armazenando a variavel "cpf" utilizando a fun��o string "%s"
    
    FILE *file; //consultar arquivo(abrir)
    file = fopen(cpf,"r"); //Abre o arquivo CPF e "R" de Read para "ler" a informa��o
    
    if(file == NULL) //Se a informa��o n�o existir traz a seguinte mensagem
    {
    	printf("\nN�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //(while) enquanto tiver informa�o, armazene a informa��o em conteudo se for diferente de NULL (nulo)
	{
 		printf("\nEssas s�o as informa��es do usu�rio: \n");//informa��o que vai aparecer antes dos dados
 		printf("%s", conteudo);
 		printf("\n\n"); //Comando utilizado para quebra de linha
    }

	system("pause");

    }  
	
int deletar() //fun��o respons�vel por deletar us�ario do sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
		
	FILE *file; //acessar arquivo
	file = fopen(cpf, "r"); //ler o cpf
	
	if(file == NULL) //caso o arquivo n�o for encontrado mostrar a seguinte informa��o para o usu�rio
	{
		printf("\nUsu�rio n�o encontrado no sistema!.\n\n");
		system("pause");
	}
	
	remove(cpf); //remover arquivo
	
	if(file != NULL) //cpf encontrado e deletado com sucesso (!=) diferente de "n�o encontrado"
	{
		printf("\nUsu�rio deletado com sucesso! \n\n");
		system("pause");
	}

}

int main() //Fun��o principal do menu
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) //criando la�o de repeti��o 
	{
	   system("cls"); //limpa a tela
	   
	   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	   printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	   printf("Escolha a op��o desejada do menu:\n\n");
       printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n");
	   printf("\t4 - Sair do sitema\n\n");
	   printf("Op��o: "); //fim do menu
	
	   scanf("%d" , &opcao); //armezando a escolha do usu�rio
	
	   system("cls");
	   
	switch(opcao) //(switch)escolha
	   {
	   	    case 1:
	   		registro(); //chamada da fun��o
	        break;
	        
			case 2: 
			consulta(); //chamda da fun��o consulta
	        break;
	        
	        case 3:
	        deletar(); //chamada da fun��o deletar
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema!\n");
		    return 0;
		    break;
		    	
		    default:
		    printf("Essa opcao n�o est� disponivel!\n"); 
		    system("pause"); 
			break; 
		    //fim da sele��o	
	   }
    }
}

