#include "headers.h"
#include "sha.h"


void check(const BIGNUM *pri, int len)
{
	//公钥转地址
	CKey key;
	key.MakeNewKey();

	//用于+1
	BIGNUM *one = BN_new();
	BN_one(one);
	//私钥
	BIGNUM *num = BN_new();
	BN_copy(num, pri);
	
	//打开文件
	FILE *fp = NULL;
	fp = fopen("test.txt", "aw+");
	//累加
	for(int i=0; i<len; i++)
	{
		key.SetPrivKey_wepeng(num);
		fprintf(fp, key.GetPrivKey_wepeng());
		fprintf(fp, ",");
		string strAddress = PubKeyToAddress(key.GetPubKey());
		fprintf(fp, strAddress.c_str());
		fprintf(fp, "\n");
		BN_add(num, num, one);
	}
	fclose(fp);
	
	return;
}

int main(int argc, char * argv[]) {
	if(argc != 3)
	{
		printf("argc=3\n");
		return 0;
	} else if( strlen(argv[1]) != 64)
	{
		printf("argv[1] Len=64\n%s\n", argv[1]);
		return 0;
	}
	const char *pri_char = argv[1]; //
	int len = atoi(argv[2]);  //个数
	BIGNUM *pri= BN_new();
	BN_hex2bn(&pri, pri_char);
	
	//统计时间和速度
	time_t start, end ; 
	double cost;  
    time(&start);  
	
	check(pri, len);
	
	//显示时间和速度
	time(&end);  
    cost=difftime(end,start);
	int t = cost;
	if(t==0)
	{
		printf("All time:%f\n Speed:%d n/s\n", cost, len);  
	} else {
		printf("All time:%f\n Speed:%d n/s\n", cost, len/t); 
	}
	return 1;
}