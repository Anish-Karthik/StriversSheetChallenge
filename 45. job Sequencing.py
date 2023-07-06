from os import *
from sys import *
from collections import *
from math import *

def jobScheduling(jobs):

    jobs.sort(key=lambda x: x[1], reverse=True)
    
    maxi = jobs[0][0]
    for i in range(1, len(jobs)):
        maxi = max(maxi, jobs[i][0])


    slot = [-1] * (maxi + 1)
    countJobs = jobProfit = 0


    for i in range(len(jobs)):
        for j in range(jobs[i][0], 0, -1):
            if slot[j] == -1:
                slot[j] = i
                countJobs += 1
                jobProfit += jobs[i][1]
                break


    return jobProfit
