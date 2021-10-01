//
//  main.c
//  MPI_Test
//
//  Created by Saif Chowdhury on 10/1/21.
//  Copyright © 2021 Saif Chowdhury. All rights reserved.
//

#define boilerPlate int pid;MPI_Comm_rank(MPI_COMM_WORLD, &pid); int np; MPI_Comm_size(MPI_COMM_WORLD, &np);

#define send(X) MPI_Send(message, 10, MPI_INT, X, 0, MPI_COMM_WORLD);
#define recieve(Y) MPI_Recv(Y, 1, MPI_INT, Y, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

#define message(X) int[] message = { X , X , X, X}
#define msg message[0]
#define msg(X) message[X]

#define rank(X) pid==X

#include <stdio.h>
#include <mpi.h>

int main(int argc, const char * argv[]) {
    
    boilerPlate
    message(0)
    
    if(rank(0)){
        send(1)
    }
    if(rank(1)){
        recieve(0)
    }
    
    
    return 0;
}
