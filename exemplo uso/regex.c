#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int compara(char *argv[], char *linha){
	/* aloca espaço para a estrutura do tipo regex_t */
	regex_t reg;
  	/* compila a ER passada em argv[1]
	* em caso de erro, a função retorna diferente de zero */
	if (regcomp(&reg , argv[1], REG_EXTENDED|REG_NOSUB|REG_ICASE) != 0) {
		fprintf(stderr,"Erro regcomp\n");
		exit(1);
	}
  
  	/* tenta comparar a Expressao Regular compilada (&reg) com a entrada (linha) 
  	* se a função regexec retornar 0 casou, caso contrário não */
	if ((regexec(&reg, linha, 0, (regmatch_t *)NULL, 0)) == 0){
    		puts(linha);
  	}	
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("Uso: compara <ExpReg> \n");
		return 1;
	}
  //puts(argv[1]); entrada
FILE *arq= fopen("entrada.txt", "r");
size_t len= 100; // valor arbitrário
char *linha= malloc(len);

	if (!arq)
	{
    		perror("entrada.txt");
    		exit(1);
	}
  	while (getline(&linha, &len, arq) > 0)
 	{
    		//printf("%s", linha);
    		compara(argv,linha);
	}
  	if (linha){
    		free(linha);
	}
fclose(arq);
return 0;
}
