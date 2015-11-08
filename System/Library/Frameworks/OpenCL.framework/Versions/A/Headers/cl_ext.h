/*******************************************************************************
 * Copyright:  (c) 2007-2009 by Apple, Inc., All Rights Reserved.
 ******************************************************************************/

#ifndef __CL_EXT_H
#define __CL_EXT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>
#include <OpenCL/cl.h>
#include <AvailabilityMacros.h>

/* enum can be used if cl_khr_fp64 extension is supported by the OpenCL implementation. */
#define CL_DEVICE_DOUBLE_FP_CONFIG                  0x1032

/* enum can be used if cl_khr_fp16 extension is supported by the OpenCL implementation. */
#define CL_DEVICE_HALF_FP_CONFIG                    0x1033
  
/*
 * Apple extensions:
 *  Apple has been allocated a block of identifiers starting at 0x10000000, and error codes in the range 
 *  -1060 ... -1091.
 */
    
/* Memory object destruction
 *
 * Apple extension for use to manage externally allocated buffers used with cl_mem objects with CL_MEM_USE_HOST_PTR
 *
 * Registers a user callback function that will be called when the memory object is deleted and its resources 
 * freed. Each call to clSetMemObjectCallbackFn registers the specified user callback function on a callback 
 * stack associated with memobj. The registered user callback functions are called in the reverse order in 
 * which they were registered. The user callback functions are called and then the memory object is deleted 
 * and its resources freed. This provides a mechanism for the application (and libraries) using memobj to be 
 * notified when the memory referenced by host_ptr, specified when the memory object is created and used as 
 * the storage bits for the memory object, can be reused or freed.
 *
 * The application may not call CL api's with the cl_mem object passed to the pfn_notify.
 *
 * Please check for the "cl_APPLE_SetMemObjectDestructor" extension using clGetDeviceInfo(CL_DEVICE_EXTENSIONS)
 * before using.
 *
 * NOTE:  This feature is a core feature in OpenCL 1.1. Please use clSetMemObjectDestructorCallback instead.
 */

/* *** DEPRECATED! **** Please use the equivalent standard function clSetMemObjectDestructor instead. It was added in OpenCL 1.1. */
cl_int	clSetMemObjectDestructorAPPLE(  cl_mem                  /* memobj */, 
                                        void (CL_CALLBACK *    /*pfn_notify*/)( cl_mem /* memobj */, void* /*user_data*/), 
                                        void *                 /*user_data */ ) CL_EXT_SUFFIX__VERSION_1_0_DEPRECATED;

/* Context Logging Functions
 *
 * The next three convenience functions are intended to be used as the pfn_notify parameter to clCreateContext().
 * Please check for the "cl_APPLE_ContextLoggingFunctions" extension using clGetDeviceInfo(CL_DEVICE_EXTENSIONS)
 * before using.  Note that if you pass NULL to the clCreateContext pfn_notify parameter, you can also use these
 * by setting the CL_LOG_ERRORS environment variable to one of stdout, stderr, or console.  Pass your own do-nothing
 * context logging function to disable the CL_LOG_ERRORS override.
 *
 * clLogMessagesToSystemLog fowards on all log messages to the Apple System Logger 
 */
extern void clLogMessagesToSystemLogAPPLE(  const char * /* errstr */, 
                                            const void * /* private_info */, 
                                            size_t       /* cb */, 
                                            void *       /* user_data */ )  CL_EXT_SUFFIX__VERSION_1_0;

/* clLogMessagesToStdout sends all log messages to the file descriptor stdout   */
extern void clLogMessagesToStdoutAPPLE(   const char * /* errstr */, 
                                          const void * /* private_info */, 
                                          size_t       /* cb */, 
                                          void *       /* user_data */ )    CL_EXT_SUFFIX__VERSION_1_0;

/* clLogMessagesToStderr sends all log messages to the file descriptor stderr   */
extern void clLogMessagesToStderrAPPLE(   const char * /* errstr */, 
                                          const void * /* private_info */, 
                                          size_t       /* cb */, 
                                          void *       /* user_data */ )    CL_EXT_SUFFIX__VERSION_1_0;
    
/* Extension: cl_APPLE_clut 
 * New APIs that allow apps to reduce the number of CL API calls they need to make
 * to setup CL before a kernel can be enqueued for execution.   
 */
extern CL_API_ENTRY cl_int CL_API_CALL clCreateContextAndCommandQueueAPPLE(
                                                  const cl_context_properties * /* properties */,
                                                  cl_uint                       /* num_devices */,
                                                  const cl_device_id *          /* devices */,
                                                  void ( CL_CALLBACK *          /*pfn_notify*/)(const char * /* errinfo */, const void * /* private_info */, size_t /* cb */, void * /* user_data */),
                                                  void *                        /* user_data */,
                                                  cl_command_queue_properties   /* queue_properties */,
                                                  cl_context *                  /* context */,
                                                  cl_command_queue *            /* queues */)   CL_EXT_SUFFIX__VERSION_1_1;

