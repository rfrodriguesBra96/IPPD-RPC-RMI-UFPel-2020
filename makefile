
#targets
all: start compcliente compservidor

start: gettoken.x cliente.c servico.c
	rpcgen gettoken.x 

compcliente: cliente.c gettoken_xdr.c gettoken_clnt.c
	gcc cliente.c gettoken_xdr.c gettoken_clnt.c -o cliente

compservidor: servico.c gettoken_xdr.c gettoken_svc.c
	gcc servico.c gettoken_xdr.c gettoken_svc.c -o servico

clean:
	 $(RM) core gettoken_clnt.c gettoken_xdr.c gettoken.h gettoken_svc.c
