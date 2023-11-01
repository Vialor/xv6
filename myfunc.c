#define INITAL_SEED 1278210672

int cur_seed = INITAL_SEED;
int prng(int mod) // xorshift32
{
  if (mod <= 0) return 0;
  int x = cur_seed;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
  cur_seed = x;
	return (x % mod + mod) % mod; // positive modulo
}