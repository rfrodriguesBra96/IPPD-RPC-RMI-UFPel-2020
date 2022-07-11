/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _GETTOKEN_H_RPCGEN
#define _GETTOKEN_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct token {
	int token;
	int aux;
};
typedef struct token token;

#define GETTOKEN_PROG 987654321
#define GETTOKEN_VERSION 1

#if defined(__STDC__) || defined(__cplusplus)
#define GTOKEN 1
extern  int * gtoken_1(token *, CLIENT *);
extern  int * gtoken_1_svc(token *, struct svc_req *);
#define LIBERTA 2
extern  int * liberta_1(token *, CLIENT *);
extern  int * liberta_1_svc(token *, struct svc_req *);
extern int gettoken_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define GTOKEN 1
extern  int * gtoken_1();
extern  int * gtoken_1_svc();
#define LIBERTA 2
extern  int * liberta_1();
extern  int * liberta_1_svc();
extern int gettoken_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_token (XDR *, token*);

#else /* K&R C */
extern bool_t xdr_token ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_GETTOKEN_H_RPCGEN */