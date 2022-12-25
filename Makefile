MarketParentChild:	MarketParentChild.cpp Market.h Market.cpp HashMap.h HashMap.cpp LinkedHashStock.h LinkedHashStock.cpp Stock.h Stock.cpp StringList.h StringList.cpp
	g++ -g -o MarketParentChild MarketParentChild.cpp Market.cpp HashMap.cpp LinkedHashStock.cpp Stock.cpp StringList.cpp

clean:
	rm MarketParentChild
