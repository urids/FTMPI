
#include "ompi_config.h"

#include <stdio.h>

#include "ompi/mpi/c/bindings.h"
#include "ompi/mpiext/mpiext.h"
#include "ompi/mpiext/FTFrame/c/mpiext_FTFrame_c.h"

static const char FUNC_NAME[] = "OMPI_Progress";

/*
 * Global variable from this extension
 */
int OMPI_FTFrame_global = 42;

/*
 * Just to make the extension "interesting", we pass in an integer and
 * an MPI handle.
 */



int OMPI_Progress(int count, MPI_Comm comm) 
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

    printf("Count = %d, commName is: = %s\n", count, name);

    return MPI_SUCCESS;
}

