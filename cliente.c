#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "gettoken.h"

int gtoken (CLIENT *clnt){

	token t_token;
	int *result, *teste, i;

	/* Cliente vai iterar 10 vzs. */
	for(i = 0; i < 10; i++){
		result = gtoken_1(&t_token, clnt);

		/*
		if(*result == 1){
			printf("Token disponível. Result é: %d\n", *result);
		}else{
			printf("Token indisponível. Result é %d\n", *result);
		}
		*/
		

		/* Verifica se houve algum erro de conexão. */
		if (result == NULL){
			printf("Problemas ao chamar a função remota! 'ERROR - NULL'\n");
			exit(1);
		}

		/* Há um token disponível. */
		if(*result == 1){
			printf("Iteração %d acesso permitido, token é TRUE.\n", i);
			sleep(3);
			liberta_1(&t_token, clnt);
			//printf("Result depois de liberado é: %d\n", *result);
		}

		/* Token indisponível (FALSE) */
		if(*result == 0){
			printf("Iteração %d acesso negado, token é FALSE.\n", i);
			int flag = 1;
			while(flag){
				result = gtoken_1(&t_token, clnt);
				/* Token disponível(TRUE) */
				if(*result == 1){
					printf("Iteração %d acesso permitido na iteração negada, token é TRUE.\n", i);
					liberta_1(&t_token, clnt);
					//printf("Result depois de liberado é: %d\n", *result);
					flag = 0;
				}		
			};	
		}
		sleep(2);
	}
	return (*result);
}

int main(int argc, char *argv[]){

	CLIENT *clnt;

	if(argc != 2){
		fprintf (stderr,"Usage: %s hostname token\n",argv[0]);
      	exit (1);
	}

	clnt = clnt_create (argv[1], GETTOKEN_PROG, GETTOKEN_VERSION, "udp");

    if (clnt == (CLIENT *) NULL)
	{
      clnt_pcreateerror (argv[1]);
      exit(1);
	}
 	
 	gtoken(clnt);
	
}
