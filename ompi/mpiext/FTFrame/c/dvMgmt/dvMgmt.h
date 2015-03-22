
#ifndef __dvMgmt_H__
#define __dvMgmt_H__

#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

#include "/home/uriel/Dev/mpiApps/FTWrkDistr/multiDeviceMgmt/src/deviceMgmt/Device.h"
#include "deviceMgmt/deviceExploration.h"
#include "deviceMgmt/devicesInitialization.h"

void deviceXploration(CLxplorInfo * clXplr);
void initializeDevices(CLxplorInfo*  xplorInfo);

#endif //__dvMgmt_H__
