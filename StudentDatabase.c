#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//functions used in this programs header file
void WriteData(char *filename);
void ReadData(char *filename);
void Grade(float per);
void GetFullDetails(char *filename);
int foundStudent(char *filename, char s[],char f[], char m[]);
void GetOneStudentData(char *filename , char s[], char f[], char m[]);
void DeleteData(char *filename, char s[], char f[], char m[]);
int TotalStudent(char *filename);
void ModifyStudent(char *filename);
void SetColour(int ForgC);
void ClearConsoleToColors(int ForgC, int BackC);

struct Sname {

	char sname[20];
	//char lname[20];
	char fname[20];
	char mname[20];
};

struct Date {

	int dd;
	int mm;
	int yy;
};

struct Adress {

	char taddress[50];
	char padress[50];
};

struct Student {

	int marks[5];
	struct Sname name;
	struct Date dob;
	struct Adress adr;
	int roll_num;
};

typedef struct Student Student;

//main function
int main()
{
	char s[20],f[20],m[20];
	int choice,pos;
	int r = 10;
	ClearConsoleToColors(15,6);
	SetConsoleTitle("Program is developed by Raju Raghuwanhsi");

	while(1)
	{
	    fflush(stdin);
	    printf("\n\t========================Student DataBase========================\n");
	    printf("\n1. for Add Record in DataBase !\n");
	    printf("\n2. for Display all Records in DataBase !\n");
	    printf("\n3. for Display all Records in DataBase in Details !\n");
	    printf("\n4. for Display the Records of n-th Student !\n");
	    printf("\n5. for Delete the Records in DataBase !\n");
	    printf("\n6. for Search Student in DataBase !\n");
	    printf("\n7. for Total number of Student in DataBase !\n");
	    printf("\n8. for Modify Records in data base !\n");
	    printf("\n9. for exit !\n");

		printf("\nEnter your choice :");
		scanf("%d",&choice);
		fflush(stdin);

		switch(choice)
		{
		    case 1:
				system("cls");
                WriteData("StudentDataBase.txt");
				break;

			case 2:
				system("cls");
				ReadData("StudentDataBase.txt");
				break;

            case 3:
				system("cls");
                GetFullDetails("StudentDataBase.txt");
                break;

            case 4:
				system("cls");
				printf("\nDisplay the Records of nth Student !\n");

				fflush(stdin);
                printf("\nEnter student name :");
                gets(s);

				fflush(stdin);
                printf("\nEnter student father name :");
                gets(f);

                fflush(stdin);
                printf("\nEnter student mother name :");
                gets(m);

				GetOneStudentData("StudentDataBase.txt",s,f,m);
                break;

			case 5:
                system("cls");
				printf("\nfor Delete the Reacords in DataBase !\n");

				fflush(stdin);
                printf("\nEnter student name :");
                gets(s);

				fflush(stdin);
                printf("\nEnter student father name :");
                gets(f);

                fflush(stdin);
                printf("\nEnter student mother name :");
                gets(m);

                DeleteData("StudentDataBase.txt",s,f,m);
                break;

			case 6:
				system("cls");
				printf("\nfor search student in DataBase is present or not !\n");

				fflush(stdin);
                printf("\nEnter student name :");
                gets(s);

				fflush(stdin);
                printf("\nEnter student father name :");
                gets(f);

                fflush(stdin);
                printf("\nEnter student mother name :");
                gets(m);

				pos =  foundStudent("StudentDataBase.txt",s,f,m);
                if(pos > 0)
				{
					printf("\nRecord found in DataBase !\n");
                    printf("\nAnd Student S.no. is : %d\n",pos);
				}

				else
					printf("\nRecord not present in the DataBase !\n\n");
				break;

			case 7:
				printf("\nfor total number of student\n");
				pos = TotalStudent("StudentDataBase.txt");
				printf("\nTotal number of students available in DataBase is : %d\n\n",pos);
				break;
            case 8:
                system("cls");
				printf("\nfor Modify the Reacords in DataBase !\n");

                ModifyStudent("StudentDataBase.txt");
			    break;

			case 9:
				system("cls");
				exit(1);
		}
    	system("pause");
		system("cls");
        SetColour(rand()%1000);
        fflush(stdin);
	}
}

//function body start
//Write function body

