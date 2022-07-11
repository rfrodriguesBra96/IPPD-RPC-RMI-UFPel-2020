/* Implementação do procedimento remoto "printmessage" */
#include <stdio.h>
#include "gettoken.h" /* msg.h gerado por rpcgen */
token token_global;
int flag = 0; /* Controla o primeiro acesso ao servidor */

int * gtoken_1_svc (token *argp, struct svc_req *rqstp)
{
	printf("Recebeu uma chamda de um cliente.\n");
	/* 
	 * Verifica se é o primeiro acesso.
	 * flag == 0, então é first acesso.
	 */
	//printf("Valor de flag: %d\n", flag);
	if(flag == 0){
		printf("Primeiro acesso.\n");
		token_global.token = 1; /* Libera o acesso a token. */
		flag = 1; /* Sinaliza que foi feito o first acesso. */
	}

	/* Preserva o valor fora do escopo */
	static int result;
	
	/* Verifica se há um token disponível. */
	if(token_global.token == 1){
		//printf("Token disponível.\n");
		result = 1;
		token_global.token = 0; /* Não há mais token disponível. */
		return(&result); /* Retorna TRUE */
	}

	/* Não há token disponível. */
	if(!token_global.token){
		//printf("Token indisponível.\n"); 
		result = 0; 
		return(&result); /* Retorna FALSE */
	}

}


int * liberta_1_svc(token *argp, struct svc_req *rqstp){
	static int result;
	token_global.token = 1;
	result = 1;
	return(&result);
}
