#User function Template for python3

class Solution:
    
    #Function to find the maximum profit and the number of jobs done.
    def JobScheduling(self,Job,n):
        Jobs = []
        m = -1
        for i in range(n):
            Jobs.append((Job[i].id,Job[i].deadline,Job[i].profit))
            if m<Job[i].deadline:
                m = Job[i].deadline
        Jobs = sorted(Jobs,key= lambda x:x[2],reverse=True)
        L = [0]*m
        i = 0
        res = 0
        for Jobid, Deadline, Profit in Jobs:
            for j in range(Deadline-1,-1,-1):
                if L[j]==0 :
                    L[j] = 1
                    i+=1
                    res+=Profit
                    break
        return [i,res]

        # code here

    
