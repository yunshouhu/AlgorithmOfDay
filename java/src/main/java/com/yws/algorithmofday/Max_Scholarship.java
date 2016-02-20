package com.yws.algorithmofday;

import java.util.*;

/**
 * Created by Administrator on 2016/2/20.
 */
public class Max_Scholarship {

    public static  class ScholarShipStudent
    {
        String name;
        int gpa;
        int review_piont;//班级评议成绩
        String isCadre;//是否是学生干部
        String isWesterntudent;//是否是西部省份学生
        int paperNumber;//论文数

        public int getGpa() {
            return gpa;
        }

        public void setGpa(int gpa) {
            this.gpa = gpa;
        }

        public String getIsCadre() {
            return isCadre;
        }

        public void setIsCadre(String isCadre) {
            this.isCadre = isCadre;
        }

        public String getIsWesterntudent() {
            return isWesterntudent;
        }

        public void setIsWesterntudent(String isWesterntudent) {
            this.isWesterntudent = isWesterntudent;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public int getPaperNumber() {
            return paperNumber;
        }

        public void setPaperNumber(int paperNumber) {
            this.paperNumber = paperNumber;
        }

        public int getReview_piont() {
            return review_piont;
        }

        public void setReview_piont(int review_piont) {
            this.review_piont = review_piont;
        }

        public int GainScholarShip() {
            int scholarShip=0;
            if(gpa>80 &&paperNumber>=1)
            {
                scholarShip+=8000;
            }
            if(gpa>85 && review_piont>80)
            {
                scholarShip+=4000;
            }
            if(gpa>90)
            {
                scholarShip+=2000;
            }
            if(gpa>85 && isWesterntudent.equals("Y"))
            {
                scholarShip+=1000;
            }
            if(review_piont>80 &&isCadre.equals("Y"))
            {
                scholarShip+=850;
            }
            return scholarShip;
        }
    }
    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);
        int count;
        count=cin.nextInt();
        while (count>0) {
            int totalStudent=cin.nextInt();
            List<ScholarShipStudent> list=new ArrayList<ScholarShipStudent>(totalStudent);
            while(totalStudent>0)
            {

                //姓名，期末平均成绩，班级评议成绩，是否是学生干部，是否是西部省份学生，以及发表的论文数
                //chenruiyi 88 78 N Y 1
                String name=cin.next();
                //grade point average
                int gpa=cin.nextInt();//期末平均成绩
                int review_piont=cin.nextInt();//班级评议成绩
                String isCadre=cin.next();//是否是学生干部
                String isWesterntudent=cin.next();//是否是西部省份学生
                int paperNumber=cin.nextInt();//论文数
                ScholarShipStudent scholarShipStudent=new ScholarShipStudent();
                scholarShipStudent.setGpa(gpa);
                scholarShipStudent.setIsCadre(isCadre);
                scholarShipStudent.setIsWesterntudent(isWesterntudent);
                scholarShipStudent.setName(name);
                scholarShipStudent.setPaperNumber(paperNumber);
                scholarShipStudent.setReview_piont(review_piont);
                list.add(scholarShipStudent);
                totalStudent--;
            }
            doJob(list);
            count--;
        }
        cin.close();


    }

    private static void doJob(List<ScholarShipStudent> list) {

        Collections.sort(list, new Comparator<ScholarShipStudent>() {

            public int compare(ScholarShipStudent o1, ScholarShipStudent o2) {
                int scholarShip1=o1.GainScholarShip();
                int scholarShip2=o2.GainScholarShip();
                return scholarShip2-scholarShip1;
            }
        });
        int total=0;
        for(int i=0;i<list.size();i++)
        {
            total+=list.get(i).GainScholarShip();
        }
        System.out.println(list.get(0).getName());

        if(list.size()>1 && list.get(0)==list.get(1))
        {
            System.out.println(list.get(0).getName());
        }else{
            System.out.println(list.get(0).GainScholarShip());
        }
        System.out.println(total);


    }
}
