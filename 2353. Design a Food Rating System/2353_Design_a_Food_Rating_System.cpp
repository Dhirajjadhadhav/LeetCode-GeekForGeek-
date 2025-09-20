class FoodRatings {
    unordered_map<string, string>foodTocusines;
    unordered_map<string, int>foodToRating;
    unordered_map<string, set<pair<int, string>>>cuisinesToFood;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i<foods.size(); ++i){
            foodTocusines[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            cuisinesToFood[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodTocusines[food];
        int oldRating = foodToRating[food];
        cuisinesToFood[cuisine].erase({-oldRating, food});
        cuisinesToFood[cuisine].insert({-newRating, food});
        foodToRating[food] = newRating;
    }

    
    string highestRated(string cuisine) {
        return cuisinesToFood[cuisine].begin()->second;  
    }
};


/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */