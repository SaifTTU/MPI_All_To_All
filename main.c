//
//  main.c
//  MPI_Test
//
//  Created by Saif Chowdhury on 10/1/21.
//  Copyright © 2021 Saif Chowdhury. All rights reserved.
//

#define boilerPlate MPI_Status status; MPI_Init(&argc, &argv); int pid;MPI_Comm_rank(MPI_COMM_WORLD, &pid); int np; MPI_Comm_size(MPI_COMM_WORLD, &np); int message[] = {0};
#define send(X) MPI_Send(message, 2, MPI_INT, X, 0, MPI_COMM_WORLD); printf("Process %d sent message to %d", pid, X);
#define recieve(X) MPI_Recv(message, 2, MPI_INT, X, 0, MPI_COMM_WORLD, &status); printf("Process %d recieved message from %d", pid, X);

#define msg message[0]

#define pid(X) pid==X

#define print(X) printf(X);

#define finalize MPI_Finalize();

#define for(X) for(int i=0;i<X;i++)

#define round(X) round = X;
#define round(X, Y, Z) round = X; if(pid==Z){MPI_Send(&round, 2, MPI_INT, Y, 0, MPI_COMM_WORLD); } if(pid==Y){MPI_Recv(&round, 2, MPI_INT, Z, 0, MPI_COMM_WORLD, &status); }

#define round_(X) round==X

#define send_and_recieve(X,Y) if(pid==Y){MPI_Send(message, 2, MPI_INT, X, 0, MPI_COMM_WORLD); printf("Process %d sent message to %d\n", pid, X);} if(pid==X){MPI_Recv(message, 2, MPI_INT, Y, 0, MPI_COMM_WORLD, &status); printf("Process %d recieved message from %d\n", pid, Y);}



#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {

    boilerPlate

        int round = 0;

    if (round_(0)) {
        send_and_recieve(3, 7);
        round(1, 3, 7)
        send_and_recieve(2, 6);
        round(1, 2, 6)
        send_and_recieve(1, 5);
        round(1, 1, 5)
        send_and_recieve(0, 4);
        round(1, 0, 4)

    }

    if (round_(1)) {
        send_and_recieve(2, 4);
        round(2, 2, 4)
        send_and_recieve(1, 3);
        round(2, 1, 3)
            //round(2)
    }

    if (round_(2)) {
        send_and_recieve(0, 2);
        round(3, 0, 2)
        send_and_recieve(0, 1);
        round(3, 0, 1)
    }







    finalize

        return 0;
}
