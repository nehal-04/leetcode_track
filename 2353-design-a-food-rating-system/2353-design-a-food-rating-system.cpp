class FoodRatings {
public:
    unordered_map<string , set<pair<int,string>>> cuisine_food;
    unordered_map<string , pair<string , int>> food_cuisine;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = -1*ratings[i];
            food_cuisine[food] = {cuisine , rating};
            cuisine_food[cuisine].insert({rating , food});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_cuisine[food].first;
        int oldrating = food_cuisine[food].second;
        food_cuisine[food].second = -1*newRating;
        cuisine_food[cuisine].erase({oldrating , food});
        cuisine_food[cuisine].insert({-1*newRating, food});
    }
    
    string highestRated(string cuisine) {
        return cuisine_food[cuisine].begin()->second;
        
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */