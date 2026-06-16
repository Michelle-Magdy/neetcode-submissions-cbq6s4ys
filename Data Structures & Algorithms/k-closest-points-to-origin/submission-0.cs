public class Solution {
    public int[][] KClosest(int[][] points, int k) {
        PriorityQueue<int[],double> minHeap = new PriorityQueue<int[],double>();

        for(int i = 0; i< points.GetLength(0);i++){
            double distance = Math.Sqrt(Math.Pow(points[i][0],2) + Math.Pow(points[i][1],2));
            minHeap.Enqueue(points[i],distance);
        }
        int[][] res = new int[k][];
        for(int i = 0; i< k;i++){
            res[i] = minHeap.Dequeue();
        }
        return res;

    }
}
