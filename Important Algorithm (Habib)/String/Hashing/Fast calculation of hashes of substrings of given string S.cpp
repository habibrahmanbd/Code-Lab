// input data
// s - the input string
// len - the length of the two substrings to be compared
// i1 - the start index of the first substring
// i2 - the start index of the second substring
string s; int i1, i2, len;

// calculate all powers of p
const int p = 31;
vector <unsigned long long> p_pow (s.length ());
p_pow [0] = 1;
for (size_t i = 1; i <p_pow.size (); ++ i)
    p_pow [i] = p_pow [i-1] * p;

// Calculate the hashes of all prefixes
vector <unsigned long long> h (s.length ());
for (size_t i = 0; i <s.length (); ++ i)
{
    h [i] = (s [i] - 'a' + 1) * p_pow [i];
    if (i) h [i] + = h [i-1];
}

// Get the hashes of two substrings
unsigned long long h1 = h [i1 + len-1];
if (i1) h1 - = h [i1-1];
unsigned long long h2 = h [i2 + len-1];
if (i2) h2 - = h [i2-1];

// Get the two hashes multiplied by the same power of P and then
// compare them
if (i1 <i2 && h1 * p_pow [i2-i1] == h2 ||
    i1> i2 && h1 == h2 * p_pow [i1-i2])
    cout << "equal" << endl;
else
    cout << "different" << endl;
    