void WriteData(char *filename)
{
	FILE *fps;
    Student *sp;
    char choice = 'Y';
	int i;

	fps = fopen(filename,"a");
	if(fps == NULL)
	{
		printf("\nFile not open !");
		exit(1);
	}

	sp = (Student *)malloc(sizeof(Student));
	if(sp == NULL)
	{
		printf("\nMemory not allocated !");
		exit(1);
	}

	while(toupper(choice) == 'Y')
	{
		fflush(stdin);
		printf("\nEnter Student name :");
		gets(sp->name.sname);
        fflush(stdin);

		printf("\nEnter Student Roll_number : ");
        scanf("%d",&sp->roll_num);
        fflush(stdin);

		printf("\nEnter Student father name :");
		gets(sp->name.fname);
		fflush(stdin);

		printf("\nEnter Student mother name :");
		gets(sp->name.mname);
        fflush(stdin);

		printf("\nEnter date of birth in dd/mm/yy :");
		scanf("%d %d %d",&sp->dob.dd,&sp->dob.mm,&sp->dob.yy);
        fflush(stdin);

		printf("\nPlease Enter Student marks :\n");
		for(i=0; i<5; i++)
		{
			switch(i)
			{
			    case 0:
					printf("\nEnter marks in Mathmatics :");
					scanf("%d",&sp->marks[i]);
                    break;

			    case 1:
					printf("\nEnter marks in Physics :");
					scanf("%d",&sp->marks[i]);
					break;

			    case 2:
					printf("\nEnter marks in Chemistry :");
					scanf("%d",&sp->marks[i]);
					break;

			    case 3:
					printf("\nEnter marks in English :");
					scanf("%d",&sp->marks[i]);
					break;

			    case 4:
					printf("\nEnter marks in Hindi :");
					scanf("%d",&sp->marks[i]);
					break;
			}
		}
		fflush(stdin);

		printf("\nEnter Student Temporary Address :");
		gets(sp->adr.taddress);
		fflush(stdin);

		printf("\nEnter Student permanent Address :");
		gets(sp->adr.padress);
		fflush(stdin);

		fwrite(sp,sizeof(Student),1,fps);
		fflush(stdin);

		printf("\nDo you want to enter another student data :y/n :");
		scanf("%c",&choice);
		printf("\nData is Sucessfully added in DataBase !\n\n");
	}

	fclose(fps);
	free(sp);
}

//Read function body
void ReadData(char *filename)
{
	FILE *fps;
	Student *sp;
	int i = 1;

	sp = (Student *)malloc(sizeof(Student));
	if(sp == NULL)
	{
		printf("\nMemory not allocated !");
		exit(1);
	}

	fps = fopen(filename,"r");
	if(fps == NULL)
	{
		printf("\nFile not open !");
		exit(1);
	}

	fflush(stdin);
    rewind(fps);  //this fuction places the pointer to the begnning of the file
	while((fread(sp,sizeof(Student),1,fps))==1)
	{
		printf("\n\nStudent serial number is -->>%d\n",i);
		printf("\nStudent Roll_Number : %d\n",sp->roll_num);
		printf("\nStudent name :%s\n",sp->name.sname);
    	printf("\nStudent father name :%s\n",sp->name.fname);
		i++;
	}
	printf("\n");
    fclose(fps);
    free(sp);
}

//function return grade
void Grade(float per)
{
	if(85<=per && per <=100)
	    printf("A+");

	else if(70<=per && per <85)
		printf("A");

	else if(60<=per && per <70)
	    printf("B+");

	else if(50<= per && per <60)
		printf("B");

	else if(45<=per && per <50)
		printf("C");
}

//function for get all details
void GetFullDetails(char *filename)
{
	FILE *fps;
	Student *sp;
	int sum = 0;
	float per;
	int i = 1;

	sp = (Student *)malloc(sizeof(Student));
	if(sp == NULL)
	{
		printf("\nMemory not allocated !");
		exit(1);
	}

	fps = fopen(filename,"r");
	if(fps == NULL)
	{
		printf("\nFile not open !");
		exit(1);
	}

    fflush(stdin);
    rewind(fps);  //this fuction places the pointer to the begnning of the file
	while((fread(sp,sizeof(Student),1,fps))==1)
	{
		printf("\n\nStudent Serial number -->>%d\n",i);
		printf("\nStudent Roll_Number is : %d\n",sp->roll_num);
		printf("\nStudent name :%s\n",sp->name.sname);
		printf("\nStudent father name :%s\n",sp->name.fname);
		printf("\nStudent Mother name :%s\n",sp->name.mname);
		printf("\nData of birth in dd/mm/yy :%d %d %d\n",sp->dob.dd,sp->dob.mm,sp->dob.yy);
		printf("\nStudent Temporary Address :%s\n",sp->adr.taddress);
		printf("\nStudent Permanent Address :%s\n",sp->adr.padress);
		printf("\nStudent Marks :");
		printf("\n.............................................");
		printf("\nS.No.   Subjects                 Marks");
	    printf("\n.............................................");
		printf("\n 1      MathMatics            %d",sp->marks[0]);
		printf("\n 2      Physics               %d",sp->marks[1]);
		printf("\n 3      Chemistry             %d",sp->marks[2]);
		printf("\n 4      English               %d",sp->marks[3]);
		printf("\n 5      Hindi                 %d",sp->marks[4]);
		printf("\n.............................................");
		sum = sp->marks[0]+sp->marks[1]+sp->marks[2]+sp->marks[3]+sp->marks[4];
		printf("\nTotal is :                    %d",sum);
		per = (float)sum/5;
		printf("\npercentage is:                %.2f",(float)sum/5);
        printf("\n.............................................");
		printf("\nGrade is :                    ");
		Grade(per);
		printf("\n.............................................\n");
		i++;
	}
	printf("\n");
	fclose(fps);
	free(sp);
}

//function to chek student found or not
int foundStudent(char *filename, char s[],char f[], char m[])
{
	FILE *fps;
	Student *sp;
	int i=0;

	sp = (Student *)malloc(sizeof(Student));
	if(sp == NULL)
	{
		printf("\nMemory not allocated !");
		exit(1);
	}

	fps = fopen(filename,"r");
	if(fps == NULL)
	{
		printf("\nUnable to file open !");
		exit(1);
	}

	rewind(fps);
	while(fread(sp,sizeof(Student),1,fps)==1)
	{
		i++;
		if(strcmp(sp->name.sname,s)==0)
		{
			if(strcmp(sp->name.fname,f)==0)
			{
				if(strcmp(sp->name.mname,m)==0)
				{
					fclose(fps);
					return (i);
				}
			}
		}
	}

	fclose(fps);
	free(sp);
	return 0;
}

//display only one student data
void GetOneStudentData(char *filename , char s[], char f[], char m[])
{
	FILE *fps;
	Student *sp;
    int n;
	int sum = 0;
	float per;

	sp = (Student *)malloc(sizeof(Student));
	if(sp == NULL)
	{
		printf("\nMemory not allocated !");
		exit(1);
	}

	fps = fopen(filename,"r");
	if(fps == NULL)
	{
		printf("\nUnable to file open !");
		exit(1);
	}

	if(foundStudent(filename,s,f,m) == 0)
		printf("\nRecord not found in the Database !\n\n");

	else
	{
		n = foundStudent(filename,s,f,m);
		fseek(fps, (n-1)*sizeof(Student), SEEK_SET);
		fread(sp,sizeof(Student),1,fps);

		printf("\n\nStudent Serial number is-->> %d\n",n);
		printf("\nStudent Roll_Number is : %d\n",sp->roll_num);
		printf("\nStudent name :%s\n",sp->name.sname);
		printf("\nStudent father name :%s\n",sp->name.fname);
		printf("\nStudent Mother name :%s\n",sp->name.mname);
		printf("\nData of birth in dd/mm/yy :%d %d %d\n",sp->dob.dd,sp->dob.mm,sp->dob.yy);
		printf("\nStudent Temporary Address :%s\n",sp->adr.taddress);
		printf("\nStudent Permanent Address :%s\n",sp->adr.padress);
		printf("\nStudent Marks :");
		printf("\n.............................................");
		printf("\nS.No.   Subjects                 Marks");
	    printf("\n.............................................");
		printf("\n 1      MathMatics            %d",sp->marks[0]);
		printf("\n 2      Physics               %d",sp->marks[1]);
		printf("\n 3      Chemistry             %d",sp->marks[2]);
		printf("\n 4      English               %d",sp->marks[3]);
		printf("\n 5      Hindi                 %d",sp->marks[4]);
		printf("\n.............................................");
		sum = sp->marks[0]+sp->marks[1]+sp->marks[2]+sp->marks[3]+sp->marks[4];
		printf("\nTotal is :                    %d",sum);
		per = (float)sum/5;
		printf("\npercentage is:                %.2f",(float)sum/5);
        printf("\n.............................................");
		printf("\nGrade is :                    ");
		Grade(per);
		printf("\n.............................................\n");
}
	fclose(fps);
	free(sp);
}

//function delete student data

void DeleteData(char *filename, char s[], char f[], char m[])
{
	FILE *fps,*fpt;
	Student *sp;
	int n;

	n = 1;
	if(foundStudent(filename,s,f,m) > 0)
	{
        sp = (Student *)malloc(sizeof(Student));
	    if(sp == NULL)
		{
		    printf("\nMemory is not allocated !");
		    exit(1);
		}

	    fps = fopen(filename, "r+");
	    if(fps == NULL)
		{
	        printf("\nUnable to file open !");
		    exit(1);
		}

	    fpt = fopen("Temp.txt", "w");
		if(fpt == NULL)
		{
			printf("\nUnable to file open !");
			fclose(fps);
			exit(1);
		}

		fflush(stdin);
		rewind(fps);
	//	fseek(fps, (n-1)*sizeof(Student),SEEK_SET);
		while(fread(sp, sizeof(Student),1,fps)==1)
		{
			if(n != foundStudent(filename,s,f,m))

			    fwrite(sp,sizeof(Student),1,fpt);
			n++;
		}
		fclose(fps);
		fclose(fpt);
        free(sp);

		remove("StudentDataBase.txt");
		rename("Temp.txt","StudentDataBase.txt");
		printf("\nData is Deleted Successfully !\n");
	}

	else
		printf("\nRecord not available in DataBase !\n\n");
}

