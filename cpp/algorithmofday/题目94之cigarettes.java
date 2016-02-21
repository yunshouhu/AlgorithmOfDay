
import java.util.Scanner;
/**
 * Created by wjh on 2016/2/21.
 *  oj题目 http://acm.nyist.net/JudgeOnline/problem.php?pid=94
 *  提交oj时 把包名去掉 类名改为Main
 */
public class Main {

    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);
        int count;
        count=cin.nextInt();
        while (count>0) {
            int n=cin.nextInt();
            int k=cin.nextInt();
            int sum=getResult2(n,k);
            System.out.println(sum);
            count--;
        }
        cin.close();
    }
    //有n支烟，每吸k根就再给他一根，问一共有多少烟？题目好难懂！！
    private static int getResult(int n, int k) {
        int total=n;
        while(n>=k)
        {
            total+=n/k;
            n=n/k+n%k;
        }
        return total;
    }
    //每K个烟头可以换根新烟抽，求n根烟总共能抽几根
    private static int getResult2(int n, int k) {
        for(int i=1;i<=n;i++)
        {
            if(i% k==0)
                n++;
        }
        return n;
    }

}
