#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\cherk\source\repos\Edmonds–Karp\Edmonds–Karp\AdjList.cpp"
#include "C:\Users\cherk\source\repos\Edmonds–Karp\Edmonds–Karp\AdjMatrix.cpp"
#include "C:\Users\cherk\source\repos\Edmonds–Karp\Edmonds–Karp\Array.cpp"
#include "C:\Users\cherk\source\repos\Edmonds–Karp\Edmonds–Karp\Source.cpp"
#include "C:\Users\cherk\source\repos\Edmonds–Karp\Edmonds–Karp\IntQueue.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EdmondsKarpTests
{
	TEST_CLASS(EdmondsKarpTests)
	{
	public:
		
		TEST_METHOD(countVertexTest)
		{
			text.push_back("S O 3");
			text.push_back("S P 3");
			text.push_back("O Q 3");
			text.push_back("O P 2");
			text.push_back("P R 2");
			text.push_back("Q R 4");
			text.push_back("Q T 2");
			text.push_back("R T 3");
			countVertex();
			Assert::IsTrue(translator['S'] == 0 && translator['O'] == 1 && translator['P'] == 2 && translator['Q'] == 3 && translator['R'] == 4 && translator['T'] == 5);
		}

		TEST_METHOD(separateTest)
		{
			char a, b;
			std::string dist, temp;
			temp = "S P 3";
			separate(a, b, dist, temp);
			Assert::IsTrue(a == 'S' && b == 'P' && dist == "3");
		}

		TEST_METHOD(initTest)
		{
			text.push_back("S O 3");
			text.push_back("S P 3");
			text.push_back("O Q 3");
			text.push_back("O P 2");
			text.push_back("P R 2");
			text.push_back("Q R 4");
			text.push_back("Q T 2");
			text.push_back("R T 3");
			init();
			for (int i = 0; i < g.getSize(); i++) {
				for (int j = 0; j < g.getSize(); j++) {
					if ((i == 0 && (j == 1 || j == 2)) || (i == 1 && j == 3) || (i == 4 && j == 5))Assert::IsTrue(g[i][j] == 3);
					else if ((i == 1 && j == 2) || (i == 2 && j == 4) || (i == 3 && j == 5))Assert::IsTrue(g[i][j] == 2);
					else if (i == 3 && j == 4)Assert::IsTrue(g[i][j] == 4);
					else Assert::IsTrue(g[i][j] == 0);
				}
			}
		}

		TEST_METHOD(widthSearchTest)
		{
			text.push_back("S O 3");
			text.push_back("S P 3");
			text.push_back("O Q 3");
			text.push_back("O P 2");
			text.push_back("P R 2");
			text.push_back("Q R 4");
			text.push_back("Q T 2");
			text.push_back("R T 3");
			init();
			int flow = 0;
			bool flag = false;
			flag = widthSearch(translator['S'], translator['T'], flow);
			Assert::IsTrue(flow == 2 && flag == 1);
		}
		
		TEST_METHOD(algEdmondsKarpTest)
		{
			text.push_back("S O 3");
			text.push_back("S P 3");
			text.push_back("O Q 3");
			text.push_back("O P 2");
			text.push_back("P R 2");
			text.push_back("Q R 4");
			text.push_back("Q T 2");
			text.push_back("R T 3");
			init();
			int flow = algEdmondsKarp(translator['S'], translator['T']);
			Assert::IsTrue(flow == 5);
		}
	};
}
