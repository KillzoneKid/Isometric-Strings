#include <iostream>
#include <string>
#include <array>
#include <limits>

bool IsIsomorphic(std::string const &s, std::string const &t)
{
	std::array<char, std::numeric_limits<char>::max() - std::numeric_limits<char>::min() + 1> arr = {};

	for (size_t i = 0, n = s.length(); i < n; ++i)
	{
		size_t pos = static_cast<size_t>(s[i]);

		if (arr[pos] == 0)
		{
			arr[pos] = t[i];
			continue;
		}
		
		if (arr[pos] != t[i])
			return false;
	}

	return true;
}

int main()
{
	// test
	std::string const ss[10][2] =
	{
		{ "add", "egg" },
		{ "foo", "bar" },
		{ "paper", "title" },
		{ "aab", "xyz" },
		{ "aab", "xxy" },
		{ "abcd", "aabb" },
		{ "aaba", "bbaa" },
		{ "bbaa", "aaba" },
		{ "topcode", "topcoat" },
		{ "topcoat", "topcode" }
	};

	for (auto const &s : ss)
		std::cout 
		<< "\"" << s[0] << "\"" 
		<< (IsIsomorphic(s[0], s[1]) ? " is isomorphic to " : " is NOT isomorphic to ") 
		<< "\"" << s[1] << "\"" << std::endl;

	return 0;
}