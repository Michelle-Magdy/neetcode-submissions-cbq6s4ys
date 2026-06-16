public class Solution {
    public int FindKthLargest(int[] nums, int k) {
        PriorityQueue<int,int> maxHeap = new PriorityQueue<int,int>(
            Comparer<int>.Create((x,y) => y.CompareTo(x))
        );
        foreach(int num in nums){
            maxHeap.Enqueue(num,num);
        }

        for(int i=1;i<k;i++){
            maxHeap.Dequeue();
        }
        return maxHeap.Dequeue();
    }
}
