/*
This project is given by my course teacher. In this project, i was told to make a unversity management system of a department.
This project includes ADMIN PANNEL, TEACHER PANNEL and STUDENT PANNEL.

***In ADMIN PANNEL, admin should create teacher account and student account, update teacher account and student account
      and assign courses to teacher.
***In TEACHER PANNEL, teacher should provide ct marks to students, count them, and find the students. I have created all the
      functions by this given information.
***In STUDENT PANNEL, student is checking his or her ct marks. And so, i have created a function for this.

Therefore, this project includes all the information above.

Submitted by-
   Name: Farzana Rahman
   Roll: 1907028
   Course Name: Structured Programming Laboratory
   Course Code: CSE 1202
   Department: Computer Science and Engineering

*/


//admin username = "admin"
//admin password = "12345"


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void CREATE_STUDENT_ACCOUNT();
void CREATE_TEACHER_ACCOUNT();
void UPDATE_STUDENT_ACCOUNT();
void UPDATE_TEACHER_ACCOUNT();
void ASSIGN_COURSE();
void PROVIDE_CT_MARKS();
void COUNT_STUDENT();
void COUNT_BY_ACCOUNT();
void COUNT_BY_MARKS();
void FIND_STUDENT();
void CHECK_COURSES();
void CHECK_CT_MARKS();
void LOGIN();
void MAIN_MENU();
void A_LOGIN();
void S_LOGIN();
void T_LOGIN();

//these are all functions needed for this project

struct student
{
    char ns1[30];
    char ns2[30];
    int roll;
    char passs[30];
} s;

//this struct is for creating and updating student account

int sz_s=sizeof(s);

struct teacher
{
    char nt1[30];
    char nt2[30];
    int age;
    char passt[30];
} t;

int sz_t=sizeof(t);

//this struct is for creating and updating teacher account

struct assign_course
{
    char namt[30];
    char crs1[30];
    char crs2[30];
} cs;

int sz_cs=sizeof(cs);

//this struct is for assigning courses to teacher

struct ctmarks
{
    int stroll;
    char nams[30];
    char course1[30];
    int course1_mark;
    char course2[30];
    int course2_mark;
} ct;

int sz_ct=sizeof(ct);

//this struct is for providing ct marks to students

int main()
{
    printf("\n\n\t\t\t\t<<<------ WELCOME TO UNIVERSITY MANAGEMENT SYSTEM ------>>>\t\t\t\t\t\n\n");

    MAIN_MENU();

    return 0;
}

void MAIN_MENU()
{

    LOGIN();

}

void ADMIN_PANNEL()
{
    system("cls");

    //system("cls") - clears the screen

    printf("\n\n\n\t\t\t\t\t<<<<<< WElCOME TO ADMIN PANNEL >>>>>>\t\t\t\t\t\n\n\n");

    int a_choice,cnt=0;

    printf("\n\t\t\t What do you want to do?\n");

    printf("\n\t\t\t 0. Do you want to go main menu?\n\t\tPress '0'\n");

    printf("\n\t\t\t 1. Do you want to create a teacher account?\n\t\tPress '1'\n");

    printf("\n\t\t\t 2. Do you want to create a student account?\n\t\tPress '2'\n");

    printf("\n\t\t\t 3. Do you want to update a teacher account?\n\t\tPress '3'\n");

    printf("\n\t\t\t 4. Do you want to update a student account?\n\t\tPress '4'\n");

    printf("\n\t\t\t 5. Do you want to assign course to a teacher?\n\t\tPress '5'\n\n\n");


    scanf("%d",&a_choice);

    if(a_choice==0)
        MAIN_MENU();

    if(a_choice==1)
        CREATE_TEACHER_ACCOUNT();


    if(a_choice==2)
        CREATE_STUDENT_ACCOUNT();


    if(a_choice==3)
        UPDATE_TEACHER_ACCOUNT();

    if(a_choice==4)
        UPDATE_STUDENT_ACCOUNT();


    if(a_choice==5)
        ASSIGN_COURSE();

    //In this function, i am checking what admin wants to do

}

void A_LOGIN()
{
    system("cls");

    char us[30];
    int pass;

    printf("\n\t\t\t Enter Your Username- ");
    fflush(stdin);
    gets(us);

    printf("\n\t\t\t Enter Your Password- ");
    scanf("%d", &pass);

    if(strcmp(us,"admin") == 0 && pass == 12345)
    {

        ADMIN_PANNEL();

        //Here , i am checking if given pass and username match the admin's pass and username
        //if matches ,then it will call the admin pannel

    }
    else
    {
        printf("\n\t\t\t SORRY! INVALID PASSWORD OR USERNAME!!! \t\t\t\n");
        //if username or pass doesn't match,,,then it will show this message
    }

}

void CREATE_TEACHER_ACCOUNT()
{
    system("cls");

    FILE *fpt;
    fpt=fopen("teacheracc.dat","ab");

    //here 'ab' is used because it adds information at the end
    // and doesn't affect previous data
    //and .dat is used so that user can not read the file

    printf("\n\t\tEnter Teacher's First Name : ");
    fflush(stdin);
    gets(t.nt1);

    printf("\n\t\t Enter Teacher's Last Name : ");
    fflush(stdin);
    gets(t.nt2);

    printf("\n\t\t       Enter Teacher's Age : ");
    scanf("%d",&t.age);

    printf("\n\t\t   Enter Teacher's Password : ");
    fflush(stdin);
    gets(t.passt);


    fwrite(&t,sz_t,1,fpt);
    //here,i have written all the info
    fclose(fpt);
    //after written , i have closed it

    printf("\n\n\t\t\t:::::::::ACCOUNT HAS BEEN CREATED SUCCESFULLY:::::::::\n\n");

    MAIN_MENU();

    //this function is for creating teacher account
    //first i have opened a file and get the input from the user and write it to the file through a file pointer


}

void UPDATE_TEACHER_ACCOUNT()
{
    system("cls");

    FILE *fptt;

    char nt[30];
    int cntt=0;

    fptt=fopen("teacheracc.dat","rb+");
    //here, 'rb+' is used because the file pointer placed at the begining of the file
    //and it both reads and writes in the file

    printf("\n\t\t\t\tEnter Teacher's First Name to Update : ");
    fflush(stdin);
    gets(nt);

    while(fread(&t,sz_t,1,fptt)==1)
    {
        if(strcmp(nt,t.nt1)==0)
        {
            cntt=1;
            break;
            //here , i am comparing if the teacher exists or not
        }
    }
    if(cntt==1)
    {
        //i have found that teacher exists
        //so i am updating all the information

        printf("\n\t\t Enter New Information to Update---\n\n");

        printf("\n\n\t\t  Enter Teacher's First Name : ");
        fflush(stdin);
        gets(t.nt1);

        printf("\n\t\t   Enter Teacher's Last Name : ");
        fflush(stdin);
        gets(t.nt2);

        printf("\n\t\t         Enter Teacher's Age : ");
        scanf("%d",&t.age);

        printf("\n\t\tEnter Teacher's New Password : ");
        fflush(stdin);
        gets(t.passt);

        fseek(fptt,-sz_t,1);
        //fseek changes the position of the pointer
        fwrite(&t,sz_t,1,fptt);
        //here i have written into the file
        printf("\n\n\t\t\t------ACCOUNT HAS BEEN UPDATED SUCCESFULLY------\n\n");
        fclose(fptt);
        //also closed it


    }
    else
    {
        printf("\n\t\t\t\t\tSorry!!!!ACCOUNT NOT FOUND.......\n\n\n");
    }

    MAIN_MENU();

    //in this function,i am updating a teacher account
    //first i am checking if the input teacher name still exists or not
    //if it exists, then i am updating all its information as creating a new account

}

void CREATE_STUDENT_ACCOUNT()
{
    system("cls");

    FILE *fps;
    fps=fopen("studentacc.dat","ab");

    printf("\n\t\t Enter Student's First Name : ");
    fflush(stdin);
    gets(s.ns1);

    printf("\n\t\t  Enter Student's Last Name : ");
    fflush(stdin);
    gets(s.ns2);

    printf("\n\t\t       Enter Student's Roll : ");
    scanf("%d",&s.roll);

    printf("\n\t\t   Enter Student's Password : ");
    fflush(stdin);
    gets(s.passs);

    fwrite(&s,sz_s,1,fps);
    fclose(fps);

    printf("\n\n\t\t\t:::::::::ACCOUNT HAS BEEN CREATED SUCCESFULLY:::::::::\n\n");

    MAIN_MENU();

    //this function is for creating a student account
    //first i have opened a file and write the input information into it through a file pointer

}


