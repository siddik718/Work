import java.util.*;
import java.io.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        ArrayList<ArrayList<Integer>>adj = new ArrayList<ArrayList<Integer>>();
        int n,m;
        n = sc.nextInt();
        m = sc.nextInt();
        for(int i = 0; i <= n; i++){
            adj.add(new ArrayList<Integer>());
        }
        for(int i = 0; i < m; i++){
            int a,b;
            a = sc.nextInt();
            b = sc.nextInt();
            adj.get(a).add(b);
            adj.get(b).add(a);
        }
        int source = 1,destination = n;
        int[]dist = new int[n+1];
        int[]parent = new int[n+1];
        boolean[]vis = new boolean[n+1];
        LinkedList<Integer>queue = new LinkedList<Integer>();
        queue.push(source);
        vis[source] = true;
        dist[source] = 0;
        parent[source] = -1;
        while(!queue.isEmpty()){
            int u = queue.pop();
            for(int v : adj.get(u)){
                if(!vis[v]){
                    vis[v] = true;
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    queue.push(v);
                }
            }
        }
        if(!vis[destination]){
            System.out.println("No Path");
        }else{
            ArrayList<Integer> path = new ArrayList<Integer>();
            for(int v = destination ; v != -1 ;v = parent[v]){
                path.add(v);
            }
            Collections.reverse(path);
            for(int i : path){
                System.out.print(i+" ");
            }
            System.out.println();
        }

        sc.close();
    }
}