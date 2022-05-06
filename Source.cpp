//Test sandbox for DogDev
#include "DFW/DWin.h"

#include "DFW/DContainers.h"
#include "DFW/Time/Stopwatch.h"

#include <vector>

using namespace DogFW;

int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ int)
{
	Int32* p = new Int32;
	Stopwatch* s = new Stopwatch;

	std::vector<Double> resvec;
	for (int a = 0; a < 100; ++a)
	{

		for (int test = 0; test < 100; ++test)
		{
			WString result;
			Stopwatch clock;

			std::vector<List<WString>> vec;
			clock.start();

			for (int i = 0; i < 100; ++i)
			{
				vec.push_back(List<WString>());
			}
			for (auto& i : vec)
			{
				for (int j = 0; j < 100; ++j)
				{
					i.pushBack(L"Gaw");
				}
			}
			for (auto& i : vec)
			{
				for (auto& j : i)
				{
					result += j;
				}
				result += L"\n";
			}

			clock.stop();
			resvec.push_back(clock.getTimeElapsed());
		}
	}
	Double sum = 0;
	Int64  count = 0;
	for (auto i : resvec)
	{
		sum += i;
		++count;
	}
	Double res = sum / count;
	win::msgbox::info(std::to_wstring(res));
	return 0;
}

