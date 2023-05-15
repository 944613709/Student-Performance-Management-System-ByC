#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<io.h>
#include<windows.h>
#define N 99
typedef struct course_s
{
    char coursename[100];
    int coursescore;
} COURSE_S;
typedef struct student_s
{
    char num[100];
    char name[100];
    COURSE_S course[6];
} STUDENT_S;
void input(STUDENT_S *student, int *Pnum_student, int *Pnum_course); //OK
void output(STUDENT_S *student, int num_student, int num_course, int stuscore_sum[], float stuscore_ave[], int coursescore_sum[], float coursescore_ave[]); //OK
void Calculatecourse(STUDENT_S *student, int flag_ifprintf, int num_student, int num_course, int coursescore_sum[], float coursescore_ave[]); //һ����Ŀ����ѧ���ܷ� OK
void Calculatestudent(STUDENT_S *student, int flag_ifprintf, int num_student, int num_course, int *stuscore_sum, float *stuscore_ave); //һ��ѧ������Ŀ�ܷ� OK
void sort_by_XueHao(STUDENT_S *student, int num_student, int num_course); //��ѧ����С�����ţ�OK
void sort_by_XingMing(STUDENT_S *student, int num_student, int num_course); //���������ֵ�˳����OK
void Search_by_num(STUDENT_S *student, int num_student, int num_course); //��ѧ�Ų�ѯѧ���������俼�Գɼ�OK
void Search_by_XingMing(STUDENT_S *student, int num_student, int num_course); //��������ѯѧ���������俼�Գɼ���
int Mymenu(void);
void Myread(void);
void PaiXu_1 (STUDENT_S *student, int num_student, int num_course, int stuscore_sum[]); //��d��g
void PaiXu_2 (STUDENT_S *student, int num_student, int num_course, int stuscore_sum[]); //�Ӹߵ���
void Mywrite(STUDENT_S *student, int num_student, int num_course, int stuscore_sum[], float stuscore_ave[], int coursescore_sum[], float coursescore_ave[]);
void TongJi(STUDENT_S *student, int num_student, int num_course, int stuscore_sum[], float stuscore_ave[], int coursescore_sum[], float coursescore_ave[]); //�����㣨90~100�ֱ�ͳ��ÿ�����������Լ���ռ�İٷֱ�
int main()
{
    int coursescore_sum[6] = {0}; //��Ŀ����ѧ���ܷ�
    float coursescore_ave[6] = {0}; //��Ŀƽ�� ��
    int stuscore_sum[30] = {0}; //gѧ�����п�Ŀ�ܷ�
    float stuscore_ave[30] = {0}; //һ��ѧ�����п�Ŀ�ۼƵ�ƽ����
    int num_student;//һ������stu
    int num_course;//һ������course
    int order;
    STUDENT_S student[30];
    printf("             LOADING!!!!!!!!!!!!!!!!!");
    Sleep(500);//��Ч����
    Beep(523, 500); //��Ч����
    Beep(587, 500); //��Ч����
    Beep(659, 500); //��Ч����
    Beep(698, 500); //��Ч����
    Beep(784, 500); //��Ч����
    system("cls");//������Ļ�ͻ�����

    //1�Ų�����   û�����룬������ܷ�Ϊ0������ȡ��1�Ų��Ծ�û���⣬���ùܣ�

    //Calculatecourse(student);//��ǰ���м���һ����Ŀ����ѧ���ܷ�
    //Calculatestudent(student);//��ǰ���м���һ��ѧ������Ŀ�ܷ�
    //Search_by_num(student);
    //sort_by_XueHao(student);
    //sort_by_XingMing(student);
    //output(student);
    //input(student);
tag:
    order = Mymenu();
    switch (order)
    {
    case 1:
        input(student, &num_student, &num_course);
        Calculatecourse(student, 0, num_student, num_course, coursescore_sum, coursescore_ave);
        Calculatestudent(student, 0, num_student, num_course, stuscore_sum, stuscore_ave);
        break;
    case 2:
        Calculatecourse(student, 1, num_student, num_course, coursescore_sum, coursescore_ave);
        break;
    case 3:
        Calculatestudent(student, 1, num_student, num_course, stuscore_sum, stuscore_ave);
        break;//1->Ҫ��ӡ;
    case 4:
        PaiXu_2(student, num_student, num_course, stuscore_sum);
        break;
    case 5:
        PaiXu_1(student, num_student, num_course, stuscore_sum);
        break;
    case 6:
        sort_by_XueHao(student, num_student, num_course);
        break;
    case 7:
        sort_by_XingMing(student, num_student, num_course);
        break;
    case 8:
        Search_by_num(student, num_student, num_course);
        break;
    case 9:
        Search_by_XingMing(student, num_student, num_course);
        break;
    case 10:
        TongJi(student, num_student, num_course, stuscore_sum, stuscore_ave, coursescore_sum, coursescore_ave);
        break;
    case 11:
        output(student, num_student, num_course, stuscore_sum, stuscore_ave, coursescore_sum, coursescore_ave);
        break;
    case 12:
        Mywrite(student, num_student, num_course, stuscore_sum, stuscore_ave, coursescore_sum, coursescore_ave);
        break;
    case 13:
        Myread();
        break;
    case 0:
        break;
    }
    if (order > 13 || order < 0)
    {
        printf("�������������³���\n");
        system("pause");
        system("cls");//������Ļ�ͻ�����
        fflush(stdin);
        goto tag;
    }
    else if (order == 0)
    {
        int temp;
        printf("��ȷ���Ƿ��˳���1(yes)/2(no) ");
        while (scanf("%d", &temp) != 1 || temp > 2 || temp < 1)
        {
            printf("�����������������\n");
            while (getchar() != '\n');
        }
        if (temp == 1)
        {
            system("cls");//����ʱ������Ļ�ͻ���������ӡ�·���У��
            fflush(stdin);
            printf("\n��лʹ�ã�\n");
            printf("\n                                                               \n");
            printf("     ****          ****    ******************    ******************  \n");
            printf("     ****          ****    ******************    ******************  \n");
            printf("     ****          ****           ****                  ****  \n");
            printf("     ****          ****           ****                  **** \n");
            printf("     ******************           ****                  ****      \n");
            printf("     ******************           ****                  ****   \n");
            printf("     ****          ****           ****                  ****   \n");
            printf("     ****          ****           ****                  ****   \n");
            printf("     ****          ****    ******************           ****   \n");
            printf("     ****          ****    ******************           ****   \n");
            system("pause");
            return 0;
        }
        else if (order == 2)
        {
            system("cls");//������Ļ�ͻ�����
            fflush(stdin);
            goto tag;
        }
    }
    else
    {
        printf("\t\t\t\t\t\n�ɹ�ִ��\n");
        system("pause");
        system("cls");//������Ļ�ͻ�����
        goto tag;
    }
}

