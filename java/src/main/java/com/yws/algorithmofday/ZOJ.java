package com.yws.algorithmofday;

import java.util.*;

/**
 * Created by wjh on 2016/2/23.
 *  oj题目 http://ac.jobdu.com/problem.php?pid=1032
 *  提交oj时 把包名去掉 类名改为Main
 *  http://ac.jobdu.com/faqs.php
 */
public class ZOJ {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        String word;
        while (cin.hasNext()) {
            word=cin.next();
            if(word.equals("E"))
            {
                break;
            }
            doJob(word);
        }
        // System.out.println();
        cin.close();
    }

    private static void doJob(String word) {
        char[] chs=word.toCharArray();
        int count_Z=0;
        int count_O=0;
        int count_J=0;
        for (Character ch:chs)
        {
            if(ch.equals('Z'))
            {
                count_Z++;
            }
            if(ch.equals('O'))
            {
                count_O++;
            }
            if(ch.equals('J'))
            {
                count_J++;
            }
        }
        while(count_Z>0 || count_O>0 || count_J>0)
        {
            if(count_Z>0)
            {
                System.out.print('Z');
                count_Z--;
            }
            if(count_O>0)
            {
                System.out.print('O');
                count_O--;
            }
            if(count_J>0)
            {
                System.out.print("J");
                count_J--;
            }
        }
        System.out.println();
    }

    private static void doJob2(String word) {
        char[] chs=word.toCharArray();
        Map<Character,Integer> maps=new HashMap<Character, Integer>();
        for (char ch:chs)
        {
            if(!maps.containsKey(ch))
            {
                maps.put(ch,1);
            }else{
                int count=maps.get(ch);
                count++;
                maps.put(ch,count);
            }
        }
        int count_Z=0;
        if(maps.containsKey('Z'))
        {
            count_Z= maps.get('Z');
        }


        int count_O=0;
        if(maps.containsKey('O'))
        {
            count_O= maps.get('O');
        }
        int count_J=0;
        if(maps.containsKey('J'))
        {
            count_J= maps.get('J');
        }
        while(count_Z>0 || count_O>0 || count_J>0)
        {
            if(count_Z>0)
            {
                System.out.print('Z');
                count_Z--;
            }
            if(count_O>0)
            {
                System.out.print('O');
                count_O--;
            }
            if(count_J>0)
            {
                System.out.print("J");
                count_J--;
            }
        }
        System.out.println();

    }
}
