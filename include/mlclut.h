/**
 * @header
 * @author Michele Laurenti
 * @language c
 */

#ifndef __ML_CLUT_H
#define __ML_CLUT_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "opencl.h"

/*!
 * The following macro checks if [r] (a cl_int) equals CL_SUCCESS.
 * If it does not, it prints the string [s], along with a description of [r],
 * and jumps to [e] (an appropriate error label).
 */
#define CLUT_CHECK_ERROR(r,s,e)	\
	do { \
		if (!clut_returnSuccess((r))) {\
			fprintf(stderr, "%s: %s.\n", (s), clut_getErrorDescription((r))); \
			goto e; \
		} \
	} while (0)

#define COMPUTE_GLOBAL_SIZE(size,local)		(((size)/(local) + (((size) % (local) != 0) ? 1 : 0)) * (local))


void clut_checkReturn(const char * const function, cl_int value);

int clut_returnSuccess(cl_int value);

cl_platform_id *clut_getAllPlatforms(cl_uint *n_p);
cl_device_id *clut_getAllDevices(cl_platform_id platform, cl_device_type t, cl_uint *n_d);

void * clut_getDeviceInfo(const cl_device_id device, const cl_device_info info, size_t * const size);
void * clut_getPlatformInfo(const cl_platform_id platform, const cl_platform_info info, size_t * const size);

cl_program clut_createProgramFromFile(cl_context context, const char * const file, const char * const flags);

void clut_printProgramBuildLog(const cl_program program);

void clut_contextCallback(const char *errinfo, const void *private_info, size_t private_info_size, void *user_data);

cl_double clut_getEventDuration(cl_event event);
cl_ulong clut_getEventDuration_ns(cl_event event);

#endif

