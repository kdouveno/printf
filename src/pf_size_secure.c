long long	min_ll()
{
	static long long a;

	if (!a)
		a = ((long long)1 << (sizeof(long long) * 8 - 1));
	return (a);
}
long		min_l()
{
	static long a;

	if (!a)
		a = ((long)1 << (sizeof(long) * 8 - 1));
	return (a);
}
int			min_i()
{
	static int a;

	if (!a)
		a = ((int)1 << (sizeof(int) * 8 - 1));
	return (a);
}
short		min_s()
{
	static short a;

	if (!a)
		a = ((short)(1 << (sizeof(short) * 8 - 1)));
	return (a);
}
char		min_c()
{
	static char a;

	if (!a)
		a = ((char)(1 << (sizeof(char) * 8 - 1)));
	return (a);
}
