#include "opencl.hpp"
#include <cstdio>
#include <cstdlib>

int main() {
	Device device(select_device_with_most_flops()); // compile OpenCL C code for the fastest available device

	const uint N = 1024u; // size of vectors
	Memory<float> A(device, N); // allocate memory on both host and device
	Memory<float> B(device, N);
	Memory<float> C(device, N);

	Kernel add_kernel(device, N, "add_kernel", A, B, C); // kernel that runs on the device

	for(uint n=0u; n<N; n++) {
		A[n] = 3.0f; // initialize memory
		B[n] = 2.0f;
		C[n] = 1.0f;
	}

	print_info("Value before kernel execution: C[0] = "+to_string(C[0]));

	A.write_to_device(); // copy data from host memory to device memory
	B.write_to_device();
	add_kernel.run(); // run add_kernel on the device
	C.read_from_device(); // copy data from device memory to host memory

	/*
	for (uint n = 0u; n < N; n++) {
		printf("Value after kernel execution: C[%d] = %s\n", n, to_string(C[n]));
	}
	*/
	print_info("Value after kernel execution: C[0] = "+to_string(C[0]));

	wait();

	cl_uint platformCount;
	cl_platform_id* platforms;
	cl_uint deviceCount;
	cl_device_id* devices;
	size_t valueSize;
	char* value;
	cl_uint maxComputeUnits;

	// 1. 플랫폼 가져오기
	clGetPlatformIDs(0, NULL, &platformCount);
	printf("Total Platform Count: %d\n", platformCount);
	platforms = (cl_platform_id*)malloc(sizeof(cl_platform_id) * platformCount);
	clGetPlatformIDs(platformCount, platforms, NULL);

	for (int i = 0; i < platformCount; i++)
	{
		printf("Platform %d\n", i);

		// 2. 디바이스 가져오기
		clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, 0, NULL, &deviceCount);
		printf("\tTotal Device Count: %d\n", deviceCount);
		devices = (cl_device_id*)malloc(sizeof(cl_device_id) * deviceCount);
		clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, deviceCount, devices, NULL);

		// 3. 디바이스 정보 가져오기
		for (int j = 0; j < deviceCount; j++)
		{
			printf("\tDevice %d\n", j);

			// 3-1. 디바이스 이름 출력
			clGetDeviceInfo(devices[j], CL_DEVICE_NAME, 0, NULL, &valueSize);
			value = (char*)malloc(valueSize);
			clGetDeviceInfo(devices[j], CL_DEVICE_NAME, valueSize, value, NULL);
			printf("\t\tDevice Name: %s\n", value);
			free(value);

			// 3-2. 디바이스 버전 출력
			clGetDeviceInfo(devices[j], CL_DEVICE_VERSION, 0, NULL, &valueSize);
			value = (char*)malloc(valueSize);
			clGetDeviceInfo(devices[j], CL_DEVICE_VERSION, valueSize, value, NULL);
			printf("\t\tDevice Version: %s\n", value);
			free(value);

			// 3-3. 드라이버 버전 출력
			clGetDeviceInfo(devices[j], CL_DRIVER_VERSION, 0, NULL, &valueSize);
			value = (char*)malloc(valueSize);
			clGetDeviceInfo(devices[j], CL_DRIVER_VERSION, valueSize, value, NULL);
			printf("\t\tDriver Version: %s\n", value);
			free(value);

			// 3-4. OpenCL C 버전 출력
			clGetDeviceInfo(devices[j], CL_DEVICE_OPENCL_C_VERSION, 0, NULL, &valueSize);
			value = (char*)malloc(valueSize);
			clGetDeviceInfo(devices[j], CL_DEVICE_OPENCL_C_VERSION, valueSize, value, NULL);
			printf("\t\tOpenCL C Version: %s\n", value);
			free(value);

			// 3-5. 연산 유닛 수 출력
			clGetDeviceInfo(devices[j], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(maxComputeUnits), &maxComputeUnits, NULL);
			printf("\t\tMax Compute Units: %d\n", maxComputeUnits);
		}
	}

	return 0;
}