#include "miniRT.h"

int main()
{
	t_p3 v;

	v.x = 4;
	v.y = 3;
	v.z = 6;
	
	v = normalize(v);

	printf("%f, %f, %f\n", v.x, v.y, v.z);
	return (0);
}
