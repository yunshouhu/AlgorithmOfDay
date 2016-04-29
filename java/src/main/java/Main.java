
import java.util.*;

/**
 * Created by wjh on 2016/2/23.
 *  oj题目 http://ac.jobdu.com/problem.php?pid=198
 *  提交oj时 把包名去掉 类名改为Main
 *  http://ac.jobdu.com/faqs.php
 */
public class Main {

        private static Map<Integer,Character> map=new HashMap<Integer, Character>();
        static {
            map.put(0,'O');
            map.put(1,'O');
            map.put(2,'T');
            map.put(3,'T');
            map.put(4,'F');
            map.put(5,'F');
            map.put(6,'S');
            map.put(7,'S');
            map.put(8,'E');
            map.put(9,'N');
        }
        public static void main(String[] args) {
            Scanner cin = new Scanner(System.in);
            int count;
            count=cin.nextInt();
            while (count>0) {
                String word=cin.next();
                doJob(word);
                count--;
            }
            cin.close();
        }

        private static void doJob(String word) {
            char datas[]=word.toCharArray();
            for(int i=datas.length-1;i>=0;i--)
            {
                int key=Integer.parseInt(String.valueOf(datas[i]));
                System.out.print(map.get(key));
            }
            System.out.println();
        }
    }
