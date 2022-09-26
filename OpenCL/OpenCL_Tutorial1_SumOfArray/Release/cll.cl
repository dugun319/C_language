
#pragma OPENCL EXTENSION cl_khr_local_int32_base_atomics : enable

__kernel
void simpleKernel(__global float* imageIn,
	__global float* imageOut
)
{

	uint dstYStride = get_global_size(0);
	uint dstIndex = get_global_id(1) * dstYStride + get_global_id(0);
	uint globalRow = get_global_id(1);
	uint globalCol = get_global_id(0);

	imageOut[dstIndex] = imageIn[dstIndex];

}