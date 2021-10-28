#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i, j;//in loop
    int total_num, local_num, phase;
    int comm_sz, process_id;
    double start_time, total_time;
    int *sort_ans, *arr_temp, *sub_ans;//arr_temp: save the arr you receive
    int num_temp;//process 0 need to receive other arr, save in here.
    int partner;//partner when doing odd-even sort
    int self_i, partner_i, total_i;//used in odd-even merge sort
    int *new_temp;

    //MPI start
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &process_id);

    //start record time
    start_time = MPI_Wtime();
    srand(time(NULL));
    //srand(process_id * 100);

    //read number
    if(process_id == 0){
        printf("Enter number n:");
        scanf("%d", &total_num);
    }
    MPI_Bcast(&total_num, 1, MPI_INTEGER, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);

    //Calculate how many digits in each process
    local_num = total_num/comm_sz;
    if(process_id < total_num%comm_sz){
        local_num += 1;
    }

    //allocate number array
    arr_temp = (int *)malloc(sizeof(int) * local_num + 1);
    sort_ans = (int *)malloc(sizeof(int) * total_num);

    //generate random number and sort
    sub_ans = (int *)malloc(sizeof(int) * local_num);
    for(i=0; i<local_num; i++){
        sub_ans[i] = rand();
    }
    //bubble sort
    for(i=0; i<local_num; i++){
        for(j=0; j<local_num-i; j++){
            if(sub_ans[j]>sub_ans[j+1]){
                int temp;
                temp = sub_ans[j];
                sub_ans[j] = sub_ans[j+1];
                sub_ans[j+1] = temp;
            }
        }
    }

    MPI_Barrier(MPI_COMM_WORLD);
    //Collect into process 0
    //MPI_Gatherv parameter
    int num_of_send[comm_sz];
    int start_addr[comm_sz];
    int now_loc = 0;
    for(i=0; i<comm_sz; i++){
        num_of_send[i] = total_num/comm_sz;
        if(i < total_num%comm_sz)
            num_of_send[i]++;
        start_addr[i] = now_loc;
        now_loc += num_of_send[i];
    }

    //MPI_Gatherv
    MPI_Gatherv(sub_ans, local_num, MPI_INTEGER, sort_ans, num_of_send, start_addr, MPI_INTEGER, 0, MPI_COMM_WORLD);
    //print
    if(process_id == 0){
        int count = 0;//we can count were we done.
        printf("\n");
        for(i=0; i<comm_sz; i++){
            printf("Process %d's local sort: ", i);
            for(j=0; j<num_of_send[i]; j++){
                printf("%d, ", sort_ans[start_addr[i]+j]);
            }
            printf("\n");
            fflush(stdout);
            count += num_temp;
        }
    }
    MPI_Barrier(MPI_COMM_WORLD);
    
    //Odd-even
    new_temp = (int *)malloc(sizeof(int) * (local_num*2+2));
    phase = comm_sz;
    for(i=0; i<phase; i++){
        //find partner
        if(i%2 == 0){
            if(process_id%2 != 0)
                partner = process_id - 1;
            else
                partner = process_id + 1;
        }
        else{
            if(process_id%2 != 0)
                partner = process_id + 1;
            else
                partner = process_id - 1;
        }
        if(partner == -1 || partner == comm_sz)
            continue;
        //change infomation
        num_temp = total_num/comm_sz;
        if(partner < total_num%comm_sz)
            num_temp++;
        if(process_id%2!=0){
            MPI_Send(sub_ans, local_num, MPI_INTEGER, partner, 0, MPI_COMM_WORLD);
            MPI_Recv(arr_temp, num_temp, MPI_INTEGER, partner, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        else{
            MPI_Recv(arr_temp, num_temp, MPI_INTEGER, partner, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Send(sub_ans, local_num, MPI_INTEGER, partner, 0, MPI_COMM_WORLD);
        }
        //sort
        self_i=partner_i=total_i=0;
        while (total_i < local_num + num_temp)
        {
            if(partner_i>=num_temp){
                new_temp[total_i] = sub_ans[self_i];
                total_i++, self_i++;
            }
            else if(self_i>=local_num){
                new_temp[total_i] = arr_temp[partner_i];
                total_i++, partner_i++;
            }
            else if(sub_ans[self_i]<arr_temp[partner_i]){
                new_temp[total_i] = sub_ans[self_i];
                total_i++, self_i++;
            }
            else{
                new_temp[total_i] = arr_temp[partner_i];
                total_i++, partner_i++;
            }
        }
        //move new array
        for(j=0; j<local_num; j++){
            if(process_id > partner)
                sub_ans[j] = new_temp[num_temp + j];
            else
                sub_ans[j] = new_temp[j];
        }
    }
    
    MPI_Barrier(MPI_COMM_WORLD);
    //Gather after sorting all
    MPI_Gatherv(sub_ans, local_num, MPI_INTEGER, sort_ans, num_of_send, start_addr, MPI_INTEGER, 0, MPI_COMM_WORLD);

    //MPI time calculate
    total_time = MPI_Wtime() - start_time;
    if(process_id == 0){
        printf("Total execution time in %f secs.\n", total_time);
        fflush(stdout);
    //print final answer
        printf("Final answer: ");
        for(i=0; i<total_num; i++){
            printf("%d, ", sort_ans[i]);
        }
        printf("\n");
        fflush(stdout);
    }

    //free space
    free(sub_ans);
    free(sort_ans);
    free(arr_temp);
    free(new_temp);

    //End MPI
    MPI_Finalize();
    
    return 0;
}