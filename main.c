#include "ft_printf.h"

int main(int argc, char const *argv[])
{
	printf("|123456789|\n");
	printf("|%-*s|\n", -3, "ad");
	ft_printf("|%-*s|\n", -3, "ad");
	return 0;
}
