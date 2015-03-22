
#include "CL/cl.h"
#include "/home/uriel/Dev/mpiApps/FTWrkDistr/multiDeviceMgmt/src/deviceMgmt/Device.h"
#include "/home/uriel/Dev/mpiApps/FTWrkDistr/multiDeviceMgmt/src/taskMgmt/task.h"
#include "deviceMgmt/deviceExploration.h"
#include "deviceMgmt/devicesInitialization.h"
#include "/home/uriel/Dev/mpiApps/FTWrkDistr/multiDeviceMgmt/src/deviceMgmt/localDevices.h"


#define DEBUG 0



OMPI_DECLSPEC extern int OMPI_FTFrame_global;

//OMPI_DECLSPEC int OMPI_commit_EntityType(int blockcount, int* blocklen, MPI_Aint* displacements, MPI_Datatype* basictypes, MPI_Datatype * newDatatype);

//this function collect in root node the information of all devices in each node of the communicator.
OMPI_DECLSPEC int OMPI_collectDevicesInfo(int devSelection, MPI_Comm comm); //first parameter for this represents "ALL" or "GPUs"
OMPI_DECLSPEC int OMPI_XclCreateKernel(MPI_Comm comm,char* srcPath,char* kernelName);
OMPI_DECLSPEC int OMPI_XclScatter(MPI_Comm communicator, const char* datafileName, MPI_Datatype MPIentityType, void **entitiesbuffer,int size, int* ePerRank);
OMPI_DECLSPEC int OMPI_XclExecKernel(MPI_Comm communicator,int globalThreads, int localThreads,const char * fmt, ...) __attribute__((format (printf, 4, 5)));
OMPI_DECLSPEC int OMPI_XclGather(MPI_Comm comm, int entitiesBufferSize,void **entitiesbuffer);
