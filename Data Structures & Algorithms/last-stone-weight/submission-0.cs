public class Solution {
    public int LastStoneWeight(int[] stones) {
        PriorityQueue<int,int> maxHeap = new PriorityQueue<int,int>(
            Comparer<int>.Create((x,y)=>y.CompareTo(x))
        );
        foreach(int stone in stones){
            maxHeap.Enqueue(stone,stone);
        }

        while(maxHeap.Count >1){
            int x = maxHeap.Dequeue();
            int y = maxHeap.Dequeue();

            if(x < y){
                y -=x;
                maxHeap.Enqueue(y,y);
            }else if(y<x){
                x -= y;
                maxHeap.Enqueue(x,x);
            }
        }
        if(maxHeap.Count == 1){
            return maxHeap.Peek();
        }
        return 0;
    }
}
