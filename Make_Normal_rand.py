import numpy as np
import secrets
import random
#！！！
#注：以下注释掉的部分为利用python的numpy与random库函数直接得到的均值为N/2方差为1的正态分布随机数，同时也有对其绘制的直方图，若需要可以取消注释
#！！！
# def generate_normal_in_range(N, num_samples=1):
#     # 生成标准正态分布随机数
#     samples = np.random.normal(N/2, 1, num_samples)
#     return samples
# N = 100000
# num_samples = 100000000
# random_numbers = generate_normal_in_range(N, num_samples)
# #print(random_numbers)
# #绘制直方图以查看结果分布
# import matplotlib.pyplot as plt
#
# plt.hist(random_numbers, bins=30, density=True, alpha=0.6, color='g')
# plt.title('Approximate Normal Distribution in [0, N]')
# plt.xlabel('Value')
# plt.ylabel('Frequency')
# plt.grid(axis='y', alpha=0.75)
# plt.show()

p=0
k=0
j=0
while j<100000:
    while k<pow(2,16): #利用中心极限定理得到正态分布。
        random_number = random.randint(0, 1)
        p=p+random_number
        k=k+1
    k=0
    with open('rand_1.txt', 'a') as file:
        file.write(str(p) + ' ')
    with open('rand_1_bin.txt', 'a') as file:
        file.write(bin(p)[2:])
    p = 0
    j = j + 1
