#include <stdio.h>
#include <math.h>
#include<windows.h>
#include <stdlib.h>
#include <string.h> 
#define N 65536

int main(){
	long long int sum=0;
	int s;
	float rear1[N],rear2[N],rear3[N],rear4[N];
	char pass;
	for(long long int i=0;i<N;i++){
		rear1[i]=0;
		rear2[i]=0;
		rear3[i]=0;
		rear4[i]=0;
	}
	FILE *fp2;
	fp2 = fopen("rand_1.txt", "r"); //读入随机数数据
	for(float i=0;fscanf(fp2,"%d",&s)==1;i++){	
		fscanf(fp2,"%c",&pass);
		//printf("%d\n",s);
		rear4[s]++;
		if(rear1[s]==0){
			rear1[s]=float(i);
			rear3[s]++;
			continue;
		}
		rear2[s]=rear2[s]+float(i)-rear1[s];
		rear1[s]=float(i);
		rear3[s]++;
	}
	fclose(fp2);
	FILE *fp3;
	fp3 = fopen("rand2_x.txt", "w");//统计重复出现间隔
	for(long long int i=0;i<N;i++){
		if(rear3[i]-2>0){
			sum=rear2[i]/(rear3[i]-2);
			fprintf(fp3,"%lld\t",sum);
		}else{
			sum=0;
			fprintf(fp3,"%lld\t",sum);
		}
	}
	fclose(fp3);
	FILE *fp4;
	fp4 = fopen("rand2_y.txt", "w");//统计各数出现次数
	for(long long int i=0;i<N;i++){
		fprintf(fp4,"%lld %.0f\t",i,rear4[i]);
	}
	fclose(fp4);
	return 0;
}
