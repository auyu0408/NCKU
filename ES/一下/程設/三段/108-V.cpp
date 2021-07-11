#include<cstdlib>
#include<vector>
class Package
{
	public:
		virtual int CalculateCost() const;
};
class overnight:public Package
{
    public:
		virtual int CalculateCost() const;
};
class twodays:public Package
{
    public:
		virtual int CalculateCost() const;
};
int main()
{
	vector <Package *> Pack;
	overnight o();
	twodays t();
	
	Pack.push_back(&o);
	Pack.push_back(&t);
	for(size_t i=0;i<Pack.size();i++)
	{
	cout<<Pack[i]->CalculateCost()<<endl;
	}
	return 0;
}
