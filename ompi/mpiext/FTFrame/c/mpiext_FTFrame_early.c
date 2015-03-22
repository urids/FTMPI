
#include "ompi_config.h"

#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>


#include "ompi/mpi/c/bindings.h"
#include "ompi/mpiext/mpiext.h"
#include "ompi/mpiext/FTFrame/c/mpiext_FTFrame_c.h"


/* 
 * If an extension would like to have init/fini, in
 * addition to providing the hooks below, adding the line in
 * configure.m4  is also required.
 */


//these elements have extern linkage and lives in the runtime system memory
CLxplorInfo clXplr; //Global Variable Declared in deviceExploration.h
cpudev*   cpu; // Global Variable declared in localDevices.h
gpudev*   gpu; // Global Variable declared in localDevices.h
acceldev* accel; // Global Variable declared in localDevices.h



static int FTFrame_init(void)
{
    //printf("FTFrame mpiext __init\n");

	void *dvMgmt_dlhandle;

	void (*deviceXploration)(CLxplorInfo *);
	void (*initializeDevices)(CLxplorInfo*);


	char *error;

	dvMgmt_dlhandle = dlopen ("/home/uriel/Dev/mpisrc/FTMPI/ompi/mpiext/FTFrame/c/dvMgmt/libdvMgmt.so", RTLD_LAZY);

	if (!dvMgmt_dlhandle ) {
		fputs(dlerror(), stderr);
		exit(1);
	}

	deviceXploration = dlsym(dvMgmt_dlhandle, "deviceXploration");
	initializeDevices = dlsym(dvMgmt_dlhandle, "initializeDevices");

	if ((error = dlerror()) != NULL ) {
		fputs(error, stderr);
		exit(1);
	}



    (*deviceXploration)(&clXplr);
    (*initializeDevices)(&clXplr);




    dlclose(dvMgmt_dlhandle);

    
    return OMPI_SUCCESS;
}

static int FTFrame_fini(void)
{
    //printf("FTFrame mpiext _fini\n");
    return OMPI_SUCCESS;
}

/*
 * Similar to Open MPI components, a well-known struct provides
 * function pointers to the extension's init/fini hooks.  The struct
 * must be a global symbol of the form ompi_mpiext_<ext_name> and be
 * of type ompi_mpiext_component_t.
 */


ompi_mpiext_component_t ompi_mpiext_FTFrame = {
    FTFrame_init,
    FTFrame_fini
};