int Mymenu(void)
{
    int order;
    printf("\n");
    printf("\t\t\t\t\t\t��ѧ������ϵͳ6.0��\t\t\t\t\t\n");
    printf("\t\t���������������������������������������������������������������������������������\n\n");
    printf("\t\t\t | 1. ��Ϣ¼��                   2.����ÿ�ſγ̵��ֺܷ�ƽ����     3.����ÿ��ѧ�����ֺܷ�ƽ���� |\n\n");
    printf("\t\t\t | 4. �ܷ��ɸߵ����ų����α�     5.�ܷ��ɵ͵����ų����α�         6.��ѧ����С�����ų��ɼ���  |\n\n");
    printf("\t\t\t | 7.���������ֵ�˳���ų��ɼ���  8.��ѧ�Ų�ѯѧ������  	        9. ��������ѯѧ������  |\n\n");
    printf("\t\t\t | 10.��ÿ�ſγ̷ֱ�ͳ��         11.���ÿ��ѧ����Ϣ              12.��¼��Ϣд���ļ�  |\n\n");
    printf("\t\t\t | 13.���ļ��ж���ѧ����Ϣ\n\n");
    printf("\t\t���������������������������������0���س��˳���������������������������������������\n");
    printf("������ִ������:");
    printf("\\ "
       "Please enter your choice: \n"
           );
           printf("��ӭ����ѧ���������ϵͳ\n");
           printf("���������ִ��\n");
           while(scanf(" % d",&order)!=1)
           {   printf("�����������������\n");
           while(getchar()!='\n');
       }
           return order;
       }

           void TongJi(STUDENT_S *student,int num_student,int num_course,int stuscore_sum[],float stuscore_ave[],int coursescore_sum[],float coursescore_ave[])
           {

           int i,j;
           for(i=0;i<num_course;i++)
           {
           printf("��Ŀ���ƣ� % s",student[0].course[i].coursename);
           int countperson[5]={0};
           for(j=0;j<num_student;j++)
           {
           if(student[j].course[i].coursescore<=100&&student[j].course[i].coursescore>=90)
           countperson[0]++;//youxiu
           if(student[j].course[i].coursescore<=89&&student[j].course[i].coursescore>=80)
           countperson[1]++;//youxiu
           if(student[j].course[i].coursescore<=79&&student[j].course[i].coursescore>=70)
           countperson[2]++;//youxiu
           if(student[j].course[i].coursescore<=69&&student[j].course[i].coursescore>=60)
           countperson[3]++;//youxiu
           if(student[j].course[i].coursescore<=59&&student[j].course[i].coursescore>=0)
           countperson[4]++;//youxiu
       }
           printf("���� % d��ռ % f \n",countperson[0],(float)countperson[0]/num_student);
           printf("���� % d��ռ % f \n",countperson[1],(float)countperson[1]/num_student);
           printf("�е� % d��ռ % f \n",countperson[2],(float)countperson[2]/num_student);
           printf("���� % d��ռ % f \n",countperson[3],(float)countperson[3]/num_student);
           printf("������ % d��ռ % f \n",countperson[4],(float)countperson[4]/num_student);
       }
       }
           void PaiXu_1 (STUDENT_S *student,int num_student,int num_course,int stuscore_sum[])
           {
           int i,j;
           int n=num_student;
           STUDENT_S temp;
           int tempint;
           for(i=0;i<n-1;i++)
           for(j=0;j<n-1-i;j++)
           {
           if(stuscore_sum[j]>stuscore_sum[j+1])
           {
           temp=student[j];
           student[j]=student[j+1];
           student[j+1]=temp;
           tempint=stuscore_sum[j];
           stuscore_sum[j]=stuscore_sum[j+1];
           stuscore_sum[j+1]=tempint;
       }
       }
           for(i=0;i<num_student;i++)
           {
           printf("��ǰ�� % dλѧ����Ϣ����\n",i+1);
           printf("ѧ�� % s\n",student[i].num);
           printf("���� % s\n",student[i].name);
       printf("�ܳɼ�: % d\n",stuscore_sum[i]);

       }
       }
           void PaiXu_2 (STUDENT_S *student,int num_student,int num_course,int stuscore_sum[])
           {
           int i,j;
           int n=num_student;
           STUDENT_S temp;
           int tempint;
           for(i=0;i<n-1;i++)
           for(j=0;j<n-1-i;j++)
           {
           if(stuscore_sum[j]<stuscore_sum[j+1])
           {
           temp=student[j];
           student[j]=student[j+1];
           student[j+1]=temp;
           tempint=stuscore_sum[j];
           stuscore_sum[j]=stuscore_sum[j+1];
           stuscore_sum[j+1]=tempint;
       }
       }
           for(i=0;i<num_student;i++)
           {
           printf("��ǰ�� % dλѧ����Ϣ����\n",i+1);
           printf("ѧ�� % s\n",student[i].num);
           printf("���� % s\n",student[i].name);
       printf("�ܳɼ�: % d\n",stuscore_sum[i]);

       }
       }
           void Myread()
           {
           int oldstdin = dup(0);
           freopen("a.txt","r",stdin);
           char ch;
           while((ch=getchar())!=EOF) putchar(ch);
           freopen("con","r",stdin);
           dup2(oldstdin,0);
       }
           void Mywrite(STUDENT_S *student,int num_student,int num_course,int stuscore_sum[],float stuscore_ave[],int coursescore_sum[],float coursescore_ave[])
           {
           int i,j;
           int oldstdout=dup(1);
           freopen("a.txt","w",stdout);
           for(i=0;i<num_student;i++)
           {
           printf("��ǰ�� % dλѧ����Ϣ����\n",i+1);
           printf("ѧ�� % s\n",student[i].num);
           printf("���� % s\n",student[i].name);
           for(j=0;j<num_course;j++)
           {
       printf("��Ŀ���ƣ� % s      �ɼ�: % d\n",student[i].course[j].coursename,student[i].course[j].coursescore);
       }
           printf("��ѧ�����п�Ŀ�ܷ�  % d \n",stuscore_sum[i]);
           printf("��ѧ�����п�Ŀƽ����  % .2f\n",stuscore_ave[i]);
       }
           fclose(stdout);
           freopen("con", "w", stdout);
           dup2(oldstdout,1);
       }
           void Search_by_XingMing(STUDENT_S *student,int num_student,int num_course)//��������ѯѧ���������俼�Գɼ���
           {
           int i,j;//i��¼�ҵ�ѧ��֮���i
           int Found=0;//��δ�ҵ�
           char getname[99];
           printf("\nĿǰ����������ѯѧ���������俼�Գɼ�\n");
           printf("������������");
           fflush(stdin);
           gets(getname);
           for(i=0;i<num_student;i++)
           {
           if(strcmp(student[i].name,getname)==0)
           {
           Found=1;//�ҵ�
           break;
       }
       }
           //����i��¼�ҵ�ѧ��֮���i
           if(Found==1)
           {
           printf("��ѧ����Ϣ����\n");
           printf("ѧ�� % s\n",student[i].num);
           printf("���� % s\n",student[i].name);
           for(j=0;j<num_course;j++)
           {
       printf("��Ŀ���ƣ� % s      �ɼ�: % d\n",student[i].course[j].coursename,student[i].course[j].coursescore);
       }
       }
           else
           {
           printf("��ѧ������δ����\n");//����ģ������
           int temp;
           printf("��ȷ��Ҫ����ģ��������1(yes) / 2(no) ");
           while(scanf(" % d",&temp)!=1||temp>2||temp<1)
           {   printf("�����������������\n");
           while(getchar()!='\n');
       }
           //!!!!!!!!!!!!!!!!!!!!!
           if(temp==1);//����ģ������
           {
           char getname_mohu[99];
           fflush(stdin);
           printf("��������Ҫ���ҵ�ѧ�������п��ܺ��е��֣�");
           gets(getname_mohu);
           int count=1;
           int Found_mohu=0;
           for(i=0;i<num_student;i++)
           {
           if(strstr(student[i].name,getname_mohu)!=NULL)
           {
           Found_mohu=1;//ģ��ƥ�䵽�ˣ�
           printf("ģ��ƥ�䵽�ĵ� % dλѧ����Ϣ����\n",count);
           printf("ѧ�� % s\n",student[i].num);
           printf("���� % s\n",student[i].name);
           for(j=0;j<num_course;j++)
           {
       printf("��Ŀ���ƣ� % s      �ɼ�: % d\n",student[i].course[j].coursename,student[i].course[j].coursescore);
       }
           count++;
       }
       }
           if(Found_mohu==0)
           {printf("�ܱ�Ǹ��ģ��ƥ��Ҳ��δƥ�䵽�������ֵ�ѧ������\n");
           return;
       }
       }
           //!!!!!!!!!!
           if(temp==2)
           return;
       }

       }

           void Search_by_num(STUDENT_S *student,int num_student,int num_course)
           {
           int i,j;//i��¼�ҵ�ѧ��֮���i
           int Found=0;//��δ�ҵ�
           char getnum[99];
           printf("\nĿǰ���밴ѧ�Ų�ѯѧ���������俼�Գɼ�\n");
           printf("������ѧ�ţ�");
           fflush(stdin);
           gets(getnum);
           for(i=0;i<num_student;i++)
           {
           if(strcmp(student[i].num,getnum)==0)
           {
           Found=1;//�ҵ�
           break;
       }
       }
           //����i��¼�ҵ�ѧ��֮���i
           if(Found==1)
           {
           printf("��ѧ����Ϣ����\n");
           printf("ѧ�� % s\n",student[i].num);
           printf("���� % s\n",student[i].name);
           for(j=0;j<num_course;j++)
           {
       printf("��Ŀ���ƣ� % s      �ɼ�: % d\n",student[i].course[j].coursename,student[i].course[j].coursescore);
       }
       }
           else
           {
           printf("��ѧ��δ����\n");//����ģ������
           int temp;
           printf("��ȷ��Ҫ����ģ��������1(yes) / 2(no) ");
           while(scanf(" % d",&temp)!=1||temp>2||temp<1)
           {   printf("�����������������\n");
           while(getchar()!='\n');
       }
           //!!!!!!!!!!!!!!!!!!!!!
           if(temp==1);//����ģ������
           {
           char getnum_mohu[99];
           fflush(stdin);
           printf("��������Ҫ���ҵ�ѧ���п��ܺ��е����֣�");
           gets(getnum_mohu);
           int count=1;
           int Found_mohu=0;
           for(i=0;i<num_student;i++)
           {
           if(strstr(student[i].num,getnum_mohu)!=NULL)
           {
           Found_mohu=1;//ģ��ƥ�䵽�ˣ�
           printf("ģ��ƥ�䵽�ĵ� % dλѧ����Ϣ����\n",count);
           printf("ѧ�� % s\n",student[i].num);
           printf("���� % s\n",student[i].name);
           for(j=0;j<num_course;j++)
           {
       printf("��Ŀ���ƣ� % s      �ɼ�: % d\n",student[i].course[j].coursename,student[i].course[j].coursescore);
       }
           count++;
       }
       }
           if(Found_mohu==0)
           {printf("�ܱ�Ǹ��ģ��ƥ��Ҳ��δƥ�䵽���������ֵ�ѧ��\n");
           return;
       }
       }
           //!!!!!!!!!!
           if(temp==2)
           return;
       }
       }

           void sort_by_XingMing(STUDENT_S *student,int num_student,int num_course)
           {
           int i,j;
           int n=num_student;
           STUDENT_S temp;
           for(i=0;i<n-1;i++)
           for(j=0;j<n-1-i;j++)
           {
           if(strcmp(student[j].name,student[j+1].name)>0)
           {
           temp=student[j];
           student[j]=student[j+1];
           student[j+1]=temp;
       }
       }
           for(i=0;i<num_student;i++)
           {
           printf("��ǰ�� % dλѧ����Ϣ����\n",i+1);
           printf("ѧ�� % s\n",student[i].num);
           printf("���� % s\n",student[i].name);
           for(j=0;j<num_course;j++)
           {
       printf("��Ŀ���ƣ� % s      �ɼ�: % d\n",student[i].course[j].coursename,student[i].course[j].coursescore);
       }

       }
       }
           void sort_by_XueHao(STUDENT_S *student,int num_student,int num_course)
           {
           int i,j;
           int n=num_student;
           STUDENT_S temp;
           for(i=0;i<n-1;i++)
           for(j=0;j<n-1-i;j++)
           {
           if(strcmp(student[j].num,student[j+1].num)>0)
           {
           temp=student[j];
           student[j]=student[j+1];
           student[j+1]=temp;
       }
       }
           for(i=0;i<num_student;i++)
           {
           printf("��ǰ�� % dλѧ����Ϣ����\n",i+1);
           printf("ѧ�� % s\n",student[i].num);
           printf("���� % s\n",student[i].name);
           for(j=0;j<num_course;j++)
           {
       printf("��Ŀ���ƣ� % s      �ɼ�: % d\n",student[i].course[j].coursename,student[i].course[j].coursescore);
       }

       }
       }
           void Calculatecourse(STUDENT_S *student,int flag_ifprintf,int num_student,int num_course,int coursescore_sum[],float coursescore_ave[])//һ����Ŀ����ѧ���ܷ�
           {
           int i;
           int j;
           for(i=0;i<num_course;i++)
           {
           for(j=0;j<num_student;j++)
           {
           coursescore_sum[i]+=student[j].course[i].coursescore;//�ܷ�
       }
           coursescore_ave[i]=(float)(coursescore_sum[i])/(float)num_student;//ƽ����
       }
           if(flag_ifprintf==1)//�Ƿ�Ҫ��ӡ
           {
           for(i=0;i<num_course;i++)
           {
           printf("��ǰ�� % d�ſγ���Ϣ����\n",i+1);
           printf("�γ��� % s\n",student[0].course[i].coursename);
           printf("�ÿ�Ŀ�ܷ�  % d \n",coursescore_sum[i]);
           printf("�ÿ�Ŀƽ����  % .2f\n",coursescore_ave[i]);
       }
       }
           else if(flag_ifprintf==0)//���ô�ӡ
           {
           return;
       }
       }
           void Calculatestudent(STUDENT_S *student,int flag_ifprintf,int num_student,int num_course,int *stuscore_sum,float *stuscore_ave)//һ��ѧ������Ŀ�ܷ�
           {
           int i;
           int j;
           for(i=0;i<num_student;i++)
           {
           for(j=0;j<num_course;j++)
           {
           stuscore_sum[i]+=student[i].course[j].coursescore;//�ܷ�
       }
           stuscore_ave[i]=(float)(stuscore_sum[i])/(float)num_course;//ƽ����
           //printf(" % f\n",coursescore_ave[i]);
       }
           if(flag_ifprintf==1)//�Ƿ�Ҫ��ӡ
           {
           for(i=0;i<num_student;i++)
           {
           printf("��ǰ�� % dλѧ����Ϣ����\n",i+1);
           printf("ѧ�� % s",student[i].num);
           printf("       ���� % s\n",student[i].name);
           printf("��ѧ�����п�Ŀ�ܷ�  % d \n",stuscore_sum[i]);
           printf("��ѧ�����п�Ŀƽ����  % .2f\n",stuscore_ave[i]);
       }
       }
           else if(flag_ifprintf==0)//���ô�ӡ
           return;
       }
           void output(STUDENT_S *student,int num_student,int num_course,int stuscore_sum[],float stuscore_ave[],int coursescore_sum[],float coursescore_ave[])
           {

           int i,j;
           for(i=0;i<num_student;i++)
           {
           printf("��ǰ�� % dλѧ����Ϣ����\n",i+1);
           printf("ѧ�� % s\n",student[i].num);
           printf("���� % s\n",student[i].name);
           for(j=0;j<num_course;j++)
           {
       printf("��Ŀ���ƣ� % s      �ɼ�: % d\n",student[i].course[j].coursename,student[i].course[j].coursescore);
       }
           printf("��ѧ�����п�Ŀ�ܷ�  % d \n",stuscore_sum[i]);
           printf("��ѧ�����п�Ŀƽ����  % .2f\n",stuscore_ave[i]);
       }

       }
           void input(STUDENT_S *student,int *Pnum_student,int *Pnum_course)
           {
           char **temp_course=NULL;//��̬��ά���� ��������ʱ������Щ��Ŀ��ֹһֱ�ظ�����
           int i,j;
           printf("������һ������ѧ��\n");
           while(scanf(" % d",Pnum_student)!=1)
           {   printf("�����������������\n");
           while(getchar()!='\n');
       }
           printf("��ȷ����һ���� % dѧ��\n",*Pnum_student);
           printf("*************\n");
           fflush(stdin);
           printf("������һ�����ٿ�Ŀ\n");
           while(scanf(" % d",Pnum_course)!=1)
           {   printf("�����������������\n");
           while(getchar()!='\n');
       }
           printf("��ȷ����һ���� % d��Ŀ\n",*Pnum_course);
           printf("*************\n");
           temp_course=(char **)malloc(sizeof(char*)*(*Pnum_course));
           for(i=0;i<*Pnum_course;i++)//��̬��ά����
           temp_course[i]=(char*)malloc(sizeof(char)*N);//��̬��ά����
           for(j=0;j<*Pnum_course;j++)//////////////
           {
           printf("������� % d�ſ��Կ�Ŀ����\n",j+1);
           fflush(stdin);
           gets(temp_course[j]);
           for(i=0;i<*Pnum_student;i++)
           strcpy(student[i].course[j].coursename,temp_course[j]);//for��ֵ���еĸÿγ���
           printf("*************\n");
       }
           free(temp_course) ;
           fflush(stdin);
           for(i=0;i<*Pnum_student;i++)
           {
           printf("������� % dλѧ��ѧ��\n",i+1);
           gets(student[i].num);
           printf("*************\n");
           printf("������� % dλѧ������\n",i+1);
           gets(student[i].name);
           printf("*************\n");
           printf("׼��������������Կ�Ŀ�ɼ�\n");
           for(j=0;j<*Pnum_course;j++)
           {
           printf("������� % d�� % s���Կ�Ŀ����\n",j+1,student[i].course[j].coursename);
           while(scanf(" % d",&student[i].course[j].coursescore)!=1)
           {   printf("�����������������\n");
           while(getchar()!='\n');
       }
           fflush(stdin);
           printf("*************\n");
       }
       }
       }
