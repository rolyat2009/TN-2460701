using namespace std;
class card
{
public:
	string desc;
	int value;
	card(string d, int v)
	{
		desc=d;
		value=v;
	}
	string getDesc()
    {return desc;}
    int getValue()
    {return value;}
	~card(void)
	{
	}
};