
/***********************
 * 
 *
 *
 */
bool is_bigendian()
{
	static bool _isBigEndian = false;
	static bool bInit = false;

	if( !bInit ){
		union{
			int val;
			char ch;
		}u;
		u.val = 1;
	
		_isBigEndian = (u.ch != 1);
		
		bInit = true;  //must place it here!
	}
	
	return _isBigEndian;	
}
