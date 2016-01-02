#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Debug.h>

#include "mlclut.h"
#include "mlclut_descriptions.h"

#define DEBUG_MAIN	"main"

int main(void)
{
	cl_uint n_platforms, n_devices;

	cl_platform_id *platforms = clut_getAllPlatforms(&n_platforms);
	if (NULL == platforms) {
		Debug_out(DEBUG_MAIN, "No platforms available.\n");
		return EXIT_FAILURE;
	}

	printf("Total number of platforms: '%d'.\n", n_platforms);

	cl_device_id *devices = NULL;

	cl_uint i, j;
	for (i = 0; i < n_platforms; ++i) {
		printf("Printing info for platform '%d':\n", i);
		clut_printPlatformInfos(platforms[i]);
		devices = clut_getAllDevices(platforms[i], CL_DEVICE_TYPE_ALL, &n_devices);
		if (NULL == devices) {
			Debug_out(DEBUG_MAIN, "Platform %d has no devices.\n", i);
			continue;
		}

		printf("Platform %d has %d devices.\n", i, n_devices);
		for (j = 0; j < n_devices; ++j) {
			printf("Printing info for device '%d':\n", j);
			clut_printDeviceInfos(devices[j]);
		}
	}

	if (NULL == devices) {
		return EXIT_FAILURE;
	}

	clut_printDeviceSupportedImageFormats(devices[0]);
	clut_printDeviceSupportedImageFormats(devices[1 ]);

//	clut_printContextInfo(context);
//
//	cl_program program = clut_createProgramFromFile(context, "/Users/michele/Developer/openCL/matmul/matmul.cl");
//	clut_printProgramBuildLog(program);
//
//	clReleaseProgram(program);
//	clReleaseContext(context);

	return 0;
}




