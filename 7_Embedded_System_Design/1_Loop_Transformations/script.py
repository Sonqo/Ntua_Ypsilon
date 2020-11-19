import numpy
import subprocess
import seaborn as sns
from subprocess import PIPE
import matplotlib.pyplot as plt

# Default PHODS
acc_v0 = []
subprocess.run('gcc -O0 phods.c -o phods.app', shell=True)
sum_default = 0
max_default = 0
min_default = 10000
for i in range(10):
    curr = subprocess.run('./phods.app', stdout=PIPE, shell=True)
    info = int(curr.stdout.decode('utf-8').split("'")[0])
    acc_v0.append(info)
    if info < min_default:
        min_default = info
    if info > max_default:
        max_default = info
    sum_default += info
average_default = sum_default/10
print(min_default, average_default, max_default)

# Loop Transformed PHODS
acc_v1 = []
subprocess.run('gcc -O0 phods_opt_v1.c -o phods_opt_v1.app', shell=True)
sum_opt_v1 = 0
max_opt_v1 = 0
min_opt_v1 = 10000
for i in range(10):
    curr = subprocess.run('./phods_opt_v1.app', stdout=PIPE, shell=True)
    info = int(curr.stdout.decode('utf-8').split("'")[0])
    acc_v1.append(info)
    if info < min_opt_v1:
        min_opt_v1 = info
    if info > max_opt_v1:
        max_opt_v1 = info
    sum_opt_v1 += info
average_opt_v1 = sum_opt_v1/10
print(min_opt_v1, average_opt_v1, max_opt_v1)

# Space Exploration V1_PHODS
subprocess.run('gcc -O0 phods_opt_v2.c -o phods_opt_v2.app', shell=True)
average_opt_v2 = 10000
for B in [1, 2, 4, 8, 16]:
    curr_acc_v2 = []
    curr_sum_opt_v2 = 0
    curr_max_opt_v2 = 0
    curr_min_opt_v2 = 10000
    for i in range(10):
        curr = subprocess.run('./phods_opt_v2.app ' + str(B), stdout=PIPE, shell=True)
        info = int(curr.stdout.decode('utf-8').split("'")[0])
        curr_acc_v2.append(info)
        if info < curr_min_opt_v2:
            curr_min_opt_v2 = info
        if info > curr_max_opt_v2:
            curr_max_opt_v2 = info
        curr_sum_opt_v2 += info
    curr_average_opt_v2 = curr_sum_opt_v2/10
    if curr_average_opt_v2 < average_opt_v2:
        best_B = B
        acc_v2 = curr_acc_v2
        min_opt_v2 = curr_min_opt_v2
        max_opt_v2 = curr_max_opt_v2
        average_opt_v2 = curr_average_opt_v2
print(best_B, min_opt_v2, average_opt_v2, max_opt_v2)

# Space Exploration V2_PHODS
subprocess.run('gcc -O0 phods_opt_v3.c -o phods_opt_v3.app', shell=True)
average_opt_v3 = 10000
for Bx in [1, 2, 4, 8, 16]:
    for By in [1, 2, 4, 8, 16]:
        curr_acc_v3 = []
        curr_sum_opt_v3 = 0
        curr_max_opt_v3 = 0
        curr_min_opt_v3 = 10000
        for i in range(10):
            curr = subprocess.run('./phods_opt_v3.app ' + str(Bx) + ' ' + str(By), stdout=PIPE, shell=True)
            info = int(curr.stdout.decode('utf-8').split("'")[0])
            curr_acc_v3.append(info)
            if info < curr_min_opt_v3:
                curr_min_opt_v3 = info
            if info > curr_max_opt_v3:
                curr_max_opt_v3 = info
            curr_sum_opt_v3 += info
        curr_average_opt_v3 = curr_sum_opt_v3/10
        if curr_average_opt_v3 < average_opt_v3:
            best_Bx = Bx
            best_By = By
            acc_v3 = curr_acc_v3
            min_opt_v3 = curr_min_opt_v3
            max_opt_v3 = curr_max_opt_v3
            average_opt_v3 = curr_average_opt_v3
print(best_Bx, best_By, min_opt_v3, average_opt_v3, max_opt_v3)

# Plotting
acc0 = numpy.array(acc_v0)
acc1 = numpy.array(acc_v1)
acc2 = numpy.array(acc_v2)
acc3 = numpy.array(acc_v3)

final = numpy.stack([acc0, acc1, acc2, acc3], axis=1)

ax = sns.boxplot(data=final, showfliers=False)
plt.show()