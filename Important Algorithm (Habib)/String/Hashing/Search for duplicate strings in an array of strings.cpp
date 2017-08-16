vector <string> s (n);
// ... Input the strings...

// Calculate all powers of p up to 10,000 - the maximum length of a string
const int p = 31;
vector <unsigned long long> p_pow (10000);
p_pow [0] = 1;
for (size_t i = 1; i <p_pow.size (); ++ i)
    p_pow [i] = p_pow [i-1] * p;

// Calculate the hash of each string

// hashes[] stores the hash value and the index of the string in the array s
vector <pair <unsigned long long, int>> hashes (n);
for (int i = 0; i <n; ++ i)
{
    unsigned long long hash = 0;
    for (size_t j = 0; j <s [i] .length (); ++ j)
        hash + = (s [i] [j] - 'a' + 1) * p_pow [j];
    hashes [i] = make_pair (hash, i);
}

// Sort by hashes
sort (hashes.begin (), hashes.end ());

// Display the answer
for (int i = 0, group = 0; i <n; ++ i)
{
    if (i == 0 || hashes [i] .first! = hashes [i-1] .first)
        cout << "\n Group" << ++ group << ":";
    cout << " " << hashes [i] .second;
}
