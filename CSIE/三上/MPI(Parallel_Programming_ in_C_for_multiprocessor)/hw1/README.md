# MPI HW1

## What have you done

### Problem 1
- 在題目給的基礎程式加上課堂上交的MPI步驟，並把計算count的地方改成：
```c 
for (i = process_rank; i <= USHRT_MAX; i+=total_process) {
      count += checkCircuit (process_rank, i);
   }
```
- 利用間隔為總process使每個process處理的數減少
- 使用的 tree-structure求global count的部份：
```c
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
```
- 印出時間則是在求出 global count之後

### Problem 2
- 方法和第一題以及課本上差不多，差別是把課本裡的四分之一圓換成下圖，以及以(-1,1), (-1,-1), (1,-1), (1,1)四點為頂點的正方形(參照題目)
- ![](https://images2018.cnblogs.com/blog/1203675/201805/1203675-20180516213843523-166516479.png)
- 求出該點是否在園內的算法：
``` c
// pi = 1*1*pi, 0 is center and its radius is 1, the square that it produce is 2*2=4
    for(toss = my_rank; toss < number_of_tosses; toss += comm_sz){
        x = (double)rand()/RAND_MAX*2 - 1;//get x, range in (-1,1)
        y = (double)rand()/RAND_MAX*2 - 1;// get y, range in (-1,1)
        distance_squard = x*x +y*y;//if (x,y) is in the circle, its distance with square is smaller than 1.
        if(distance_squard <= 1){
            number_in_circle ++;
        }
    }
```
- 一樣是由多個process分散處理，再使用tree-structured建構，列印時間也是在求出global count之後
- 另外，有設計在一開始時先印出 toss總數量，好方便我們做觀察
```
if(my_rank == 0){
        printf("number of tosses is: %lld\n", number_of_tosses);// for more easily, 
}
```

## Analysis on your result

### Problem 1
因為一開始沒有做出 tree-structure，正好讓我有範本可以比較 Serial Communication和 tree-structure的不同
- total_process = 1:
  - Serial
  - ![](https://i.imgur.com/bcdNn9c.png)
  - Tree
  - ![](https://i.imgur.com/zUuVQjH.png)
- total_process = 2:
  - Serial
  - ![](https://i.imgur.com/4J0CHfH.png)

  - Tree
  - ![](https://i.imgur.com/oGD9QYy.png)
- total_process = 4:
  - Serial
  - ![](https://i.imgur.com/9wpVxXa.png)
  - Tree
  - ![](https://i.imgur.com/ZYp7ihX.png)
- total_process = 8:
  - Serial
  - ![](https://i.imgur.com/GYvY9QG.png)
  - ![](https://i.imgur.com/Lu4f9Dy.png)
  - Tree
  - ![](https://i.imgur.com/rcmWoMM.png)
  
- 觀察起來是在process數量少(1或2)的時候，兩者都是差不多的，而process數量變大時，serial的executiion time變得不太穩定；但因為我不曉得我使用的時候是否有其他人跟同時使用server，也沒有很確定網路穩定度，所以只能當成額外的觀察。

### Problem 2
- 在一開始 process 0 會先印出toss總數，這樣就可以方便觀察不同toss數對答案的影響
  - toss = 10
  - ![](https://i.imgur.com/M5iFEZ2.png)
  - toss = 100
  - ![](https://i.imgur.com/DohIfAM.png)
  - toss = 1000
  - ![](https://i.imgur.com/370kMPc.png)
  - toss = 10000
  - ![](https://i.imgur.com/mCd8gEM.png)
  - toss = 100000
  - ![](https://i.imgur.com/5PXDmio.png)
  - toss = 1000000
  - ![](https://i.imgur.com/BA78ARb.png)
  - toss = 10000000
  - ![](https://i.imgur.com/vMV0jSr.png)
- 如果希望能求出 $\pi$ = 3.14, toss數至少要是 1000000，且隨著toss數增加，所需計算時間自然也會變大。

## Any difficulites?

### Problem 1
- 一開始沒有做出 Tree structure，只做出了 Serial communication，主要是在 process為奇數時會不知道該如何處理。
- 另外也有在想是否要繼續用迴圈來做 tree-structure sum，因為process的行為是recv(*$n, n\geq 0$) -> send -> wait(*$n, n\geq 0$) -> end； 這樣安排else if 條件內做的事情會不知道要怎麼辦，目前有兩種想法： 1. 一旦進入else if迴圈就break 或是 2. 就這樣擺著讓他什麼都不做，但好像都不夠好，所以才會思考這個問題。

### Problem 2
- 有點懷疑要在什麼時候計算 total time，是算完各自的 number_in_circle就可以算還是要等加完的時候，如果把重點放在不同toss數會影響的執行時間就應該選第一個，如果是要強調 tree-structure的話好像第二個會比較好，所以先選擇了第二個。

## Feedback to TAs

希望可以有中文的題目解說uu，很不好意思；然後操作解說很淺顯易懂。