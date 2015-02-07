/*
 * hiddenComms.h
 *
 *  Created on: Feb 6, 2015
 *      Author: uriel
 */

#ifndef HIDDENCOMMS_H_
#define HIDDENCOMMS_H_

#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>



void sendXploreInfo(MPI_Comm mcomm);
void rcvXploreInfo(MPI_Comm mcomm);

#endif /* HIDDENCOMMS_H_ */
