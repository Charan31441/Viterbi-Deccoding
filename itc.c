#include<stdio.h>

/******Finding Xor of two numbers******/
int xor(int k, int l)
{
	if(k==l)
		return 0;
	else return 1;
}
/*******Finding xor of three numbers*****/
int Exor(int k,int l,int m)
{
	int temp=xor(k,l);
	int e=xor(temp,m);
	return e;
}
int k1=0,k2=0,k3=0,k4=0,k5=0,k6=0,k7=0,k8=0,k9=0,k10=0,k11=0,k12=0,k13=0,k14=0,k15=0,k16=0;
int a1,a2,a3,b1,b2,b3;

int Trellis(int n,int k);
struct node{
int hamming_dist;
char pre;
char state;
}a[100],b[100],c[100],d[100];
char current_state; 
int ind=0;
/*****Computing Hamming Distance***/
int dist(int k,int l,int m ,int n)
{
if(k==m&&l==n)return 0;
else if((k==m&&l!=n)||(k!=m&&l==n))return 1;
else if(k!=m&&l!=n)return 2;
}

int Finding_hamming(int i,int j)
{
int h1=dist(i,j,k1,k2),h2=dist(i,j,k5,k6);
h1=h1 + a[ind].hamming_dist;
h2=h2 + b[ind].hamming_dist;
//printf("ind=%d,%d %d",ind,h1,h2);
a[ind+1].hamming_dist= (h1<h2)?h1:h2;
a[ind+1].pre= (h1<h2)?'a':'b';

int h3=dist(i,j,k9,k10),h4=dist(i,j,k13,k14);
h3=h3 + c[ind].hamming_dist;
h4=h4 + d[ind].hamming_dist;
//printf("ind=%d,%d %d",ind,h3,h4);
b[ind+1].hamming_dist= (h3<h4)?h3:h4;
b[ind+1].pre= (h3<h4)?'c':'d';

int h5=dist(i,j,k3,k4),h6=dist(i,j,k7,k8);
h5=h5 + a[ind].hamming_dist;
h6=h6 + b[ind].hamming_dist;
//printf("ind=%d,%d %d",ind,h5,h6);
c[ind+1].hamming_dist= (h5<h6)?h5:h6;
c[ind+1].pre= (h5<h6)?'a':'b';

int h7=dist(i,j,k11,k12),h8=dist(i,j,k15,k16);
h7=h7 + c[ind].hamming_dist;
h8=h8 + d[ind].hamming_dist;
//printf("ind=%d,%d %d",ind,h7,h8);
d[ind+1].hamming_dist= (h7<h8)?h7:h8;
d[ind+1].pre= (h7<h8)?'c':'d';

}
int second_stage(int i,int j)
{
a[2].hamming_dist=dist(i,j,k1,k2) + a[1].hamming_dist;
a[2].pre='a';
b[2].hamming_dist=dist(i,j,k9,k10) + c[1].hamming_dist;
b[2].pre='c';
c[2].hamming_dist=dist(i,j,k3,k4) + a[1].hamming_dist;
//printf("%d ",c[2].hamming_dist);
c[2].pre='a';
d[2].hamming_dist=dist(i,j,k11,k12) + c[1].hamming_dist;
d[2].pre='c';

}
int first_stage(int i,int j)
{

a[1].hamming_dist=dist(i,j,k1,k2) ;
a[1].pre= 'a';
b[1].hamming_dist=0;
b[1].pre='n';
c[1].hamming_dist=dist(i,j,k3,k4);
c[1].pre='a';
d[1].hamming_dist=0;
d[1].pre='n';

}
void init()
{

a[0].hamming_dist=0;
a[0].pre='n';
b[0].hamming_dist=0;
b[0].pre='n';
c[0].hamming_dist=0;
c[0].pre='n';
d[0].hamming_dist=0;
d[0].pre='n';

}