void UPDATE_STUDENT_ACCOUNT()
{
    system("cls");

    FILE *fpss;

    char ns[30];
    int cnts=0;

    fpss=fopen("studentacc.dat","rb+");

    printf("\n\t\t\t\tEnter Student's First Name to Update : ");
    fflush(stdin);
    gets(ns);

    while(fread(&s,sz_s,1,fpss)==1)
    {
        if(strcmp(ns,s.ns1)==0)
        {
            cnts=1;
            break;
            //in this loop, i am checking that student exists or not
        }
    }

    if(cnts==1)
    {
        //found the student and updating the information
        printf("\n\t\t Enter New Information to Update---\n\n");

        printf("\n\t\t   Enter Student's First Name : ");
        fflush(stdin);
        gets(s.ns1);

        printf("\n\t\t    Enter Student's Last Name : ");
        fflush(stdin);
        gets(s.ns2);

        printf("\n\t\t     Enter Student's New Roll : ");
        scanf("%d",&s.roll);

        printf("\n\t\t Enter Student's New Password : ");
        fflush(stdin);
        gets(s.passs);

        fseek(fpss,-sz_s,1);
        fwrite(&s,sz_s,1,fpss);
        //written in the file
        fclose(fpss);
        //and closed it
        printf("\n\n\t\t\t------ACCOUNT HAS BEEN UPDATED SUCCESFULLY------\n\n");

    }
    else
    {
        printf("\n\t\t\t\t\tSorry!!!!ACCOUNT NOT FOUND.......\n\n\n");
    }

    MAIN_MENU();

    //in this function, i am updating a student account
    //first i am checking if the input student still exists or not
    //if exists ,then i am updating all the infos
    //if not,then i am showing the message that account not found

}


void ASSIGN_COURSE()
{
    system("cls");

    FILE *fpta;
    FILE *fpttt;

    char cs1[30],cs2[30],ntt[30];
    int cnttt=0;

    fpta=fopen("teacheracccs.dat","rb+");
    fpttt=fopen("teacheracc.dat","rb");

    //here fpttt points to the file only for reading
    //and fpta points both for reading and writing

    printf("\n\t\t\tEnter Teacher's First Name to Assign Course : ");
    fflush(stdin);
    gets(ntt);

    while(fread(&t,sz_t,1,fpttt)==1)
    {
        if(strcmp(ntt,t.nt1)==0)
        {
            cnttt=1;
            strcpy(cs.namt,t.nt1);
            break;
            //if input matches the teacher first name,then the teacher exists
        }
    }

    if(cnttt==1)
    {
        printf("\n\n\t\tTeacher's Name  : %s",cs.namt);
        printf("\n\n\n\t\tEnter First Course - ");
        fflush(stdin);
        gets(cs.crs1);

        printf("\n\n\t\tEnter Second Course - ");
        fflush(stdin);
        gets(cs.crs2);

        fwrite(&cs,sz_cs,1,fpta);
        //i have written the courses in the file
        printf("\n\t\t\t------ COURSES HAVE BEEN ASSIGNED SUCCESFULLY ------\n");
        fclose(fpta);
        fclose(fpttt);
        //closed the file
    }
    else
    {
        printf("\n\t\t\t\t\t SORRY!!!!ACCOUNT NOT FOUND..........\n");
    }

    MAIN_MENU();

    //in this function,, i am assigning courses to teacher
    //first i am checking if the exists or not
    //if exists then i am copying info from teacher struct to assign course struct
    //if copying info is completed ,then i am writing it to teacher account and closing all the files

}

void STUDENT_PANNEL()
{

    CHECK_CT_MARKS();
    //student pannel is for checking ct marks
}

