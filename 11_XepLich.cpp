#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Event {
    int start_time;
    int end_time;
};

bool compareEvents(Event a, Event b) {
    return a.end_time < b.end_time;
}

int scheduleEvents(vector<Event>& events) {
    sort(events.begin(), events.end(), compareEvents);
    int count = 1;
    int current_end_time = events[0].end_time;
    for (int i = 1; i < events.size(); i++) {
        if (events[i].start_time >= current_end_time) {
            count++;
            current_end_time = events[i].end_time;
        }
    }
    return count;
}

int main() {
    vector<Event> events;
    
    // Nhập thông tin các sự kiện
    int n;
    cout << "Enter the number of events: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Event event;
        cout << "Enter start time of event " << i+1 << ": ";
        cin >> event.start_time;
        cout << "Enter end time of event " << i+1 << ": ";
        cin >> event.end_time;
        events.push_back(event);
    }
    
    // Tính số lượng sự kiện tối đa có thể xếp lịch
    int maxEvents = scheduleEvents(events);
    
    cout << "Maximum number of events that can be scheduled: " << maxEvents << endl;
    
    return 0;
}

