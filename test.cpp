#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions_to_implement.cpp"
#include <vector>

TEST_CASE("Factorials are computed", "[factorial]") // tag
{
	CHECK(Factorial(0) == 1); // assertion
	REQUIRE(Factorial(1) == 1);
	REQUIRE(Factorial(2) == 2);
	REQUIRE(Factorial(3) == 6);
	REQUIRE(Factorial(10) == 3628800);
}

TEST_CASE("incrementing values in integer vector", "[addN]")
{
	std::vector<int> v{1, 2, 3, 5, 6, 7, 8, 10};

	SECTION("checking with +ve n")
	{
		int n = 5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand() % v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE(res[0] == 6);
		REQUIRE(res[v.size() - 1] == 15);
		REQUIRE(res[random] == v[random] + n);
	}
	SECTION("checking with -ve n")
	{
		int n = -5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand() % v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE(res[0] == -4);
		REQUIRE(res[v.size() - 1] == 5);
		REQUIRE(res[random] == v[random] + n);
	}
}

TEST_CASE("test split", "[string]")
{
	REQUIRE(Split("this,is,a,csv,format",",") == std::vector<std::string>{"this","is","a","csv","format"});
	REQUIRE(Split("hyphen--in--sentence", "-") == std::vector<std::string>{"hyphen", "in", "sentence"});
	REQUIRE(Split("...", ".") == std::vector<std::string>{});
	REQUIRE(Split(".a.a.", ",") == std::vector<std::string>{".a.a."});
}

TEST_CASE("test match removal", "[vector]")
{
	REQUIRE(MatchVectors(std::vector<int>{1,2,3,4,5}, std::vector<int>{3,4,5,10,12}) == std::vector<int>{1,2});
	REQUIRE(MatchVectors(std::vector<int>{9}, std::vector<int>{3, 4, 5, 10, 12}) == std::vector<int>{9});
	REQUIRE(MatchVectors(std::vector<int>{}, std::vector<int>{3, 4, 5, 10, 12}) == std::vector<int>{});
	REQUIRE(MatchVectors(std::vector<int>{1}, std::vector<int>{}) == std::vector<int>{1});
}

TEST_CASE("test multiplies removal", "[vector]")
{
	REQUIRE(MultiplesFilter(std::vector<double>{1, 2, 3, 4, 5}, 2) == std::vector<double>{1,3,5});
	REQUIRE(MultiplesFilter(std::vector<double>{9},1) == std::vector<double>{});
	REQUIRE(MultiplesFilter(std::vector<double>{},5)==std::vector<double>{});
	REQUIRE(MultiplesFilter(std::vector<double>{1},5)==std::vector<double>{1});
	REQUIRE(MultiplesFilter(std::vector<double>{1.5,2.7,3}, 1.5) == std::vector<double>{2.7});
	REQUIRE(MultiplesFilter(std::vector<double>{1,2,3}, 0) == std::vector<double>{1,2,3});
	REQUIRE(MultiplesFilter(std::vector<double>{1, 2, 3}, -2) == std::vector<double>{1, 3});
}

TEST_CASE("test greater than vector", "[vector]")
{
	REQUIRE(GreaterMask(std::vector<double>{1.2,3.4,2.4,6.4}, 3.39) == std::vector<bool>{false, true, false, true});
	REQUIRE(GreaterMask(std::vector<double>{-1.2, -3.4, -2.4, -6.4}, -3.39) == std::vector<bool>{true, false, true, false});
	REQUIRE(GreaterMask(std::vector<double>{}, 9) == std::vector<bool>{});
	REQUIRE(GreaterMask(std::vector<double>{-INFINITY}, INFINITY) == std::vector<bool>{false});
	REQUIRE(GreaterMask(std::vector<double>{1}, 1) == std::vector<bool>{false});
}

TEST_CASE("test product", "[vector]")
{
	REQUIRE(Product(std::vector<double>{1,2,3})==6);
	REQUIRE(Product(std::vector<double>{1, 2, 0}) == 0);
	REQUIRE(Product(std::vector<double>{-1, 2, -1}) == 2);
	REQUIRE(Product(std::vector<double>{}) == 0);
}

TEST_CASE("test sign", "[number]")
{
	REQUIRE(Sign(-125.215) == -1);
	REQUIRE(Sign(1251.5) == 1);
	REQUIRE(Sign(0.0) == 0);
	REQUIRE(Sign(-INFINITY) == -1);
	REQUIRE(Sign(INFINITY) == 1);
}