void S_LOGIN()
{
    system("cls");

    FILE *fs;
    char nss[30],pas[30];
    int c=0;

    fs=fopen("studentacc.dat","rb");
    //i used rb because the file is being read only

    printf("\n\n\n\t\t        Enter Your First Name : ");
    fflush(stdin);
    gets(nss);

    printf("\n\n\n\t Enter Your Password (you must enter the pass given by the admin) : ");
    fflush(stdin);
    gets(pas);

    while(fread(&s,sz_s,1,fs)==1)
    {
        if(strcmp(nss,s.ns1)==0&&strcmp(pas,s.passs)==0)
        {
            c=1;
            break;
            //here, i am comparing
            //if account found,then student will be logged in
        }
    }
    fclose(fs);
    //closed the file

    if(c==1)
    {
        printf("\n\t\t\t\t------You are LOGGED IN------\n");
        printf("\n\n\t\t\t\t<<<------WELCOME TO STUDENT PANNEL------>>>\n");

        STUDENT_PANNEL();
    }
    else
    {
        printf("\n\t\t\t------- SORRY! INVALID PASSWORD OR USERNAME!!! -------\t\t\t\n");
    }

    //this function is for student login
    //first i am checking the username and pass
    //if it matches to the info given by the admin,,then the student will be logged in
    //otherwise it will show invalid name or password

}

void TEACHER_PANNEL()
{
    int t_choice;
    printf("\n\n\n\t\t\tWhat do you want to do???");

    printf("\n\n\t\t1. Do you want to provide CT marks?\n\tPress '1'\n");
    printf("\n\n\t\t2. Do you want to find student by first name?\n\tPress '2'\n");
    printf("\n\n\t\t3. Do you want to count students?\n\tPress '3'\n");
    printf("\n\n\t\t4. Do you want to see your assigned course?\n\tPress '4'\n");
    printf("\n\n\t\t0. Do you want to go to main menu?\n\tPress '0'\n");

    scanf("%d",&t_choice);

    if(t_choice==1)
    {
        PROVIDE_CT_MARKS();
    }
    if(t_choice==2)
    {
        FIND_STUDENT();
    }
    if(t_choice==3)
    {
        COUNT_STUDENT();
    }
    if(t_choice==4)
    {
        CHECK_COURSES();
    }
    if(t_choice==0)
    {
        MAIN_MENU();
    }

    //this function is for what teacher wants to do

}
void T_LOGIN()
{
    system("cls");

    FILE *ft1;

    char ntt[30],past[30];
    int cntl=0;

    ft1=fopen("teacheracc.dat","rb");

    printf("\n\n\n\t\t        Enter Your First Name : ");
    fflush(stdin);
    gets(ntt);

    printf("\n\n\n\t Enter Your Password (you must enter the pass given by the admin) : ");
    fflush(stdin);
    gets(past);

    while(fread(&t,sz_t,1,ft1)==1)
    {
        if(strcmp(ntt,t.nt1)==0&&strcmp(past,t.passt)==0)
        {
            cntl=1;
            break;
            //checking that teacher account exists or not
        }
    }

    fclose(ft1);
    //closed the file

    if(cntl==1)
    {
        printf("\n\t\t\t\t------You are LOGGED IN------\n");
        printf("\n\n\t\t\t\t<<<------WELCOME TO TEACHER PANNEL------>>>\n\n");

        TEACHER_PANNEL();
    }
    else
    {
        printf("\n\t\t\t----- SORRY! INVALID PASSWORD OR USERNAME!!! -----\t\t\t\n");
        exit(0);
    }
    //this function is for teacher loggin
    //if the given input matches the info given by the admin ,,then the teacher will be logged in
    //else it will show invalid username or pass

}


