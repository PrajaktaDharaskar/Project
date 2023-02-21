//Minor project on Records of cricket players//
#include<stdio.h>
#include<string.h>
typedef struct player
{   
    char country[10];
	int jersy_no;
	char name[20];
	int matches_played;
	int runs;
	int wickets;
	
}player;

void storevalue(player*,int);
void display(player*,int);
void max_runs(player*,int);
void max_wicket(player*,int);
void second_max_runs(player*,int);
void search(player*,int);
void Total_runs(player*,int);
void Avg_runs(player*,int);
void sort_player(player*,int);

void main()
{    
    int n,ch;
    printf("<----Records of cricket players---->");
    printf("\n\nHow many player you want to enter:");
    scanf("%d",&n);
    player p[n];
    
    storevalue(p,n);
    
    printf("\n-----Menu------");
    do{

    printf("\n1.display the information of player:");
    printf("\n2.maximum runs of player:");
    printf("\n3.second maximum runs player");
    printf("\n4.maximum wickets of player:");
    printf("\n5.player by jersy no:");
    printf("\n6.finding total runs of players:");
    printf("\n7.Avrage runs of team players:");
    printf("\n8.sorting the information of players by runs");
    printf("\n9.Exit");
    
    
    
    printf("\nEnter the choice:");
    scanf("%d",&ch);
    
    switch(ch)
    {
    		case 1:
    		display(p,n);
			break;
			case 2:
			max_runs(p,n);
			break;
			case 3:
			second_max_runs(p,n);
			break;	
			case 4:
			max_wicket(p,n);
			break;
			case 5:
			search(p,n);
			break;
			case 6:
			Total_runs(p,n);
			break;
			case 7:
			Avg_runs(p,n);	
			break;
			case 8:
			sort_player(p,n);
			break;
			case 9:
			printf("Exit of a program");
			break;	
			default:
			printf("Invalid choice");
			break;				
	}
     
     printf("\n\n");
   }while(1);
}

void storevalue(player*p,int n)
{   
   printf("\n---storing values---");
    int i;
    for(i=0;i<n;i++)
   {
   	printf("\nEnter the country of player:");
   	scanf("%s",&p[i].country);
   	printf("Enter the jersy no of player:");
	scanf("%d",&p[i].jersy_no);	
	printf("Enter the name of player:");
	scanf("%s",&p[i].name);
	printf("Enter the no of matches played by player:");
	scanf("%d",&p[i].matches_played);
	printf("Enter the runs of player:");
	scanf("%d",&p[i].runs);
	printf("Enter the wicket take by player:");
	scanf("%d",&p[i].wickets);
	
   }
}
void display(player*p,int n)
{   
   printf("\n---Displaying values---");
     int i;
     for(i=0;i<n;i++)
   {
   	printf("\ncountry of player is:%s",p[i].country);
   	printf("\njersy number  of player are:%d",p[i].jersy_no);
	printf("\nName of player is:%s",p[i].name);
	printf("\nMatches played by player are:%d",p[i].matches_played);
	printf("\nRuns made by player are:%d",p[i].runs);
	printf("\nWicket take by player are:%d",p[i].wickets);
   }
   printf("\n\n");
}

void max_runs(player*p,int n)
{
	printf("\n---finding maximum runs---");
	int i,r;
	int max=0;
	for(i=0;i<n;i++)
	{
		if(p[i].runs>max)
		{  
			max=p[i].runs;
			r=i;	
		}
	}
	printf("\nmaximum runs scored by player %s is %d",p[r].name,max);
}
void second_max_runs(player*p,int n)
{
	int i,max1,max2;
	max1=p[0].runs;
	for(i=0;i<n;i++)
	{
		if(p[i].runs>max1)
		{
			max2=max1;
			max1=p[i].runs; 
		}
	}
	if(p[i].runs > max2 && p[i].runs < max1)
	{
		max2=p[i].runs;
		
	}
	printf("\nsecond maximum runs are %d",max2);	
}
void max_wicket(player*p,int n)
{ 
   printf("\n---finding maximum wickets---");
   int i,r;
	int max=0;
	for(i=0;i<n;i++)
	{
		if(p[i].wickets>max)
		{
			max=p[i].wickets;
		    r=i;
		}
	}
	printf("\nmaximum wicket gain by player %s is %d",p[r].name,max);	
}
void search(player*p,int n)
{   
    printf("\n---searching player---");
	int i,flag=0;
	int search;
	printf("\nEnter the jersy number of player you want to search:");
	scanf("%d",&search);
	for(i=0;i<n;i++)
	{
		if(p[i].jersy_no==search)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		printf("\nplayer found %s having jersy number:%d\n having runs=%d\n taking wickets=%d\n matches played=%d",p[i].name,search,p[i].runs,p[i].wickets,p[i].matches_played);
	}
	else
	printf("\nplayer not found");	
}

void Total_runs(player*p,int n)
{   
    printf("\n---calculating total runs of players---");
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		sum+=p[i].runs;
	}	
	printf("\nTotal runs of team player are:%d",sum);
}
void Avg_runs(player*p,int n)
{
	printf("\n---Average runs of player---");
	int i;
	double sum=0;
	for(i=0;i<n;i++)
	{
		sum+=p[i].runs;
	}

	printf("\nAvrage run:%.2f",sum/n);
}
void sort_player(player*p,int n)
{
	int i,j;
    player temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<(n-1-i);j++)
		{
			if(p[j].runs>p[j+1].runs)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	printf("\ncricketer info in terms of runs scored from lowest to higest\n");
	printf("\nName\t\tWickets\t\tRuns\n");
	
	for(i=0;i<n;i++)
	{
		printf("%s\t\t%d\t\t%d\n",p[i].name,p[i].wickets,p[i].runs);
	}
	
}



