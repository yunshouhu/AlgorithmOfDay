package com.yws.algorithmofday;

import java.util.*;

/**
 * Created by wjh on 2016/1/27.
 *  oj题目 http://acm.nyist.net/JudgeOnline/problem.php?pid=8
 *  提交oj时 把包名去掉 类名改为Main
 */
public class MySort {

    public static void main(String[] args) {

        test();
        testBinarySearch();

        Scanner cin = new Scanner(System.in);
        int count;
        count=cin.nextInt();

        while (count>0) {

            String line="";
            if(cin.hasNextLine())
            {
                 line=cin.nextLine();
            }
            if(line.trim().equals(""))
            {
                 line=cin.nextLine();
            }


            String[] lines=line.split(" ");
            int data[]=new int[lines.length];
            for(int i=0;i<lines.length;i++)
            {
                data[i]=Integer.parseInt(lines[i]);
            }
            System.out.println(Arrays.toString(data));
            //quicksort(data,0,data.length-1);
           // mergesort(data,0,data.length-1);
            bubblesort(data);
            System.out.println(Arrays.toString(data));
            count--;
        }
        cin.close();


    }

    private static void testBinarySearch() {

        int list_bsearch[] = { 2,12,34,45,52,59 };

        int result=binarySearch(list_bsearch,52,0,list_bsearch.length);
        System.out.println(result);
    }

    private static int binarySearch(int[] list_bsearch, int data, int left, int right) {

        while(left<=right)
        {
            int index=(left+right)/2;
            if(data==list_bsearch[index])
                return index;

            if(data<list_bsearch[index])
            {
                right=index-1;
            }else{
                left=index+1;
            }
        }
        return -1;


    }

    private static void mergesort(int[] data, int left, int right) {

        if(left>=right)
        {
            return ;
        }
        int middle=(left+right)/2;
        mergesort(data,left,middle);
        mergesort(data,middle+1,right);
        merge(data,left,middle,right);
    }

    private static void merge(int[] data, int left, int middle, int right) {
        int arr[]=new int[data.length];
        int mid=middle+1;
        int arr_index=left;
        int arr_left=left;
        while(left<=middle && mid<=right)
        {
            if(data[left]<=data[mid])
            {
                arr[arr_index++]=data[left++];
            }else{
                arr[arr_index++]=data[mid++];
            }
        }
        while(mid<=right)
        {
            arr[arr_index++]=data[mid++];

        }
        while(left<=middle)
        {
            arr[arr_index++]=data[left++];
        }
        while(arr_left<=right)
        {
            data[arr_left]=arr[arr_left++];
        }
    }

    private static void test() {

        int[] data={1,5,4,4,67,8,4,3,129};
        //quicksort(data,0,data.length-1);
        //mergesort(data,0,data.length-1);
        bubblesort(data);
        System.out.println(Arrays.toString(data));
    }

    private static void bubblesort(int[] data) {
        boolean isSorted=false;
        for(int i=0;i<data.length-1;i++)
        {
            isSorted=true;
            for(int j=0;j<data.length-i-1;j++)
            {
                if(data[j]>data[j+1])
                {
                    int tmp=data[j];
                    data[j]=data[j+1];
                    data[j+1]=tmp;
                    isSorted=false;
                }
            }
            if(isSorted)
            {
                break;
            }
        }


    }

    private static void quicksort(int[] data, int low, int high) {

        if(low<high)
        {
            int p=partion(data,low,high);
            quicksort(data,low,p-1);
            quicksort(data,p+1,high);
        }

    }

    private static int partion(int[] data, int low, int high) {
        int first=data[low];
        while(low<high)
        {
            while (low<high && data[high] >= first)
            {
                high--;
            }
            if(low<high)
                data[low++]=data[high];

            while(low<high && data[low] <= first)
            {
                low++;
            }
            if(low<high)
                data[high--]=data[low];

        }
        data[low]=first;
        return high;

    }

}
