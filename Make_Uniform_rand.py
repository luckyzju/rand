import numpy as np
import random
def int_to_binary_string(num, width=32):   #int转二进制并填充
    binary_str = bin(num)[2:]    # 去除开头的'0b'
    # 使用zfill方法填充前导零，使其达到指定的宽度
    return binary_str.zfill(width)
def change_bit_string(str2):   #异或与移位操作
    str1=list(str2)
    i=random.randint(0,18)
    j=random.randint(19,31)
    a=str(int(str1[(i+4)%32])^int(str1[(i+13)%32])^int(str1[(i+23)%32])^int(str1[(i+31)%32]))
    b=str(int(str1[(j + 5) % 32] )^int( str1[(j + 11) % 32]) ^int( str1[(j + 25) % 32] )^int( str1[(j + 29) % 32]))
    str1[i]=a
    str1[j]=b
    str1=str1[2:] + str1[:2]
    data=''.join(str1)
    return data
j=0
N = pow(2,32)
random_number = random.randint(0, N-1)
while j<10000000:
    if j==0:
        str1=int_to_binary_string(random_number)
        str1=change_bit_string(str1)
        m=int(str1,2)
        n=m%pow(2,16)
    else:
        str1 = int_to_binary_string(m)
        str1 = change_bit_string(str1)
        m = int(str1, 2)
        n = m % pow(2, 16)
    with open('rand1.txt', 'a') as file: #int写入
        file.write(str(n) + ' ')
    with open('rand3.txt', 'a') as file1: #二进制写入
        file1.write(bin(n)[2:])
    j=j+1