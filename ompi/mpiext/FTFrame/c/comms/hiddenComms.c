
#include "/home/uriel/Dev/mpisrc/FTMPI/ompi/include/mpi.h"
#include "hiddenComms.h"
void rcvXploreInfo(MPI_Comm mcomm){

	int testDt;
	//*testDt=25;
	MPI_Recv(&testDt,1,MPI_INT,1,0,mcomm,MPI_STATUS_IGNORE);

		printf("Received data is: %d \n ",testDt);
}


void sendXploreInfo(MPI_Comm mcomm){
	int testDt=7;
	MPI_Send(&testDt,1,MPI_INT,0,0,mcomm);

}



