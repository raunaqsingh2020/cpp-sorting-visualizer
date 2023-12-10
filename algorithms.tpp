/*
 * algorithms.tpp
 */

// --- INSERTION SORT ---

// template <std::totally_ordered T>
template <typename T>
void insertion_sort(sf::RenderWindow &window, std::vector<T> &v, bool &is_sorted)
{
    for (int j = 1; j < v.size(); j++)
    {
        int key = v[j];

        // insert v[j] into sorted sequence v[1..j − 1]
        int i = j - 1;
        while (i >= 0 && v[i] > key)
        {
            v[i + 1] = v[i];
            i--;
            render(window, v, i, is_sorted);
        }

        v[i + 1] = key;
    }

    is_sorted = true;
    render(window, v, v.size() - 1, is_sorted);

    return;
}

// --- MERGE SORT ---

// template <std::totally_ordered T>
template <typename T>
void merge_sort(sf::RenderWindow &window, std::vector<T> &v, int start, int end, bool &is_sorted)
{
    int len = end - start + 1;
    if (len <= 1)
        return;

    int mid = start + (len / 2);

    merge_sort(window, v, start, mid - 1, is_sorted);
    merge_sort(window, v, mid, end, is_sorted);

    // merge start -> mid and mid + 1 -> end
    std::vector<T> temp(len);
    int i = start;
    int j = mid;
    int curr = 0;

    while (i < mid && j <= end)
    {
        if (v[i] <= v[j])
            temp[curr++] = v[i++];
        else
            temp[curr++] = v[j++];
    }

    while (i < mid)
        temp[curr++] = v[i++];

    while (j <= end)
        temp[curr++] = v[j++];

    std::copy(temp.begin(), temp.end(), v.begin() + start);

    if (len == v.size())
        is_sorted = true;

    for (int i = start; i <= end; ++i)
        render(window, v, i, is_sorted);
}

// --- QUICK SORT ---

template <typename T>
int partition(sf::RenderWindow &window, std::vector<T> &v, int start, int end)
{
    // Choose random pivot index and swap with end element
    int pivot_idx = start + std::rand() % (end - start + 1);
    render(window, v, pivot_idx, false);
    std::swap(v[pivot_idx], v[end]);

    // Partition the vector
    T pivot = v[end];
    int i = start - 1;

    for (int j = start; j < end; ++j)
    {
        if (v[j] < pivot)
        {
            ++i;
            std::swap(v[i], v[j]);
        }
    }

    std::swap(v[i + 1], v[end]);
    render(window, v, i + 1, false);
    return i + 1;
}

// template <std::totally_ordered T>
template <typename T>
void quick_sort(sf::RenderWindow &window, std::vector<T> &v, int start, int end, bool &is_sorted)
{
    if (start < end)
    {
        // Partition the vector and get the pivot index
        int pivot_idx = partition(window, v, start, end);

        // Recursively sort the sub-vectors
        quick_sort(window, v, start, pivot_idx - 1, is_sorted);
        quick_sort(window, v, pivot_idx + 1, end, is_sorted);
    }

    int len = end - start + 1;
    if (len == v.size())
    {
        is_sorted = true;
        render(window, v, v.size() - 1, is_sorted);
    }
}
