// C standard includes
#include <stdio.h>

// OpenCL includes
#include <CL/cl.h>

int main()
{
    cl_int CL_err = CL_SUCCESS;
    cl_uint numPlatforms;
    cl_platform_id* platforms;

    clGetPlatformIDs( 0, NULL, &numPlatforms );
    platforms = (cl_platform_id*)malloc(sizeof(cl_platform_id)* numPlatforms);
    CL_err = clGetPlatformIDs(numPlatforms, platforms, NULL);

    if (CL_err == CL_SUCCESS)
        printf("%u platform(s) found\n", numPlatforms);
    else
        printf("clGetPlatformIDs(%i)\n", CL_err);

    return 0;
}