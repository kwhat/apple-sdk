/*
     File:       CFNetwork/CFSocketStream.h
 
     Contains:   CoreFoundation Network socket streams header
 
     Version:    CFNetwork-71.2~1
 
     Copyright:  � 2001-2003 by Apple Computer, Inc., all rights reserved
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFSOCKETSTREAM__
#define __CFSOCKETSTREAM__

#ifndef __CFSTREAM__
#include <CoreFoundation/CFStream.h>
#endif

#ifndef __CFHOST__
#include <CFNetwork/CFHost.h>
#endif

#ifndef __CFNETSERVICES__
#include <CFNetwork/CFNetServices.h>
#endif




#include <AvailabilityMacros.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if PRAGMA_ENUM_ALWAYSINT
    #pragma enumsalwaysint on
#endif

/*
 *  kCFStreamErrorDomainSSL
 *  
 *  Discussion:
 *    Errors located in Security/SecureTransport.h
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const int kCFStreamErrorDomainSSL;


/*
 *  kCFStreamPropertySocketSecurityLevel
 *  
 *  Discussion:
 *    Stream property key, for both set and copy operations. To set a
 *    stream to be secure, call CFReadStreamSetProperty or
 *    CFWriteStreamSetPropertywith the property name set to
 *    kCFStreamPropertySocketSecurityLevel and the value being one of
 *    the following values.  Streams may set a security level after
 *    open in order to allow on-the-fly securing of a stream.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertySocketSecurityLevel;


/*
 *  kCFStreamSocketSecurityLevelNone
 *  
 *  Discussion:
 *    Stream property value, for both set and copy operations.
 *    Indicates to use no security (default setting).
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamSocketSecurityLevelNone;


/*
 *  kCFStreamSocketSecurityLevelSSLv2
 *  
 *  Discussion:
 *    Stream property value, for both set and copy operations.
 *    Indicates to use SSLv2 security.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamSocketSecurityLevelSSLv2;


/*
 *  kCFStreamSocketSecurityLevelSSLv3
 *  
 *  Discussion:
 *    Stream property value, for both set and copy operations.
 *    Indicates to use SSLv3 security.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamSocketSecurityLevelSSLv3;


/*
 *  kCFStreamSocketSecurityLevelTLSv1
 *  
 *  Discussion:
 *    Stream property value, for both set and copy operations.
 *    Indicates to use TLSv1 security.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamSocketSecurityLevelTLSv1;


/*
 *  kCFStreamSocketSecurityLevelNegotiatedSSL
 *  
 *  Discussion:
 *    Stream property value, for both set and copy operations.
 *    Indicates to use TLS or SSL with fallback to lower versions. This
 *    is what HTTPS does, for instance.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamSocketSecurityLevelNegotiatedSSL;


/*
 *  kCFStreamErrorDomainSOCKS
 *  
 *  Discussion:
 *    SOCKS proxy error domain.  Errors formulated using inlines below.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const int kCFStreamErrorDomainSOCKS;



CF_INLINE
SInt32 CFSocketStreamSOCKSGetErrorSubdomain(CFStreamError* error) {
    return ((error->domain >> 16) & 0x0000FFFF);
}

CF_INLINE
SInt32 CFSocketStreamSOCKSGetError(CFStreamError* error) {
    return (error->domain & 0x0000FFFF);
}

enum {
  kCFStreamErrorSOCKSSubDomainNone = 0, /* Error code is a general SOCKS error*/
  kCFStreamErrorSOCKSSubDomainVersionCode = 1, /* Error code is the version of SOCKS which the server wishes to use*/
  kCFStreamErrorSOCKS4SubDomainResponse = 2, /* Error code is the status code returned by the server*/
  kCFStreamErrorSOCKS5SubDomainUserPass = 3, /* Error code is the status code that the server returned*/
  kCFStreamErrorSOCKS5SubDomainMethod = 4, /* Error code is the server's desired negotiation method*/
  kCFStreamErrorSOCKS5SubDomainResponse = 5 /* Error code is the response code that the server returned in reply to the connection request*/
};


/* kCFStreamErrorSOCKSSubDomainNone*/
enum {
  kCFStreamErrorSOCKS5BadResponseAddr = 1,
  kCFStreamErrorSOCKS5BadState  = 2,
  kCFStreamErrorSOCKSUnknownClientVersion = 3
};

/* kCFStreamErrorSOCKS4SubDomainResponse*/
enum {
  kCFStreamErrorSOCKS4RequestFailed = 91, /* request rejected or failed */
  kCFStreamErrorSOCKS4IdentdFailed = 92, /* request rejected because SOCKS server cannot connect to identd on the client */
  kCFStreamErrorSOCKS4IdConflict = 93   /* request rejected because the client program and identd report different user-ids */
};

/* kCFStreamErrorSOCKS5SubDomainMethod*/
enum {
  kSOCKS5NoAcceptableMethod     = 0xFF  /* other values indicate the server's desired method */
};



