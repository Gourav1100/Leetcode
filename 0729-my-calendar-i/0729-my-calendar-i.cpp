class MyCalendar {
    map<int, int> tasks;
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        // cout << start << " " << end << endl;
        for(auto& item: tasks) {
            // cout << item.first << " " << item.second << endl;
            if ((start >= item.first && start < item.second) || (end > item.first && end <= item.second) || (start < item.first && end > item.second)) {
                // cout << "false" << endl;
                return false;
            }
        }
        // cout <<"true" << endl;
        tasks[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */