
import java.util.Scanner;

/**
 * ����������һ��5x5�Ķ�ά���飬�������־���0��Ȼ�����ϽǱ��1������ѭ������һ������f(i)��
 * ����������һ��ȫ�ֱ������Ʒ���Ȼ��ÿ���ж��Ƿ񵽱߽���ߵ�����Ҫ�ı䷽�������
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
        //��ʼλ��
        fangzheng[x][y]=startIndex=1;
        //http://tieba.baidu.com/p/2907662150
        while(startIndex <n*n)
        {
            //�Ƿ񵽱߽� �� �� �� �� ��
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
