
#include "ompi_config.h"

#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

#include "ompi/mpi/c/bindings.h"
#include "ompi/mpiext/mpiext.h"
#include "ompi/mpiext/FTFrame/c/mpiext_FTFrame_c.h"

/* 
 * The init/fini functions and the component struct are not required,
 * but optional.  If an extension would like to have init/fini, in
 * addition to providing the hooks below, adding the line in
 * configure.m4 (documented in example's configure.m4) is also
 * required.
 */
static int FTFrame_init(void)
{
    printf("FTFrame mpiext __init\n");

	void *handle;
	void (*xtfn)();
	char *error;


	handle = dlopen ("/home/uriel/Dev/mpisrc/FTMPI/ompi/mpiext/FTFrame/c/dvXplore/libdvXplore.so", RTLD_LAZY);
        if (!handle) {
            fputs (dlerror(), stderr);
            exit(1);
        }


	xtfn = dlsym(handle, "htft");
        if ((error = dlerror()) != NULL)  {
            fputs(error, stderr);
            exit(1);
        }

	(*xtfn)();
        dlclose(handle);


    
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
