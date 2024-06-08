#include <stdio.h>
#include <math.h>
#include<windows.h>
#include <stdlib.h>
#define N 32768

char* int_to_binary_string(int num) {  
    // ȷ���������ַ�������󳤶�  
    size_t length = sizeof(int) * 8 + 1; // 8λ/�ֽڣ���1λ�����ַ���������'\0'  
    char *binary_string = (char*)malloc(length);  
    if (!binary_string) {  
        return NULL; // �ڴ����ʧ��  
    }  
  
    // ��ʼ���ַ���Ϊȫ0  
    memset(binary_string, '0', length - 1);  
    binary_string[length - 1] = '\0'; // �����ַ���������  
  
    // ���ÿһλ��������Ϊ1�������Ҫ��  
    for (int i = 0; i < sizeof(int) * 8; ++i) {  
        // ʹ��λ�ƺ�λ����������ÿһλ  
        if (num & (1 << (sizeof(int) * 8 - 1 - i))) {  
            binary_string[i] = '1';  
        }  
    }  
  
    // ȥ��ǰ���㣨��ѡ��  
    size_t non_zero_index = 0;  
    while (non_zero_index < length - 1 && binary_string[non_zero_index] == '0') {  
        non_zero_index++;  
    }  
  
    // �����㲿���ƶ����ַ�����ͷ  
    if (non_zero_index > 0) {  
        memmove(binary_string, binary_string + non_zero_index, length - non_zero_index);  
    }  
  
    return binary_string;  
}

int main(){
	//printf("RAND_MAX = %d\n", RAND_MAX);
	float x[N];
	for(int i=0;i<N;i++){
		x[i]=0;
	}
	FILE *fp1;
	fp1 = fopen("data2.txt", "w");//ͳ�������
	FILE *fp2;
	fp2 = fopen("data2_bin.txt", "w");//ͳ��������Ķ����Ʊ�ʾ
	int j=0;
	for(int i=0;i<10000000;i++){
		j=rand()%N;
		fprintf(fp1,"%d",j);
		fprintf(fp1," ");
		x[j]++;
		char *binary_string = int_to_binary_string(j);
		fprintf(fp2,"%s",binary_string);
		free(binary_string);
	}
	fclose(fp1);
	FILE *fp;
	fp = fopen("data1.txt", "w");//ÿ�������ֵĸ���
	for(int i=0;i<N;i++){
		fprintf(fp,"%d\t%f\t\t",i,x[i]/10000000);	
	}
	fclose(fp);
	return 0;
}
