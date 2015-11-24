/* 
   +----------------------------------------------------------------------+
   | PHP Version 5                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2008 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: The typical suspects                                        |
   |          Marcus Boerger <helly@php.net>                              |
   |          Pollita <pollita@php.net>                                   |
   +----------------------------------------------------------------------+
*/

/* $Id: dns.h,v 1.19.2.1.2.1.2.6 2009/05/19 19:39:53 jani Exp $ */

#ifndef DNS_H
#define DNS_H

#if HAVE_RES_MKQUERY && !defined(HAVE_RES_NMKQUERY) && HAVE_RES_SEND && !defined(HAVE_RES_NSEND)
#define HAVE_DEPRECATED_DNS_FUNCS 1
#endif

#if HAVE_DEPRECATED_DNS_FUNCS
#define res_nmkquery(res, op, dname, class, type, data, datalen, newrr, buf, buflen) \
	res_mkquery(op, dname, class, type, data, datalen, newrr, buf, buflen)
#define res_nsend(res, msg, msglen, answer, anslen) \
	res_send(msg, msglen, answer, anslen);
#define res_nclose(res) /* noop */
#endif

#if ((HAVE_RES_NMKQUERY && HAVE_RES_NSEND) || HAVE_DEPRECATED_DNS_FUNCS) && HAVE_DN_EXPAND && HAVE_DN_SKIPNAME
#define HAVE_DNS_FUNCS 1
#endif

PHP_FUNCTION(gethostbyaddr);
PHP_FUNCTION(gethostbyname);
PHP_FUNCTION(gethostbynamel);

#ifdef HAVE_GETHOSTNAME
PHP_FUNCTION(gethostname);
#endif

#if defined(PHP_WIN32) || (HAVE_RES_SEARCH && !(defined(__BEOS__) || defined(NETWARE)))
PHP_FUNCTION(dns_check_record);
# if defined(PHP_WIN32) || (HAVE_DN_SKIPNAME && HAVE_DN_EXPAND)
PHP_FUNCTION(dns_get_mx);
# endif

#if defined(PHP_WIN32) || HAVE_DNS_FUNCS
PHP_FUNCTION(dns_get_record);
PHP_MINIT_FUNCTION(dns);
# endif

#endif /* defined(PHP_WIN32) || (HAVE_RES_SEARCH && !(defined(__BEOS__) || defined(NETWARE))) */

#ifndef INT16SZ
#define INT16SZ		2
#endif

#ifndef INT32SZ
#define INT32SZ		4
#endif

#endif /* DNS_H */
