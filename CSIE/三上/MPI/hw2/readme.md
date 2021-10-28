# MPI HW2

## What have you done
### Problem1
主要是自己做了分割、計算完再合併，其他部份是可以用原本程式碼的。
附上直接用Smooth.cpp 和平行化後的比較，發現兩者結果是一樣的。
![](https://i.imgur.com/NesaFcI.png)
### Problem2
一開始先下指令再輸入n，n代表的是總共要排序的數目，之後會顯示每個process先當地sort 後的結果，再出現全部merge sort後的結果。
![](https://i.imgur.com/sfwVm58.png)
## Analysis on your result
### Problem1
當process = 1時，大概需要45~50秒，會發現隨著process數增加，執行時間會減少，到大約process=8時事最小值，process = 10和12有可能是通訊時增加時間。
- process = 1
- ![](https://i.imgur.com/Rfh4BOk.png)
- process = 2
- ![](https://i.imgur.com/oqIawKH.png)
- process = 4
- ![](https://i.imgur.com/lViGIXG.png)
- process = 8
- ![](https://i.imgur.com/C0MeQsK.png)
- process = 10
- ![](https://i.imgur.com/OeIuvAY.png)
- process = 12
- ![](https://i.imgur.com/AzpDaXn.png)
### Problem2
執行到的時間和感受到的時間似乎不太一樣，像Problem1可以明確的感受到時間差別，但這個感覺旱地一次作業一樣，process之間並沒有差太多（雖然實際數字有差）
- process = 2
- ![](https://i.imgur.com/YNipuKT.png)
- process = 4
- ![](https://i.imgur.com/CSb75sB.png)
- process = 8
- ![](https://i.imgur.com/gYgmIhv.png)
## Any difficulties?
### Problem1
- 在切割時，雖然原理與第二題類似，但因為一次是切一排，要考慮的數變多了，並且需要先理解bmp file的一些structure
### Problem2
- 題目需要注意的地方是當輸入的n不能被整除時，要把剩下的平均分配。
- 另外，我在初期測試時發現「每次產生出來的亂數都很接近」（已經有加srand），對此，我思考是不是因為每個process執行到那個指令時的時間是差不多的，因為在產生亂數前有Broadcast，Broadcast完後有Barrier。
後來我把rand的seed更改為`time(NULL)+process_id*100`，這樣不僅可以讓每個process產生不同亂數，不同次的執行結果也會不一樣。
- 附圖示為了確定兩次產生亂數是不同的：
- ![](https://i.imgur.com/tU2Vgon.png)
- ![](https://i.imgur.com/ODHnXkl.png)
- 另外，有時候程式在memory allocate的時候好像會有問題，不過好像都是特定的數字。
