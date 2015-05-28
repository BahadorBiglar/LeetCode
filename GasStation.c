int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int StartingIndex=gasSize-1, tank;
    
    tank = 0;
    int CurrentPos = StartingIndex;
    do{
        tank += gas[CurrentPos];
        tank -= cost[CurrentPos];
        CurrentPos ++;
        
        if (CurrentPos==gasSize) CurrentPos = 0;
        if (tank < 0){
            do{
                StartingIndex--;
                if (StartingIndex==-1)
                    StartingIndex = gasSize;
                if (StartingIndex==gasSize-1)
                    return -1;
                tank += gas[StartingIndex];
                tank -= cost[StartingIndex];
            } while (tank < 0);
        }
    } while (CurrentPos != StartingIndex);
    
    return StartingIndex;

}