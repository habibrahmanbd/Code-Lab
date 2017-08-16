const int p = 31; //p=31 for lowercase English Letter and p = 53 for both uppercase and lowecase
unsigned long long hash = 0, p_pow = 1; //Modulu is 2^64 because of unsigned long long
for (size_t i = 0; i <s.length (); ++ i)
{
    // Generally, it is recommended to take the "value" of 'a' to be 1
    // so that strings like "aaaaa" do not all hash to the value 0
    hash + = (s [i] - 'a' + 1) * p_pow;
    p_pow * = p;
}
