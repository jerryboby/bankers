#include<stdio.h>
#include<stdlib.h>
int need[5][3];
int finish[5],order[5],n,m,work[3],eligible[5],flag,check=0;
int n=5,m=3;
int allocate[5][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
int max[5][3]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
int available[3]={3,3,2};
int p[5]={0,1,2,3,4};

int safety(int available[],int allocate[][3])
{
int i,j,y,flag,k=0;
int np=0;
for(i=0;i<n;i++)
{work[i]=available[i];
finish[i]=0;
}


for(y=0;y<n;y++)
{
	for(i=0;i<n;i++)
	{
		if(finish[i]==0)
		{
		flag=0;
			for(j=0;j<m;j++)
			{
			if(need[i][j]>work[j])
			flag=1;
			}

				if(flag==0)
				{
					for(j=0;j<m;j++)
					work[j]=work[j]+allocate[i][j];
				finish[i]=1;
				order[k]=i; //order of execution
				k++;
				np++;
				}


		}
	}

if(np==4)
return 1;

}

}

void res_request(int pid)
{
	int reqmat[3];
	int i;
	printf("\n Enter additional request :- \n");
	for(i=0;i<m;i++){
		scanf("%d",&reqmat[i]);
	}
	
	for(i=0;i<m;i++)
		if(reqmat[i] > need[pid][i]){
			printf("\n Error encountered.\n");
			exit(0);
	}

	for(i=0;i<m;i++)
		if(reqmat[i] > available[i]){
			printf("\n Resources unavailable.\n");
			exit(0);
		}
	
	for(i=0;i<m;i++){
		available[i]= available[i]-reqmat[i];
		allocate[pid][i]=allocate[pid][i]+reqmat[i];
		need[pid][i]=need[pid][i]-reqmat[i];
	}
}


void display(int a[5][3],int p[])
{
int i,j;
for(i=0;i<n;i++)
{printf("\n%d",p[i]);
for(j=0;j<m;j++)
printf("\t%d",a[i][j]);
}
}

int banker(){
	int j,i,a[10];
	j=safety(available,allocate);
	if(j != 0 ){
		printf("\n\n");
		for(i=0;i<n;i++)
		     printf(" P%d  ",order[i]);
		printf("\n A safety sequence has been detected.\n");
		return 1;
	}else{
		printf("\n Deadlock has occured.\n");
		return 0;
	}
}


int main()
{int i,j,ch,pid,ret;


for(i=0;i<5;i++)
for(j=0;j<3;j++)
need[i][j]=max[i][j]-allocate[i][j];
printf("\n\t\tAllocate:");

display(allocate,p);
printf("\n\n\t\tMax:");

display(max,p);
printf("\n\n\t\tNeed:");

display(need,p);



printf("\n\nAvailable\n");
for(i=0;i<3;i++)
printf("\t%d",available[i]);

ret=banker();
	if(ret !=0 ){
		printf("\n Do you want make an additional request ? press 1");
		scanf("%d",&ch);
		if(ch == 1){
			printf("\n Enter process no. : ");
			scanf("%d",&pid);
			res_request(pid);
			ret=banker();
			if(ret == 0 )
				exit(0);
		}
	}else
		exit(0);
	return 0;

printf("\n");
}


	

