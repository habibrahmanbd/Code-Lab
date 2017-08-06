//Building Sparse Table
for i=0..N-1: // assuming Arr is indexed from 0
  Table[i][0] = F(Arr[i])
for j=1..k: // assuming N < 2^(k+1)
  for i=0..N-2^j:
    Table[i][j] = F(Table[i][j - 1], Table[i + 2^(j - 1)][j - 1])


//Answer Generating
answer = ZERO
L’ = L
for i=k..0:
  if L’ + 2^i - 1 <= R:
    answer = F(answer, Table[L’][i]) // F is associative, so this operation is meaningful
    L’ += 2^i
