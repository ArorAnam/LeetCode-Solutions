/*
checkInData = a new HashMap (id -> startStation, checkInTime)
journeyData = a new HashMap (startStation, endStation -> total, count)
*/

class UndergroundSystem {
    unordered_map<int, pair<string, int>> checkInData;
    unordered_map<string, pair<int, int>> journeyData;
public:
    UndergroundSystem() {
        checkInData.clear();
        journeyData.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInData[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {

        string state = checkInData[id].first + "," + stationName; 
        
        journeyData[state].first += t - checkInData[id].second;
        journeyData[state].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string state = startStation + "," + endStation;
        
        return double(1.0 * journeyData[state].first / journeyData[state].second);
    }
};

/*
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */


// Solution 2
// T: O(1)
// S: O(N (no. of arrivals) + M (no. of averages) )
// averages will increase with no. of customers arriving
// buut they are deleted when customers check out
// This is going to increase the more times the customers check out
// so we will have to include that here.

class Event {
    int id;
    string stationName;
    int time;
public:
    Event() {}
    
    Event(int id, string stationName, int time)
        : id(id), stationName(stationName), time(time) 
    {}

    int getTime() { return this->time ;}

    string getStationName() { return this->stationName; }
};

class Average {
    double total;
    int count;
public:
    Average() {
        total = 0;
        count = 0;
    }

    void updateAverage(int diff) {
        ++count;
        total += diff;
    }

    double getAverage() {
        return total / count;
    }
};

class UndergroundSystem {
    const string delimeter = ",";

    unordered_map<int, Event> arrivals;
    unordered_map<string, Average> averages;
public:
    UndergroundSystem() {
        arrivals.clear();
        averages.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        arrivals[id] = Event(id, stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        Event arrivalEvent = arrivals[id];
        arrivals.erase(id);

        int diff = t - arrivalEvent.getTime();
        string key = arrivalEvent.getStationName() + delimeter + stationName;

        Average average = averages.find(key) != averages.end() ? averages[key] : Average();
        average.updateAverage(diff);

        averages[key] = average;
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        string key = startStation + delimeter + endStation;

        return averages[key].getAverage();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
