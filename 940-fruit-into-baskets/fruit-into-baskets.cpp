class Solution 
{
public:
    int totalFruit(vector<int>& fruits) 
    {
        unordered_map<int, int> fruitBasket;//can hold maximum two (key(fruit) value(count)) pair
        int windowStart = 0;
        int maxFruits = 0;

        for (int windowEnd = 0; windowEnd < fruits.size(); windowEnd++)
        {
            //Add into fruit basket
            fruitBasket[fruits[windowEnd]]++;

            while (fruitBasket.size() > 2) 
            {
                fruitBasket[fruits[windowStart]]--;
                if (fruitBasket[fruits[windowStart]] == 0)
                    fruitBasket.erase(fruits[windowStart]);//remove the key value pair (fruit and basket)
                windowStart++;
            }
            maxFruits = max(maxFruits, (windowEnd - windowStart) + 1);
        }
        return maxFruits;
    }
};