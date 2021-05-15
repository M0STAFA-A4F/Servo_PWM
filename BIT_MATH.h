#define SET_BIT(var,bit_no)		var|=(1<<bit_no)
#define CLR_BIT(var,bit_no)		var&=~(1<<bit_no)
#define Toggle_BIT(var,bit_no)	var^=(1<<bit_no)
#define GET_BIT(var,bit_no)		(var>>bit_no)&1
