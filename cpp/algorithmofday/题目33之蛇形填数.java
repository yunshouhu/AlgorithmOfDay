
import java.util.Scanner;

/**
 * 比如先生成一张5x5的二维数组，所有数字均填0，然后右上角变成1，不断循环调用一个函数f(i)，
 * 这个函数里放一个全局变量控制方向，然后每次判断是否到边界或者到底需要改变方向就行了
 */
public class Main {

    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);
        int n;
        n=cin.nextInt();
        int fangzheng[][]=new int[n][n];
        int startIndex=0;
        int x=0;
        int y=n-1;
        //开始位置
        fangzheng[x][y]=startIndex=1;
        //http://tieba.baidu.com/p/2907662150
        while(startIndex <n*n)
        {
            //是否到边界 下 左 上 右 下
            while(y+1<n  && fangzheng[x][y+1]==0)
            {
                //fangzheng[x][++y]=++startIndex;
                startIndex++;
                y++;
                fangzheng[x][y]=startIndex;
            }
            while(x+1< n && fangzheng[x+1][y]==0)
            {
                //fangzheng[++x][y]=++startIndex;
                startIndex++;
                x++;
                fangzheng[x][y]=startIndex;
            }
            while(y-1>=0  && fangzheng[x][y-1]==0)
            {
                //fangzheng[x][--y]=++startIndex;
                startIndex++;
                y--;
                fangzheng[x][y]=startIndex;
            }
            while(x-1>=0  && fangzheng[x-1][y]==0)
            {
                //fangzheng[--x][y]=++startIndex;
                startIndex++;
                x--;
                fangzheng[x][y]=startIndex;

            }

        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                System.out.print(fangzheng[i][j]+" ");
            }
            System.out.println();
        }
        cin.close();
    }
}
