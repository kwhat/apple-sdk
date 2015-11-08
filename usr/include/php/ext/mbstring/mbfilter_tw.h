/*
   +----------------------------------------------------------------------+
   | PHP Version 4                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 2001 The PHP Group                                     |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.02 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available at through the world-wide-web at                           |
   | http://www.php.net/license/2_02.txt.                                 |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Rui Hirokawa <hirokawa@php.net>                              |
   +----------------------------------------------------------------------+
 */


/* $Id: mbfilter_tw.h,v 1.1.1.1 2003/03/11 01:09:22 zarzycki Exp $ */

#ifndef MBFL_MBFILTER_TW_H
#define MBFL_MBFILTER_TW_H

int mbfl_filt_conv_euctw_wchar(int c, mbfl_convert_filter *filter TSRMLS_DC);
int mbfl_filt_conv_wchar_euctw(int c, mbfl_convert_filter *filter TSRMLS_DC);
int mbfl_filt_conv_big5_wchar(int c, mbfl_convert_filter *filter TSRMLS_DC);
int mbfl_filt_conv_wchar_big5(int c, mbfl_convert_filter *filter TSRMLS_DC);

#endif /* MBFL_MBFILTER_TW_H */
