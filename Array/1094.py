
class Solution:
    def carPooling(self, trips: list[list[int]], capacity: int) -> bool:
        
        max_destination  = 0
        #find the max destination of all trips
        for passengers, start, end in trips:
            max_destination  = max(end, max_destination )

        passenger_changes = [0]*(max_destination +1)
        #record how many passenger changes in one stop
        for passengers, start, end in trips:
            passenger_changes[start] += passengers
            passenger_changes[end] -= passengers
        
        current =0
        for change  in passenger_changes:
            current += change 
            #if passengers in the car > capacity -> False
            if current > capacity:
                return False

        return True

