def maximumActivities(start, finish):
    
    activity = sorted(zip(start, finish), key = lambda x: x[1])
    lastFinishTime = 0
    activitiesPerformed = 0
    for startTime, finishTime in activity:
        if lastFinishTime <= startTime:
            lastFinishTime = finishTime
            activitiesPerformed+=1
    return activitiesPerformed
