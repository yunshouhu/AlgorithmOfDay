package com.yws.algorithmofday;

import java.util.*;

/**
 * Created by wjh on 2016/1/27.
 *  oj题目 http://acm.nyist.net/JudgeOnline/problem.php?pid=8
 *  提交oj时 把包名去掉 类名改为Main
 */
public class OneSort {

    //长方形
    public static class Rectangle
    {
        //编号id
        private int id;
        //长
        private int length;
        //宽
        private int with;

        public Rectangle(){

        }
        public Rectangle(int id, int length, int with) {
            this.id = id;
            this.length = length;
            this.with = with;
        }

        public int getId() {
            return id;
        }

        public void setId(int id) {
            this.id = id;
        }

        public int getLength() {
            return length;
        }

        public void setLength(int length) {
            this.length = length;
        }

        public int getWith() {
            return with;
        }

        public void setWith(int with) {
            this.with = with;
        }
    }
    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);
        int count;
        int m;
        count=cin.nextInt();

        while (count>0) {
            m = cin.nextInt();//m个长方形
            List<Rectangle> list=new ArrayList<Rectangle>(m);
            while(m>0)
            {
                int id=Integer.parseInt(cin.next());
                int a=Integer.parseInt(cin.next());
                int b=Integer.parseInt(cin.next());
                Rectangle rectangle=new Rectangle();
                rectangle.setId(id);
                if(a>b)
                {
                    rectangle.setLength(a);
                    rectangle.setWith(b);
                }else{
                    rectangle.setLength(b);
                    rectangle.setWith(a);
                }
                list.add(rectangle);

                m--;
            }
            doJob(list);

            count--;
        }
        cin.close();


    }

    private static void doJob(final List<Rectangle> list) {

        final List<Rectangle> delList=new ArrayList<Rectangle>();

        Collections.sort(list, new Comparator<Rectangle>() {
            public int compare(Rectangle o1, Rectangle o2) {
                int ret=0;
                ret=o1.getId()-o2.getId();
                if(ret==0)
                {
                    ret=o1.getLength()-o2.getLength();
                    if(ret==0)
                    {
                        ret=o1.getWith()-o2.getWith();
                        if(ret==0)
                        {
                            delList.add(o1);
                        }
                    }
                }
                return ret;
            }
        });
        list.removeAll(delList);

        for(Rectangle rectangle:list)
        {
            System.out.println(rectangle.getId()+" "+rectangle.getLength()+" "+rectangle.getWith());
        }

    }
}