int main()
{

	int n,k;
	char string[1000];
	printf("n=");
	scanf("%d",&n);
	printf("k=");
	scanf("%d",&k);
	Trellis(n,k);
	printf("Input BitStream for Decoding is=");
	scanf("\n%[^\n]s",string);
	printf("%s\n",string);
	int p=0,i1,i2;
	init();
	i1=string[0]-'0';
	i2=string[1]-'0';
//		printf("%d %d\n",i1,i2);
	first_stage(i1,i2);
printf("%c->A->%d        %c->B->%d        %c->C->%d        %c->D->%d\n\n",a[0].pre,a[0].hamming_dist,b[0].pre,b[0].hamming_dist,c[0].pre,c[0].hamming_dist,d[0].pre,d[0].hamming_dist);

	i1=string[3]-'0';
	i2=string[4]-'0';
//		printf("%d %d\n",i1,i2);
	second_stage(i1,i2);

printf("%c->A->%d        %c->B->%d        %c->C->%d        %c->D->%d\n\n",a[1].pre,a[1].hamming_dist,b[1].pre,b[1].hamming_dist,c[1].pre,c[1].hamming_dist,d[1].pre,d[1].hamming_dist);

	p=6;
ind=2;
	int flag=0;
	if(string[p]=='\0')flag=1;
	while(string[p]!='\n'&&flag==0)
	{
		i1=string[p]-'0';
		i2=string[p+1]-'0';
//		printf("%d %d\n",i1,i2);

		/*******Hamming*******/
		Finding_hamming(i1,i2);

printf("%c->A->%d        %c->B->%d        %c->C->%d        %c->D->%d\n\n",a[ind].pre,a[ind].hamming_dist,b[ind].pre,b[ind].hamming_dist,c[ind].pre,c[ind].hamming_dist,d[ind].pre,d[ind].hamming_dist);
ind++;
		if(string[p+2]=='\0')
		{
printf("%c->A->%d        %c->B->%d        %c->C->%d        %c->D->%d\n\n",a[ind].pre,a[ind].hamming_dist,b[ind].pre,b[ind].hamming_dist,c[ind].pre,c[ind].hamming_dist,d[ind].pre,d[ind].hamming_dist);
			break;
		}		
		p=p+3;
	}
	return 0;
}




/****************FORMING A TRELLIS DIAGRAM**********/
int Trellis(int n,int k)
{
	/******for n****/
	if(n==0)
	{a1=0;a2=0;a3=0;}
	else if(n==1)
	{a1=0;a2=0;a3=1;}
	else if(n==2)
	{a1=0;a2=1;a3=0;}
	else if(n==3)
	{a1=0;a2=1;a3=1;}
	else if(n==4)
	{a1=1;a2=0;a3=0;}
	else if(n==5)
	{a1=1;a2=0;a3=1;}
	else if(n==6)
	{a1=1;a2=1;a3=0;}
	else if(n==7)
	{a1=1;a2=1;a3=1;}

	/******for k****/
	if(k==0)
	{b1=0;b2=0;b3=0;}
	else if(k==1)
	{b1=0;b2=0;b3=1;}
	else if(k==2)
	{b1=0;b2=1;b3=0;}
	else if(k==3)
	{b1=0;b2=1;b3=1;}
	else if(k==4)
	{b1=1;b2=0;b3=0;}
	else if(k==5)
	{b1=1;b2=0;b3=1;}
	else if(k==6)
	{b1=1;b2=1;b3=0;}
	else if(k==7)
	{b1=1;b2=1;b3=1;}

	/******for n*******/
	k1=Exor(a1*0,a2*0,a3*0);
	k3=Exor(a1*1,a2*0,a3*0);
	k5=Exor(a1*0,a2*0,a3*1);
	k7=Exor(a1*1,a2*0,a3*1);
	k9=Exor(a1*0,a2*1,a3*0);
	k11=Exor(a1*1,a2*1,a3*0);
	k13=Exor(a1*0,a2*1,a3*1);
	k15=Exor(a1*1,a2*1,a3*1);

	/*******for k*******/
	k2=Exor(b1*0,b2*0,b3*0);
	k4=Exor(b1*1,b2*0,b3*0);
	k6=Exor(b1*0,b2*0,b3*1);
	k8=Exor(b1*1,b2*0,b3*1);
	k10=Exor(b1*0,b2*1,b3*0);
	k12=Exor(b1*1,b2*1,b3*0);
	k14=Exor(b1*0,b2*1,b3*1);
	k16=Exor(b1*1,b2*1,b3*1);

	/*********Printing Trellis Diagram********/
	printf("\n\n***************************************************\n\n\n");
	printf("*****************TRELLIS DIAGRAM********************\n\n");
	printf("a----0/%d%d--->a  |--0/%d%d-->a            a           a\n  |             |                                      \n  |             |                                      \nb |          b--           b |--0/%d%d-->b |--0/%d%d-->b\n  |             |            |           |           \n  |             |            |           |           \nc |---1/%d%d-->c  |--1/%d%d-->c--          c |         c\n                             |           |           \n                             |           |           \nd            d            d  |--1/%d%d-->d---1/%d%d--->d\n",k1,k2,k5,k6,k9,k10,k13,k14,k3,k4,k7,k8,k11,k12,k15,k16); 
	printf("\n\n*****************************************************\n\n\n\n\n");

}
