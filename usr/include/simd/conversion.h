/*  Copyright (c) 2014 Apple, Inc. All rights reserved.
 *
 *  The interfaces declared in this header provide conversions between vector
 *  types.  The following functions are available:
 *
 *      vector_char(x)      vector_uchar(x)
 *      vector_short(x)     vector_ushort(x)
 *      vector_int(x)       vector_uint(x)
 *      vector_long(x)      vector_ulong(x)
 *      vector_float(x)
 *      vector_double(x)
 *
 *  Each of these functions converts x to a vector whose elements have the
 *  type named by the function, with the same number of elements as x.  Unlike
 *  a vector cast, these functions convert the elements to the new element
 *  type.  These conversions behave exactly as C scalar conversions, except
 *  that conversions from integer vector types to signed integer vector types
 *  are guaranteed to wrap modulo 2^N (where N is the number of bits in an
 *  element of the result type).
 *
 *  For integer vector types, saturating conversions are also available:
 *
 *      vector_char_sat(x)      vector_uchar_sat(x)
 *      vector_short_sat(x)     vector_ushort_sat(x)
 *      vector_int_sat(x)       vector_uint_sat(x)
 *      vector_long_sat(x)      vector_ulong_sat(x)
 *
 *  These conversions clamp x to the representable range of the result type
 *  before converting.
 *
 *  Unlike most vector operations in <simd/>, there are no abbreviated C++
 *  names for these fuctions in the simd:: namespace.
 */

#ifndef __SIMD_CONVERSION_HEADER__
#define __SIMD_CONVERSION_HEADER__

#include <simd/internal.h>
#if __SIMD_REQUIRED_COMPILER_FEATURES__
#include <simd/vector_types.h>
#include <simd/common.h>
#include <simd/logic.h>

#ifdef __cplusplus
extern "C" {
#endif

static vector_char2  __SIMD_ATTRIBUTES__ vector_char(vector_char2    __x);
static vector_char3  __SIMD_ATTRIBUTES__ vector_char(vector_char3    __x);
static vector_char4  __SIMD_ATTRIBUTES__ vector_char(vector_char4    __x);
static vector_char8  __SIMD_ATTRIBUTES__ vector_char(vector_char8    __x);
static vector_char16 __SIMD_ATTRIBUTES__ vector_char(vector_char16   __x);
static vector_char32 __SIMD_ATTRIBUTES__ vector_char(vector_char32   __x);
static vector_char2  __SIMD_ATTRIBUTES__ vector_char(vector_uchar2   __x);
static vector_char3  __SIMD_ATTRIBUTES__ vector_char(vector_uchar3   __x);
static vector_char4  __SIMD_ATTRIBUTES__ vector_char(vector_uchar4   __x);
static vector_char8  __SIMD_ATTRIBUTES__ vector_char(vector_uchar8   __x);
static vector_char16 __SIMD_ATTRIBUTES__ vector_char(vector_uchar16  __x);
static vector_char32 __SIMD_ATTRIBUTES__ vector_char(vector_uchar32  __x);
static vector_char2  __SIMD_ATTRIBUTES__ vector_char(vector_short2   __x);
static vector_char3  __SIMD_ATTRIBUTES__ vector_char(vector_short3   __x);
static vector_char4  __SIMD_ATTRIBUTES__ vector_char(vector_short4   __x);
static vector_char8  __SIMD_ATTRIBUTES__ vector_char(vector_short8   __x);
static vector_char16 __SIMD_ATTRIBUTES__ vector_char(vector_short16  __x);
static vector_char32 __SIMD_ATTRIBUTES__ vector_char(vector_short32  __x);
static vector_char2  __SIMD_ATTRIBUTES__ vector_char(vector_ushort2  __x);
static vector_char3  __SIMD_ATTRIBUTES__ vector_char(vector_ushort3  __x);
static vector_char4  __SIMD_ATTRIBUTES__ vector_char(vector_ushort4  __x);
static vector_char8  __SIMD_ATTRIBUTES__ vector_char(vector_ushort8  __x);
static vector_char16 __SIMD_ATTRIBUTES__ vector_char(vector_ushort16 __x);
static vector_char32 __SIMD_ATTRIBUTES__ vector_char(vector_ushort32 __x);
static vector_char2  __SIMD_ATTRIBUTES__ vector_char(vector_int2     __x);
static vector_char3  __SIMD_ATTRIBUTES__ vector_char(vector_int3     __x);
static vector_char4  __SIMD_ATTRIBUTES__ vector_char(vector_int4     __x);
static vector_char8  __SIMD_ATTRIBUTES__ vector_char(vector_int8     __x);
static vector_char16 __SIMD_ATTRIBUTES__ vector_char(vector_int16    __x);
static vector_char2  __SIMD_ATTRIBUTES__ vector_char(vector_uint2    __x);
static vector_char3  __SIMD_ATTRIBUTES__ vector_char(vector_uint3    __x);
static vector_char4  __SIMD_ATTRIBUTES__ vector_char(vector_uint4    __x);
static vector_char8  __SIMD_ATTRIBUTES__ vector_char(vector_uint8    __x);
static vector_char16 __SIMD_ATTRIBUTES__ vector_char(vector_uint16   __x);
static vector_char2  __SIMD_ATTRIBUTES__ vector_char(vector_float2   __x);
static vector_char3  __SIMD_ATTRIBUTES__ vector_char(vector_float3   __x);
static vector_char4  __SIMD_ATTRIBUTES__ vector_char(vector_float4   __x);
static vector_char8  __SIMD_ATTRIBUTES__ vector_char(vector_float8   __x);
static vector_char16 __SIMD_ATTRIBUTES__ vector_char(vector_float16  __x);
static vector_char2  __SIMD_ATTRIBUTES__ vector_char(vector_long2    __x);
static vector_char3  __SIMD_ATTRIBUTES__ vector_char(vector_long3    __x);
static vector_char4  __SIMD_ATTRIBUTES__ vector_char(vector_long4    __x);
static vector_char8  __SIMD_ATTRIBUTES__ vector_char(vector_long8    __x);
static vector_char2  __SIMD_ATTRIBUTES__ vector_char(vector_ulong2   __x);
static vector_char3  __SIMD_ATTRIBUTES__ vector_char(vector_ulong3   __x);
static vector_char4  __SIMD_ATTRIBUTES__ vector_char(vector_ulong4   __x);
static vector_char8  __SIMD_ATTRIBUTES__ vector_char(vector_ulong8   __x);
static vector_char2  __SIMD_ATTRIBUTES__ vector_char(vector_double2  __x);
static vector_char3  __SIMD_ATTRIBUTES__ vector_char(vector_double3  __x);
static vector_char4  __SIMD_ATTRIBUTES__ vector_char(vector_double4  __x);
static vector_char8  __SIMD_ATTRIBUTES__ vector_char(vector_double8  __x);
static vector_char2  __SIMD_ATTRIBUTES__ vector_char_sat(vector_char2    __x);
static vector_char3  __SIMD_ATTRIBUTES__ vector_char_sat(vector_char3    __x);
static vector_char4  __SIMD_ATTRIBUTES__ vector_char_sat(vector_char4    __x);
static vector_char8  __SIMD_ATTRIBUTES__ vector_char_sat(vector_char8    __x);
static vector_char16 __SIMD_ATTRIBUTES__ vector_char_sat(vector_char16   __x);
static vector_char32 __SIMD_ATTRIBUTES__ vector_char_sat(vector_char32   __x);
static vector_char2  __SIMD_ATTRIBUTES__ vector_char_sat(vector_short2   __x);
static vector_char3  __SIMD_ATTRIBUTES__ vector_char_sat(vector_short3   __x);
static vector_char4  __SIMD_ATTRIBUTES__ vector_char_sat(vector_short4   __x);
static vector_char8  __SIMD_ATTRIBUTES__ vector_char_sat(vector_short8   __x);
static vector_char16 __SIMD_ATTRIBUTES__ vector_char_sat(vector_short16  __x);
static vector_char32 __SIMD_ATTRIBUTES__ vector_char_sat(vector_short32  __x);
static vector_char2  __SIMD_ATTRIBUTES__ vector_char_sat(vector_int2     __x);
static vector_char3  __SIMD_ATTRIBUTES__ vector_char_sat(vector_int3     __x);
static vector_char4  __SIMD_ATTRIBUTES__ vector_char_sat(vector_int4     __x);
static vector_char8  __SIMD_ATTRIBUTES__ vector_char_sat(vector_int8     __x);
static vector_char16 __SIMD_ATTRIBUTES__ vector_char_sat(vector_int16    __x);
static vector_char2  __SIMD_ATTRIBUTES__ vector_char_sat(vector_float2   __x);
static vector_char3  __SIMD_ATTRIBUTES__ vector_char_sat(vector_float3   __x);
static vector_char4  __SIMD_ATTRIBUTES__ vector_char_sat(vector_float4   __x);
static vector_char8  __SIMD_ATTRIBUTES__ vector_char_sat(vector_float8   __x);
static vector_char16 __SIMD_ATTRIBUTES__ vector_char_sat(vector_float16  __x);
static vector_char2  __SIMD_ATTRIBUTES__ vector_char_sat(vector_long2    __x);
static vector_char3  __SIMD_ATTRIBUTES__ vector_char_sat(vector_long3    __x);
static vector_char4  __SIMD_ATTRIBUTES__ vector_char_sat(vector_long4    __x);
static vector_char8  __SIMD_ATTRIBUTES__ vector_char_sat(vector_long8    __x);
static vector_char2  __SIMD_ATTRIBUTES__ vector_char_sat(vector_double2  __x);
static vector_char3  __SIMD_ATTRIBUTES__ vector_char_sat(vector_double3  __x);
static vector_char4  __SIMD_ATTRIBUTES__ vector_char_sat(vector_double4  __x);
static vector_char8  __SIMD_ATTRIBUTES__ vector_char_sat(vector_double8  __x);
static vector_char2  __SIMD_ATTRIBUTES__ vector_char_sat(vector_uchar2   __x);
static vector_char3  __SIMD_ATTRIBUTES__ vector_char_sat(vector_uchar3   __x);
static vector_char4  __SIMD_ATTRIBUTES__ vector_char_sat(vector_uchar4   __x);
static vector_char8  __SIMD_ATTRIBUTES__ vector_char_sat(vector_uchar8   __x);
static vector_char16 __SIMD_ATTRIBUTES__ vector_char_sat(vector_uchar16  __x);
static vector_char32 __SIMD_ATTRIBUTES__ vector_char_sat(vector_uchar32  __x);
static vector_char2  __SIMD_ATTRIBUTES__ vector_char_sat(vector_ushort2  __x);
static vector_char3  __SIMD_ATTRIBUTES__ vector_char_sat(vector_ushort3  __x);
static vector_char4  __SIMD_ATTRIBUTES__ vector_char_sat(vector_ushort4  __x);
static vector_char8  __SIMD_ATTRIBUTES__ vector_char_sat(vector_ushort8  __x);
static vector_char16 __SIMD_ATTRIBUTES__ vector_char_sat(vector_ushort16 __x);
static vector_char32 __SIMD_ATTRIBUTES__ vector_char_sat(vector_ushort32 __x);
static vector_char2  __SIMD_ATTRIBUTES__ vector_char_sat(vector_uint2    __x);
static vector_char3  __SIMD_ATTRIBUTES__ vector_char_sat(vector_uint3    __x);
static vector_char4  __SIMD_ATTRIBUTES__ vector_char_sat(vector_uint4    __x);
static vector_char8  __SIMD_ATTRIBUTES__ vector_char_sat(vector_uint8    __x);
static vector_char16 __SIMD_ATTRIBUTES__ vector_char_sat(vector_uint16   __x);
static vector_char2  __SIMD_ATTRIBUTES__ vector_char_sat(vector_ulong2   __x);
static vector_char3  __SIMD_ATTRIBUTES__ vector_char_sat(vector_ulong3   __x);
static vector_char4  __SIMD_ATTRIBUTES__ vector_char_sat(vector_ulong4   __x);
static vector_char8  __SIMD_ATTRIBUTES__ vector_char_sat(vector_ulong8   __x);

static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar(vector_char2    __x);
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar(vector_char3    __x);
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar(vector_char4    __x);
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar(vector_char8    __x);
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar(vector_char16   __x);
static vector_uchar32 __SIMD_ATTRIBUTES__ vector_uchar(vector_char32   __x);
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar(vector_uchar2   __x);
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar(vector_uchar3   __x);
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar(vector_uchar4   __x);
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar(vector_uchar8   __x);
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar(vector_uchar16  __x);
static vector_uchar32 __SIMD_ATTRIBUTES__ vector_uchar(vector_uchar32  __x);
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar(vector_short2   __x);
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar(vector_short3   __x);
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar(vector_short4   __x);
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar(vector_short8   __x);
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar(vector_short16  __x);
static vector_uchar32 __SIMD_ATTRIBUTES__ vector_uchar(vector_short32  __x);
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar(vector_ushort2  __x);
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar(vector_ushort3  __x);
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar(vector_ushort4  __x);
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar(vector_ushort8  __x);
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar(vector_ushort16 __x);
static vector_uchar32 __SIMD_ATTRIBUTES__ vector_uchar(vector_ushort32 __x);
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar(vector_int2     __x);
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar(vector_int3     __x);
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar(vector_int4     __x);
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar(vector_int8     __x);
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar(vector_int16    __x);
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar(vector_uint2    __x);
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar(vector_uint3    __x);
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar(vector_uint4    __x);
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar(vector_uint8    __x);
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar(vector_uint16   __x);
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar(vector_float2   __x);
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar(vector_float3   __x);
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar(vector_float4   __x);
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar(vector_float8   __x);
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar(vector_float16  __x);
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar(vector_long2    __x);
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar(vector_long3    __x);
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar(vector_long4    __x);
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar(vector_long8    __x);
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar(vector_ulong2   __x);
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar(vector_ulong3   __x);
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar(vector_ulong4   __x);
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar(vector_ulong8   __x);
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar(vector_double2  __x);
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar(vector_double3  __x);
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar(vector_double4  __x);
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar(vector_double8  __x);
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_char2    __x);
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_char3    __x);
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_char4    __x);
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_char8    __x);
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_char16   __x);
static vector_uchar32 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_char32   __x);
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_short2   __x);
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_short3   __x);
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_short4   __x);
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_short8   __x);
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_short16  __x);
static vector_uchar32 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_short32  __x);
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_int2     __x);
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_int3     __x);
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_int4     __x);
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_int8     __x);
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_int16    __x);
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_float2   __x);
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_float3   __x);
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_float4   __x);
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_float8   __x);
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_float16  __x);
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_long2    __x);
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_long3    __x);
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_long4    __x);
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_long8    __x);
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_double2  __x);
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_double3  __x);
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_double4  __x);
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_double8  __x);
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uchar2   __x);
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uchar3   __x);
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uchar4   __x);
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uchar8   __x);
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uchar16  __x);
static vector_uchar32 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uchar32  __x);
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_ushort2  __x);
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_ushort3  __x);
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_ushort4  __x);
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_ushort8  __x);
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_ushort16 __x);
static vector_uchar32 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_ushort32 __x);
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uint2    __x);
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uint3    __x);
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uint4    __x);
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uint8    __x);
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uint16   __x);
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_ulong2   __x);
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_ulong3   __x);
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_ulong4   __x);
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_ulong8   __x);

