#include "../inc/fdf.h"

u64	get_data_add(u64	ptr)
{
	static u64	data = 0;

	if (data != 0)
		return (data);
	else
		data = ptr;
	return (0);
}