void PROVIDE_CT_MARKS()
{
    system("cls");

    int rl,cntr=0;
    char cs1[30],cs2[30];
    int c1_mark,c2_mark;

    FILE *fpct;
    FILE *fpss;

    fpct=fopen("studentaccct.dat","ab");
    fpss=fopen("studentacc.dat","rb");

    //fpct points to the studentaccct file which includes ctmarks struct in ab mode
    //fpss points to the studentacc file which includes student struct in rb mode

    printf("\n\n\t\t\tEnter Student's Roll to Provide CT Marks : ");
    scanf("%d",&rl);

    while(fread(&s,sz_s,1,fpss)==1)
    {
        if(rl==s.roll)
        {
            cntr=1;
            // i am checking account exists or not
            strcpy(ct.nams,s.ns1);
            ct.stroll=s.roll;
            //here i am copying the student info to ctmarks struct for showing the data
            break;
        }
    }

    if(cntr==1)
    {
        //found the account
        printf("\n\n\t\t\t          Student's Name : %s",ct.nams);
        printf("\n\n\t\t\t          Student's Roll : %d",ct.stroll);
        printf("\n\n\t\t\t  Enter First Course Name: ");
        fflush(stdin);
        gets(cs1);
        strcpy(ct.course1,cs1);

        printf("\n\n\t\t\t Enter First Course Mark : ");
        scanf("%d",&c1_mark);
        ct.course1_mark=c1_mark;

        printf("\n\n\t\t\tEnter Second Course Name : ");
        fflush(stdin);
        gets(cs2);
        strcpy(ct.course2,cs2);

        printf("\n\n\t\t\tEnter Second Course Mark : ");
        scanf("%d",&c2_mark);
        ct.course2_mark=c2_mark;
        fwrite(&ct,sz_ct,1,fpct);
        //write to the studentaccct file
        printf("\n\n\n\t\t\t\t\tMARKS HAVE BEEN ASSIGNED SUCCESFULLY......\n\n");
        fclose(fpct);
        fclose(fpss);
        //closed the file

    }
    else
    {
        printf("\n\n\n\t\t\t\t\tSORRY!!!!ACCOUNT NOT FOUND......\n");
    }

    MAIN_MENU();

    //this fuction is for providing ct marks to student
    //first i am checking that the student exists or not by the input roll
    //if exists,, then i am copying student name and roll to ct marks struct
    //then i am taking course name and marks from teacher and write it to the file

}

void FIND_STUDENT()
{
    FILE *ffs;
    FILE *frs;
    char sn[30];
    int ctf=0,ctff=0;

    printf("\n\t\t\tEnter Student's First Name to Search : ");
    fflush(stdin);
    gets(sn);

    ffs=fopen("studentacc.dat","rb");
    frs=fopen("studentaccct.dat","rb");

    //ffs points to the studentacc file containing student structure
    //and frs points to the studentaccct file containing ctmarks structure

    while(fread(&s,sz_s,1,ffs)==1)
    {
        if(strcmp(sn,s.ns1)==0)
        {
            ctf=1;
            strcpy(ct.nams,s.ns1);
            break;
            //checking that account exists or not
        }
    }
    while(fread(&ct,sz_ct,1,frs)==1)
    {
        if(strcmp(sn,ct.nams)==0)
        {
            ctff=1;
            break;
            //here i am checking that marks have been provided or not
        }
    }
    if(ctf==1&&ctff==1)
    {
        //account found & marks have been provided
        //so i am showing the information

        printf("\n\n\t\t               Student's Name: %s",ct.nams);
        printf("\n\n\t\t               Student's Roll: %d",ct.stroll);
        printf("\n\n\t\t Student's First Course Name : %s",ct.course1);
        printf("\n\n\t\t Student's First Course Mark : %d",ct.course1_mark);
        printf("\n\n\t\tStudent's Second Course Name : %s",ct.course2);
        printf("\n\n\t\tStudent's Second Course Mark : %d",ct.course2_mark);
        fclose(ffs);
        fclose(frs);
        //closed the file

    }
    else if(ctf==1&&ctff==0)
    {
        printf("\n\n\t\t\t\t\tACCOUNT HAS BEEN FOUND BUT MARKS HAVE NOT BEEN PROVIDED YET!!!!!\n");
    }
    else
    {
        printf("\n\n\t\t\t\t\tSORRY!!!ACCOUNT NOT FOUND......\n");
        exit(0);
    }
    MAIN_MENU();

    //in this function, i am searching the student by its first name to check student exists or not
    //if exixts, then i am showing students info from ct marks struct

}

void COUNT_STUDENT()
{
    system("cls");

    int in;
    printf("\n\t\t1. Do you want to count student whose marks are assigned?");
    printf("\n\n\tThen press '1'-> ");
    printf("\n\n\t\t2. Do you want to count total students?");
    printf("\n\n\tThen press '2'->\n\n\n ");
    scanf("%d",&in);
    if(in==1)
    {
        COUNT_BY_MARKS();
    }
    if(in==2)
    {
        COUNT_BY_ACCOUNT();
    }

    //this function is for counting student
}

void COUNT_BY_MARKS()
{
    FILE *fcms;
    fcms=fopen("studentaccct.dat","rb");
    //count the students whose marks are assigned

    int count=0;
    while(fread(&ct,sz_ct,1,fcms)==1)
    {
        count++;
        //increasing count by reading each record
    }
    fclose(fcms);
    //closed the file

    printf("\n\n\t\tTHE NUMBER OF STUDENTS WHOSE MARKS ARE ASSIGNED IS = %d\n",count);

    //this function shows number of students whose marks are assigned that's why i am reading the info from ctmarks struct
}

void COUNT_BY_ACCOUNT()
{
    FILE *fcsa;
    fcsa=fopen("studentacc.dat","rb");
    int count=0;
    while(fread(&s,sz_s,1,fcsa)==1)
    {
        count++;
    }
    fclose(fcsa);
    printf("\n\n\t\tTOTAL STUDENTS = %d\n",count);

    //this function will count the total students
    //that's why i am reading the info from student struct
}


void CHECK_CT_MARKS()
{
    FILE *fccc;
    int rrll,cmt=0;
    char nn[30];

    printf("\n\n\t\t\tEnter Your Roll and Name to Check CT Marks : ");
    printf("\n\n\t\tEnter your roll : ");
    scanf("%d",&rrll);
    printf("\n\n\t\tEnter your name : ");
    fflush(stdin);
    gets(nn);
    fccc=fopen("studentaccct.dat","rb");

    while(fread(&ct,sz_ct,1,fccc)==1)
    {
        if(rrll==ct.stroll&&strcmp(nn,ct.nams)==0)
        {
            cmt=1;
            break;
            //found that marks have been assigned
        }
    }
    if(cmt==1)
    {
        //showing results
        printf("\n\n\t\t\t              Your Name : %s",ct.nams);
        printf("\n\n\t\t\t      Your First Course : %s",ct.course1);
        printf("\n\n\t\t\t Your First Course Mark : %d",ct.course1_mark);
        printf("\n\n\t\t\t     Your Second Course : %s",ct.course2);
        printf("\n\n\t\t\tYour Second Course Mark : %d\n",ct.course2_mark);
        fclose(fccc);
        //closed the file
    }
    else
    {
        printf("\n\n\t\t\t\t\tMARKS HAVE NOT BEEN PROVIDED YET......\n\n");
    }

    MAIN_MENU();

    //this function is for checking ct marks
    //if the student exists, then it will to the info from ctmarks struct

}

void CHECK_COURSES()
{
    system("cls");

    int cmtt=0;
    char nnt[30];

    FILE *ftc,*ftcc;
    ftc=fopen("teacheracc.dat","rb");
    ftcc=fopen("teacheracccs.dat","ab");

    //ftc points to the teacheracc file containg teacher struct
    //ftcc points to the teacheracccs file containing assign courses struct

    printf("\n\n\t\t\tEnter Your First Name to Check Your Courses : ");
    fflush(stdin);
    gets(nnt);

    while(fread(&t,sz_t,1,ftc)==1)
    {
        if(strcmp(nnt,t.nt1)==0)
        {
            cmtt=1;
            strcpy(cs.namt,t.nt1);
            //account exists and copying the name into assign course struct to show the results
            break;
        }
    }
    if(cmtt==1)
    {
        printf("\n\n\t\tYour Name : %s",cs.namt);
        printf("\n\n\t\tYour First Course : %s",cs.crs1);
        printf("\n\n\t\tYour Second Course : %s\n\n\n",cs.crs2);
        fclose(ftc);
        fclose(ftcc);
        //closed the files
    }
    else
    {
        printf("\n\n\t\t\t\tCOURSES HAVE NOT BEEN ASSIGNED YET........");
    }
}

void LOGIN()
{
    int l;

    printf("\n\n\t\t\t  1. Do you want to log in as an ADMIN?\n\t\t Press '1'\n");
    printf("\n\n\t\t\t  2. Do you want to log in as a TEACHER?\n\t\t Press '2'\n");
    printf("\n\n\t\t\t  3. Do you want to log in as a STUDENT?\n\t\t Press '3'\n");
    printf("\n\n\t\t\t  0. Exit\n\t\t Press '0'\n");

    scanf("%d",&l);

    if(l==1)
    {
        A_LOGIN();
    }
    if(l==2)
    {
        T_LOGIN();
    }
    if(l==3)
    {
        S_LOGIN();
    }
    if(l==0)
    {
        exit(0);
    }

    //this function is only for loggin admin, student and teacher
}

