
#include "ompi_config.h"

#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

#include "ompi/mpi/c/bindings.h"
#include "ompi/mpiext/mpiext.h"
#include "ompi/mpiext/FTFrame/c/mpiext_FTFrame_c.h"

//static const char FUNC_NAME[] = "OMPI_Progress";

/*
 * Global variable from this extension
 */
int OMPI_FTFrame_global = 42;

/*
 * Just to make the extension "interesting", we pass in an integer and
 * an MPI handle.
 */



int OMPI_initXplore(int count, MPI_Comm comm)
{
    char name[MPI_MAX_OBJECT_NAME];
    int len;

    /* Just as an example, get the name of the communicator and print
       it out.  Use the PMPI name when possible so that these
       invocations don't show up in profiling tools. */

#if OMPI_ENABLE_MPI_PROFILING
    PMPI_Comm_get_name(comm, name, &len);
#else
    MPI_Comm_get_name(comm, name, &len);
#endif

    int numprocess, myRank, len2;
    char hostname[MPI_MAX_PROCESSOR_NAME];

    MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
    MPI_Get_processor_name(hostname, &len2);

    printf("Hello from task %d on %s!\n", myRank, hostname);  
    printf("Count = %d, LB_name is: = %s\n", count, name);


    	void *dlhandle;
    	void (*recvfcn)(MPI_Comm mcomm);
    	void (*sendfcn)(MPI_Comm mcomm);
    	char *error;


    		dlhandle = dlopen ("/home/uriel/Dev/mpisrc/FTMPI/ompi/mpiext/FTFrame/c/comms/libhiddenComms.so", RTLD_LAZY);
            if (!dlhandle) {
                fputs (dlerror(), stderr);
                exit(1);
            }


            if(myRank==0){
            recvfcn = dlsym(dlhandle, "rcvXploreInfo");

            	if ((error = dlerror()) != NULL)  {
            		fputs(error, stderr);
            		exit(1);
            	}


            	(*recvfcn)(comm);

            }
            else {
            	sendfcn = dlsym(dlhandle, "sendXploreInfo");

            	if ((error = dlerror()) != NULL ) {
            		fputs(error, stderr);
            		exit(1);
            	}

            	(*sendfcn)(comm);

            }


            dlclose(dlhandle);



    return MPI_SUCCESS;
}

