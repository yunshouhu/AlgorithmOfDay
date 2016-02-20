package com.yws.algorithmofday;

import java.util.*;   //蛇形填数
public class Snake
{
    static int a[][]=new int [15][15];
    public static void main(String  args[])
    {

        int n,i,j;
        Scanner sc=new Scanner(System.in);
        while(1==1)
        {	int x=0,y=0,k=0;
            a=new int [15][15];

            System.out.println("请输入阶数n:");
            n=sc.nextInt();
            if(n==0)break;

            x=0;
            y=n-1;
            a[x][y]=k=1;
            while(k<n*n)
            {	while( y+1<n && a[x][y+1]==0)a[x][++y]=++k;
                while(x+1<n && a[x+1][y]==0 )a[++x][y]=++k;
                while(y-1>=0 && a[x][y-1]==0)a[x][--y]=++k;
                while(x-1>=0 && a[x-1][y]==0 )a[--x][y]=++k;
            }
            for(i=0;i<n;i++)
            {	System.out.printf("\n");
                for(j=0;j<n;j++)
                    System.out.printf("%-4d",a[i][j]);
            }
            System.out.printf("\n");
        }
    }

}