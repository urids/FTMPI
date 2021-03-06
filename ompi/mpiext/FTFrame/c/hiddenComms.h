/*
 * hiddenComms.h
 *
 *  Created on: Feb 6, 2015
 *      Author: uriel
 */

#ifndef HIDDENCOMMS_H_
#define HIDDENCOMMS_H_

#define DEBUG 0

#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <CL/cl.h>

#include "/home/uriel/Dev/mpisrc/FTMPI/ompi/include/mpi.h"
#include "/home/uriel/Dev/mpiApps/FTWrkDistr/multiDeviceMgmt/src/deviceMgmt/Device.h"
#include "deviceMgmt/deviceExploration.h"
#include "deviceMgmt/devicesInitialization.h"

#include "mpiext_FTFrame_c.h"

void sendXploreInfo(MPI_Comm mcomm);
void rcvXploreInfo(MPI_Comm mcomm);

#endif /* HIDDENCOMMS_H_ */