static vector_short2  __SIMD_ATTRIBUTES__ vector_short(vector_char2    __x);
static vector_short3  __SIMD_ATTRIBUTES__ vector_short(vector_char3    __x);
static vector_short4  __SIMD_ATTRIBUTES__ vector_short(vector_char4    __x);
static vector_short8  __SIMD_ATTRIBUTES__ vector_short(vector_char8    __x);
static vector_short16 __SIMD_ATTRIBUTES__ vector_short(vector_char16   __x);
static vector_short32 __SIMD_ATTRIBUTES__ vector_short(vector_char32   __x);
static vector_short2  __SIMD_ATTRIBUTES__ vector_short(vector_uchar2   __x);
static vector_short3  __SIMD_ATTRIBUTES__ vector_short(vector_uchar3   __x);
static vector_short4  __SIMD_ATTRIBUTES__ vector_short(vector_uchar4   __x);
static vector_short8  __SIMD_ATTRIBUTES__ vector_short(vector_uchar8   __x);
static vector_short16 __SIMD_ATTRIBUTES__ vector_short(vector_uchar16  __x);
static vector_short32 __SIMD_ATTRIBUTES__ vector_short(vector_uchar32  __x);
static vector_short2  __SIMD_ATTRIBUTES__ vector_short(vector_short2   __x);
static vector_short3  __SIMD_ATTRIBUTES__ vector_short(vector_short3   __x);
static vector_short4  __SIMD_ATTRIBUTES__ vector_short(vector_short4   __x);
static vector_short8  __SIMD_ATTRIBUTES__ vector_short(vector_short8   __x);
static vector_short16 __SIMD_ATTRIBUTES__ vector_short(vector_short16  __x);
static vector_short32 __SIMD_ATTRIBUTES__ vector_short(vector_short32  __x);
static vector_short2  __SIMD_ATTRIBUTES__ vector_short(vector_ushort2  __x);
static vector_short3  __SIMD_ATTRIBUTES__ vector_short(vector_ushort3  __x);
static vector_short4  __SIMD_ATTRIBUTES__ vector_short(vector_ushort4  __x);
static vector_short8  __SIMD_ATTRIBUTES__ vector_short(vector_ushort8  __x);
static vector_short16 __SIMD_ATTRIBUTES__ vector_short(vector_ushort16 __x);
static vector_short32 __SIMD_ATTRIBUTES__ vector_short(vector_ushort32 __x);
static vector_short2  __SIMD_ATTRIBUTES__ vector_short(vector_int2     __x);
static vector_short3  __SIMD_ATTRIBUTES__ vector_short(vector_int3     __x);
static vector_short4  __SIMD_ATTRIBUTES__ vector_short(vector_int4     __x);
static vector_short8  __SIMD_ATTRIBUTES__ vector_short(vector_int8     __x);
static vector_short16 __SIMD_ATTRIBUTES__ vector_short(vector_int16    __x);
static vector_short2  __SIMD_ATTRIBUTES__ vector_short(vector_uint2    __x);
static vector_short3  __SIMD_ATTRIBUTES__ vector_short(vector_uint3    __x);
static vector_short4  __SIMD_ATTRIBUTES__ vector_short(vector_uint4    __x);
static vector_short8  __SIMD_ATTRIBUTES__ vector_short(vector_uint8    __x);
static vector_short16 __SIMD_ATTRIBUTES__ vector_short(vector_uint16   __x);
static vector_short2  __SIMD_ATTRIBUTES__ vector_short(vector_float2   __x);
static vector_short3  __SIMD_ATTRIBUTES__ vector_short(vector_float3   __x);
static vector_short4  __SIMD_ATTRIBUTES__ vector_short(vector_float4   __x);
static vector_short8  __SIMD_ATTRIBUTES__ vector_short(vector_float8   __x);
static vector_short16 __SIMD_ATTRIBUTES__ vector_short(vector_float16  __x);
static vector_short2  __SIMD_ATTRIBUTES__ vector_short(vector_long2    __x);
static vector_short3  __SIMD_ATTRIBUTES__ vector_short(vector_long3    __x);
static vector_short4  __SIMD_ATTRIBUTES__ vector_short(vector_long4    __x);
static vector_short8  __SIMD_ATTRIBUTES__ vector_short(vector_long8    __x);
static vector_short2  __SIMD_ATTRIBUTES__ vector_short(vector_ulong2   __x);
static vector_short3  __SIMD_ATTRIBUTES__ vector_short(vector_ulong3   __x);
static vector_short4  __SIMD_ATTRIBUTES__ vector_short(vector_ulong4   __x);
static vector_short8  __SIMD_ATTRIBUTES__ vector_short(vector_ulong8   __x);
static vector_short2  __SIMD_ATTRIBUTES__ vector_short(vector_double2  __x);
static vector_short3  __SIMD_ATTRIBUTES__ vector_short(vector_double3  __x);
static vector_short4  __SIMD_ATTRIBUTES__ vector_short(vector_double4  __x);
static vector_short8  __SIMD_ATTRIBUTES__ vector_short(vector_double8  __x);
static vector_short2  __SIMD_ATTRIBUTES__ vector_short_sat(vector_char2    __x);
static vector_short3  __SIMD_ATTRIBUTES__ vector_short_sat(vector_char3    __x);
static vector_short4  __SIMD_ATTRIBUTES__ vector_short_sat(vector_char4    __x);
static vector_short8  __SIMD_ATTRIBUTES__ vector_short_sat(vector_char8    __x);
static vector_short16 __SIMD_ATTRIBUTES__ vector_short_sat(vector_char16   __x);
static vector_short32 __SIMD_ATTRIBUTES__ vector_short_sat(vector_char32   __x);
static vector_short2  __SIMD_ATTRIBUTES__ vector_short_sat(vector_short2   __x);
static vector_short3  __SIMD_ATTRIBUTES__ vector_short_sat(vector_short3   __x);
static vector_short4  __SIMD_ATTRIBUTES__ vector_short_sat(vector_short4   __x);
static vector_short8  __SIMD_ATTRIBUTES__ vector_short_sat(vector_short8   __x);
static vector_short16 __SIMD_ATTRIBUTES__ vector_short_sat(vector_short16  __x);
static vector_short32 __SIMD_ATTRIBUTES__ vector_short_sat(vector_short32  __x);
static vector_short2  __SIMD_ATTRIBUTES__ vector_short_sat(vector_int2     __x);
static vector_short3  __SIMD_ATTRIBUTES__ vector_short_sat(vector_int3     __x);
static vector_short4  __SIMD_ATTRIBUTES__ vector_short_sat(vector_int4     __x);
static vector_short8  __SIMD_ATTRIBUTES__ vector_short_sat(vector_int8     __x);
static vector_short16 __SIMD_ATTRIBUTES__ vector_short_sat(vector_int16    __x);
static vector_short2  __SIMD_ATTRIBUTES__ vector_short_sat(vector_float2   __x);
static vector_short3  __SIMD_ATTRIBUTES__ vector_short_sat(vector_float3   __x);
static vector_short4  __SIMD_ATTRIBUTES__ vector_short_sat(vector_float4   __x);
static vector_short8  __SIMD_ATTRIBUTES__ vector_short_sat(vector_float8   __x);
static vector_short16 __SIMD_ATTRIBUTES__ vector_short_sat(vector_float16  __x);
static vector_short2  __SIMD_ATTRIBUTES__ vector_short_sat(vector_long2    __x);
static vector_short3  __SIMD_ATTRIBUTES__ vector_short_sat(vector_long3    __x);
static vector_short4  __SIMD_ATTRIBUTES__ vector_short_sat(vector_long4    __x);
static vector_short8  __SIMD_ATTRIBUTES__ vector_short_sat(vector_long8    __x);
static vector_short2  __SIMD_ATTRIBUTES__ vector_short_sat(vector_double2  __x);
static vector_short3  __SIMD_ATTRIBUTES__ vector_short_sat(vector_double3  __x);
static vector_short4  __SIMD_ATTRIBUTES__ vector_short_sat(vector_double4  __x);
static vector_short8  __SIMD_ATTRIBUTES__ vector_short_sat(vector_double8  __x);
static vector_short2  __SIMD_ATTRIBUTES__ vector_short_sat(vector_uchar2   __x);
static vector_short3  __SIMD_ATTRIBUTES__ vector_short_sat(vector_uchar3   __x);
static vector_short4  __SIMD_ATTRIBUTES__ vector_short_sat(vector_uchar4   __x);
static vector_short8  __SIMD_ATTRIBUTES__ vector_short_sat(vector_uchar8   __x);
static vector_short16 __SIMD_ATTRIBUTES__ vector_short_sat(vector_uchar16  __x);
static vector_short32 __SIMD_ATTRIBUTES__ vector_short_sat(vector_uchar32  __x);
static vector_short2  __SIMD_ATTRIBUTES__ vector_short_sat(vector_ushort2  __x);
static vector_short3  __SIMD_ATTRIBUTES__ vector_short_sat(vector_ushort3  __x);
static vector_short4  __SIMD_ATTRIBUTES__ vector_short_sat(vector_ushort4  __x);
static vector_short8  __SIMD_ATTRIBUTES__ vector_short_sat(vector_ushort8  __x);
static vector_short16 __SIMD_ATTRIBUTES__ vector_short_sat(vector_ushort16 __x);
static vector_short32 __SIMD_ATTRIBUTES__ vector_short_sat(vector_ushort32 __x);
static vector_short2  __SIMD_ATTRIBUTES__ vector_short_sat(vector_uint2    __x);
static vector_short3  __SIMD_ATTRIBUTES__ vector_short_sat(vector_uint3    __x);
static vector_short4  __SIMD_ATTRIBUTES__ vector_short_sat(vector_uint4    __x);
static vector_short8  __SIMD_ATTRIBUTES__ vector_short_sat(vector_uint8    __x);
static vector_short16 __SIMD_ATTRIBUTES__ vector_short_sat(vector_uint16   __x);
static vector_short2  __SIMD_ATTRIBUTES__ vector_short_sat(vector_ulong2   __x);
static vector_short3  __SIMD_ATTRIBUTES__ vector_short_sat(vector_ulong3   __x);
static vector_short4  __SIMD_ATTRIBUTES__ vector_short_sat(vector_ulong4   __x);
static vector_short8  __SIMD_ATTRIBUTES__ vector_short_sat(vector_ulong8   __x);

static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort(vector_char2    __x);
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort(vector_char3    __x);
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort(vector_char4    __x);
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort(vector_char8    __x);
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort(vector_char16   __x);
static vector_ushort32 __SIMD_ATTRIBUTES__ vector_ushort(vector_char32   __x);
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort(vector_uchar2   __x);
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort(vector_uchar3   __x);
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort(vector_uchar4   __x);
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort(vector_uchar8   __x);
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort(vector_uchar16  __x);
static vector_ushort32 __SIMD_ATTRIBUTES__ vector_ushort(vector_uchar32  __x);
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort(vector_short2   __x);
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort(vector_short3   __x);
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort(vector_short4   __x);
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort(vector_short8   __x);
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort(vector_short16  __x);
static vector_ushort32 __SIMD_ATTRIBUTES__ vector_ushort(vector_short32  __x);
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort(vector_ushort2  __x);
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort(vector_ushort3  __x);
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort(vector_ushort4  __x);
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort(vector_ushort8  __x);
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort(vector_ushort16 __x);
static vector_ushort32 __SIMD_ATTRIBUTES__ vector_ushort(vector_ushort32 __x);
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort(vector_int2     __x);
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort(vector_int3     __x);
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort(vector_int4     __x);
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort(vector_int8     __x);
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort(vector_int16    __x);
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort(vector_uint2    __x);
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort(vector_uint3    __x);
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort(vector_uint4    __x);
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort(vector_uint8    __x);
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort(vector_uint16   __x);
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort(vector_float2   __x);
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort(vector_float3   __x);
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort(vector_float4   __x);
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort(vector_float8   __x);
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort(vector_float16  __x);
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort(vector_long2    __x);
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort(vector_long3    __x);
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort(vector_long4    __x);
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort(vector_long8    __x);
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort(vector_ulong2   __x);
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort(vector_ulong3   __x);
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort(vector_ulong4   __x);
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort(vector_ulong8   __x);
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort(vector_double2  __x);
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort(vector_double3  __x);
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort(vector_double4  __x);
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort(vector_double8  __x);
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_char2    __x);
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_char3    __x);
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_char4    __x);
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_char8    __x);
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_char16   __x);
static vector_ushort32 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_char32   __x);
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_short2   __x);
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_short3   __x);
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_short4   __x);
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_short8   __x);
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_short16  __x);
static vector_ushort32 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_short32  __x);
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_int2     __x);
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_int3     __x);
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_int4     __x);
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_int8     __x);
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_int16    __x);
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_float2   __x);
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_float3   __x);
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_float4   __x);
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_float8   __x);
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_float16  __x);
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_long2    __x);
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_long3    __x);
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_long4    __x);
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_long8    __x);
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_double2  __x);
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_double3  __x);
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_double4  __x);
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_double8  __x);
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uchar2   __x);
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uchar3   __x);
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uchar4   __x);
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uchar8   __x);
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uchar16  __x);
static vector_ushort32 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uchar32  __x);
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_ushort2  __x);
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_ushort3  __x);
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_ushort4  __x);
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_ushort8  __x);
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_ushort16 __x);
static vector_ushort32 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_ushort32 __x);
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uint2    __x);
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uint3    __x);
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uint4    __x);
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uint8    __x);
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uint16   __x);
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_ulong2   __x);
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_ulong3   __x);
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_ulong4   __x);
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_ulong8   __x);

static vector_int2  __SIMD_ATTRIBUTES__ vector_int(vector_char2    __x);
static vector_int3  __SIMD_ATTRIBUTES__ vector_int(vector_char3    __x);
static vector_int4  __SIMD_ATTRIBUTES__ vector_int(vector_char4    __x);
static vector_int8  __SIMD_ATTRIBUTES__ vector_int(vector_char8    __x);
static vector_int16 __SIMD_ATTRIBUTES__ vector_int(vector_char16   __x);
static vector_int2  __SIMD_ATTRIBUTES__ vector_int(vector_uchar2   __x);
static vector_int3  __SIMD_ATTRIBUTES__ vector_int(vector_uchar3   __x);
static vector_int4  __SIMD_ATTRIBUTES__ vector_int(vector_uchar4   __x);
static vector_int8  __SIMD_ATTRIBUTES__ vector_int(vector_uchar8   __x);
static vector_int16 __SIMD_ATTRIBUTES__ vector_int(vector_uchar16  __x);
static vector_int2  __SIMD_ATTRIBUTES__ vector_int(vector_short2   __x);
static vector_int3  __SIMD_ATTRIBUTES__ vector_int(vector_short3   __x);
static vector_int4  __SIMD_ATTRIBUTES__ vector_int(vector_short4   __x);
static vector_int8  __SIMD_ATTRIBUTES__ vector_int(vector_short8   __x);
static vector_int16 __SIMD_ATTRIBUTES__ vector_int(vector_short16  __x);
static vector_int2  __SIMD_ATTRIBUTES__ vector_int(vector_ushort2  __x);
static vector_int3  __SIMD_ATTRIBUTES__ vector_int(vector_ushort3  __x);
static vector_int4  __SIMD_ATTRIBUTES__ vector_int(vector_ushort4  __x);
static vector_int8  __SIMD_ATTRIBUTES__ vector_int(vector_ushort8  __x);
static vector_int16 __SIMD_ATTRIBUTES__ vector_int(vector_ushort16 __x);
static vector_int2  __SIMD_ATTRIBUTES__ vector_int(vector_int2     __x);
static vector_int3  __SIMD_ATTRIBUTES__ vector_int(vector_int3     __x);
static vector_int4  __SIMD_ATTRIBUTES__ vector_int(vector_int4     __x);
static vector_int8  __SIMD_ATTRIBUTES__ vector_int(vector_int8     __x);
static vector_int16 __SIMD_ATTRIBUTES__ vector_int(vector_int16    __x);
static vector_int2  __SIMD_ATTRIBUTES__ vector_int(vector_uint2    __x);
static vector_int3  __SIMD_ATTRIBUTES__ vector_int(vector_uint3    __x);
static vector_int4  __SIMD_ATTRIBUTES__ vector_int(vector_uint4    __x);
static vector_int8  __SIMD_ATTRIBUTES__ vector_int(vector_uint8    __x);
static vector_int16 __SIMD_ATTRIBUTES__ vector_int(vector_uint16   __x);
static vector_int2  __SIMD_ATTRIBUTES__ vector_int(vector_float2   __x);
static vector_int3  __SIMD_ATTRIBUTES__ vector_int(vector_float3   __x);
static vector_int4  __SIMD_ATTRIBUTES__ vector_int(vector_float4   __x);
static vector_int8  __SIMD_ATTRIBUTES__ vector_int(vector_float8   __x);
static vector_int16 __SIMD_ATTRIBUTES__ vector_int(vector_float16  __x);
static vector_int2  __SIMD_ATTRIBUTES__ vector_int(vector_long2    __x);
static vector_int3  __SIMD_ATTRIBUTES__ vector_int(vector_long3    __x);
static vector_int4  __SIMD_ATTRIBUTES__ vector_int(vector_long4    __x);
static vector_int8  __SIMD_ATTRIBUTES__ vector_int(vector_long8    __x);
static vector_int2  __SIMD_ATTRIBUTES__ vector_int(vector_ulong2   __x);
static vector_int3  __SIMD_ATTRIBUTES__ vector_int(vector_ulong3   __x);
static vector_int4  __SIMD_ATTRIBUTES__ vector_int(vector_ulong4   __x);
static vector_int8  __SIMD_ATTRIBUTES__ vector_int(vector_ulong8   __x);
static vector_int2  __SIMD_ATTRIBUTES__ vector_int(vector_double2  __x);
static vector_int3  __SIMD_ATTRIBUTES__ vector_int(vector_double3  __x);
static vector_int4  __SIMD_ATTRIBUTES__ vector_int(vector_double4  __x);
static vector_int8  __SIMD_ATTRIBUTES__ vector_int(vector_double8  __x);
static vector_int2  __SIMD_ATTRIBUTES__ vector_int_sat(vector_char2    __x);
static vector_int3  __SIMD_ATTRIBUTES__ vector_int_sat(vector_char3    __x);
static vector_int4  __SIMD_ATTRIBUTES__ vector_int_sat(vector_char4    __x);
static vector_int8  __SIMD_ATTRIBUTES__ vector_int_sat(vector_char8    __x);
static vector_int16 __SIMD_ATTRIBUTES__ vector_int_sat(vector_char16   __x);
static vector_int2  __SIMD_ATTRIBUTES__ vector_int_sat(vector_short2   __x);
static vector_int3  __SIMD_ATTRIBUTES__ vector_int_sat(vector_short3   __x);
static vector_int4  __SIMD_ATTRIBUTES__ vector_int_sat(vector_short4   __x);
static vector_int8  __SIMD_ATTRIBUTES__ vector_int_sat(vector_short8   __x);
static vector_int16 __SIMD_ATTRIBUTES__ vector_int_sat(vector_short16  __x);
static vector_int2  __SIMD_ATTRIBUTES__ vector_int_sat(vector_int2     __x);
static vector_int3  __SIMD_ATTRIBUTES__ vector_int_sat(vector_int3     __x);
static vector_int4  __SIMD_ATTRIBUTES__ vector_int_sat(vector_int4     __x);
static vector_int8  __SIMD_ATTRIBUTES__ vector_int_sat(vector_int8     __x);
static vector_int16 __SIMD_ATTRIBUTES__ vector_int_sat(vector_int16    __x);
static vector_int2  __SIMD_ATTRIBUTES__ vector_int_sat(vector_float2   __x);
static vector_int3  __SIMD_ATTRIBUTES__ vector_int_sat(vector_float3   __x);
static vector_int4  __SIMD_ATTRIBUTES__ vector_int_sat(vector_float4   __x);
static vector_int8  __SIMD_ATTRIBUTES__ vector_int_sat(vector_float8   __x);
static vector_int16 __SIMD_ATTRIBUTES__ vector_int_sat(vector_float16  __x);
static vector_int2  __SIMD_ATTRIBUTES__ vector_int_sat(vector_long2    __x);
static vector_int3  __SIMD_ATTRIBUTES__ vector_int_sat(vector_long3    __x);
static vector_int4  __SIMD_ATTRIBUTES__ vector_int_sat(vector_long4    __x);
static vector_int8  __SIMD_ATTRIBUTES__ vector_int_sat(vector_long8    __x);
static vector_int2  __SIMD_ATTRIBUTES__ vector_int_sat(vector_double2  __x);
static vector_int3  __SIMD_ATTRIBUTES__ vector_int_sat(vector_double3  __x);
static vector_int4  __SIMD_ATTRIBUTES__ vector_int_sat(vector_double4  __x);
static vector_int8  __SIMD_ATTRIBUTES__ vector_int_sat(vector_double8  __x);
static vector_int2  __SIMD_ATTRIBUTES__ vector_int_sat(vector_uchar2   __x);
static vector_int3  __SIMD_ATTRIBUTES__ vector_int_sat(vector_uchar3   __x);
static vector_int4  __SIMD_ATTRIBUTES__ vector_int_sat(vector_uchar4   __x);
static vector_int8  __SIMD_ATTRIBUTES__ vector_int_sat(vector_uchar8   __x);
static vector_int16 __SIMD_ATTRIBUTES__ vector_int_sat(vector_uchar16  __x);
static vector_int2  __SIMD_ATTRIBUTES__ vector_int_sat(vector_ushort2  __x);
static vector_int3  __SIMD_ATTRIBUTES__ vector_int_sat(vector_ushort3  __x);
static vector_int4  __SIMD_ATTRIBUTES__ vector_int_sat(vector_ushort4  __x);
static vector_int8  __SIMD_ATTRIBUTES__ vector_int_sat(vector_ushort8  __x);
static vector_int16 __SIMD_ATTRIBUTES__ vector_int_sat(vector_ushort16 __x);
static vector_int2  __SIMD_ATTRIBUTES__ vector_int_sat(vector_uint2    __x);
static vector_int3  __SIMD_ATTRIBUTES__ vector_int_sat(vector_uint3    __x);
static vector_int4  __SIMD_ATTRIBUTES__ vector_int_sat(vector_uint4    __x);
static vector_int8  __SIMD_ATTRIBUTES__ vector_int_sat(vector_uint8    __x);
static vector_int16 __SIMD_ATTRIBUTES__ vector_int_sat(vector_uint16   __x);
static vector_int2  __SIMD_ATTRIBUTES__ vector_int_sat(vector_ulong2   __x);
static vector_int3  __SIMD_ATTRIBUTES__ vector_int_sat(vector_ulong3   __x);
static vector_int4  __SIMD_ATTRIBUTES__ vector_int_sat(vector_ulong4   __x);
static vector_int8  __SIMD_ATTRIBUTES__ vector_int_sat(vector_ulong8   __x);

static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint(vector_char2    __x);
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint(vector_char3    __x);
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint(vector_char4    __x);
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint(vector_char8    __x);
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint(vector_char16   __x);
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint(vector_uchar2   __x);
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint(vector_uchar3   __x);
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint(vector_uchar4   __x);
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint(vector_uchar8   __x);
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint(vector_uchar16  __x);
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint(vector_short2   __x);
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint(vector_short3   __x);
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint(vector_short4   __x);
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint(vector_short8   __x);
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint(vector_short16  __x);
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint(vector_ushort2  __x);
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint(vector_ushort3  __x);
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint(vector_ushort4  __x);
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint(vector_ushort8  __x);
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint(vector_ushort16 __x);
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint(vector_int2     __x);
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint(vector_int3     __x);
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint(vector_int4     __x);
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint(vector_int8     __x);
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint(vector_int16    __x);
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint(vector_uint2    __x);
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint(vector_uint3    __x);
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint(vector_uint4    __x);
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint(vector_uint8    __x);
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint(vector_uint16   __x);
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint(vector_float2   __x);
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint(vector_float3   __x);
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint(vector_float4   __x);
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint(vector_float8   __x);
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint(vector_float16  __x);
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint(vector_long2    __x);
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint(vector_long3    __x);
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint(vector_long4    __x);
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint(vector_long8    __x);
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint(vector_ulong2   __x);
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint(vector_ulong3   __x);
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint(vector_ulong4   __x);
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint(vector_ulong8   __x);
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint(vector_double2  __x);
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint(vector_double3  __x);
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint(vector_double4  __x);
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint(vector_double8  __x);
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_char2    __x);
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_char3    __x);
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_char4    __x);
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_char8    __x);
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint_sat(vector_char16   __x);
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_short2   __x);
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_short3   __x);
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_short4   __x);
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_short8   __x);
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint_sat(vector_short16  __x);
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_int2     __x);
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_int3     __x);
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_int4     __x);
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_int8     __x);
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint_sat(vector_int16    __x);
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_float2   __x);
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_float3   __x);
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_float4   __x);
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_float8   __x);
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint_sat(vector_float16  __x);
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_long2    __x);
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_long3    __x);
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_long4    __x);
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_long8    __x);
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_double2  __x);
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_double3  __x);
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_double4  __x);
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_double8  __x);
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_uchar2   __x);
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_uchar3   __x);
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_uchar4   __x);
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_uchar8   __x);
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint_sat(vector_uchar16  __x);
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_ushort2  __x);
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_ushort3  __x);
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_ushort4  __x);
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_ushort8  __x);
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint_sat(vector_ushort16 __x);
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_uint2    __x);
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_uint3    __x);
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_uint4    __x);
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_uint8    __x);
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint_sat(vector_uint16   __x);
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_ulong2   __x);
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_ulong3   __x);
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_ulong4   __x);
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_ulong8   __x);

static vector_float2  __SIMD_ATTRIBUTES__ vector_float(vector_char2    __x);
static vector_float3  __SIMD_ATTRIBUTES__ vector_float(vector_char3    __x);
static vector_float4  __SIMD_ATTRIBUTES__ vector_float(vector_char4    __x);
static vector_float8  __SIMD_ATTRIBUTES__ vector_float(vector_char8    __x);
static vector_float16 __SIMD_ATTRIBUTES__ vector_float(vector_char16   __x);
static vector_float2  __SIMD_ATTRIBUTES__ vector_float(vector_uchar2   __x);
static vector_float3  __SIMD_ATTRIBUTES__ vector_float(vector_uchar3   __x);
static vector_float4  __SIMD_ATTRIBUTES__ vector_float(vector_uchar4   __x);
static vector_float8  __SIMD_ATTRIBUTES__ vector_float(vector_uchar8   __x);
static vector_float16 __SIMD_ATTRIBUTES__ vector_float(vector_uchar16  __x);
static vector_float2  __SIMD_ATTRIBUTES__ vector_float(vector_short2   __x);
static vector_float3  __SIMD_ATTRIBUTES__ vector_float(vector_short3   __x);
static vector_float4  __SIMD_ATTRIBUTES__ vector_float(vector_short4   __x);
static vector_float8  __SIMD_ATTRIBUTES__ vector_float(vector_short8   __x);
static vector_float16 __SIMD_ATTRIBUTES__ vector_float(vector_short16  __x);
static vector_float2  __SIMD_ATTRIBUTES__ vector_float(vector_ushort2  __x);
static vector_float3  __SIMD_ATTRIBUTES__ vector_float(vector_ushort3  __x);
static vector_float4  __SIMD_ATTRIBUTES__ vector_float(vector_ushort4  __x);
static vector_float8  __SIMD_ATTRIBUTES__ vector_float(vector_ushort8  __x);
static vector_float16 __SIMD_ATTRIBUTES__ vector_float(vector_ushort16 __x);
static vector_float2  __SIMD_ATTRIBUTES__ vector_float(vector_int2     __x);
static vector_float3  __SIMD_ATTRIBUTES__ vector_float(vector_int3     __x);
static vector_float4  __SIMD_ATTRIBUTES__ vector_float(vector_int4     __x);
static vector_float8  __SIMD_ATTRIBUTES__ vector_float(vector_int8     __x);
static vector_float16 __SIMD_ATTRIBUTES__ vector_float(vector_int16    __x);
static vector_float2  __SIMD_ATTRIBUTES__ vector_float(vector_uint2    __x);
static vector_float3  __SIMD_ATTRIBUTES__ vector_float(vector_uint3    __x);
static vector_float4  __SIMD_ATTRIBUTES__ vector_float(vector_uint4    __x);
static vector_float8  __SIMD_ATTRIBUTES__ vector_float(vector_uint8    __x);
static vector_float16 __SIMD_ATTRIBUTES__ vector_float(vector_uint16   __x);
static vector_float2  __SIMD_ATTRIBUTES__ vector_float(vector_float2   __x);
static vector_float3  __SIMD_ATTRIBUTES__ vector_float(vector_float3   __x);
static vector_float4  __SIMD_ATTRIBUTES__ vector_float(vector_float4   __x);
static vector_float8  __SIMD_ATTRIBUTES__ vector_float(vector_float8   __x);
static vector_float16 __SIMD_ATTRIBUTES__ vector_float(vector_float16  __x);
static vector_float2  __SIMD_ATTRIBUTES__ vector_float(vector_long2    __x);
static vector_float3  __SIMD_ATTRIBUTES__ vector_float(vector_long3    __x);
static vector_float4  __SIMD_ATTRIBUTES__ vector_float(vector_long4    __x);
static vector_float8  __SIMD_ATTRIBUTES__ vector_float(vector_long8    __x);
static vector_float2  __SIMD_ATTRIBUTES__ vector_float(vector_ulong2   __x);
static vector_float3  __SIMD_ATTRIBUTES__ vector_float(vector_ulong3   __x);
static vector_float4  __SIMD_ATTRIBUTES__ vector_float(vector_ulong4   __x);
static vector_float8  __SIMD_ATTRIBUTES__ vector_float(vector_ulong8   __x);
static vector_float2  __SIMD_ATTRIBUTES__ vector_float(vector_double2  __x);
static vector_float3  __SIMD_ATTRIBUTES__ vector_float(vector_double3  __x);
static vector_float4  __SIMD_ATTRIBUTES__ vector_float(vector_double4  __x);
static vector_float8  __SIMD_ATTRIBUTES__ vector_float(vector_double8  __x);

static vector_long2  __SIMD_ATTRIBUTES__ vector_long(vector_char2    __x);
static vector_long3  __SIMD_ATTRIBUTES__ vector_long(vector_char3    __x);
static vector_long4  __SIMD_ATTRIBUTES__ vector_long(vector_char4    __x);
static vector_long8  __SIMD_ATTRIBUTES__ vector_long(vector_char8    __x);
static vector_long2  __SIMD_ATTRIBUTES__ vector_long(vector_uchar2   __x);
static vector_long3  __SIMD_ATTRIBUTES__ vector_long(vector_uchar3   __x);
static vector_long4  __SIMD_ATTRIBUTES__ vector_long(vector_uchar4   __x);
static vector_long8  __SIMD_ATTRIBUTES__ vector_long(vector_uchar8   __x);
static vector_long2  __SIMD_ATTRIBUTES__ vector_long(vector_short2   __x);
static vector_long3  __SIMD_ATTRIBUTES__ vector_long(vector_short3   __x);
static vector_long4  __SIMD_ATTRIBUTES__ vector_long(vector_short4   __x);
static vector_long8  __SIMD_ATTRIBUTES__ vector_long(vector_short8   __x);
static vector_long2  __SIMD_ATTRIBUTES__ vector_long(vector_ushort2  __x);
static vector_long3  __SIMD_ATTRIBUTES__ vector_long(vector_ushort3  __x);
static vector_long4  __SIMD_ATTRIBUTES__ vector_long(vector_ushort4  __x);
static vector_long8  __SIMD_ATTRIBUTES__ vector_long(vector_ushort8  __x);
static vector_long2  __SIMD_ATTRIBUTES__ vector_long(vector_int2     __x);
static vector_long3  __SIMD_ATTRIBUTES__ vector_long(vector_int3     __x);
static vector_long4  __SIMD_ATTRIBUTES__ vector_long(vector_int4     __x);
static vector_long8  __SIMD_ATTRIBUTES__ vector_long(vector_int8     __x);
static vector_long2  __SIMD_ATTRIBUTES__ vector_long(vector_uint2    __x);
static vector_long3  __SIMD_ATTRIBUTES__ vector_long(vector_uint3    __x);
static vector_long4  __SIMD_ATTRIBUTES__ vector_long(vector_uint4    __x);
static vector_long8  __SIMD_ATTRIBUTES__ vector_long(vector_uint8    __x);
static vector_long2  __SIMD_ATTRIBUTES__ vector_long(vector_float2   __x);
static vector_long3  __SIMD_ATTRIBUTES__ vector_long(vector_float3   __x);
static vector_long4  __SIMD_ATTRIBUTES__ vector_long(vector_float4   __x);
static vector_long8  __SIMD_ATTRIBUTES__ vector_long(vector_float8   __x);
static vector_long2  __SIMD_ATTRIBUTES__ vector_long(vector_long2    __x);
static vector_long3  __SIMD_ATTRIBUTES__ vector_long(vector_long3    __x);
static vector_long4  __SIMD_ATTRIBUTES__ vector_long(vector_long4    __x);
static vector_long8  __SIMD_ATTRIBUTES__ vector_long(vector_long8    __x);
static vector_long2  __SIMD_ATTRIBUTES__ vector_long(vector_ulong2   __x);
static vector_long3  __SIMD_ATTRIBUTES__ vector_long(vector_ulong3   __x);
static vector_long4  __SIMD_ATTRIBUTES__ vector_long(vector_ulong4   __x);
static vector_long8  __SIMD_ATTRIBUTES__ vector_long(vector_ulong8   __x);
static vector_long2  __SIMD_ATTRIBUTES__ vector_long(vector_double2  __x);
static vector_long3  __SIMD_ATTRIBUTES__ vector_long(vector_double3  __x);
static vector_long4  __SIMD_ATTRIBUTES__ vector_long(vector_double4  __x);
static vector_long8  __SIMD_ATTRIBUTES__ vector_long(vector_double8  __x);
static vector_long2  __SIMD_ATTRIBUTES__ vector_long_sat(vector_char2    __x);
static vector_long3  __SIMD_ATTRIBUTES__ vector_long_sat(vector_char3    __x);
static vector_long4  __SIMD_ATTRIBUTES__ vector_long_sat(vector_char4    __x);
static vector_long8  __SIMD_ATTRIBUTES__ vector_long_sat(vector_char8    __x);
static vector_long2  __SIMD_ATTRIBUTES__ vector_long_sat(vector_short2   __x);
static vector_long3  __SIMD_ATTRIBUTES__ vector_long_sat(vector_short3   __x);
static vector_long4  __SIMD_ATTRIBUTES__ vector_long_sat(vector_short4   __x);
static vector_long8  __SIMD_ATTRIBUTES__ vector_long_sat(vector_short8   __x);
static vector_long2  __SIMD_ATTRIBUTES__ vector_long_sat(vector_int2     __x);
static vector_long3  __SIMD_ATTRIBUTES__ vector_long_sat(vector_int3     __x);
static vector_long4  __SIMD_ATTRIBUTES__ vector_long_sat(vector_int4     __x);
static vector_long8  __SIMD_ATTRIBUTES__ vector_long_sat(vector_int8     __x);
static vector_long2  __SIMD_ATTRIBUTES__ vector_long_sat(vector_float2   __x);
static vector_long3  __SIMD_ATTRIBUTES__ vector_long_sat(vector_float3   __x);
static vector_long4  __SIMD_ATTRIBUTES__ vector_long_sat(vector_float4   __x);
static vector_long8  __SIMD_ATTRIBUTES__ vector_long_sat(vector_float8   __x);
static vector_long2  __SIMD_ATTRIBUTES__ vector_long_sat(vector_long2    __x);
static vector_long3  __SIMD_ATTRIBUTES__ vector_long_sat(vector_long3    __x);
static vector_long4  __SIMD_ATTRIBUTES__ vector_long_sat(vector_long4    __x);
static vector_long8  __SIMD_ATTRIBUTES__ vector_long_sat(vector_long8    __x);
static vector_long2  __SIMD_ATTRIBUTES__ vector_long_sat(vector_double2  __x);
static vector_long3  __SIMD_ATTRIBUTES__ vector_long_sat(vector_double3  __x);
static vector_long4  __SIMD_ATTRIBUTES__ vector_long_sat(vector_double4  __x);
static vector_long8  __SIMD_ATTRIBUTES__ vector_long_sat(vector_double8  __x);
static vector_long2  __SIMD_ATTRIBUTES__ vector_long_sat(vector_uchar2   __x);
static vector_long3  __SIMD_ATTRIBUTES__ vector_long_sat(vector_uchar3   __x);
static vector_long4  __SIMD_ATTRIBUTES__ vector_long_sat(vector_uchar4   __x);
static vector_long8  __SIMD_ATTRIBUTES__ vector_long_sat(vector_uchar8   __x);
static vector_long2  __SIMD_ATTRIBUTES__ vector_long_sat(vector_ushort2  __x);
static vector_long3  __SIMD_ATTRIBUTES__ vector_long_sat(vector_ushort3  __x);
static vector_long4  __SIMD_ATTRIBUTES__ vector_long_sat(vector_ushort4  __x);
static vector_long8  __SIMD_ATTRIBUTES__ vector_long_sat(vector_ushort8  __x);
static vector_long2  __SIMD_ATTRIBUTES__ vector_long_sat(vector_uint2    __x);
static vector_long3  __SIMD_ATTRIBUTES__ vector_long_sat(vector_uint3    __x);
static vector_long4  __SIMD_ATTRIBUTES__ vector_long_sat(vector_uint4    __x);
static vector_long8  __SIMD_ATTRIBUTES__ vector_long_sat(vector_uint8    __x);
static vector_long2  __SIMD_ATTRIBUTES__ vector_long_sat(vector_ulong2   __x);
static vector_long3  __SIMD_ATTRIBUTES__ vector_long_sat(vector_ulong3   __x);
static vector_long4  __SIMD_ATTRIBUTES__ vector_long_sat(vector_ulong4   __x);
static vector_long8  __SIMD_ATTRIBUTES__ vector_long_sat(vector_ulong8   __x);

static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong(vector_char2    __x);
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong(vector_char3    __x);
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong(vector_char4    __x);
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong(vector_char8    __x);
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong(vector_uchar2   __x);
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong(vector_uchar3   __x);
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong(vector_uchar4   __x);
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong(vector_uchar8   __x);
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong(vector_short2   __x);
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong(vector_short3   __x);
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong(vector_short4   __x);
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong(vector_short8   __x);
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong(vector_ushort2  __x);
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong(vector_ushort3  __x);
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong(vector_ushort4  __x);
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong(vector_ushort8  __x);
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong(vector_int2     __x);
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong(vector_int3     __x);
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong(vector_int4     __x);
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong(vector_int8     __x);
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong(vector_uint2    __x);
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong(vector_uint3    __x);
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong(vector_uint4    __x);
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong(vector_uint8    __x);
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong(vector_float2   __x);
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong(vector_float3   __x);
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong(vector_float4   __x);
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong(vector_float8   __x);
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong(vector_long2    __x);
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong(vector_long3    __x);
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong(vector_long4    __x);
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong(vector_long8    __x);
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong(vector_ulong2   __x);
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong(vector_ulong3   __x);
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong(vector_ulong4   __x);
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong(vector_ulong8   __x);
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong(vector_double2  __x);
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong(vector_double3  __x);
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong(vector_double4  __x);
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong(vector_double8  __x);
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_char2    __x);
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_char3    __x);
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_char4    __x);
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_char8    __x);
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_short2   __x);
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_short3   __x);
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_short4   __x);
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_short8   __x);
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_int2     __x);
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_int3     __x);
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_int4     __x);
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_int8     __x);
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_float2   __x);
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_float3   __x);
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_float4   __x);
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_float8   __x);
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_long2    __x);
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_long3    __x);
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_long4    __x);
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_long8    __x);
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_double2  __x);
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_double3  __x);
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_double4  __x);
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_double8  __x);
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_uchar2   __x);
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_uchar3   __x);
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_uchar4   __x);
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_uchar8   __x);
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_ushort2  __x);
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_ushort3  __x);
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_ushort4  __x);
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_ushort8  __x);
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_uint2    __x);
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_uint3    __x);
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_uint4    __x);
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_uint8    __x);
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_ulong2   __x);
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_ulong3   __x);
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_ulong4   __x);
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_ulong8   __x);

static vector_double2  __SIMD_ATTRIBUTES__ vector_double(vector_char2    __x);
static vector_double3  __SIMD_ATTRIBUTES__ vector_double(vector_char3    __x);
static vector_double4  __SIMD_ATTRIBUTES__ vector_double(vector_char4    __x);
static vector_double8  __SIMD_ATTRIBUTES__ vector_double(vector_char8    __x);
static vector_double2  __SIMD_ATTRIBUTES__ vector_double(vector_uchar2   __x);
static vector_double3  __SIMD_ATTRIBUTES__ vector_double(vector_uchar3   __x);
static vector_double4  __SIMD_ATTRIBUTES__ vector_double(vector_uchar4   __x);
static vector_double8  __SIMD_ATTRIBUTES__ vector_double(vector_uchar8   __x);
static vector_double2  __SIMD_ATTRIBUTES__ vector_double(vector_short2   __x);
static vector_double3  __SIMD_ATTRIBUTES__ vector_double(vector_short3   __x);
static vector_double4  __SIMD_ATTRIBUTES__ vector_double(vector_short4   __x);
static vector_double8  __SIMD_ATTRIBUTES__ vector_double(vector_short8   __x);
static vector_double2  __SIMD_ATTRIBUTES__ vector_double(vector_ushort2  __x);
static vector_double3  __SIMD_ATTRIBUTES__ vector_double(vector_ushort3  __x);
static vector_double4  __SIMD_ATTRIBUTES__ vector_double(vector_ushort4  __x);
static vector_double8  __SIMD_ATTRIBUTES__ vector_double(vector_ushort8  __x);
static vector_double2  __SIMD_ATTRIBUTES__ vector_double(vector_int2     __x);
static vector_double3  __SIMD_ATTRIBUTES__ vector_double(vector_int3     __x);
static vector_double4  __SIMD_ATTRIBUTES__ vector_double(vector_int4     __x);
static vector_double8  __SIMD_ATTRIBUTES__ vector_double(vector_int8     __x);
static vector_double2  __SIMD_ATTRIBUTES__ vector_double(vector_uint2    __x);
static vector_double3  __SIMD_ATTRIBUTES__ vector_double(vector_uint3    __x);
static vector_double4  __SIMD_ATTRIBUTES__ vector_double(vector_uint4    __x);
static vector_double8  __SIMD_ATTRIBUTES__ vector_double(vector_uint8    __x);
static vector_double2  __SIMD_ATTRIBUTES__ vector_double(vector_float2   __x);
static vector_double3  __SIMD_ATTRIBUTES__ vector_double(vector_float3   __x);
static vector_double4  __SIMD_ATTRIBUTES__ vector_double(vector_float4   __x);
static vector_double8  __SIMD_ATTRIBUTES__ vector_double(vector_float8   __x);
static vector_double2  __SIMD_ATTRIBUTES__ vector_double(vector_long2    __x);
static vector_double3  __SIMD_ATTRIBUTES__ vector_double(vector_long3    __x);
static vector_double4  __SIMD_ATTRIBUTES__ vector_double(vector_long4    __x);
static vector_double8  __SIMD_ATTRIBUTES__ vector_double(vector_long8    __x);
static vector_double2  __SIMD_ATTRIBUTES__ vector_double(vector_ulong2   __x);
static vector_double3  __SIMD_ATTRIBUTES__ vector_double(vector_ulong3   __x);
static vector_double4  __SIMD_ATTRIBUTES__ vector_double(vector_ulong4   __x);
static vector_double8  __SIMD_ATTRIBUTES__ vector_double(vector_ulong8   __x);
static vector_double2  __SIMD_ATTRIBUTES__ vector_double(vector_double2  __x);
static vector_double3  __SIMD_ATTRIBUTES__ vector_double(vector_double3  __x);
static vector_double4  __SIMD_ATTRIBUTES__ vector_double(vector_double4  __x);
static vector_double8  __SIMD_ATTRIBUTES__ vector_double(vector_double8  __x);

