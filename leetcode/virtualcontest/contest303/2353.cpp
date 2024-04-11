#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class FoodRatings
{
public:
    unordered_map<string, int> food_rating;
    unordered_map<string, set<pair<int, string>>> cuisine_rating_food;
    unordered_map<string, string> food_cusine;
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        int n = foods.size();
        for (int i = 0; i < n; i++)
        {
            string food = cuisines[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            cuisine_rating_food[cuisine].insert({-rating, food});
            food_cusine[food] = cuisine;
            food_rating[food] = rating;
        }
    }

    void changeRating(string food, int newRating)
    {
        string cusine = food_cusine[food];
        int old_rating = food_rating[food];

        food_rating[food] = newRating;
        cuisine_rating_food[cusine].erase({-old_rating, food});
        cuisine_rating_food[cusine].insert({-newRating, food});
    }

    string highestRated(string cuisine)
    {
        return begin(cuisine_rating_food[cuisine])->second;
    }
};