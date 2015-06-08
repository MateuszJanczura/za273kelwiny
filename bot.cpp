class bot
{
	public:
		double sA, sB, sC; //parametry bota
		int sKonta, sPrzedmioty;
		bot();
		bot(double x, double y, double z);
		bool wynik();
		bool operator< (bot const &q) const {return sPrzedmioty < q.sPrzedmioty;}
};

bot::bot()
{
}

bot::bot(double x, double y, double z)
{
	sA = x;
	sB = y;
	sC = z;
}

bool bot::wynik()
{
	return true;
}
