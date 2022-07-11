import java.io.*;
import java.util.*;
import javafx.util.Pair;
public class A{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        while(t-->0){
            String w,ans="";
            w = input.next();
            long p = input.nextLong();
            ArrayList<Pair<Character,Integer>> tmp = new ArrayList<Pair<Character,Integer>>();
            for(int i=0;i<w.length();i++){
                tmp.add(new Pair<Character,Integer>(w.charAt(i),i));
            }
            Collections.sort(tmp,(a,b)->a.getValue()-b.getValue());
            long cur = 0;
            for(int i=0;i<tmp.size();i++){
                cur += (tmp.get(i).getKey()-'a'+1);
                if(cur>p){
                    cur -= (tmp.get(i).getKey()-'a'+1);
                    w.setcharAt(tmp.get(i).getValue(),'#');
                }
            }
            for(int i=0;i<w.length();i++){
                if(w.charAt(i)!='#'){
                    ans += w.charAt(i);
                }
            }
            System.out.println(ans);
        }
        input.close();
    }
}