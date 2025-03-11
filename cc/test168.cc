template<typename T> bool less(T a, T b)
{
    return a<b;
}

template<>
bool less<const char*>(const char* a, const char* b)
{
    return false;
}

#if 0
template<>
bool less<>(const char* a, const char* b)
{
    return false;
}
#endif
int main(int argc, char *argv[])
{
    return 0;
}
