/**
 * byte order is big endian ?
 * return value:
 * 	1  --  big endian
 * 	0  --  lower endian
 * 	
 */
int is_bigendian()
{
	union {
		int v;
		char c;
	}data;

	data.v = 1;
	return data.c != 1;
}

