/*
 * algorithms.tpp
 */

// template <std::totally_ordered T>
template<typename T>
void insertion_sort(sf::RenderWindow &window, std::vector<T> &v, bool &is_sorted)
{
    for (int j = 1; j < v.size(); j++) 
    {
        int key = v[j];

        // insert v[j] into sorted sequence v[1..j − 1]
        int i = j - 1;
        while (i > 0 && v[i] > key) 
        {
            v[i + 1] = v[i];
            i--;
            render(window, v, i);
        }

        v[i + 1] = key;
    }
    is_sorted = true;
    render(window, v, v.size() - 1);

    return;
}

// template <std::totally_ordered T>
template<typename T>
void merge_sort(sf::RenderWindow &window, std::vector<T> &v, int start, int end, bool &is_sorted)
{
    int len = end - start + 1;
    if (len <= 1)
    {
        is_sorted = true;
        return;
    }

    int mid = start + (len / 2);

    merge_sort(window, v, start, mid - 1, is_sorted);
    merge_sort(window, v, mid, end, is_sorted);

    // merge start->mid and mid+1-> end
    std::vector<T> temp(len);
    int i = start;
    int j = mid;
    int curr = 0;

    while (i < mid && j <= end)
    {
        if (v[i] <= v[j])
        {
            temp[curr++] = v[i++];
        }
        else 
        {
            temp[curr++] = v[j++];
        }
    }

    while (i < mid)
    {
        temp[curr++] = v[i++];
    }

    while (j <= end)
    {
        temp[curr++] = v[j++];
    }
    std::copy(temp.begin(), temp.end(), v.begin() + start);

    for (int i = start; i <= end; i++)
    {
        render(window, v, i);
    }
}