#pragma mark - Implementation

static vector_char2  __SIMD_ATTRIBUTES__ vector_char(vector_char2    __x) { return __x; }
static vector_char3  __SIMD_ATTRIBUTES__ vector_char(vector_char3    __x) { return __x; }
static vector_char4  __SIMD_ATTRIBUTES__ vector_char(vector_char4    __x) { return __x; }
static vector_char8  __SIMD_ATTRIBUTES__ vector_char(vector_char8    __x) { return __x; }
static vector_char16 __SIMD_ATTRIBUTES__ vector_char(vector_char16   __x) { return __x; }
static vector_char32 __SIMD_ATTRIBUTES__ vector_char(vector_char32   __x) { return __x; }
static vector_char2  __SIMD_ATTRIBUTES__ vector_char(vector_uchar2   __x) { return (vector_char2)__x; }
static vector_char3  __SIMD_ATTRIBUTES__ vector_char(vector_uchar3   __x) { return (vector_char3)__x; }
static vector_char4  __SIMD_ATTRIBUTES__ vector_char(vector_uchar4   __x) { return (vector_char4)__x; }
static vector_char8  __SIMD_ATTRIBUTES__ vector_char(vector_uchar8   __x) { return (vector_char8)__x; }
static vector_char16 __SIMD_ATTRIBUTES__ vector_char(vector_uchar16  __x) { return (vector_char16)__x; }
static vector_char32 __SIMD_ATTRIBUTES__ vector_char(vector_uchar32  __x) { return (vector_char32)__x; }
static vector_char2  __SIMD_ATTRIBUTES__ vector_char(vector_short2   __x) { return ((vector_char4)__x).even; }
static vector_char3  __SIMD_ATTRIBUTES__ vector_char(vector_short3   __x) { vector_char4 __r = vector_char(__x.xyzz); return __r.xyz; }
static vector_char4  __SIMD_ATTRIBUTES__ vector_char(vector_short4   __x) { return ((vector_char8)__x).even; }
static vector_char8  __SIMD_ATTRIBUTES__ vector_char(vector_short8   __x) { return ((vector_char16)__x).even; }
static vector_char16 __SIMD_ATTRIBUTES__ vector_char(vector_short16  __x) { return ((vector_char32)__x).even; }
static vector_char32 __SIMD_ATTRIBUTES__ vector_char(vector_short32  __x) { vector_char32 __r; __r.lo = vector_char(__x.lo); __r.hi = vector_char(__x.hi); return __r; }
static vector_char2  __SIMD_ATTRIBUTES__ vector_char(vector_ushort2  __x) { return vector_char(vector_short(__x)); }
static vector_char3  __SIMD_ATTRIBUTES__ vector_char(vector_ushort3  __x) { return vector_char(vector_short(__x)); }
static vector_char4  __SIMD_ATTRIBUTES__ vector_char(vector_ushort4  __x) { return vector_char(vector_short(__x)); }
static vector_char8  __SIMD_ATTRIBUTES__ vector_char(vector_ushort8  __x) { return vector_char(vector_short(__x)); }
static vector_char16 __SIMD_ATTRIBUTES__ vector_char(vector_ushort16 __x) { return vector_char(vector_short(__x)); }
static vector_char32 __SIMD_ATTRIBUTES__ vector_char(vector_ushort32 __x) { return vector_char(vector_short(__x)); }
static vector_char2  __SIMD_ATTRIBUTES__ vector_char(vector_int2     __x) { return vector_char(vector_short(__x)); }
static vector_char3  __SIMD_ATTRIBUTES__ vector_char(vector_int3     __x) { return vector_char(vector_short(__x)); }
static vector_char4  __SIMD_ATTRIBUTES__ vector_char(vector_int4     __x) { return vector_char(vector_short(__x)); }
static vector_char8  __SIMD_ATTRIBUTES__ vector_char(vector_int8     __x) { return vector_char(vector_short(__x)); }
static vector_char16 __SIMD_ATTRIBUTES__ vector_char(vector_int16    __x) { return vector_char(vector_short(__x)); }
static vector_char2  __SIMD_ATTRIBUTES__ vector_char(vector_uint2    __x) { return vector_char(vector_short(__x)); }
static vector_char3  __SIMD_ATTRIBUTES__ vector_char(vector_uint3    __x) { return vector_char(vector_short(__x)); }
static vector_char4  __SIMD_ATTRIBUTES__ vector_char(vector_uint4    __x) { return vector_char(vector_short(__x)); }
static vector_char8  __SIMD_ATTRIBUTES__ vector_char(vector_uint8    __x) { return vector_char(vector_short(__x)); }
static vector_char16 __SIMD_ATTRIBUTES__ vector_char(vector_uint16   __x) { return vector_char(vector_short(__x)); }
static vector_char2  __SIMD_ATTRIBUTES__ vector_char(vector_float2   __x) { return vector_char(vector_short(__x)); }
static vector_char3  __SIMD_ATTRIBUTES__ vector_char(vector_float3   __x) { return vector_char(vector_short(__x)); }
static vector_char4  __SIMD_ATTRIBUTES__ vector_char(vector_float4   __x) { return vector_char(vector_short(__x)); }
static vector_char8  __SIMD_ATTRIBUTES__ vector_char(vector_float8   __x) { return vector_char(vector_short(__x)); }
static vector_char16 __SIMD_ATTRIBUTES__ vector_char(vector_float16  __x) { return vector_char(vector_short(__x)); }
static vector_char2  __SIMD_ATTRIBUTES__ vector_char(vector_long2    __x) { return vector_char(vector_short(__x)); }
static vector_char3  __SIMD_ATTRIBUTES__ vector_char(vector_long3    __x) { return vector_char(vector_short(__x)); }
static vector_char4  __SIMD_ATTRIBUTES__ vector_char(vector_long4    __x) { return vector_char(vector_short(__x)); }
static vector_char8  __SIMD_ATTRIBUTES__ vector_char(vector_long8    __x) { return vector_char(vector_short(__x)); }
static vector_char2  __SIMD_ATTRIBUTES__ vector_char(vector_ulong2   __x) { return vector_char(vector_short(__x)); }
static vector_char3  __SIMD_ATTRIBUTES__ vector_char(vector_ulong3   __x) { return vector_char(vector_short(__x)); }
static vector_char4  __SIMD_ATTRIBUTES__ vector_char(vector_ulong4   __x) { return vector_char(vector_short(__x)); }
static vector_char8  __SIMD_ATTRIBUTES__ vector_char(vector_ulong8   __x) { return vector_char(vector_short(__x)); }
static vector_char2  __SIMD_ATTRIBUTES__ vector_char(vector_double2  __x) { return vector_char(vector_short(__x)); }
static vector_char3  __SIMD_ATTRIBUTES__ vector_char(vector_double3  __x) { return vector_char(vector_short(__x)); }
static vector_char4  __SIMD_ATTRIBUTES__ vector_char(vector_double4  __x) { return vector_char(vector_short(__x)); }
static vector_char8  __SIMD_ATTRIBUTES__ vector_char(vector_double8  __x) { return vector_char(vector_short(__x)); }
static vector_char2  __SIMD_ATTRIBUTES__ vector_char_sat(vector_char2    __x) { return __x; }
static vector_char3  __SIMD_ATTRIBUTES__ vector_char_sat(vector_char3    __x) { return __x; }
static vector_char4  __SIMD_ATTRIBUTES__ vector_char_sat(vector_char4    __x) { return __x; }
static vector_char8  __SIMD_ATTRIBUTES__ vector_char_sat(vector_char8    __x) { return __x; }
static vector_char16 __SIMD_ATTRIBUTES__ vector_char_sat(vector_char16   __x) { return __x; }
static vector_char32 __SIMD_ATTRIBUTES__ vector_char_sat(vector_char32   __x) { return __x; }
static vector_char2  __SIMD_ATTRIBUTES__ vector_char_sat(vector_short2   __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char3  __SIMD_ATTRIBUTES__ vector_char_sat(vector_short3   __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char4  __SIMD_ATTRIBUTES__ vector_char_sat(vector_short4   __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char8  __SIMD_ATTRIBUTES__ vector_char_sat(vector_short8   __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char16 __SIMD_ATTRIBUTES__ vector_char_sat(vector_short16  __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char32 __SIMD_ATTRIBUTES__ vector_char_sat(vector_short32  __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char2  __SIMD_ATTRIBUTES__ vector_char_sat(vector_int2     __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char3  __SIMD_ATTRIBUTES__ vector_char_sat(vector_int3     __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char4  __SIMD_ATTRIBUTES__ vector_char_sat(vector_int4     __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char8  __SIMD_ATTRIBUTES__ vector_char_sat(vector_int8     __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char16 __SIMD_ATTRIBUTES__ vector_char_sat(vector_int16    __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char2  __SIMD_ATTRIBUTES__ vector_char_sat(vector_float2   __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char3  __SIMD_ATTRIBUTES__ vector_char_sat(vector_float3   __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char4  __SIMD_ATTRIBUTES__ vector_char_sat(vector_float4   __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char8  __SIMD_ATTRIBUTES__ vector_char_sat(vector_float8   __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char16 __SIMD_ATTRIBUTES__ vector_char_sat(vector_float16  __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char2  __SIMD_ATTRIBUTES__ vector_char_sat(vector_long2    __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char3  __SIMD_ATTRIBUTES__ vector_char_sat(vector_long3    __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char4  __SIMD_ATTRIBUTES__ vector_char_sat(vector_long4    __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char8  __SIMD_ATTRIBUTES__ vector_char_sat(vector_long8    __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char2  __SIMD_ATTRIBUTES__ vector_char_sat(vector_double2  __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char3  __SIMD_ATTRIBUTES__ vector_char_sat(vector_double3  __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char4  __SIMD_ATTRIBUTES__ vector_char_sat(vector_double4  __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char8  __SIMD_ATTRIBUTES__ vector_char_sat(vector_double8  __x) { return vector_char(vector_clamp(__x,-0x80,0x7f)); }
static vector_char2  __SIMD_ATTRIBUTES__ vector_char_sat(vector_uchar2   __x) { return vector_char(vector_min(__x,0x7f)); }
static vector_char3  __SIMD_ATTRIBUTES__ vector_char_sat(vector_uchar3   __x) { return vector_char(vector_min(__x,0x7f)); }
static vector_char4  __SIMD_ATTRIBUTES__ vector_char_sat(vector_uchar4   __x) { return vector_char(vector_min(__x,0x7f)); }
static vector_char8  __SIMD_ATTRIBUTES__ vector_char_sat(vector_uchar8   __x) { return vector_char(vector_min(__x,0x7f)); }
static vector_char16 __SIMD_ATTRIBUTES__ vector_char_sat(vector_uchar16  __x) { return vector_char(vector_min(__x,0x7f)); }
static vector_char32 __SIMD_ATTRIBUTES__ vector_char_sat(vector_uchar32  __x) { return vector_char(vector_min(__x,0x7f)); }
static vector_char2  __SIMD_ATTRIBUTES__ vector_char_sat(vector_ushort2  __x) { return vector_char(vector_min(__x,0x7f)); }
static vector_char3  __SIMD_ATTRIBUTES__ vector_char_sat(vector_ushort3  __x) { return vector_char(vector_min(__x,0x7f)); }
static vector_char4  __SIMD_ATTRIBUTES__ vector_char_sat(vector_ushort4  __x) { return vector_char(vector_min(__x,0x7f)); }
static vector_char8  __SIMD_ATTRIBUTES__ vector_char_sat(vector_ushort8  __x) { return vector_char(vector_min(__x,0x7f)); }
static vector_char16 __SIMD_ATTRIBUTES__ vector_char_sat(vector_ushort16 __x) { return vector_char(vector_min(__x,0x7f)); }
static vector_char32 __SIMD_ATTRIBUTES__ vector_char_sat(vector_ushort32 __x) { return vector_char(vector_min(__x,0x7f)); }
static vector_char2  __SIMD_ATTRIBUTES__ vector_char_sat(vector_uint2    __x) { return vector_char(vector_min(__x,0x7f)); }
static vector_char3  __SIMD_ATTRIBUTES__ vector_char_sat(vector_uint3    __x) { return vector_char(vector_min(__x,0x7f)); }
static vector_char4  __SIMD_ATTRIBUTES__ vector_char_sat(vector_uint4    __x) { return vector_char(vector_min(__x,0x7f)); }
static vector_char8  __SIMD_ATTRIBUTES__ vector_char_sat(vector_uint8    __x) { return vector_char(vector_min(__x,0x7f)); }
static vector_char16 __SIMD_ATTRIBUTES__ vector_char_sat(vector_uint16   __x) { return vector_char(vector_min(__x,0x7f)); }
static vector_char2  __SIMD_ATTRIBUTES__ vector_char_sat(vector_ulong2   __x) { return vector_char(vector_min(__x,0x7f)); }
static vector_char3  __SIMD_ATTRIBUTES__ vector_char_sat(vector_ulong3   __x) { return vector_char(vector_min(__x,0x7f)); }
static vector_char4  __SIMD_ATTRIBUTES__ vector_char_sat(vector_ulong4   __x) { return vector_char(vector_min(__x,0x7f)); }
static vector_char8  __SIMD_ATTRIBUTES__ vector_char_sat(vector_ulong8   __x) { return vector_char(vector_min(__x,0x7f)); }

static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar(vector_char2    __x) { return (vector_uchar2)__x; }
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar(vector_char3    __x) { return (vector_uchar3)__x; }
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar(vector_char4    __x) { return (vector_uchar4)__x; }
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar(vector_char8    __x) { return (vector_uchar8)__x; }
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar(vector_char16   __x) { return (vector_uchar16)__x; }
static vector_uchar32 __SIMD_ATTRIBUTES__ vector_uchar(vector_char32   __x) { return (vector_uchar32)__x; }
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar(vector_uchar2   __x) { return __x; }
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar(vector_uchar3   __x) { return __x; }
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar(vector_uchar4   __x) { return __x; }
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar(vector_uchar8   __x) { return __x; }
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar(vector_uchar16  __x) { return __x; }
static vector_uchar32 __SIMD_ATTRIBUTES__ vector_uchar(vector_uchar32  __x) { return __x; }
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar(vector_short2   __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar(vector_short3   __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar(vector_short4   __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar(vector_short8   __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar(vector_short16  __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar32 __SIMD_ATTRIBUTES__ vector_uchar(vector_short32  __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar(vector_ushort2  __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar(vector_ushort3  __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar(vector_ushort4  __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar(vector_ushort8  __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar(vector_ushort16 __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar32 __SIMD_ATTRIBUTES__ vector_uchar(vector_ushort32 __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar(vector_int2     __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar(vector_int3     __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar(vector_int4     __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar(vector_int8     __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar(vector_int16    __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar(vector_uint2    __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar(vector_uint3    __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar(vector_uint4    __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar(vector_uint8    __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar(vector_uint16   __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar(vector_float2   __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar(vector_float3   __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar(vector_float4   __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar(vector_float8   __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar(vector_float16  __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar(vector_long2    __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar(vector_long3    __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar(vector_long4    __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar(vector_long8    __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar(vector_ulong2   __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar(vector_ulong3   __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar(vector_ulong4   __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar(vector_ulong8   __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar(vector_double2  __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar(vector_double3  __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar(vector_double4  __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar(vector_double8  __x) { return vector_uchar(vector_char(__x)); }
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_char2    __x) { return vector_uchar(vector_max(0,__x)); }
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_char3    __x) { return vector_uchar(vector_max(0,__x)); }
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_char4    __x) { return vector_uchar(vector_max(0,__x)); }
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_char8    __x) { return vector_uchar(vector_max(0,__x)); }
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_char16   __x) { return vector_uchar(vector_max(0,__x)); }
static vector_uchar32 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_char32   __x) { return vector_uchar(vector_max(0,__x)); }
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_short2   __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_short3   __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_short4   __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_short8   __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_short16  __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar32 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_short32  __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_int2     __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_int3     __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_int4     __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_int8     __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_int16    __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_float2   __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_float3   __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_float4   __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_float8   __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_float16  __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_long2    __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_long3    __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_long4    __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_long8    __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_double2  __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_double3  __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_double4  __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_double8  __x) { return vector_uchar(vector_clamp(__x,0,0x100)); }
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uchar2   __x) { return __x; }
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uchar3   __x) { return __x; }
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uchar4   __x) { return __x; }
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uchar8   __x) { return __x; }
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uchar16  __x) { return __x; }
static vector_uchar32 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uchar32  __x) { return __x; }
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_ushort2  __x) { return vector_uchar(vector_min(__x,0xff)); }
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_ushort3  __x) { return vector_uchar(vector_min(__x,0xff)); }
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_ushort4  __x) { return vector_uchar(vector_min(__x,0xff)); }
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_ushort8  __x) { return vector_uchar(vector_min(__x,0xff)); }
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_ushort16 __x) { return vector_uchar(vector_min(__x,0xff)); }
static vector_uchar32 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_ushort32 __x) { return vector_uchar(vector_min(__x,0xff)); }
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uint2    __x) { return vector_uchar(vector_min(__x,0xff)); }
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uint3    __x) { return vector_uchar(vector_min(__x,0xff)); }
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uint4    __x) { return vector_uchar(vector_min(__x,0xff)); }
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uint8    __x) { return vector_uchar(vector_min(__x,0xff)); }
static vector_uchar16 __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_uint16   __x) { return vector_uchar(vector_min(__x,0xff)); }
static vector_uchar2  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_ulong2   __x) { return vector_uchar(vector_min(__x,0xff)); }
static vector_uchar3  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_ulong3   __x) { return vector_uchar(vector_min(__x,0xff)); }
static vector_uchar4  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_ulong4   __x) { return vector_uchar(vector_min(__x,0xff)); }
static vector_uchar8  __SIMD_ATTRIBUTES__ vector_uchar_sat(vector_ulong8   __x) { return vector_uchar(vector_min(__x,0xff)); }

static vector_short2  __SIMD_ATTRIBUTES__ vector_short(vector_char2    __x) { vector_char4  __r; __r.odd = __x; return (vector_short2)__r >> (short)8; }
static vector_short3  __SIMD_ATTRIBUTES__ vector_short(vector_char3    __x) { vector_short4 __r = vector_short(__x.xyzz); return __r.xyz; }
static vector_short4  __SIMD_ATTRIBUTES__ vector_short(vector_char4    __x) { vector_char8  __r; __r.odd = __x; return (vector_short4)__r >> (short)8; }
static vector_short8  __SIMD_ATTRIBUTES__ vector_short(vector_char8    __x) { vector_char16 __r; __r.odd = __x; return (vector_short8)__r >> (short)8; }
static vector_short16 __SIMD_ATTRIBUTES__ vector_short(vector_char16   __x) { vector_char32 __r; __r.odd = __x; return (vector_short16)__r >> (short)8; }
static vector_short32 __SIMD_ATTRIBUTES__ vector_short(vector_char32   __x) { vector_short32 __r; __r.lo = vector_short(__x.lo); __r.hi = vector_short(__x.hi); return __r; }
static vector_short2  __SIMD_ATTRIBUTES__ vector_short(vector_uchar2   __x) { vector_uchar4  __r = 0; __r.even = __x; return (vector_short2)__r; }
static vector_short3  __SIMD_ATTRIBUTES__ vector_short(vector_uchar3   __x) { vector_short4 __r = vector_short(__x.xyzz); return __r.xyz; }
static vector_short4  __SIMD_ATTRIBUTES__ vector_short(vector_uchar4   __x) { vector_uchar8  __r = 0; __r.even = __x; return (vector_short4)__r; }
static vector_short8  __SIMD_ATTRIBUTES__ vector_short(vector_uchar8   __x) { vector_uchar16 __r = 0; __r.even = __x; return (vector_short8)__r; }
static vector_short16 __SIMD_ATTRIBUTES__ vector_short(vector_uchar16  __x) { vector_uchar32 __r = 0; __r.even = __x; return (vector_short16)__r; }
static vector_short32 __SIMD_ATTRIBUTES__ vector_short(vector_uchar32  __x) { vector_short32 __r; __r.lo = vector_short(__x.lo); __r.hi = vector_short(__x.hi); return __r; }
static vector_short2  __SIMD_ATTRIBUTES__ vector_short(vector_short2   __x) { return __x; }
static vector_short3  __SIMD_ATTRIBUTES__ vector_short(vector_short3   __x) { return __x; }
static vector_short4  __SIMD_ATTRIBUTES__ vector_short(vector_short4   __x) { return __x; }
static vector_short8  __SIMD_ATTRIBUTES__ vector_short(vector_short8   __x) { return __x; }
static vector_short16 __SIMD_ATTRIBUTES__ vector_short(vector_short16  __x) { return __x; }
static vector_short32 __SIMD_ATTRIBUTES__ vector_short(vector_short32  __x) { return __x; }
static vector_short2  __SIMD_ATTRIBUTES__ vector_short(vector_ushort2  __x) { return (vector_short2)__x; }
static vector_short3  __SIMD_ATTRIBUTES__ vector_short(vector_ushort3  __x) { return (vector_short3)__x; }
static vector_short4  __SIMD_ATTRIBUTES__ vector_short(vector_ushort4  __x) { return (vector_short4)__x; }
static vector_short8  __SIMD_ATTRIBUTES__ vector_short(vector_ushort8  __x) { return (vector_short8)__x; }
static vector_short16 __SIMD_ATTRIBUTES__ vector_short(vector_ushort16 __x) { return (vector_short16)__x; }
static vector_short32 __SIMD_ATTRIBUTES__ vector_short(vector_ushort32 __x) { return (vector_short32)__x; }
static vector_short2  __SIMD_ATTRIBUTES__ vector_short(vector_int2     __x) { return ((vector_short4)__x).even; }
static vector_short3  __SIMD_ATTRIBUTES__ vector_short(vector_int3     __x) { vector_short4 __r = vector_short(__x.xyzz); return __r.xyz; }
static vector_short4  __SIMD_ATTRIBUTES__ vector_short(vector_int4     __x) { return ((vector_short8)__x).even; }
static vector_short8  __SIMD_ATTRIBUTES__ vector_short(vector_int8     __x) { return ((vector_short16)__x).even; }
static vector_short16 __SIMD_ATTRIBUTES__ vector_short(vector_int16    __x) { return ((vector_short32)__x).even; }
static vector_short2  __SIMD_ATTRIBUTES__ vector_short(vector_uint2    __x) { return vector_short(vector_int(__x)); }
static vector_short3  __SIMD_ATTRIBUTES__ vector_short(vector_uint3    __x) { return vector_short(vector_int(__x)); }
static vector_short4  __SIMD_ATTRIBUTES__ vector_short(vector_uint4    __x) { return vector_short(vector_int(__x)); }
static vector_short8  __SIMD_ATTRIBUTES__ vector_short(vector_uint8    __x) { return vector_short(vector_int(__x)); }
static vector_short16 __SIMD_ATTRIBUTES__ vector_short(vector_uint16   __x) { return vector_short(vector_int(__x)); }
static vector_short2  __SIMD_ATTRIBUTES__ vector_short(vector_float2   __x) { return vector_short(vector_int(__x)); }
static vector_short3  __SIMD_ATTRIBUTES__ vector_short(vector_float3   __x) { return vector_short(vector_int(__x)); }
static vector_short4  __SIMD_ATTRIBUTES__ vector_short(vector_float4   __x) { return vector_short(vector_int(__x)); }
static vector_short8  __SIMD_ATTRIBUTES__ vector_short(vector_float8   __x) { return vector_short(vector_int(__x)); }
static vector_short16 __SIMD_ATTRIBUTES__ vector_short(vector_float16  __x) { return vector_short(vector_int(__x)); }
static vector_short2  __SIMD_ATTRIBUTES__ vector_short(vector_long2    __x) { return vector_short(vector_int(__x)); }
static vector_short3  __SIMD_ATTRIBUTES__ vector_short(vector_long3    __x) { return vector_short(vector_int(__x)); }
static vector_short4  __SIMD_ATTRIBUTES__ vector_short(vector_long4    __x) { return vector_short(vector_int(__x)); }
static vector_short8  __SIMD_ATTRIBUTES__ vector_short(vector_long8    __x) { return vector_short(vector_int(__x)); }
static vector_short2  __SIMD_ATTRIBUTES__ vector_short(vector_ulong2   __x) { return vector_short(vector_int(__x)); }
static vector_short3  __SIMD_ATTRIBUTES__ vector_short(vector_ulong3   __x) { return vector_short(vector_int(__x)); }
static vector_short4  __SIMD_ATTRIBUTES__ vector_short(vector_ulong4   __x) { return vector_short(vector_int(__x)); }
static vector_short8  __SIMD_ATTRIBUTES__ vector_short(vector_ulong8   __x) { return vector_short(vector_int(__x)); }
static vector_short2  __SIMD_ATTRIBUTES__ vector_short(vector_double2  __x) { return vector_short(vector_int(__x)); }
static vector_short3  __SIMD_ATTRIBUTES__ vector_short(vector_double3  __x) { return vector_short(vector_int(__x)); }
static vector_short4  __SIMD_ATTRIBUTES__ vector_short(vector_double4  __x) { return vector_short(vector_int(__x)); }
static vector_short8  __SIMD_ATTRIBUTES__ vector_short(vector_double8  __x) { return vector_short(vector_int(__x)); }
static vector_short2  __SIMD_ATTRIBUTES__ vector_short_sat(vector_char2    __x) { return vector_short(__x); }
static vector_short3  __SIMD_ATTRIBUTES__ vector_short_sat(vector_char3    __x) { return vector_short(__x); }
static vector_short4  __SIMD_ATTRIBUTES__ vector_short_sat(vector_char4    __x) { return vector_short(__x); }
static vector_short8  __SIMD_ATTRIBUTES__ vector_short_sat(vector_char8    __x) { return vector_short(__x); }
static vector_short16 __SIMD_ATTRIBUTES__ vector_short_sat(vector_char16   __x) { return vector_short(__x); }
static vector_short32 __SIMD_ATTRIBUTES__ vector_short_sat(vector_char32   __x) { return vector_short(__x); }
static vector_short2  __SIMD_ATTRIBUTES__ vector_short_sat(vector_short2   __x) { return __x; }
static vector_short3  __SIMD_ATTRIBUTES__ vector_short_sat(vector_short3   __x) { return __x; }
static vector_short4  __SIMD_ATTRIBUTES__ vector_short_sat(vector_short4   __x) { return __x; }
static vector_short8  __SIMD_ATTRIBUTES__ vector_short_sat(vector_short8   __x) { return __x; }
static vector_short16 __SIMD_ATTRIBUTES__ vector_short_sat(vector_short16  __x) { return __x; }
static vector_short32 __SIMD_ATTRIBUTES__ vector_short_sat(vector_short32  __x) { return __x; }
static vector_short2  __SIMD_ATTRIBUTES__ vector_short_sat(vector_int2     __x) { return vector_short(vector_clamp(__x,-0x8000,0x7fff)); }
static vector_short3  __SIMD_ATTRIBUTES__ vector_short_sat(vector_int3     __x) { return vector_short(vector_clamp(__x,-0x8000,0x7fff)); }
static vector_short4  __SIMD_ATTRIBUTES__ vector_short_sat(vector_int4     __x) { return vector_short(vector_clamp(__x,-0x8000,0x7fff)); }
static vector_short8  __SIMD_ATTRIBUTES__ vector_short_sat(vector_int8     __x) { return vector_short(vector_clamp(__x,-0x8000,0x7fff)); }
static vector_short16 __SIMD_ATTRIBUTES__ vector_short_sat(vector_int16    __x) { return vector_short(vector_clamp(__x,-0x8000,0x7fff)); }
static vector_short2  __SIMD_ATTRIBUTES__ vector_short_sat(vector_float2   __x) { return vector_short(vector_clamp(__x,-0x8000,0x7fff)); }
static vector_short3  __SIMD_ATTRIBUTES__ vector_short_sat(vector_float3   __x) { return vector_short(vector_clamp(__x,-0x8000,0x7fff)); }
static vector_short4  __SIMD_ATTRIBUTES__ vector_short_sat(vector_float4   __x) { return vector_short(vector_clamp(__x,-0x8000,0x7fff)); }
static vector_short8  __SIMD_ATTRIBUTES__ vector_short_sat(vector_float8   __x) { return vector_short(vector_clamp(__x,-0x8000,0x7fff)); }
static vector_short16 __SIMD_ATTRIBUTES__ vector_short_sat(vector_float16  __x) { return vector_short(vector_clamp(__x,-0x8000,0x7fff)); }
static vector_short2  __SIMD_ATTRIBUTES__ vector_short_sat(vector_long2    __x) { return vector_short(vector_clamp(__x,-0x8000,0x7fff)); }
static vector_short3  __SIMD_ATTRIBUTES__ vector_short_sat(vector_long3    __x) { return vector_short(vector_clamp(__x,-0x8000,0x7fff)); }
static vector_short4  __SIMD_ATTRIBUTES__ vector_short_sat(vector_long4    __x) { return vector_short(vector_clamp(__x,-0x8000,0x7fff)); }
static vector_short8  __SIMD_ATTRIBUTES__ vector_short_sat(vector_long8    __x) { return vector_short(vector_clamp(__x,-0x8000,0x7fff)); }
static vector_short2  __SIMD_ATTRIBUTES__ vector_short_sat(vector_double2  __x) { return vector_short(vector_clamp(__x,-0x8000,0x7fff)); }
static vector_short3  __SIMD_ATTRIBUTES__ vector_short_sat(vector_double3  __x) { return vector_short(vector_clamp(__x,-0x8000,0x7fff)); }
static vector_short4  __SIMD_ATTRIBUTES__ vector_short_sat(vector_double4  __x) { return vector_short(vector_clamp(__x,-0x8000,0x7fff)); }
static vector_short8  __SIMD_ATTRIBUTES__ vector_short_sat(vector_double8  __x) { return vector_short(vector_clamp(__x,-0x8000,0x7fff)); }
static vector_short2  __SIMD_ATTRIBUTES__ vector_short_sat(vector_uchar2   __x) { return vector_short(__x); }
static vector_short3  __SIMD_ATTRIBUTES__ vector_short_sat(vector_uchar3   __x) { return vector_short(__x); }
static vector_short4  __SIMD_ATTRIBUTES__ vector_short_sat(vector_uchar4   __x) { return vector_short(__x); }
static vector_short8  __SIMD_ATTRIBUTES__ vector_short_sat(vector_uchar8   __x) { return vector_short(__x); }
static vector_short16 __SIMD_ATTRIBUTES__ vector_short_sat(vector_uchar16  __x) { return vector_short(__x); }
static vector_short32 __SIMD_ATTRIBUTES__ vector_short_sat(vector_uchar32  __x) { return vector_short(__x); }
static vector_short2  __SIMD_ATTRIBUTES__ vector_short_sat(vector_ushort2  __x) { return vector_short(vector_min(__x,0x7fff)); }
static vector_short3  __SIMD_ATTRIBUTES__ vector_short_sat(vector_ushort3  __x) { return vector_short(vector_min(__x,0x7fff)); }
static vector_short4  __SIMD_ATTRIBUTES__ vector_short_sat(vector_ushort4  __x) { return vector_short(vector_min(__x,0x7fff)); }
static vector_short8  __SIMD_ATTRIBUTES__ vector_short_sat(vector_ushort8  __x) { return vector_short(vector_min(__x,0x7fff)); }
static vector_short16 __SIMD_ATTRIBUTES__ vector_short_sat(vector_ushort16 __x) { return vector_short(vector_min(__x,0x7fff)); }
static vector_short32 __SIMD_ATTRIBUTES__ vector_short_sat(vector_ushort32 __x) { return vector_short(vector_min(__x,0x7fff)); }
static vector_short2  __SIMD_ATTRIBUTES__ vector_short_sat(vector_uint2    __x) { return vector_short(vector_min(__x,0x7fff)); }
static vector_short3  __SIMD_ATTRIBUTES__ vector_short_sat(vector_uint3    __x) { return vector_short(vector_min(__x,0x7fff)); }
static vector_short4  __SIMD_ATTRIBUTES__ vector_short_sat(vector_uint4    __x) { return vector_short(vector_min(__x,0x7fff)); }
static vector_short8  __SIMD_ATTRIBUTES__ vector_short_sat(vector_uint8    __x) { return vector_short(vector_min(__x,0x7fff)); }
static vector_short16 __SIMD_ATTRIBUTES__ vector_short_sat(vector_uint16   __x) { return vector_short(vector_min(__x,0x7fff)); }
static vector_short2  __SIMD_ATTRIBUTES__ vector_short_sat(vector_ulong2   __x) { return vector_short(vector_min(__x,0x7fff)); }
static vector_short3  __SIMD_ATTRIBUTES__ vector_short_sat(vector_ulong3   __x) { return vector_short(vector_min(__x,0x7fff)); }
static vector_short4  __SIMD_ATTRIBUTES__ vector_short_sat(vector_ulong4   __x) { return vector_short(vector_min(__x,0x7fff)); }
static vector_short8  __SIMD_ATTRIBUTES__ vector_short_sat(vector_ulong8   __x) { return vector_short(vector_min(__x,0x7fff)); }

static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort(vector_char2    __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort(vector_char3    __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort(vector_char4    __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort(vector_char8    __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort(vector_char16   __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort32 __SIMD_ATTRIBUTES__ vector_ushort(vector_char32   __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort(vector_uchar2   __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort(vector_uchar3   __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort(vector_uchar4   __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort(vector_uchar8   __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort(vector_uchar16  __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort32 __SIMD_ATTRIBUTES__ vector_ushort(vector_uchar32  __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort(vector_short2   __x) { return (vector_ushort2)__x; }
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort(vector_short3   __x) { return (vector_ushort3)__x; }
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort(vector_short4   __x) { return (vector_ushort4)__x; }
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort(vector_short8   __x) { return (vector_ushort8)__x; }
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort(vector_short16  __x) { return (vector_ushort16)__x; }
static vector_ushort32 __SIMD_ATTRIBUTES__ vector_ushort(vector_short32  __x) { return (vector_ushort32)__x; }
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort(vector_ushort2  __x) { return __x; }
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort(vector_ushort3  __x) { return __x; }
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort(vector_ushort4  __x) { return __x; }
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort(vector_ushort8  __x) { return __x; }
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort(vector_ushort16 __x) { return __x; }
static vector_ushort32 __SIMD_ATTRIBUTES__ vector_ushort(vector_ushort32 __x) { return __x; }
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort(vector_int2     __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort(vector_int3     __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort(vector_int4     __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort(vector_int8     __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort(vector_int16    __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort(vector_uint2    __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort(vector_uint3    __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort(vector_uint4    __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort(vector_uint8    __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort(vector_uint16   __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort(vector_float2   __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort(vector_float3   __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort(vector_float4   __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort(vector_float8   __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort(vector_float16  __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort(vector_long2    __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort(vector_long3    __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort(vector_long4    __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort(vector_long8    __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort(vector_ulong2   __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort(vector_ulong3   __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort(vector_ulong4   __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort(vector_ulong8   __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort(vector_double2  __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort(vector_double3  __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort(vector_double4  __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort(vector_double8  __x) { return vector_ushort(vector_short(__x)); }
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_char2    __x) { return vector_ushort(vector_max(__x, 0)); }
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_char3    __x) { return vector_ushort(vector_max(__x, 0)); }
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_char4    __x) { return vector_ushort(vector_max(__x, 0)); }
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_char8    __x) { return vector_ushort(vector_max(__x, 0)); }
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_char16   __x) { return vector_ushort(vector_max(__x, 0)); }
static vector_ushort32 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_char32   __x) { return vector_ushort(vector_max(__x, 0)); }
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_short2   __x) { return vector_ushort(vector_max(__x, 0)); }
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_short3   __x) { return vector_ushort(vector_max(__x, 0)); }
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_short4   __x) { return vector_ushort(vector_max(__x, 0)); }
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_short8   __x) { return vector_ushort(vector_max(__x, 0)); }
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_short16  __x) { return vector_ushort(vector_max(__x, 0)); }
static vector_ushort32 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_short32  __x) { return vector_ushort(vector_max(__x, 0)); }
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_int2     __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_int3     __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_int4     __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_int8     __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_int16    __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_float2   __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_float3   __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_float4   __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_float8   __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_float16  __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_long2    __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_long3    __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_long4    __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_long8    __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_double2  __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_double3  __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_double4  __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_double8  __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uchar2   __x) { return vector_ushort(__x); }
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uchar3   __x) { return vector_ushort(__x); }
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uchar4   __x) { return vector_ushort(__x); }
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uchar8   __x) { return vector_ushort(__x); }
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uchar16  __x) { return vector_ushort(__x); }
static vector_ushort32 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uchar32  __x) { return vector_ushort(__x); }
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_ushort2  __x) { return __x; }
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_ushort3  __x) { return __x; }
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_ushort4  __x) { return __x; }
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_ushort8  __x) { return __x; }
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_ushort16 __x) { return __x; }
static vector_ushort32 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_ushort32 __x) { return __x; }
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uint2    __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uint3    __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uint4    __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uint8    __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort16 __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_uint16   __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort2  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_ulong2   __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort3  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_ulong3   __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort4  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_ulong4   __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }
static vector_ushort8  __SIMD_ATTRIBUTES__ vector_ushort_sat(vector_ulong8   __x) { return vector_ushort(vector_clamp(__x, 0, 0xffff)); }

static vector_int2  __SIMD_ATTRIBUTES__ vector_int(vector_char2    __x) { vector_char8 __r; __r.odd.odd = __x; return (vector_int2)__r >> 24; }
static vector_int3  __SIMD_ATTRIBUTES__ vector_int(vector_char3    __x) { vector_int4 __r = vector_int(__x.xyzz); return __r.xyz; }
static vector_int4  __SIMD_ATTRIBUTES__ vector_int(vector_char4    __x) { vector_char16 __r; __r.odd.odd = __x; return (vector_int4)__r >> 24; }
static vector_int8  __SIMD_ATTRIBUTES__ vector_int(vector_char8    __x) { vector_char32 __r; __r.odd.odd = __x; return (vector_int8)__r >> 24; }
static vector_int16 __SIMD_ATTRIBUTES__ vector_int(vector_char16   __x) { vector_int16 __r; __r.lo = vector_int(__x.lo); __r.hi = vector_int(__x.hi); return __r; }
static vector_int2  __SIMD_ATTRIBUTES__ vector_int(vector_uchar2   __x) { vector_uchar8 __r = 0; __r.even.even = __x; return (vector_int2)__r; }
static vector_int3  __SIMD_ATTRIBUTES__ vector_int(vector_uchar3   __x) { vector_int4 __r = vector_int(__x.xyzz); return __r.xyz; }
static vector_int4  __SIMD_ATTRIBUTES__ vector_int(vector_uchar4   __x) { vector_uchar16 __r = 0; __r.even.even = __x; return (vector_int4)__r; }
static vector_int8  __SIMD_ATTRIBUTES__ vector_int(vector_uchar8   __x) { vector_uchar32 __r = 0; __r.even.even = __x; return (vector_int8)__r; }
static vector_int16 __SIMD_ATTRIBUTES__ vector_int(vector_uchar16  __x) { vector_int16 __r; __r.lo = vector_int(__x.lo); __r.hi = vector_int(__x.hi); return __r; }
static vector_int2  __SIMD_ATTRIBUTES__ vector_int(vector_short2   __x) { vector_short4 __r; __r.odd = __x; return (vector_int2)__r >> 16; }
static vector_int3  __SIMD_ATTRIBUTES__ vector_int(vector_short3   __x) { vector_int4 __r = vector_int(__x.xyzz); return __r.xyz; }
static vector_int4  __SIMD_ATTRIBUTES__ vector_int(vector_short4   __x) { vector_short8 __r; __r.odd = __x; return (vector_int4)__r >> 16; }
static vector_int8  __SIMD_ATTRIBUTES__ vector_int(vector_short8   __x) { vector_short16 __r; __r.odd = __x; return (vector_int8)__r >> 16; }
static vector_int16 __SIMD_ATTRIBUTES__ vector_int(vector_short16  __x) { vector_short32 __r; __r.odd = __x; return (vector_int16)__r >> 16; }
static vector_int2  __SIMD_ATTRIBUTES__ vector_int(vector_ushort2  __x) { vector_ushort4 __r = 0; __r.even = __x; return (vector_int2)__r; }
static vector_int3  __SIMD_ATTRIBUTES__ vector_int(vector_ushort3  __x) { vector_int4 __r = vector_int(__x.xyzz); return __r.xyz; }
static vector_int4  __SIMD_ATTRIBUTES__ vector_int(vector_ushort4  __x) { vector_ushort8 __r = 0; __r.even = __x; return (vector_int4)__r; }
static vector_int8  __SIMD_ATTRIBUTES__ vector_int(vector_ushort8  __x) { vector_ushort16 __r = 0; __r.even = __x; return (vector_int8)__r; }
static vector_int16 __SIMD_ATTRIBUTES__ vector_int(vector_ushort16 __x) { vector_ushort32 __r = 0; __r.even = __x; return (vector_int16)__r; }
static vector_int2  __SIMD_ATTRIBUTES__ vector_int(vector_int2     __x) { return __x; }
static vector_int3  __SIMD_ATTRIBUTES__ vector_int(vector_int3     __x) { return __x; }
static vector_int4  __SIMD_ATTRIBUTES__ vector_int(vector_int4     __x) { return __x; }
static vector_int8  __SIMD_ATTRIBUTES__ vector_int(vector_int8     __x) { return __x; }
static vector_int16 __SIMD_ATTRIBUTES__ vector_int(vector_int16    __x) { return __x; }
static vector_int2  __SIMD_ATTRIBUTES__ vector_int(vector_uint2    __x) { return (vector_int2)__x; }
static vector_int3  __SIMD_ATTRIBUTES__ vector_int(vector_uint3    __x) { return (vector_int3)__x; }
static vector_int4  __SIMD_ATTRIBUTES__ vector_int(vector_uint4    __x) { return (vector_int4)__x; }
static vector_int8  __SIMD_ATTRIBUTES__ vector_int(vector_uint8    __x) { return (vector_int8)__x; }
static vector_int16 __SIMD_ATTRIBUTES__ vector_int(vector_uint16   __x) { return (vector_int16)__x; }
static vector_int2  __SIMD_ATTRIBUTES__ vector_int(vector_float2   __x) { return __builtin_convertvector(__x,vector_int2); }
static vector_int3  __SIMD_ATTRIBUTES__ vector_int(vector_float3   __x) { return __builtin_convertvector(__x,vector_int3); }
static vector_int4  __SIMD_ATTRIBUTES__ vector_int(vector_float4   __x) { return __builtin_convertvector(__x,vector_int4); }
static vector_int8  __SIMD_ATTRIBUTES__ vector_int(vector_float8   __x) { return __builtin_convertvector(__x,vector_int8); }
static vector_int16 __SIMD_ATTRIBUTES__ vector_int(vector_float16  __x) { return __builtin_convertvector(__x,vector_int16); }
static vector_int2  __SIMD_ATTRIBUTES__ vector_int(vector_long2    __x) { return ((vector_int4)__x).even; }
static vector_int3  __SIMD_ATTRIBUTES__ vector_int(vector_long3    __x) { vector_int4 __r = vector_int(__x.xyzz); return __r.xyz; }
static vector_int4  __SIMD_ATTRIBUTES__ vector_int(vector_long4    __x) { return ((vector_int8)__x).even; }
static vector_int8  __SIMD_ATTRIBUTES__ vector_int(vector_long8    __x) { return ((vector_int16)__x).even; }
static vector_int2  __SIMD_ATTRIBUTES__ vector_int(vector_ulong2   __x) { return vector_int(vector_long(__x)); }
static vector_int3  __SIMD_ATTRIBUTES__ vector_int(vector_ulong3   __x) { return vector_int(vector_long(__x)); }
static vector_int4  __SIMD_ATTRIBUTES__ vector_int(vector_ulong4   __x) { return vector_int(vector_long(__x)); }
static vector_int8  __SIMD_ATTRIBUTES__ vector_int(vector_ulong8   __x) { return vector_int(vector_long(__x)); }
static vector_int2  __SIMD_ATTRIBUTES__ vector_int(vector_double2  __x) { return __builtin_convertvector(__x,vector_int2); }
static vector_int3  __SIMD_ATTRIBUTES__ vector_int(vector_double3  __x) { return __builtin_convertvector(__x,vector_int3); }
static vector_int4  __SIMD_ATTRIBUTES__ vector_int(vector_double4  __x) { return __builtin_convertvector(__x,vector_int4); }
static vector_int8  __SIMD_ATTRIBUTES__ vector_int(vector_double8  __x) { return __builtin_convertvector(__x,vector_int8); }
static vector_int2  __SIMD_ATTRIBUTES__ vector_int_sat(vector_char2    __x) { return vector_int(__x); }
static vector_int3  __SIMD_ATTRIBUTES__ vector_int_sat(vector_char3    __x) { return vector_int(__x); }
static vector_int4  __SIMD_ATTRIBUTES__ vector_int_sat(vector_char4    __x) { return vector_int(__x); }
static vector_int8  __SIMD_ATTRIBUTES__ vector_int_sat(vector_char8    __x) { return vector_int(__x); }
static vector_int16 __SIMD_ATTRIBUTES__ vector_int_sat(vector_char16   __x) { return vector_int(__x); }
static vector_int2  __SIMD_ATTRIBUTES__ vector_int_sat(vector_short2   __x) { return vector_int(__x); }
static vector_int3  __SIMD_ATTRIBUTES__ vector_int_sat(vector_short3   __x) { return vector_int(__x); }
static vector_int4  __SIMD_ATTRIBUTES__ vector_int_sat(vector_short4   __x) { return vector_int(__x); }
static vector_int8  __SIMD_ATTRIBUTES__ vector_int_sat(vector_short8   __x) { return vector_int(__x); }
static vector_int16 __SIMD_ATTRIBUTES__ vector_int_sat(vector_short16  __x) { return vector_int(__x); }
static vector_int2  __SIMD_ATTRIBUTES__ vector_int_sat(vector_int2     __x) { return __x; }
static vector_int3  __SIMD_ATTRIBUTES__ vector_int_sat(vector_int3     __x) { return __x; }
static vector_int4  __SIMD_ATTRIBUTES__ vector_int_sat(vector_int4     __x) { return __x; }
static vector_int8  __SIMD_ATTRIBUTES__ vector_int_sat(vector_int8     __x) { return __x; }
static vector_int16 __SIMD_ATTRIBUTES__ vector_int_sat(vector_int16    __x) { return __x; }
static vector_int2  __SIMD_ATTRIBUTES__ vector_int_sat(vector_float2   __x) { return vector_bitselect(vector_int(vector_max(__x,-0x1.0p31f)), 0x7fffffff, __x >= 0x1.0p31f); }
static vector_int3  __SIMD_ATTRIBUTES__ vector_int_sat(vector_float3   __x) { return vector_bitselect(vector_int(vector_max(__x,-0x1.0p31f)), 0x7fffffff, __x >= 0x1.0p31f); }
static vector_int4  __SIMD_ATTRIBUTES__ vector_int_sat(vector_float4   __x) { return vector_bitselect(vector_int(vector_max(__x,-0x1.0p31f)), 0x7fffffff, __x >= 0x1.0p31f); }
static vector_int8  __SIMD_ATTRIBUTES__ vector_int_sat(vector_float8   __x) { return vector_bitselect(vector_int(vector_max(__x,-0x1.0p31f)), 0x7fffffff, __x >= 0x1.0p31f); }
static vector_int16 __SIMD_ATTRIBUTES__ vector_int_sat(vector_float16  __x) { return vector_bitselect(vector_int(vector_max(__x,-0x1.0p31f)), 0x7fffffff, __x >= 0x1.0p31f); }
static vector_int2  __SIMD_ATTRIBUTES__ vector_int_sat(vector_long2    __x) { return vector_int(vector_clamp(__x,-0x80000000,0x7fffffff)); }
static vector_int3  __SIMD_ATTRIBUTES__ vector_int_sat(vector_long3    __x) { return vector_int(vector_clamp(__x,-0x80000000,0x7fffffff)); }
static vector_int4  __SIMD_ATTRIBUTES__ vector_int_sat(vector_long4    __x) { return vector_int(vector_clamp(__x,-0x80000000,0x7fffffff)); }
static vector_int8  __SIMD_ATTRIBUTES__ vector_int_sat(vector_long8    __x) { return vector_int(vector_clamp(__x,-0x80000000,0x7fffffff)); }
static vector_int2  __SIMD_ATTRIBUTES__ vector_int_sat(vector_double2  __x) { return vector_int(vector_clamp(__x,-0x1.0p31,0x1.fffffffcp30)); }
static vector_int3  __SIMD_ATTRIBUTES__ vector_int_sat(vector_double3  __x) { return vector_int(vector_clamp(__x,-0x1.0p31,0x1.fffffffcp30)); }
static vector_int4  __SIMD_ATTRIBUTES__ vector_int_sat(vector_double4  __x) { return vector_int(vector_clamp(__x,-0x1.0p31,0x1.fffffffcp30)); }
static vector_int8  __SIMD_ATTRIBUTES__ vector_int_sat(vector_double8  __x) { return vector_int(vector_clamp(__x,-0x1.0p31,0x1.fffffffcp30)); }
static vector_int2  __SIMD_ATTRIBUTES__ vector_int_sat(vector_uchar2   __x) { return vector_int(__x); }
static vector_int3  __SIMD_ATTRIBUTES__ vector_int_sat(vector_uchar3   __x) { return vector_int(__x); }
static vector_int4  __SIMD_ATTRIBUTES__ vector_int_sat(vector_uchar4   __x) { return vector_int(__x); }
static vector_int8  __SIMD_ATTRIBUTES__ vector_int_sat(vector_uchar8   __x) { return vector_int(__x); }
static vector_int16 __SIMD_ATTRIBUTES__ vector_int_sat(vector_uchar16  __x) { return vector_int(__x); }
static vector_int2  __SIMD_ATTRIBUTES__ vector_int_sat(vector_ushort2  __x) { return vector_int(__x); }
static vector_int3  __SIMD_ATTRIBUTES__ vector_int_sat(vector_ushort3  __x) { return vector_int(__x); }
static vector_int4  __SIMD_ATTRIBUTES__ vector_int_sat(vector_ushort4  __x) { return vector_int(__x); }
static vector_int8  __SIMD_ATTRIBUTES__ vector_int_sat(vector_ushort8  __x) { return vector_int(__x); }
static vector_int16 __SIMD_ATTRIBUTES__ vector_int_sat(vector_ushort16 __x) { return vector_int(__x); }
static vector_int2  __SIMD_ATTRIBUTES__ vector_int_sat(vector_uint2    __x) { return vector_int(vector_min(__x,0x7fffffff)); }
static vector_int3  __SIMD_ATTRIBUTES__ vector_int_sat(vector_uint3    __x) { return vector_int(vector_min(__x,0x7fffffff)); }
static vector_int4  __SIMD_ATTRIBUTES__ vector_int_sat(vector_uint4    __x) { return vector_int(vector_min(__x,0x7fffffff)); }
static vector_int8  __SIMD_ATTRIBUTES__ vector_int_sat(vector_uint8    __x) { return vector_int(vector_min(__x,0x7fffffff)); }
static vector_int16 __SIMD_ATTRIBUTES__ vector_int_sat(vector_uint16   __x) { return vector_int(vector_min(__x,0x7fffffff)); }
static vector_int2  __SIMD_ATTRIBUTES__ vector_int_sat(vector_ulong2   __x) { return vector_int(vector_min(__x,0x7fffffff)); }
static vector_int3  __SIMD_ATTRIBUTES__ vector_int_sat(vector_ulong3   __x) { return vector_int(vector_min(__x,0x7fffffff)); }
static vector_int4  __SIMD_ATTRIBUTES__ vector_int_sat(vector_ulong4   __x) { return vector_int(vector_min(__x,0x7fffffff)); }
static vector_int8  __SIMD_ATTRIBUTES__ vector_int_sat(vector_ulong8   __x) { return vector_int(vector_min(__x,0x7fffffff)); }

static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint(vector_char2    __x) { return vector_uint(vector_int(__x)); }
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint(vector_char3    __x) { return vector_uint(vector_int(__x)); }
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint(vector_char4    __x) { return vector_uint(vector_int(__x)); }
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint(vector_char8    __x) { return vector_uint(vector_int(__x)); }
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint(vector_char16   __x) { return vector_uint(vector_int(__x)); }
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint(vector_uchar2   __x) { return vector_uint(vector_int(__x)); }
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint(vector_uchar3   __x) { return vector_uint(vector_int(__x)); }
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint(vector_uchar4   __x) { return vector_uint(vector_int(__x)); }
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint(vector_uchar8   __x) { return vector_uint(vector_int(__x)); }
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint(vector_uchar16  __x) { return vector_uint(vector_int(__x)); }
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint(vector_short2   __x) { return vector_uint(vector_int(__x)); }
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint(vector_short3   __x) { return vector_uint(vector_int(__x)); }
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint(vector_short4   __x) { return vector_uint(vector_int(__x)); }
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint(vector_short8   __x) { return vector_uint(vector_int(__x)); }
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint(vector_short16  __x) { return vector_uint(vector_int(__x)); }
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint(vector_ushort2  __x) { return vector_uint(vector_int(__x)); }
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint(vector_ushort3  __x) { return vector_uint(vector_int(__x)); }
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint(vector_ushort4  __x) { return vector_uint(vector_int(__x)); }
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint(vector_ushort8  __x) { return vector_uint(vector_int(__x)); }
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint(vector_ushort16 __x) { return vector_uint(vector_int(__x)); }
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint(vector_int2     __x) { return (vector_uint2)__x; }
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint(vector_int3     __x) { return (vector_uint3)__x; }
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint(vector_int4     __x) { return (vector_uint4)__x; }
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint(vector_int8     __x) { return (vector_uint8)__x; }
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint(vector_int16    __x) { return (vector_uint16)__x; }
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint(vector_uint2    __x) { return __x; }
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint(vector_uint3    __x) { return __x; }
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint(vector_uint4    __x) { return __x; }
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint(vector_uint8    __x) { return __x; }
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint(vector_uint16   __x) { return __x; }
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint(vector_float2   __x) { vector_int2  __big = __x > 0x1.0p31f; return vector_uint(vector_int(__x - vector_bitselect((vector_float2)0,0x1.0p31f,__big))) + vector_bitselect((vector_uint2)0,0x80000000,__big); }
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint(vector_float3   __x) { vector_int3  __big = __x > 0x1.0p31f; return vector_uint(vector_int(__x - vector_bitselect((vector_float3)0,0x1.0p31f,__big))) + vector_bitselect((vector_uint3)0,0x80000000,__big); }
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint(vector_float4   __x) { vector_int4  __big = __x > 0x1.0p31f; return vector_uint(vector_int(__x - vector_bitselect((vector_float4)0,0x1.0p31f,__big))) + vector_bitselect((vector_uint4)0,0x80000000,__big); }
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint(vector_float8   __x) { vector_int8  __big = __x > 0x1.0p31f; return vector_uint(vector_int(__x - vector_bitselect((vector_float8)0,0x1.0p31f,__big))) + vector_bitselect((vector_uint8)0,0x80000000,__big); }
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint(vector_float16  __x) { vector_int16 __big = __x > 0x1.0p31f; return vector_uint(vector_int(__x - vector_bitselect((vector_float16)0,0x1.0p31f,__big))) + vector_bitselect((vector_uint16)0,0x80000000,__big); }
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint(vector_long2    __x) { return vector_uint(vector_int(__x)); }
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint(vector_long3    __x) { return vector_uint(vector_int(__x)); }
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint(vector_long4    __x) { return vector_uint(vector_int(__x)); }
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint(vector_long8    __x) { return vector_uint(vector_int(__x)); }
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint(vector_ulong2   __x) { return vector_uint(vector_int(__x)); }
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint(vector_ulong3   __x) { return vector_uint(vector_int(__x)); }
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint(vector_ulong4   __x) { return vector_uint(vector_int(__x)); }
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint(vector_ulong8   __x) { return vector_uint(vector_int(__x)); }
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint(vector_double2  __x) { vector_long2 __big = __x > 0x1.fffffffcp30; return vector_uint(vector_int(__x - vector_bitselect((vector_double2)0,0x1.0p31,__big))) + vector_bitselect((vector_uint2)0,0x80000000,vector_int(__big)); }
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint(vector_double3  __x) { vector_long3 __big = __x > 0x1.fffffffcp30; return vector_uint(vector_int(__x - vector_bitselect((vector_double3)0,0x1.0p31,__big))) + vector_bitselect((vector_uint3)0,0x80000000,vector_int(__big)); }
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint(vector_double4  __x) { vector_long4 __big = __x > 0x1.fffffffcp30; return vector_uint(vector_int(__x - vector_bitselect((vector_double4)0,0x1.0p31,__big))) + vector_bitselect((vector_uint4)0,0x80000000,vector_int(__big)); }
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint(vector_double8  __x) { vector_long8 __big = __x > 0x1.fffffffcp30; return vector_uint(vector_int(__x - vector_bitselect((vector_double8)0,0x1.0p31,__big))) + vector_bitselect((vector_uint8)0,0x80000000,vector_int(__big)); }
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_char2    __x) { return vector_uint(vector_max(__x,0)); }
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_char3    __x) { return vector_uint(vector_max(__x,0)); }
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_char4    __x) { return vector_uint(vector_max(__x,0)); }
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_char8    __x) { return vector_uint(vector_max(__x,0)); }
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint_sat(vector_char16   __x) { return vector_uint(vector_max(__x,0)); }
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_short2   __x) { return vector_uint(vector_max(__x,0)); }
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_short3   __x) { return vector_uint(vector_max(__x,0)); }
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_short4   __x) { return vector_uint(vector_max(__x,0)); }
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_short8   __x) { return vector_uint(vector_max(__x,0)); }
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint_sat(vector_short16  __x) { return vector_uint(vector_max(__x,0)); }
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_int2     __x) { return vector_uint(vector_max(__x,0)); }
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_int3     __x) { return vector_uint(vector_max(__x,0)); }
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_int4     __x) { return vector_uint(vector_max(__x,0)); }
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_int8     __x) { return vector_uint(vector_max(__x,0)); }
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint_sat(vector_int16    __x) { return vector_uint(vector_max(__x,0)); }
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_float2   __x) { return vector_bitselect(vector_uint(vector_max(__x,0)), 0xffffffff, __x >= 0x1.0p32f); }
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_float3   __x) { return vector_bitselect(vector_uint(vector_max(__x,0)), 0xffffffff, __x >= 0x1.0p32f); }
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_float4   __x) { return vector_bitselect(vector_uint(vector_max(__x,0)), 0xffffffff, __x >= 0x1.0p32f); }
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_float8   __x) { return vector_bitselect(vector_uint(vector_max(__x,0)), 0xffffffff, __x >= 0x1.0p32f); }
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint_sat(vector_float16  __x) { return vector_bitselect(vector_uint(vector_max(__x,0)), 0xffffffff, __x >= 0x1.0p32f); }
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_long2    __x) { return vector_uint(vector_clamp(__x,0,0xffffffff)); }
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_long3    __x) { return vector_uint(vector_clamp(__x,0,0xffffffff)); }
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_long4    __x) { return vector_uint(vector_clamp(__x,0,0xffffffff)); }
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_long8    __x) { return vector_uint(vector_clamp(__x,0,0xffffffff)); }
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_double2  __x) { return vector_uint(vector_clamp(__x,0,0xffffffff)); }
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_double3  __x) { return vector_uint(vector_clamp(__x,0,0xffffffff)); }
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_double4  __x) { return vector_uint(vector_clamp(__x,0,0xffffffff)); }
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_double8  __x) { return vector_uint(vector_clamp(__x,0,0xffffffff)); }
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_uchar2   __x) { return vector_uint(__x); }
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_uchar3   __x) { return vector_uint(__x); }
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_uchar4   __x) { return vector_uint(__x); }
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_uchar8   __x) { return vector_uint(__x); }
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint_sat(vector_uchar16  __x) { return vector_uint(__x); }
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_ushort2  __x) { return vector_uint(__x); }
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_ushort3  __x) { return vector_uint(__x); }
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_ushort4  __x) { return vector_uint(__x); }
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_ushort8  __x) { return vector_uint(__x); }
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint_sat(vector_ushort16 __x) { return vector_uint(__x); }
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_uint2    __x) { return __x; }
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_uint3    __x) { return __x; }
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_uint4    __x) { return __x; }
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_uint8    __x) { return __x; }
static vector_uint16 __SIMD_ATTRIBUTES__ vector_uint_sat(vector_uint16   __x) { return __x; }
static vector_uint2  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_ulong2   __x) { return vector_uint(vector_clamp(__x,0,0xffffffff)); }
static vector_uint3  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_ulong3   __x) { return vector_uint(vector_clamp(__x,0,0xffffffff)); }
static vector_uint4  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_ulong4   __x) { return vector_uint(vector_clamp(__x,0,0xffffffff)); }
static vector_uint8  __SIMD_ATTRIBUTES__ vector_uint_sat(vector_ulong8   __x) { return vector_uint(vector_clamp(__x,0,0xffffffff)); }

static vector_float2  __SIMD_ATTRIBUTES__ vector_float(vector_char2    __x) { return (vector_float2)(vector_int(__x) + (vector_int2)0x1.8p23f) - 0x1.8p23f; }
static vector_float3  __SIMD_ATTRIBUTES__ vector_float(vector_char3    __x) { return (vector_float3)(vector_int(__x) + (vector_int3)0x1.8p23f) - 0x1.8p23f; }
static vector_float4  __SIMD_ATTRIBUTES__ vector_float(vector_char4    __x) { return (vector_float4)(vector_int(__x) + (vector_int4)0x1.8p23f) - 0x1.8p23f; }
static vector_float8  __SIMD_ATTRIBUTES__ vector_float(vector_char8    __x) { return (vector_float8)(vector_int(__x) + (vector_int8)0x1.8p23f) - 0x1.8p23f; }
static vector_float16 __SIMD_ATTRIBUTES__ vector_float(vector_char16   __x) { return (vector_float16)(vector_int(__x) + (vector_int16)0x1.8p23f) - 0x1.8p23f; }
static vector_float2  __SIMD_ATTRIBUTES__ vector_float(vector_uchar2   __x) { return (vector_float2)(vector_int(__x) + (vector_int2)0x1.8p23f) - 0x1.8p23f; }
static vector_float3  __SIMD_ATTRIBUTES__ vector_float(vector_uchar3   __x) { return (vector_float3)(vector_int(__x) + (vector_int3)0x1.8p23f) - 0x1.8p23f; }
static vector_float4  __SIMD_ATTRIBUTES__ vector_float(vector_uchar4   __x) { return (vector_float4)(vector_int(__x) + (vector_int4)0x1.8p23f) - 0x1.8p23f; }
static vector_float8  __SIMD_ATTRIBUTES__ vector_float(vector_uchar8   __x) { return (vector_float8)(vector_int(__x) + (vector_int8)0x1.8p23f) - 0x1.8p23f; }
static vector_float16 __SIMD_ATTRIBUTES__ vector_float(vector_uchar16  __x) { return (vector_float16)(vector_int(__x) + (vector_int16)0x1.8p23f) - 0x1.8p23f; }
static vector_float2  __SIMD_ATTRIBUTES__ vector_float(vector_short2   __x) { return (vector_float2)(vector_int(__x) + (vector_int2)0x1.8p23f) - 0x1.8p23f; }
static vector_float3  __SIMD_ATTRIBUTES__ vector_float(vector_short3   __x) { return (vector_float3)(vector_int(__x) + (vector_int3)0x1.8p23f) - 0x1.8p23f; }
static vector_float4  __SIMD_ATTRIBUTES__ vector_float(vector_short4   __x) { return (vector_float4)(vector_int(__x) + (vector_int4)0x1.8p23f) - 0x1.8p23f; }
static vector_float8  __SIMD_ATTRIBUTES__ vector_float(vector_short8   __x) { return (vector_float8)(vector_int(__x) + (vector_int8)0x1.8p23f) - 0x1.8p23f; }
static vector_float16 __SIMD_ATTRIBUTES__ vector_float(vector_short16  __x) { return (vector_float16)(vector_int(__x) + (vector_int16)0x1.8p23f) - 0x1.8p23f; }
static vector_float2  __SIMD_ATTRIBUTES__ vector_float(vector_ushort2  __x) { return (vector_float2)(vector_int(__x) + (vector_int2)0x1.8p23f) - 0x1.8p23f; }
static vector_float3  __SIMD_ATTRIBUTES__ vector_float(vector_ushort3  __x) { return (vector_float3)(vector_int(__x) + (vector_int3)0x1.8p23f) - 0x1.8p23f; }
static vector_float4  __SIMD_ATTRIBUTES__ vector_float(vector_ushort4  __x) { return (vector_float4)(vector_int(__x) + (vector_int4)0x1.8p23f) - 0x1.8p23f; }
static vector_float8  __SIMD_ATTRIBUTES__ vector_float(vector_ushort8  __x) { return (vector_float8)(vector_int(__x) + (vector_int8)0x1.8p23f) - 0x1.8p23f; }
static vector_float16 __SIMD_ATTRIBUTES__ vector_float(vector_ushort16 __x) { return (vector_float16)(vector_int(__x) + (vector_int16)0x1.8p23f) - 0x1.8p23f; }
static vector_float2  __SIMD_ATTRIBUTES__ vector_float(vector_int2     __x) { return __builtin_convertvector(__x,vector_float2); }
static vector_float3  __SIMD_ATTRIBUTES__ vector_float(vector_int3     __x) { return __builtin_convertvector(__x,vector_float3); }
static vector_float4  __SIMD_ATTRIBUTES__ vector_float(vector_int4     __x) { return __builtin_convertvector(__x,vector_float4); }
static vector_float8  __SIMD_ATTRIBUTES__ vector_float(vector_int8     __x) { return __builtin_convertvector(__x,vector_float8); }
static vector_float16 __SIMD_ATTRIBUTES__ vector_float(vector_int16    __x) { return __builtin_convertvector(__x,vector_float16); }
static vector_float2  __SIMD_ATTRIBUTES__ vector_float(vector_uint2    __x) { return __builtin_convertvector(__x,vector_float2); }
static vector_float3  __SIMD_ATTRIBUTES__ vector_float(vector_uint3    __x) { return __builtin_convertvector(__x,vector_float3); }
static vector_float4  __SIMD_ATTRIBUTES__ vector_float(vector_uint4    __x) { return __builtin_convertvector(__x,vector_float4); }
static vector_float8  __SIMD_ATTRIBUTES__ vector_float(vector_uint8    __x) { return __builtin_convertvector(__x,vector_float8); }
static vector_float16 __SIMD_ATTRIBUTES__ vector_float(vector_uint16   __x) { return __builtin_convertvector(__x,vector_float16); }
static vector_float2  __SIMD_ATTRIBUTES__ vector_float(vector_float2   __x) { return __x; }
static vector_float3  __SIMD_ATTRIBUTES__ vector_float(vector_float3   __x) { return __x; }
static vector_float4  __SIMD_ATTRIBUTES__ vector_float(vector_float4   __x) { return __x; }
static vector_float8  __SIMD_ATTRIBUTES__ vector_float(vector_float8   __x) { return __x; }
static vector_float16 __SIMD_ATTRIBUTES__ vector_float(vector_float16  __x) { return __x; }
static vector_float2  __SIMD_ATTRIBUTES__ vector_float(vector_long2    __x) { return __builtin_convertvector(__x,vector_float2); }
static vector_float3  __SIMD_ATTRIBUTES__ vector_float(vector_long3    __x) { return __builtin_convertvector(__x,vector_float3); }
static vector_float4  __SIMD_ATTRIBUTES__ vector_float(vector_long4    __x) { return __builtin_convertvector(__x,vector_float4); }
static vector_float8  __SIMD_ATTRIBUTES__ vector_float(vector_long8    __x) { return __builtin_convertvector(__x,vector_float8); }
static vector_float2  __SIMD_ATTRIBUTES__ vector_float(vector_ulong2   __x) { return __builtin_convertvector(__x,vector_float2); }
static vector_float3  __SIMD_ATTRIBUTES__ vector_float(vector_ulong3   __x) { return __builtin_convertvector(__x,vector_float3); }
static vector_float4  __SIMD_ATTRIBUTES__ vector_float(vector_ulong4   __x) { return __builtin_convertvector(__x,vector_float4); }
static vector_float8  __SIMD_ATTRIBUTES__ vector_float(vector_ulong8   __x) { return __builtin_convertvector(__x,vector_float8); }
static vector_float2  __SIMD_ATTRIBUTES__ vector_float(vector_double2  __x) { return __builtin_convertvector(__x,vector_float2); }
static vector_float3  __SIMD_ATTRIBUTES__ vector_float(vector_double3  __x) { return __builtin_convertvector(__x,vector_float3); }
static vector_float4  __SIMD_ATTRIBUTES__ vector_float(vector_double4  __x) { return __builtin_convertvector(__x,vector_float4); }
static vector_float8  __SIMD_ATTRIBUTES__ vector_float(vector_double8  __x) { return __builtin_convertvector(__x,vector_float8); }

static vector_long2  __SIMD_ATTRIBUTES__ vector_long(vector_char2    __x) { vector_char16 __r; __r.odd.odd.odd = __x; return (vector_long2)__r >> 56; }
static vector_long3  __SIMD_ATTRIBUTES__ vector_long(vector_char3    __x) { vector_long4 __r = vector_long(__x.xyzz); return __r.xyz; }
static vector_long4  __SIMD_ATTRIBUTES__ vector_long(vector_char4    __x) { vector_char32 __r; __r.odd.odd.odd = __x; return (vector_long4)__r >> 56; }
static vector_long8  __SIMD_ATTRIBUTES__ vector_long(vector_char8    __x) { vector_long8 __r; __r.lo = vector_long(__x.lo); __r.hi = vector_long(__x.hi); return __r; }
static vector_long2  __SIMD_ATTRIBUTES__ vector_long(vector_uchar2   __x) { vector_uchar16 __r = 0; __r.even.even.even = __x; return (vector_long2)__r; }
static vector_long3  __SIMD_ATTRIBUTES__ vector_long(vector_uchar3   __x) { vector_long4 __r = vector_long(__x.xyzz); return __r.xyz; }
static vector_long4  __SIMD_ATTRIBUTES__ vector_long(vector_uchar4   __x) { vector_uchar32 __r = 0; __r.even.even.even = __x; return (vector_long4)__r; }
static vector_long8  __SIMD_ATTRIBUTES__ vector_long(vector_uchar8   __x) { vector_long8 __r; __r.lo = vector_long(__x.lo); __r.hi = vector_long(__x.hi); return __r; }
static vector_long2  __SIMD_ATTRIBUTES__ vector_long(vector_short2   __x) { vector_short8 __r; __r.odd.odd = __x; return (vector_long2)__r >> 48; }
static vector_long3  __SIMD_ATTRIBUTES__ vector_long(vector_short3   __x) { vector_long4 __r = vector_long(__x.xyzz); return __r.xyz; }
static vector_long4  __SIMD_ATTRIBUTES__ vector_long(vector_short4   __x) { vector_short16 __r; __r.odd.odd = __x; return (vector_long4)__r >> 48; }
static vector_long8  __SIMD_ATTRIBUTES__ vector_long(vector_short8   __x) { vector_short32 __r; __r.odd.odd = __x; return (vector_long8)__r >> 48; }
static vector_long2  __SIMD_ATTRIBUTES__ vector_long(vector_ushort2  __x) { vector_ushort8 __r = 0; __r.even.even = __x; return (vector_long2)__r; }
static vector_long3  __SIMD_ATTRIBUTES__ vector_long(vector_ushort3  __x) { vector_long4 __r = vector_long(__x.xyzz); return __r.xyz; }
static vector_long4  __SIMD_ATTRIBUTES__ vector_long(vector_ushort4  __x) { vector_ushort16 __r = 0; __r.even.even = __x; return (vector_long4)__r; }
static vector_long8  __SIMD_ATTRIBUTES__ vector_long(vector_ushort8  __x) { vector_ushort32 __r = 0; __r.even.even = __x; return (vector_long8)__r; }
static vector_long2  __SIMD_ATTRIBUTES__ vector_long(vector_int2     __x) { vector_int4 __r; __r.odd = __x; return (vector_long2)__r >> 32; }
static vector_long3  __SIMD_ATTRIBUTES__ vector_long(vector_int3     __x) { vector_long4 __r = vector_long(__x.xyzz); return __r.xyz; }
static vector_long4  __SIMD_ATTRIBUTES__ vector_long(vector_int4     __x) { vector_int8 __r; __r.odd = __x; return (vector_long4)__r >> 32; }
static vector_long8  __SIMD_ATTRIBUTES__ vector_long(vector_int8     __x) { vector_int16 __r; __r.odd = __x; return (vector_long8)__r >> 32; }
static vector_long2  __SIMD_ATTRIBUTES__ vector_long(vector_uint2    __x) { vector_uint4 __r = 0; __r.even = __x; return (vector_long2)__r; }
static vector_long3  __SIMD_ATTRIBUTES__ vector_long(vector_uint3    __x) { vector_long4 __r = vector_long(__x.xyzz); return __r.xyz; }
static vector_long4  __SIMD_ATTRIBUTES__ vector_long(vector_uint4    __x) { vector_uint8 __r = 0; __r.even = __x; return (vector_long4)__r; }
static vector_long8  __SIMD_ATTRIBUTES__ vector_long(vector_uint8    __x) { vector_uint16 __r = 0; __r.even = __x; return (vector_long8)__r; }
static vector_long2  __SIMD_ATTRIBUTES__ vector_long(vector_float2   __x) { return __builtin_convertvector(__x,vector_long2); }
static vector_long3  __SIMD_ATTRIBUTES__ vector_long(vector_float3   __x) { return __builtin_convertvector(__x,vector_long3); }
static vector_long4  __SIMD_ATTRIBUTES__ vector_long(vector_float4   __x) { return __builtin_convertvector(__x,vector_long4); }
static vector_long8  __SIMD_ATTRIBUTES__ vector_long(vector_float8   __x) { return __builtin_convertvector(__x,vector_long8); }
static vector_long2  __SIMD_ATTRIBUTES__ vector_long(vector_long2    __x) { return __x; }
static vector_long3  __SIMD_ATTRIBUTES__ vector_long(vector_long3    __x) { return __x; }
static vector_long4  __SIMD_ATTRIBUTES__ vector_long(vector_long4    __x) { return __x; }
static vector_long8  __SIMD_ATTRIBUTES__ vector_long(vector_long8    __x) { return __x; }
static vector_long2  __SIMD_ATTRIBUTES__ vector_long(vector_ulong2   __x) { return (vector_long2)__x; }
static vector_long3  __SIMD_ATTRIBUTES__ vector_long(vector_ulong3   __x) { return (vector_long3)__x; }
static vector_long4  __SIMD_ATTRIBUTES__ vector_long(vector_ulong4   __x) { return (vector_long4)__x; }
static vector_long8  __SIMD_ATTRIBUTES__ vector_long(vector_ulong8   __x) { return (vector_long8)__x; }
static vector_long2  __SIMD_ATTRIBUTES__ vector_long(vector_double2  __x) { return __builtin_convertvector(__x,vector_long2); }
static vector_long3  __SIMD_ATTRIBUTES__ vector_long(vector_double3  __x) { return __builtin_convertvector(__x,vector_long3); }
static vector_long4  __SIMD_ATTRIBUTES__ vector_long(vector_double4  __x) { return __builtin_convertvector(__x,vector_long4); }
static vector_long8  __SIMD_ATTRIBUTES__ vector_long(vector_double8  __x) { return __builtin_convertvector(__x,vector_long8); }
static vector_long2  __SIMD_ATTRIBUTES__ vector_long_sat(vector_char2    __x) { return vector_long(__x); }
static vector_long3  __SIMD_ATTRIBUTES__ vector_long_sat(vector_char3    __x) { return vector_long(__x); }
static vector_long4  __SIMD_ATTRIBUTES__ vector_long_sat(vector_char4    __x) { return vector_long(__x); }
static vector_long8  __SIMD_ATTRIBUTES__ vector_long_sat(vector_char8    __x) { return vector_long(__x); }
static vector_long2  __SIMD_ATTRIBUTES__ vector_long_sat(vector_short2   __x) { return vector_long(__x); }
static vector_long3  __SIMD_ATTRIBUTES__ vector_long_sat(vector_short3   __x) { return vector_long(__x); }
static vector_long4  __SIMD_ATTRIBUTES__ vector_long_sat(vector_short4   __x) { return vector_long(__x); }
static vector_long8  __SIMD_ATTRIBUTES__ vector_long_sat(vector_short8   __x) { return vector_long(__x); }
static vector_long2  __SIMD_ATTRIBUTES__ vector_long_sat(vector_int2     __x) { return vector_long(__x); }
static vector_long3  __SIMD_ATTRIBUTES__ vector_long_sat(vector_int3     __x) { return vector_long(__x); }
static vector_long4  __SIMD_ATTRIBUTES__ vector_long_sat(vector_int4     __x) { return vector_long(__x); }
static vector_long8  __SIMD_ATTRIBUTES__ vector_long_sat(vector_int8     __x) { return vector_long(__x); }
static vector_long2  __SIMD_ATTRIBUTES__ vector_long_sat(vector_float2   __x) { return vector_bitselect(vector_long(vector_max(__x,-0x1.0p63f)), 0x7fffffffffffffff, vector_long(__x >= 0x1.0p63f)); }
static vector_long3  __SIMD_ATTRIBUTES__ vector_long_sat(vector_float3   __x) { return vector_bitselect(vector_long(vector_max(__x,-0x1.0p63f)), 0x7fffffffffffffff, vector_long(__x >= 0x1.0p63f)); }
static vector_long4  __SIMD_ATTRIBUTES__ vector_long_sat(vector_float4   __x) { return vector_bitselect(vector_long(vector_max(__x,-0x1.0p63f)), 0x7fffffffffffffff, vector_long(__x >= 0x1.0p63f)); }
static vector_long8  __SIMD_ATTRIBUTES__ vector_long_sat(vector_float8   __x) { return vector_bitselect(vector_long(vector_max(__x,-0x1.0p63f)), 0x7fffffffffffffff, vector_long(__x >= 0x1.0p63f)); }
static vector_long2  __SIMD_ATTRIBUTES__ vector_long_sat(vector_long2    __x) { return __x; }
static vector_long3  __SIMD_ATTRIBUTES__ vector_long_sat(vector_long3    __x) { return __x; }
static vector_long4  __SIMD_ATTRIBUTES__ vector_long_sat(vector_long4    __x) { return __x; }
static vector_long8  __SIMD_ATTRIBUTES__ vector_long_sat(vector_long8    __x) { return __x; }
static vector_long2  __SIMD_ATTRIBUTES__ vector_long_sat(vector_double2  __x) { return vector_bitselect(vector_long(vector_max(__x,-0x1.0p63)), 0x7fffffffffffffff, __x >= 0x1.0p63); }
static vector_long3  __SIMD_ATTRIBUTES__ vector_long_sat(vector_double3  __x) { return vector_bitselect(vector_long(vector_max(__x,-0x1.0p63)), 0x7fffffffffffffff, __x >= 0x1.0p63); }
static vector_long4  __SIMD_ATTRIBUTES__ vector_long_sat(vector_double4  __x) { return vector_bitselect(vector_long(vector_max(__x,-0x1.0p63)), 0x7fffffffffffffff, __x >= 0x1.0p63); }
static vector_long8  __SIMD_ATTRIBUTES__ vector_long_sat(vector_double8  __x) { return vector_bitselect(vector_long(vector_max(__x,-0x1.0p63)), 0x7fffffffffffffff, __x >= 0x1.0p63); }
static vector_long2  __SIMD_ATTRIBUTES__ vector_long_sat(vector_uchar2   __x) { return vector_long(__x); }
static vector_long3  __SIMD_ATTRIBUTES__ vector_long_sat(vector_uchar3   __x) { return vector_long(__x); }
static vector_long4  __SIMD_ATTRIBUTES__ vector_long_sat(vector_uchar4   __x) { return vector_long(__x); }
static vector_long8  __SIMD_ATTRIBUTES__ vector_long_sat(vector_uchar8   __x) { return vector_long(__x); }
static vector_long2  __SIMD_ATTRIBUTES__ vector_long_sat(vector_ushort2  __x) { return vector_long(__x); }
static vector_long3  __SIMD_ATTRIBUTES__ vector_long_sat(vector_ushort3  __x) { return vector_long(__x); }
static vector_long4  __SIMD_ATTRIBUTES__ vector_long_sat(vector_ushort4  __x) { return vector_long(__x); }
static vector_long8  __SIMD_ATTRIBUTES__ vector_long_sat(vector_ushort8  __x) { return vector_long(__x); }
static vector_long2  __SIMD_ATTRIBUTES__ vector_long_sat(vector_uint2    __x) { return vector_long(__x); }
static vector_long3  __SIMD_ATTRIBUTES__ vector_long_sat(vector_uint3    __x) { return vector_long(__x); }
static vector_long4  __SIMD_ATTRIBUTES__ vector_long_sat(vector_uint4    __x) { return vector_long(__x); }
static vector_long8  __SIMD_ATTRIBUTES__ vector_long_sat(vector_uint8    __x) { return vector_long(__x); }
static vector_long2  __SIMD_ATTRIBUTES__ vector_long_sat(vector_ulong2   __x) { return vector_long(vector_min(__x,0x7fffffffffffffff)); }
static vector_long3  __SIMD_ATTRIBUTES__ vector_long_sat(vector_ulong3   __x) { return vector_long(vector_min(__x,0x7fffffffffffffff)); }
static vector_long4  __SIMD_ATTRIBUTES__ vector_long_sat(vector_ulong4   __x) { return vector_long(vector_min(__x,0x7fffffffffffffff)); }
static vector_long8  __SIMD_ATTRIBUTES__ vector_long_sat(vector_ulong8   __x) { return vector_long(vector_min(__x,0x7fffffffffffffff)); }

static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong(vector_char2    __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong(vector_char3    __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong(vector_char4    __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong(vector_char8    __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong(vector_uchar2   __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong(vector_uchar3   __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong(vector_uchar4   __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong(vector_uchar8   __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong(vector_short2   __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong(vector_short3   __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong(vector_short4   __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong(vector_short8   __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong(vector_ushort2  __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong(vector_ushort3  __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong(vector_ushort4  __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong(vector_ushort8  __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong(vector_int2     __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong(vector_int3     __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong(vector_int4     __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong(vector_int8     __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong(vector_uint2    __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong(vector_uint3    __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong(vector_uint4    __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong(vector_uint8    __x) { return vector_ulong(vector_long(__x)); }
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong(vector_float2   __x) { vector_int2 __big = __x >= 0x1.0p63f; return vector_ulong(vector_long(__x - vector_bitselect((vector_float2)0,0x1.0p63f,__big))) + vector_bitselect((vector_ulong2)0,0x8000000000000000,vector_long(__big)); }
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong(vector_float3   __x) { vector_int3 __big = __x >= 0x1.0p63f; return vector_ulong(vector_long(__x - vector_bitselect((vector_float3)0,0x1.0p63f,__big))) + vector_bitselect((vector_ulong3)0,0x8000000000000000,vector_long(__big)); }
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong(vector_float4   __x) { vector_int4 __big = __x >= 0x1.0p63f; return vector_ulong(vector_long(__x - vector_bitselect((vector_float4)0,0x1.0p63f,__big))) + vector_bitselect((vector_ulong4)0,0x8000000000000000,vector_long(__big)); }
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong(vector_float8   __x) { vector_int8 __big = __x >= 0x1.0p63f; return vector_ulong(vector_long(__x - vector_bitselect((vector_float8)0,0x1.0p63f,__big))) + vector_bitselect((vector_ulong8)0,0x8000000000000000,vector_long(__big)); }
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong(vector_long2    __x) { return (vector_ulong2)__x; }
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong(vector_long3    __x) { return (vector_ulong3)__x; }
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong(vector_long4    __x) { return (vector_ulong4)__x; }
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong(vector_long8    __x) { return (vector_ulong8)__x; }
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong(vector_ulong2   __x) { return __x; }
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong(vector_ulong3   __x) { return __x; }
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong(vector_ulong4   __x) { return __x; }
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong(vector_ulong8   __x) { return __x; }
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong(vector_double2  __x) { vector_long2 __big = __x >= 0x1.0p63; return vector_ulong(vector_long(__x - vector_bitselect((vector_double2)0,0x1.0p63,__big))) + vector_bitselect((vector_ulong2)0,0x8000000000000000,__big); }
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong(vector_double3  __x) { vector_long3 __big = __x >= 0x1.0p63; return vector_ulong(vector_long(__x - vector_bitselect((vector_double3)0,0x1.0p63,__big))) + vector_bitselect((vector_ulong3)0,0x8000000000000000,__big); }
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong(vector_double4  __x) { vector_long4 __big = __x >= 0x1.0p63; return vector_ulong(vector_long(__x - vector_bitselect((vector_double4)0,0x1.0p63,__big))) + vector_bitselect((vector_ulong4)0,0x8000000000000000,__big); }
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong(vector_double8  __x) { vector_long8 __big = __x >= 0x1.0p63; return vector_ulong(vector_long(__x - vector_bitselect((vector_double8)0,0x1.0p63,__big))) + vector_bitselect((vector_ulong8)0,0x8000000000000000,__big); }
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_char2    __x) { return vector_ulong(vector_max(__x,0)); }
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_char3    __x) { return vector_ulong(vector_max(__x,0)); }
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_char4    __x) { return vector_ulong(vector_max(__x,0)); }
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_char8    __x) { return vector_ulong(vector_max(__x,0)); }
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_short2   __x) { return vector_ulong(vector_max(__x,0)); }
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_short3   __x) { return vector_ulong(vector_max(__x,0)); }
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_short4   __x) { return vector_ulong(vector_max(__x,0)); }
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_short8   __x) { return vector_ulong(vector_max(__x,0)); }
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_int2     __x) { return vector_ulong(vector_max(__x,0)); }
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_int3     __x) { return vector_ulong(vector_max(__x,0)); }
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_int4     __x) { return vector_ulong(vector_max(__x,0)); }
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_int8     __x) { return vector_ulong(vector_max(__x,0)); }
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_float2   __x) { return vector_bitselect(vector_ulong(vector_max(__x,0.f)), 0xffffffffffffffff, vector_long(__x >= 0x1.0p64f)); }
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_float3   __x) { return vector_bitselect(vector_ulong(vector_max(__x,0.f)), 0xffffffffffffffff, vector_long(__x >= 0x1.0p64f)); }
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_float4   __x) { return vector_bitselect(vector_ulong(vector_max(__x,0.f)), 0xffffffffffffffff, vector_long(__x >= 0x1.0p64f)); }
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_float8   __x) { return vector_bitselect(vector_ulong(vector_max(__x,0.f)), 0xffffffffffffffff, vector_long(__x >= 0x1.0p64f)); }
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_long2    __x) { return vector_ulong(vector_max(__x,0)); }
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_long3    __x) { return vector_ulong(vector_max(__x,0)); }
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_long4    __x) { return vector_ulong(vector_max(__x,0)); }
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_long8    __x) { return vector_ulong(vector_max(__x,0)); }
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_double2  __x) { return vector_bitselect(vector_ulong(vector_max(__x,0.0)), 0xffffffffffffffff, __x >= 0x1.0p64); }
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_double3  __x) { return vector_bitselect(vector_ulong(vector_max(__x,0.0)), 0xffffffffffffffff, __x >= 0x1.0p64); }
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_double4  __x) { return vector_bitselect(vector_ulong(vector_max(__x,0.0)), 0xffffffffffffffff, __x >= 0x1.0p64); }
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_double8  __x) { return vector_bitselect(vector_ulong(vector_max(__x,0.0)), 0xffffffffffffffff, __x >= 0x1.0p64); }
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_uchar2   __x) { return vector_ulong(__x); }
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_uchar3   __x) { return vector_ulong(__x); }
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_uchar4   __x) { return vector_ulong(__x); }
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_uchar8   __x) { return vector_ulong(__x); }
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_ushort2  __x) { return vector_ulong(__x); }
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_ushort3  __x) { return vector_ulong(__x); }
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_ushort4  __x) { return vector_ulong(__x); }
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_ushort8  __x) { return vector_ulong(__x); }
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_uint2    __x) { return vector_ulong(__x); }
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_uint3    __x) { return vector_ulong(__x); }
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_uint4    __x) { return vector_ulong(__x); }
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_uint8    __x) { return vector_ulong(__x); }
static vector_ulong2  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_ulong2   __x) { return __x; }
static vector_ulong3  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_ulong3   __x) { return __x; }
static vector_ulong4  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_ulong4   __x) { return __x; }
static vector_ulong8  __SIMD_ATTRIBUTES__ vector_ulong_sat(vector_ulong8   __x) { return __x; }

