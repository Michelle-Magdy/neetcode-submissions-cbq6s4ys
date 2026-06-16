public class KthLargest {
    private PriorityQueue<int,int> minHeap;
    private int k;


    public KthLargest(int k, int[] nums) {
        this.k = k;
        this.minHeap = new PriorityQueue<int,int>();
        foreach(int num in nums){
            this.minHeap.Enqueue(num,num);
            if(this.minHeap.Count > k){
                this.minHeap.Dequeue();
            }
        }
    }
    
    public int Add(int val) {
        minHeap.Enqueue(val,val);
        if(this.minHeap.Count > k){
            this.minHeap.Dequeue();
        }
        return minHeap.Peek();

    }
}
