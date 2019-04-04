
long factorial(long size)
{
    if (size == 0)
        return 0;

    long total = 1;
    for (long i = 1; i <= size; i++)
    {
        total *= i;
    }

    return total;
}

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
    if (arr.size() < 3)
    {
        return 0;
    }

    unordered_map<long, vector<long>> itemLocations;
    for(long index = 0; index < arr.size(); index++) {
        itemLocations[arr[index]].push_back(index);
    }

    long count = 0;
    if (r == 1)
    {
        for (auto it: itemLocations)
        {
            const long size = it.second.size();
            if (it.second.size() > 3) {
              count += (size * (size-1) * (size - 2)) / 6;
            } else if (it.second.size() == 3)
            {
                count += 1;
            }
        }
    }
    else {
        for (auto it : itemLocations)
        {
            count += it.second.size() 
                * itemLocations[it.first * r].size()
                * itemLocations[it.first * (r*r)].size();
        }
    }
    

    return count;

}