/*
 *  kCFStreamPropertySOCKSProxy
 *  
 *  Discussion:
 *    Stream property key, for both set and copy operations.  To set a
 *    stream to use a SOCKS proxy, call CFReadStreamSetProperty or
 *    CFWriteStreamSetProperty with the property name set to
 *    kCFStreamPropertySOCKSProxy and the value being a dictionary with
 *    at least the following two keys: kCFStreamPropertySOCKSProxyHost
 *    and kCFStreamPropertySOCKSProxyPort.  The dictionary returned by
 *    SystemConfiguration for SOCKS proxies will work without
 *    alteration.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertySOCKSProxy;

/*
 *  kCFStreamPropertySOCKSProxyHost
 *  
 *  Discussion:
 *    CFDictinary key for SOCKS proxy information.  The key
 *    kCFStreamPropertySOCKSProxyHost should contain a CFStringRef
 *    value representing the SOCKS proxy host.  Defined to match
 *    kSCPropNetProxiesSOCKSProxy
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertySOCKSProxyHost;

/*
 *  kCFStreamPropertySOCKSProxyPort
 *  
 *  Discussion:
 *    CFDictinary key for SOCKS proxy information.  The key
 *    kCFStreamPropertySOCKSProxyPort should contain a CFNumberRef
 *    which itself is of type kCFNumberSInt32Type.  This value should
 *    represent the port on which the proxy is listening.  Defined to
 *    match kSCPropNetProxiesSOCKSPort
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertySOCKSProxyPort;

/*
 *  kCFStreamPropertySOCKSVersion
 *  
 *  Discussion:
 *    CFDictinary key for SOCKS proxy information.  By default, SOCKS5
 *    will be used unless there is a kCFStreamPropertySOCKSVersion key
 *    in the dictionary.  Its value must be
 *    kCFStreamSocketSOCKSVersion4 or kCFStreamSocketSOCKSVersion5 to
 *    set SOCKS4 or SOCKS5, respectively.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertySOCKSVersion;

/*
 *  kCFStreamSocketSOCKSVersion4
 *  
 *  Discussion:
 *    CFDictionary value for SOCKS proxy information.  Indcates that
 *    SOCKS will or is using version 4 of the SOCKS protocol.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamSocketSOCKSVersion4;

/*
 *  kCFStreamSocketSOCKSVersion5
 *  
 *  Discussion:
 *    CFDictionary value for SOCKS proxy information.  Indcates that
 *    SOCKS will or is using version 5 of the SOCKS protocol.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamSocketSOCKSVersion5;

/*
 *  kCFStreamPropertySOCKSUser
 *  
 *  Discussion:
 *    CFDictinary key for SOCKS proxy information.  To set a user name
 *    and/or password, if required, the dictionary must contain the
 *    key(s) kCFStreamPropertySOCKSUser and/or  
 *    kCFStreamPropertySOCKSPassword with the value being the user's
 *    name as a CFStringRef and/or the user's password as a
 *    CFStringRef, respectively.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertySOCKSUser;

/*
 *  kCFStreamPropertySOCKSPassword
 *  
 *  Discussion:
 *    CFDictinary key for SOCKS proxy information.  To set a user name
 *    and/or password, if required, the dictionary must contain the
 *    key(s) kCFStreamPropertySOCKSUser and/or  
 *    kCFStreamPropertySOCKSPassword with the value being the user's
 *    name as a CFStringRef and/or the user's password as a
 *    CFStringRef, respectively.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertySOCKSPassword;


/*
 *  kCFStreamPropertyShouldCloseNativeSocket
 *  
 *  Discussion:
 *    Set the value to kCFBooleanTrue if the stream should close and
 *    release the underlying native socket when the stream is released.
 *     Set the value to kCFBooleanFalse to keep the native socket from
 *    closing and releasing when the stream is released. If the stream
 *    was created with a native socket, the default property setting on
 *    the stream is kCFBooleanFalse. The
 *    kCFStreamPropertyShouldCloseNativeSocket can be set through
 *    CFReadStreamSetProperty or CFWriteStreamSetProperty.  The
 *    property can be copied through CFReadStreamCopyProperty or
 *    CFWriteStreamCopyProperty.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertyShouldCloseNativeSocket;


/*
 *  kCFStreamPropertySocketRemoteHost
 *  
 *  Discussion:
 *    Stream property key for copy operations. Returns a CFHostRef if
 *    known, otherwise NULL.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertySocketRemoteHost           AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  kCFStreamPropertySocketRemoteNetService
 *  
 *  Discussion:
 *    Stream property key for copy operations. Returns a
 *    CFNetServiceRef if known, otherwise NULL.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertySocketRemoteNetService     AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  CFStreamCreatePairWithSocketToCFHost()
 *  
 *  Discussion:
 *    Given a CFHostRef, this function will create a pair of streams
 *    suitable for connecting to the host.  If there is a failure
 *    during creation, the stream references will be set to NULL.
 *  
 *  Mac OS X threading:
 *    Thread safe
 *  
 *  Parameters:
 *    
 *    alloc:
 *      The CFAllocator which should be used to allocate memory for the
 *      streams. If this reference is not a valid CFAllocator, the
 *      behavior is undefined.
 *    
 *    host:
 *      A reference to a CFHost to which the streams are desired.  If
 *      unresolved, the host will be resolved prior to connecting.
 *    
 *    port:
 *      The port to which the connection should be established.
 *    
 *    readStream:
 *      A pointer to a CFReadStreamRef which will be set to the new
 *      read stream instance.  Can be set to NULL if not desired.
 *    
 *    writeStream:
 *      A pointer to a CFWriteStreamRef which will be set to the new
 *      write stream instance.  Can be set to NULL if not desired.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
CFStreamCreatePairWithSocketToCFHost(
  CFAllocatorRef      alloc,
  CFHostRef           host,
  UInt32              port,
  CFReadStreamRef *   readStream,        /* can be NULL */
  CFWriteStreamRef *  writeStream)       /* can be NULL */    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  CFStreamCreatePairWithSocketToNetService()
 *  
 *  Discussion:
 *    Given a CFNetService, this function will create a pair of streams
 *    suitable for connecting to the service.  If there is a failure
 *    during creation, the stream references will be set to NULL.
 *  
 *  Mac OS X threading:
 *    Thread safe
 *  
 *  Parameters:
 *    
 *    alloc:
 *      The CFAllocator which should be used to allocate memory for the
 *      streams. If this reference is not a valid CFAllocator, the
 *      behavior is undefined.
 *    
 *    service:
 *      A reference to a CFNetService to which the streams are desired.
 *       If unresolved, the service will be resolved prior to
 *      connecting.
 *    
 *    readStream:
 *      A pointer to a CFReadStreamRef which will be set to the new
 *      read stream instance.  Can be set to NULL if not desired.
 *    
 *    writeStream:
 *      A pointer to a CFWriteStreamRef which will be set to the new
 *      write stream instance.  Can be set to NULL if not desired.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern void 
CFStreamCreatePairWithSocketToNetService(
  CFAllocatorRef      alloc,
  CFNetServiceRef     service,
  CFReadStreamRef *   readStream,        /* can be NULL */
  CFWriteStreamRef *  writeStream)       /* can be NULL */    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;




/*
 *  CFStreamSocketSecurityProtocol
 *  
 *  Discussion:
 *    These enum values and CFSocketStreamPairSetSecurityProtocol have
 *    been deprecated in favor of CFReadStreamSetProperty and
 *    CFWriteStreamSetProperty with the previously mentioned property
 *    and values.
 */
enum CFStreamSocketSecurityProtocol {

  /*
   * DEPRECATED, use kCFStreamSocketSecurityLevelNone
   */
  kCFStreamSocketSecurityNone   = 0,

  /*
   * DEPRECATED, use kCFStreamSocketSecurityLevelSSLv2
   */
  kCFStreamSocketSecuritySSLv2  = 1,

  /*
   * DEPRECATED, use kCFStreamSocketSecurityLevelSSLv3
   */
  kCFStreamSocketSecuritySSLv3  = 2,

  /*
   * DEPRECATED, use kCFStreamSocketSecurityLevelNegotiatedSSL
   */
  kCFStreamSocketSecuritySSLv23 = 3,

  /*
   * DEPRECATED, use kCFStreamSocketSecurityLevelTLSv1
   */
  kCFStreamSocketSecurityTLSv1  = 4
};
typedef enum CFStreamSocketSecurityProtocol CFStreamSocketSecurityProtocol;

/*
 *  CFSocketStreamPairSetSecurityProtocol()   *** DEPRECATED ***
 *  
 *  Discussion:
 *    CFSocketStreamPairSetSecurityProtocol has been deprecated in
 *    favor of CFReadStreamSetProperty and CFWriteStreamSetProperty
 *    with the previously mentioned property and values.  Sets the
 *    security level on a pair of streams.
 *  
 *  Mac OS X threading:
 *    Thread safe
 *  
 *  Parameters:
 *    
 *    socketReadStream:
 *      Read stream reference which is to have its security level
 *      changed.
 *    
 *    socketWriteStream:
 *      Write stream reference which is to have its security level
 *      changed.
 *    
 *    securityProtocol:
 *      CFStreamSocketSecurityProtocol enum indicating the security
 *      level to be set.
 *  
 *  Result:
 *    Returns TRUE if the settings were placed on the stream, FALSE
 *    otherwise.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in CoreServices.framework but deprecated in 10.2
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern Boolean 
CFSocketStreamPairSetSecurityProtocol(
  CFReadStreamRef                  socketReadStream,
  CFWriteStreamRef                 socketWriteStream,
  CFStreamSocketSecurityProtocol   securityProtocol)          AVAILABLE_MAC_OS_X_VERSION_10_1_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_2;



#if PRAGMA_ENUM_ALWAYSINT
    #pragma enumsalwaysint reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CFSOCKETSTREAM__ */