extern CL_API_ENTRY cl_int CL_API_CALL clCreateProgramAndKernelsWithSourceAPPLE(
                                                       cl_context           /* context */,
                                                       cl_uint              /* count */,
                                                       const char **        /* program_source_strings */,
                                                       const size_t *       /* program_source_lengths */,
                                                       cl_uint              /* num_devices */,
                                                       const cl_device_id * /* device_list */,
                                                       const char *         /* options */,
                                                       cl_uint              /* num_kernels */,
                                                       const char **        /* kernel_name_strings */,
                                                       cl_program *         /* program */,
                                                       cl_kernel *          /* kernels */)   CL_EXT_SUFFIX__VERSION_1_1;

extern CL_API_ENTRY cl_int CL_API_CALL clSetKernelArgsListAPPLE(cl_kernel /* kernel */, 
                                                                cl_uint   /* num_args */, 
                                                                ... )   CL_EXT_SUFFIX__VERSION_1_1;

extern CL_API_ENTRY cl_int CL_API_CALL clSetKernelArgsVaListAPPLE(cl_kernel /* kernel */, 
                                                                  cl_uint   /* num_args */, 
                                                                  va_list   /* argp */)   CL_EXT_SUFFIX__VERSION_1_1;

#define CL_INVALID_ARG_NAME_APPLE   -1060
extern CL_API_ENTRY cl_int CL_API_CALL clSetKernelArgByNameAPPLE(cl_kernel    /* kernel */,                                         
                                                                 const char * /* arg_name */,
                                                                 size_t       /* arg_size */,
                                                                 const void * /* arg_value */) CL_API_SUFFIX__VERSION_1_1;

/* Extension: cl_APPLE_query_kernel_names
 * 
 * These selectors may be passed to clGetProgramInfo to obtain information about the kernel functions in a cl_program.
 * The cl_program must be successfully built with clBuildProgram for at least one device to succeed. Otherwise CL_INVALID_PROGRAM_EXECUTABLE is returned.
 */
#define CL_PROGRAM_NUM_KERNELS_APPLE                      0x10000004    /* Introduced in MacOS X.7.  Returns a cl_uint for number of kernels in program. */
#define CL_PROGRAM_KERNEL_NAMES_APPLE                     0x10000005    /* Introduced in MacOS X.7.  Returns a ';' delimited char[] containing the names of kernels in program */


/* Extension: cl_APPLE_fixed_alpha_channel_orders
 *
 * These selectors may be passed to clCreateImage2D() in the cl_image_format.image_channel_order field.
 * They are like CL_BGRA and CL_ARGB except that the alpha channel to be ignored.  On calls to read_imagef, 
 * the alpha will be 0xff (1.0f) if the sample falls in the image and 0 if it does not fall in the image. 
 * On calls to write_imagef, the alpha value is ignored and 0xff (1.0f) is written. These formats are 
 * currently only available for the CL_UNORM_INT8 cl_channel_type. They are intended to support legacy
 * image formats. 
 */
#define CL_1RGB_APPLE                                     0x10000006      /* Introduced in MacOS X.7. */
#define CL_BGR1_APPLE                                     0x10000007      /* Introduced in MacOS X.7. */

/* Extension: cl_APPLE_biased_fixed_point_image_formats
 *
 * This selector may be passed to clCreateImage2D() in the cl_image_format.image_channel_data_type field.
 * It defines a biased signed 1.14 fixed point storage format, with range [-1, 3). The conversion from
 * float to this fixed point format is defined as follows:
 * 
 *      ushort float_to_sfixed14( float x ){
 *          int i = convert_int_sat_rte( x * 0x1.0p14f );         // scale [-1, 3.0) to [-16384, 3*16384), round to nearest integer
 *          i = add_sat( i, 0x4000 );                             // apply bias, to convert to [0, 65535) range
 *          return convert_ushort_sat(i);                         // clamp to destination size
 *      }
 *
 * The inverse conversion is the reverse process. The formats are currently only available on the CPU with
 * the CL_RGBA channel layout.
 */
#define CL_SFIXED14_APPLE                                 0x10000008      /* Introduced in MacOS X.7. */

/* Extension: YUV image support 
 * 
 * These formats can only be used when creating images from YUV 4:2:2 IOSurface, using the
 * clCreateImageFromIOSurface2DAPPLE() API. These formats are only available for the CL_UNORM_INT8, 
 * CL_UNSIGNED_INT8, and CL_SIGNED_INT8 cl_channel_type.
 */
#define CL_YCbYCr_APPLE                                   0x10000010      /* Introduced in MacOS X.7. */
#define CL_CbYCrY_APPLE                                   0x10000011      /* Introduced in MacOS X.7. */
 
#ifdef __cplusplus
}
#endif


#endif /* __CL_EXT_H */
