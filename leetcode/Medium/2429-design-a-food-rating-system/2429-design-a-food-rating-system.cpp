/*
 Problem: 2429. Design a Food Rating System
 Language: cpp
 Runtime: 178 ms (16.89%)
 Memory: 174.2 MB (47.98%)
 Tags: Array, Hash Table, String, Design, Heap (Priority Queue), Ordered Set
*/
class FoodRatings {
    struct Food {
        string name;
        int rating;
        bool operator<(const Food& other) const {
            if (rating != other.rating) return rating > other.rating; 
            return name < other.name; 
        }
    };

    unordered_map<string, string> foodToCuisine;      // food -> cuisine
    unordered_map<string, int> foodToRating;          // food -> rating
    unordered_map<string, set<Food>> cuisineToFoods;  // cuisine -> set of foods

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            foodToCuisine[food] = cuisine;
            foodToRating[food] = rating;
            cuisineToFoods[cuisine].insert({food, rating});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];

        cuisineToFoods[cuisine].erase({food, oldRating});
        cuisineToFoods[cuisine].insert({food, newRating});
        foodToRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineToFoods[cuisine].begin()->name;
    }
};
