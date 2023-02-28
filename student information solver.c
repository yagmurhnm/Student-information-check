
#include<stdio.h>
#include<stdlib.h>
int functionA(int n,int stuID[]);//year
int functionB(int n,int stuID[]);//department
int main()
{
	int num=0,i;
	printf("How many students you want to enter: ");
	scanf("%d",&num);//size of array
	int stuID[num];
	for(i=0;i<num;i++)
	{
		printf("Enter %d. student id: ",i+1);
		scanf("%d",&stuID[i]);
	}
	
	int menu;
	printf("List Students \n");
	printf("	1. Entrance Year \n");
	printf("	2. Department \n");
	printf("Enter your choice: ");
	scanf("%d",&menu);//choice for 1 or 2
	
	if(menu==1)
	{
		functionA(num,stuID);//entrance year
	}
	else if(menu==2)
	{
		functionB(num,stuID);//department 
	}
	else
	{
		printf("You entered wrong option.");//error message
	}
}

int functionA(int n,int stuID[])//stuID original array 
{
	int year,yearArr[n],i;//yearArr newly formed array & n is size
	printf("Choose the entrance year between (2018-2020):");
	scanf("%d",&year);//year user choice
	int y;
	y=year%100;//ex:2020 to 20 
	int x;
	printf("The students with entrance year %d: \n",year);
	
	for(i=0;i<n;i++){
		
		x=stuID[i]/10000000;//ex:200300011 to 20
		if(x==y)//�f year last 2 digit and id first 2 digit equal 
		{
			yearArr[i]=stuID[i];//put this id to yearArr array(newly formed)
			printf("%d \n",yearArr[i]);
		}//if not equal do not do anything just past to next one
		
	}
}

int functionB(int n,int stuID[])//stuID->original array
{
	int dept,deptArr[n],i;//deptArr->newly array & n is size
	int a,b;//for calculating...
	printf("Choose a department, enter 0 for CMPE, 1 for SE and 2 for ISE:");
	scanf("%d",&dept);//department user choice
	printf("The students in this department:\n");
	if(dept==0)//cmpe
	{
		dept=300;//in id 300 for cmpe
	}
	else if(dept==1)//se
	{
		dept=301;//in id 301 for se
	}
	else if(dept==2)//ise
	{
		dept=302;//in id 302 for ise
	}
	else
	{
		printf("You entered wrong option.");//error message
	}
	
	for(i=0;i<n;i++)
	{
		a=stuID[i]/1000;//stuID->200300011 becomes a->200300
		b=a%1000;//a->200300 becomes b->300 to understand department
		if(b==dept)//id number's department =? dept user want
		{	
			deptArr[i]=stuID[i];//if equal put that id to deptArr(newly array)
			printf("%d \n",deptArr[i]);
		}//if not do not do anything just pass to next one
	}

}
