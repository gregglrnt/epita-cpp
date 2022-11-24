void swap(auto &a, auto &b) {
    auto t = a;
    a = b;
    b = t;
}

template<class C>
C my_min(C first, C last, auto lambda) {
    if(first == last) {
        return last;
    }

    C smallest = first;
    ++first;

    for(; first != last; ++first) {
        if(lambda(*first, *smallest)) {
            smallest = first;
        }
    }

    return smallest;
}

template <typename Iterator>
void my_selection_sort(Iterator start, Iterator end, auto lambda) {
    for(; start != end; ++start) {
        auto min = my_min<Iterator>(start, end, lambda);
        swap(*min, *start);
    }
}
