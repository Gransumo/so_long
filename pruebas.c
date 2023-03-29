
#include <stdio.h>

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}


int main()
{
	char *s1 = "hellober";
	char *s2 = ".ber";

	if (ft_strcmp_end(s1, s2) != 0)
		printf("ES IGUAL");
	else
		printf("ES DIFERENTE");
}
