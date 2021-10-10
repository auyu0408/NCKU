/* circuitSatifiability.c solves the Circuit Satisfiability
 *  Problem using a brute-force sequential solution.
 *
 *   The particular circuit being tested is "wired" into the
 *   logic of function 'checkCircuit'. All combinations of
 *   inputs that satisfy the circuit are printed.
 *
 *   16-bit version by Michael J. Quinn, Sept 2002.
 *   Extended to 32 bits by Joel C. Adams, Sept 2013.
 */

#include <stdio.h>     // printf()
#include <limits.h>    // UINT_MAX
#include <mpi.h>

int checkCircuit (int, int);

int main (int argc, char *argv[]) {
   int i;               /* loop variable (32 bits) */
   int count = 0;        /* number of solutions */
   double starttime = 0.0, totaltime = 0.0;//calculate execcution time

   int total_process;
   int process_rank;
   int remain, offset;
   int received;

   MPI_Init(NULL, NULL);//MPI start
   MPI_Comm_size(MPI_COMM_WORLD, &total_process);
   MPI_Comm_rank(MPI_COMM_WORLD, &process_rank);

   starttime = MPI_Wtime();

   for (i = process_rank; i <= USHRT_MAX; i+=total_process) {
      count += checkCircuit (process_rank, i);
   }

   remain = total_process;//尚未處理的process數目
   while(remain > 1){
      offset = remain/2 + remain % 2;//代表判定標準，每次可以處理掉一半的process，但還有無法被配對到的process要算進去
      //如有7個process時，0-4, 1-5, 2-6, 3;第二輪會被分成0-2,1-3
      //process_rank<處理的數目：代表他是負責收count的
      if(process_rank<remain/2){
         MPI_Recv(&received, 1, MPI_INT, process_rank+offset, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
         count += received;
      }
      //若process>處理的數目，代表他是負責傳count的，但為了不讓傳過得東西再傳一次，需要加上process_rank<remain
      //在第一輪，3就不會被分配到，但是他之後還是會傳到
      else if(process_rank >= offset && process_rank < remain){
         MPI_Send(&count, 1, MPI_INT, process_rank-offset, 0, MPI_COMM_WORLD);
      }
   remain = offset;
   }
   
   if(process_rank != 0){
	   printf ("Process %d finished.\n", process_rank);
   	fflush (stdout);
   }
   else{
	totaltime = MPI_Wtime() - starttime;
      printf ("Process %d finished in %f secs.\n", process_rank, totaltime);
      fflush(stdout);
      printf("\nA total of %d solutions were found.\n\n", count);
   }
   MPI_Finalize();
   return 0;
}

/* EXTRACT_BIT is a macro that extracts the ith bit of number n.
 *
 * parameters: n, a number;
 *             i, the position of the bit we want to know.
 *
 * return: 1 if 'i'th bit of 'n' is 1; 0 otherwise 
 */

#define EXTRACT_BIT(n,i) ( (n & (1<<i) ) ? 1 : 0)


/* checkCircuit() checks the circuit for a given input.
 * parameters: id, the id of the process checking;
 *             bits, the (long) rep. of the input being checked.
 *
 * output: the binary rep. of bits if the circuit outputs 1
 * return: 1 if the circuit outputs 1; 0 otherwise.
 */

#define SIZE 16

int checkCircuit (int id, int bits) {
   int v[SIZE];        /* Each element is a bit of bits */
   int i;

   for (i = 0; i < SIZE; i++)
      v[i] = EXTRACT_BIT(bits,i);

   if (  (v[0] || v[1]) && (!v[1] || !v[3]) && (v[2] || v[3])
         && (!v[3] || !v[4]) && (v[4] || !v[5])
         && (v[5] || !v[6]) && (v[5] || v[6])
         && (v[6] || !v[15]) && (v[7] || !v[8])
         && (!v[7] || !v[13]) && (v[8] || v[9])
         && (v[8] || !v[9]) && (!v[9] || !v[10])
         && (v[9] || v[11]) && (v[10] || v[11])
         && (v[12] || v[13]) && (v[13] || !v[14])
         && (v[14] || v[15])  )
   {
      printf ("%d) %d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d \n", id,
         v[15],v[14],v[13],v[12],
         v[11],v[10],v[9],v[8],v[7],v[6],v[5],v[4],v[3],v[2],v[1],v[0]);
      fflush (stdout);
      return 1;
   } else {
      return 0;
   }
}
