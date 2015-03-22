/*
 * tskMgmt.h
 *
 *  Created on: Feb 9, 2015
 *      Author: uriel
 */

#ifndef TKMGMT_H_
#define TKMGMT_H_

#define DEBUG 0

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <CL/cl.h>

#include "/home/uriel/Dev/mpisrc/FTMPI/ompi/include/mpi.h"
#include "/home/uriel/Dev/mpiApps/FTWrkDistr/multiDeviceMgmt/src/taskMgmt/task.h"

#include "deviceMgmt/Device.h"
#include "deviceMgmt/localDevices.h"
#include "deviceMgmt/deviceExploration.h"
#include "deviceMgmt/devicesInitialization.h"

extern int numTasks;  //This will be defined in late.c and is property of the runtime system.

#endif /* TKMGMT_H_ */
