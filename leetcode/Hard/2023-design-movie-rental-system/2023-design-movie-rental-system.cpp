/*
 Problem: 2023. Design Movie Rental System
 Language: cpp
 Runtime: 244 ms (77.99%)
 Memory: 402.5 MB (43.22%)
 Tags: Array, Hash Table, Design, Heap (Priority Queue), Ordered Set
*/
#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
    unordered_map<long long, int> priceMap; // (shop,movie)->price
    unordered_map<int, set<pair<int,int>>> available; // movie -> {(price, shop)}
    set<tuple<int,int,int>> rented; // {(price, shop, movie)}

    long long encode(int shop, int movie) {
        return ((long long)shop << 32) | (unsigned int)movie;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap[encode(shop,movie)] = price;
            available[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        if (available.count(movie)) {
            for (auto it = available[movie].begin(); it != available[movie].end() && res.size()<5; ++it) {
                res.push_back(it->second); // shop
            }
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = priceMap[encode(shop,movie)];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = priceMap[encode(shop,movie)];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (auto it = rented.begin(); it != rented.end() && res.size()<5; ++it) {
            auto [price, shop, movie] = *it;
            res.push_back({shop, movie});
        }
        return res;
    }
};
