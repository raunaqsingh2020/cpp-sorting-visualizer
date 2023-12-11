/*
 * algorithms.tpp
 */

// --- INSERTION SORT ---

template <typename T>
void insertion_sort(sf::RenderWindow &window,
                    DropdownMenu &dropdown,
                    std::tuple<std::vector<int>, std::vector<int>, std::vector<int>> &v,
                    std::tuple<int, int, int> &curr_index,
                    std::tuple<bool, bool, bool> &is_sorted)
{
    auto &v1 = std::get<0>(v);
    auto &idx1 = std::get<0>(curr_index);
    auto &sorted1 = std::get<0>(is_sorted);

    for (int j = 1; j < v1.size(); j++)
    {
        int key = v1[j];

        // insert v[j] into sorted sequence v[1..j − 1]
        int i = j - 1;
        while (i >= 0 && v1[i] > key)
        {
            v1[i + 1] = v1[i];
            i--;
            idx1 = i;
            std::this_thread::sleep_for(std::chrono::milliseconds(15));
        }

        v1[i + 1] = key;
    }

    sorted1 = true;
    idx1 = v1.size() - 1;
    std::this_thread::sleep_for(std::chrono::milliseconds(15));

    return;
}

// --- MERGE SORT ---

template <typename T>
void merge_sort(sf::RenderWindow &window,
                DropdownMenu &dropdown,
                std::tuple<std::vector<int>, std::vector<int>, std::vector<int>> &v,
                std::tuple<int, int, int> &curr_index,
                std::tuple<bool, bool, bool> &is_sorted,
                int start,
                int end)
{
    auto &v2 = std::get<1>(v);
    auto &idx2 = std::get<1>(curr_index);
    auto &sorted2 = std::get<1>(is_sorted);

    int len = end - start + 1;
    if (len <= 1)
        return;

    int mid = start + (len / 2);

    merge_sort<T>(window, dropdown, v, curr_index, is_sorted, start, mid - 1);
    merge_sort<T>(window, dropdown, v, curr_index, is_sorted, mid, end);

    // merge start -> mid and mid + 1 -> end
    std::vector<T> temp(len);
    int i = start;
    int j = mid;
    int curr = 0;

    while (i < mid && j <= end)
    {
        if (v2[i] <= v2[j])
            temp[curr++] = v2[i++];
        else
            temp[curr++] = v2[j++];
    }

    while (i < mid)
        temp[curr++] = v2[i++];

    while (j <= end)
        temp[curr++] = v2[j++];

    std::copy(temp.begin(), temp.end(), v2.begin() + start);

    if (len == v2.size())
        sorted2 = true;

    for (int i = start; i <= end; ++i)
    {
        idx2 = i;
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
    }
}

// --- QUICK SORT ---

template <typename T>
int partition(sf::RenderWindow &window,
              DropdownMenu &dropdown,
              std::tuple<std::vector<int>, std::vector<int>, std::vector<int>> &v,
              std::tuple<int, int, int> &curr_index,
              std::tuple<bool, bool, bool> &is_sorted,
              int start,
              int end)
{
    auto &v3 = std::get<2>(v);
    auto &idx3 = std::get<2>(curr_index);
    auto &sorted3 = std::get<2>(is_sorted);

    // Choose random pivot index and swap with end element
    int pivot_idx = start + std::rand() % (end - start + 1);
    idx3 = pivot_idx;
    sorted3 = false;
    std::this_thread::sleep_for(std::chrono::milliseconds(15));
    std::swap(v3[pivot_idx], v3[end]);

    // Partition the vector
    T pivot = v3[end];
    int i = start - 1;

    for (int j = start; j < end; ++j)
    {
        if (v3[j] < pivot)
        {
            ++i;
            std::swap(v3[i], v3[j]);
        }
    }

    std::swap(v3[i + 1], v3[end]);
    idx3 = i + 1;
    sorted3 = false;
    std::this_thread::sleep_for(std::chrono::milliseconds(15));
    return i + 1;
}

template <typename T>
void quick_sort(sf::RenderWindow &window,
                DropdownMenu &dropdown,
                std::tuple<std::vector<int>, std::vector<int>, std::vector<int>> &v,
                std::tuple<int, int, int> &curr_index,
                std::tuple<bool, bool, bool> &is_sorted,
                int start,
                int end)
{
    auto &v3 = std::get<2>(v);
    auto &idx3 = std::get<2>(curr_index);
    auto &sorted3 = std::get<2>(is_sorted);

    if (start < end)
    {
        // Partition the vector and get the pivot index
        int pivot_idx = partition<T>(window, dropdown, v, curr_index, is_sorted, start, end);

        // Recursively sort the sub-vectors
        quick_sort<T>(window, dropdown, v, curr_index, is_sorted, start, pivot_idx - 1);
        quick_sort<T>(window, dropdown, v, curr_index, is_sorted, pivot_idx + 1, end);
    }

    int len = end - start + 1;
    if (len == v3.size())
    {
        idx3 = v3.size() - 1;
        sorted3 = true;
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
    }
}