//count total number of student
int TotalStudent(char *filename)
{
	Student *sp;
	FILE *fps;
    int count = 0;

	sp = (Student *)malloc(sizeof(Student));
	if(sp == NULL)
	{
		printf("\nMemory not allocated !");
		exit(1);
	}

	fps = fopen(filename,"r");
	if(fps == NULL)
	{
		printf("\nUnable to open file !");
		exit(1);
	}
	rewind(fps);

	while(fread(sp,sizeof(Student),1,fps) == 1)
		++count;

	return (count);
}

//function for modify records
void ModifyStudent(char *filename)
{
	char choice;
	int i;
	Student *sp;
	FILE *fps;
	int n;
    char s[20],f[20],m[20];

	sp = (Student *)malloc(sizeof(Student));
	if(sp == NULL)
	{
		printf("\nMemory not allocated !");
		exit(1);
	}

	do {
        fflush(stdin);
        printf("\nEnter student name :");
        gets(s);

        fflush(stdin);
        printf("\nEnter student father name :");
        gets(f);

        fflush(stdin);
        printf("\nEnter student mother name :");
        gets(m);
		fps = fopen(filename,"r+");
		if(fps == NULL)
		{
			printf("\nUnable to open file !");
			exit(1);
		}
		rewind(fps);

		if(foundStudent(filename,s,f,m)> 0)
		{
     	    fflush(stdin);
	  	    printf("\nEnter Student name :");
		    gets(sp->name.sname);
            fflush(stdin);

	    	printf("\nEnter Student Roll_number : ");
            scanf("%d",&sp->roll_num);
            fflush(stdin);

		    printf("\nEnter Student father name :");
		    gets(sp->name.fname);
		    fflush(stdin);

		    printf("\nEnter Student mother name :");
		    gets(sp->name.mname);
            fflush(stdin);

		    printf("\nEnter date of birth in dd/mm/yy :");
		    scanf("%d %d %d",&sp->dob.dd,&sp->dob.mm,&sp->dob.yy);
            fflush(stdin);

		    printf("\nPlease Enter Student marks :\n");
		    for(i=0; i<5; i++)
			{
			    switch(i)
				{
			        case 0:
					    printf("\nEnter marks in Mathmatics :");
					    scanf("%d",&sp->marks[i]);
                        break;

			        case 1:
					    printf("\nEnter marks in Physics :");
					    scanf("%d",&sp->marks[i]);
					    break;

			        case 2:
					    printf("\nEnter marks in Chemistry :");
					    scanf("%d",&sp->marks[i]);
					    break;

			        case 3:
					    printf("\nEnter marks in English :");
					    scanf("%d",&sp->marks[i]);
					    break;

			        case 4:
					    printf("\nEnter marks in Hindi :");
					    scanf("%d",&sp->marks[i]);
					    break;
				}
			}
		    fflush(stdin);

		   printf("\nEnter Student Temporary Address :");
		   gets(sp->adr.taddress);
		   fflush(stdin);

		   printf("\nEnter Student permanent Address :");
		   gets(sp->adr.padress);
		   fflush(stdin);

		fseek(fps,-(sizeof(Student)),SEEK_CUR);
	    fflush(stdin);
	    fwrite(sp,sizeof(Student),1,fps);
	    fflush(stdin);
	    fflush(stdin);
	}
		else
			printf("\nNo record found in DataBase !\n");

		printf("\nDo you want to modofy another records y/n :");
		scanf("%c",&choice);
		fflush(stdin);
   }while(toupper(choice) == 'Y');

   fclose(fps);
}
//function for set text colour
void SetColour(int ForgC)
{
     WORD wColor;
     ///We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     ///We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        ///Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

//funciton for cahnge the background colour
void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     //Get the handle to the current output buffer...
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     //This is used to reset the carat/cursor to the top left.
     COORD coord = {0, 0};
     //A return value... indicating how many chars were written
     //   not used but we need to capture this since it will be
     //   written anyway (passing NULL causes an access violation).
     DWORD count;

     //This is a structure containing all of the console info
     // it is used here to find the size of the console.
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //Here we will set the current color
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //This fills the buffer with a given character (in this case 32=space).
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          //This will set our cursor position for the next print statement.
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}

