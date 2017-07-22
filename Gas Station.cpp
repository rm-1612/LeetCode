/*

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int start=0;
        int end=1;
        int n=gas.size();
        if(n==1)
        {
            if(cost[0]>gas[0])
                return -1;
            return 0;
        }
        int curr_gas=gas[start]-cost[start];
        while(start!=end || curr_gas<0)
        {
            while(start!=end && curr_gas<0)
            {
                curr_gas=curr_gas+cost[start]-gas[start];
                start=(start+1)%n;
                if(start==0)
                    return -1;
            }
            curr_gas=curr_gas+gas[end]-cost[end];
            end=(end+1)%n;
        }
        return start;
    }
};
