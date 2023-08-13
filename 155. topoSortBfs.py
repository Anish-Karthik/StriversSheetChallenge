from queue import Queue
class Solution:
    def topoSort(self, V, adj):
                indegree={}
                q=Queue()
                res=[]

    #initializing indegree dictionary
                for i in range(V):
                    indegree[i]=0

   #traversing adj list and updating indegree dictionary
                for l in adj:
                        for i in range(0,len(l)):
                                indegree[l[i]]+=1

                def khan(adj,indegree):

                     #initialization into the queue
                        for key in indegree:
                                    if indegree[key]==0:
                                            q.put(key)
                        while(not q.empty()):
                                        temp=q.get()
                                        res.append(temp)
                                        for child in adj[temp]:
                                                if indegree[child]!=0:
                                                            indegree[child]-=1
                                                            if indegree[child]==0:
                                                                q.put(child)
                        return res
                        
                return khan(adj,indegree)
