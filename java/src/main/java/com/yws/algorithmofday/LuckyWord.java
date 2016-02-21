package com.yws.algorithmofday;

import java.util.*;

/**
 * Created by wjh on 2016/2/21.
 *  oj题目 http://acm.nyist.net/JudgeOnline/problem.php?pid=62
 *  提交oj时 把包名去掉 类名改为Main
 */
public class LuckyWord {

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
    //是否质数（素数）
    static  boolean isPrime(int a)
    {
        if (a == 1 || a==0)
            return false;
        for (int i = 2; i*i<= a; i++)
            if (a%i == 0)
                return false;
        return true;
    }
    private static void doJob(String word) {
        char words[]=word.toCharArray();
        Map<Character,Integer> map=new HashMap<Character, Integer>();
        for(int i=0;i<words.length;i++)
        {
           char ch=words[i];
            if(!map.containsKey(ch))
            {
                map.put(ch,1);
            }else{
                int count=map.get(ch);
                count++;
                map.put(ch,count);
            }
        }
        int maxn,minn;
        maxn=minn=(Integer) map.values().toArray()[0];
        for(Integer number:map.values())
        {
            if(number>maxn)
            {
                maxn=number;
            }
            if(number<minn)
            {
                minn=number;
            }
        }
        int n=maxn-minn;
        if(isPrime(n))
        {
            System.out.println("Lucky Word");
            System.out.println(n);
        }else{
            System.out.println("No Answer");
            System.out.println(0);
        }
    }
}
