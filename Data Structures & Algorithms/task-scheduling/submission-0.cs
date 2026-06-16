public class Solution {
    public int LeastInterval(char[] tasks, int n) {
        PriorityQueue<int,int> maxHeap = new PriorityQueue<int,int>();
        int[] count = new int[26];
        foreach(char task in tasks){
            count[task -'A']++;
        }
        for(int i =0;i<26;i++){
            if(count[i] > 0){
                maxHeap.Enqueue(count[i],-count[i]);
            }
        }
        Queue<int[]> queue = new Queue<int[]>();

        int time = 0;
        while(maxHeap.Count > 0 || queue.Count > 0){
            if(queue.Count > 0 && time >= queue.Peek()[1]){
                int[] temp = queue.Dequeue();
                maxHeap.Enqueue(temp[0],-temp[0]);
            }
            if(maxHeap.Count>0){
                int cnt = maxHeap.Dequeue() -1;
                if(cnt > 0){
                    queue.Enqueue(new int[]{cnt,time+n+1});
                }
            }
            time++;
        }
        return time;
    }
}
