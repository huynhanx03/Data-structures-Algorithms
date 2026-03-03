/*
 Problem: 4067. Design Auction System
 Language: cpp
 Runtime: 175 ms (75.81%)
 Memory: 362.6 MB (36.61%)
 Tags: Hash Table, Design, Heap (Priority Queue), Ordered Set
*/
class AuctionSystem {
private:
    unordered_map<int, unordered_map<int, int>> bids;
    unordered_map<int, set<pair<int, int>>> ranks;
public:
    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        if (bids[itemId].count(userId)) {
            int old = bids[itemId][userId];
            ranks[itemId].erase({old, userId});
        }

        bids[itemId][userId] = bidAmount;
        ranks[itemId].insert({bidAmount, userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        int old = bids[itemId][userId];
        ranks[itemId].erase({old, userId});

        bids[itemId][userId] = newAmount;
        ranks[itemId].insert({newAmount, userId});
    }
    
    void removeBid(int userId, int itemId) {
        int v = bids[itemId][userId];
        ranks[itemId].erase({v, userId});
        bids[itemId].erase(userId);
    }
    
    int getHighestBidder(int itemId) {
        if (ranks[itemId].empty()) return -1;

        return ranks[itemId].rbegin()->second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */