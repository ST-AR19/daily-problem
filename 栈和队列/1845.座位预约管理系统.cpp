/*
 * @lc app=leetcode.cn id=1845 lang=cpp
 *
 * [1845] 座位预约管理系统
 */

// @lc code=start
class SeatManager {
public:
    vector<int> seat;
    SeatManager(int n) {
        for(int i = 1; i <= n; i++) {
            seat.push_back(i);
        }
    }
    
    int reserve() {
        //根据小顶堆取出最小元素
        pop_heap(seat.begin(), seat.end(), greater<int>());
        int temp = seat.back();
        seat.pop_back();
        return temp;
    }
    
    void unreserve(int seatNumber) {
        //根据释放的座位重新调整，维护小顶堆
        seat.push_back(seatNumber);
        push_heap(seat.begin(), seat.end(), greater<int>());
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
// @lc code=end

