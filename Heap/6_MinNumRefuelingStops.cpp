/*
A car travels from a starting position to a destination which is target miles east of the starting position.

There are gas stations along the way. The gas stations are represented as an array stations where stations[i] = [positioni, fueli] indicates that the 
ith gas station is positioni miles east of the starting position and has fueli liters of gas.

The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it. It uses one liter of gas per one mile that it drives. 
When the car reaches a gas station, it may stop and refuel,transferring all the gas from the station into the car.

Return the minimum number of refueling stops the car must make in order to reach its destination. If it cannot reach the destination, return -1.

Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there. If the car reaches the destination with 0 fuel left, 
it is still considered to have arrived.
*/ 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0;
        int dist = 0;
        int i = 0;
        priority_queue<pair<int,int>> maxheap; // {fuel,position}
        int fuel = startFuel;
        while(true){
            while(i<stations.size()){
                // push stations in reach
                if(stations[i][0] <= dist+fuel){
                    maxheap.push({stations[i][1], stations[i][0]});
                }
                else{
                    break;
                }
                i++;
            }
            // travel with full level
            dist += fuel;
            fuel = 0;
            // reached
            if(dist>=target) break;
            // no fuel station in reach
            if(maxheap.empty()) return -1;
            // refuel
            auto& top = maxheap.top();
            fuel = (dist-top.second) + top.first;
            dist = top.second;
            maxheap.pop();
            stops++;
        }
        return stops;
    }
};