static vector_double2  __SIMD_ATTRIBUTES__ vector_double(vector_char2    __x) { return vector_double(vector_int(__x)); }
static vector_double3  __SIMD_ATTRIBUTES__ vector_double(vector_char3    __x) { return vector_double(vector_int(__x)); }
static vector_double4  __SIMD_ATTRIBUTES__ vector_double(vector_char4    __x) { return vector_double(vector_int(__x)); }
static vector_double8  __SIMD_ATTRIBUTES__ vector_double(vector_char8    __x) { return vector_double(vector_int(__x)); }
static vector_double2  __SIMD_ATTRIBUTES__ vector_double(vector_uchar2   __x) { return vector_double(vector_int(__x)); }
static vector_double3  __SIMD_ATTRIBUTES__ vector_double(vector_uchar3   __x) { return vector_double(vector_int(__x)); }
static vector_double4  __SIMD_ATTRIBUTES__ vector_double(vector_uchar4   __x) { return vector_double(vector_int(__x)); }
static vector_double8  __SIMD_ATTRIBUTES__ vector_double(vector_uchar8   __x) { return vector_double(vector_int(__x)); }
static vector_double2  __SIMD_ATTRIBUTES__ vector_double(vector_short2   __x) { return vector_double(vector_int(__x)); }
static vector_double3  __SIMD_ATTRIBUTES__ vector_double(vector_short3   __x) { return vector_double(vector_int(__x)); }
static vector_double4  __SIMD_ATTRIBUTES__ vector_double(vector_short4   __x) { return vector_double(vector_int(__x)); }
static vector_double8  __SIMD_ATTRIBUTES__ vector_double(vector_short8   __x) { return vector_double(vector_int(__x)); }
static vector_double2  __SIMD_ATTRIBUTES__ vector_double(vector_ushort2  __x) { return vector_double(vector_int(__x)); }
static vector_double3  __SIMD_ATTRIBUTES__ vector_double(vector_ushort3  __x) { return vector_double(vector_int(__x)); }
static vector_double4  __SIMD_ATTRIBUTES__ vector_double(vector_ushort4  __x) { return vector_double(vector_int(__x)); }
static vector_double8  __SIMD_ATTRIBUTES__ vector_double(vector_ushort8  __x) { return vector_double(vector_int(__x)); }
static vector_double2  __SIMD_ATTRIBUTES__ vector_double(vector_int2     __x) { return __builtin_convertvector(__x, vector_double2); }
static vector_double3  __SIMD_ATTRIBUTES__ vector_double(vector_int3     __x) { return __builtin_convertvector(__x, vector_double3); }
static vector_double4  __SIMD_ATTRIBUTES__ vector_double(vector_int4     __x) { return __builtin_convertvector(__x, vector_double4); }
static vector_double8  __SIMD_ATTRIBUTES__ vector_double(vector_int8     __x) { return __builtin_convertvector(__x, vector_double8); }
static vector_double2  __SIMD_ATTRIBUTES__ vector_double(vector_uint2    __x) { return __builtin_convertvector(__x, vector_double2); }
static vector_double3  __SIMD_ATTRIBUTES__ vector_double(vector_uint3    __x) { return __builtin_convertvector(__x, vector_double3); }
static vector_double4  __SIMD_ATTRIBUTES__ vector_double(vector_uint4    __x) { return __builtin_convertvector(__x, vector_double4); }
static vector_double8  __SIMD_ATTRIBUTES__ vector_double(vector_uint8    __x) { return __builtin_convertvector(__x, vector_double8); }
static vector_double2  __SIMD_ATTRIBUTES__ vector_double(vector_float2   __x) { return __builtin_convertvector(__x, vector_double2); }
static vector_double3  __SIMD_ATTRIBUTES__ vector_double(vector_float3   __x) { return __builtin_convertvector(__x, vector_double3); }
static vector_double4  __SIMD_ATTRIBUTES__ vector_double(vector_float4   __x) { return __builtin_convertvector(__x, vector_double4); }
static vector_double8  __SIMD_ATTRIBUTES__ vector_double(vector_float8   __x) { return __builtin_convertvector(__x, vector_double8); }
static vector_double2  __SIMD_ATTRIBUTES__ vector_double(vector_long2    __x) { return __builtin_convertvector(__x, vector_double2); }
static vector_double3  __SIMD_ATTRIBUTES__ vector_double(vector_long3    __x) { return __builtin_convertvector(__x, vector_double3); }
static vector_double4  __SIMD_ATTRIBUTES__ vector_double(vector_long4    __x) { return __builtin_convertvector(__x, vector_double4); }
static vector_double8  __SIMD_ATTRIBUTES__ vector_double(vector_long8    __x) { return __builtin_convertvector(__x, vector_double8); }
static vector_double2  __SIMD_ATTRIBUTES__ vector_double(vector_ulong2   __x) { return __builtin_convertvector(__x, vector_double2); }
static vector_double3  __SIMD_ATTRIBUTES__ vector_double(vector_ulong3   __x) { return __builtin_convertvector(__x, vector_double3); }
static vector_double4  __SIMD_ATTRIBUTES__ vector_double(vector_ulong4   __x) { return __builtin_convertvector(__x, vector_double4); }
static vector_double8  __SIMD_ATTRIBUTES__ vector_double(vector_ulong8   __x) { return __builtin_convertvector(__x, vector_double8); }
static vector_double2  __SIMD_ATTRIBUTES__ vector_double(vector_double2  __x) { return __builtin_convertvector(__x, vector_double2); }
static vector_double3  __SIMD_ATTRIBUTES__ vector_double(vector_double3  __x) { return __builtin_convertvector(__x, vector_double3); }
static vector_double4  __SIMD_ATTRIBUTES__ vector_double(vector_double4  __x) { return __builtin_convertvector(__x, vector_double4); }
static vector_double8  __SIMD_ATTRIBUTES__ vector_double(vector_double8  __x) { return __builtin_convertvector(__x, vector_double8); }

#ifdef __cplusplus
}
#endif
#endif // __SIMD_REQUIRED_COMPILER_FEATURES__
#endif // __SIMD_CONVERSION_HEADER__
