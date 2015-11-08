/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _YPPASSWD_H_RPCGEN
#define _YPPASSWD_H_RPCGEN

#define RPCGEN_VERSION	199506

#include <rpc/rpc.h>


struct x_passwd {
	char *pw_name;
	char *pw_passwd;
	int pw_uid;
	int pw_gid;
	char *pw_gecos;
	char *pw_dir;
	char *pw_shell;
};
typedef struct x_passwd x_passwd;
#ifdef __cplusplus
extern "C" bool_t xdr_x_passwd(XDR *, x_passwd*);
#elif __STDC__
extern  bool_t xdr_x_passwd(XDR *, x_passwd*);
#else /* Old Style C */
bool_t xdr_x_passwd();
#endif /* Old Style C */


struct yppasswd {
	char *oldpass;
	x_passwd newpw;
};
typedef struct yppasswd yppasswd;
#ifdef __cplusplus
extern "C" bool_t xdr_yppasswd(XDR *, yppasswd*);
#elif __STDC__
extern  bool_t xdr_yppasswd(XDR *, yppasswd*);
#else /* Old Style C */
bool_t xdr_yppasswd();
#endif /* Old Style C */


#define YPPASSWDPROG ((u_long)100009)
#define YPPASSWDVERS ((u_long)1)

#ifdef __cplusplus
#define YPPASSWDPROC_UPDATE ((u_long)1)
extern "C" int * yppasswdproc_update_1(yppasswd *, CLIENT *);
extern "C" int * yppasswdproc_update_1_svc(yppasswd *, struct svc_req *);

#elif __STDC__
#define YPPASSWDPROC_UPDATE ((u_long)1)
extern  int * yppasswdproc_update_1(yppasswd *, CLIENT *);
extern  int * yppasswdproc_update_1_svc(yppasswd *, struct svc_req *);

#else /* Old Style C */
#define YPPASSWDPROC_UPDATE ((u_long)1)
extern  int * yppasswdproc_update_1();
extern  int * yppasswdproc_update_1_svc();
#endif /* Old Style C */

#endif /* !_YPPASSWD_H_RPCGEN */
